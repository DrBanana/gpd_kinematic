////////////////////////////////////////////////////////////////
//  Tri_defines.h
//  �������:   8-���-2013 17:11:22
//  �����:     Freeman
//  ��������:  �����������, ����������� ��� ������ ������������	
///////////////////////////////////////////////////////////////

#pragma once

#include "../../BasicMath/GPDPoint2d.h"
#include "../../BasicMath/GPDPoint.h"
#include "../../General/basicArray.h"
#include "../../General/basicList.h"


namespace Gepard
{
    namespace Visualization
    {
        namespace Triangulation
        {

            using namespace Gepard::General;
            using namespace Gepard::BasicMath;

            /**
             *  ������ 2D ����� � ������� �����
             */
            typedef basicList<GPDPoint2dPtr>    Tri_Contour2D;

            /**
             *  ������ 3D ����� � ������� �����
             */
            typedef basicList<GPDPointPtr>      Tri_Contour3D;

             /**
                *  ��������� ��������� �����
                */
            struct Tri_Edge 
            {
                Gepard::BasicMath::GPDPoint2dPtr P[2]; //����� �����

                Tri_Edge(){};
                Tri_Edge( Gepard::BasicMath::GPDPoint2dPtr p0, 
                          Gepard::BasicMath::GPDPoint2dPtr p1 ) 
                {  
                    P[0] = p0; 
                    P[1] = p1;
                };
            };

            typedef std::list<Tri_Edge>::iterator edges_iterator;

            /**
             *  ��������� ��� �������� ������������ (3D)
             */
            struct Triangle3D 
            {
                Gepard::BasicMath::GPDPointPtr vertex[3];

                Triangle3D( Gepard::BasicMath::GPDPointPtr P0,
                            Gepard::BasicMath::GPDPointPtr P1,
                            Gepard::BasicMath::GPDPointPtr P2)
                {
                    vertex[0] = P0;
                    vertex[1] = P1;
                    vertex[2] = P2;
                }
                
                Gepard::BasicMath::GPDPointPtr operator[](unsigned int _index)
                {
                    if (_index>2) return nullptr;
                    return vertex[_index];
                }
            };
                        

            /**
             *  ��������� ��� �������� ������������ (2D)
             */            
            struct Triangle2D 
            {                
                Gepard::BasicMath::GPDPoint2dPtr vertex[3]; //������� ������������
                bool isExist; //���������� �� �����������

                Triangle2D( Gepard::BasicMath::GPDPoint2dPtr P0,
                            Gepard::BasicMath::GPDPoint2dPtr P1,
                            Gepard::BasicMath::GPDPoint2dPtr P2)
                {
                    vertex[0] = P0;
                    vertex[1] = P1;
                    vertex[2] = P2;
                    isExist = true;
                }
                Gepard::BasicMath::GPDPoint2dPtr operator[](unsigned int _index)
                {
                    if (_index>2) return nullptr;
                    return vertex[_index];
                }
            };

#ifdef TRIANGULATION_CHECK_TRI
            struct triangle2d_test
            {
                Gepard::BasicMath::GPDPoint2d vertex[3]; //������� ������������

                triangle2d_test( Gepard::BasicMath::GPDPoint2d P0,
                                 Gepard::BasicMath::GPDPoint2d P1,
                                 Gepard::BasicMath::GPDPoint2d P2)
                {
                    vertex[0] = P0;
                    vertex[1] = P1;
                    vertex[2] = P2;                    
                }
            };
#endif

        };
    };
};