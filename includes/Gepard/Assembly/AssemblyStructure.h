///////////////////////////////////////////////////////////
//  AssemblyStructure.cpp
//  ���������� 	Class AssemblyStructure
//  �������:   	20-���-2010 15:31:34
//  �����: 		Freeman
///////////////////////////////////////////////////////////

#if !defined(EA_C081D8AF_827D_4686_B9C6_C401F2A61E9B__INCLUDED_)
#define EA_C081D8AF_827D_4686_B9C6_C401F2A61E9B__INCLUDED_


#include "NodesMatingRelations.h"
#include "../Topology_geometry/GPDSolid.h"
#include "../BasicMath/GPDReper.h"
//#include "../Tolerances/ToleranceArray.h"
#include "../General/basicTree.h"
#include "../General/basicList.h"
//#include "ImitationStage.h"


namespace Gepard
{	
    class MathModel;

    namespace Assembly
    {
        /**
         * ��������� ������ - ���� ������
         */
        class AssemblyNode
        {
        public:
            typedef Gepard::General::basicTree<AssemblyNode>::basicTreeNodePtr asmTreeNodePtr;
            typedef AssemblyNode* AssemblyNodePtr;
        public:	
            /**
             * ������� ������
             */
            unsigned int level;

            /**
             * ���������� ����� ���� - �������� � ������� ��������
             */
            unsigned int NodeNumber;

            /**
             * ������� ����������
             */
            Gepard::Assembly::NodesMatingRelations nodesRelations;

            /**
             * ������ ���������� �� ���� ������� ����. (����� ���� ����-���� � ����-���������)
             */
            Gepard::Topology_Geometry::GPDSolidPtrList solids;

            /**
             * ����� ������ ��������� (����)
             * ���� ��� �����, �� ������ ����� ����� ������ ������� ����
             */
            Gepard::BasicMath::GPDReper assmNodeReper;

            /**
            *	��������� �� ���� ������
            */
            asmTreeNodePtr treeNodePtr;			

            AssemblyNode();
            ~AssemblyNode();

            /**
             *	������� ������ ���� �� ���� fi ������������ ��� axis
             */
            void RotateNode(Gepard::BasicMath::GPDVector axis, double fi);

            /**
             *	���������� ����� ����� ����
             */
            void SetNodeReper(Gepard::BasicMath::GPDReper _nodeReper);                       
                    
            /**
             *  ��������� ������ ���� � ����� (����� ��������� � ������� ����������)
             */
            void saveToFile(ostream &os);

            /**
             *  ��������� ������ ���� �� �����
             */
            void loadFromFile(istream &is, Gepard::MathModel* mathModelPtr);

            /**
             * ��������� ��������� ���� � ����� 
             */
            void saveNodeTopologyToFile(ostream &os);

            /**
             *  ��������� ��������� ���� �� ������
             */
            void loadNodeTopologyFromFile(istream &is, Gepard::MathModel* mathModelPtr);

            /**
             *  ������� ���� �� ����
             */
            void DeleteSolid(Gepard::Topology_Geometry::GPDSolid* solPtr);

        private:
            /**
             *	������� �������� �������� ������� ��� � ����� ����
             */
            void TransformGlobalToNode(Gepard::BasicMath::GPDReperList &repersList);

            /**
             *	������� �������� �������� ������� ��� � ���������� �����
             */
            void TransformNodeToGlobal(Gepard::BasicMath::GPDReperList &repersList);

            /**
             *  ��������� ������ ������� ��� ��� ������� ����
             */
            void FillSolidsRepersList(Gepard::BasicMath::GPDReperList &repersList);

            /**
             *  ������� ��������� ��������� ���� ������� �� �������� ����� �������
             */
            void UpdateSolidsByRepers(Gepard::BasicMath::GPDReperList &repersList);

        };

        typedef Gepard::General::basicList<AssemblyNode*> AssemblyNodePtrList;
//-------------------------------------------------------------------------------------------------------------------------

        /**
         * ���� ������ - ������� �� �����
         */
        class AssemblyGraph : public Gepard::General::basicTree<AssemblyNode>
        {
        public:
            /**
             * ��������� �� ���� ������
             */
            typedef basicTree<AssemblyNode>::basicTreeNodePtr asmTreeNodePtr;

            /**
             * ������ �� ���� ������
             */
            typedef basicTree<AssemblyNode>::basicTreeNodeRef asmTreeNodeRef;

            /**
             * ���� ������
             */
            typedef basicTree<AssemblyNode>::basicTreeNode asmTreeNode;

            /**
             * �������� ������� ������
             */
            typedef basicTree<AssemblyNode>::bt_iterator as_iterator;

            /**
            * ������ ���������� �� ���� ������
            */
            class asmTreeNodePtrList: public Gepard::General::basicList<asmTreeNodePtr>
            {
            public:
                asmTreeNodePtrList(){};
                ~asmTreeNodePtrList(){};
            };


