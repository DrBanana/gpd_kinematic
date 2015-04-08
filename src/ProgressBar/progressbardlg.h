#ifndef PROGRESSBARDLG_H
#define PROGRESSBARDLG_H

#include <QtWidgets/QDialog>
#include <ui_progressbardlg.h>
#include <Gepard/Callbacks/CB_Progress.h>

class ProgressBarDlg : public QDialog, 
                       Gepard::Callbacks::ProgressEvent
{
    Q_OBJECT

public:
    ProgressBarDlg(QWidget *parent = 0);
    ~ProgressBarDlg();
       
    /**
    *  ���������� ������� �������� ���������
    */
    void SetCurrentProgress( int _progress, std::string _Message="" ) override;

    /**
    *  ���������� ������� �������� �������� ���������
    */
    void SetCurrentMainProgress( int _progress ) override;
    
private:
    Ui::ProgressBarDlgClass ui;

};


#endif // PROGRESSBARDLG_H
