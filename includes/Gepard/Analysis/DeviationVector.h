///////////////////////////////////////////////////////////
//  DeviationVector.h
//  ������ ����������
//  �������:  13-���-2014
//	������������ �����: Anton
///////////////////////////////////////////////////////////

#ifndef DEVIATIONVECTOR_H
#define DEVIATIONVECTOR_H

#include "../BasicMath/GPDPoint.h"
#include "../BasicMath/GPDVector.h"
#include "../General/basicList.h"
#include "../General/basicArray.h"

#include <fstream>

namespace Gepard 
{
    namespace Analysis
    {
        using namespace std;

        /**
         *  ��� ������� ����������
         */
        enum DV_TYPE { UNKNOWN, CLEARANCE, INTERSECTION };
        

        /**
         *  ��������� ������� ����������
         */
        struct DeviationVector
        {
            DeviationVector()
            {
                _type = UNKNOWN;
            }

            DeviationVector( Gepard::BasicMath::GPDPoint _bp,
                             Gepard::BasicMath::GPDPoint _dp, 
                             DV_TYPE _t = UNKNOWN )
            : bP(_bp), dP(_dp), _type(_t)
            { }

            /**
             *  ��� �������
             */
            DV_TYPE _type;

            /**
             *  ����� �� ������� �����
             */
            Gepard::BasicMath::GPDPoint bP;

            /**
             *  ����� �� ��������� �����
             */
            Gepard::BasicMath::GPDPoint dP;

            /**
             *  �������� ������ ����������
             */
            Gepard::BasicMath::GPDVector V()
            {                
                return Gepard::BasicMath::GPDVector( dP.x - bP.x, dP.y - bP.y, dP.z - bP.z );
            }

            /**
             *  ��������
             */
            void setNull()
            {
                bP.setNull();
                dP.setNull();
                _type = UNKNOWN;
            }

            /**
             *  ������������� �������� ������
             */
            friend ostream& operator<<(ostream& os, const DeviationVector &dv)
            {
                os.write((char *) &dv._type, sizeof dv._type);
                os << dv.bP;
                os << dv.dP;
                return os;
            }

             /**
             *  ������������� �������� �����
             */
            friend istream& operator>>(istream& is, DeviationVector &dv)
            {
                is.read((char *) &dv._type, sizeof dv._type);
                is >> dv.bP;
                is >> dv.dP;
                return is;
            }

        };

        typedef Gepard::General::basicArray<Gepard::Analysis::DeviationVector> DeviationVectorArray;
        typedef Gepard::General::basicList<Gepard::Analysis::DeviationVector>  DeviationVectorList;

        /**
         *  ������ �������� ���������� � ������ ����� �.�.
         */
        typedef Gepard::General::basicList<DeviationVectorList> DeviationVectorsLists;

    }//Analysis
}//Gepard

#endif