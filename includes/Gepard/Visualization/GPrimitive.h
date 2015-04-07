///////////////////////////////////////////////////////////
//  GPrimitive.h
//  Implementation of the Class GPrimitive
//  Created on:      19-���-2013 18:50:20
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
         * ������� ����� ��� �������������� ����������
         */
        class GPrimitive
        {

        public:
            GPrimitive();
            GPrimitive(GPRIMITIVE_TYPE _prim_type);
            virtual ~GPrimitive();
            
            /**
             *	������ ������ ���������
             */
             std::list<GVertex> Vertexes;
             
            /**
             *	���� ������� (������ ������� - ����)
             */
             boost::unordered_map<unsigned int, GColor> _ColorMap;
            
            /**
             * ���� ���������
             */ 
             GColor _Color;	

             /**
              * ���������� ������� ���������
              */
             void AddVertex( float x, float y, float z,
                             float nx=0.0f, float ny=0.0f, float nz=0.0f );

             /**
              * ���������� ������� ��������� � ������
              */
             void AddVertex( float x, float y, float z,
                             GColor VertexColor,
                             float nx=0.0f, float ny=0.0f, float nz=0.0f );

             /**
              * ���������� ���� ���������
              */
             void SetPrimitiveColor(float _red, float _green, float _blue, float _alpha);
             /**
              * ���������� ���� ���������
              */
             void SetPrimitiveColor(GColor _color);

             /**
              * �������� ��� ���������
              */
             GPRIMITIVE_TYPE GetType();

             /**
              * ���� �� � ��������� ����
              */
             bool isColored() const;

             /**
              * ����� ����� ���������
              */
             void DropColor();

//TODO: � ������� ��������� ������ ���� ������ �� ������� ����� "������ ����������" - 
// ��� ������� ���� ��������� ����� ������ ��������� ����� ������ (��������, ������� � ��� �����)

        private:
            /** 
             *  ��� ���������
             */
            GPRIMITIVE_TYPE primitive_type;

            /**
             *  ���� �� ���� � ���������
             */
            bool _isColored;              
        };

    }

}
#endif // !defined(GPD_390F7782_0537_40bc_8B0C_CC6A1F9EE420__INCLUDED_)
