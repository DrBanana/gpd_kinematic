///////////////////////////////////////////////////////////
//  CombinedTolerance
//  ���������� 	 ��������������� ������ 
//			 - ��������� �������� �� ���� �����������
//  �������:   	 15-���-2014 15:02:15
//  �����: 		 Dr_Freeman
///////////////////////////////////////////////////////////

#ifndef COMBINEDTOLERANCE_H
#define COMBINEDTOLERANCE_H

#include "Tolerance.h"

namespace Gepard 
{
    class MathModel;

    using namespace BasicMath;

    namespace Tolerances 
    {

        /**
         *	��������������� ������ - ������� �� ���������� ��������,
         *	����������� �� ���� �����������
         */
        class CombinedTolerance : public Gepard::Tolerances::Tolerance
        {

        public:
            CombinedTolerance();
            CombinedTolerance(Gepard::Topology_Geometry::GPDFacePtr tFacePtr);

            /**
             *  ������ �������� ��� ������� ����������������
             */
            TolerancePtrArray tolArray;

            /**
             *  �������� �� ������ ���������������
             */
            bool isCombined() override;
      
             /**
             *  �������� ����� ����� �.�.
             */
            unsigned int GetCountCS() override;

             /**
             *  �������� ������� ����������� ����� �� ������� ����� ��
             *  isForVisual - ����� �� �������������� ��������� ��� ������������
             */
            TModifyPointsFunc GetPointsModificationFunc(unsigned int cs_index, bool isForVisual = false) override;
                      
            /**
             *  �������������� ��������� ����� �� ������� ����� ��
             */
            void ModifyFaceParamsByCS(int cs_index) override;

            /**
             * ���������� � ����
             */
            void saveToFile(std::ostream& os) override;

            /**
             * ������ �� �����
             */
            void readFromFile(std::istream& is, Gepard::MathModel *mathModelPtr) override;          

        };

        typedef CombinedTolerance* CombinedTolerancePtr;
        typedef Gepard::General::basicList<CombinedTolerance>     CombinedToleranceList;
        typedef Gepard::General::basicList<CombinedTolerancePtr>  CombinedTolerancePtrList;
        typedef Gepard::General::basicArray<CombinedTolerance>    CombinedToleranceArray;
        typedef Gepard::General::basicArray<CombinedTolerancePtr> CombinedTolerancePtrArray;

    }
}


#endif