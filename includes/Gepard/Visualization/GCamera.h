///////////////////////////////////////////////////////////
//  GCamera.h
//  Implementation of the Class GCamera
//  Created on:      19-���-2013 21:39:27
//  Original author: Anton
///////////////////////////////////////////////////////////

#if !defined(GPD_CA5451FC_1171_4820_A2DF_9AC89575B821__INCLUDED_)
#define GPD_CA5451FC_1171_4820_A2DF_9AC89575B821__INCLUDED_

#include "GSceneItem.h"
#include "SpecialObjects/GReper.h"
#include "SpecialObjects/GPrecScale.h"
#include "fps_counter.h"

/**
*  ����������� ������� ��������� ������ ��� ������ - ������� �������� ������������
*/
typedef void(*GCameraCallbackFunc)(Gepard::Visualization::GCallbackMessage _message);


namespace Gepard
{
    namespace Visualization
    {             
        using namespace SpecialObjects;       

        /**
         * ����� �������� ��������� ����������� � ����������� ������� ������������.
         */
        class GCamera
        {            
            friend class GPDGeometryRender;

        public:

            /**
             *  ��������� ���������� ������
             */
            GCameraOrientationSetting CameraOrientationSetting;
            /**
             *  ��������� ������������� ������
             */
            GOrthoCameraSetting CurrentOrthoCameraSetting;
            /**
             *  ��������� �������
             */
            GRenderSetting RenderSetting;
            /**
             *  ������� ������������
             */
            GUserAction UserAction;                                 


        public:

            GCamera();
            virtual ~GCamera();
                                               
            /**
             *  ������� ������� ��� ����������� ������ ������
             */
            virtual void ClearCameraData();

            /**
             *  ������� �������������� ��������� ��� �����������
             */
            void PrepareRenderData( GSceneItem *itemPtr=nullptr );
                      
            /**
             *  ���������� ���������� ������
             */
            bool SetCameraOrientation(float CameraFromX, float CameraFromY, float CameraFromZ, 
                                      float CameraToX, float CameraToY, float CameraToZ);
                       
            
            /**
             *  ���������� ������� ���� �������
             */
            void SetRenderSize(int left, int top, int width, int height);
           

            /**
             *  ������� �� �������� � �����
             */
            void MouseEvent(GCAMERA_EVENT camera_event, int X, int Y, bool isShift=false, bool isCtrl=false );
            
            /**
             *  ������� �� �������� � ����������
             */
            void KeyboardEvent(GCAMERA_EVENT camera_event, bool isShift = false, bool isCtrl = false);

            /**
             *  ������������� ���������� OpenGL - ������� ��� ������ ���� ����������
             */
            void InitCamera();
          
            /**
             *  ���������� ������� ������
             */
            void ResizeCamera(int nWidth, int nHeight);

            //-> ��� ������ (������������ ��������������)

            void UseOrthoCamera(double Left, double Right, double Bottom, double Top, double Near, double Far);
                       

            /**
             *  ��������� ��������� - ����������� ���� ���
             */
            void ShowGCSAxes(bool isShow);

            /**
             *  ������� ������� ����������� �����
             */
            GSceneItem* CreateGSceneItem();

            /**
             *  ������� ����������� ������ � �������� ��� � ������ ��������
             */            
            GObject* CreateGObject( GSceneItem *sceneItem = nullptr );

            /**
             *  ������� ����������� �������� � �������� ��� � ������ ���������� ���������� �������
             *  ���� ������ �� ������, �������� ����� �������� � ���������� ������������ �������
             *  ���� �������� ��� �� ����, �� ����� ������ � �������� ��������� � ����
             */
            GPrimitive* CreateGPrimitive(GPRIMITIVE_TYPE primitive_type, GObject* gObjectPtr=nullptr);

            /**
             *  ������� ����������� ��������� ������
             */
            GText*  CreateGText(GSceneItem *sceneItem = nullptr);

