///////////////////////////////////////////////////////////
//  MatingRelation.cpp
//  ���������� 	Class MatingRelation
//  �������:   	20-���-2010 15:12:00
//  �����: 		Freeman
///////////////////////////////////////////////////////////

#if !defined(EA_C35EF362_C727_4c43_89B4_812D3FC6BCF3__INCLUDED_)
#define EA_C35EF362_C727_4c43_89B4_812D3FC6BCF3__INCLUDED_

#include "../Surfaces/GPDSurface.h"
#include "../Topology_geometry/GPDFace.h"
#include "MatingRelationType.h"

#include <fstream>

using namespace std;

namespace Gepard
{
    class MathModel;

    namespace Assembly
    {
        class NodesMatingRelations;

        /**
         * ������� ����������
         */
        class MatingRelation
        {

        public:
            MatingRelation(bool useRelationForAnalisys = true);
            ~MatingRelation();

            /**
            *  ������� ����������� - �����������
            */
            Gepard::Topology_Geometry::GPDFacePtr BaseFace;

            /**
            *  ��������� ����������� - ������� � �������
            */
            Gepard::Topology_Geometry::GPDFacePtr DependFace;

            /**
             * ��� ����������
             */
            Gepard::Assembly::MatingRelationType TypeRelation;

            /**
             * ���������� ����
             */
            MRAxesDirection axesDirection;
                        
            /**
             *	������������ �� ������ ������� ��� ������� 
             *	false - ������ ��� ������� ����� ������ ��� ������� ������������ ���������
             */
            bool isUsedForAnalysis;

            /**
             *	������������ �� ������ ������� ��� ������� ������������ ���������
             *	���� ������� �� ������������ ��� ������� � �� ������������ ��� ������� ���. ���.
             *  �� ��� �� �����. ���� ������������ ��� �� ����� ��������
             */
            bool isUsedForNominalPosition;

            /**
             *  ������������ ����� - ������� ���������� ��� ����
             */
            NodesMatingRelations* parentNodesRelations;

            /**
             *  ����� ������� ����������
             */
            unsigned int UIN;

            /**
             *	�������� �������� ������� ����������
             */
            static std::string toString(Gepard::Assembly::MatingRelationType MR_relation_type);

            /**
             *  �������� �������� - ���������� ���� (� ����������� �� ���� �������)
             */
            static std::string toString( Gepard::Assembly::MatingRelationType MR_relation_type, 
                                         Gepard::Assembly::MRAxesDirection axes_direction);

            /**
             *  �������� ������ �������������� ����� ������� ���������� ��� ������ ������
             */
            static std::list<Gepard::Assembly::MatingRelationType>
                GetMatingRelationTypes( Gepard::Topology_Geometry::GPDFacePtr _baseFace,
                                        Gepard::Topology_Geometry::GPDFacePtr _dependFace );

            /**
             *  �������� ��������� ������� ����������  
             */
            void Clear();

            /**
             *  �������� ��������� ������� ����������
             */
            bool operator==(MatingRelation &mr);

            /**
             *  ��������� � ����
             */
            void saveToFile(ostream &os);

            /**
             *  ��������� �� �����
             */
            void loadFromFile(istream &is, Gepard::MathModel *mathModelPtr);

        };

        typedef MatingRelation* MatingRelationPtr;		
        typedef Gepard::General::basicList<MatingRelationPtr> MatingRelationPtrList;

    }

}
#endif // !defined(EA_C35EF362_C727_4c43_89B4_812D3FC6BCF3__INCLUDED_)
