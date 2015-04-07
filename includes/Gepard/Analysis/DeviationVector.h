///////////////////////////////////////////////////////////
//  DeviationVector.h
//  Вектор отклонения
//  Создано:  13-окт-2014
//	Оригинальный автор: Anton
///////////////////////////////////////////////////////////

#ifndef DEVIATIONVECTOR_H
#define DEVIATIONVECTOR_H

#include "../BasicMath/GPDPoint.h"
#include "../BasicMath/GPDVector.h"
#include "../General/basicList.h"
#include "../General/basicArray.h"

#include <fstream>

namespace Gepard 
{
    namespace Analysis
    {
        using namespace std;

        /**
         *  Тип вектора отклонения
         */
        enum DV_TYPE { UNKNOWN, CLEARANCE, INTERSECTION };
        

        /**
         *  Структура Вектора отклонения
         */
        struct DeviationVector
        {
            DeviationVector()
            {
                _type = UNKNOWN;
            }

            DeviationVector( Gepard::BasicMath::GPDPoint _bp,
                             Gepard::BasicMath::GPDPoint _dp, 
                             DV_TYPE _t = UNKNOWN )
            : bP(_bp), dP(_dp), _type(_t)
            { }

            /**
             *  Тип вектора
             */
            DV_TYPE _type;

            /**
             *  Точка на базовой грани
             */
            Gepard::BasicMath::GPDPoint bP;

            /**
             *  Точка на зависимой грани
             */
            Gepard::BasicMath::GPDPoint dP;

            /**
             *  Получить вектор отклонения
             */
            Gepard::BasicMath::GPDVector V()
            {                
                return Gepard::BasicMath::GPDVector( dP.x - bP.x, dP.y - bP.y, dP.z - bP.z );
            }

            /**
             *  Обнулить
             */
            void setNull()
            {
                bP.setNull();
                dP.setNull();
                _type = UNKNOWN;
            }

            /**
             *  Перегруженный оператор вывода
             */
            friend ostream& operator<<(ostream& os, const DeviationVector &dv)
            {
                os.write((char *) &dv._type, sizeof dv._type);
                os << dv.bP;
                os << dv.dP;
                return os;
            }

             /**
             *  Перегруженный оператор ввода
             */
            friend istream& operator>>(istream& is, DeviationVector &dv)
            {
                is.read((char *) &dv._type, sizeof dv._type);
                is >> dv.bP;
                is >> dv.dP;
                return is;
            }

        };

        typedef Gepard::General::basicArray<Gepard::Analysis::DeviationVector> DeviationVectorArray;
        typedef Gepard::General::basicList<Gepard::Analysis::DeviationVector>  DeviationVectorList;

        /**
         *  Список векторов отклонений в каждой точке К.П.
         */
        typedef Gepard::General::basicList<DeviationVectorList> DeviationVectorsLists;

    }//Analysis
}//Gepard

#endif