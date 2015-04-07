///////////////////////////////////////////////////////////
//  GPDFaceBound.h
//  ���������� Class GPDFaceBound
//  �������:   15-���-2012 16:38:04
//  �����:     Dr_Freeman
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
         * ������� ����� - ������������ ����� ������ �����(������), �������������� �����������.
         */
        class GPDFaceBound
        {
        public:
            /**`
             *	����������� ��-���������
             */
            GPDFaceBound( GPDFace* parent_face=0, 
                          FACE_BOUND_TYPE boundType=FBT_OUTER_BOUND );
                        
            /**
             *	������� 
             */
            virtual ~GPDFaceBound();
            
            /**
             * ��� �������
             */
            FACE_BOUND_TYPE bound_type;
            /**
             * ������ ����� - ������ (edges_loop)
             */
            GPDCurve3DPtrArray edges;

            /**
             *	������ ����� �� ����� ����������� (2D-������)
             */            
            GPDContourBound contourBound;
            /**
             *	��������� �� ������������ �����
             */
            GPDFace* parentFace;

            /**
             *  ����� ����� - ������ �������� � �������� ����������� �����������
             */
            GPDPoint loop_vertex;

            /**
             *  ���� - ���� �� loopVertex
             */
            bool isLoopVertex;

            /**
             * �������� �����.
             */
            GPDCurve3DPtr operator[](unsigned int i);

            /**
             * �������� ����� � �������
             */
            void addEdge(GPDCurve3DPtr _edge, bool _edge_orient=true);

            /**
             *	��������� ����� �������� ��������� �����
             */
            void setDeleteEdgesGeometryFlag(bool isDelGeom);

            /**
             *	������ ������� 2� ����� �� ����� �� ������� 3� ����� �� �����
             */
            void CalcMapContour(bool isSecondPass = false);

            /**
             *  ������ �������� 3� ����� ������, ����������� �������
             */
            void CalcBoundNormals();

            /**
             *  ������� 3D-������ �� ����
             */
            static GPDCurve3DPtr createCurve(CURVE_3D_TYPE curve_type);

            /**
             *  ��������� ������� - ������� 3D-������ �� ����
             */
            template <class T>
            static GPDCurve3DPtr CreateCurve();

            /**
             *  ������� ��������� ������ ����� (�������. �������� �����)             
             */
            void CalcFaceBoundGeometry();

            /**
             *  �������� ����������� ����� � 3D �� ��������� �������� ������������ �����
             *  ������������ ������ - ����� �� ��������: U = [1] - [0], V = [3] - [2],
             *  ��� U - ����� ������������ ������� �������, V - �������
             */
            void CalcAxesLimit( GPDPointRef O, 
                                GPDVectorRef axisU,
                                GPDVectorRef axisV,
                                double (&lenUV)[4] );

            /**
             *  ������� ���������������� - ���������� ������ � parentFace -> tri_MapSectorList
             *  (���������� ������ ��� ������������)
             */
            void PreTriangulate();

             /**
             *  ���������� ����� ������� �����
             */
            void SetBoundNum( unsigned int _boundNum ) {BoundNum = _boundNum;}

             /**
             *  �������� ����� ������� �����
             */
            unsigned int GetBoundNum() { return BoundNum; }
            
            /**
             *  �������� ������������� ���� bound
             */
            int GetBoundTypeId();

            /**
             *  ������� �������� ������� ������� � ��������� �� � �������� �����
             */
            void CopyFaceBound( GPDFace* facePtr );

            /**
             *  ����������� ����� ����� �� ������� ��������� oldReper � ������� ��������� newReper
             */
            void ConvertToBasis( GPDReper &oldReper, 
                                 GPDReper &newReper);

            /**
             *  �������� �������� ���������� ������������������ ����� � ��������������
             */
            bool GetEdgeOrientation(int eIndex);

            /**
             *  ���������� ������� ������� ������������� ��������� ������� boundPtr
             */
            void SetEquivalentParamsFrom(GPDFaceBound* boundPtr);

            /**
             *	�������� ����������� ��������������
             */
            BoundingBox GetBoundingBox();

            /**
             *	����� �����-���������
             */
            void FindBridgeEdges();

            /**
             *	�������� �� ������ ����� ����������
             */
            bool isBridge(Gepard::Curves::GPDCurve3DPtr c3d);


            //������������� �������� ������
            friend ostream& GPDFaceBound::operator<<(ostream& os, GPDFaceBound &bound)
            {	
                //�������� � ���������� ��� �������                                
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

            //������������� �������� �����
            friend istream& operator>>(istream& is, GPDFaceBound &face_bound)
            {
                //��������� ��� �������                 
                is.read((char *) &face_bound.bound_type, sizeof face_bound.bound_type);
                is.read((char *) &face_bound.BoundNum, sizeof face_bound.BoundNum);
              
                is.read((char*)&face_bound.loop_vertex, sizeof (Gepard::BasicMath::GPDPoint));
                is.read((char*)&face_bound.isLoopVertex, sizeof(bool));

                //���������� ������
                unsigned int _edge_count = 0;
                is.read((char *) &_edge_count, sizeof _edge_count);

                for (unsigned int i=0; i<_edge_count; i++)
                {
                    //��������� ������������� ��� �����
                    int _curve_type = 0;
                    is.read((char *) &_curve_type, sizeof _curve_type);

                    //��������� ��������� �����
                    Gepard::Curves::GPDCurve3DPtr _curvePtr = \
                        GPDFaceBound::createCurve((Gepard::Curves::CURVE_3D_TYPE)_curve_type);
                    _curvePtr->readFromFile(is);

                    //��������� orientation
                    bool _orientation;
                    is.read((char *) &_orientation, sizeof _orientation);

                    face_bound.addEdge(_curvePtr, _orientation);                    
                }//for

                return is;
            }


        private:

            /**
             *  ������� �������� ������ ������ �� ���� � �������� ������
             */
            void CopyCurve3D( GPDCurve3DPtr fromCurve, GPDCurve3DPtr toCurve);

            /**
             *  ��������� ������� �������� �������������� ������ ������ fromCurve � ������ toCurve �� ����
             */
            template <class T>
            void SetCurveData( GPDCurve3DPtr fromCurve, GPDCurve3DPtr toCurve);
                     
            /**
             * ���������� �������������� ���������� ����� � ��������������. ������������ ���
             * ����������� ���������� 2D-�������� �������.
             */
            std::vector<bool> edge_Orientation;

            /**
             *  ����� ������� �� ������ �����
             */
            unsigned int BoundNum;

            /**
             *	���� �������� ��������� �����
             */
            bool isDeleteEdgesGeometryFlag;

            /**
             *	����������� �������������� 
             */
            BoundingBox boundingBox;

            /**
             *	������ �����-���������
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
