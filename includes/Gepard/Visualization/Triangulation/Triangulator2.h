///////////////////////////////////////////////////////////
//  -------------------------------------------------------
//  Triangulator.h
//  Реализация 	Class Triangulator
//  Создана:   	8-апр-2013 16:13:15
//  Автор: 		Freeman
//  -------------------------------------------------------
//	Триангуляция с ограничениями.
//  Стратегия: Удаляй и строй
//  Используется тесселятор OpenGL
//  !!!!!! DEBUG - ВЕРСИЯ !!!!!!
///////////////////////////////////////////////////////////

//#define TRIANGULATION_STEP

#pragma once

#include "../../BasicMath/GPDPoint.h"
#include "../../BasicMath/GPDPoint2d.h"
#include "Tri_MapSector.h"

#include <boost/unordered_map.hpp>

namespace Gepard 
{
    namespace Topology_Geometry { class GPDFace; }

    namespace Visualization 
    {
        namespace Triangulation 
        {
           
            /**
             *  Класс триангуляции с ограничениями
             */
            class Triangulator2
            {

            public:

                Triangulator2();
                ~Triangulator2();

                /**
                 *  Запуск функции триангуляции
                 *  Возврат - число созданных треугольников
                 *  - 1 - в случае ошибки
                 */
                int Triangulate( Topology_Geometry::GPDFace* _parentFace,
                                 Tri_MapSector* _mapSector               );

            private:

//#ifdef MAP_TRIANGULATION_TEST
            public:
//#endif

                /**
                 *  Указатель на родительскую грань
                 */
                Topology_Geometry::GPDFace* parentFacePtr;

                /**
                 *  Указатель на сектор карты
                 */
                Tri_MapSector* mapSectorPtr;


                ///расчетные данные              

                /**
                 *  Массив треугольников 2D - удаляется после расчета триангуляции
                 */
                basicList<Triangle2D> triangles2D;                

                /**
                 *  Крайние точки сегмента - в 3D
                 */
                GPDPointPtr QPoints3D[4];

                /**
                 *  Крайние точки сегмента - в 3D
                 */
                GPDPoint2d  QPoints2D[4];

                /**
                 *  Список индексов существуюших треугольников 2D
                 */
                basicList<unsigned int> tri2d_exist_list;

                /**
                 *  Индексный массив треугольников 2D
                 */
                basicArray<basicList<Triangle2D>::_ITERATOR> tri_2d_indexes;

                /**
                 *  Индексный массив треугольников 3D
                 */
                //basicArray<basicList<Triangle3D>::_ITERATOR> tri_3d_indexes;

                /**
                 *  Хэш-таблица соответствия 2D-точек 3D-точкам (ТОЛЬКО крайние точки сектора)
                 */
                boost::unordered_map<GPDPoint2dPtr,GPDPointPtr> Qpoints_hash_table;                

                /**
                 *  Добавляет ребра в отсортированный список
                 *  cP(0-1) - точки контура (ребро контура)
                 *  eP(0-1) - точки ребра треугольника, которое нужно добавить
                 */
                void AddEdgeToList( GPDPoint2dPtr cP0, GPDPoint2dPtr cP1, 
                                    GPDPoint2dPtr eP0, GPDPoint2dPtr eP1,
                                    std::list<Tri_Edge> &left_edges,
                                    std::list<Tri_Edge> &right_edges );

                /**
                 *  Триангуляция списка ребер - формирует треугольники замкнутого контура
                 *  cP0 - начальная точка контура
                 */
#ifdef TRIANGULATION_STEP
                void TriEdgeList(std::list<Tri_Edge> &Edge_List, GPDPoint2dPtr cP0, GPDPoint2dPtr cP1, bool isLeft);
#else                
                void TriEdgeList(std::list<Tri_Edge> &Edge_List, GPDPoint2dPtr cP0, GPDPoint2dPtr cP1);
#endif

                /**
                 *  Добавить треугольник 2D к текущему mapSector
                 *  Возврат: номер добавленного треугольника в массиве
                 */
                unsigned int AddTriangle2D( Gepard::BasicMath::GPDPoint2dPtr P0,
                                            Gepard::BasicMath::GPDPoint2dPtr P1,
                                            Gepard::BasicMath::GPDPoint2dPtr P2 );

