///////////////////////////////////////////////////////////
//  GPDNURBSSurface.h
//  Реализация Class GPDNURBSSurface
//  Создано:      03-мар-2015 10:13
//  Автор: Dr_Freeman
///////////////////////////////////////////////////////////

#ifndef GPDNURBSSURFACE_H
#define GPDNURBSSURFACE_H

#include "GPDSurface.h"

namespace Gepard
{
    namespace Surfaces
    {
        using namespace Gepard::BasicMath;

        /**
        *	Структура описывает временные данные для вычисления точек и производных в них
        */
        struct NURBSEvaluationTmpData
        {
            /**
            *	Временный массив для хранения промежуточных значений точек (по j)
            *   Второй элемент массива - для производных
            */
            std::vector<GPDPointArray> points_j_array[2];

            /**
            *	Временный массив для хранения промежуточных значений точек (по i)
            *   Второй элемент массива - для производных
            */
            std::vector<GPDPointArray> points_i_array[2];

            /**
            *  Временный массив для хранения промежуточных значений весов (по j)
            *   Второй элемент массива - для производных
            */
            std::vector<GPDPointArray> weights_j_array[2];

            /**
            *  Временный массив для хранения промежуточных значений весов (по i)
            *   Второй элемент массива - для производных
            */
            std::vector<GPDPointArray> weights_i_array[2];

            /**
            *	Существуют ли данные
            */
            bool isExist;
            NURBSEvaluationTmpData() { isExist = false; }
        };

        /**
         *	Поверхность типа NURBS: (B-spline рациональный и нерациональный)
         */
        class GPDNURBSSurface : public Gepard::Surfaces::GPDSurface
        {
            friend class GPDBSplineWithKnotsSurface;
            friend class GPDRationalBSplineSurface;
            friend class GPDBSplineSurface;                      

        public:
            GPDNURBSSurface();
            GPDNURBSSurface( int order_u, int order_v, bool is_rational,
                             Gepard::BasicMath::GPDPointArray &control_points,
                             const std::vector<double> &u_knots = std::vector<double>(),
                             const std::vector<int> &u_mult = std::vector<int>(),
                             const std::vector<double> &v_knots = std::vector<double>(),
                             const std::vector<int> &v_mult = std::vector<int>(),
                             const std::vector<std::vector<double>> &W = std::vector<std::vector<double>>());

            ~GPDNURBSSurface();

            /**
            *  Установить параметры поверхности
            */
            void setParameters( int order_u, int order_v, bool is_rational, 
                                Gepard::BasicMath::GPDPointArray &control_points,
                                const std::vector<double> &u_knots = std::vector<double>(), 
                                const std::vector<int> &u_mult = std::vector<int>(),
                                const std::vector<double> &v_knots = std::vector<double>(), 
                                const std::vector<int> &v_mult = std::vector<int>(),
                                const std::vector<std::vector<double>> &W = std::vector<std::vector<double>>());

            /**
            * Создать поверхность с указанными параметрами точности
            */
            void CalcSurface(unsigned int _numU = 0, unsigned int _numV = 0, double _stepU = 0, double _stepV = 0)  override;

           /**
            *	Расчет 2Д точки на карте по ее 3Д координатам
            */
            void CalcMapPoint(Gepard::BasicMath::GPDPointRef P3D,
                              Gepard::BasicMath::GPDPoint2dRef p2d) override;

            /**
            *  Расчет 2Д контура на карте по 3Д кривой
            */
            void CalcMapContour(Gepard::Curves::GPDCurve3DPtr curve3DPtr,
                                Gepard::General::basicList<Gepard::BasicMath::GPDPoint2dn> &curve2DRef) override;

            /**
            *  Расчет нормалей для границы на поверхности (3D)
            */
            void CalcContourNormals(Gepard::Curves::GPDCurve3DPtr curve3DPtr) override;

            /**
            *  Расчет 3Д точки поверхности по ее 2Д координате
            */
            void CalcSurfacePoint(Gepard::BasicMath::GPDPoint2dRef p2d,
                                  Gepard::BasicMath::GPDPointRef P3D) override;

            /**
            *  Сохранить поверхность в поток
            */
            void saveToFile(std::ostream& os) override;

            /**
            *  Загрузить поверхность из потока
            */
            void readFromFile(std::istream& _is) override;
          
            /**
             *	Получить число контрольных точек
             */
            unsigned int GetControlPointsCount();

            /**
             *	Получить число узлов по u
             */
            unsigned int GetKnotsUCount();

            /**
            *	Получить число узлов по v
            */
            unsigned int GetKnotsVCount();

            /**
             *	Получить порядок по u
             */
            unsigned int GetOrderUCount();

            /**
             *	Получить порядок по v
             */
            unsigned int GetOrderVCount();

        private:
            /**
            *	Флаг рациональной B-Spline поверхности
            */
            bool isRational;

            /**
            *	Порядок поверхности в направлении U (степеньU +1)
            */
            int Ku;

            /**
            *	Порядок поверхности в направлении V (степеньV +1)
            */
            int Kv;

            /**
            *	Вектор узлов в направлении U
            */
            std::vector<double> Knots_u;

            /**
            *	Вектор узлов в направлении V
            */
            std::vector<double> Knots_v;

            /**
            *	Задающие точки - двумерный массив (UxV)
            */
            Gepard::BasicMath::GPDPointArray Control_points;

            /**
             *	Веса точек в случае рационального B-SPLINE
             */
            std::vector<std::vector<double>> weights;
               
            /**
             *	Временные данные
             */
            NURBSEvaluationTmpData evTmpData;            

            /**
             *	Очистить временные данные
             */
            void ClearTmpData();

            /**
             *  Вычислить временные массивы для быстрого расчета точек
             */
            void CalcTempArrays();

            /**
             *	Подготовить временный массив с производными 
             */
            void PrepareTempDerivativeArrays(int uv, std::vector<GPDPointArray> &dp_array, std::vector<GPDPointArray> &dw_array);


            /**
             *	Посчитать производные в точке и установить нормаль 
             *  (coef - вычислен на предыдущем шаге знаменатель)
             */
            void CalcDerivativesAndNormal( Gepard::BasicMath::GPDPoint2dRef p2d,
                                           Gepard::BasicMath::GPDPointRef P3D, 
                                           int interval_u, int interval_v, double coef );
                       
            /**
            *	Установка параметров поверхности по умолчанию
            */
            void setDefaultParameters() override;                     


            /**
             *	Найти ближайшую точку на поверхности
             */
            double FindClosestPoint3D( Gepard::BasicMath::GPDPointArray &_PointArray, 
                                       Gepard::BasicMath::GPDPoint &P3d, unsigned int &uu, unsigned int &vv );
            /**
            *	Проверка, является ли одна из сторон поверхности - точкой
            */
            void CheckSidesIsPoint();

            /**
            *	Корректировка нормалей точек для случая, когда одна из сторон - точка
            */
            void CorrectNormalOnSideAsPoint();

            /**
             *  Действия после расчета поверхности
             */
            void ProcessAfterCalcSurface() override;
            

            /**
            *	Какая из сторон поверхности ушла в точку
            *  ( 1 - {u:0;v=0-1}; 2 - {u:0-1;v=1};
            *    3 - {u:1;v=1-0}; 4 - {u:1-0;v=0}; )
            */
            std::vector<int> sideIsPoint;
        };
    }
}

#endif