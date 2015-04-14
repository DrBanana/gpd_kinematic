
#pragma once

#include <Gepard/Callbacks/CB_GeometryRender.h>
#include <Gepard/Topology_Geometry/GPDSolid.h>

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


 //	Класс диалога задания параметров движения детали

class AddMovementDlg : public QDialog,
                              Gepard::Callbacks::GeometryRenderCallback
{
    Q_OBJECT

public:

    AddMovementDlg(int, QWidget *parent = 0);

	
    

	QString GetSolidName(Gepard::Topology_Geometry::GPDSolid *);

public slots:

	void setLinear();
	void setRadial();
	void hideAll();
	void showAll();
	void partNameOutputRed();
	void partNameOutputGreen();
	void axisOutputRed();
	void axisOutputGreen();
	//Виртуальная функция обратного вызова - реакции на действия пользователя
	void renderCallbackEvent(Gepard::Visualization::GCallbackMessage _message) override;

signals:

    void addMovementSignal(Gepard::Topology_Geometry::GPDSolid *solidPtr);

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

	QTableWidget * moveList;
	QHeaderView * moveListHeader;
	QStringList  moveListLabels;

	int stepCount; //Общее число шагов

};
