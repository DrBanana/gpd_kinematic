///////////////////////////////////////////////////////////
//  KF_PrecDiagram.h
//  �������� �������� - ��������� ��������
//  �������:  2-���-2014
//	������������ �����: Anton
///////////////////////////////////////////////////////////

#pragma once

#include "FacesRelation.h"

namespace Gepard 
{
    class MathModel;

    namespace Tolerances { class Tolerance; }

    namespace Analysis 
    {
        /**
         *  �������� �������� - ��������� ��������
         */
        class KF_PrecDiagram : public FacesRelation
        {
        public:
            KF_PrecDiagram();            
          
            /**
             *  �������� ���������� ����������� �������
             */
            void ClearResults() override;                      

            /**
             *  �������� ������ �������� ���������� ����� ��������� �������
             */
            void CalcDeviationVectors( Gepard::Tolerances::Tolerance *b_tol, int b_csIndex,
                                       Gepard::Tolerances::Tolerance *d_tol, int d_csIndex,
                                       unsigned int tc_index );            

            /**
             *  ���������� �������
             */
            unsigned int ResultsCount();

            /**
             *  ���� �� ���������� ��� ������� ��������
             */
            bool hasResults() override;

            /**
             *  ��������� �������� � ������� ������������� 
             * � ������������� ���������� �� ���� ������ �.�.
             */
            void CalcMinMax( double &max_tight, double &min_tight, 
                             double &max_gap,   double &min_gap );

            /**
             *  ��������� �������� � ������� ������������� 
             *  � ������������� ���������� �� ���� ������ �.�.
             *  + ������������ ������� ��� �������� � ������� ��� ������ �����
             */
            void CalcMinMax( double &max_tight, double &min_tight, 
                             double &max_gap,   double &min_gap,
                             std::vector<std::pair<double, double>> *tights_array,
                             std::vector<std::pair<double, double>> *gaps_array );

            /**
             *  ��������� �������� � ������� ������������� 
             * � ������������� ���������� �� ���� ������ �.�.
             */
            void CalcMinMax( unsigned int cs_index,
                             double &max_tight, double &min_tight, 
                             double &max_gap,   double &min_gap );

            /**
             *	���������� �������� ��������� ������������� 
             *  � ��������� ������������� ���������� �� ���� ������ �.�.
             */
            void CalcPercentage( int &tight_percent, int &gap_percent);

            /**
             *  �������� ���������� ������� � ���������� �������� � �������� ����� �.�.
             */
            void GetAbsMinMax(unsigned int cs_index, double &abs_min, double &abs_max);

            /**
             *  �������� ���������� �������� � �������� ����� �.�.
             */
            double GetAbsMax(unsigned int cs_index);

            /**
             *  ������ ������� �������� ���������� ����� ��������� ������� � ������ ����� �.�.
             */
            DeviationVectorsLists deviationVectorsLists;

            /**
             *  ������ ����� �.�., � ������� ���� ������� ����������
             */
            std::vector<unsigned int> tc_indexes;

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