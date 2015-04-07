///////////////////////////////////////////////////////////
//  TPerpendicularity.h
//  Допуск перпендикулярности
//  Создана:   	06-июня-2014 14:06:38
//  Автор: 		Anton
///////////////////////////////////////////////////////////

#ifndef TPERPENDICULARITY_H
#define TPERPENDICULARITY_H
#pragma once

#include "Tolerance.h"

namespace Gepard 
{
    namespace Tolerances 
    {
        /**
         *  Допуск перпендикулярности
         */
        class TPerpendicularity : public Tolerance
        {
            friend class TFlatness;
            friend class TParallelity;

        public:

            TPerpendicularity();


        protected:

            /**
             *  Вычислить конфигурационное пространство для допуска
             */
            double calcConfigurationSpaceTol( unsigned int COUNT_CONF_POINTS ) override;

            /**
             *  Вычислить значение допуска по значению параметра точки К.П.
             */
            double calcTolValueByCSParam(CSParam par, double A=0.0, double B=0.0) override;

            /**
             *  Получить функцию модификации точек по значению точки КП             
             */
            TModifyPointsFunc GetPointsModificationFunc(CSParam par) override;            
        
            /**
             *  Модифицировать параметры грани по значению точки КП
             */
            void ModifyFaceParamsByCS(CSParam par) override;

             /**
             *  Подходит ли данная поверхность для данного допуска
             */
            bool CheckFace(Gepard::Topology_Geometry::GPDFacePtr facePtr) override;

            /**
             *  Посчитать значение gamma (для каждого допуска разное)
             *  по значению допуска и параметрам поверхности
             */
            double CalcGammaByTolValue(double tolValue) override;

            /**
             *  Получить коэффициент для визуализации допуска
             */
            double GetVisualKoeff() override;

            /**
             *  Функция для расчета нового репера точек по точке К.П.
             */
            bool CalcRepers(CSParam par, GPDReper &nominal_point_reper, GPDReper &point_reper);
                       
        };

    }//Tolerances
}//Gepard

#endif