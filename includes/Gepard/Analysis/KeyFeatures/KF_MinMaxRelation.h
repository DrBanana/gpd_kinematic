///////////////////////////////////////////////////////////
//  KF_MinMaxRelation.h
//  Ключевое свойство - Максимальный и минимальный вектор
//  Создано:  5-ноя-2014
//  Оригинальный автор: Anton
///////////////////////////////////////////////////////////

#pragma once

#include "KF_PrecDiagram.h"

namespace Gepard 
{
    class MathModel;

    //TODO: Добавить процент зазоров и натягов (по примеру диаграммы точности)

    namespace Analysis 
    {
        /**
         *  Ключевое свойство - Максимальный и минимальный вектор
         */
        class KF_MinMaxRelation: public KF_PrecDiagram                                 
        {
        public:

            explicit KF_MinMaxRelation(KEY_FEATURE_TYPE minmaxType);
                        
            /**
             *  Максимальный вектор
             */
            DeviationVector max_vector;

            /**
             *  Максимальный вектор
             */
            DeviationVector min_vector;
            
            /**
             *  Есть ли результаты для данного свойства
             */
            bool hasResults() override;

            /**
             *  Очистить результаты предыдущего анализа
             */
            void ClearResults() override;

            /**
             *  Посчитать минимальный и максимальный зазор
             */
            void CalcMinMaxRelation();

            /**
             *  Сохранить данные в файл
             */
            void saveToFile(std::ostream &os) override;

            /**
             *  Загрузить данные из файла
             */
            void readFromFile(std::istream &is, Gepard::MathModel *mathModelPtr) override;

        private:

            /**
             *  Тип вектора
             */
            DV_TYPE dvType;
        };
    }
}
