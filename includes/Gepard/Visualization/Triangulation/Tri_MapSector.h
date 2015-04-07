///////////////////////////////////////////////////////////
//  Tri_MapSector.h
//  ���������� Class Tri_MapSector
//  �������:   27-���-2013 17:10:53
//  �����:     Dr_Freeman
///////////////////////////////////////////////////////////

#if !defined(GPD_8A273BD2_FC48_4765_9B08_E9D633606B68__INCLUDED_)
#define GPD_8A273BD2_FC48_4765_9B08_E9D633606B68__INCLUDED_

#include "Tri_defines.h"
#include <boost/unordered_map.hpp>

namespace Gepard
{
    namespace Topology_Geometry {class GPDFace;}

    namespace Visualization
    {
        namespace Triangulation
        {
                        
            /**
             * ���������� ������ �� ����� �����������. ��������������� ���������� ������� ��
             * ����������� � �������� "��������" - ���������� �� �����
             */
            struct Tri_MapSector
            {    
                
                //TODO: �������� ������ - �������� ������ ��, ��� ������� ����� ��� ������������ � ����� ���

                /**
                 * ���������� ����� ������� - ��� ��������� ����� � ����� �����������
                 */
                unsigned int num;

                /**
                 *  ������ 2D �������� � ������� �����
                 */
                basicList<Tri_Contour2D> c_2DArray;

                /**
                 *  ������ ����� ����������� � ��������� 2D
                 */
                basicList<GPDPoint2d> Intersections2D;

                /**
                 *  ������ 3D �������� � ������� �����
                 */
                basicList<Tri_Contour3D> c_3DArray;

                /**
                 *  ������ ����� ����������� � ��������� 3D
                 */
                basicList<GPDPoint> Intersections3D;

                /**
                 *  ������ ������������� 3D
                 */
                basicList<Triangle3D> triangles3D;

#ifdef TRIANGULATION_CHECK_TRI
                /**
                 *  ������ ������� �������������
                 */                
                std::list<triangle2d_test> tri2D_visible;

                /**
                 *  ������ ��������� �������������
                 */                
                std::list<triangle2d_test> tri2D_invisible;
#endif


                /**
                 *  ����������� ������
                 */
                void CopyMapSector( Tri_MapSector *targetPtr,
                                    Gepard::Topology_Geometry::GPDFace* parentFacePtr,
                                    Gepard::Topology_Geometry::GPDFace* targetFacePtr);              

            };
            typedef basicList<Tri_MapSector> Tri_MapSectorList;

        }

    }

}
#endif // !defined(GPD_8A273BD2_FC48_4765_9B08_E9D633606B68__INCLUDED_)
