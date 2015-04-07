///////////////////////////////////////////////////////////
//  GCamera.h
//  Implementation of the Class GCamera
//  Created on:      19-авг-2013 21:39:27
//  Original author: Anton
///////////////////////////////////////////////////////////

#if !defined(GPD_CA5451FC_1171_4820_A2DF_9AC89575B821__INCLUDED_)
#define GPD_CA5451FC_1171_4820_A2DF_9AC89575B821__INCLUDED_

#include "GSceneItem.h"
#include "SpecialObjects/GReper.h"
#include "SpecialObjects/GPrecScale.h"
#include "fps_counter.h"

/**
*  Определение функции обратного вызова для камеры - возврат действий пользователя
*/
typedef void(*GCameraCallbackFunc)(Gepard::Visualization::GCallbackMessage _message);


namespace Gepard
{
    namespace Visualization
    {             
        using namespace SpecialObjects;       

        /**
         * Класс содержит параметры отображения и виртуальные функции визуализации.
         */
        class GCamera
        {            
            friend class GPDGeometryRender;

        public:

            /**
             *  Настройки ориентации камеры
             */
            GCameraOrientationSetting CameraOrientationSetting;
            /**
             *  Настройки ортогональной камеры
             */
            GOrthoCameraSetting CurrentOrthoCameraSetting;
            /**
             *  Настройки рендера
             */
            GRenderSetting RenderSetting;
            /**
             *  Реакции пользователя
             */
            GUserAction UserAction;                                 


        public:

            GCamera();
            virtual ~GCamera();
                                               
            /**
             *  Функция очищает все графические данные камеры
             */
            virtual void ClearCameraData();

            /**
             *  Функция подготавливает геометрию для отображения
             */
            void PrepareRenderData( GSceneItem *itemPtr=nullptr );
                      
            /**
             *  Установить ориентацию камеры
             */
            bool SetCameraOrientation(float CameraFromX, float CameraFromY, float CameraFromZ, 
                                      float CameraToX, float CameraToY, float CameraToZ);
                       
            
            /**
             *  Установить размеры окна рендера
             */
            void SetRenderSize(int left, int top, int width, int height);
           

            /**
             *  Реакция на действия с мышью
             */
            void MouseEvent(GCAMERA_EVENT camera_event, int X, int Y, bool isShift=false, bool isCtrl=false );
            
            /**
             *  Реакция на действия с клавиатуры
             */
            void KeyboardEvent(GCAMERA_EVENT camera_event, bool isShift = false, bool isCtrl = false);

            /**
             *  Инициализация параметров OpenGL - размеры уже должны быть выставлены
             */
            void InitCamera();
          
            /**
             *  Установить размеры камеры
             */
            void ResizeCamera(int nWidth, int nHeight);

            //-> Тип камеры (Проекционное преобразование)

            void UseOrthoCamera(double Left, double Right, double Bottom, double Top, double Near, double Far);
                       

            /**
             *  Установка параметра - отображение осей ГСК
             */
            void ShowGCSAxes(bool isShow);

            /**
             *  Создать участок графической сцены
             */
            GSceneItem* CreateGSceneItem();

            /**
             *  Создать графический объект и добавить его в массив объектов
             */            
            GObject* CreateGObject( GSceneItem *sceneItem = nullptr );

            /**
             *  Создать графический примитив и добавить его в массив примитивов указанного объекта
             *  Если объект не указан, примитив будет добавлен к последнему добавленному объекту
             *  Если объектов еще не было, он будет создан и примитив добавится к нему
             */
            GPrimitive* CreateGPrimitive(GPRIMITIVE_TYPE primitive_type, GObject* gObjectPtr=nullptr);

            /**
             *  Создать графический текстовый объект
             */
            GText*  CreateGText(GSceneItem *sceneItem = nullptr);

            /**
             *  Удалить текстовый объект
             */
            void DeleteGText(GText* _text);

