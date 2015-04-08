#include "progressbardlg.h"

ProgressBarDlg::ProgressBarDlg(QWidget *parent)
    : QDialog(parent)
{    
    ui.setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint); 
    setWindowFlags(Qt::WindowTitleHint); 
    setWindowFlags(Qt::WindowSystemMenuHint);   
    setWindowIcon(QIcon(":/Resources/mainIcon"));
    ui.pushButton->setVisible(false);
    ui.main_progressBar->setVisible(false);
}

ProgressBarDlg::~ProgressBarDlg()
{

}


/**
*  ”становить текущее значение прогресса
*/
void ProgressBarDlg::SetCurrentProgress( int _progress, std::string _Message )
{
    if ( _progress>=0 && _progress<=100 ) ui.progressBar->setValue(_progress);
    if (!_Message.empty()) ui.label->setText(QString().fromStdString(_Message));
    else {
        ui.label->setText(tr("Wait..."));
    }

    QApplication::processEvents();
    
    if (!ui.main_progressBar->isVisible()) 
    {
        if (_progress == 0)     show();            
        if ( _progress == 100 ) hide();    
    }
}

/**
*  ”становить текущее значение главного прогресса
*/
void ProgressBarDlg::SetCurrentMainProgress( int _progress )
{
    if ( _progress>=0 && _progress<=100 ) ui.main_progressBar->setValue(_progress);

    QApplication::processEvents();

    if (_progress == 0) {
        ui.main_progressBar->setVisible(true);
        show();
    }

    if (_progress == 100) {
        ui.main_progressBar->setVisible(false);
        hide();
    }

}