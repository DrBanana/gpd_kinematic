///////////////////////////////////////////////////////////
//  QuadMap.cpp
//  ���������� 	QuadMap
//  �������:   	5-���-2013 13:38:31
//  �����: 		Freeman
//  ��������:   ��������� ����� �����������
///////////////////////////////////////////////////////////
#pragma once

#include <fstream>

namespace Gepard 
{
    namespace Surfaces
    {
        /**
         *  ��������� ����� �����������
         */
        class QuadMap
        {
        public:

            QuadMap()
            {
                U0 = V0 = 0.0;
                U1 = V1 = 1.0;
                numU = numV = 10;
                closedU = closedV = false;
                stepU = stepV = 0.1;
            };

             /**
             * ����������� �� u
             */
            bool closedU;

            /**
             * ����������� �� v
             */
            bool closedV;

            /**
             *	����� ����� �� ���������
             */
            unsigned int numU, numV;

            /**
             *	���� �� ����� - � ������ ����������� �������
             */
            double stepU, stepV;
            /**
             *	����� ����������� (� ������ U = 0x1; V = 0x1;)
             */
            double U0, V0, U1, V1;

             /**
             * ���������� � ����
             */
            virtual void saveToFile(std::ostream& os)
            {
                os.write((char*) &closedU, sizeof closedU);
                os.write((char*) &closedV, sizeof closedV);
                os.write((char*) &numU,    sizeof numU);
                os.write((char*) &numV,    sizeof numV);
                os.write((char*) &stepU,   sizeof stepU);
                os.write((char*) &stepV,   sizeof stepV);
                os.write((char*) &U0,      sizeof U0);
                os.write((char*) &V0,      sizeof V0);
                os.write((char*) &U1,      sizeof U1);
                os.write((char*) &V1,      sizeof V1);
            }

            /**
             * ������ �� �����
             */
            virtual void readFromFile(std::istream& is)
            {
                is.read((char*) &closedU, sizeof closedU);
                is.read((char*) &closedV, sizeof closedV);
                is.read((char*) &numU,    sizeof numU);
                is.read((char*) &numV,    sizeof numV);
                is.read((char*) &stepU,   sizeof stepU);
                is.read((char*) &stepV,   sizeof stepV);
                is.read((char*) &U0,      sizeof U0);
                is.read((char*) &V0,      sizeof V0);
                is.read((char*) &U1,      sizeof U1);
                is.read((char*) &V1,      sizeof V1);
            }
            
        };
    };
};