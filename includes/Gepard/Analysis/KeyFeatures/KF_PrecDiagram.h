///////////////////////////////////////////////////////////
//  KF_PrecDiagram.h
//  Ключевое свойство - Диаграмма точности
//  Создано:  2-окт-2014
//	Оригинальный автор: Anton
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
         *  Ключевое свойство - Диаграмма точности
         */
        class KF_PrecDiagram : public FacesRelation
        {
        public:
            KF_PrecDiagram();            
          
            /**
             *  Очистить результаты предыдущего анализа
             */
            void ClearResults() override;                      

            /**
             *  Получить список векторов отклонений между заданными гранями
             */
            void CalcDeviationVectors( Gepard::Tolerances::Tolerance *b_tol, int b_csIndex,
                                       Gepard::Tolerances::Tolerance *d_tol, int d_csIndex,
                                       unsigned int tc_index );            

            /**
             *  Количество списков
             */
            unsigned int ResultsCount();

            /**
             *  Есть ли результаты для данного свойства
             */
            bool hasResults() override;

            /**
             *  Посчитать максимум и минимум отрицательных 
             * и положительных отклонений во всех точках К.П.
             */
            void CalcMinMax( double &max_tight, double &min_tight, 
                             double &max_gap,   double &min_gap );

            /**
             *  Посчитать максимум и минимум отрицательных 
             *  и положительных отклонений во всех точках К.П.
             *  + Сформировать массивы для врезаний и зазоров для каждой точки
             */
            void CalcMinMax( double &max_tight, double &min_tight, 
                             double &max_gap,   double &min_gap,
                             std::vector<std::pair<double, double>> *tights_array,
                             std::vector<std::pair<double, double>> *gaps_array );

            /**
             *  Посчитать максимум и минимум отрицательных 
             * и положительных отклонений во всех точках К.П.
             */
            void CalcMinMax( unsigned int cs_index,
                             double &max_tight, double &min_tight, 
                             double &max_gap,   double &min_gap );

            /**
             *	Рассчитать проценты полностью отрицательных 
             *  и полностью положительных отклонений во всех точках К.П.
             */
            void CalcPercentage( int &tight_percent, int &gap_percent);

            /**
             *  Получить абсолютный минимум и абсолютный максимум в заданной точке К.П.
             */
            void GetAbsMinMax(unsigned int cs_index, double &abs_min, double &abs_max);

            /**
             *  Получить абсолютный максимум в заданной точке К.П.
             */
            double GetAbsMax(unsigned int cs_index);

            /**
             *  Список списков векторов отклонений между заданными гранями в каждой точке К.П.
             */
            DeviationVectorsLists deviationVectorsLists;

            /**
             *  Список точек К.П., в которых есть вектора отклонений
             */
            std::vector<unsigned int> tc_indexes;

            /**
             *  Сохранить данные в файл
             */
            void saveToFile(std::ostream &os) override;

            /**
             *  Загрузить данные из файла
             */
            void readFromFile(std::istream &is, Gepard::MathModel *mathModelPtr) override;
            
        };

    }
}