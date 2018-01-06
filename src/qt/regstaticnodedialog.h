#ifndef REGSTATICNODEDIALOG_H
#define REGSTATICNODEDIALOG_H

#include <QDialog>
#include <QString>

namespace Ui {
    class RegSTaTiCnodeDialog;
}
class WalletModel;
class SendCoinsEntry;
class SendCoinsRecipient;

QT_BEGIN_NAMESPACE
class QUrl;
QT_END_NAMESPACE

/** Dialog for sending xtrabytess */
class RegSTaTiCnodeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RegSTaTiCnodeDialog(QWidget *parent = 0);
    ~RegSTaTiCnodeDialog();

    void showEvent(QShowEvent *);

private:
    Ui::RegSTaTiCnodeDialog *ui;


signals:
      void requireUpdateRegSTaTiCnodeDialogMessages();


private slots:
	void pushButtonNewKeyPairsClicked();
	void pushButtonTestKeyPairsClicked();
   void pushButtonRegSTaTiCClicked();
	void UpdateRegSTaTiCnodeDialogMessages();
	
};

#endif // REGSTATICNODEDIALOG_H
