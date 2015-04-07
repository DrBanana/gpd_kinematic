///////////////////////////////////////////////////////////
//  CSParam.h
//  Реализация 	struct CSParam
//  Описание:     Параметр К.П.
//  Автор: 		Dr_Freeman
///////////////////////////////////////////////////////////

#pragma once

#include "../General/basicList.h"

namespace Gepard
{
    namespace Tolerances
    {

        /**
         * Параметр конф. пространства
         */
        struct CSParam
        {
            CSParam()
            {
                fi = 0.0;
                psi = 0.0;
                tol = 0.0;
            };
            CSParam(double _fi, double _psi)
                    : fi(_fi), psi(_psi), tol(0.0) {};

            CSParam(double _fi, double _psi, double _tol)
                    : fi(_fi), psi(_psi), tol(_tol) {};

            /**
             *  Вернуть значение параметра КП
             */
            double& operator[](int ind)
            {
                if      (ind == 0) return fi;
                else if (ind == 1) return psi;
                else if (ind == 2) return tol;
                return fi;
            }

            /**
             *  Оператор сравнения
             */
            bool operator==(CSParam &p)
            {
                return (fi==p.fi && psi == p.psi);
            }
            /**
             *	Значение FI
             */
            double fi;
            /**
             *	Значение PSI
             */
            double psi;
            /**
             *  Значение отклонения tol
             */
            double tol;
        };

        /**
         *  Список параметров К.П.
         */
        typedef Gepard::General::basicList<CSParam> CSParamsList;
}
}