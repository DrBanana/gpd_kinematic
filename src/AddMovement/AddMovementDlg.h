
#pragma once

#include "..\includes\gepard.h"
#include <Gepard/Callbacks/CB_GeometryRender.h>
#include <Gepard/Topology_Geometry/GPDSolid.h>
#include <Gepard/Visualization/SpecialObjects/GAxis.h>
#include <Gepard/Visualization/GColor.h>

#include <CMovements/Mover.h>

#include <QtWidgets/QDialog>
#include <QtGui>

#include <QGridLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QRadioButton>
#include <QTableWidget>
#include <QHeaderView>
#include <QPalette>


using namespace Gepard::Visualization;
//using namespace Gepard::BasicMath;


 //	Класс диалога задания параметров движения детали

class AddMovementDlg : public QDialog,
                              Gepard::Callbacks::GeometryRenderCallback
{
    Q_OBJECT

public:

    AddMovementDlg(int, QWidget *parent = 0);
    ~AddMovementDlg();

    
    

    QString GetSolidName(Gepard::Topology_Geometry::GPDSolid *);
    QString GetFaceName(Gepard::Topology_Geometry::GPDFace *);

    void closeEvent(QCloseEvent *) override;

public slots:

    void setLinear();
    void setRadial();
    void hideAll();
    void showAll();
    void partNameOutputRed();
    void partNameOutputGreen();
    void axisOutputRed();
    void axisOutputGreen();
    //Переключение флага
    void flagPart();
    void flagFace();
    void flagNothing();

    void addMovement();
    void clearMovement();
    //Виртуальная функция обратного вызова - реакции на действия пользователя
    void renderCallbackEvent(Gepard::Visualization::GCallbackMessage _message) override;
    void showAxis();
    void deleteAxis(GAxis *);

    void sendMover();

signals:

    void moverToLine(CMover);

private:
    


    QPalette * redPalette;
    QPalette * greenPalette;
    QGridLayout * mainLay;

    QLabel * mainLabel;                //Выбор детали
    QLabel * partLabel;                //Деталь:
    QLabel * moveTypeLabel;            //Тип движения:
    QLabel * moveNameLabel;            //Имя: (Движения)
    QLabel * shiftLabel;               //Смещение: или Угол:
    QLabel * axisLabel;                //Вектор:
    QLabel * startStepLabel;           //Стартовый шаг:
    QLabel * endStepLabel;             //Конечный шаг:
    QLabel * moveListLabel;            //Список движений

    QRadioButton * linearRadio;        //Линейное
    QRadioButton * radialRadio;        //Вращательное

    QLineEdit * partNameOutput;        //Вывод детали
    QLineEdit * moveNameInput;        //Ввод движения
    QLineEdit * shiftInput;            //Ввод смещения
    QLineEdit * axisOutput;            //Вывод оси
    QLineEdit * startStepInput;        //Ввод стартового шага
    QLineEdit * endStepInput;          //Ввод конечного шага

    QPushButton * partAddButton;       //Добавть деталь
    QPushButton * partDropButton;      //Сбросить деталь
    QPushButton * axisAddButton;       //Добавить ось
    QPushButton * axisDropButton;      //Сбросить ось
    QPushButton * moveAddButton;       //Добавить движение
    QPushButton * moveDropButton;      //Сбросить данные диалога
    QPushButton * moverAdd;

    QTableWidget * moveList;
    QHeaderView * moveListHeader;
    QStringList  moveListLabels;

    int stepCount; //Общее число шагов
    int shift;
    Gepard::BasicMath::GPDVector shiftEnd;
    Gepard::BasicMath::GPDVector shiftStart;

    enum modeFlag{ PART, FACE, NOTHING };

    modeFlag currentMode;

    bool moveFlag;

    Gepard::BasicMath::GPDReper fReper;

    Gepard::Topology_Geometry::GPDSolid * newPart;  //Указатель на деталь
    GAxis * newAxis;                                //На ось


    vector<CMovements> newMovements;

};
