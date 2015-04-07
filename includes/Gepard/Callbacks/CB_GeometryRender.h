///////////////////////////////////////////////////////////
//  CB_GeometryRender.h
//  Реализация 	Class CB_GeometryRender
//  Создана:   	08-окт-2013 17:00:12
//  Автор: 		Dr_Freeman
///////////////////////////////////////////////////////////

#pragma once
#ifndef CB_GEOMETRY_RENDER_H_
#define CB_GEOMETRY_RENDER_H_

#include "../Visualization/GCamera.h"
#include "../General/basicList.h"
#include "../General/basicArray.h"

namespace Gepard 
{
    namespace Callbacks 
    {
//----------------------------------------------------------------------------------------------------
        /**
         *  Виртуальный класс принимает все реакции, поступающие от камеры
         */
        class GeometryRenderCallback 
        {
        public:
            GeometryRenderCallback();
            ~GeometryRenderCallback();

            /**
             *  Виртуальная функция обратного вызова - реакции на действия пользователя             
             */
            virtual void renderCallbackEvent(Gepard::Visualization::GCallbackMessage _message);

            /**
             *  Виртуальная функция - вызывается, при закрытии рендера
             */
            virtual void CloseRenderEvent(int RenderNum);

        };

        typedef Gepard::General::basicList<GeometryRenderCallback*> GeometryRenderCallbackPtrList;

        /**
         *  Массив элементов GeometryRenderCallBack
         */
        extern GeometryRenderCallbackPtrList CB_GeometryRenderCallbackPtrList;               

        /**
        *  Глобальная функция обратного вызова - сюда поступают все реакции от всех зарегистрированных камер
        */
        void CB_RenderCallbackEvent(Gepard::Visualization::GCallbackMessage _message);

        /**
         *  Глобальная функция обратного вызова - сюда поступают реакции, когда рендер закрывается
         */
        void CB_RenderCloseEvent( int NumRender );

//----------------------------------------------------------------------------------------------------
        /**
         *  Массив камер
         */
        extern Gepard::General::basicArray<Gepard::Visualization::GCamera*> CB_GCameraPtrArray;

        /**
         *  Флаг закрытия и удаления камеры0
         */
        extern bool isCloseCamera0;

//----------------------------------------------------------------------------------------------------
        /**
         *  Класс - менеджер камер. Нужно работать с ним
         *  Синглтон
         */
        class GeometryRenderManager
        {
        public:
            /**
             *  Шаблонная функция создания камеры - сразу происходит регистрация камеры
             *  (если isRegister=true)
             *  Для использования - подключить CB_GeometryRender.hpp
             */
            template <typename T>
            static T* CreateCamera(bool isRegister=true);

            /**
             *  Функция возвращает количество зарегистрированных камер
             */
            static int getCamerasCount();

            /**
            *  Функция закрывает все камеры и удаляет их память
            */
            static void CloseCameras();

            /**
             *  Удаляет камеру из массива.
             *  Если isDeleteMemory = true, то удаляет память
             */
            static void UnregisterGCamera( Gepard::Visualization::GCamera *_gCameraPtr, bool isDeleteMemory = false );

            /**
             *  Получить камеру из массива камер
             */
            static Gepard::Visualization::GCamera* GetCamera(unsigned int CameraIndex);

            /**
             *  Получить номер камеры в массиве камер
             */
            static int GetCameraIndex(Gepard::Visualization::GCamera* _gCameraPtr);

            /**
             *  Функция регистрации камеры - чтобы камера могла отправлять сообщения             
             */
            static void RegisterGCamera( Gepard::Visualization::GCamera *_gCameraPtr );

            /**
             *  Зарегистрировать класс для получения реакций от камер
             */
            static void RegisterRenderCallbackClass( GeometryRenderCallback* _geometryRenderCallbackPtr );

            /**
             *  Удалить класс получения реакций от камер
             */
            static void UnregisterRenderCallbackClass( GeometryRenderCallback* _geometryRenderCallbackPtr );

            /**
             *  Обновить номера камер
             */
            static void UpdateCamerasNums();

            /**
             *  Установить флаг удаления камеры0
             */
            static void SetCloseCamera0(bool isClose=true);

        private:
            GeometryRenderManager(){isCloseCamera0 = true;};
            ~GeometryRenderManager();
            GeometryRenderManager(const GeometryRenderManager& grm);
            GeometryRenderManager& operator=(const GeometryRenderManager& grm);

        static GeometryRenderManager geometryRenderManagerInstance;        
        };


    }
}
#endif

