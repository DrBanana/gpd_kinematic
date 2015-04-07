///////////////////////////////////////////////////////////
//  TParallelity.h
//  Допуск параллельности
//  Создана:   	06-июня-2014 09:50:15
//  Автор: 		Anton
///////////////////////////////////////////////////////////

#ifndef TPARALLELITY_H
#define TPARALLELITY_H
#pragma once

#include "Tolerance.h"

namespace Gepard 
{
    namespace Tolerances 
    {

        /**
         *  Допуск параллельности
         */
        class TParallelity : public Tolerance
        {
        public:

            TParallelity();


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
             *  Подходит ли данная поверхность для данного допуска
             */
            bool CheckFace(Gepard::Topology_Geometry::GPDFacePtr facePtr) override;

            /**
             *  Посчитать значение gamma (для каждого допуска разное)
             *  по значению допуска и параметрам поверхности
             */
            double CalcGammaByTolValue(double tolValue) override;

            /**
             *  Получить функцию модификации точек по значению точки КП             
             */
            TModifyPointsFunc GetPointsModificationFunc(CSParam par) override;

            /**
             *  Модифицировать параметры грани по значению точки КП
             */
            void ModifyFaceParamsByCS(CSParam par) override;

            /**
             *  Получить коэффициент для визуализации допуска
             */
            double GetVisualKoeff() override;

        };

    }//Tolerances 
}//Gepard 

#endif