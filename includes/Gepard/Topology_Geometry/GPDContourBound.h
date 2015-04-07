///////////////////////////////////////////////////////////
//  GPDContourBound.h
//  Реализация Class GPDContourBound
//  Создано:      30-янв-2013 21:06:05
//  Автор: Dr_Freeman
///////////////////////////////////////////////////////////

#if !defined(GPD_0746DBE7_61A8_4045_90E1_2E79E648461D__INCLUDED_)
#define GPD_0746DBE7_61A8_4045_90E1_2E79E648461D__INCLUDED_

#include "FACE_BOUND_TYPE.h"
#include "../BasicMath/GPDPoint2dn.h"
#include "../General/basicList.h"
#include "../General/basicArray.h"
#include "../Curves/GPDCurve3D.h"
#include "../Visualization/Triangulation/Tri_MapSector.h"

#include <BOOST/unordered_map.hpp>
#include <functional>
#include <set>

namespace Gepard
{
    namespace Topology_Geometry
    {
        using namespace Gepard::BasicMath;
        using namespace Gepard::Visualization::Triangulation;
        using namespace Gepard::General;
        using namespace Gepard::Curves;

//TODO: Реализовать динамическое кэширование по аналогии с триангуляцией

        class GPDFaceBound;
        /**
         *	Кривая (2D), содержащая список точек(2D) с нормалями
         */
        // НЕ ПЛОДИ СУЩНОСТЕЙ, СЦУКА! (c) Оккам с его бритвой
        //typedef Gepard::General::basicList<Gepard::BasicMath::GPDPoint2dn> GPDCurve2D_l;

        /**
         * Массив кривых 2D
         */
        typedef basicArray<GPDPoint2dnList> ContourCurve2DArray;

        /**
         *  Индекс точки в ребре в контура (№контура, индекс точки)
         */
        typedef std::pair<unsigned int, unsigned int> PointEdgeIndex;

        /**
         *	Функция обработки ребер
         */
        typedef std::function<void( GPDPoint2dnList::_ITERATOR&, GPDPoint2dnList::_ITERATOR&, GPDPoint2dnList*&,
                                    GPDPointArray::_ITERATOR&, GPDPointArray::_ITERATOR&, GPDCurve3DPtr &)> edges_function;

        /**
         * Граница на карте
         */
        class GPDContourBound
        {

        public:
            GPDContourBound();
            ~GPDContourBound();

            /**
             *	Массив кривых 2D, составляюших контур на карте
             */
            ContourCurve2DArray Edges2D;

            /**
             *  Хэш-таблица связывает указатель на точку с парой (№контура, индекс точки)
             */
            boost::unordered_map<GPDPoint2dPtr, PointEdgeIndex> P2Edges2D_Hash;

            /**
             *	Тип контура (внутренний/внешний)
             */
            //FACE_BOUND_TYPE BoundType;

            /**
             *  Функция инициализации контура, резервируется место для контуров
             */
            void Initialize( GPDFaceBound *faceBoundPtr );

            /**
             *	Определение, лежит ли точка внутри действительного контура			 
             *  Функция работает с дискретным контуром (не точно)
             *  [out] c_length - расстояние до ближайшего контура (до ОТРЕЗКА контура)
             *  [ret] true - точка недействительная
             */
            bool CheckPointDiscrete( GPDPoint2dn *P, double &c_length );

            /**
             *	Определение, лежит ли точка внутри действительного контура			 
             *  Функция работает с просчетом контура (точно)
             *  [ret] true - точка недействительная
             */
            //bool CheckPoint(Gepard::BasicMath::GPDPoint2dRef P, int BoundCurveIndex = -1, int PointIndex = -1);


            /**
             *  Функция добавляет вычисленную 2Д кривую к массиву контуров 
             *  и вычисляет на ней нормали (2Д)
             */
            void addContour(GPDPoint2dnList &curve2DRef, bool isClosed, bool isStaticAdd = true);

            /**
             *  Установить указатель на родительскую границу
             */
            void SetParentFaceBound(GPDFaceBound* faceBoundPtr);           

