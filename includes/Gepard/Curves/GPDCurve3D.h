///////////////////////////////////////////////////////////
//  GPDCurve.h
//  Реализация	Class GPDCurve
//  Создано:    15-ноя-2012 16:15:33
//  Автор:		Dr_Freeman
///////////////////////////////////////////////////////////

#if !defined(EA_05916F1D_D6E7_43e5_9EE8_82360E9A3782__INCLUDED_)
#define EA_05916F1D_D6E7_43e5_9EE8_82360E9A3782__INCLUDED_

#include "../BasicMath/GPDPoint.h"
#include "../General/basicArray.h"
#include "../BasicMath/basicFuncs.h"
#include "CURVE_3D_TYPE.h"


namespace Gepard
{
    namespace Curves
    {

        class GPDLine;
        class GPDCircle;
        class GPDEllipse;        
        class GPDBezierCurve;
        class GPDNurbsCurve;

        /**
         * Базовый класс кривой
         */
        class GPDCurve3D
        {           

        public:
            /**
             * Массив 3D точек кривой
             */
            Gepard::BasicMath::GPDPointArray Points;

            GPDCurve3D();
            virtual ~GPDCurve3D();
        
            /**
             * Получить тип кривой
             */
            CURVE_3D_TYPE getCurveType();

            /**
             * Построить кривую с заданным числом точек
             */
            virtual void calcCurve(unsigned int numPoints=0);

            /**
             *  Преобразовать в линию
             */
            GPDLine* toLine();

            /**
             *  Преобразовать в окружность
             */
            GPDCircle* toCircle();

            /**
             *  Преобразовать в эллипс
             */
            GPDEllipse* toEllipse();           

            /**
             *	Преобразовать в кривую NURBS
             */
            GPDNurbsCurve* toNURBS();

            /**
             *	Получить крайнюю точку A
             */
            Gepard::BasicMath::GPDPoint getPointA();

            /**
            *	Получить крайнюю точку B
            */
            Gepard::BasicMath::GPDPoint getPointB();

            /**
             *	Установить крайнюю точку A
             */
            virtual void setPointA(Gepard::BasicMath::GPDPoint _a);

            /**
             *	Установить крайнюю точку B
             */
            virtual void setPointB(Gepard::BasicMath::GPDPoint _b);

            /**
             *  Получить значение флага замкнутости кривой
             */
            bool IsClosed();

            /**
             *  Преобразовать в заданную кривую
             */
            template <class T>
            T* Convert();

            /**
             *  Преобразует точки кривой из системы координат oldReper в систему координат newReper
             */
            virtual void ConvertToBasis( Gepard::BasicMath::GPDReper &oldReper, 
                                         Gepard::BasicMath::GPDReper &newReper);

            /**
             *  Установить данной кривой эквивалентные параметры кривой fromCurvePtr
             */
            virtual void SetEquivalentParameters(GPDCurve3D* curvePtr);

            /**
             *  Сохранить данные кривой в поток
             */
            virtual void saveToFile(std::ostream& os);

            /**
             *  Загрузить данные из потока
             */
            virtual void readFromFile(std::istream& _is);

            /**
             *	Кривые совпадают
             */
            virtual bool isEquivalent(GPDCurve3D* curve3dPtr);

            /**
             *	Получить ограничивающий параллелепипед
             */
            Gepard::BasicMath::BoundingBox GetBoundingBox();

        protected:
            /**
             *	Начальная и конечная точки кривой
             */
            Gepard::BasicMath::GPDPoint A, B;
        
            /**
             * тип кривой
             */
            Gepard::Curves::CURVE_3D_TYPE CurveType;

            /**
             *	Число точек кривой по умолчанию
             */
            int defaultPointsCount;

            /**
             *  Замкнутая кривая
             */
            bool isCurveClosed;

            /**
             *	Накрывающие параллелепипед для кривой
             */
            Gepard::BasicMath::BoundingBox boundingBox;

        private:
             /**
             *	Установка параметров по умолчанию
             */
            virtual void setDefaultParameters();
        };
        typedef Gepard::Curves::GPDCurve3D* GPDCurve3DPtr;						//указатель на базовую кривую 3D
        typedef Gepard::Curves::GPDCurve3D& GPDCurve3DRef;						//ссылка на базовую кривую 3D
        typedef Gepard::General::basicArray<GPDCurve3DPtr> GPDCurve3DPtrArray;  //Массив указателей на кривые 3D. НЕ ЗАБУДЬ УДАЛИТЬ! (Если надо).
        typedef Gepard::General::basicList<GPDCurve3DPtr>  GPDCurve3DPtrList;   //Список указателей на кривые 3D. НЕ ЗАБУДЬ УДАЛИТЬ! (Если надо).		
    }

}
#endif // !defined(EA_05916F1D_D6E7_43e5_9EE8_82360E9A3782__INCLUDED_)
