///////////////////////////////////////////////////////////
//  KeyCharacteristics.h
//  Ключевая характеристика (этап размерного анализа)
//  Создано:  13-сен-2014
//	Оригинальный автор: Anton
///////////////////////////////////////////////////////////

#ifndef KEYCHARACTERISTICS_H
#define KEYCHARACTERISTICS_H

#include "../Assembly/AssemblyStructure.h"
#include "ConfigurationalSpace.h"
#include "AnalysisRules.h"
#include "ConstructiveParams.h"
#include "KeyFeatures/KeyFeature.h"
#include "DeviationVector.h"
#include "../Topology_Geometry/GPDFace.h"

#include <boost/unordered_map.hpp>

namespace Gepard 
{
    class MathModel;

    namespace Analysis 
    {

        /**
         *	Ключевая характеристика (этап размерного анализа)
         */
        class KeyCharacteristics
        {

        public:
            KeyCharacteristics();

            /**
             *	Название
             */
            std::string Name;		
            
            /**
             *	Указатель на узел графа сборки
             */
            Gepard::Assembly::AssemblyNode *asmNode;
            
            /**
             *	Набор конструктивных параметров (допусков), 
             *	Конфигурационное пространство узла
             */
            ConstructiveParamList constructiveParameters;

            /**
             *  Конфигурационное пространство, 
             *  сформированное по назначенным конструктивным параметрам
             */
            ConfigurationalSpace confSpace;

            /**
             *	Ключевые свойства (вычисляемые/результирующие)
             */
            KeyFeaturePtrList keyFeatures;
             
            /**
             *	Правила анализа
             */            
            AnalysisRuleList analysisRules;

            /**
             *	Результаты анализа по ключевым параметрам
             */			 

            /**
             *  Очистить параметры
             */
            void clear();
            
            /**
             * Копировать ключевую характеристику 
             */
            void CopyTo(KeyCharacteristics *kc_to);

            /**
             *  Функция пространственного размерного анализа 
             */
            void Analize();

            /**
             *  Удалить деталь
             */
            void DeleteSolid(Gepard::Topology_Geometry::GPDSolidPtr solPtr);

            /**
             *  Есть ли результаты
             */
            bool isHasResults();

            /**
             *	Очистить результаты
             */
            void ClearResults();

            /**
             *  Сохранить данные в файл
             */
            void saveToFile(std::ostream &os);

            /**
             *  Загрузить данные из файла
             */
            void readFromFile(std::istream &is, Gepard::MathModel *mathModelPtr);

        private:

            /**
             *  Список деталей, которые необходимо сбросить до номинала
             */
            boost::unordered_map< Gepard::Topology_Geometry::GPDSolidPtr,
            std::pair<Gepard::BasicMath::GPDReper, Gepard::BasicMath::GPDReper>> dropSolids;

            /**
             *  Применить правила анализа в данной точке
             */
            void ApplyAnalysisRules(TC_counters &c);
            
            /**
             *  Получить ключевые свойства для точки К.П.
             */
            void CalcKeyFeatures(TC_counters &c);

            /**
             *  Сбросить тела в номинальное положение
             */
            void DropSolidsToNominal();
           
            /**
             *	Получить указатель на допуск и индекс точки по грани
             */
            void GetFaceTolAndIndex( Gepard::Topology_Geometry::GPDFace* face,
                                     TC_counters &c,
                                     Gepard::Tolerances::Tolerance **tolPtr, 
                                     int &csIndex );
                                
        };

        typedef Gepard::General::basicList<KeyCharacteristics>  KeyCharacteristicsList;
        typedef Gepard::General::basicArray<KeyCharacteristics> KeyCharacteristicsArray;
        typedef Gepard::General::basicArray<KeyCharacteristics*> KeyCharacteristicsPtrArray;

    }//Analysis
}//Gepard

#endif
