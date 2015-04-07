///////////////////////////////////////////////////////////
//  GeometryManager.h
//  �������� ��������� ������
//  �������:  29-���-2013 15:41:21
//  �����:    Dr_Freeman
///////////////////////////////////////////////////////////

#ifndef GEOMETRYMANAGER_H
#define GEOMETRYMANAGER_H

#include "MathModel.h"
#include "Visualization/GPDGeometryRender.h"
#include <map>

namespace Gepard {

    using namespace Visualization;

    class GeometryManager 
    {
    public:
        GeometryManager();
        ~GeometryManager();
               

        /**
        * ������ ������ �� STEP
        */
        int importSTEP(std::string stpFileName, GPDGeometryRender *gCamera=nullptr);


        /**
         *	��������� ������ � ������ GPD
         */
        void saveGPD(std::string gpdFileName);

        /**
        *	������ ������ �� GPD
        */
        int importGPD(std::string gpdFileName, GPDGeometryRender *gCamera=nullptr);
                      

        /**
        *	�������� ���� ������
        */
        Gepard::Assembly::AssemblyGraph* getAssemblyGraph();

         /**
         *	"�������" - ������� ��� ���������
         */
        void CloseAll();

        /**
         *  ��������� ������ ������� ��������, � ������� ��������� ������
         */
        void FillSolidRendersList( Gepard::Topology_Geometry::GPDSolidPtr SolidPtr, 
                                   std::list<Gepard::Visualization::GPDGeometryRender*> &RendersList );

        /**
         *  �������� ��������� �� ���-������
         */
        Gepard::MathModel* GetMathModelPtr();

        /**
         *  ���������� ���� ������ � ��������
         */
        void SetSolidColor( Gepard::Topology_Geometry::GPDSolidPtr solPtr, 
                            Gepard::Visualization::GColor _color);

        /**
         *  �������� ���� ������
         */
        void DropSolidColor(Gepard::Topology_Geometry::GPDSolidPtr solPtr);

        /**
         *  �������� ������ (������� �� ���� ��������)
         */
        void HideSolid(Gepard::Topology_Geometry::GPDSolidPtr solPtr);

        /**
         *  �������� ������ � �������� ������
         */
        void ShowSolidInRender( Gepard::Topology_Geometry::GPDSolidPtr solPtr, 
                                Gepard::Visualization::GCamera *camera, 
                                bool isUpdateCam = true );

        /**
         *  ������� ������
         */
        void DeleteSolid( Gepard::Topology_Geometry::GPDSolidPtr solPtr );

        /**
         *  ������� ������� ����������
         */
        void DeleteMatingRelation( Gepard::Assembly::MatingRelation* mrPtr);

        /**
         *  ������� �������� ��������������
         */
        void DeleteKeyCharacteristic( Gepard::Analysis::KeyCharacteristics *kcPtr );

        /**
        *	�������� �������
        */
        void AddFit(Gepard::Tolerances::Fit fit_);

        /**
         *	�������� �������
         */
        void DeleteFit(Gepard::Tolerances::Fit *fit);

        private:
        /**
         *  �������������� ������ - ��� ������ ��� ������� ���������� �����
         */
        MathModel gpdMathModel;

        /**
         *  ������������� ������: ������ � �� ����
         */
        std::map< Gepard::Topology_Geometry::GPDSolid*,
                  Gepard::Visualization::GColor >   Solid2Color;

        /**
         *  ������������� ������: ������ � �� ��������
         */
        std::map< Gepard::Topology_Geometry::GPDSolid*,
                  Gepard::Visualization::ObjectMaterial > Solid2Material;
    };
}


#endif



