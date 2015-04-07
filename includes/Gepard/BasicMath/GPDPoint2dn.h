///////////////////////////////////////////////////////////
//  GPDPoint2dn.h
//  Реализация	Class GPDPoint2dn
//  Создано:    09-ноя-2012 12:10:31
//  Автор:		Dr_Freeman
///////////////////////////////////////////////////////////

#if !defined(EA_9CE44084_A907_4688_BD8C_167CD498E2A1__INCLUDED_)
#define EA_9CE44084_A907_4688_BD8C_167CD498E2A1__INCLUDED_

#include "GPDPoint2d.h"
#include "..\General\basicArray.h"
#include "..\General\basicList.h"

namespace Gepard
{
    namespace BasicMath
    {
        class GPDVector2d;
        /**
         * Класс двухмерной точки с 2D нормалью
         */
        class GPDPoint2dn : public Gepard::BasicMath::GPDPoint2d
        {

        public:
            /**
             *	Нормаль к точке
             */
            double nu,nv;

            GPDPoint2dn();
            ~GPDPoint2dn();
            GPDPoint2dn(GPDPoint2d &P);
            GPDPoint2dn(double U, double V);
            GPDPoint2dn(double U, double V,	double NU, double NV);

            /**
             * Получить нормаль
             */
            Gepard::BasicMath::GPDVector2d getNormal();

            /**
             *  Нормализация нормали
             */
            void Normalize();

            /**
             *  Функция инвертирования нормали
             */
            void InvertNormal();

        };
        typedef GPDPoint2dn* GPDPoint2dnPtr;	//Указатель на 2D точку
        typedef GPDPoint2dn& GPDPoint2dnRef;	//Ссылка на 2D точку
        typedef Gepard::General::basicArray<GPDPoint2dn> GPDPoint2dnArray; 	//Массив 2d точек
        typedef Gepard::General::basicList<GPDPoint2dn> GPDPoint2dnList;		//Список 2d точек
        typedef Gepard::General::basicArray<GPDPoint2dnPtr> GPDPoint2dnPtrArray;	//Массив указателей на 2d точки
        typedef Gepard::General::basicList<GPDPoint2dnPtr> GPDPoint2dnPtrList;		//Список указателей на 2d точки


    }

}
#endif // !defined(EA_9CE44084_A907_4688_BD8C_167CD498E2A1__INCLUDED_)