            /**
             *  ������� ��������� ������
             */
            void DeleteGText(GText* _text);

            /**
             *  ������� ��� ��������� �������
             */
            void DeleteGTexts();

            /**
             *  ������� ����������� ����������� ������
             */
            SpecialGObject* CreateSpecialGObject(SpecialGObject::SGO_TYPE obj_type);

            /**
             *  ������� ����������� ����������� ������
             */
            void DeleteSpecialGObject(SpecialGObject *specObjPtr);
                       
             /**
             *  ������� ������������� ����������� ��������� ��������� ��� �������
             */
            void SetObjectMaterial( void* ObjDataPtr, float (ambient)[4], float (diffuse)[4], 
                                                      float (specular)[4], float (emission)[4], 
                                                      float shininess );

            /**
             *  ������� ������������� ���� ������������ �������
             */
            void SetObjectColor( void* ObjDataPtr, float R, float G, float B, float Alpha );
            /**
             *  ������� ������������� ���� ������������ �������
             */
            void SetObjectColor( void* ObjDataPtr, GColor _color );

            /**
             *  �������� ���� ������������ �������
             */
            void DropObjectColor( void* ObjDataPtr );

            /**
             *  ���������� ������� ��������� ������
             */
            void SetCallBackFunction(GCameraCallbackFunc _callbackFunc);

            /**
             *  ��������� ������ � ������������ �������
             */
            void SetObjectData( GObject* ObjPtr, GObjectDataType _DataType, void *dataPtr );

            /**
             *  �������� ������ �� ���� � ���������
             */
            void SetObjectSelection(void *dataPtr, bool select = true);

            ///����������� �������

            /**
             *  ����������� ������� - ������� ������
             */
            virtual void CloseCamera();

            /**
             *  ����������� ������� - �������� ������
             */
            virtual void ShowCamera();
            
            /**
             *  �������� ����� ������
             */
            unsigned int GetCameraNum() const;

            /**
             *  ��������� ����� ������
             */
            void SetCameraNum( unsigned int num );

            /**
             *  �������� ������
             */
            void RefreshCamera();                       

            /**
             *  ������� �������� ��������� �������
             */
            void CopyCameraSettingsTo(GCamera &cameraTo);

            /**
             *  ���������� ��������� ������
             */
            void SetCameraSettings(unsigned long _Flags);

            /**
             *  ������� ������� ����� �� �������
             */
            void DeleteSceneItem(GSceneItem *itemPtr);

            /**
             *  ���������� ��������� ������� �����
             */
            void SetSceneItemVisible(GSceneItem *itemPtr, bool isVisible);

             /**
              * �������� ���������� ������������ ������� (�� ��������� �� ������, ����������� � ����� �������)
              * ������ �������� - ������ �� ������-�������.
              * �������� ������-������� - ��������� �� ��������� ������ 
              * (�� ����� ������ ��������� ���������� ����� �������).
              */
             void ModifyObject(void *object_data_ptr, std::function<void(float *)> &funcRef);

             /**
              * ���������� ������������� ������������ ���������� �������� �������
              * ������� ������ ���� ����������
              */
             void SetEquivalent(void *nominal_obj, void *target_obj);

             /**
              * �������� ��������� �� �������� �������
              */
             GFontManager* GetFontManager();

             /**
              * ����� ������ ������
              */
             void DropCenterCamShift();

             /**
              * ������������ ������ ������������ ������
              */
             void SetCenterToCamShift();

             /**
              * ������� �������� ����� � ��������� � ��������� ���� (TGA)
              */
             void MakeTGAScreenShot(std::string fileName);

             /**
              * ������� �������� ����� � ��������� � ��������� ���� (PNG)
              */
             void MakePNGScreenShot(std::string fileName);

             /**
              * ��������� ��������� ������
              */
             void save(std::ostream &os);

             /**
              * ��������� ��������� ������
              */
             void load(std::istream &is);

