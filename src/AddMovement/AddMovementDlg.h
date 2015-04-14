
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


 //	����� ������� ������� ���������� �������� ������

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
	//����������� ������� ��������� ������ - ������� �� �������� ������������
	void renderCallbackEvent(Gepard::Visualization::GCallbackMessage _message) override;

signals:

    void addMovementSignal(Gepard::Topology_Geometry::GPDSolid *solidPtr);

private:

	QPalette * redPalette;
	QPalette * greenPalette;
	QGridLayout * mainLay;

	QLabel * mainLabel;                //����� ������
	QLabel * partLabel;                //������:
	QLabel * moveTypeLabel;            //��� ��������:
	QLabel * moveNameLabel;            //���: (��������)
	QLabel * shiftLabel;               //��������: ��� ����:
	QLabel * axisLabel;                //������:
	QLabel * startStepLabel;           //��������� ���:
	QLabel * endStepLabel;             //�������� ���:
	QLabel * moveListLabel;            //������ ��������

	QRadioButton * linearRadio;        //��������
	QRadioButton * radialRadio;        //������������

	QLineEdit * partNameOutput;        //����� ������
	QLineEdit * moveNameInput;        //���� ��������
	QLineEdit * shiftInput;            //���� ��������
	QLineEdit * axisOutput;            //����� ���
	QLineEdit * startStepInput;        //���� ���������� ����
	QLineEdit * endStepInput;          //���� ��������� ����

	QPushButton * partAddButton;       //������� ������
	QPushButton * partDropButton;      //�������� ������
	QPushButton * axisAddButton;       //�������� ���
	QPushButton * axisDropButton;      //�������� ���
	QPushButton * moveAddButton;       //�������� ��������
	QPushButton * moveDropButton;      //�������� ������ �������

	QTableWidget * moveList;
	QHeaderView * moveListHeader;
	QStringList  moveListLabels;

	int stepCount; //����� ����� �����

};
