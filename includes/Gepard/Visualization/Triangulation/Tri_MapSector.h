///////////////////////////////////////////////////////////
//  Tri_MapSector.h
//  Реализация Class Tri_MapSector
//  Создано:   27-фев-2013 17:10:53
//  Автор:     Dr_Freeman
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
             * Квадратный сектор на карте поверхности. Характеризуется порядковым номером на
             * поверхности и массивом "контуров" - указателей на точки
             */
            struct Tri_MapSector
            {    
                
                //TODO: выкинуть лишнее - оставить только то, что реально нужно для триангуляции и после нее

                /**
                 * Порядковый номер сектора - для получения точек с карты поверхности
                 */
                unsigned int num;

                /**
                 *  Массив 2D контуров в секторе карты
                 */
                basicList<Tri_Contour2D> c_2DArray;

                /**
                 *  Массив точек пересечений с сегментом 2D
                 */
                basicList<GPDPoint2d> Intersections2D;

                /**
                 *  Массив 3D контуров в секторе карты
                 */
                basicList<Tri_Contour3D> c_3DArray;

                /**
                 *  Массив точек пересечений с сегментом 3D
                 */
                basicList<GPDPoint> Intersections3D;

                /**
                 *  Массив треугольников 3D
                 */
                basicList<Triangle3D> triangles3D;

#ifdef TRIANGULATION_CHECK_TRI
                /**
                 *  Массив видимых треугольников
                 */                
                std::list<triangle2d_test> tri2D_visible;

                /**
                 *  Массив невидимых треугольников
                 */                
                std::list<triangle2d_test> tri2D_invisible;
#endif


                /**
                 *  Скопировать сектор
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
