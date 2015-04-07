///////////////////////////////////////////////////////////
//  ConfigurationalSpace.h
//  ���������� 	���������������� ������������ ����
//  �������:   	15-���-2014 16:10
//  �����: 		Dr_Freeman
///////////////////////////////////////////////////////////


#ifndef CONFIGURATIONALSPACE_H
#define CONFIGURATIONALSPACE_H

#include "../Tolerances/CombinedTolerance.h"
#include "TC_counters.h"
#include "../Topology_Geometry/GPDFace.h"

#include <boost/unordered_map.hpp>

namespace Gepard 
{
    class MathModel;

    namespace Topology_Geometry {class GPDFace; class GPDSolid;}

    namespace Analysis 
    {
    
        /**
         *	���������������� ������������ ����
         */
        class ConfigurationalSpace 
        {
        public:
            ConfigurationalSpace();
                              
            /**
             *  ��������������� ������ �������� - ��������������� � ���������
             */
            Gepard::Tolerances::TolerancePtrArray generatedTolerances;

            /**
             *  �������� ������ � ����������������� ������������
             */
            void AddTolerance(Gepard::Tolerances::TolerancePtr tolPtr);

            /**
             *	������� �������� ����� �������� �������� �� �������� ������ ��
             */
            unsigned int getVariationCount();
            
            /**
             *	������� ����������� ��� (��������� ����� ��������)
             */
            void createTolCalc();

            /**
             *  �������� �.�.
             */
            void clear();

            /**
             *  ��������� �� �.�.
             */
            bool isExist();

            /**
             *  ���������� ������ ��������� ����� �.�. ��������
             */
            TC_counters getTolCSCounters();

            /**
             *  ���������� ������ �������, ����������� �� �������� ����� (�������)
             */
            int GetTolIndexByNominalFace(GPDFace* nominalFace);

            /**
             *  ������������ ��������� ����� (����� �����) �� ����������� ��������
             */
            void ModifyNominalFaceParams(TC_counters &c, GPDFace* nominalFace);

            /**
             *  �������� ��������� ���� ������ � ����������� ��������             
             */
            void DropFacesParamsToNominal();                        

            /**
             *  �������������� ��������� ���� ������ (����� �����), �� ������� ��������� �������
             */
            void ModifyNominalFacesParams(TC_counters &c);

            /**
             *  ����������� �.�.
             */
            void CopyTo(ConfigurationalSpace *csTo);

             /**
             *  ��������� ������ � ����
             */
            void saveToFile(std::ostream &os);

            /**
             *  ��������� ������ �� �����
             */
            void readFromFile(std::istream &is, Gepard::MathModel *mathModelPtr);

            /**
             *  �������� ����
             */
            bool DeleteSolid(Gepard::Topology_Geometry::GPDSolid *solPtr);

        private:

            /**
             *	������ �������� �.�.			 
             */
            Gepard::Tolerances::TolerancePtrArray toleranceArray;
            
            /**
             *	������ ��������������� ��������������� ��������
             */
            Gepard::Tolerances::CombinedToleranceList combinedTols;

            /**
             *  ������ �� �������� �������� ���������� �.�.
             *  ( ������ ������ - ����� ������� �� genTolsArray,
             *    ������ - ����� ��������� � cs � ����� ����������� )
             */
            std::list<std::list<int>> cs_indexes;

            /**
             *  ������������� ���������� ������ �������� 
             *  (������� ��������������� � ��������� �������)
             */
            void GenerateTolCalcArray();
        };
    
    }
}


#endif