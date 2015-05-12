///////////////////////////////////////////////////////////
//  GPDEllipse.cpp
//  Реализация 	Class GPDEllipse
//  Создана:   	04-мар-2010 15:36:50
//  Автор: 		Dr_Freeman
///////////////////////////////////////////////////////////

#pragma once

#include "GPDCurve3D.h"
#include "../BasicMath/GPDPoint.h"
#include "../BasicMath/GPDVector.h"
#include "../BasicMath/GPDReper.h"
#include <vector>

namespace Gepard
{
    namespace Curves
    {
        /**
         * Эллипс
         */
        class GPDEllipse : public Gepard::Curves::GPDCurve3D
        {

        public:
            GPDEllipse();
            ~GPDEllipse();

            GPDEllipse( double r_small, double R_big, 
                        Gepard::BasicMath::GPDPoint location, 
                        Gepard::BasicMath::GPDVector direction, 
                        Gepard::BasicMath::GPDPoint Pstart, 
                        Gepard::BasicMath::GPDPoint Pend );
            /**
             * малый радиус
             */
            double r;
            /**
             * больший радиус
             */
            double R;
            /**
             * центральная точка эллипса сразу с нормалью
             */
            Gepard::BasicMath::GPDPoint Location;
            /**
             * направление - вектор дальнего радиуса
             */
            Gepard::BasicMath::GPDVector Direction_vector;

            /**
             * Построить эллипс с заданным число точек
             */
            void calcEllipse(int numPoints = 0, bool checkPrec = true);

            /**
            * Построить кривую с заданным числом точек
            * (кроме случая, когда точки получаются почти равны с точностью precDelta)
            */
            void calcCurve(unsigned int numPoints = 0, bool checkPrec = true) override;

            /**
             *  Задать параметры для кривой
             */
            void setParameters( double r_small, double R_big, 
                                Gepard::BasicMath::GPDPoint location, 
                                Gepard::BasicMath::GPDVector direction, 
                                Gepard::BasicMath::GPDPoint Pstart, 
                                Gepard::BasicMath::GPDPoint Pend );

            /**
             *  Преобразует точки кривой из системы координат oldReper в систему координат newReper
             */
            void ConvertToBasis( Gepard::BasicMath::GPDReper &oldReper, 
                                 Gepard::BasicMath::GPDReper &newReper) override;

            /**
             *  Сохранить данные кривой в поток
             */
            void saveToFile(std::ostream& os) override;
            /**
             *  Загрузить данные из потока
             */
            void readFromFile(std::istream& _is) override;

            /**
            *	Кривые совпадают
            */
            bool isEquivalent(Gepard::Curves::GPDCurve3DPtr curve3dPtr) override;

            private:
            /**
             *	Установка параметров по умолчанию
             */
            virtual void setDefaultParameters() override;


        };

    }

}

