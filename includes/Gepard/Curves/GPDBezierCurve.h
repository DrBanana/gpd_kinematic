///////////////////////////////////////////////////////////
//  GPDBezierCurve.h
//  Реализация	Class GPDBezierCurve
//  Создано:    10-сен-2012 16:53:48
//  Автор:		PashaP
///////////////////////////////////////////////////////////
#pragma once

#include "../BasicMath/GPDPoint.h"
#include "GPDCurve3D.h"
#include <vector>

namespace Gepard
{
    namespace Curves
    {
        
        //using namespace Gepard::BasicMath;
        /**
         * Класс вычисления Bezier кривой
         */ 
        class GPDBezierCurve : public Gepard::Curves::GPDCurve3D
        {

        private:

            int k; //степень кривой Безье
            int Resolution; //Количество точек кривой Безье
            std::vector<Gepard::BasicMath::GPDPoint> ControlPoints;

            /**
             *	Расчет текущей точки по параметру
             */
            void calcCurrentPoint(double u, Gepard::BasicMath::GPDPoint &pnt);

             /**
             *	Установка параметров по умолчанию
             */
            void setDefaultParameters() override;


            public:

                GPDBezierCurve ();
                ~GPDBezierCurve ();
                GPDBezierCurve (int t, std::vector<Gepard::BasicMath::GPDPoint> &Control);

            /**
            *	Построить кривую Безье с заданным числом точек
            */
            void calcBezier( unsigned int numPoints=0, bool checkPrec = true );
                        
            /**
            * Построить кривую с заданным числом точек
            * (кроме случая, когда точки получаются почти равны с точностью precDelta)
            */
            void calcCurve(unsigned int numPoints = 0, bool checkPrec = true) override;

             /**
             *  Задать параметры для кривой
             */
            void setParameters( int t, std::vector<Gepard::BasicMath::GPDPoint> &Control );

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
        };
    }
}