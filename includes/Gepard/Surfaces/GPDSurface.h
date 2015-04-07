///////////////////////////////////////////////////////////
//  GPDSurface.h
//  Реализация	Class GPDSurface
//  Создано:    15-ноя-2012 17:35:18
//  Автор:		Dr_Freeman
///////////////////////////////////////////////////////////

#if !defined(EA_42BBD7AE_96C2_48b4_B2C9_2F1A73FFEBF5__INCLUDED_)
#define EA_42BBD7AE_96C2_48b4_B2C9_2F1A73FFEBF5__INCLUDED_

#include "SURFACE_TYPES.h"
#include "../General/basicArray.h"
#include "../General/basicList.h"
#include "../BasicMath/GPDReper.h"
#include "../BasicMath/additionalFuncs.h"
#include "../BasicMath/basicFuncs.h"
#include "../Curves/GPDCurve3D.h"
#include "QuadMap.h"


namespace Gepard
{
    namespace Topology_Geometry { class GPDFace; };

    namespace Surfaces
    {
        class GPDPlaneSurface;
        class GPDCylindricalSurface;
        class GPDConicalSurface;
        class GPDToroidalSurface;
        class GPDSphericalSurface;
        class GPDBSplineWithKnotsSurface;
        class GPDBSplineSurface;
        class GPDNURBSSurface;

        /**
         * Виртуальный класс поверхности.
         * Карта поверхности всегда от 0 до 1 в оба направления.
         */
        class GPDSurface : public QuadMap
        {

        public:

            /**
             * репер точек - нужен для быстрой глобализации точек (pointreper - это глобальный
             * repervariat)
             */
            Gepard::BasicMath::GPDReper point_reper;
         
            /**
             * Массив векторов касательных по U
             */
            Gepard::BasicMath::GPDVectorArray VectorsTangentU;

            /**
             * Массив векторов касательных по V
             */
            Gepard::BasicMath::GPDVectorArray VectorsTangentV;

            /**
             * Массив точек поверхности в глобальных координатах.
             */
            Gepard::BasicMath::GPDPointArray Points;

            /**
             * Массив соседних поверхностей
             * Заполняется при импорте из STEP или при моделировании
             */
            std::vector<unsigned int> NearSurfaces;
            
            /** 
             *  Указатель на родительскую грань
             */
            Gepard::Topology_Geometry::GPDFace* parentFace;


            GPDSurface();
            virtual ~GPDSurface();

            /**
             * Создать поверхность с указанными параметрами точности
             */            
            virtual void CalcSurface(unsigned int _numU = 0, unsigned int _numV = 0, double _stepU = 0, double _stepV = 0);

             /**
             *	Посчитать поверхность в заданном сегменте параметрической плоскости
             */
            void calc_surface( double u0, double v0, double u1, double v1, 
                               unsigned int _numU, unsigned int _numV );

            /**
             *	Посчитать поверхность в заданном сегменте параметрической плоскости
             */
            virtual void CalcSurface(double u0, double v0, double u1, double v1, 
                                     unsigned int _numU, unsigned int _numV,
                                     Gepard::BasicMath::GPDPointArray &_PointArray);

            /**
             *	Расчет 2Д точки на карте по ее 3Д координатам
             */
            virtual void CalcMapPoint(  Gepard::BasicMath::GPDPointRef P3D, 
                                        Gepard::BasicMath::GPDPoint2dRef p2d );

            /**
             *  Расчет 3Д точки поверхности по ее 2Д координате
             */
            virtual void CalcSurfacePoint( Gepard::BasicMath::GPDPoint2dRef p2d,
                                           Gepard::BasicMath::GPDPointRef P3D );

            /**
             *  Расчет 2Д контура на карте по 3Д кривой
             */
            virtual void CalcMapContour( Gepard::Curves::GPDCurve3DPtr curve3DPtr,
                                         Gepard::General::basicList<Gepard::BasicMath::GPDPoint2dn> &curve2DRef);
            
            /**
             *  Расчет нормалей для границы на поверхности (3D)
             */
            virtual void CalcContourNormals( Gepard::Curves::GPDCurve3DPtr curve3DPtr );

            /**
             *  Действия после расчета поверхности
             */
            virtual void ProcessAfterCalcSurface();

            /**
             *  Корректировка номрали (внутрь/наружу)
             */
            void CorrectNormal(Gepard::BasicMath::GPDPointRef P3D);

            /**
             * Установить точность поверхности
             */
            void setSurfacePrecision(unsigned int _numU, unsigned int _numV, double _stepU=0, double _stepV=0);

            /**
             * Получить репер p_rep; R - координаты точки (u_index, v_index), E1 - касательная
             * по U, E2 - касательная по V, E3 - нормаль
             */
            void getP(int u_index, int v_index, Gepard::BasicMath::GPDReperRef p_rep);

            /**
             * Задать точку на поверхности: R - координаты точки (u_index, v_index), E1 -
             * касательный вектор по U, E2 - касательный вектор по V, E3 - нормаль
             */
            void setP(int u_index, int v_index, Gepard::BasicMath::GPDReperRef p_rep);
                     