            /**
             *  Удалить все текстовые объекты
             */
            void DeleteGTexts();

            /**
             *  Создать специальный графический объект
             */
            SpecialGObject* CreateSpecialGObject(SpecialGObject::SGO_TYPE obj_type);

            /**
             *  Удалить специальный графический объект
             */
            void DeleteSpecialGObject(SpecialGObject *specObjPtr);
                       
             /**
             *  Функция устанавливает специальные параметры материала для объекта
             */
            void SetObjectMaterial( void* ObjDataPtr, float (ambient)[4], float (diffuse)[4], 
                                                      float (specular)[4], float (emission)[4], 
                                                      float shininess );

            /**
             *  Функция устанавливает цвет графического объекта
             */
            void SetObjectColor( void* ObjDataPtr, float R, float G, float B, float Alpha );
            /**
             *  Функция устанавливает цвет графического объекта
             */
            void SetObjectColor( void* ObjDataPtr, GColor _color );

            /**
             *  Сбросить цвет графического объекта
             */
            void DropObjectColor( void* ObjDataPtr );

            /**
             *  Установить функцию обратного вызова
             */
            void SetCallBackFunction(GCameraCallbackFunc _callbackFunc);

            /**
             *  Привязать данные к графическому объекту
             */
            void SetObjectData( GObject* ObjPtr, GObjectDataType _DataType, void *dataPtr );

            /**
             *  Выделить объект по типу и указателю
             */
            void SetObjectSelection(void *dataPtr, bool select = true);

            ///ВИРТУАЛЬНЫЕ ФУНКЦИИ

            /**
             *  Виртуальная функция - закрыть камеру
             */
            virtual void CloseCamera();

            /**
             *  Виртуальная функция - Показать камеру
             */
            virtual void ShowCamera();
            
            /**
             *  Получить номер камеры
             */
            unsigned int GetCameraNum() const;

            /**
             *  Присвоить номер камеры
             */
            void SetCameraNum( unsigned int num );

            /**
             *  Обновить камеру
             */
            void RefreshCamera();                       

            /**
             *  Функция копирует настройки рендера
             */
            void CopyCameraSettingsTo(GCamera &cameraTo);

            /**
             *  Установить настройки камеры
             */
            void SetCameraSettings(unsigned long _Flags);

            /**
             *  Удалить участок сцены по индексу
             */
            void DeleteSceneItem(GSceneItem *itemPtr);

            /**
             *  Установить видимость участка сцены
             */
            void SetSceneItemVisible(GSceneItem *itemPtr, bool isVisible);

             /**
              * Изменить координаты графического объекта (по указателю на данные, привязанные к этому объекту)
              * Второй аргумент - ссылка на лямбда-функцию.
              * Параметр лямбда-функции - указатель на вершинный массив 
              * (по этому адресу находится конкретная точка объекта).
              */
             void ModifyObject(void *object_data_ptr, std::function<void(float *)> &funcRef);

             /**
              * Установить эквивалентные номинальному координаты целевого объекта
              * Объекты должны быть идентичные
              */
             void SetEquivalent(void *nominal_obj, void *target_obj);

             /**
              * Получить указатель на менеджер шрифтов
              */
             GFontManager* GetFontManager();

             /**
              * Сброс сдвига камеры
              */
             void DropCenterCamShift();

             /**
              * Центрировать камеру относительно сдвига
              */
             void SetCenterToCamShift();

             /**
              * Сделать скриншот сцены и сохранить в указанный файл (TGA)
              */
             void MakeTGAScreenShot(std::string fileName);

             /**
              * Сделать скриншот сцены и сохранить в указанный файл (PNG)
              */
             void MakePNGScreenShot(std::string fileName);

             /**
              * Сохранить настройки камеры
              */
             void save(std::ostream &os);

             /**
              * Загрузить настройки камеры
              */
             void load(std::istream &is);

