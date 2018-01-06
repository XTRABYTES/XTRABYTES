#include "statisticspage.h"
#include "ui_statisticspage.h"
#include "main.h"
#include "wallet.h"
#include "init.h"
#include "base58.h"
#include "clientmodel.h"
#include "xtrabytesrpc.h"
#include <sstream>
#include <string>

using namespace json_spirit;

StatisticsPage::StatisticsPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StatisticsPage)
{
    ui->setupUi(this);
    
    setFixedSize(400, 420);
    
    connect(ui->startButton, SIGNAL(pressed()), this, SLOT(updateStatistics()));
}

int heightPrevious = -1;
int connectionPrevious = -1;
int volumePrevious = -1;
double netPawratePrevious = -1;
double pawratePrevious = -1;
double hardnessPrevious = -1;
double hardnessPrevious2 = -1;
int stakeminPrevious = -1;
int stakemaxPrevious = -1;
QString stakecPrevious = "";
QString rewardPrevious = "";

void StatisticsPage::updateStatistics()
{
    double pHardness = GetDifficulty();
    double pHardness2 = GetDifficulty(GetLastBlockIndex(pindexBest, true));
    int pPawrate = GetPoWMHashPS();
    double pPawrate2 = 0.000;
    int nHeight = pindexBest->nHeight;
    uint64_t nMinWeight = 0, nMaxWeight = 0, nWeight = 0;
    pwalletMain->GetStakeWeight(*pwalletMain, nMinWeight, nMaxWeight, nWeight);
    uint64_t nNetworkWeight = GetPoSKernelPS();
    int volume = ((pindexBest->nMoneySupply)/100000000);
    int peers = this->model->getNumConnections();
    pPawrate2 = (double)pPawrate;
    QString height = QString::number(nHeight);
    QString stakemin = QString::number(nMinWeight);
    QString stakemax = QString::number(nNetworkWeight);
    QString phase = "";
    if (pindexBest->nHeight < 10300)
    {
        phase = "X14 POW (POW/POS Starts Block 7200)";
    }
    else if (pindexBest->nHeight > 10300)
    {
        phase = "POS";
    }

    QString subsidy = "";

    if(pindexBest->nHeight < 650)
    {
        subsidy = "1000000 XBY";
    }
    else 
    {
        subsidy = "0 XBY";
    }

    QString hardness = QString::number(pHardness, 'f', 6);
    QString hardness2 = QString::number(pHardness2, 'f', 6);
    QString pawrate = QString::number(pPawrate2, 'f', 3);
    QString Qlpawrate = model->getLastBlockDate().toString();

    QString QPeers = QString::number(peers);
    QString qVolume = QLocale(QLocale::English).toString(volume);

    if(nHeight > heightPrevious)
    {
        ui->heightBox->setText("<b><font color=\"green\">" + height + "</font></b>");
    } else {
    ui->heightBox->setText(height);
    }

    if(0 > stakeminPrevious)
    {
        ui->minBox->setText("<b><font color=\"green\">" + stakemin + "</font></b>");
    } else {
    ui->minBox->setText(stakemin);
    }
    if(0 > stakemaxPrevious)
    {
        ui->maxBox->setText("<b><font color=\"green\">" + stakemax + "</font></b>");
    } else {
    ui->maxBox->setText(stakemax);
    }

    if(phase != stakecPrevious)
    {
        ui->cBox->setText("<b><font color=\"green\">" + phase + "</font></b>");
    } else {
    ui->cBox->setText(phase);
    }
    
    if(subsidy != rewardPrevious)
    {
        ui->rewardBox->setText("<b><font color=\"green\">" + subsidy + "</font></b>");
    } else {
    ui->rewardBox->setText(subsidy);
    }
    
    if(pHardness > hardnessPrevious)
    {
        ui->diffBox->setText("<b><font color=\"green\">" + hardness + "</font></b>");        
    } else if(pHardness < hardnessPrevious) {
        ui->diffBox->setText("<b><font color=\"red\">" + hardness + "</font></b>");
    } else {
        ui->diffBox->setText(hardness);        
    }

    if(pHardness2 > hardnessPrevious2)
    {
        ui->diffBox2->setText("<b><font color=\"green\">" + hardness2 + "</font></b>");
    } else if(pHardness2 < hardnessPrevious2) {
        ui->diffBox2->setText("<b><font color=\"red\">" + hardness2 + "</font></b>");
    } else {
        ui->diffBox2->setText(hardness2);
    }
    
    if(pPawrate2 > netPawratePrevious)
    {
        ui->pawrateBox->setText("<b><font color=\"green\">" + pawrate + " MH/s</font></b>");
    } else if(pPawrate2 < netPawratePrevious) {
        ui->pawrateBox->setText("<b><font color=\"red\">" + pawrate + " MH/s</font></b>");
    } else {
        ui->pawrateBox->setText(pawrate + " MH/s");
    }

    if(Qlpawrate != pawratePrevious)
    {
        ui->localBox->setText("<b><font color=\"green\">" + Qlpawrate + "</font></b>");
    } else {
    ui->localBox->setText(Qlpawrate);
    }
    
    if(peers > connectionPrevious)
    {
        ui->connectionBox->setText("<b><font color=\"green\">" + QPeers + "</font></b>");             
    } else if(peers < connectionPrevious) {
        ui->connectionBox->setText("<b><font color=\"red\">" + QPeers + "</font></b>");        
    } else {
        ui->connectionBox->setText(QPeers);  
    }

    if(volume > volumePrevious)
    {
        ui->volumeBox->setText("<b><font color=\"green\">" + qVolume + " XBY" + "</font></b>");
    } else if(volume < volumePrevious) {
        ui->volumeBox->setText("<b><font color=\"red\">" + qVolume + " XBY" + "</font></b>");
    } else {
        ui->volumeBox->setText(qVolume + " XBY");
    }
    updatePrevious(nHeight, nMinWeight, nNetworkWeight, phase, subsidy, pHardness, pHardness2, pPawrate2, Qlpawrate, peers, volume);
}

void StatisticsPage::updatePrevious(int nHeight, int nMinWeight, int nNetworkWeight, QString phase, QString subsidy, double pHardness, double pHardness2, double pPawrate2, QString Qlpawrate, int peers, int volume)
{
    heightPrevious = nHeight;
    stakeminPrevious = nMinWeight;
    stakemaxPrevious = nNetworkWeight;
    stakecPrevious = phase;
    rewardPrevious = subsidy;
    hardnessPrevious = pHardness;
    hardnessPrevious2 = pHardness2;
    netPawratePrevious = pPawrate2;
    pawratePrevious = Qlpawrate;
    connectionPrevious = peers;
    volumePrevious = volume;
}

void StatisticsPage::setModel(ClientModel *model)
{
    updateStatistics();
    this->model = model;
}


StatisticsPage::~StatisticsPage()
{
    delete ui;
}
