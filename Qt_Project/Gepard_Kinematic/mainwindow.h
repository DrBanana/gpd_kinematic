#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDockWidget>
#include <QBoxLayout>

#include <ProgressBar/progressbardlg.h>
#include<TimeLine/timeline.h>
#include <AddMovement/AddMovementDlg.h>

#include <Gepard/GeometryManager.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionOpenStep_triggered();

    void on_test();

private:
    Ui::MainWindow *ui;

    Gepard::GeometryManager g_manager;

	QDockWidget * tLineWidget;
	TimeLine * timeLineWidget;
    ProgressBarDlg      progressDlg;

    AddMovementDlg addMovement;
};

#endif // MAINWINDOW_H
