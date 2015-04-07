///////////////////////////////////////////////////////////
//  GDefine.h
//  Implementation of the Class GDefine
//  Created on:      19-���-2013 19:39:32
//  Original author: Anton
///////////////////////////////////////////////////////////

#if !defined(GPD_AF5C17F8_7A6C_43fb_8DA7_63080398086F__INCLUDED_)
#define GPD_AF5C17F8_7A6C_43fb_8DA7_63080398086F__INCLUDED_

#include "GVector.h"
#include <list>
#include <fstream>

//     TODO: �������� ��� ���������� ������:
//     1) ������ ��������� ��� ������� ���������
//     2) ������� ��������� �� ������
//     3) ������� ������ ����� ������� ��� ���������
//     4) ����������� ����������� ��������
//     5) ������������ ��������/�������������� ��������

//     6) ��� ������� ������ ���� ���������:
//          - ��� � ������� ����� � �������, ���� ���� �����
//          - ������ � ���� ����� � �������
//          - ��������� �������� ���������

//     7) ������� ���� ����������: GPT_LINE_STRIP, GPT_QUAD_STRIP? 

#include "Materials.h"

//�������� �� ��������� VBO
#define GPD_VBO_SUPPORT_CHECK

namespace Gepard
{
    namespace Visualization
    {
                
         /**
         *  �������
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
         *  ��� ������������ ��������
         */
        enum GPRIMITIVE_TYPE 
        {
             GPD_UNKNOWN    //����������
            ,GPT_LINE       //�����
            ,GPT_POINT      //�����
            ,GPT_TRIANGLE   //�����������
            ,GPT_QUAD       //�������
        };

        /**
         *  ��� �������
         */
        enum GCAMERA_EVENT
        {
            GCE_NO_EVENT,         //��� �������
//Mouse events
            GCE_MOUSELBUTTONDOWN, //������� ����� ������ ����
            GCE_MOUSERBUTTONDOWN, //������� ������ ������ ����
            GCE_MOUSEMBUTTONDOWN, //������� ������� ������ ����
            GCE_MOUSELBUTTONUP,   //���������� ����� ������ ����
            GCE_MOUSERBUTTONUP,   //���������� ������ ������ ����
            GCE_MOUSEMBUTTONUP,   //���������� ������� ������ ����
            GCE_MOUSEMOVE,        //�������� ����
            GCE_MOUSEWHEELDOWN,   //��������� ����
            GCE_MOUSEWHEELUP,     //��������� �����
//keyboard events
            GCE_KEY_ENTER,        //������� ENTER
            GCE_KEY_DELETE        //������� DELETE
        };


        class GCamera;
        enum GMessageType {
                GMT_ON_SELECT             //������ ������
              , GMT_ON_LOST_SELECT        //������ �������
//               , GMT_ON_ADD_TO_GROUP         //������ �������� � ������ ������
//               , GMT_ON_REMOVE_FROM_GROUP    //������ ������ �� ������ ������
              , GMT_ON_MOVE_OBJECT
              , GMT_ON_KEY_DELETE
              , GMT_ON_KEY_ENTER
        };
                
        
        /**
         *  ��� �������, � �������� �������� ������� ����������� ������
         */
        enum GObjectDataType
        {
             GODT_UNKNOWN    //����������� �������������
            ,GODT_FACE       //GPDFace
            ,GODT_SOLID      //GPDSolid
            ,GODT_FACEBOUND  //GPDFaceBound
            ,GODT_CONF_SPACE //Configurational space
            ,GODT_CS_POINT   //Conf space point
            ,GODT_CS_SURF    //Conf space Surface
            ,GODT_CS_TOLFACE //���� �������� - ����� � ����� �.�.
        };

        /**
         *  �������� ��������� ������
         */
        enum GCAMERA_SETTINGS
        {
             GCS_NONE            =   0
            ,GCS_SHOW_AXES       =   1<<1    //����������� ���� ���
            ,GCS_SHOW_WIDGETS    =   1<<2    //����������� �������������� ��������
            ,GCS_GRADIENT_FILL   =   1<<3    //����������� ������� ������� ����
            ,GCS_SHOW_LOGO       =   1<<4    //����������� ����
            ,GCS_SELECTABLE      =   1<<5    //����������� ������ ��������
            ,GCS_MULTISELECT     =   1<<6    //����������� ������ ���������� ��������
            ,GCS_ROTATABLE       =   1<<7    //����������� ��������
            ,GCS_MOVABLE         =   1<<8    //����������� ������
            ,GCS_SCALABLE        =   1<<9    //���������������
            ,GCS_SHOW_OSD_AXES   =   1<<10   //����������� ���� ����� �����
            ,GCS_SHIFTABLE       =   1<<11   //������������� ����� ������
            ,GCS_SHOW_FPS        =   1<<12   //���������� FPS
        };

        /**
         *  ��������� ������� ����������� �����
         */
        enum GSCENE_ITEM_SETTINGS
        {
             GSI_SELECTABLE     = 1<<1  //����������� ������ ��������
//             ,GSI_MULTISELECT    = 1<<2  //����������� �������������
//             ,GSI_ZOOMABLE       = 1<<3  //���������������
//             ,GSI_ROTATABLE      = 1<<4  //�������
//             ,GSI_TRANSLATABLE   = 1<<5  //�������
            ,GSI_MOVABLE        = 1<<6  //������������ ������� - ����� ������� ���������� ������
            ,GSI_OBJ_COLOR      = 1<<7  //������������ ���� - ���� �� ������, ������������ ��������
            ,GSI_HIGHLIGHT_SELECTED  = 1<<8  //������������ �� ��������� �������
            ,GSI_OBJ_ONLY_COLOR = 1<<9 //������������ ������ ���� ������� 
                                       //- ��� ����� �������� � ����� (���� �������� �������� �� GSI_OBJ_COLOR)
            ,GSI_KBRD_REACTION  = 1<<10 //����������� �� ����������
            ,GSI_NO_DEPTH       = 1<<11 //����������� ����� �������
            ,GSI_CULL_BACK_FACE = 1<<12 //�������� ��������� �����
        };

