///////////////////////////////////////////////////////////
//  DatumFaceReferenceList.h
//  ������ ������� ������������ (������)
//  �������:  27-���-2014
///////////////////////////////////////////////////////////

#pragma once

#include "DatumFace.h"
#include "../General/basicArray.h"

namespace Gepard 
{
    namespace Tolerances
    {       
        /**
         *  ������ ��������� ���
         */
        class DatumFaceReferenceList : public Gepard::General::basicList<DatumFace>
        {
        public:
            /**
             *  ���� �� ����� ����
             */
            bool isDatumExist(DatumFace &datumFace);

            /**
             *  ���� �� ����� ���� (�� ������� �� 0)
             */
            bool isDatumExist(int datum_index);

            /**
             *  �������� ������ �������� �� ��������� �� �����������
             */
            int GetDatumElementIndex(Gepard::Topology_Geometry::GPDFacePtr _facePtr);

            /**
             *  �������� ��������� ����������� ������ ����
             *  (���� �����-���� ������� ����� �������������� ������, 
             *  �� ��������� ������ ����� ����� ������� ����������)
             */
            int GetNextDatumIndex();

            /**
             *  �������� ������������ ����� ��������
             */
            int getMax();

            /**
             *  �������� ��������� �� ����
             */
            DatumFace* GetDatum(DatumFace &datumFace);
                        
            /**
             *  �������� ��������� �� ���� �� �������
             */
            DatumFace* GetDatum(int datum_index);

            /**
             *  ������� ���� �� ������
             */
            void DeleteDatum(DatumFace &datumFace);

            /**
             *  �������� ����� � �������� ������� � ������� (���� ����� ����� ��� ���).
             *  ������� - ������ ����� � �������
             */
            int AddDatumFace(Gepard::Topology_Geometry::GPDFacePtr _facePtr);
        };

    }//namespace Tolerances
}//namespace Gepard 
