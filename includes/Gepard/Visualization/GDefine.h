///////////////////////////////////////////////////////////
//  GDefine.h
//  Implementation of the Class GDefine
//  Created on:      19-авг-2013 19:39:32
//  Original author: Anton
///////////////////////////////////////////////////////////

#if !defined(GPD_AF5C17F8_7A6C_43fb_8DA7_63080398086F__INCLUDED_)
#define GPD_AF5C17F8_7A6C_43fb_8DA7_63080398086F__INCLUDED_

#include "GVector.h"
#include <list>
#include <fstream>

//     TODO: Подумать над следующими вещами:
//     1) Экстра параметры для каждого примитива
//     2) Задание материала на объект
//     3) Задание просто цвета объекта без материала
//     4) Отображение специальных объектов
//     5) Динамическое удаление/редактирование массивов

//     6) Для объекта должны быть параметры:
//          - Тип и толщина линий у объекта, цвет этих линий
//          - Размер и цвет точек у объекта
//          - Дефолтные значения раскрасок

//     7) Сделать типы примитивов: GPT_LINE_STRIP, GPT_QUAD_STRIP? 

#include "Materials.h"

//Включать ли поддержку VBO
#define GPD_VBO_SUPPORT_CHECK

namespace Gepard
{
    namespace Visualization
    {
                
         /**
         *  Вершина
         */
        struct GVertex
        {
            float V[6];

            GVertex( float x, float y, float z, 
                     float nx=0.0f, float ny=0.0f, float nz=0.0f )
            {
                V[0] = x;  V[1] = y;  V[2] = z;
                V[3] = nx; V[4] = ny; V[5] = nz;
            }

            friend bool operator==(const GVertex &v0, const GVertex &v1)
            {
                return ( v0.V[0] == v1.V[0] && 
                         v0.V[1] == v1.V[1] && 
                         v0.V[2] == v1.V[2] );
            }
        };


        /**
         *  Тип графического элемента
         */
        enum GPRIMITIVE_TYPE 
        {
             GPD_UNKNOWN    //Неизвестно
            ,GPT_LINE       //Линия
            ,GPT_POINT      //Точка
            ,GPT_TRIANGLE   //Треугольник
            ,GPT_QUAD       //Квадрат
        };

        /**
         *  Тип реакции
         */
        enum GCAMERA_EVENT
        {
            GCE_NO_EVENT,         //Нет события
//Mouse events
            GCE_MOUSELBUTTONDOWN, //Нажатие левой кнопки мыши
            GCE_MOUSERBUTTONDOWN, //Нажатие правой кнопки мыши
            GCE_MOUSEMBUTTONDOWN, //Нажатие средней кнопки мыши
            GCE_MOUSELBUTTONUP,   //Отпускание левой кнопки мыши
            GCE_MOUSERBUTTONUP,   //Отпускание правой кнопки мыши
            GCE_MOUSEMBUTTONUP,   //Отпускание средней кнопки мыши
            GCE_MOUSEMOVE,        //Движение мыши
            GCE_MOUSEWHEELDOWN,   //Прокрутка вниз
            GCE_MOUSEWHEELUP,     //Прокрутка вверх
//keyboard events
            GCE_KEY_ENTER,        //Клавиша ENTER
            GCE_KEY_DELETE        //клавиша DELETE
        };


        class GCamera;
        enum GMessageType {
                GMT_ON_SELECT             //Выбран объект
              , GMT_ON_LOST_SELECT        //Селект потерян
//               , GMT_ON_ADD_TO_GROUP         //Объект добавлен в группу выбора
//               , GMT_ON_REMOVE_FROM_GROUP    //Объект удален из группы выбора
              , GMT_ON_MOVE_OBJECT
              , GMT_ON_KEY_DELETE
              , GMT_ON_KEY_ENTER
        };
                
        
        /**
         *  Тип объекта, к которому привязан текущий графический объект
         */
        enum GObjectDataType
        {
             GODT_UNKNOWN    //Установлено пользователем
            ,GODT_FACE       //GPDFace
            ,GODT_SOLID      //GPDSolid
            ,GODT_FACEBOUND  //GPDFaceBound
            ,GODT_CONF_SPACE //Configurational space
            ,GODT_CS_POINT   //Conf space point
            ,GODT_CS_SURF    //Conf space Surface
            ,GODT_CS_TOLFACE //Пара значений - грань и точка к.п.
        };

