///////////////////////////////////////////////////////////
//  NodesMatingRelations.cpp
//  ���������� 	Class NodesMatingRelations
//  �������:   	20-���-2010 15:24:36
//  �����: 		Dr_Freeman
///////////////////////////////////////////////////////////

#if !defined(EA_050A250A_B220_448d_AF75_581F5ED2F6B5__INCLUDED_)
#define EA_050A250A_B220_448d_AF75_581F5ED2F6B5__INCLUDED_

#include "FixingRelationArray.h"
#include "MatingRelationArray.h"

#include <fstream>

namespace Gepard
{
    class MathModel;

    namespace Assembly
    {
        /**
         * ������� ���������� �����
         */
        class AssemblyNode;
        class NodesMatingRelations
        {

        public:
            NodesMatingRelations();
            ~NodesMatingRelations();
            /**
             * ��������� �� ������� ����
             */
            Gepard::Assembly::AssemblyNode *baseNode;
            /**
             * ��������� �� ��������� ����
             */
            Gepard::Assembly::AssemblyNode *dependNode;

            /**
             *  ��������� �� ������������ ����
             */
            Gepard::Assembly::AssemblyNode *parentNode;

            /**
             * ������� ���������� ���������� ������������ �����. �� ���� ������ �����������
             * 1)����������� ��������� �����, 2) ������� ������ ��� ��������
             */
            Gepard::Assembly::MatingRelationList matingRelations;
        
            /**
             * �������������� ������� ��� ���������� ������ 
             * ��� ���������� ������������ ��������� �� �������� ����������
             */
            Gepard::Assembly::FixingRelationArray fixingMatingRelations;

            /**
             *	���������� ������������ ��������� ���������� ���� (� ��������), 
             *  � ����������� �� ���������� ����������
             *  ��������� ��� ��������� ����������, ������� � start_mr_index
             */
            int CalcDependNominalPosition(unsigned int start_mr_index = 0);

            /**
             *  �������� ��������� ���������� ������������ ���������
             *  ���� isReturnToNominal=true - ������� ����������� ��������
             */
            void CancelLastNodeMove(bool isReturnToNominal=false);

            /**
             *  �������� ��������� ������� ����������
             */
            void DropMatingRelation(Gepard::Assembly::MatingRelation &matingRelation);

            /**
             *  ����� ������� ����������
             */
            int FindMatingRelation(Gepard::Assembly::MatingRelation &matingRelation);

            /**
             *  ����� ������� ���������� �� UIN
             */
            Gepard::Assembly::MatingRelation* FindMatingRelationByUIN(unsigned int mr_uin);

            /**
             *  ������� ������� ����������, ��������� � �������
             */
            void DeleteSolid(Gepard::Topology_Geometry::GPDSolid *solPtr);

            /**
             *  ������� ������e ����������
             */
            void DeleteMatingRelation(Gepard::Assembly::MatingRelation *mrPtr);

            /**
             *  �������� ����������� ����� ����
             */
            Gepard::BasicMath::GPDReper GetNominalNodeReper();

            /**
             *  ��������� � ����
             */
            void saveToFile(ostream &os);
          
            /**
             *  ��������� ������ �� �����
             */
            void loadFromFile(istream &is, Gepard::MathModel *mathModelPtr);

        private:

            /**
             *  ����������� ����� ���������� ����
             */
            //Gepard::BasicMath::GPDReper DependNominalReper;

            /**
             *  ������ ���������� ������� ���������� ���� (� ��� ����� ����������� - 0)
             */
            Gepard::BasicMath::GPDReperList DependReperList;

            /**
             *  �������� ����� ������� �����������
             */
            void GetBaseReper(MatingRelation *_matingRelation, Gepard::BasicMath::GPDReper &reper);

            /**
             *  �������� ����� ��������� �����������
             */
            void GetDependReper(MatingRelation *_matingRelation, Gepard::BasicMath::GPDReper &reper);


            /**
             *	������� ��������� ��� N � ���� �������� fi �� ������ ������� ���������� � ���� �������
             *	���� ��������� false - ���������� ����� ���
             */
            bool CalcRotationalAngleAndAxis( MatingRelation *_matingRelation,
                                             Gepard::BasicMath::GPDVector &N, double &fi );


            /**
             *	������� ��������� ��� N � ���� fi �� ������� ������� ���������� � ��� ��������� ������
             *	(������������ ��� ��������+�������� ����)
             */
            void CalcTranslationalAngleAndAxis(	MatingRelation *_matingRelation, 
                                                Gepard::BasicMath::GPDReperPtr _reperPtr,
                                                Gepard::BasicMath::GPDVector &N, double &fi);

            /**
             *	������� ������ ��� ��������������
             *  true - ��� �������
             */
            bool CalcInvertAxis(Gepard::BasicMath::GPDVector reper_axis, Gepard::BasicMath::GPDVector &rotate_axis);

            /**
             *	������� �������� ������ ��� �� ����������� �������� �� ���� fi
             *	true - ����� �������	
             */
            bool CheckRotationAxis(MatingRelation *_matingRelation, Gepard::BasicMath::GPDVector _axis, double fi);

            /**
             *	����� �����(� �������� �����������) � ��������� ���� �� �������� ���� fi ������������ ��� axis
             */
            void FindReperAndRotateNode(Gepard::BasicMath::GPDReper rotational_reper, 
                                        Gepard::BasicMath::GPDVector axis, double fi);

            /**
             *	������� ������ ������ ��� �������� � �������� �����������
             */
            bool FindRotationalReper(Gepard::BasicMath::GPDVector axis, double fi, Gepard::BasicMath::GPDReper &_reper);

            /**
             *	������� ��������� ���� �� ���� fi ������������ ��� axis ������ reper
             */
            void RotateNode(Gepard::Assembly::AssemblyNode *Node, 
                            Gepard::BasicMath::GPDReper rotational_reper, 
                            Gepard::BasicMath::GPDVector axis, double fi);
            /**
             *	������� ������ ���� �� �������� ������
             */
            void MoveNode(Gepard::Assembly::AssemblyNode *Node,Gepard::BasicMath::GPDVector dir_vector);

            /**
             *	������� ����������� ��������� �������
             */
            bool CheckRotationalTranslation(Gepard::BasicMath::GPDReper _reper, Gepard::BasicMath::GPDVector _axis, double fi);

            /**
             *	������� ��������� ������ ������ ��� �������� ������� ����������
             *  ���� ����� _reper - ������������ ����
             */
            Gepard::BasicMath::GPDVector GetDirectoryVector(MatingRelation *_matingRelation);
            /**
             *	������� �������� ��� ������ ���� �� ������ � ������ ������� ����������� 
             */
            void MoveOrRotateNodeByVector(Gepard::Assembly::AssemblyNode *Node, MatingRelation *_matingRelation);

            /**
             *	������� ������� ������� ����������� ��� ������� ������� ����������
             */
            void CreateFixingRelation(MatingRelation *_matingRelation);

            /**
             *  ������� ������� ����������� 
             */
            void DeleteFixingRelations();

        };

    }

}
#endif // !defined(EA_050A250A_B220_448d_AF75_581F5ED2F6B5__INCLUDED_)
