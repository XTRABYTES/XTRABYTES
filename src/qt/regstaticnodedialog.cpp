#include "regstaticnodedialog.h"
#include "ui_regstaticnodedialog.h"

#include "init.h"

#include "xtrabytesunits.h"
#include "addressbookpage.h"
#include "optionsmodel.h"
#include "sendcoinsentry.h"
#include "guiutil.h"
#include "askpassphrasedialog.h"

#include "coincontrol.h"
#include "coincontroldialog.h"

#include "wallet.h"
#include "walletdb.h"
#include "base58.h"

#include <QMessageBox>
#include <QLocale>
#include <QTextDocument>
#include <QScrollBar>
#include <QClipboard>

#include <string>
#include <vector>

using namespace std;

RegSTaTiCnodeDialog::RegSTaTiCnodeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegSTaTiCnodeDialog)
{
    ui->setupUi(this);

#ifdef Q_OS_MAC // Icons on push buttons are very uncommon on Mac
    ui->pushButtonNewKeyPairs->setIcon(QIcon());
    ui->pushButtonRegSTaTiC->setIcon(QIcon());
#endif

    ui->sTaTiCNodePrivateKeyLineEdit->setReadOnly(true);
    ui->sTaTiCNodePublicKeyLineEdit->setReadOnly(true);
    ui->sTaTiCNodeIDLineEdit->setReadOnly(true);
    ui->pushButtonNewKeyPairs->setEnabled(false);
    ui->pushButtonTestKeyPairs->setEnabled(true); 
    ui->pushButtonRegSTaTiC->setEnabled(false);
 
    connect(ui->pushButtonNewKeyPairs, SIGNAL(clicked()), this, SLOT(pushButtonNewKeyPairsClicked()));
    connect(ui->pushButtonTestKeyPairs, SIGNAL(clicked()), this, SLOT(pushButtonTestKeyPairsClicked()));
    connect(ui->pushButtonRegSTaTiC, SIGNAL(clicked()), this, SLOT(pushButtonRegSTaTiCClicked()));
    connect(this, SIGNAL(requireUpdateRegSTaTiCnodeDialogMessages()), this, SLOT(UpdateRegSTaTiCnodeDialogMessages()));    
    
}

RegSTaTiCnodeDialog::~RegSTaTiCnodeDialog()
{
    delete ui;
}

void RegSTaTiCnodeDialog::showEvent(QShowEvent *){
    emit requireUpdateRegSTaTiCnodeDialogMessages();
}

void RegSTaTiCnodeDialog::UpdateRegSTaTiCnodeDialogMessages() {

	 int64_t AccountBalance = 0;	 
	 string strAccount;
	 string AccountAddress; 
	 CXtraBYtesAddress address;
    int acounter = 0;
    BOOST_FOREACH(const PAIRTYPE(CTxDestination, string)& entry, pwalletMain->mapAddressBook) {
        if (IsMine(*pwalletMain, entry.first)) {
            // This address belongs to me
            strAccount = entry.second;
            address = entry.first;
            acounter++;
        } 
       
    }
   
   if (acounter != 1) {
     ui->labelSTaTiCnodeControlMsgBox->setText(tr("WARNING! You have more than 1 account in this wallet. You need a clean STaTiC deposit wallet.") );
     AccountAddress = "BAD DEPOSIT WALLET!";
   } else {
   
   
    CWalletDB walletdb(pwalletMain->strWalletFile);

    CAccount account;
    walletdb.ReadAccount(strAccount, account);
    AccountAddress = address.ToString();
    
    int64_t nBalance = 0;

    // Tally wallet transactions
    for (map<uint256, CWalletTx>::iterator it = pwalletMain->mapWallet.begin(); it != pwalletMain->mapWallet.end(); ++it)
    {
        const CWalletTx& wtx = (*it).second;
        if (!wtx.IsFinal() || wtx.GetDepthInMainChain() < 0)
            continue;

        int64_t nReceived, nSent, nFee;
        wtx.GetAccountAmounts(strAccount, nReceived, nSent, nFee);

        if (nReceived != 0 && wtx.GetDepthInMainChain() >= 1 && wtx.GetDepthInMainChain() <= 50000 && wtx.GetBlocksToMaturity() == 0)
            nBalance += nReceived;
        nBalance -= nSent + nFee;
    }

    // Tally internal accounting entries
    nBalance += walletdb.GetAccountCreditDebit(strAccount);
    
    AccountBalance = nBalance; 
    
    if (AccountBalance != ( STaTiC_DEPOSIT + (100 * COIN))) {
   
        ui->labelSTaTiCnodeControlMsgBox->setText(tr("WARNING! You need exactly 500100 deposited to your STaTiC deposit wallet.") );

    } else {
      ui->pushButtonNewKeyPairs->setEnabled(true);
    }
   
   
    

   }
   
   
   ui->sTaTiCNodeIDLineEdit->setText(QString::fromUtf8( AccountAddress.c_str() ));
   
}

