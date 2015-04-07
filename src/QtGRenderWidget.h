///////////////////////////////////////////////////////////
//  QtGRenderWidget.h
//  ������ ��� ����������� ���������
//  Created on:      27-���-2013 15:09:41
//  Original author: Anton
///////////////////////////////////////////////////////////

#ifndef QT_GRENDER_WIDGET_H
#define QT_GRENDER_WIDGET_H

#include <Gepard/Visualization/GPDGeometryRender.h>

#include <QtGui>
#include <QtOpenGL/QGLWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QToolBar>


   /**
    * ����� ��� ����������� �������������� ���������� � �������������� � �������������
    */
    class QtGRenderWidget : public QGLWidget
                           ,public Gepard::Visualization::GPDGeometryRender
    {
        Q_OBJECT

    public:

        QtGRenderWidget(bool deleteOnClose = true, QWidget *parent = NULL);
        ~QtGRenderWidget();

        /**
         *  ����������� ������� - ������� ������
         */
        void CloseCamera() override;

        /**
        * ������� ���������� � ��������� ����(�������) ��� ����������� ��� ��������
        */
        void RepaintContent();

        /**
         *  ����� �� ��������� ������ ��� ����������� ������� � ��������
         */
        void SetCloseFlag(bool isClose);

        /**
         *  ����� �� ���������� ������ ��� ����������� ������� � ������
         */
        void SetShowFlag(bool isShow);

        /**
         *	 ������� ������� �������� OpenGL ��� ������ ������
         */
        void SetCurrentGLContext() override;

    signals:

        /**
         *  ������ ��������� ���������
         */
        void VisibilityChanged(bool isVisible);

        /**
         *  ������ "��������� ������"
         */
        void CallbackSignal(Gepard::Visualization::GCallbackMessage _message);

        /**
         *  ��������� ������ ����
         */
        void SizeChanged(int nWidth, int nHeight);

        /**
         *  ������ �������� ������
         */
        void CloseCameraSignal();

        /**
         *  ������ ������ �������
         */
        void ShowCameraSignal();

    protected:
        /**
         *  ������������� OpenGL
         */
        void initializeGL() override;

        /**
         *  ��������� �������� ����
         */
        void resizeGL(int nWidth, int nHeight) override;

        /**
         *  ����� ��������� ��������
         */
        void paintGL() override;

        /**
         *  ������� ������� �� ������� ������ ����
         */
        void mousePressEvent(QMouseEvent *event);
        /**
         *  ������� ������� �� ������������ ������ ����
         */
        void mouseReleaseEvent(QMouseEvent *event);
        /**
         *  ������� ������� �� �������� ����
         */
        void mouseMoveEvent(QMouseEvent *event);
        /**
         *  ������� ������� �� �������� �������� ����
         */
        void wheelEvent(QWheelEvent *event);
        /**
         *  ������� ������� �� ������� ������� �� ����������
         */
        void keyPressEvent(QKeyEvent *event);

        /**
        *  �������, ����� ����� ������������
        */
        void showEvent(QShowEvent *_event) override;

        /**
        *  �������, ����� ����� �����������
        */
        void hideEvent ( QHideEvent * event ) override;

        /**
        *  ������� "��������� ������" �� ������
        */
        void CallbackEvent(Gepard::Visualization::GCallbackMessage _message) override;
        
        /**
        *  ����������� ������� - �������� ������
        */
        void ShowCamera() override;

        /**    
         *  ����� �� ��������� ������ ��� ������ "CloseCamera"
         */
        bool isCloseOnCloseCamera;
         /**    
         *  ����� �� ���������� ������ ��� ������ "ShowCamera"
         */
        bool isShowOnShowCamera;
        };

#endif
