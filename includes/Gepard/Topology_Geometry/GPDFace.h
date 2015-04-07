///////////////////////////////////////////////////////////
//  GPDFace.h
//  ���������� Class GPDFace
//  �������:      15-���-2012 16:53:48
//  �����: Dr_Freeman
///////////////////////////////////////////////////////////

#if !defined(EA_27D69AAA_B986_4142_8602_0BD2ACFA8FCD__INCLUDED_)
#define EA_27D69AAA_B986_4142_8602_0BD2ACFA8FCD__INCLUDED_

#include "GPDFaceBound.h"
#include "../Surfaces/GPDSurface.h"
#include "../General/basicArray.h"

#include <map>
#include <BOOST/unordered_map.hpp>

namespace Gepard
{
    namespace Topology_Geometry
    {
        using namespace Gepard::Visualization::Triangulation;        

        class GPDSolid;
        /**
         * �����.
         */
        class GPDFace
        {
        public:            
            /**
             *	����������� 
             */
            GPDFace();
            /**
             *	������� ����� � �������� ����������
             */
            GPDFace( Gepard::Surfaces::GPDSurface* surf_geom, 
                     Gepard::Topology_Geometry::GPDSolid *parent_solidPtr, 
                     bool face_orientation=true);

            /**
             *	������� ����� �� ���� �����������
             */
            GPDFace( Gepard::Surfaces::SURFACE_TYPES surface_type, 
                     Gepard::Topology_Geometry::GPDSolid *parent_solidPtr, 
                     bool face_orientation=true );

            virtual ~GPDFace();			

            /**
             * ������ ����� ����� - �������.
             */
            Gepard::Topology_Geometry::GPDFaceBoundList Bounds;
            /**
             * �������������� �������� �����
             */
            Gepard::Surfaces::GPDSurface* geometry;
            /**
             * ���������� ����� - ��� ����������� ����������� �������� ������� �� �����
             * �����������.
             */
            bool orientation;
            /**
             * ������������ CLOSED_SHELL - GPDSolid
             */
            GPDSolid* parentSolidPtr;

            /**
             *  ������ �������� ��� ������������
             */
            Tri_MapSectorList tri_MapSectorList;            

            /**
             *	������� ������ �������������� ������������ �� �����
             */
            void deleteGeometry();

            /**
             *	������� ������ � ���� ����� � �������� ������ �����
             */
            void deleteBounds();

            /**
             *	������ ��������� �����, ���� ��������� ��� �� ���� ������
             *	������������ ��������: NULL - �� ������� �������,
             *	����� - ��������� �� ���������
             */
            Gepard::Surfaces::GPDSurface* createFaceGeometry(Gepard::Surfaces::SURFACE_TYPES surface_type);

            /**
             *  ������� ��������� �� ���� � �������� �� ��� ���������
             */
            static Gepard::Surfaces::GPDSurface* createGeometry(Gepard::Surfaces::SURFACE_TYPES surface_type);

            /**
             *	��������� ���� �������� ��������� � �����������,
             *	� ��� ����� �������� �����
             */
            void setGeometryDeleteFlag(bool isDelGeom);

            /**
             *  ������� ��������� ������ ����������� (��������������� �������� �����)
             *  � ������ ���� ����� (�� ���������. ���������)
             */
            void CalcFaceGeometry(bool isSecondPass = false);

            /**
             *  �������� ������� �����
             */
            Gepard::Topology_Geometry::GPDFaceBoundPtr AddBound(Gepard::Topology_Geometry::GPDFaceBoundRef bound);

            /**
             *  ������� ������������ �����
             */
            void Triangulate();    

            /**
             *  ������� ��������� ��������� ����� (2D) �� �����
             */
            bool CheckPoint2DVisibleDiscrete(Gepard::BasicMath::GPDPoint2dn *p2d);
           

             /**
             *  ���-������� ��������� ����� �������� ����� � ���������� �� ������� 
             *  (�� ������� tri_MapSectorList)
             */
            boost::unordered_map<unsigned int,Tri_MapSector*> MapSectors_hash;

            /**
             *  ������ ������� ������� �������� ����������� (��� �������������)
             */
            std::list<unsigned int> MapSectors_visible;

             /**
             *  ���-������� ������������ 2D-����� 3D-������
            */
            boost::unordered_map<GPDPoint2dPtr,GPDPointPtr> MapPoints_hash;

            /**
             *  ������� �������� ����� � �������� �� � �������� ����
             *  ����� - ������������ �� ����������! 
             *  ������� - ��������� �� ������������� �����
             */
            GPDFace* CopyFace(GPDSolid* solPtr);

            /**
             *  ������� �������� ������� ����� � ���������
             */
            void CopyFace(GPDFace *targetFacePtr, GPDSolid *parentS = nullptr);

            /**
             *  �������� ����� ����������� (� ��������������� ��������)
             */
            Gepard::BasicMath::GPDReper GetFaceReper();

            /**
             *  �������� ��������� ����� �� ������ ��������� ������ ����
             */
            void UpdateFacePosBySolidReper(Gepard::BasicMath::GPDReper PosReper);

            /**
             *  �������� ������ - ��� �����������
             */
            std::string GetFaceTypeStr();

            /**
             *  �������� ������������� ���� �����������
             */
            int GetFaceTypeId();

            /**
            * �������� ����� ����
            */
            void SetUIN(unsigned int uin);

            /**
            * ������ ����� ����
            */
            unsigned int GetUIN();

            /**
             *  �������� ��� ��������������� ��������
             */
            Gepard::Surfaces::SURFACE_TYPES GetFaceType();

            /**
             *  ������� ����������� ���������� ��������� �� ����
             */
            void CopyGeometryTo(Gepard::Surfaces::GPDSurface* surfPtr);

