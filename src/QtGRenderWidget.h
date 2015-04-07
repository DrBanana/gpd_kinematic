///////////////////////////////////////////////////////////
//  QtGRenderWidget.h
//  Виджет для отображения геометрии
//  Created on:      27-авг-2013 15:09:41
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
    * Класс для отображения геометрической информации и взаимодействия с пользователем
    */
    class QtGRenderWidget : public QGLWidget
                           ,public Gepard::Visualization::GPDGeometryRender
    {
        Q_OBJECT

    public:

        QtGRenderWidget(bool deleteOnClose = true, QWidget *parent = NULL);
        ~QtGRenderWidget();

        /**
         *  Виртуальная функция - закрыть камеру
         */
        void CloseCamera() override;

        /**
        * Функция вызывается у дочернего окна(виджета) для перерисовки его контента
        */
        void RepaintContent();

        /**
         *  Нужно ли закрывать виджет при поступлении сигнала о закрытии
         */
        void SetCloseFlag(bool isClose);

        /**
         *  Нужно ли показывать виджет при поступлении сигнала о показе
         */
        void SetShowFlag(bool isShow);

        /**
         *	 Сделать текущим контекст OpenGL для данной камеры
         */
        void SetCurrentGLContext() override;

    signals:

        /**
         *  Сигнал изменения видимости
         */
        void VisibilityChanged(bool isVisible);

        /**
         *  Сигнал "Обратного вызова"
         */
        void CallbackSignal(Gepard::Visualization::GCallbackMessage _message);

        /**
         *  Изменился размер окна
         */
        void SizeChanged(int nWidth, int nHeight);

        /**
         *  Сигнал закрытия камеры
         */
        void CloseCameraSignal();

        /**
         *  Сигнал показа виджета
         */
        void ShowCameraSignal();

    protected:
        /**
         *  Инициализация OpenGL
         */
        void initializeGL() override;

        /**
         *  Изменение размеров окна
         */
        void resizeGL(int nWidth, int nHeight) override;

        /**
         *  Метод отрисовки контента
         */
        void paintGL() override;

        /**
         *  Функция реакции на нажатие кнопки мыши
         */
        void mousePressEvent(QMouseEvent *event);
        /**
         *  Функция реакции на освобождение кнопки мыши
         */
        void mouseReleaseEvent(QMouseEvent *event);
        /**
         *  Функция реакции на движение мыши
         */
        void mouseMoveEvent(QMouseEvent *event);
        /**
         *  Функция реакции на вращение колесика мыши
         */
        void wheelEvent(QWheelEvent *event);
        /**
         *  Функция реакции на нажатие клавиши на клавиатуре
         */
        void keyPressEvent(QKeyEvent *event);

        /**
        *  Событие, когда форма отображается
        */
        void showEvent(QShowEvent *_event) override;

        /**
        *  Событие, когда форма закрывается
        */
        void hideEvent ( QHideEvent * event ) override;

        /**
        *  Функция "обратного вызова" от камеры
        */
        void CallbackEvent(Gepard::Visualization::GCallbackMessage _message) override;
        
        /**
        *  Виртуальная функция - Показать камеру
        */
        void ShowCamera() override;

        /**    
         *  Нужно ли закрывать виджет при вызове "CloseCamera"
         */
        bool isCloseOnCloseCamera;
         /**    
         *  Нужно ли показывать виджет при вызове "ShowCamera"
         */
        bool isShowOnShowCamera;
        };

#endif
