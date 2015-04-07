///////////////////////////////////////////////////////////
//  TFlatness.h
//  ������ �������������
//  �������:   	06-����-2014 14:20
//  �����: 		Anton
///////////////////////////////////////////////////////////

#ifndef TFLATNESS_H
#define TFLATNESS_H
#pragma once

#include "Tolerance.h"

namespace Gepard 
{
    namespace Tolerances 
    {
        /**
         *  ������ �������������
         */
        class TFlatness : public Tolerance
        {
        public:

            TFlatness();


        protected:

            /**
             *  ��������� ���������������� ������������ ��� �������
             */
            double calcConfigurationSpaceTol( unsigned int COUNT_CONF_POINTS ) override;

            /**
             *  ��������� �������� ������� �� �������� ��������� ����� �.�.
             */
            double calcTolValueByCSParam(CSParam par, double A=0.0, double B=0.0) override;

             /**
             *  �������� �� ������ ����������� ��� ������� �������
             */
            bool CheckFace(Gepard::Topology_Geometry::GPDFacePtr facePtr) override;

            /**
             *  ��������� �������� gamma (��� ������� ������� ������)
             *  �� �������� ������� � ���������� �����������
             */
            double CalcGammaByTolValue(double tolValue) override;
                       
            /**
            *  �������� ������� ����������� ����� �� �������� ����� ��             
            */
            TModifyPointsFunc GetPointsModificationFunc(CSParam par) override;

        };

    }//Tolerances
}//Gepard

#endif