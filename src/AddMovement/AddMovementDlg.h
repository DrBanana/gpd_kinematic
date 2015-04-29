
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


 //	����� ������� ������� ���������� �������� ������

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
    //������������ �����
    void flagPart();
    void flagFace();
    void flagNothing();

    void addMovement();
    void clearMovement();
    //����������� ������� ��������� ������ - ������� �� �������� ������������
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
    QPushButton * moverAdd;

    QTableWidget * moveList;
    QHeaderView * moveListHeader;
    QStringList  moveListLabels;

    int stepCount; //����� ����� �����
    int shift;
    Gepard::BasicMath::GPDVector shiftEnd;
    Gepard::BasicMath::GPDVector shiftStart;

    enum modeFlag{ PART, FACE, NOTHING };

    modeFlag currentMode;

    bool moveFlag;

    Gepard::BasicMath::GPDReper fReper;

    Gepard::Topology_Geometry::GPDSolid * newPart;  //��������� �� ������
    GAxis * newAxis;                                //�� ���


    vector<CMovements> newMovements;

};
