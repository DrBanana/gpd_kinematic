///////////////////////////////////////////////////////////
//  TDiameter.h
//  Допуск на диаметр
//  Создана:   	03-июля-2014
//  Автор: 		Anton
///////////////////////////////////////////////////////////

#ifndef TDIAMETER_H
#define TDIAMETER_H

#pragma once

#include "Tolerance.h"

namespace Gepard 
{
    class MathModel;

    namespace Tolerances 
    {
        /**
         *  Допуск на диаметр
         */
        class TDiameter : public Tolerance
        {
        public:
            TDiameter();

            /**
             *  Установить указатель на посадку
             */
            void SetFit(Gepard::Tolerances::Fit *fitPtr);

            /**
             *  Получить указатель на посадку
             */
            Gepard::Tolerances::Fit* GetFit();
            
        protected:

            /**
             *  Вычислить конфигурационное пространство для допуска
             */
            double calcConfigurationSpaceTol( unsigned int COUNT_CONF_POINTS) override;

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
             *  Получить коэффициент для визуализации допуска
             */
            double GetVisualKoeff() override;

            /**
             *  Допуск задан с помощью посадки (на диаметр)
             */
            bool isFit() override;

             /**
             * сохранение в файл
             */
            void saveToFile(std::ostream& os) override;

            /**
             * чтение из файла
             */
            void readFromFile(std::istream& is, Gepard::MathModel *mathModelPtr) override;

        private:

            /**
             *  Допуск находится в посадке
             */
            bool is_fit;

            /**
             *	Указатель на родительскую посадку
             */
            Gepard::Tolerances::Fit *parentFit;

        };

    }//Tolerances
}//Gepard


#endif