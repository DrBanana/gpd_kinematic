///////////////////////////////////////////////////////////
//  GPDSurface.h
//  ����������	Class GPDSurface
//  �������:    15-���-2012 17:35:18
//  �����:		Dr_Freeman
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
         * ����������� ����� �����������.
         * ����� ����������� ������ �� 0 �� 1 � ��� �����������.
         */
        class GPDSurface : public QuadMap
        {

        public:

            /**
             * ����� ����� - ����� ��� ������� ������������ ����� (pointreper - ��� ����������
             * repervariat)
             */
            Gepard::BasicMath::GPDReper point_reper;
         
            /**
             * ������ �������� ����������� �� U
             */
            Gepard::BasicMath::GPDVectorArray VectorsTangentU;

            /**
             * ������ �������� ����������� �� V
             */
            Gepard::BasicMath::GPDVectorArray VectorsTangentV;

            /**
             * ������ ����� ����������� � ���������� �����������.
             */
            Gepard::BasicMath::GPDPointArray Points;

            /**
             * ������ �������� ������������
             * ����������� ��� ������� �� STEP ��� ��� �������������
             */
            std::vector<unsigned int> NearSurfaces;
            
            /** 
             *  ��������� �� ������������ �����
             */
            Gepard::Topology_Geometry::GPDFace* parentFace;


            GPDSurface();
            virtual ~GPDSurface();

            /**
             * ������� ����������� � ���������� ����������� ��������
             */            
            virtual void CalcSurface(unsigned int _numU = 0, unsigned int _numV = 0, double _stepU = 0, double _stepV = 0);

             /**
             *	��������� ����������� � �������� �������� ��������������� ���������
             */
            void calc_surface( double u0, double v0, double u1, double v1, 
                               unsigned int _numU, unsigned int _numV );

            /**
             *	��������� ����������� � �������� �������� ��������������� ���������
             */
            virtual void CalcSurface(double u0, double v0, double u1, double v1, 
                                     unsigned int _numU, unsigned int _numV,
                                     Gepard::BasicMath::GPDPointArray &_PointArray);

            /**
             *	������ 2� ����� �� ����� �� �� 3� �����������
             */
            virtual void CalcMapPoint(  Gepard::BasicMath::GPDPointRef P3D, 
                                        Gepard::BasicMath::GPDPoint2dRef p2d );

            /**
             *  ������ 3� ����� ����������� �� �� 2� ����������
             */
            virtual void CalcSurfacePoint( Gepard::BasicMath::GPDPoint2dRef p2d,
                                           Gepard::BasicMath::GPDPointRef P3D );

            /**
             *  ������ 2� ������� �� ����� �� 3� ������
             */
            virtual void CalcMapContour( Gepard::Curves::GPDCurve3DPtr curve3DPtr,
                                         Gepard::General::basicList<Gepard::BasicMath::GPDPoint2dn> &curve2DRef);
            
            /**
             *  ������ �������� ��� ������� �� ����������� (3D)
             */
            virtual void CalcContourNormals( Gepard::Curves::GPDCurve3DPtr curve3DPtr );

            /**
             *  �������� ����� ������� �����������
             */
            virtual void ProcessAfterCalcSurface();

            /**
             *  ������������� ������� (������/������)
             */
            void CorrectNormal(Gepard::BasicMath::GPDPointRef P3D);

            /**
             * ���������� �������� �����������
             */
            void setSurfacePrecision(unsigned int _numU, unsigned int _numV, double _stepU=0, double _stepV=0);

            /**
             * �������� ����� p_rep; R - ���������� ����� (u_index, v_index), E1 - �����������
             * �� U, E2 - ����������� �� V, E3 - �������
             */
            void getP(int u_index, int v_index, Gepard::BasicMath::GPDReperRef p_rep);

            /**
             * ������ ����� �� �����������: R - ���������� ����� (u_index, v_index), E1 -
             * ����������� ������ �� U, E2 - ����������� ������ �� V, E3 - �������
             */
            void setP(int u_index, int v_index, Gepard::BasicMath::GPDReperRef p_rep);
                     

            /**
             *  �������� 4 ����� �������� ����������� �� ��� ����������� ������
             */
            void getSegmentPoints( unsigned int seg_num, 
                                   Gepard::BasicMath::GPDPointPtr (&seg_points3D)[4],
                                   Gepard::BasicMath::GPDPoint2d  (&seg_points2D)[4] );

            /**
             *  �������� 4 �����(3D) �������� ����������� �� ��� ����������� ������
             */
            void getSegmentPoints3D( unsigned int seg_num, 
                                     Gepard::BasicMath::GPDPointPtr (&seg_points3D)[4] );
            /**
             *  �������� 4 �����(3D) �������� ����������� �� ��� �����������
             */
            void getSegmentPoints3D( unsigned int U_index, unsigned int V_index, 
                                     Gepard::BasicMath::GPDPointPtr (&seg_points3D)[4] );

            /**
             *  ���������� ���������� ����� �� ����� �� ������ �������
             */
            void calcSegmentPoints2D( unsigned int seg_num, 
                                     Gepard::BasicMath::GPDPoint2d  (&seg_points2D)[4] );


            /**
             *  ���������� ���������� ����� �� ����� �� ����������� �������
             */
            void calcSegmentPoints2D( unsigned int U_index, unsigned int V_index,
                                      Gepard::BasicMath::GPDPoint2d  (&seg_points2D)[4] ) ;
            

            /**
             *	������������ ����� - ������� �� ��������� ������� ��������� (variation_reper)
             *  � ���������� ������� ��������� (GlobalReper)
             */
            void GlobalizePoint(Gepard::BasicMath::GPDPoint &P);

            /**
             *  �������� ��� �����������
             */
            Gepard::Surfaces::SURFACE_TYPES GetSurfaceType() const;

            /**
             *  �������� ��� �����������
             */
            int GetSurfaceTypeNum();

            /**
             *  �������� ��������� ����� �����������
             */
            QuadMap GetSurfaceMap();             

            /**
             *  ������������� ����� � ��������� ������� ���������
             *  (�.�. � ������� ��������� ������ point_reper)
             */
            void ConvertToLocalBasis();

            /**
             *  ������������� ����� � ���������� ������� ���������
             *  (�.�. �� ������� ��������� ������ point_reper � global)
             */
            void ConvertToGlobalBasis();

            /**
             * ������������� � ������� �����������
             */
            GPDPlaneSurface* toPlane();

            /**
             * ������������� � �������������� �����������
             */
            GPDCylindricalSurface* toCylindrical();

            /**
             * ������������� � ���������� �����������
             */
            GPDConicalSurface* toConical();

            /**
             * ������������� � ������������ �����������
             */
            GPDToroidalSurface* toToroidal();
            
            /**
             * ������������� � ����������� �����������
             */
            GPDSphericalSurface* toSpherical();
                      
            /**
             *	������������� � NURBS �����������
             */
            GPDNURBSSurface* toNURBS();
                       
            /**
             *  �������� ���������� ����� �� �������� ������� (GPDPoint2d, GPDPoint &P)
             */
            void ModifyPoints(Gepard::BasicMath::TModifyPointsFunc &funcRef);

            /**
             *  ���������� ������� ����������� ������������� ��������� ����������� fromSurfPtr
             */
            virtual void SetEquivalentParamsFrom(Gepard::Surfaces::GPDSurface* fromSurfPtr);

            /**
             * ���������� � ����
             */
            virtual void saveToFile(std::ostream& os);

            /**
             * ������ �� �����
             */
            virtual void readFromFile(std::istream& _is);

            /**
             *	�������� �������������� ��������������
             */
            Gepard::BasicMath::BoundingBox GetBoundingBox();

        private:
           
            /**
             *	��������� ���������� ����������� �� ���������
             */
            virtual void setDefaultParameters();

            /**
             *  ����������� ����� �� ������� ��������� oldReper
             *  � ������� ��������� newReper
             */
            void ConvertToBasis(Gepard::BasicMath::GPDReper& oldReper,
                                Gepard::BasicMath::GPDReper& newReper );

        protected:
            /**
             * ��� �����������
             */
            Gepard::Surfaces::SURFACE_TYPES TYPE;
            
            /**
             *  ������� ��������� �������� ��������� ����� "����� ������" 0 � 1
             */
            void CorrectCoordsAtLimit(Gepard::BasicMath::GPDPoint2dPtr P);

            /**
             *	����������� �������������� �����������
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