                /**
                 *  Добавить треугольник 3D к текущему mapSector
                 */
                void AddTriangle3D( Gepard::BasicMath::GPDPointPtr P0,
                                    Gepard::BasicMath::GPDPointPtr P1,
                                    Gepard::BasicMath::GPDPointPtr P2 );

public:                             
                /**
                 *  Функция локализации точки. 
                 *  На входе:  1) Указатель на точку для локализации
                 *             2) Триангуляция (искать точку только в ней)
                 *  На выходе:  false - не нужно добавлять точку
                 *  Массив индексов треугольников (макс 2):
                 *              1) пустой массив    - точку не надо добавлять в триангуляцию
                 *              2) один тр.-к       - точка находится внутри него
                 *              3) два тр.-ка       - точка находится на ребре
                 *              4) два тр.-ка, но второй = -1 - точка находится на ребре суперструктуры
                 *  Массив номеров ребер (макс 2) соотв. треугольников (если точка на ребре)                 
                 *  isDangling - висячая точка
                 */
                bool LocalizePoint( Gepard::BasicMath::GPDPoint2dPtr p, 
                                    std::vector<int> &triangles, 
                                    std::vector<int> &edges, bool isDangling = false,
                                    basicList<unsigned int> *triangulation = nullptr );

                /**
                 *  Заменяет заданный треугольник (tri_num) новыми - tri_num_list
                 */
                void ReplaceTriangle(   unsigned int tri_num, 
                                        unsigned int (&tri_num_list)[3], 
                                        unsigned int count_tri_list );

                 /**
                 *  Функция добавляет заданную точку к триангуляции
                 *  Если задан массив triangulation - то точка будет добавлена только в данную триангуляцию,
                 *  Иначе - в триангуляцию tri2d_exist_list
                 *  isDangling - висячая точка
                 */
                void AddPointToTriangulation( Gepard::BasicMath::GPDPoint2dPtr p, bool isDangling = false,
                                              basicList<unsigned int> *triangulation = nullptr );


                 /**
                 *  Функция вставляет заданное ребро (eP1,eP2) в заданную триангуляцию
                 *  Если триангуляция не задана - используется tri2d_exist_list
                 */
                void InsertEdgeToTriangulation( Gepard::BasicMath::GPDPoint2dPtr eP1,
                                                Gepard::BasicMath::GPDPoint2dPtr eP2,
                                                basicList<unsigned int> *triangulation = nullptr );

                /**
                 *  Функция создает замкнутый контур (Closed_Contour) из набора ребер (cP0-cP1 - Edge_List),
                 *  а также выдает массив "висячих" ребер (Dangling_Edges).
                 */
                void PrepareContour( GPDPoint2dPtr cP0, GPDPoint2dPtr cP1,
                                     std::list<Tri_Edge> &Edge_List, 
                                     std::vector<GPDPoint2dPtr> &Closed_Contour, 
                                     std::list<Tri_Edge> &Dangling_Edges );
                
                /**
                 *	Поиск ребер, содержащих данную точку
                 */
                void FindEdgesByPoint( std::list<Tri_Edge> &all_edges, GPDPoint2dPtr _p, 
                                       std::list<std::pair<Tri_Edge,edges_iterator>> &p_edges);

                /**
                 *	Рекурсивная функция поиска замкнутого контура из набора ребер
                 */
                bool RecursePrepareContour( GPDPoint2dPtr ep0, GPDPoint2dPtr ep1, 
                                            std::list<Tri_Edge> &cur_edges,
                                            std::list<Tri_Edge> &all_edges,
                                            std::list<Tri_Edge> &dangling_edges );
                /**
                 *  Функция заполняет массив треугольников в 3D, используя расчетные данные и хэш-таблицу
                 */
                int FillTriangles3D();

                /**
                 *  Функция, используя указатель на parentFace, проверяем треугольники на 
                 *  видимость относительно контуров грани. Оставляет только видимые
                 */
                bool isTriangleVisible(Triangle2D &tri);

                /**
                 *  Функция очищает временные данные из массива
                 */
                void ClearTempData();

#ifdef TRIANGULATION_STEP
///->>>>>>>>>>>>>>>>>>> ДЛЯ ТЕСТОВ!!!!

                void Triangulation_Init( Topology_Geometry::GPDFace* _parentFace, Tri_MapSector* _mapSector );      //Инициализация

                bool Triangulate_Stage1_Step(  ); //Шаг этапа №1 (вставка точек), true - этап окончен

                bool Triangulate_Stage2_Step(  ); //Шаг этапа №2 (вставка ребер) (true - триангуляция окончена)

                Tri_Contour2D *_contour2DPtr;
                Tri_Contour2D::_ITERATOR _p_itr;

                int getNextEdgePoint(GPDPoint2d* &_oldP, GPDPoint2d* &_curP);

                Gepard::General::basicList<Gepard::BasicMath::GPDPoint2d> _left_Contour;
                Gepard::General::basicList<Gepard::BasicMath::GPDPoint2d> _right_Contour;
                basicList<Triangle2D> _gen_triangles2D;
                basicList<Triangle2D> _cross_triangles2D;
                Gepard::BasicMath::GPDPoint2d _edgeP0, _edgeP1;
                basicList<Tri_Edge> _dangling_Edges; //массив висячих ребер
///->>>>>>>>>>>>>>>>>>> ДЛЯ ТЕСТОВ!!!!
#endif

            };


        } // Triangulation
    }// Visualisation
}// Gepard