        /**
         *  Основные параметры камеры
         */
        enum GCAMERA_SETTINGS
        {
             GCS_NONE            =   0
            ,GCS_SHOW_AXES       =   1<<1    //Отображение осей ГСК
            ,GCS_SHOW_WIDGETS    =   1<<2    //Отображение дополнительных виджетов
            ,GCS_GRADIENT_FILL   =   1<<3    //Градиентная заливка заднего фона
            ,GCS_SHOW_LOGO       =   1<<4    //Отображение лого
            ,GCS_SELECTABLE      =   1<<5    //Возможность выбора объектов
            ,GCS_MULTISELECT     =   1<<6    //Возможность выбора нескольких объектов
            ,GCS_ROTATABLE       =   1<<7    //Возможность поворота
            ,GCS_MOVABLE         =   1<<8    //Возможность сдвига
            ,GCS_SCALABLE        =   1<<9    //Масштабирование
            ,GCS_SHOW_OSD_AXES   =   1<<10   //Отображение осей слева снизу
            ,GCS_SHIFTABLE       =   1<<11   //Относительный сдвиг камеры
            ,GCS_SHOW_FPS        =   1<<12   //Показывать FPS
        };

        /**
         *  Параметры участка графической сцены
         */
        enum GSCENE_ITEM_SETTINGS
        {
             GSI_SELECTABLE     = 1<<1  //Возможность выбора объектов
//             ,GSI_MULTISELECT    = 1<<2  //Возможность мультиселекта
//             ,GSI_ZOOMABLE       = 1<<3  //Масштабирование
//             ,GSI_ROTATABLE      = 1<<4  //Поворот
//             ,GSI_TRANSLATABLE   = 1<<5  //Перенос
            ,GSI_MOVABLE        = 1<<6  //Передвижение объекта - вызов функции обьратного вызова
            ,GSI_OBJ_COLOR      = 1<<7  //Использовать цвет - если не задано, используется материал
            ,GSI_HIGHLIGHT_SELECTED  = 1<<8  //подсвечивать ли выбранные объекты
            ,GSI_OBJ_ONLY_COLOR = 1<<9 //Использовать только цвет объекта 
                                       //- без учета нормалей и света (флаг задается отдельно от GSI_OBJ_COLOR)
            ,GSI_KBRD_REACTION  = 1<<10 //Реагировать на клавиатуру
            ,GSI_NO_DEPTH       = 1<<11 //Отключенный буфер глубины
            ,GSI_CULL_BACK_FACE = 1<<12 //Скрывать нелицевые грани
        };

        /**
         *  Объект данных, привязанных к графическому объекту
         */
        struct GObjectData
        {
            GObjectData()
            {
                ObjectData = nullptr;
                _type = GODT_UNKNOWN;
            };

            GObjectData(GObjectDataType _t, void *_p)
                :_type(_t), ObjectData(_p)
            {}

        /**
         *  Тип объекта данных
         */
            GObjectDataType _type;
        /**
         *  Указатель на объект данных
         */
            void* ObjectData;
        };

        /**
         *  Структура сообщения, возвращаемого функцией
         */
        struct GCallbackMessage
        {            
            GCallbackMessage()
            {
                for (int i=0; i<6; i++) coords[i] = 0.0f;

                cameraPtr = nullptr;
                _Object = nullptr;
            }
            //TODO:
            //std::list<void*> ObjectsArray;  //Массив объектов под курсором, отсортированных по удаленности
                        
