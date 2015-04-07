///////////////////////////////////////////////////////////
//  GPDFaceBound.h
//  Реализация Class GPDFaceBound
//  Создано:   15-ноя-2012 16:38:04
//  Автор:     Dr_Freeman
///////////////////////////////////////////////////////////

#if !defined(EA_0239A580_C7EE_4bc2_8D0A_AC94D7D8B71F__INCLUDED_)
#define EA_0239A580_C7EE_4bc2_8D0A_AC94D7D8B71F__INCLUDED_

#include "FACE_BOUND_TYPE.h"
#include "../BasicMath/GPDPoint.h"
#include "../BasicMath/GPDVector.h"
#include "../Curves/GPDCurve3D.h"
#include "../General/basicArray.h"
#include "../BasicMath/basicFuncs.h"
#include "../Topology_Geometry/GPDContourBound.h"

#include <boost/unordered_set.hpp>

namespace Gepard
{
    namespace Topology_Geometry
    {
        using namespace Gepard::Curves;
        using namespace Gepard::BasicMath;

        class GPDFace;
        /**
         * Граница грани - представляет собой массив ребер(кривых), ограничивающих поверхность.
         */
        class GPDFaceBound
        {
        public:
            /**`
             *	Конструктор по-умолчанию
             */
            GPDFaceBound( GPDFace* parent_face=0, 
                          FACE_BOUND_TYPE boundType=FBT_OUTER_BOUND );
                        
            /**
             *	Создать 
             */
            virtual ~GPDFaceBound();
            
            /**
             * Тип границы
             */
            FACE_BOUND_TYPE bound_type;
            /**
             * Массив ребер - кривых (edges_loop)
             */
            GPDCurve3DPtrArray edges;

            /**
             *	Массив ребер на карте поверхности (2D-контур)
             */            
            GPDContourBound contourBound;
            /**
             *	Указатель на родительскую грань
             */
            GPDFace* parentFace;

            /**
             *  Точка петли - иногда задается в качестве ограничения поверхности
             */
            GPDPoint loop_vertex;

            /**
             *  Флаг - есть ли loopVertex
             */
            bool isLoopVertex;

            /**
             * Получить ребро.
             */
            GPDCurve3DPtr operator[](unsigned int i);

            /**
             * Добавить ребро к границе
             */
            void addEdge(GPDCurve3DPtr _edge, bool _edge_orient=true);

            /**
             *	Установка флага удаления геометрии ребер
             */
            void setDeleteEdgesGeometryFlag(bool isDelGeom);

            /**
             *	Расчет массива 2Д точек на карте по массиву 3Д точек на карте
             */
            void CalcMapContour(bool isSecondPass = false);

            /**
             *  Расчет нормалей 3Д точек кривых, составлящих контуры
             */
            void CalcBoundNormals();

            /**
             *  Создать 3D-кривую по типу
             */
            static GPDCurve3DPtr createCurve(CURVE_3D_TYPE curve_type);

            /**
             *  Шаблонная функция - создать 3D-кривую по типу
             */
            template <class T>
            static GPDCurve3DPtr CreateCurve();

            /**
             *  Функция запускает расчет ребер (геометр. носителя ребер)             
             */
            void CalcFaceBoundGeometry();

            /**
             *  Получить ограничения грани в 3D по указанным векторам относительно точки
             *  Возаращаемый массив - длины по векторам: U = [1] - [0], V = [3] - [2],
             *  где U - длина относительно первого вектора, V - второго
             */
            void CalcAxesLimit( GPDPointRef O, 
                                GPDVectorRef axisU,
                                GPDVectorRef axisV,
                                double (&lenUV)[4] );

            /**
             *  Функция предтриангуляции - записывает данные в parentFace -> tri_MapSectorList
             *  (Подготовка данных для триангуляции)
             */
            void PreTriangulate();

             /**
             *  Установить номер границы грани
             */
            void SetBoundNum( unsigned int _boundNum ) {BoundNum = _boundNum;}

             /**
             *  Получить номер границы грани
             */
            unsigned int GetBoundNum() { return BoundNum; }
            
            /**
             *  Получить идентификатор типа bound
             */
            int GetBoundTypeId();

            /**
             *  Функция копирует текущую границу и добавляет ее к заданной грани
             */
            void CopyFaceBound( GPDFace* facePtr );

            /**
             *  Преобразует точки ребер из системы координат oldReper в систему координат newReper
             */
            void ConvertToBasis( GPDReper &oldReper, 
                                 GPDReper &newReper);

            /**
             *  Получить параметр совпадения топологиориентации ребра с геометрическим
             */
            bool GetEdgeOrientation(int eIndex);

