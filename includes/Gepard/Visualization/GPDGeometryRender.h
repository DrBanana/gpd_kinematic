///////////////////////////////////////////////////////////
//  GPDGeometryRender.h
//  ����� ����������� ��������� �������
//  Created on:      29-���-2013 14:28:33
//  Original author: Anton
///////////////////////////////////////////////////////////
#ifndef GPDGEOMETRYRENDER_H
#define GPDGEOMETRYRENDER_H

#include "GCamera.h"
#include "../Topology_Geometry/GPDSolid.h"
#include "../Tolerances/Tolerance.h"
#include "../BasicMath/additionalFuncs.h"
#include "../Service/gpd_messaging.h"
#include "../Analysis/DeviationVector.h"

#include <boost/unordered_map.hpp>

namespace Gepard 
{
    namespace Visualization 
    {        
        /**
         *  ������ ��������� �������
         */
        class GPDGeometryRender : public GCamera
        {
        public:

             explicit GPDGeometryRender(bool autoRegister = false);
             virtual ~GPDGeometryRender();
             
            /**
             *  ���������� ����� ����
             */
             void DrawFace( GObject *obj, Gepard::Topology_Geometry::GPDFacePtr _facePtr , bool isUpdateCamera = true );

             /**
             *  ���������� ����� ����
             */
             void DrawFace( GObject *gObj, GColor faceColor, Gepard::Topology_Geometry::GPDFacePtr _facePtr , bool isUpdateCamera = true );

            /**
             *  ���������� ����� ����
             */
             void DrawFace( Gepard::Topology_Geometry::GPDFacePtr _facePtr , bool isUpdateCamera = true );

            /**
             *  ���������� ����
             */
             void DrawSolid( Gepard::Topology_Geometry::GPDSolidPtr _SolidPtr, bool isUpdateCamera = true );

            /**
             *	���������� ���� ��� preview
             */
             GSceneItem* DrawSolidPreview( Gepard::Topology_Geometry::GPDSolidPtr _Solid, GSceneItem* solidsItem = nullptr, bool isUpdateCamera = true);

            /**
             *	���������� ���� ��� preview
             */
             GSceneItem* DrawSolidsPreview( Gepard::Topology_Geometry::GPDSolidPtrList _SolidsList, bool isUpdateCamera = true);

             /**
              * ���������� ���������� ������
              */
             void DrawBound( Gepard::Topology_Geometry::GPDFaceBoundList *_FaceBoundList, bool isUpdateCamera = true );

             /**
              * ���������� ��������� ������
              */
             void DrawBound2D( Gepard::Topology_Geometry::GPDFaceBoundList *_FaceBoundList, 
                               double u0, double v0, double map_u, double map_v, bool isUpdateCamera = true );

             /**
              * ����������  
              */
             void ShowMapAndContours3D( Gepard::Topology_Geometry::GPDSolidPtr _SolidPtr,
                                        int numSurface );

             /**
              * ���������� �����������
              */
             void DrawSurface( Gepard::Surfaces::GPDSurfacePtr _SurfPtr, bool isUpdateCamera = true );

             /**
              * ���������� �����������
              */
             void DrawSurface( Gepard::Surfaces::GPDSurfacePtr _SurfPtr, float r, float g, float b, 
                               bool isPrimTri = true, bool isUpdateCamera = true );

             /**
              * ���������� ����������� ��
              */
             void DrawConfigurationalSpace( Gepard::Surfaces::GPDSurfacePtr _SurfPtr, 
                                            Gepard::Tolerances::Tolerance *cs_tol );
          
             /**
              * ���������� ����� ��
              */
             GSceneItem* DrawCSPoint(Gepard::BasicMath::GPDPoint *P);

             /**
              * ���������� ����������� ��
              */
             GSceneItem* DrawCSSurface(Gepard::Surfaces::GPDSurfacePtr SurfPtr, bool isUpdateCamera=true);

             /**
              * ���������� ����� ��
              */
             GSceneItem* DrawCSFace(Gepard::Tolerances::TolCSFace *tolFace, bool isUpdateCamera=true );

             /**
              * ���������� ����� ������������ �������
              */
             GSceneItem* DrawCSReper(Gepard::BasicMath::GPDReper *Rep);

             /**
              * ���������� ����� ������������ ������� ��� ����������� ������
              */
             SpecialGObject* DrawSpecCSReper(Gepard::BasicMath::GPDReper *Rep
                                             , std_stringsVector strVec = std_stringsVector() );