             /**
              *	 Сделать текущим контекст OpenGL для данной камеры
              */
             virtual void SetCurrentGLContext();

             /**
              *	Установить сдвиг камеры
              */
             void SetCameraShift(float (&cam_shift)[3]);

        protected:

            /**
             *  Задает параметры ортогональной матрицы отображения
             */
            void UseOrthoCamera();

            /**
             *  Функция отрисовки геометрии
             *  isSelection - режим выбора
             */
            void DrawGeometry(bool isSelection=false );

            /**
             *  Функция "обратного вызова" от камеры
             */
            virtual void CallbackEvent(Gepard::Visualization::GCallbackMessage _message);

            /**
             *  Найти часть сцены, в которой находится объект (objIndex - индекс объекта в массиве)
             */
            GSceneItem* FindSceneItem( GObject* objPtr, int *objIndex = nullptr );

            /**
             *  Получить указатель на графический объект
             */
            GObject* GetGObject(void *dataPtr);

            /**
             *  Установить флаг инициализации камеры
             */
            void SetCameraInitFlag(){isInit = true;}

        private:

            /**
            *  Параметры трансформации сцены
            */
            enum GC_TRANS
            {
                trans_flag   = 1<<1,  //флаг перемещения позиции камеры
                scale_flag   = 1<<2,  //флаг масштаба
                shift_flag   = 1<<3,  //флаг относительного сдвига камеры
                rotate_flag  = 1<<4,  //флаг поворота сцены
                unscale_flag = 1<<5,  //флаг обратного масштаба
                unshift_flag = 1<<6   //флаг обратного относительного сдвига

                ,no_unshift_flag = trans_flag | scale_flag | shift_flag | rotate_flag //флаг без обратного сдвига
                ,default_flag    = no_unshift_flag | unshift_flag                     //флаг по умолчанию
            };

            /**
            *  Трансформация камеры - для отображения
            */
            void TransformScene(unsigned long transFlags = default_flag);

            /**
             *  Отрисовка участка сцены
             */
            void DrawSceneItem(GSceneItem &sItem, unsigned int &indexer, bool isSelection);

            /**
             *  Отрисовка текстовых объектов
             */
            void DrawSceneItemText(GSceneItem &sItem);
                      
            /**
             *  Отрисовка осей в левом нижнем углу
             */
            void OSDShowAxes();

            /**
             *  Отрисовка градиента на заднем фоне
             */
            void DrawGradientBackground();

            /**
             *  Реакция на действия мыши
             */
            void MouseReaction();

            /**
             *  Реакция на движение объекта
             */
            void MoveObjectReaction( int offsetX, int offsetY );

            /**
             *  Вращение камеры
             */
            bool RotateCamera(int XMouseOffset, int YMouseOffset);
            /**
             *  Сдвиг камеры
             */
            bool OffsetCamera(int XMouseOffset, int YMouseOffset);

            /**
             *  Преобразование координат
             */
            void SR_2D_TO_3D(double Pointx_X, double Point_Y, double (&coords)[3] );

             /**
             * Возвращение расположения окна по ось X (Left)
             */
            int GetRenderLeft() const;
            /** 
             * Возвращение расположения окна по ось Y (Top)
             */
            int GetRenderTop()  const;
            /** 
             * Возвращение ширины окна (Width)
             */
            int GetRenderWidth()  const;        
            /** 
             * Возвращение высоты окна (Height)
             */
            int GetRenderHeight()  const;

             /**
             *  Функция устанавливает параметры материала по умолчанию
             */
            void SetDefaultObjectMaterial();

            /**
             *  Функция включает лампу0 по умолчанию
             */
            void SetDefaultLight0();

            /**
             *  Функция устанавливает текущие параметры материала для объекта
             */
            void SetCustomObjectMaterial(float (ambient)[4], float (diffuse)[4], 
                                         float (specular)[4], float (emission)[4], 
                                         float shininess);