void RegSTaTiCnodeDialog::pushButtonNewKeyPairsClicked()
{	    

    requireUpdateRegSTaTiCnodeDialogMessages();
    
    QMessageBox::StandardButton retval = QMessageBox::question(this, tr("Confirm key pair generation"),
                          tr(" Are you sure you want to generate new keys?"),
          QMessageBox::Yes|QMessageBox::Cancel,
          QMessageBox::Cancel);

    if(retval == QMessageBox::Yes)
    {
 
      CKey key;
      key.MakeNewKey(false);

      CPrivKey vchPrivKey = key.GetPrivKey();
    
      std::vector<unsigned char> PrivKey = ParseHex(HexStr<CPrivKey::iterator>(vchPrivKey.begin(), vchPrivKey.end()));
            
      QString sTaTiCNodePrivateKey = QString::fromUtf8( EncodeBase58( PrivKey ).c_str() );
      ui->sTaTiCNodePrivateKeyLineEdit->setText(sTaTiCNodePrivateKey);
 
      std::vector<unsigned char> PublicKey = ParseHex(HexStr(key.GetPubKey().Raw()));
            
      QString sTaTiCNodePublicKey = QString::fromUtf8( EncodeBase58( PublicKey ).c_str() );
      ui->sTaTiCNodePublicKeyLineEdit->setText(sTaTiCNodePublicKey);
      
      std::stringstream clipboardStringStream;
      
      clipboardStringStream 	<< "STaTiC Node ID (XBY address): " << ui->sTaTiCNodeIDLineEdit->text().toStdString() << endl      
      								<< "STaTiC Node Name: " << ui->sTaTiCNodeNameLineEdit->text().toStdString() << endl
      								<< "STaTiC Node Public Key: " << ui->sTaTiCNodePublicKeyLineEdit->text().toStdString() << endl
      								<< "STaTiC Node Private Key: " << ui->sTaTiCNodePrivateKeyLineEdit->text().toStdString() << endl
      								<< "Spendable Wallet Address: " << ui->spendableWalletAddressLineEdit->text().toStdString();    
  
    	  QApplication::clipboard()->setText(QString::fromStdString(clipboardStringStream.str()));
        QMessageBox::warning(this, tr("SAVE PRIVATE KEY WARNING!"),
            tr("Your private key is copied to your clipboard. Print or save this before you register your STaTiC node."),
            QMessageBox::Ok, QMessageBox::Ok);
        ui->labelSTaTiCnodeControlMsgBox->setText(tr("Friendly name (non-computerized) of STaTiC node and spendable wallet address is optional, but suggested.") );    
        ui->pushButtonRegSTaTiC->setEnabled(true);            
        return;
    }
}