            GMessageType MessageType;     //Тип возвращаемого сообщения
            GCamera *cameraPtr;           //Указатель на камеру, в которой произошло событие                    
            GObjectData* _Object;         //Указатель на текущий выбранный объект, привязанный к текущему графическому объекту            
            float coords[6];              //Координаты селективного отрезка P0(x,y,z) - P1(x,y,z)
            std::vector<float> extra_coords; //Дополнительные координаты (например, для векторов или точек)

        };

//         //->Визуальные настройки
//         static float GNormalMaterialEmission[4] = {0.0f,0.0f,0.0f,1.0f};
//         static float GFocusedMaterialEmission[4] = {0.2f,0.2f,0.2f,1.0f};
         static float GSelectedMaterialEmission[4] = {0.35f,0.35f,0.35f,1.0f};
//         //static float GMaterialSpecular[4] = {0.2f,0.2f,0.2f,1.0f};
//         static float GNormalMaterialSpecular[4] = {0.0f,0.0f,0.0f,1.0f};
         
         static float GDefaultPrimitiveColor[4] = {0.15f,0.15f,0.65f,1.0f}; //Цвет примитива по умолчанию
         static float GDefaultSelectedColor[4]  = {1.0f,0.0f,0.0f,1.0f };   //Цвет по умолчанию для выбранных объектов

       

        //-> Структура ориентации камеры
        struct GCameraOrientationSetting
        {
            GVector CameraPositionFrom, CameraPositionTo, CameraShadowX, CameraShadowY, CameraShadowZ;
            GVector CameraPosition;
            double Scale;

            friend std::ostream& operator<<(std::ostream& os, const GCameraOrientationSetting &s )
            {
                os << s.CameraPositionFrom;
                os << s.CameraPositionTo;
                os << s.CameraPosition;
                os << s.CameraShadowX;
                os << s.CameraShadowY;
                os << s.CameraShadowZ;
                os.write((char*) &s.Scale, sizeof s.Scale);
                return os;
            }

            friend std::istream& operator>>(std::istream& is, GCameraOrientationSetting &s )
            {
                is >> s.CameraPositionFrom;
                is >> s.CameraPositionTo;
                is >> s.CameraPosition;
                is >> s.CameraShadowX;
                is >> s.CameraShadowY;
                is >> s.CameraShadowZ;
                is.read((char*) &s.Scale, sizeof s.Scale);
                return is;
            }
        };


        //-> Структура настроек камер

        struct GOrthoCameraSetting
        {
            double Left;
            double Right;
            double Bottom;
            double Top;
            double Near;
            double Far;

            friend std::ostream& operator<<(std::ostream& os, const GOrthoCameraSetting &s )
            {
                os.write((char*) &s, sizeof s);
                return os;
            }

            friend std::istream& operator>>(std::istream& is, GOrthoCameraSetting &s )
            {
                is.read((char*) &s, sizeof s);
                return is;
            }

        };


        //-> Пользовательские манипуляции

        struct GMousePosition
        {
            int X, Y;
        };

        struct GMouseButton
        {	
            bool
                ButtonDownStatus, ButtonDownCtrl, ButtonDownShift,
                ButtonUpStatus, ButtonUpCtrl, ButtonUpShift;

            GMousePosition ButtonUpPosition, ButtonDownPosition;			

            GMouseButton() {clearFlags();}

            void clearFlags()
            {
                ButtonDownStatus = ButtonDownCtrl = ButtonDownShift = false;
                ButtonUpStatus = ButtonUpCtrl = ButtonUpShift = false;
            }
        };

        struct GUserAction
        {
            GMouseButton RightButton, LeftButton, ScrollButton, Scrolling;
            GMousePosition CurrentMousePosition;
        };

        struct GRenderSetting
        {
            int Left, Top, Width, Height;
            
            float BackGroundColor[4];   //Цвет очистки экрана

            float GradientColor0[4];    //Цвет градиента на заднем фоне
            float GradientColor1[4];
                        
            bool isShowAxes;        //Отображение осей ГСК
            bool isShowOSDAxes;     //Отображение осей слева внизу экрана
            bool isShowWidgets;     //Отображение дополнительных виджетов
            bool isGradientFill;    //Градиентная заливка заднего фона
            bool isShowLogo;        //Отображение лого
            //bool isShowFPS;         //Показывать FPS

