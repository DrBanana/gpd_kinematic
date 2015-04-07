///////////////////////////////////////////////////////////
//  TPerpendicularity.h
//  ������ ������������������
//  �������:   	06-����-2014 14:06:38
//  �����: 		Anton
///////////////////////////////////////////////////////////

#ifndef TPERPENDICULARITY_H
#define TPERPENDICULARITY_H
#pragma once

#include "Tolerance.h"

namespace Gepard 
{
    namespace Tolerances 
    {
        /**
         *  ������ ������������������
         */
        class TPerpendicularity : public Tolerance
        {
            friend class TFlatness;
            friend class TParallelity;

        public:

            TPerpendicularity();


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
             *  �������������� ��������� ����� �� �������� ����� ��
             */
            void ModifyFaceParamsByCS(CSParam par) override;

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
             *  �������� ����������� ��� ������������ �������
             */
            double GetVisualKoeff() override;

            /**
             *  ������� ��� ������� ������ ������ ����� �� ����� �.�.
             */
            bool CalcRepers(CSParam par, GPDReper &nominal_point_reper, GPDReper &point_reper);
                       
        };

    }//Tolerances
}//Gepard

#endif