            /**
             *  Функция устанавливает текущие параметры материала для объекта
             */
            void SetCustomObjectMaterial( ObjectMaterial &_material );

            /**
             *  Установить параметры для дополнительного объекта данных             
             */
            void SetAdditionalObjectData(GObjectDataType _DataType, void *dataPtr);

            /**
             *  Функция вызывает функцию обратного вызова.
             *  При этом, формируется сообщение GCallbackMessage по заданным параметрам
             *  Если _Object==nullptr, то используется указатель на AdditionalObjectData
             */
            void CallCameraCallbackEvent( GMessageType _MessageType = GMT_ON_SELECT,                                          
                                          GObjectData* _Object = nullptr, 
                                          std::vector<float> coords = std::vector<float>(),
                                          std::vector<float> extra = std::vector<float>() );

            /**
             *  Функция обрабатывает данные о выбранных объектах
             */
            void ProcessSelectedObjects();
                      
            /**
             *  Удалить данные по объекту
             */
            void ClearObjectData(GObject *objPtr);
         
            /**
             *  Функция находит для заданного объекта указатель на участок графической сцены и индекс объекта
             */
            bool FindObjectScene(void *object_data_ptr, GSceneItem* &sItemPtr, int &obj_index);

            /**
             *  Получить последний созданный участок сцены или создать его (если нет)
             */
            GSceneItem* GetOrCreateSceneItem();

            /**
             *  Отрисовка специальных графических объектов
             */
            void DrawSpecialGObjects(bool isDepthOn);

            /**
             *  Список SceneItem-ов
             */
            std::list<GSceneItem> SceneItemList;

            /**
             *  Функция обратного вызова для реакции на события
             */
            GCameraCallbackFunc CameraEventFunc;

            /**
             *  Номер камеры
             */
            unsigned int CameraNum;

            /**
             *  Камера инициализирована
             */
            bool isInit;

            /**
             *  Объект данных, формируемый извне функцией SetAdditionalObjectData
             *  Нужен, когда, например, пользователь выбирает тело 
             *  (его как объекта в массиве объектов данных не существует)
             */
            GObjectData AdditionalObjectData;

            /**
             *  Список привязок данных к графическим объектам
             */
            std::list<GObjectData> DataList;

            /**
             *  Выбранные в данный момент графические объекты
             */
            boost::unordered_set< GObject* > ObjSelected;                      

///ХЭШ-ТАБЛИЦЫ ПРИВЯЗОК ОБЪЕКТОВ
            /**
             * Хэш-таблица содержит информацию о материале объекта
             */
            boost::unordered_map< GObject*, ObjectMaterial> ObjMaterials;

            /**
             *  Хэш-таблица содержит привязку объекта к данным
             */
            boost::unordered_map< GObject*, GObjectData* > ObjData;
            
            /**
             *  Хэш-таблица привязки объекта данных с графическим объектом
             */
            boost::unordered_map<void*,GObject*> ObjDataToGObject;

            /** 
             * Хэш-таблица цветов объектов для выбора
             */
            boost::unordered_map< unsigned int, GObject* > ObjSelColors;
///ХЭШ-ТАБЛИЦЫ ПРИВЯЗОК ОБЪЕКТОВ          

            /**
             *  Менеджер шрифтов
             */
            GFontManager fontManager;          

            /**
             *  Ось глобальной системы координат
             */
            GReper GCS_Reper;

            /**
             *  Виджет ГСК
             */
            GReper GCS_Widget;               

            /**
             *  Массив специальных объектов
             */
            std::list<SpecialGObject*> SpecialObjects;

            /**
             *	Счетчик FPS
             */
            fps_counter _fpsCounter;

            /**
             *	Текст для информации
             */
            GText _infoText;

            /**
             *	Тест для надписи "Демонстрация"
             */
            GText _demoText;
        };

    }

}
#endif // !defined(GPD_CA5451FC_1171_4820_A2DF_9AC89575B821__INCLUDED_)