        /**
         *  ������ ������, ����������� � ������������ �������
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
         *  ��� ������� ������
         */
            GObjectDataType _type;
        /**
         *  ��������� �� ������ ������
         */
            void* ObjectData;
        };

        /**
         *  ��������� ���������, ������������� ��������
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
            //std::list<void*> ObjectsArray;  //������ �������� ��� ��������, ��������������� �� �����������
                        
            GMessageType MessageType;     //��� ������������� ���������
            GCamera *cameraPtr;           //��������� �� ������, � ������� ��������� �������                    
            GObjectData* _Object;         //��������� �� ������� ��������� ������, ����������� � �������� ������������ �������            
            float coords[6];              //���������� ������������ ������� P0(x,y,z) - P1(x,y,z)
            std::vector<float> extra_coords; //�������������� ���������� (��������, ��� �������� ��� �����)

        };

//         //->���������� ���������
//         static float GNormalMaterialEmission[4] = {0.0f,0.0f,0.0f,1.0f};
//         static float GFocusedMaterialEmission[4] = {0.2f,0.2f,0.2f,1.0f};
         static float GSelectedMaterialEmission[4] = {0.35f,0.35f,0.35f,1.0f};
//         //static float GMaterialSpecular[4] = {0.2f,0.2f,0.2f,1.0f};
//         static float GNormalMaterialSpecular[4] = {0.0f,0.0f,0.0f,1.0f};
         
         static float GDefaultPrimitiveColor[4] = {0.15f,0.15f,0.65f,1.0f}; //���� ��������� �� ���������
         static float GDefaultSelectedColor[4]  = {1.0f,0.0f,0.0f,1.0f };   //���� �� ��������� ��� ��������� ��������

       

        //-> ��������� ���������� ������
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


        //-> ��������� �������� �����

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


        //-> ���������������� �����������

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
            
            float BackGroundColor[4];   //���� ������� ������

            float GradientColor0[4];    //���� ��������� �� ������ ����
            float GradientColor1[4];
                        
            bool isShowAxes;        //����������� ���� ���
            bool isShowOSDAxes;     //����������� ���� ����� ����� ������
            bool isShowWidgets;     //����������� �������������� ��������
            bool isGradientFill;    //����������� ������� ������� ����
            bool isShowLogo;        //����������� ����
            //bool isShowFPS;         //���������� FPS

            bool isSelectable;      //����������� ������ ��������
            bool isMultiselect;     //����������� ������ ���������� ��������
            bool isRotatable;       //����������� ��������
            bool isMovable;         //����� ������
            bool isScalable;        //���������������
            bool isShiftable;       //������������� ����� ������

            GVector camShift;       //����� ������ - ��� ��������� ������������ �������� �����

            GRenderSetting ()
            {
                isShowAxes = isShowLogo = isGradientFill = isShowWidgets = false;
                isSelectable = isRotatable = isMovable = isScalable = isShiftable = true;
                isMultiselect = false;
                
                isShowOSDAxes = true;
                //isShowFPS = false;

                //���� ������� �� ���������
                BackGroundColor[0] = 0.9f;
                BackGroundColor[1] = 0.9f;
                BackGroundColor[2] = 0.9f;
                BackGroundColor[3] = 1.0f;

                isGradientFill = true;

                //���� ��������� �� ���������
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
         *  ��������� ��� �������� ���������� ������� �����
         */
        struct PIndexes
        {
            unsigned int Count;         //����� ����� � ��������� �������
            unsigned int CurPIndex;     //������� ������ �����
            unsigned int *IndexArray;   //������ ��������

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
             *  ������� ������
             */
            void CreateArray()
            {
                if (Count!=0) IndexArray = new unsigned int[Count];
            }
        };


        /**
         *	��������� ���������� ������� �������� � VBO
         */
        struct ObjVBOBufferIndexes
        {
            ObjVBOBufferIndexes()
            {
                clear();
            }

            /**
             *  ��� ������ ������ � VBO
             */
            unsigned int _Vertices;

            /**
             *  ��� ������ ������ � VBO
             */
            unsigned int _Normals;

            /**
             *  ��� ������ ����� � VBO
             */
            unsigned int _Colors; 

            /**
             *  ����� ������� �������� � VBO ��� ���������� ��������
             */
            std::list<std::list<unsigned int>> _VIndexes;

            /**
             *	������� �������� ��������
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
         *	��������� VBO
         */
        struct VBOSupportCheck
        {
            VBOSupportCheck()
            {
                isGlewInit = false;
                isVBOSupported = false;
            }
            /**
             *	��������������� �� GLEW
             */
            bool isGlewInit;

            /**
             *	�������������� �� VBO
             */
            bool isVBOSupported;
        };
        /**
         *	������� ��� �������� ��������� VBO
         */
        extern VBOSupportCheck vboSupport;


        /**
         *  ��������� �������� ���������� ���������
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
