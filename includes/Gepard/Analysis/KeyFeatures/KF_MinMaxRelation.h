///////////////////////////////////////////////////////////
//  KF_MinMaxRelation.h
//  �������� �������� - ������������ � ����������� ������
//  �������:  5-���-2014
//  ������������ �����: Anton
///////////////////////////////////////////////////////////

#pragma once

#include "KF_PrecDiagram.h"

namespace Gepard 
{
    class MathModel;

    //TODO: �������� ������� ������� � ������� (�� ������� ��������� ��������)

    namespace Analysis 
    {
        /**
         *  �������� �������� - ������������ � ����������� ������
         */
        class KF_MinMaxRelation: public KF_PrecDiagram                                 
        {
        public:

            explicit KF_MinMaxRelation(KEY_FEATURE_TYPE minmaxType);
                        
            /**
             *  ������������ ������
             */
            DeviationVector max_vector;

            /**
             *  ������������ ������
             */
            DeviationVector min_vector;
            
            /**
             *  ���� �� ���������� ��� ������� ��������
             */
            bool hasResults() override;

            /**
             *  �������� ���������� ����������� �������
             */
            void ClearResults() override;

            /**
             *  ��������� ����������� � ������������ �����
             */
            void CalcMinMaxRelation();

            /**
             *  ��������� ������ � ����
             */
            void saveToFile(std::ostream &os) override;

            /**
             *  ��������� ������ �� �����
             */
            void readFromFile(std::istream &is, Gepard::MathModel *mathModelPtr) override;

        private:

            /**
             *  ��� �������
             */
            DV_TYPE dvType;
        };
    }
}
