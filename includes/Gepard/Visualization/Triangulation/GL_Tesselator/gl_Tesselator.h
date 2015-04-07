////////////////////////////////////////////////////////////////
//  gl_Tesselator.h
//  Создано:   27-июнь-2013 21:21:42
//  Автор:     Freeman
//  Описание:  Триангуляция полигона с испоьзованием тесселятора
//             OpenGL
///////////////////////////////////////////////////////////////

#pragma once

#if defined _WIN32 || defined _WIN64
#include <windows.h>
#endif

#include <GL/GLU.h>
#include "../../../BasicMath/GPDPoint2d.h"

#if defined _WIN32 || defined _WIN64
#pragma comment(lib,"glu32.lib")
#endif


#ifndef CALLBACK
#define CALLBACK __stdcall
#endif


namespace Gepard
{
    namespace Visualization
    {
        namespace Triangulation
        {
                      
            using namespace BasicMath;

            /**
             *  Функции обратного вызова
             */
            void CALLBACK tess_begin( GLenum ) {}
            void CALLBACK tess_edgeFlag( GLboolean ) {}
            void CALLBACK tess_end() {}

            void CALLBACK tess_vertex
                ( 
                void*           data, 
                std::vector<GPDPoint2dPtr> *_outData
                )
            {
               GPDPoint2dPtr curP = (GPDPoint2dPtr)data;
               _outData->push_back(curP);
            }

            void CALLBACK tess_error(GLenum errorCode)
            { 
                const GLubyte *estring;
                estring = gluErrorString(errorCode);
                fprintf(stderr, "Tesselation error: %s\n", estring);
            }


            /**
             *  Функция создает массив треугольников (_outData (по три вершины)) по заданному замкнутому полигону
             *  Возвращаемое значение - Число треугольников, в случае успеха. -1 - ошибка
             */
            int gl_Tesselate( const std::vector<GPDPoint2dPtr> &_Polygon, std::vector<GPDPoint2dPtr> &_outData )
            {
                if ( _Polygon.size()==0 ) return -1;
                
                _outData.clear();

                GLUtesselator* tess = gluNewTess();
                gluTessCallback( tess, GLU_TESS_BEGIN,          (void (CALLBACK *)())   tess_begin      );
                gluTessCallback( tess, GLU_TESS_EDGE_FLAG,      (void (CALLBACK *)())   tess_edgeFlag   );
                gluTessCallback( tess, GLU_TESS_VERTEX_DATA,    (void (CALLBACK *)())   tess_vertex     );
                gluTessCallback( tess, GLU_TESS_END,            (void (CALLBACK *)())   tess_end        );
                gluTessCallback( tess, GLU_TESS_ERROR,          (void (CALLBACK *)())   tess_error      );
                gluTessNormal( tess, 0.0, 0.0, 1.0 );
                                
                gluTessBeginPolygon( tess, &_outData );
                gluTessBeginContour( tess );

                GLdouble coords[3];
                for( size_t i = 0; i < _Polygon.size(); ++i )
                {
                    coords[0] = _Polygon[i]->u;
                    coords[1] = _Polygon[i]->v;
                    coords[2] = 0;

                    gluTessVertex( tess, coords, (void*)_Polygon[i] );
                }

                gluTessEndContour( tess );
                gluTessEndPolygon( tess );

                gluDeleteTess(tess);               

                return (int)_outData.size()/3;
            }

        }//Triangulation
    }//Visualisation
}//Gepard