            /**
             *  Обновить хэш-таблицу привязки точек к индексам
             */
            void UpdatePoints2EdgesHash();

            /**
             *  Вычисляет точки пересечения контуров, заменяет начальные и конечные точки у кривых (3D)
             *  И запускает функцию пересчета геометрии
             */
            void CutContoursAndRecalcGeometry();

        private:
            /**
             * Родительская граница грани (3D)
             */
             GPDFaceBound* parentFaceBound;

            /**
             *	Накрывающий многоугольник
             */			
            GPDPoint2dArray Covering_Polygon;
            
             /**
             *	Поиск ближайшей точки на границе
             *  Входное значение: P - 2Д точка, для которой нужно найти ближайшую на контуре
             *  except_curve - искать везде, кроме этого контура
             *  Возвращаемые значения:
             *  [ret] Квадрат длины до контура
             *  [out] BoundCurveIndex - индекс ближайшей кривой
             *  [out] PointIterator  - итератор точки на этой кривой
             */
            double FindClosestPointOnBound( GPDPoint2dRef P, int &BoundCurveIndex, 
                                            GPDPoint2dnList::_ITERATOR &PointIterator,
                                            GPDPoint2dnList *except_curve = nullptr);

            /**
             *	Поиск ближайшего расстояния к накрывающему многоугольнику
             */
            double FindClosestDistanceToPolygon( GPDPoint2dRef P );

            /**
             *	Функция расчитывает накрывающий многоугольник для контура
             */
            void CalcCoveringPolygon();

            /**
             *  Вычисляет нормали на заданном контуре 2Д и корректирует точки контура относительно границ
             */
            void CalcNormals(GPDPoint2dnList &curve2DRef, bool isClosed, int numContour = -1);

            /**
             *  Корректировка координат контура по нормалям - в случае, если контур попадает на границу поверхности
             */
            void CorrectContourAtMapLimit(GPDPoint2dnList &curve2DRef);

            /**
             *	Вычмсляет накрывющий прямоугольник для контура, 
             *	координаты точек записываются в rect_points
             */
            void CalcContourRect(GPDPoint2dn (&rect_points)[4]);
            /**
             *  Вычисляет нормирующий коэффициент lambda
             *	И затем коэффициенты для линии - A,B,C
             */
            void CalcLineEquLambda(  GPDPoint2dn *A, GPDPoint2dn *B, 
                                     double &LE_A, double &LE_B, double &LE_C, 
                                     bool isDivToLambda = true);
            /**
             *	Находит на контуре точку, максимально отклоняющуюся от промежуточной линии 
             *  (при вычислении накрываюшего многоугольника)
             */
            bool FindMaxDeviationPoint(GPDPoint2d &P, int &bound_num, int &point_num);

            /**
             *	Поиск точки отклонения для заданных коэффициентов прямой
             */
            void FindDeviationPoint(	GPDPoint2dn *LA, GPDPoint2dn *LB,
                                        double A, double B, double C, 
                                        double deviation, 
                                        GPDPoint2dn &P );
            /**
             *  Функция определяет, был ли переход через границу между значениями val0 и val1
             */
            inline bool isCrossMapLimit( double val0, double val1, int* map_limit_index=(int*)0, double val_limit=1 );            
           
            /**
             *  Обновить хэш-таблицу связи указателей на точки с номером контура
             */
            void UpdatePoints2EdgesHash(GPDPoint2dnList *curve2DPtr, unsigned int eIndex);

            /**
             *	 Обработка всех ребер всех контуров кроме указанных
             */
            void ProcessEdges( edges_function &funcRef, bool isUpdateExcept = false,                               
                               std::set<GPDPoint2dnList*> *only_curves = nullptr,
                               std::set<GPDPoint2dnList*> *except_curves = nullptr);

        public:
            /**
             *	Проверяет, находится ли точка внутри накрывающего многоугольника
             */
            bool CheckIfPointInCoveringPolygon( GPDPoint2dnRef P );

