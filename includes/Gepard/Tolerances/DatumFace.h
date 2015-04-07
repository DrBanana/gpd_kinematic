///////////////////////////////////////////////////////////
//  DatumFace.h
//  ������ ������� ������������ (������)
//  �������:  04-���-2014
///////////////////////////////////////////////////////////

#pragma once

#include "../Topology_Geometry/GPDFace.h"

namespace Gepard 
{
    namespace Tolerances
    {
    
     /**
         *  ��������� ����
         */
        struct DatumFace
        {
            DatumFace() { Clear(); }
            DatumFace(Gepard::Topology_Geometry::GPDFacePtr f, int di)
                      : datum_index(di), facePtr(f) {}

            /**
             *  ������ ����. ���������� � ����.
             *  ����� ���� ��������������� ��� ������: 
             *  char s = datum_index + 65;
             */
            int datum_index;

            /**
             *  ��������� �� �����
             */
            Gepard::Topology_Geometry::GPDFacePtr facePtr;

            /**
             *  �������� ������ ��������� ����
             */
            char GetSymbol(int di) 
            {
                int max_index = 65+26;
                char cur_index = di + 65;

                if (cur_index>=max_index) return max_index;

                return cur_index;
            }

            /**
             *  �������� 
             */
            void Clear()
            {                
                datum_index = -1;
                facePtr = nullptr;
            }

        };
    }
}