             /**
              * ���������� ��� ��� ����������� ����������� ������
              */
             GAxis* DrawAxis( double x0, double y0, double z0,
                              double x1, double y1, double z1,
                              GColor _Color = GColor(), 
                              std::string axis_name = "" );

             /**
              * ���������� ������ �������� ����������
              */
             GSceneItem* DrawDeviationVectors3D( Gepard::Topology_Geometry::GPDFacePtr baseFace,
                                                 Gepard::Analysis::DeviationVectorList &dVec, 
                                                 double abs_max_v, bool isShowSurface = true, 
                                                 bool isShowLabels = true );

             /**
              * ���������� ��������� ������ - �����
              */
             GText* DrawGText_label(double x, double y, double z, std::string labelStr, GSceneItem *sItem=nullptr);

             /**
              * �������� ���������� ������������ ������
              */
             void UpdateGReperCoords(SpecialGObject *objPtr, Gepard::BasicMath::GPDReper *Rep);                         
            
             /**
              * ������� ���������� � ��������� ����(�������) ��� ����������� ��� ��������
              */
             virtual void RepaintContent();

            /**
             *  ����������� ������� - ������� ������
             */
             void CloseCamera() override;

             /**
              * ���� �� ������ ������ � �������
              */
             bool isSolidExist(Gepard::Topology_Geometry::GPDSolidPtr _SolidPtr);

             /**
              * �������� ������ (true - �����)
              */
             bool SetSolidSelection(Gepard::Topology_Geometry::GPDSolidPtr _SolidPtr, bool select=true);
             
             /**
              * ���������� ���� ������ (���� _color �� ����� - ���� ������������)
              */
             void SetSolidColor(Gepard::Topology_Geometry::GPDSolidPtr _SolidPtr, GColor _color=GColor());

             /**
              * �������� ���� ������
              */
             void DropSolidColor(Gepard::Topology_Geometry::GPDSolidPtr _SolidPtr);

             /**
              *  ������� ������� ��� ����������� ������ ������
              */
             void ClearCameraData() override;

             /**
              * ���� �� � ������ �������������� ������ (������)
              */
             bool isCameraHasGeometryData();
              
             /**
              * �������� ���������� ������������ ������� (�� ��������� �� ������, ����������� � ����� �������)              
              */
             void ModifyObject(void *object_data_ptr, Gepard::BasicMath::TModifyPointsFunc &funcRef);

             /**
              * ������� ������ �� ������
              */
             void RemoveSolid(Gepard::Topology_Geometry::GPDSolidPtr _SolidPtr);

             /**
              *	���������� ������������ �����������
              */
             void DrawSurfaceTriangulation(Gepard::Surfaces::GPDSurfacePtr surfPtr, bool isShowBounds = true, bool isUpdateCamera=true);
             

        private:
            
            /**
             *  ���������� �����
             */
            void draw_reper(Gepard::BasicMath::GPDReper *rep, GObject *objPtr = nullptr);

            /**
             *  ������� ���������� ������ �����������
             */
            void draw_surface_sector( Gepard::Surfaces::GPDSurfacePtr surfPtr, 
                                      unsigned int secIndex, GPrimitive* tri,
                                      GPrimitive *wire_line=nullptr, 
                                      GPrimitive *normal=nullptr );

            /**
             *  ������� ������ ������ �� 4-� �����
             */
            void draw_sector( Gepard::BasicMath::GPDPointPtr (&P)[4], GPrimitive* tri);

            /**
             *  ������� ����������, � ����� ������� �������� ����������� - ������ ��� ��������
             */
            bool getTriangleDirection(Gepard::BasicMath::GPDPointPtr (PointsArray)[3]);

            /**
             *  �������� vertex � ���������
             */
            void add_vertex(GPrimitive* prim, Gepard::BasicMath::GPDPointPtr P, bool normal=false);

            /**
             *  ������ ���������� �� ������, ������� ���������� � ������ �������
             */
            Gepard::Topology_Geometry::GPDSolidPtrList _SolidPtrList;

            /**
             *  ������������ ���� � ������� �����
             */
            boost::unordered_map< Gepard::Topology_Geometry::GPDSolid*, 
                                  Gepard::Visualization::GSceneItem* > _SolidToGItem;
        };

    }//Visualization
}//Gepard

#endif
