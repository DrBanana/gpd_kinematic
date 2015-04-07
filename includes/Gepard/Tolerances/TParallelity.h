///////////////////////////////////////////////////////////
//  TParallelity.h
//  ������ ��������������
//  �������:   	06-����-2014 09:50:15
//  �����: 		Anton
///////////////////////////////////////////////////////////

#ifndef TPARALLELITY_H
#define TPARALLELITY_H
#pragma once

#include "Tolerance.h"

namespace Gepard 
{
    namespace Tolerances 
    {

        /**
         *  ������ ��������������
         */
        class TParallelity : public Tolerance
        {
        public:

            TParallelity();


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

            /**
             *  �������������� ��������� ����� �� �������� ����� ��
             */
            void ModifyFaceParamsByCS(CSParam par) override;

            /**
             *  �������� ����������� ��� ������������ �������
             */
            double GetVisualKoeff() override;

        };

    }//Tolerances 
}//Gepard 

#endif