             /**
              *	 ������� ������� �������� OpenGL ��� ������ ������
              */
             virtual void SetCurrentGLContext();

             /**
              *	���������� ����� ������
              */
             void SetCameraShift(float (&cam_shift)[3]);

        protected:

            /**
             *  ������ ��������� ������������� ������� �����������
             */
            void UseOrthoCamera();

            /**
             *  ������� ��������� ���������
             *  isSelection - ����� ������
             */
            void DrawGeometry(bool isSelection=false );

            /**
             *  ������� "��������� ������" �� ������
             */
            virtual void CallbackEvent(Gepard::Visualization::GCallbackMessage _message);

            /**
             *  ����� ����� �����, � ������� ��������� ������ (objIndex - ������ ������� � �������)
             */
            GSceneItem* FindSceneItem( GObject* objPtr, int *objIndex = nullptr );

            /**
             *  �������� ��������� �� ����������� ������
             */
            GObject* GetGObject(void *dataPtr);

            /**
             *  ���������� ���� ������������� ������
             */
            void SetCameraInitFlag(){isInit = true;}

        private:

            /**
            *  ��������� ������������� �����
            */
            enum GC_TRANS
            {
                trans_flag   = 1<<1,  //���� ����������� ������� ������
                scale_flag   = 1<<2,  //���� ��������
                shift_flag   = 1<<3,  //���� �������������� ������ ������
                rotate_flag  = 1<<4,  //���� �������� �����
                unscale_flag = 1<<5,  //���� ��������� ��������
                unshift_flag = 1<<6   //���� ��������� �������������� ������

                ,no_unshift_flag = trans_flag | scale_flag | shift_flag | rotate_flag //���� ��� ��������� ������
                ,default_flag    = no_unshift_flag | unshift_flag                     //���� �� ���������
            };

            /**
            *  ������������� ������ - ��� �����������
            */
            void TransformScene(unsigned long transFlags = default_flag);

            /**
             *  ��������� ������� �����
             */
            void DrawSceneItem(GSceneItem &sItem, unsigned int &indexer, bool isSelection);

            /**
             *  ��������� ��������� ��������
             */
            void DrawSceneItemText(GSceneItem &sItem);
                      
            /**
             *  ��������� ���� � ����� ������ ����
             */
            void OSDShowAxes();

            /**
             *  ��������� ��������� �� ������ ����
             */
            void DrawGradientBackground();

            /**
             *  ������� �� �������� ����
             */
            void MouseReaction();

            /**
             *  ������� �� �������� �������
             */
            void MoveObjectReaction( int offsetX, int offsetY );

            /**
             *  �������� ������
             */
            bool RotateCamera(int XMouseOffset, int YMouseOffset);
            /**
             *  ����� ������
             */
            bool OffsetCamera(int XMouseOffset, int YMouseOffset);

            /**
             *  �������������� ���������
             */
            void SR_2D_TO_3D(double Pointx_X, double Point_Y, double (&coords)[3] );

             /**
             * ����������� ������������ ���� �� ��� X (Left)
             */
            int GetRenderLeft() const;
            /** 
             * ����������� ������������ ���� �� ��� Y (Top)
             */
            int GetRenderTop()  const;
            /** 
             * ����������� ������ ���� (Width)
             */
            int GetRenderWidth()  const;        
            /** 
             * ����������� ������ ���� (Height)
             */
            int GetRenderHeight()  const;

             /**
             *  ������� ������������� ��������� ��������� �� ���������
             */
            void SetDefaultObjectMaterial();

            /**
             *  ������� �������� �����0 �� ���������
             */
            void SetDefaultLight0();

            /**
             *  ������� ������������� ������� ��������� ��������� ��� �������
             */
            void SetCustomObjectMaterial(float (ambient)[4], float (diffuse)[4], 
                                         float (specular)[4], float (emission)[4], 
                                         float shininess);

