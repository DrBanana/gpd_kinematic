///////////////////////////////////////////////////////////
//  additionalFuncs.cpp
//  Реализация 	additionalFuncs
//  Создана:   	5-авг-2013 12:50:24
//  Автор: 		Freeman
//  Описание:   Дополнительные функции
///////////////////////////////////////////////////////////

#ifndef ADDITIONAL_FUNCS_H
#define ADDITIONAL_FUNCS_H
#pragma once

#include "GPDPoint2dn.h"
#include "GPDVector.h"
#include "GPDPoint.h"
#include "../Surfaces/QuadMap.h"

#include <functional>

namespace Gepard 
{
    namespace BasicMath 
    {

///----------------------------------------------------------------------------------------------------------
//Определения, общие переменные и др.
        /**
         *  Функция модификации точки 3D по параметру КП.
         */
        typedef std::function<void(GPDPoint2d, GPDPoint &)> TModifyPointsFunc;

        /**
         *  Абстрактная функция
         */
        //typedef std::function<void()> TAbstractFunc;

///----------------------------------------------------------------------------------------------------------
//Функции
        /**
         *  Функция вычисляет номер сегмента (сетки numU x numV) в области {U0,V0} - {U1,V1} (quad_map)
         *  по координатам точки (u,v)
         *  Возвращаемое значение - номер сегмента от 0 до numU*numV
         */
        int CalcSegmentNum( double U, double V,
                            Gepard::Surfaces::QuadMap &quad_map  );

        /**
        *  Функция вычисляет индексы (координаты) сектора (u,v) на карте {U0;U1 - V0;V1}, 
        *  в котором находится точка P(U,V)
        */
        int CalcSegmentIndexes( double U, double V, 
                                double U0, double V0, 
                                double U1, double V1,
                                unsigned int NumU, unsigned int NumV,
                                int &u_index, int &v_index );

        /**
         *  Функция вычисляет индексы (координаты) сектора (u,v) на карте (quad_map), 
         *  в котором находится точка P
         *  Функция корректирует индексы в случае, если точка лежит на границе! (Флаг isCorrectLimits)
         */
        int CalcSegmentIndexes( Gepard::BasicMath::GPDPoint2dPtr P,
                                Gepard::Surfaces::QuadMap &quad_map,
                                int &u_index, int &v_index, bool isCorrectLimits = true );        

        /**
         *  Функция вычисляет по номеру сектора его координаты на карте
         */
        void CalcSegmentIndexesByNum( unsigned int NumSeg, 
                                      unsigned int NumU, unsigned int NumV, 
                                      int &u_index, int &v_index );

        /**
         *  Функция вычисляет индексы (координаты) точки (u,v) на карте по индексу точки в массиве
         */
        void CalcPointUVIndexes( unsigned int p_index, 
                                 unsigned int NumU, unsigned int NumV, 
                                 int &u_index, int &v_index );

        /**
         *  Направление от текущего сегмента
         */
        enum SEGMENT_DIRECTION 
        {
            SD_LEFT,
            SD_RIGHT,
            SD_UP,
            SD_UP_LEFT,
            SD_UP_RIGHT,
            SD_DOWN,
            SD_DOWN_LEFT,
            SD_DOWN_RIGHT            
        };

        /**
         *  Функция вычисляет номер сегмента по заданному направлению от текущего
         *  В случае возврата -1 - выход за границу карты
         */
        int CalcSegmentNumByDirection( unsigned int NumSeg, 
                                       unsigned int NumU, unsigned int NumV,
                                       SEGMENT_DIRECTION SegDir );

        /**
         *  Вычисляет точку пересечения треугольника (t) с заданным отрезком (l)
         */
        bool CrossTriangleAndLine(GPDPoint (t)[3], GPDVector n, GPDPoint (l)[2], GPDPoint &P);

        /**
         *	Пропорционально вычислить нормаль для точки P(2d)
         */
        void CalcPoint2DNormal(GPDPoint2dn *A, GPDPoint2dn *B, GPDPoint2dn *P);

///----------------------------------------------------------------------------------------------------------
//Классы

        /**
         *  Класс для растеризации линии
         */
        class RasterizeLine
        {
        public:
            explicit RasterizeLine(Gepard::Surfaces::QuadMap &Quad_Map);

            /**
             *  Структура предрасчитанных значений
             */
            struct PreCalcStruct
            {
                /**
                *  Рассчитанные значения координатных линий по u
                */
                std::vector<double> d_cash_u;

                /**
                *  Рассчитанные значения координатных линий по v
                */
                std::vector<double> d_cash_v;

                /**
                *  Предрасчитанные значения для СЕКТОРА
                */
                double qU, qV;
                double stepU, stepV;

                /**
                 *  Количество СЕКТОРОВ на карте по U и V
                 */
                unsigned int countU, countV;
            };


             /**
             *  Функция растеризует линию 2D (В растр сетки numU x numV)
             *  (Работает по уравнению прямой)
             *  Входные значения:
             *  P0, P1 - Координаты крайних точек линии (должны принадл. Области)         
             *
             *  Возврат: 
             *  SectorsList - список координат секторов (u,v)
             *  true - прямой порядок секторов (от P0 до P1), 
             *  false - обратный порядок секторов (от P1 до P0)
             */
            bool RasterLine( Gepard::BasicMath::GPDPoint2dPtr P0,
                             Gepard::BasicMath::GPDPoint2dPtr P1,                         
                             Gepard::General::basicList<std::pair<int,int>> &SectorsList );

            /**
             *  Функция растеризует линию 2D (В растр сетки numU x numV)
             *  и получает список точек пересечения с секторами
             *
             *  Входные значения:
             *  P0, P1 - Координаты крайних точек линии (должны принадл. Области)         
             *
             *  Возврат: 
             *  SectorsList - список координат секторов (u,v)
             *  CrossPointList - список, содержащий список точек пересечений сектора 
             */
            void RasterLine( Gepard::BasicMath::GPDPoint2dPtr P0,
                             Gepard::BasicMath::GPDPoint2dPtr P1,                         
                             Gepard::General::basicList<std::pair<int,int>> &SectorsList,
                             Gepard::General::basicList<
                                std::list<Gepard::BasicMath::GPDPoint2d>> &CrossPointList);


         private:

            /**
             *  Предрасчитанные значения
             */
            PreCalcStruct preCalc;

            /**
             *  Параметры карты для растеризации (сетка)
             */
            Gepard::Surfaces::QuadMap quad_map;

            /**
             *  Функция вычисляет предпросчитанные значения для сегмента
             */
            void PreCalc();                

        };
    };
};

#endif