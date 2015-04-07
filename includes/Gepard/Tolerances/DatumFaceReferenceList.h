///////////////////////////////////////////////////////////
//  DatumFaceReferenceList.h
//  Список базовых поверхностей (граней)
//  Создано:  27-янв-2014
///////////////////////////////////////////////////////////

#pragma once

#include "DatumFace.h"
#include "../General/basicArray.h"

namespace Gepard 
{
    namespace Tolerances
    {       
        /**
         *  Массив ссылочных баз
         */
        class DatumFaceReferenceList : public Gepard::General::basicList<DatumFace>
        {
        public:
            /**
             *  Есть ли такая база
             */
            bool isDatumExist(DatumFace &datumFace);

            /**
             *  Есть ли такая база (по индексу от 0)
             */
            bool isDatumExist(int datum_index);

            /**
             *  Получить индекс Элемента по указателю на поверхность
             */
            int GetDatumElementIndex(Gepard::Topology_Geometry::GPDFacePtr _facePtr);

            /**
             *  Получить следующий минимальный индекс базы
             *  (Если какой-либо элемент будет предварительно удален, 
             *  то следующий индекс будет равен индексу удаленного)
             */
            int GetNextDatumIndex();

            /**
             *  Получить максимальное число символов
             */
            int getMax();

            /**
             *  Получить указатель на базу
             */
            DatumFace* GetDatum(DatumFace &datumFace);
                        
            /**
             *  Получить указатель на базу по индексу
             */
            DatumFace* GetDatum(int datum_index);

            /**
             *  Удалить базу из списка
             */
            void DeleteDatum(DatumFace &datumFace);

            /**
             *  Добавить грань в качестве базовой к массиву (если такой грани еще нет).
             *  Возврат - индекс грани в массиве
             */
            int AddDatumFace(Gepard::Topology_Geometry::GPDFacePtr _facePtr);
        };

    }//namespace Tolerances
}//namespace Gepard 
