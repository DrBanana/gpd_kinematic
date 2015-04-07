///////////////////////////////////////////////////////////
//  GPDLine.cpp
//  Реализация 	Class GPDLine
//  Создана:   	23-апр-2010 10:58:23
//  Автор: 		Dr_Freeman
///////////////////////////////////////////////////////////
#pragma once

#include "../BasicMath/GPDPoint.h"
#include "../BasicMath/GPDVector.h"
#include "GPDCurve3D.h"

namespace Gepard
{
    namespace Curves
    {
        class GPDLine : public Gepard::Curves::GPDCurve3D
        {

        public:
            GPDLine();
            ~GPDLine();

            /**
             *  Конструктор
             */
            GPDLine( Gepard::BasicMath::GPDPoint PStart, 
                     Gepard::BasicMath::GPDPoint PEnd );

            /**
            *	Построить линию по заданным параметрам
            */
            void calcLine(unsigned int numPoints=0);

            /**
             * Построить кривую с заданным числом точек
             */
            void calcCurve(unsigned int numPoints=0) override;

            /**
             *  Задать параметры для кривой
             */
            void setParameters( Gepard::BasicMath::GPDPoint PStart, 
                                Gepard::BasicMath::GPDPoint PEnd );                        

        private:
            /**
             *	Установка параметров по умолчанию
             */
            void setDefaultParameters();
        };

    }

}

