///////////////////////////////////////////////////////////
//  CB_GeometryRender.h
//  ���������� 	Class CB_GeometryRender
//  �������:   	08-���-2013 17:00:12
//  �����: 		Dr_Freeman
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
         *  ����������� ����� ��������� ��� �������, ����������� �� ������
         */
        class GeometryRenderCallback 
        {
        public:
            GeometryRenderCallback();
            ~GeometryRenderCallback();

            /**
             *  ����������� ������� ��������� ������ - ������� �� �������� ������������             
             */
            virtual void renderCallbackEvent(Gepard::Visualization::GCallbackMessage _message);

            /**
             *  ����������� ������� - ����������, ��� �������� �������
             */
            virtual void CloseRenderEvent(int RenderNum);

        };

        typedef Gepard::General::basicList<GeometryRenderCallback*> GeometryRenderCallbackPtrList;

        /**
         *  ������ ��������� GeometryRenderCallBack
         */
        extern GeometryRenderCallbackPtrList CB_GeometryRenderCallbackPtrList;               

        /**
        *  ���������� ������� ��������� ������ - ���� ��������� ��� ������� �� ���� ������������������ �����
        */
        void CB_RenderCallbackEvent(Gepard::Visualization::GCallbackMessage _message);

        /**
         *  ���������� ������� ��������� ������ - ���� ��������� �������, ����� ������ �����������
         */
        void CB_RenderCloseEvent( int NumRender );

//----------------------------------------------------------------------------------------------------
        /**
         *  ������ �����
         */
        extern Gepard::General::basicArray<Gepard::Visualization::GCamera*> CB_GCameraPtrArray;

        /**
         *  ���� �������� � �������� ������0
         */
        extern bool isCloseCamera0;

//----------------------------------------------------------------------------------------------------
        /**
         *  ����� - �������� �����. ����� �������� � ���
         *  ��������
         */
        class GeometryRenderManager
        {
        public:
            /**
             *  ��������� ������� �������� ������ - ����� ���������� ����������� ������
             *  (���� isRegister=true)
             *  ��� ������������� - ���������� CB_GeometryRender.hpp
             */
            template <typename T>
            static T* CreateCamera(bool isRegister=true);

            /**
             *  ������� ���������� ���������� ������������������ �����
             */
            static int getCamerasCount();

            /**
            *  ������� ��������� ��� ������ � ������� �� ������
            */
            static void CloseCameras();

            /**
             *  ������� ������ �� �������.
             *  ���� isDeleteMemory = true, �� ������� ������
             */
            static void UnregisterGCamera( Gepard::Visualization::GCamera *_gCameraPtr, bool isDeleteMemory = false );

            /**
             *  �������� ������ �� ������� �����
             */
            static Gepard::Visualization::GCamera* GetCamera(unsigned int CameraIndex);

            /**
             *  �������� ����� ������ � ������� �����
             */
            static int GetCameraIndex(Gepard::Visualization::GCamera* _gCameraPtr);

            /**
             *  ������� ����������� ������ - ����� ������ ����� ���������� ���������             
             */
            static void RegisterGCamera( Gepard::Visualization::GCamera *_gCameraPtr );

            /**
             *  ���������������� ����� ��� ��������� ������� �� �����
             */
            static void RegisterRenderCallbackClass( GeometryRenderCallback* _geometryRenderCallbackPtr );

            /**
             *  ������� ����� ��������� ������� �� �����
             */
            static void UnregisterRenderCallbackClass( GeometryRenderCallback* _geometryRenderCallbackPtr );

            /**
             *  �������� ������ �����
             */
            static void UpdateCamerasNums();

            /**
             *  ���������� ���� �������� ������0
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