        public:
            AssemblyGraph();
            ~AssemblyGraph();

            /**
            *	������������ ���� ������ - ��� �������� ������������ �������
            */
            unsigned int maxAssemblyStage;

            /**
            *	������� ���� ������
            */
            asmTreeNodePtr currentNode;
           
            /**
            * ���������� ������� ���� � �������� ����� ������
            */
            void createRoot();

            /**
            * �������� ������� ���� ������
            */
            asmTreeNodePtr getCurrentNode()	{	return currentNode;	}

            /**
            *	������� ����� ����, �� ��������� ��� � ������
            * ���� AsmNode = NULL, ��������� ������ ����
            */
            asmTreeNodePtr createNewTreeNode(AssemblyNode *AsmNode=NULL);

            /**
            *  �������� ���� ������ � ���� ������. ���� ���� ������ = NULL, ����������� � �������� ����
            */
            asmTreeNodePtr addChildAssemblyNode(AssemblyNode *AsmNode, asmTreeNodePtr _asmTreeNodePtr=NULL);
            
            /**
            *	������� ��� ������ � ����������� �������� ��� � ������
            * ���� ��� ���� ����� �������������������, ���� ������� ��� �������
            * ����� ���� ����� ������������ � parent-� �������� ����
            */
            asmTreeNodePtr createNewAssemblyStep(asmTreeNodePtr baseTreeNodePtr, asmTreeNodePtr dependTreeNodePtr);
                      
            /**
            *	������� ���� ������. ��� ������� ������������ � ������. ������� - ��������� �� ������
            */
            asmTreeNodePtr deleteTreeNode(asmTreeNodePtr _Node);
            
            /**
            *	����� ������ ����� ������, ��� ����������� ������ ������ (������������ �� �������� ������ ������)
            */
            //asmTreeNodePtrList findTreeNodes(Gepard::GPDSolid *_solid);
            void findTreeNodes(Gepard::Topology_Geometry::GPDSolid *_solid, asmTreeNodePtrList  &_asmTNPtrList);

            /**
            *	������������� ��������� ������ ������ �� ��������� �� ���� �����
            */
            void createAssemblyLevels();

            /**
             *  ��������� ������� ����������
             *  ������� - �������������� ����
             */
            AssemblyNode* ApplyMatingRelation(Gepard::Assembly::MatingRelation &matingRelation);

            /**
             *  �������� ������� ����������
             */
            void DropMatingRelation( AssemblyNode* nodePtr, Gepard::Assembly::MatingRelation &matingRelation );

            /**
             *  ���������� ��������� �� ���. ������
             */
            void setMathModel(Gepard::MathModel *mathModelPtr);

            /**
             *  ��������� ���� � �����
             */
            void saveToFile(std::ostream& os);

            /**
             *  ��������� ���� ������ �� ������
             */
            void loadFromFile(std::istream& is);
            
            /**
             *  ������� ������ (����) �� ����� ������
             */
            void DeleteSolid(Gepard::Topology_Geometry::GPDSolid *_solid);

            /**
             *  ������� ������� ����������
             */
            void DeleteMatingRelation(Gepard::Assembly::MatingRelation *mrPtr);

        private:
            /**
            * ������������ ������ ���� (������ ���� ������) - ���� ���������� ��������� �� ������.
            * ����� ���� �� ����������� � ������!
            */
            asmTreeNodePtr createParentTreeNode(asmTreeNodePtr baseTreeNodePtr, asmTreeNodePtr dependTreeNodePtr);

            /**
            *	�������� �� ������ ������ ����� ROOT
            */
            bool checkParents(asmTreeNodePtr baseTreeNodePtr, asmTreeNodePtr dependTreeNodePtr);


            /**
            * �������� ������ � ���� ������ - ������� �� ��������� ���� � ����
            */
            void addSolidsToAsseblyGraph(asmTreeNodePtr fromTreeNodePtr);

            /**
            * ������� ������ �� ����� ������ - ������� �� ��������� ���� � ����
            */
            void deleteSolidsFromAssemblyGraph(asmTreeNodePtr fromTreeNodePtr);

            /**
            *	���������� ������� ��� ���� �������
            */
            void setChildrensParent(asmTreeNodePtr _NodePtr, asmTreeNodePtr _NewParent);
            
            /**
             *	�������� ����� ���� ����� ������
             */
            unsigned int getLastNodeNum();            

            /**
             *  ������������ �������������� ������
             */
            Gepard::MathModel *mathModel;

        
        protected:

            /**
            *	��������������� ������ ����� ����� ������
            */
            void updateAssemblyLevels(asmTreeNodePtr _NodePtr, int curLevel);

            /**
             *	��������� ��������� ����� ����
             */
            unsigned int LastNodeNumber;

        };


//-------------------------------------------------------------------------------------------------------------------------

    }

}
#endif // !defined(EA_C081D8AF_827D_4686_B9C6_C401F2A61E9B__INCLUDED_)
