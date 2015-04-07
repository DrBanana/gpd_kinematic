///////////////////////////////////////////////////////////
//  GPDCircle.cpp
//  Реализация 	Class GPDCircle
//  Создана:   	04-мар-2010 17:20:51
//  Автор: 		Dr_Freeman
///////////////////////////////////////////////////////////
#pragma once

#include "GPDEllipse.h"

namespace Gepard
{
    namespace Curves
    {
        class GPDCircle : public Gepard::Curves::GPDEllipse
        {

        public:
            GPDCircle();
            ~GPDCircle();
                        
            GPDCircle( double radius, Gepard::BasicMath::GPDPoint location, Gepard::BasicMath::GPDVector direction, 
                                      Gepard::BasicMath::GPDPoint PStart,   Gepard::BasicMath::GPDPoint PEnd);

            /**
            *	Построить окружность с заданным числом точек
            */
            void calcCircle( unsigned int numPoints=0 );

            /**
             * Построить кривую с заданным числом точек
             */
            void calcCurve(unsigned int numPoints=0) override;

            /**
             *  Задать параметры для кривой
             */
            void setParameters( double radius,
                                Gepard::BasicMath::GPDPoint location, 
                                Gepard::BasicMath::GPDVector direction, 
                                Gepard::BasicMath::GPDPoint PStart, 
                                Gepard::BasicMath::GPDPoint PEnd );                        

            /**
             *  Преобразует точки кривой из системы координат oldReper в систему координат newReper
             */
            void ConvertToBasis( Gepard::BasicMath::GPDReper &oldReper, 
                                 Gepard::BasicMath::GPDReper &newReper) override;

        private:
            /**
             *	Установка параметров по умолчанию
             */
            void setDefaultParameters() override;
        };

    }

}