            /**
             *  Получить 4 точки сегмента поверхности по его порядковому номеру
             */
            void getSegmentPoints( unsigned int seg_num, 
                                   Gepard::BasicMath::GPDPointPtr (&seg_points3D)[4],
                                   Gepard::BasicMath::GPDPoint2d  (&seg_points2D)[4] );

            /**
             *  Получить 4 точки(3D) сегмента поверхности по его порядковому номеру
             */
            void getSegmentPoints3D( unsigned int seg_num, 
                                     Gepard::BasicMath::GPDPointPtr (&seg_points3D)[4] );
            /**
             *  Получить 4 точки(3D) сегмента поверхности по его координатам
             */
            void getSegmentPoints3D( unsigned int U_index, unsigned int V_index, 
                                     Gepard::BasicMath::GPDPointPtr (&seg_points3D)[4] );

            /**
             *  Рассчитать координаты точек на карте по номеру сектора
             */
            void calcSegmentPoints2D( unsigned int seg_num, 
                                     Gepard::BasicMath::GPDPoint2d  (&seg_points2D)[4] );


            /**
             *  Рассчитать координаты точек на карте по координатам сектора
             */
            void calcSegmentPoints2D( unsigned int U_index, unsigned int V_index,
                                      Gepard::BasicMath::GPDPoint2d  (&seg_points2D)[4] ) ;
            

            /**
             *	Глобализация точки - перевод из локальной системы координат (variation_reper)
             *  в глобальную систему координат (GlobalReper)
             */
            void GlobalizePoint(Gepard::BasicMath::GPDPoint &P);

            /**
             *  Получить тип поверхности
             */
            Gepard::Surfaces::SURFACE_TYPES GetSurfaceType() const;

            /**
             *  Получить тип поверхности
             */
            int GetSurfaceTypeNum();

            /**
             *  Получить параметры карты поверхности
             */
            QuadMap GetSurfaceMap();             

            /**
             *  Преобразовать точки в локальную систему координат
             *  (т.е. в систему координат репера point_reper)
             */
            void ConvertToLocalBasis();

            /**
             *  Преобразовать точки в глобальную систему координат
             *  (т.е. из системы координат репера point_reper в global)
             */
            void ConvertToGlobalBasis();

            /**
             * Преобразовать в плоскую поверхность
             */
            GPDPlaneSurface* toPlane();

            /**
             * Преобразовать в цилиндрическую поверхность
             */
            GPDCylindricalSurface* toCylindrical();

            /**
             * Преобразовать в коническую поверхность
             */
            GPDConicalSurface* toConical();

            /**
             * Преобразовать в тороидальную поверхность
             */
            GPDToroidalSurface* toToroidal();
            
            /**
             * Преобразовать в сферическую поверхность
             */
            GPDSphericalSurface* toSpherical();
                      
            /**
             *	Преобразовать в NURBS поверхность
             */
            GPDNURBSSurface* toNURBS();
                       
            /**
             *  Изменить координаты точек по заданной функции (GPDPoint2d, GPDPoint &P)
             */
            void ModifyPoints(Gepard::BasicMath::TModifyPointsFunc &funcRef);

            /**
             *  Установить текущей поверхности эквивалентные параметры поверхности fromSurfPtr
             */
            virtual void SetEquivalentParamsFrom(Gepard::Surfaces::GPDSurface* fromSurfPtr);

            /**
             * сохранение в файл
             */
            virtual void saveToFile(std::ostream& os);

            /**
             * чтение из файла
             */
            virtual void readFromFile(std::istream& _is);

            /**
             *	Получить ограничивающий параллелепипед
             */
            Gepard::BasicMath::BoundingBox GetBoundingBox();

        private:
           
            /**
             *	Установка параметров поверхности по умолчанию
             */
            virtual void setDefaultParameters();

            /**
             *  Преобразует точки из системы координат oldReper
             *  в систему координат newReper
             */
            void ConvertToBasis(Gepard::BasicMath::GPDReper& oldReper,
                                Gepard::BasicMath::GPDReper& newReper );

        protected:
            /**
             * Тип поверхности
             */
            Gepard::Surfaces::SURFACE_TYPES TYPE;
            
            /**
             *  Функция подгоняет значения координат точек "почти равных" 0 и 1
             */
            void CorrectCoordsAtLimit(Gepard::BasicMath::GPDPoint2dPtr P);

            /**
             *	Накрывающий параллелепипед поверхности
             */
            Gepard::BasicMath::BoundingBox boundingBox;
        };

        typedef Gepard::Surfaces::GPDSurface& GPDSurfaceRef;
        typedef Gepard::Surfaces::GPDSurface* GPDSurfacePtr;
        typedef Gepard::General::basicArray<GPDSurfacePtr> GPDSurfacePtrArray;
        typedef Gepard::General::basicList<GPDSurfacePtr> GPDSurfacePtrList;
        
        typedef Gepard::General::basicArray<GPDSurface> GPDSurfaceArray;
        typedef Gepard::General::basicList<GPDSurface> GPDSurfaceList;
    }

}
#endif // !defined(EA_42BBD7AE_96C2_48b4_B2C9_2F1A73FFEBF5__INCLUDED_)