            /**
             *  Установить текущей границе эквивалентные параметры границы boundPtr
             */
            void SetEquivalentParamsFrom(GPDFaceBound* boundPtr);

            /**
             *	Получить накрывающий параллелепипед
             */
            BoundingBox GetBoundingBox();

            /**
             *	Поиск ребер-перемычек
             */
            void FindBridgeEdges();

            /**
             *	Является ли данное ребро перемычкой
             */
            bool isBridge(Gepard::Curves::GPDCurve3DPtr c3d);


            //перегруженный оператор вывода
            friend ostream& GPDFaceBound::operator<<(ostream& os, GPDFaceBound &bound)
            {	
                //получаем и записываем тип границы                                
                os.write((char *) &bound.bound_type, sizeof bound.bound_type);
                os.write((char *) &bound.BoundNum, sizeof bound.BoundNum);
				
                os.write((char*)&bound.loop_vertex, sizeof (Gepard::BasicMath::GPDPoint));
                os.write((char*)&bound.isLoopVertex, sizeof(bool));
				
                unsigned int _edge_count = bound.edges.getCount();
                os.write((char *) &_edge_count,sizeof _edge_count);

                bound.edges.set_start();                
                while(auto edgePtr = bound.edges.get_next())
                {   
                    int curveType = (int)(*edgePtr)->getCurveType();
                    os.write((char *) &curveType, sizeof curveType);

                    (*edgePtr)->saveToFile(os);

                    bool _to = bound.edge_Orientation[bound.edges.get_current_index()];                    
                    os.write((char *) &_to,sizeof (bool));                    
                }//while edge
                                                
                return os;
            }//end of <<

            //перегруженный оператор ввода
            friend istream& operator>>(istream& is, GPDFaceBound &face_bound)
            {
                //считываем тип границы                 
                is.read((char *) &face_bound.bound_type, sizeof face_bound.bound_type);
                is.read((char *) &face_bound.BoundNum, sizeof face_bound.BoundNum);
              
                is.read((char*)&face_bound.loop_vertex, sizeof (Gepard::BasicMath::GPDPoint));
                is.read((char*)&face_bound.isLoopVertex, sizeof(bool));

                //Количество граней
                unsigned int _edge_count = 0;
                is.read((char *) &_edge_count, sizeof _edge_count);

                for (unsigned int i=0; i<_edge_count; i++)
                {
                    //Считываем геометричекий тип ребра
                    int _curve_type = 0;
                    is.read((char *) &_curve_type, sizeof _curve_type);

                    //Считываем геометрию ребра
                    Gepard::Curves::GPDCurve3DPtr _curvePtr = \
                        GPDFaceBound::createCurve((Gepard::Curves::CURVE_3D_TYPE)_curve_type);
                    _curvePtr->readFromFile(is);

                    //Считываем orientation
                    bool _orientation;
                    is.read((char *) &_orientation, sizeof _orientation);

                    face_bound.addEdge(_curvePtr, _orientation);                    
                }//for

                return is;
            }


        private:

            /**
             *  Функция копирует данные кривой по типу в заданную кривую
             */
            void CopyCurve3D( GPDCurve3DPtr fromCurve, GPDCurve3DPtr toCurve);

            /**
             *  Шаблонная функция копирует геометрические данные кривой fromCurve в кривую toCurve по типу
             */
            template <class T>
            void SetCurveData( GPDCurve3DPtr fromCurve, GPDCurve3DPtr toCurve);
                     
            /**
             * Совпадение топологической ориентации ребра с геометрическим. Используется для
             * правильного вычисления 2D-нормалей границы.
             */
            std::vector<bool> edge_Orientation;

            /**
             *  Номер границы на данной грани
             */
            unsigned int BoundNum;

            /**
             *	Флаг удаления геометрии ребер
             */
            bool isDeleteEdgesGeometryFlag;

            /**
             *	Накрывающий параллелепипед 
             */
            BoundingBox boundingBox;

            /**
             *	Массив ребер-перемычек
             */
            boost::unordered_set<GPDCurve3DPtr> bridge_edges;


        };
        typedef GPDFaceBound* GPDFaceBoundPtr;
        typedef GPDFaceBound& GPDFaceBoundRef;
        typedef Gepard::General::basicArray<GPDFaceBound> GPDFaceBoundArray;
        typedef Gepard::General::basicArray<GPDFaceBoundPtr> GPDFaceBoundPtrArray;
        typedef Gepard::General::basicList<GPDFaceBound> GPDFaceBoundList;
        typedef Gepard::General::basicList<GPDFaceBoundPtr> GPDFaceBoundPtrList;

    }

}
#endif // !defined(EA_0239A580_C7EE_4bc2_8D0A_AC94D7D8B71F__INCLUDED_)
