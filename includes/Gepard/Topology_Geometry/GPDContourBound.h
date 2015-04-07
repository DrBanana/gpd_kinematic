///////////////////////////////////////////////////////////
//  GPDContourBound.h
//  ���������� Class GPDContourBound
//  �������:      30-���-2013 21:06:05
//  �����: Dr_Freeman
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

//TODO: ����������� ������������ ����������� �� �������� � �������������

        class GPDFaceBound;
        /**
         *	������ (2D), ���������� ������ �����(2D) � ���������
         */
        // �� ����� ���������, �����! (c) ����� � ��� �������
        //typedef Gepard::General::basicList<Gepard::BasicMath::GPDPoint2dn> GPDCurve2D_l;

        /**
         * ������ ������ 2D
         */
        typedef basicArray<GPDPoint2dnList> ContourCurve2DArray;

        /**
         *  ������ ����� � ����� � ������� (��������, ������ �����)
         */
        typedef std::pair<unsigned int, unsigned int> PointEdgeIndex;

        /**
         *	������� ��������� �����
         */
        typedef std::function<void( GPDPoint2dnList::_ITERATOR&, GPDPoint2dnList::_ITERATOR&, GPDPoint2dnList*&,
                                    GPDPointArray::_ITERATOR&, GPDPointArray::_ITERATOR&, GPDCurve3DPtr &)> edges_function;

        /**
         * ������� �� �����
         */
        class GPDContourBound
        {

        public:
            GPDContourBound();
            ~GPDContourBound();

            /**
             *	������ ������ 2D, ������������ ������ �� �����
             */
            ContourCurve2DArray Edges2D;

            /**
             *  ���-������� ��������� ��������� �� ����� � ����� (��������, ������ �����)
             */
            boost::unordered_map<GPDPoint2dPtr, PointEdgeIndex> P2Edges2D_Hash;

            /**
             *	��� ������� (����������/�������)
             */
            //FACE_BOUND_TYPE BoundType;

            /**
             *  ������� ������������� �������, ������������� ����� ��� ��������
             */
            void Initialize( GPDFaceBound *faceBoundPtr );

            /**
             *	�����������, ����� �� ����� ������ ��������������� �������			 
             *  ������� �������� � ���������� �������� (�� �����)
             *  [out] c_length - ���������� �� ���������� ������� (�� ������� �������)
             *  [ret] true - ����� ����������������
             */
            bool CheckPointDiscrete( GPDPoint2dn *P, double &c_length );

            /**
             *	�����������, ����� �� ����� ������ ��������������� �������			 
             *  ������� �������� � ��������� ������� (�����)
             *  [ret] true - ����� ����������������
             */
            //bool CheckPoint(Gepard::BasicMath::GPDPoint2dRef P, int BoundCurveIndex = -1, int PointIndex = -1);


            /**
             *  ������� ��������� ����������� 2� ������ � ������� �������� 
             *  � ��������� �� ��� ������� (2�)
             */
            void addContour(GPDPoint2dnList &curve2DRef, bool isClosed, bool isStaticAdd = true);

            /**
             *  ���������� ��������� �� ������������ �������
             */
            void SetParentFaceBound(GPDFaceBound* faceBoundPtr);           

            /**
             *  �������� ���-������� �������� ����� � ��������
             */
            void UpdatePoints2EdgesHash();

            /**
             *  ��������� ����� ����������� ��������, �������� ��������� � �������� ����� � ������ (3D)
             *  � ��������� ������� ��������� ���������
             */
            void CutContoursAndRecalcGeometry();

        private:
            /**
             * ������������ ������� ����� (3D)
             */
             GPDFaceBound* parentFaceBound;

            /**
             *	����������� �������������
             */			
            GPDPoint2dArray Covering_Polygon;
            
             /**
             *	����� ��������� ����� �� �������
             *  ������� ��������: P - 2� �����, ��� ������� ����� ����� ��������� �� �������
             *  except_curve - ������ �����, ����� ����� �������
             *  ������������ ��������:
             *  [ret] ������� ����� �� �������
             *  [out] BoundCurveIndex - ������ ��������� ������
             *  [out] PointIterator  - �������� ����� �� ���� ������
             */
            double FindClosestPointOnBound( GPDPoint2dRef P, int &BoundCurveIndex, 
                                            GPDPoint2dnList::_ITERATOR &PointIterator,
                                            GPDPoint2dnList *except_curve = nullptr);

            /**
             *	����� ���������� ���������� � ������������ ��������������
             */
            double FindClosestDistanceToPolygon( GPDPoint2dRef P );

            /**
             *	������� ����������� ����������� ������������� ��� �������
             */
            void CalcCoveringPolygon();

            /**
             *  ��������� ������� �� �������� ������� 2� � ������������ ����� ������� ������������ ������
             */
            void CalcNormals(GPDPoint2dnList &curve2DRef, bool isClosed, int numContour = -1);

            /**
             *  ������������� ��������� ������� �� �������� - � ������, ���� ������ �������� �� ������� �����������
             */
            void CorrectContourAtMapLimit(GPDPoint2dnList &curve2DRef);

            /**
             *	��������� ���������� ������������� ��� �������, 
             *	���������� ����� ������������ � rect_points
             */
            void CalcContourRect(GPDPoint2dn (&rect_points)[4]);
            /**
             *  ��������� ����������� ����������� lambda
             *	� ����� ������������ ��� ����� - A,B,C
             */
            void CalcLineEquLambda(  GPDPoint2dn *A, GPDPoint2dn *B, 
                                     double &LE_A, double &LE_B, double &LE_C, 
                                     bool isDivToLambda = true);
            /**
             *	������� �� ������� �����, ����������� ������������� �� ������������� ����� 
             *  (��� ���������� ������������ ��������������)
             */
            bool FindMaxDeviationPoint(GPDPoint2d &P, int &bound_num, int &point_num);

            /**
             *	����� ����� ���������� ��� �������� ������������� ������
             */
            void FindDeviationPoint(	GPDPoint2dn *LA, GPDPoint2dn *LB,
                                        double A, double B, double C, 
                                        double deviation, 
                                        GPDPoint2dn &P );
            /**
             *  ������� ����������, ��� �� ������� ����� ������� ����� ���������� val0 � val1
             */
            inline bool isCrossMapLimit( double val0, double val1, int* map_limit_index=(int*)0, double val_limit=1 );            
           
            /**
             *  �������� ���-������� ����� ���������� �� ����� � ������� �������
             */
            void UpdatePoints2EdgesHash(GPDPoint2dnList *curve2DPtr, unsigned int eIndex);

            /**
             *	 ��������� ���� ����� ���� �������� ����� ���������
             */
            void ProcessEdges( edges_function &funcRef, bool isUpdateExcept = false,                               
                               std::set<GPDPoint2dnList*> *only_curves = nullptr,
                               std::set<GPDPoint2dnList*> *except_curves = nullptr);

        public:
            /**
             *	���������, ��������� �� ����� ������ ������������ ��������������
             */
            bool CheckIfPointInCoveringPolygon( GPDPoint2dnRef P );

            /**
             *  �������� ���������������� - �������� ������� � �������� ����� (Tri_MapSector)
             */            
            void PreTriangulate(basicList<Tri_MapSector> *tri_mapSectorsPtr);

        private:
            /**
             *  ������� �������� ������� ����� � ��������������� ��������
             */
            void GetMapLimits();
            
            /**
             *  ������� ���������, ��� �� ����������� ��������� ����
             */
            bool CheckIfError();

            /**
             *  ���������� ������ �������� �� ����������� �����
             */
            int CalcSegNum( double U, double V );

            /**
             *  ������� ��������� ��������� ����� � ��������(�������)
             *  ���� P0 � P1 - ������, ��� ����� �����������
             */
            void AddPointToSegment( basicList<Tri_MapSector> *tri_mapSectorsPtr,
                                    GPDPoint2dPtr P, 
                                    unsigned int numSector, 
                                    GPDPoint2dPtr P0 = nullptr,
                                    GPDPoint2dPtr P1 = nullptr);


            /**
             *  ������� ��������� ����� ����������� � ��������� (3D) 
             *  �� ��������� ����� ����������� �� �����
             */
            Gepard::BasicMath::GPDPoint CalcIntersectPoint3D(unsigned int numSector, GPDPoint2dPtr P);

            /**
             *  ������� ��������� ����� ����������� � ��������� (3D) 
             *  �� ��������� ����� ����������� �� ����� � �������� ������ �������
             *  P - ����� ����������� 2D; P0,P1 - ������ �� �������
             */
            Gepard::BasicMath::GPDPoint CalcIntersectPoint3D_Contour( unsigned int numSector, 
                                                                      GPDPoint2dPtr P,
                                                                      GPDPoint2dPtr P0,
                                                                      GPDPoint2dPtr P1);

            /**
             *	��������� ��������������� ����� (3D) �� �������� ������ �� ����� (A, B), 
             *  � ����� (2D) "�����������", ������� ����� AB
             */
            Gepard::BasicMath::GPDPoint CalcIntersectByPoints( GPDPoint2dPtr A, GPDPoint2dPtr B, GPDPoint2dPtr intersect2d, 
                                                               GPDPointPtr P0, GPDPointPtr P1 );


            /**
             * ����������� �����
             */
            double U0, U1, V0, V1;

            /**
             *  ���������� ������������ ����� �� �����
             */
            unsigned int NumU, NumV;           

            /**
             *  ��������� �� ���-�������, ����������� ����� �������� ����� � ���������� �� ������� 
             *  (�� ������� GPDFace->tri_MapSectorList)
             */
            boost::unordered_map<unsigned int,Tri_MapSector*> *MapSectors_hash_ptr;
                        
            /**
             *  ������ �� ����� - ��������������� ���������� ������ �����
             */
            std::list<GPDPoint2dPtr> BoundContour2D;

            /**
             *  ���-������� ��������� ��������� �� ����� � ���������� �� ������ ����� BoundContour2D
             *  - ��� ������ ������� ����� (������ ������ �������)
             */
            boost::unordered_map< GPDPoint2dPtr,
                                  std::list<GPDPoint2dPtr>::iterator > Neighbours_hash;


            /**
             *  ������� ��������� ������ �� �������� �����
             */
            void UpdateBoundContour2DList();

            /**
             *  ������� ������� ������� ���������� ��������� �� �����
             *  � ���������� ��� ��������� �� ������ BoundContour2D             
             */
            void FindPointNeighbours( std::list<GPDPoint2dPtr>::iterator cur_itr,
                                      std::list<GPDPoint2dPtr>::iterator &prev_itr, 
                                      std::list<GPDPoint2dPtr>::iterator &next_itr);

            /**
             *  ������� ������� ������ ����� � �������� �������� (�����, ������� �� ����� ������)
             */
            void DeleteSparePoints(basicList<Tri_MapSector> *tri_mapSectorsPtr);

            /**
             *  ������� ��������� ������
             */
            void ClearTempData();

        };

    }

}
#endif // !defined(GPD_0746DBE7_61A8_4045_90E1_2E79E648461D__INCLUDED_)