            /**
             *  Алгоритм предтриангуляции - получает сектора с массивом точек (Tri_MapSector)
             */            
            void PreTriangulate(basicList<Tri_MapSector> *tri_mapSectorsPtr);

        private:
            /**
             *  Функция получает границы карты с геометрического носителя
             */
            void GetMapLimits();
            
            /**
             *  Функция проверяет, все ли необходимые указатели есть
             */
            bool CheckIfError();

            /**
             *  Вычисление номера сегмента по координатам точки
             */
            int CalcSegNum( double U, double V );

            /**
             *  Функция добавляет очередную точку к сегменту(сектору)
             *  Если P0 и P1 - заданы, это точка пересечения
             */
            void AddPointToSegment( basicList<Tri_MapSector> *tri_mapSectorsPtr,
                                    GPDPoint2dPtr P, 
                                    unsigned int numSector, 
                                    GPDPoint2dPtr P0 = nullptr,
                                    GPDPoint2dPtr P1 = nullptr);


            /**
             *  Функция вычисляет точку пересечения с сегментом (3D) 
             *  по двумерной точке пересечения на карте
             */
            Gepard::BasicMath::GPDPoint CalcIntersectPoint3D(unsigned int numSector, GPDPoint2dPtr P);

            /**
             *  Функция вычисляет точку пересечения с сегментом (3D) 
             *  по двумерной точке пересечения на карте и соседним точкам контура
             *  P - точка пересечения 2D; P0,P1 - соседи на контуре
             */
            Gepard::BasicMath::GPDPoint CalcIntersectPoint3D_Contour( unsigned int numSector, 
                                                                      GPDPoint2dPtr P,
                                                                      GPDPoint2dPtr P0,
                                                                      GPDPoint2dPtr P1);

            /**
             *	Вычисляет соответствующую точку (3D) по заданным точкам на карте (A, B), 
             *  и точке (2D) "пересечения", лежащей между AB
             */
            Gepard::BasicMath::GPDPoint CalcIntersectByPoints( GPDPoint2dPtr A, GPDPoint2dPtr B, GPDPoint2dPtr intersect2d, 
                                                               GPDPointPtr P0, GPDPointPtr P1 );


            /**
             * Ограничения карты
             */
            double U0, U1, V0, V1;

            /**
             *  Количество рассчитанных точек на карте
             */
            unsigned int NumU, NumV;           

            /**
             *  Указатель на хэш-таблицу, связывающую номер сегмента карты с указателем на сегмент 
             *  (из массива GPDFace->tri_MapSectorList)
             */
            boost::unordered_map<unsigned int,Tri_MapSector*> *MapSectors_hash_ptr;
                        
            /**
             *  Контур на карте - отсортированный двусвязный список ребер
             */
            std::list<GPDPoint2dPtr> BoundContour2D;

            /**
             *  Хэш-таблица связывает указатель на точку с итератором на контур карты BoundContour2D
             *  - Для поиска соседей точки (контур всегда замкнут)
             */
            boost::unordered_map< GPDPoint2dPtr,
                                  std::list<GPDPoint2dPtr>::iterator > Neighbours_hash;


            /**
             *  Создает замкнутый контур из соседних ребер
             */
            void UpdateBoundContour2DList();

            /**
             *  Функция находит соседей указанного итератора на точку
             *  и возвращает два итератора на список BoundContour2D             
             */
            void FindPointNeighbours( std::list<GPDPoint2dPtr>::iterator cur_itr,
                                      std::list<GPDPoint2dPtr>::iterator &prev_itr, 
                                      std::list<GPDPoint2dPtr>::iterator &next_itr);

            /**
             *  Функция удаляет лишние точки в контурах секторов (точки, лежащие на одной прямой)
             */
            void DeleteSparePoints(basicList<Tri_MapSector> *tri_mapSectorsPtr);

            /**
             *  Удалить временные данные
             */
            void ClearTempData();

        };

    }

}
#endif // !defined(GPD_0746DBE7_61A8_4045_90E1_2E79E648461D__INCLUDED_)
