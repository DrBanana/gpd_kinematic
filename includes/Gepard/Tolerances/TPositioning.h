///////////////////////////////////////////////////////////
//  TPositioning.h
//  Допуск позиционный
//  Создана:   	06-июня-2014 14:52
//  Автор: 		Anton
///////////////////////////////////////////////////////////

#ifndef TPOSITIONING_H
#define TPOSITIONING_H
#pragma once

#include "Tolerance.h"

namespace Gepard 
{
    namespace Tolerances 
    {
        /**
         *  Допуск плоскостности
         */
        class TPositioning : public Tolerance
        {
        public:

            TPositioning();

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
             *  Подходит ли данная поверхность для данного допуска
             */
            bool CheckFace(Gepard::Topology_Geometry::GPDFacePtr facePtr) override;

            /**
             *  Посчитать значение gamma (для каждого допуска разное)
             *  по значению допуска и параметрам поверхности
             */
            double CalcGammaByTolValue(double tolValue) override;

             /**
             *  Модифицировать параметры грани по значению точки КП
             */
            void ModifyFaceParamsByCS(CSParam par) override;          

        };

    }//Tolerances
}//Gepard

#endif