            bool isSelectable;      //Возможность выбора объектов
            bool isMultiselect;     //Возможность выбора нескольких объектов
            bool isRotatable;       //Возможность поворота
            bool isMovable;         //Сдвиг камеры
            bool isScalable;        //Масштабирование
            bool isShiftable;       //Относительный сдвиг камеры

            GVector camShift;       //Сдвиг камеры - для поворотов относительно заданной точки

            GRenderSetting ()
            {
                isShowAxes = isShowLogo = isGradientFill = isShowWidgets = false;
                isSelectable = isRotatable = isMovable = isScalable = isShiftable = true;
                isMultiselect = false;
                
                isShowOSDAxes = true;
                //isShowFPS = false;

                //Цвет заливки по умолчанию
                BackGroundColor[0] = 0.9f;
                BackGroundColor[1] = 0.9f;
                BackGroundColor[2] = 0.9f;
                BackGroundColor[3] = 1.0f;

                isGradientFill = true;

                //Цвет градиента по умолчанию
                for (int i=0; i<3; i++) GradientColor0[i] = 1.0f;

                GradientColor0[3] = 0.01f;

                GradientColor1[0] = 0.0f;
                GradientColor1[1] = 0.0f;
                GradientColor1[2] = 1.0f;
                GradientColor1[3] = 0.12f;

            }

            bool isCamShift()
            {
                return (camShift.X()!=0.0 || camShift.Y()!=0.0 || camShift.Z()!=0.0);
            }

            friend std::ostream& operator<<(std::ostream& os, const GRenderSetting &s )
            {
                os.write((char*) &s, sizeof s);
                return os;
            }

            friend std::istream& operator>>(std::istream& is, GRenderSetting &s )
            {
                is.read((char*) &s, sizeof s);
                return is;
            }

        };


         /**
         *  Структура для описания индексного массива точек
         */
        struct PIndexes
        {
            unsigned int Count;         //Число точек в индексном массиве
            unsigned int CurPIndex;     //Текущий индекс точки
            unsigned int *IndexArray;   //Массив индексов

            PIndexes()
            {
                Count = CurPIndex = 0;
                IndexArray = nullptr;
            }

            PIndexes(unsigned int vertex_count) 
            {                
                Count = vertex_count;
                CurPIndex = 0;
                IndexArray = nullptr;
            }

            ~PIndexes()
            {
                if (IndexArray) delete [] IndexArray;
            }

            /**
             *  Создать массив
             */
            void CreateArray()
            {
                if (Count!=0) IndexArray = new unsigned int[Count];
            }
        };


        /**
         *	Структура параметров буферов объектов в VBO
         */
        struct ObjVBOBufferIndexes
        {
            ObjVBOBufferIndexes()
            {
                clear();
            }

            /**
             *  Имя буфера вершин в VBO
             */
            unsigned int _Vertices;

            /**
             *  Имя буфера вершин в VBO
             */
            unsigned int _Normals;

            /**
             *  Имя буфера цвета в VBO
             */
            unsigned int _Colors; 

            /**
             *  Имена буферов индексов в VBO для примитивов объектов
             */
            std::list<std::list<unsigned int>> _VIndexes;

            /**
             *	Очистка значений индексов
             */
            void clear()
            {
                _Vertices = 0;
                _Normals = 0;
                _Colors = 0;
                _VIndexes.clear();
            }
        };

        /**
         *	Поддержка VBO
         */
        struct VBOSupportCheck
        {
            VBOSupportCheck()
            {
                isGlewInit = false;
                isVBOSupported = false;
            }
            /**
             *	Инициализирован ли GLEW
             */
            bool isGlewInit;

            /**
             *	Поддерживается ли VBO
             */
            bool isVBOSupported;
        };
        /**
         *	Инстанс для проверки поддержки VBO
         */
        extern VBOSupportCheck vboSupport;


        /**
         *  Структура описания параметров материала
         */
        struct ObjectMaterial
        {
            float Ambient[4];
            float Diffuse[4];
            float Specular[4];            
            float Emission[4];
            float Shininess;
        };

    }

}
#endif // !defined(GPD_AF5C17F8_7A6C_43fb_8DA7_63080398086F__INCLUDED_)
