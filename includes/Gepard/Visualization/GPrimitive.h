///////////////////////////////////////////////////////////
//  GPrimitive.h
//  Implementation of the Class GPrimitive
//  Created on:      19-авг-2013 18:50:20
//  Original author: Anton
///////////////////////////////////////////////////////////

#if !defined(GPD_390F7782_0537_40bc_8B0C_CC6A1F9EE420__INCLUDED_)
#define GPD_390F7782_0537_40bc_8B0C_CC6A1F9EE420__INCLUDED_

#include <list>
#include <unordered_map>
#include <boost/unordered_map.hpp>
#include <boost/unordered_set.hpp>

#include "GDefine.h"
#include "GColor.h"

namespace Gepard
{
    namespace Visualization
    {   

        /**
         * Базовый класс для геометрических примитивов
         */
        class GPrimitive
        {

        public:
            GPrimitive();
            GPrimitive(GPRIMITIVE_TYPE _prim_type);
            virtual ~GPrimitive();
            
            /**
             *	Список вершин примитива
             */
             std::list<GVertex> Vertexes;
             
            /**
             *	Цвет вершины (индекс вершины - цвет)
             */
             boost::unordered_map<unsigned int, GColor> _ColorMap;
            
            /**
             * Цвет примитива
             */ 
             GColor _Color;	

             /**
              * Добавление вершины примитива
              */
             void AddVertex( float x, float y, float z,
                             float nx=0.0f, float ny=0.0f, float nz=0.0f );

             /**
              * Добавление вершины примитива с цветом
              */
             void AddVertex( float x, float y, float z,
                             GColor VertexColor,
                             float nx=0.0f, float ny=0.0f, float nz=0.0f );

             /**
              * Установить цвет примитива
              */
             void SetPrimitiveColor(float _red, float _green, float _blue, float _alpha);
             /**
              * Установить цвет примитива
              */
             void SetPrimitiveColor(GColor _color);

             /**
              * Получить тип примитива
              */
             GPRIMITIVE_TYPE GetType();

             /**
              * Есть ли у примитива цвет
              */
             bool isColored() const;

             /**
              * Сброс цвета примитива
              */
             void DropColor();

//TODO: У каждого примитива должна быть ссылка на базовый класс "Экстра параметров" - 
// для каждого типа примитива такие экстра параметры будут разные (например, толщина и тип линии)

        private:
            /** 
             *  Тип примитива
             */
            GPRIMITIVE_TYPE primitive_type;

            /**
             *  Есть ли цвет у примитива
             */
            bool _isColored;              
        };

    }

}
#endif // !defined(GPD_390F7782_0537_40bc_8B0C_CC6A1F9EE420__INCLUDED_)
