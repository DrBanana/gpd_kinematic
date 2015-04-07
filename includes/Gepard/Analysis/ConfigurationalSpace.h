///////////////////////////////////////////////////////////
//  ConfigurationalSpace.h
//  Реализация 	Конфигурационное пространство узла
//  Создана:   	15-сен-2014 16:10
//  Автор: 		Dr_Freeman
///////////////////////////////////////////////////////////


#ifndef CONFIGURATIONALSPACE_H
#define CONFIGURATIONALSPACE_H

#include "../Tolerances/CombinedTolerance.h"
#include "TC_counters.h"
#include "../Topology_Geometry/GPDFace.h"

#include <boost/unordered_map.hpp>

namespace Gepard 
{
    class MathModel;

    namespace Topology_Geometry {class GPDFace; class GPDSolid;}

    namespace Analysis 
    {
    
        /**
         *	Конфигурационное пространство узла
         */
        class ConfigurationalSpace 
        {
        public:
            ConfigurationalSpace();
                              
            /**
             *  Сгенерированный массив допусков - комбинированные и единичные
             */
            Gepard::Tolerances::TolerancePtrArray generatedTolerances;

            /**
             *  Добавить допуск к конфигурационному пространству
             */
            void AddTolerance(Gepard::Tolerances::TolerancePtr tolPtr);

            /**
             *	Функция получает число вариаций допусков по заданным точкам КП
             */
            unsigned int getVariationCount();
            
            /**
             *	Функция расчитывает РЛД (расчетную ленту допусков)
             */
            void createTolCalc();

            /**
             *  Очистить К.П.
             */
            void clear();

            /**
             *  Расчитано ли К.П.
             */
            bool isExist();

            /**
             *  Возвращает массив счетчиков точек К.П. допусков
             */
            TC_counters getTolCSCounters();

            /**
             *  Возвращает индекс допуска, назначенный на заданную грань (номинал)
             */
            int GetTolIndexByNominalFace(GPDFace* nominalFace);

            /**
             *  Модифицирует параметры грани (кроме точек) по назначенным допускам
             */
            void ModifyNominalFaceParams(TC_counters &c, GPDFace* nominalFace);

            /**
             *  Сбросить параметры всех граней в номинальные значения             
             */
            void DropFacesParamsToNominal();                        

            /**
             *  Модифицировать параметры всех граней (кроме точек), на которые назначены допуски
             */
            void ModifyNominalFacesParams(TC_counters &c);

            /**
             *  Скопировать К.П.
             */
            void CopyTo(ConfigurationalSpace *csTo);

             /**
             *  Сохранить данные в файл
             */
            void saveToFile(std::ostream &os);

            /**
             *  Загрузить данные из файла
             */
            void readFromFile(std::istream &is, Gepard::MathModel *mathModelPtr);

            /**
             *  Удаление тела
             */
            bool DeleteSolid(Gepard::Topology_Geometry::GPDSolid *solPtr);

        private:

            /**
             *	Список допусков К.П.			 
             */
            Gepard::Tolerances::TolerancePtrArray toleranceArray;
            
            /**
             *	Список сгенерированных комбинированных допусков
             */
            Gepard::Tolerances::CombinedToleranceList combinedTols;

            /**
             *  Список со списками индексов параметров К.П.
             *  ( первый индекс - номер допуска из genTolsArray,
             *    второй - номер параметра в cs и номер поверхности )
             */
            std::list<std::list<int>> cs_indexes;

            /**
             *  Сгенерировать рассчетный массив допусков 
             *  (создать комбинированные и единичные допуски)
             */
            void GenerateTolCalcArray();
        };
    
    }
}


#endif