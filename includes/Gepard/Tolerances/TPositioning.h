///////////////////////////////////////////////////////////
//  TPositioning.h
//  ������ �����������
//  �������:   	06-����-2014 14:52
//  �����: 		Anton
///////////////////////////////////////////////////////////

#ifndef TPOSITIONING_H
#define TPOSITIONING_H
#pragma once

#include "Tolerance.h"

namespace Gepard 
{
    namespace Tolerances 
    {
        /**
         *  ������ �������������
         */
        class TPositioning : public Tolerance
        {
        public:

            TPositioning();

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
             *  �������� ������� ����������� ����� �� �������� ����� ��             
             */
            TModifyPointsFunc GetPointsModificationFunc(CSParam par) override;

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
             *  �������������� ��������� ����� �� �������� ����� ��
             */
            void ModifyFaceParamsByCS(CSParam par) override;          

        };

    }//Tolerances
}//Gepard

#endif