void RegSTaTiCnodeDialog::pushButtonTestKeyPairsClicked()
{	    

      CKey key;
      key.MakeNewKey(false);

      CPrivKey vchPrivKey = key.GetPrivKey();
    
      std::vector<unsigned char> PrivKey = ParseHex(HexStr<CPrivKey::iterator>(vchPrivKey.begin(), vchPrivKey.end()));
            
      QString sTaTiCNodePrivateKey = QString::fromUtf8( EncodeBase58( PrivKey ).c_str() );
      ui->sTaTiCNodePrivateKeyLineEdit->setText(sTaTiCNodePrivateKey);
 
      std::vector<unsigned char> PublicKey = ParseHex(HexStr(key.GetPubKey().Raw()));
            
      QString sTaTiCNodePublicKey = QString::fromUtf8( EncodeBase58( PublicKey ).c_str() );
      ui->sTaTiCNodePublicKeyLineEdit->setText(sTaTiCNodePublicKey);
      
      std::stringstream clipboardStringStream;
      
      clipboardStringStream 	      
      								
      								<< "TEST Node Public Key: " << ui->sTaTiCNodePublicKeyLineEdit->text().toStdString() << endl
      								<< "TEST Node Private Key: " << ui->sTaTiCNodePrivateKeyLineEdit->text().toStdString() << endl;
      								    
  
    	  QApplication::clipboard()->setText(QString::fromStdString(clipboardStringStream.str()));
        QMessageBox::warning(this, tr("CLIPBOARD WARNING!"),
            tr("Your test keys is copied to your clipboard."),
            QMessageBox::Ok, QMessageBox::Ok);
        return;
    
}


void RegSTaTiCnodeDialog::pushButtonRegSTaTiCClicked() {
		    
	 std::string msg;

    // STaTiC deposit
    int64_t nAmount = STaTiC_DEPOSIT;
	    
    // FIXMEE!!! if (pwalletMain->IsLocked())   
    QMessageBox::StandardButton retval = QMessageBox::question(this, tr("Confirm the STaTiC node registration"),
                          tr(" Are you sure you want to register STaTiC node?"),
          QMessageBox::Yes|QMessageBox::Cancel,
          QMessageBox::Cancel);
    if(retval == QMessageBox::Yes) {
    	
	    CXtraBYtesAddress address(ui->sTaTiCNodeIDLineEdit->text().toStdString());
	    if ( address.IsValid()) {
	       
	    } else {
	            QMessageBox::warning(this, tr("ERROR"),
	            tr("Invalid address."),
	            QMessageBox::Ok, QMessageBox::Ok);
	    }
	                
	    // FIXMEE!!! need validate strings ( invalid characters  exampl. "|" )         
	    CXtraBYtesAddress SpendableAddress(ui->spendableWalletAddressLineEdit->text().toStdString());
	    if (SpendableAddress.IsValid()) {
	    	
	      std::stringstream regStringStream;
	      regStringStream << ui->sTaTiCNodeIDLineEdit->text().toStdString() << "|" 
	       					 << ui->sTaTiCNodeNameLineEdit->text().toStdString()  << "|" 
	       					 << ui->sTaTiCNodePublicKeyLineEdit->text().toStdString() << "|" 
	       					 << ui->spendableWalletAddressLineEdit->text().toStdString();
	    	std::string regString = regStringStream.str();           
	    	std::vector<unsigned char> regStringv(regString.begin(), regString.end()); 
	       				       				 
	    	CWalletTx wtx;
	
	    	wtx.mapValue["to"]      = ui->sTaTiCNodeIDLineEdit->text().toStdString();
	       
	    	CScript scriptPubKeyOrig;
	    	scriptPubKeyOrig.SetDestination(address.Get());
	    	CScript scriptPubKey = CScript();
	
	    	scriptPubKey << OP_SREGDATA << regStringv;    
	    	scriptPubKey += scriptPubKeyOrig;
	       
	      string strError = pwalletMain->SendMoney(scriptPubKey, nAmount, wtx, false);
	      if (strError != "") {
	          msg=strError;
	      } else {
	          msg=wtx.GetHash().GetHex();
	      }
	        
	      QMessageBox::warning(this, tr("RESULT"),
	      QString::fromUtf8(msg.c_str()),
	      QMessageBox::Ok, QMessageBox::Ok);
	    
	    } else {
	         QMessageBox::warning(this, tr("ERROR"),
	         tr("Invalid spendable address."),
	         QMessageBox::Ok, QMessageBox::Ok);
	    }
	
	
	}
}
