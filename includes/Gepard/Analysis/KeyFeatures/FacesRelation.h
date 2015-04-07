///////////////////////////////////////////////////////////
//  FacesRelation.h
//  ��������� ����� �������
//  �������:  3-���-2014
//  ������������ �����: Anton
//  ��������: ����������� �������� - ��� ����������
//  �������� �������, ��������� � �������/��������� �������
///////////////////////////////////////////////////////////

#pragma once

#include "KeyFeature.h"
#include "../DeviationVector.h"

namespace Gepard 
{
    class MathModel;

    namespace Assembly { class MatingRelation; }
    namespace Topology_Geometry { class GPDFace; }

    namespace Analysis 
    {
        /**
         *  ����������� �������� - ��������� ����� �������
         */
        class FacesRelation : public KeyFeature
        {
        public:
            FacesRelation();                       
           
            /**
             *  ��������� �� ������� �����
             */
            Gepard::Topology_Geometry::GPDFace* baseFace;

            /**
             *  ��������� �� ��������� �����
             */
            Gepard::Topology_Geometry::GPDFace* dependFace;

             /**
             *  �������� ������� � ��������� ����� �� ����������
             */
            void SetMatingRelation(Gepard::Assembly::MatingRelation *mr);

             /**
             *  �������� ������� � ��������� ����� �� �������
             */
            //TODO: ������� ��������� ������� � ��������� ����� �� �������
            //void SetFit();

             /**
             *  ��������� ������ � ����
             */
            void saveToFile(std::ostream &os) override;

            /**
             *  ��������� ������ �� �����
             */
            void readFromFile(std::istream &is, Gepard::MathModel *mathModelPtr) override;
        };
    }
}