            /**
             *  ������� ������������� ������� ��������� ��������� ��� �������
             */
            void SetCustomObjectMaterial( ObjectMaterial &_material );

            /**
             *  ���������� ��������� ��� ��������������� ������� ������             
             */
            void SetAdditionalObjectData(GObjectDataType _DataType, void *dataPtr);

            /**
             *  ������� �������� ������� ��������� ������.
             *  ��� ����, ����������� ��������� GCallbackMessage �� �������� ����������
             *  ���� _Object==nullptr, �� ������������ ��������� �� AdditionalObjectData
             */
            void CallCameraCallbackEvent( GMessageType _MessageType = GMT_ON_SELECT,                                          
                                          GObjectData* _Object = nullptr, 
                                          std::vector<float> coords = std::vector<float>(),
                                          std::vector<float> extra = std::vector<float>() );

            /**
             *  ������� ������������ ������ � ��������� ��������
             */
            void ProcessSelectedObjects();
                      
            /**
             *  ������� ������ �� �������
             */
            void ClearObjectData(GObject *objPtr);
         
            /**
             *  ������� ������� ��� ��������� ������� ��������� �� ������� ����������� ����� � ������ �������
             */
            bool FindObjectScene(void *object_data_ptr, GSceneItem* &sItemPtr, int &obj_index);

            /**
             *  �������� ��������� ��������� ������� ����� ��� ������� ��� (���� ���)
             */
            GSceneItem* GetOrCreateSceneItem();

            /**
             *  ��������� ����������� ����������� ��������
             */
            void DrawSpecialGObjects(bool isDepthOn);

            /**
             *  ������ SceneItem-��
             */
            std::list<GSceneItem> SceneItemList;

            /**
             *  ������� ��������� ������ ��� ������� �� �������
             */
            GCameraCallbackFunc CameraEventFunc;

            /**
             *  ����� ������
             */
            unsigned int CameraNum;

            /**
             *  ������ ����������������
             */
            bool isInit;

            /**
             *  ������ ������, ����������� ����� �������� SetAdditionalObjectData
             *  �����, �����, ��������, ������������ �������� ���� 
             *  (��� ��� ������� � ������� �������� ������ �� ����������)
             */
            GObjectData AdditionalObjectData;

            /**
             *  ������ �������� ������ � ����������� ��������
             */
            std::list<GObjectData> DataList;

            /**
             *  ��������� � ������ ������ ����������� �������
             */
            boost::unordered_set< GObject* > ObjSelected;                      

///���-������� �������� ��������
            /**
             * ���-������� �������� ���������� � ��������� �������
             */
            boost::unordered_map< GObject*, ObjectMaterial> ObjMaterials;

            /**
             *  ���-������� �������� �������� ������� � ������
             */
            boost::unordered_map< GObject*, GObjectData* > ObjData;
            
            /**
             *  ���-������� �������� ������� ������ � ����������� ��������
             */
            boost::unordered_map<void*,GObject*> ObjDataToGObject;

            /** 
             * ���-������� ������ �������� ��� ������
             */
            boost::unordered_map< unsigned int, GObject* > ObjSelColors;
///���-������� �������� ��������          

            /**
             *  �������� �������
             */
            GFontManager fontManager;          

            /**
             *  ��� ���������� ������� ���������
             */
            GReper GCS_Reper;

            /**
             *  ������ ���
             */
            GReper GCS_Widget;               

            /**
             *  ������ ����������� ��������
             */
            std::list<SpecialGObject*> SpecialObjects;

            /**
             *	������� FPS
             */
            fps_counter _fpsCounter;

            /**
             *	����� ��� ����������
             */
            GText _infoText;

            /**
             *	���� ��� ������� "������������"
             */
            GText _demoText;
        };

    }

}
#endif // !defined(GPD_CA5451FC_1171_4820_A2DF_9AC89575B821__INCLUDED_)
