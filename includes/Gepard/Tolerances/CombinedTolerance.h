///////////////////////////////////////////////////////////
//  CombinedTolerance
//  Реализация 	 Комбинированный допуск 
//			 - несколько допусков на одну поверхность
//  Создана:   	 15-сен-2014 15:02:15
//  Автор: 		 Dr_Freeman
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
         *	Комбинированный допуск - состоит из нескольких допусков,
         *	назначенных на одну поверхность
         */
        class CombinedTolerance : public Gepard::Tolerances::Tolerance
        {

        public:
            CombinedTolerance();
            CombinedTolerance(Gepard::Topology_Geometry::GPDFacePtr tFacePtr);

            /**
             *  Список допусков для данного комбинированного
             */
            TolerancePtrArray tolArray;

            /**
             *  Является ли допуск комбинированным
             */
            bool isCombined() override;
      
             /**
             *  Получить число точек К.П.
             */
            unsigned int GetCountCS() override;

             /**
             *  Получить функцию модификации точек по индексу точки КП
             *  isForVisual - нужно ли модифицировать параметры для визуализации
             */
            TModifyPointsFunc GetPointsModificationFunc(unsigned int cs_index, bool isForVisual = false) override;
                      
            /**
             *  Модифицировать параметры грани по индексу точки КП
             */
            void ModifyFaceParamsByCS(int cs_index) override;

            /**
             * сохранение в файл
             */
            void saveToFile(std::ostream& os) override;

            /**
             * чтение из файла
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