            /**
             *  ���������� � ������� ����� ������������� ��������� ����� fromFacePtr (�������� ����� �� ��������)
             *  ������� ����� ������ ���� ������ ����� fromFacePtr
             */
            void SetEquivalentParamsFrom(Gepard::Topology_Geometry::GPDFace* fromFacePtr);
           
            /**
             *  ������������� ����� ����������� � ���������
             *  �� ������� ������ � �����
             */
            void ConvertMapSectorsToBasis( Gepard::BasicMath::GPDReper& oldReper,
                                           Gepard::BasicMath::GPDReper& newReper );

            /**
             *  ������������� �������
             *  �� ������� ������ � �����
             */
            void ConvertBoundsToBasis(Gepard::BasicMath::GPDReper& oldReper,
                                      Gepard::BasicMath::GPDReper& newReper );

            /**
             *  ������������� � ��������� ������� ��������� (GReper->point_reper)
             */
            void ConvertToLocalBasis();

            /**
             *  ������������� � ���������� ������� ��������� (point_reper->GReper)
             */
            void ConvertToGlobalBasis();

             /**
             *  ������������� ������� � ������� ������� ��������������
             *  ������ �������: GPDPoint2d p2d - ���������� ������� �� �����, GPDPoint &P - 3D ����� �������
             */
            void ModifyBounds(Gepard::BasicMath::TModifyPointsFunc &funcRef);

            /**
             *  ������������� ����� ����������� � ��������� �������� ��������������
             *  ������ �������: GPDPoint2d p2d - ���������� ������� �� �����, GPDPoint &P - 3D ����� �������
             */
            void ModifyMapSectors(Gepard::BasicMath::TModifyPointsFunc &funcRef);

            /**
             *	�������� �������������� ��������������
             */
            Gepard::BasicMath::BoundingBox GetBoundingBox();

#ifdef TRIANGULATION_CHECK_TRI
            public:
#else
            private:
#endif
            /**
            *  ������� ���������������� - ��� �����
            */
            void PreTriangulate();

        private:

            /**
            *  ������� ��������� ������ ������� ��������
            */
            void ProcessVisibleMapSectors();

            /**
             * ���������� ����� �����������
             */
            unsigned long m_UIN;       

            /**
             *	���� �������� ��������� ����� � �����������
             */
            bool isDeleteGeometryFlag;

            /**
             *	����������� �������������� �� ���� ���� (x,y,z)
             */
            BoundingBox boundingBox;

            /**
             *	��������� ����������� �������������� �� ������
             */
            void CalcBoundingBox();

            /**
             *  ��������� ������� ����������� �������������� ��������� �� ����
             */
            template <class T>
            void SetGeometryData(Gepard::Surfaces::GPDSurface* geometryPtr);

            /**
             *  ��������� ������� ������� ��������� �� ����
             */
            template <class T>
            static Gepard::Surfaces::GPDSurface* CreateGeometry();
           

            //������������� �������� ������
            friend ostream& GPDFace::operator<<(ostream& os, Gepard::Topology_Geometry::GPDFace &face)
            {	
                //�������� � ���������� ��� �����
                int _tst = face.GetFaceTypeId();      
                os.write((char *) &_tst,sizeof _tst);
                                
                //��������� ��������� �����
                face.geometry->saveToFile(os);
            
                //�������� � ���������� ����������� bounds
                unsigned int _bound_count = face.Bounds.getCount();
                os.write((char *) &_bound_count,sizeof _bound_count);

                //��� ������� bound ���������� ����� � ���������
                face.Bounds.set_start();
                while(auto boundPtr = face.Bounds.get_next())
                {
                    os << *boundPtr;
                }//while bounds

                os.write((char *) &face.m_UIN, sizeof face.m_UIN);                
                os.write((char *) &face.orientation,sizeof face.orientation);

                return os;

            }//end of <<           
         
            //������������� �������� �����
            friend istream& operator>>(istream& is, Gepard::Topology_Geometry::GPDFace &face)
            {
                //��������� ��������� �����
                
                //��������� ��� �����
                unsigned int _face_type = 0;
                is.read((char *) &_face_type , sizeof _face_type);

                //������ �� ���������� ���� ��������� ��������� �����
                Gepard::Surfaces::GPDSurface* _surfPtr =                     
                    face.createFaceGeometry((Gepard::Surfaces::SURFACE_TYPES)_face_type);
                _surfPtr->readFromFile(is);

                //���������� ������
                unsigned int _bound_count = 0;
                is.read((char* ) &_bound_count, sizeof _bound_count);

                for (unsigned int i=0; i<_bound_count; i++ )
                {                    
                    //��������� ������� � �����
                    auto boundPtr = face.AddBound(GPDFaceBound());
                    is >> *boundPtr;

                }//for i

                is.read((char *) &face.m_UIN, sizeof face.m_UIN);
                is.read((char *) &face.orientation, sizeof face.orientation);

                return is;
            }

        };


        typedef GPDFace* GPDFacePtr;
        typedef GPDFace& GPDFaceRef;
        typedef	Gepard::General::basicArray<GPDFace> GPDFaceArray;
        typedef	Gepard::General::basicArray<GPDFacePtr> GPDFacePtrArray;
        typedef	Gepard::General::basicList<GPDFace> GPDFaceList;
        typedef	Gepard::General::basicList<GPDFacePtr> GPDFacePtrList;

        //������������� ������ - ��������� �� ����������� = ������ (����, �����)
        typedef std::map<GPDFacePtr,std::pair<int,int>> GPDFacePtrToComplexIndex;   

    }

}
#endif // !defined(EA_27D69AAA_B986_4142_8602_0BD2ACFA8FCD__INCLUDED_)
