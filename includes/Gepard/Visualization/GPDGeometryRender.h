///////////////////////////////////////////////////////////
//  GPDGeometryRender.h
//  Класс отображения геометрии ГеПАРДА
//  Created on:      29-авг-2013 14:28:33
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
         *  Рендер геометрии ГеПАРДа
         */
        class GPDGeometryRender : public GCamera
        {
        public:

             explicit GPDGeometryRender(bool autoRegister = false);
             virtual ~GPDGeometryRender();
             
            /**
             *  Отобразить грань тела
             */
             void DrawFace( GObject *obj, Gepard::Topology_Geometry::GPDFacePtr _facePtr , bool isUpdateCamera = true );

             /**
             *  Отобразить грань тела
             */
             void DrawFace( GObject *gObj, GColor faceColor, Gepard::Topology_Geometry::GPDFacePtr _facePtr , bool isUpdateCamera = true );

            /**
             *  Отобразить грань тела
             */
             void DrawFace( Gepard::Topology_Geometry::GPDFacePtr _facePtr , bool isUpdateCamera = true );

            /**
             *  Отобразить тело
             */
             void DrawSolid( Gepard::Topology_Geometry::GPDSolidPtr _SolidPtr, bool isUpdateCamera = true );

            /**
             *	Отобразить тело для preview
             */
             GSceneItem* DrawSolidPreview( Gepard::Topology_Geometry::GPDSolidPtr _Solid, GSceneItem* solidsItem = nullptr, bool isUpdateCamera = true);

            /**
             *	Отобразить тела для preview
             */
             GSceneItem* DrawSolidsPreview( Gepard::Topology_Geometry::GPDSolidPtrList _SolidsList, bool isUpdateCamera = true);

             /**
              * Отобразить трехмерный контур
              */
             void DrawBound( Gepard::Topology_Geometry::GPDFaceBoundList *_FaceBoundList, bool isUpdateCamera = true );

             /**
              * Отобразить двумерный контур
              */
             void DrawBound2D( Gepard::Topology_Geometry::GPDFaceBoundList *_FaceBoundList, 
                               double u0, double v0, double map_u, double map_v, bool isUpdateCamera = true );

             /**
              * Отобразить  
              */
             void ShowMapAndContours3D( Gepard::Topology_Geometry::GPDSolidPtr _SolidPtr,
                                        int numSurface );

             /**
              * Нарисовать поверхность
              */
             void DrawSurface( Gepard::Surfaces::GPDSurfacePtr _SurfPtr, bool isUpdateCamera = true );

             /**
              * Нарисовать поверхность
              */
             void DrawSurface( Gepard::Surfaces::GPDSurfacePtr _SurfPtr, float r, float g, float b, 
                               bool isPrimTri = true, bool isUpdateCamera = true );

             /**
              * Нарисовать поверхность КП
              */
             void DrawConfigurationalSpace( Gepard::Surfaces::GPDSurfacePtr _SurfPtr, 
                                            Gepard::Tolerances::Tolerance *cs_tol );
          
             /**
              * Нарисовать точку КП
              */
             GSceneItem* DrawCSPoint(Gepard::BasicMath::GPDPoint *P);

             /**
              * Отобразить поверхность КП
              */
             GSceneItem* DrawCSSurface(Gepard::Surfaces::GPDSurfacePtr SurfPtr, bool isUpdateCamera=true);

             /**
              * Отобразить грань КП
              */
             GSceneItem* DrawCSFace(Gepard::Tolerances::TolCSFace *tolFace, bool isUpdateCamera=true );

             /**
              * Отобразить репер контрольного участка
              */
             GSceneItem* DrawCSReper(Gepard::BasicMath::GPDReper *Rep);

             /**
              * Отобразить репер контрольного участка как специальный объект
              */
             SpecialGObject* DrawSpecCSReper(Gepard::BasicMath::GPDReper *Rep
                                             , std_stringsVector strVec = std_stringsVector() );

             /**
              * Отобразить ось как специальный графический объект
              */
             GAxis* DrawAxis( double x0, double y0, double z0,
                              double x1, double y1, double z1,
                              GColor _Color = GColor(), 
                              std::string axis_name = "" );

             /**
              * Отобразить массив векторов отклонений
              */
             GSceneItem* DrawDeviationVectors3D( Gepard::Topology_Geometry::GPDFacePtr baseFace,
                                                 Gepard::Analysis::DeviationVectorList &dVec, 
                                                 double abs_max_v, bool isShowSurface = true, 
                                                 bool isShowLabels = true );

             /**
              * Отобразить текстовый объект - метка
              */
             GText* DrawGText_label(double x, double y, double z, std::string labelStr, GSceneItem *sItem=nullptr);

             /**
              * Обновить координаты графического репера
              */
             void UpdateGReperCoords(SpecialGObject *objPtr, Gepard::BasicMath::GPDReper *Rep);                         
            
             /**
              * Функция вызывается у дочернего окна(виджета) для перерисовки его контента
              */
             virtual void RepaintContent();

            /**
             *  Виртуальная функция - закрыть камеру
             */
             void CloseCamera() override;

             /**
              * Есть ли данная деталь в рендере
              */
             bool isSolidExist(Gepard::Topology_Geometry::GPDSolidPtr _SolidPtr);

             /**
              * Выделить деталь (true - успех)
              */
             bool SetSolidSelection(Gepard::Topology_Geometry::GPDSolidPtr _SolidPtr, bool select=true);
             
             /**
              * Установить цвет детали (если _color не задан - цвет сбрасывается)
              */
             void SetSolidColor(Gepard::Topology_Geometry::GPDSolidPtr _SolidPtr, GColor _color=GColor());

             /**
              * Сбросить цвет детали
              */
             void DropSolidColor(Gepard::Topology_Geometry::GPDSolidPtr _SolidPtr);

             /**
              *  Функция очищает все графические данные камеры
              */
             void ClearCameraData() override;

             /**
              * Есть ли в камере геометрические данные (детали)
              */
             bool isCameraHasGeometryData();
              
             /**
              * Изменить координаты графического объекта (по указателю на данные, привязанные к этому объекту)              
              */
             void ModifyObject(void *object_data_ptr, Gepard::BasicMath::TModifyPointsFunc &funcRef);

             /**
              * Удалить деталь из камеры
              */
             void RemoveSolid(Gepard::Topology_Geometry::GPDSolidPtr _SolidPtr);

             /**
              *	Нарисовать триангуляцию поверхности
              */
             void DrawSurfaceTriangulation(Gepard::Surfaces::GPDSurfacePtr surfPtr, bool isShowBounds = true, bool isUpdateCamera=true);
             

        private:
            
            /**
             *  Отобразить репер
             */
            void draw_reper(Gepard::BasicMath::GPDReper *rep, GObject *objPtr = nullptr);

            /**
             *  Функция отображает сектор поверхности
             */
            void draw_surface_sector( Gepard::Surfaces::GPDSurfacePtr surfPtr, 
                                      unsigned int secIndex, GPrimitive* tri,
                                      GPrimitive *wire_line=nullptr, 
                                      GPrimitive *normal=nullptr );

            /**
             *  Функция рисует сектор из 4-х точек
             */
            void draw_sector( Gepard::BasicMath::GPDPointPtr (&P)[4], GPrimitive* tri);

            /**
             *  Функция определяет, в каком порядке выводить треугольник - прямом или обратном
             */
            bool getTriangleDirection(Gepard::BasicMath::GPDPointPtr (PointsArray)[3]);

            /**
             *  Добавить vertex к примитиву
             */
            void add_vertex(GPrimitive* prim, Gepard::BasicMath::GPDPointPtr P, bool normal=false);

            /**
             *  Массив указателей на детали, которые отображены в данном рендере
             */
            Gepard::Topology_Geometry::GPDSolidPtrList _SolidPtrList;

            /**
             *  Соответствие тела и участка сцены
             */
            boost::unordered_map< Gepard::Topology_Geometry::GPDSolid*, 
                                  Gepard::Visualization::GSceneItem* > _SolidToGItem;
        };

    }//Visualization
}//Gepard

#endif
