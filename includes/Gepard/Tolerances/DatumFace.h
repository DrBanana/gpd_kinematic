///////////////////////////////////////////////////////////
//  DatumFace.h
//  Список базовых поверхностей (граней)
//  Создано:  04-фев-2014
///////////////////////////////////////////////////////////

#pragma once

#include "../Topology_Geometry/GPDFace.h"

namespace Gepard 
{
    namespace Tolerances
    {
    
     /**
         *  Ссылочная база
         */
        struct DatumFace
        {
            DatumFace() { Clear(); }
            DatumFace(Gepard::Topology_Geometry::GPDFacePtr f, int di)
                      : datum_index(di), facePtr(f) {}

            /**
             *  Индекс базы. Начинается с нуля.
             *  Может быть интерпретирован как символ: 
             *  char s = datum_index + 65;
             */
            int datum_index;

            /**
             *  Указатель на грань
             */
            Gepard::Topology_Geometry::GPDFacePtr facePtr;

            /**
             *  Получить символ ссылочной базы
             */
            char GetSymbol(int di) 
            {
                int max_index = 65+26;
                char cur_index = di + 65;

                if (cur_index>=max_index) return max_index;

                return cur_index;
            }

            /**
             *  Очистить 
             */
            void Clear()
            {                
                datum_index = -1;
                facePtr = nullptr;
            }

        };
    }
}