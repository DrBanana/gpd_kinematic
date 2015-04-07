///////////////////////////////////////////////////////////
//  AssemblyStructure.cpp
//  Реализация 	Class AssemblyStructure
//  Создана:   	20-июл-2010 15:31:34
//  Автор: 		Freeman
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
         * Структура сборки - узел сборки
         */
        class AssemblyNode
        {
        public:
            typedef Gepard::General::basicTree<AssemblyNode>::basicTreeNodePtr asmTreeNodePtr;
            typedef AssemblyNode* AssemblyNodePtr;
        public:	
            /**
             * Уровень собрки
             */
            unsigned int level;

            /**
             * Уникальный номер узла - задается в порядке создания
             */
            unsigned int NodeNumber;

            /**
             * условия сопряжений
             */
            Gepard::Assembly::NodesMatingRelations nodesRelations;

            /**
             * Массив указателей на тела данного узла. (может быть узел-тело и узел-подсборка)
             */
            Gepard::Topology_Geometry::GPDSolidPtrList solids;

            /**
             * Репер данной подсборки (узла)
             * Если тел много, то данный репер равен реперу Первого тела
             */
            Gepard::BasicMath::GPDReper assmNodeReper;

            /**
            *	Указатель на узел дерева
            */
            asmTreeNodePtr treeNodePtr;			

            AssemblyNode();
            ~AssemblyNode();

            /**
             *	Вращать данный узел на угол fi относительно оси axis
             */
            void RotateNode(Gepard::BasicMath::GPDVector axis, double fi);

            /**
             *	Установить новый репер узла
             */
            void SetNodeReper(Gepard::BasicMath::GPDReper _nodeReper);                       
                    
            /**
             *  Сохранить данные узла в поток (кроме топологии и условий сопряжений)
             */
            void saveToFile(ostream &os);

            /**
             *  Загрузить данные узла из файла
             */
            void loadFromFile(istream &is, Gepard::MathModel* mathModelPtr);

            /**
             * Сохранить топологию узла в поток 
             */
            void saveNodeTopologyToFile(ostream &os);

            /**
             *  Загрузить топологию узла из потока
             */
            void loadNodeTopologyFromFile(istream &is, Gepard::MathModel* mathModelPtr);

            /**
             *  Удалить тело из узла
             */
            void DeleteSolid(Gepard::Topology_Geometry::GPDSolid* solPtr);

        private:
            /**
             *	Функция перевода заданных реперов тел в репер узла
             */
            void TransformGlobalToNode(Gepard::BasicMath::GPDReperList &repersList);

            /**
             *	Функция перевода заданных реперов тел в глобальный репер
             */
            void TransformNodeToGlobal(Gepard::BasicMath::GPDReperList &repersList);

            /**
             *  Заполнить массив реперов тел для данного Узла
             */
            void FillSolidsRepersList(Gepard::BasicMath::GPDReperList &repersList);

            /**
             *  Функция обновляет положение всех деталей по заданным новым реперам
             */
            void UpdateSolidsByRepers(Gepard::BasicMath::GPDReperList &repersList);

        };

        typedef Gepard::General::basicList<AssemblyNode*> AssemblyNodePtrList;
//-------------------------------------------------------------------------------------------------------------------------

        /**
         * Граф сборки - состоит из узлов
         */
        class AssemblyGraph : public Gepard::General::basicTree<AssemblyNode>
        {
        public:
            /**
             * Указатель на узел дерева
             */
            typedef basicTree<AssemblyNode>::basicTreeNodePtr asmTreeNodePtr;

            /**
             * Ссылка на узел дерева
             */
            typedef basicTree<AssemblyNode>::basicTreeNodeRef asmTreeNodeRef;

            /**
             * Узел дерева
             */
            typedef basicTree<AssemblyNode>::basicTreeNode asmTreeNode;

            /**
             * Итератор данного дерева
             */
            typedef basicTree<AssemblyNode>::bt_iterator as_iterator;

            /**
            * Массив указателей на узлы дерева
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
            *	Максимальный этап сборки - для контроля правильности задания
            */
            unsigned int maxAssemblyStage;

            /**
            *	Текущий узел дерева
            */
            asmTreeNodePtr currentNode;
           
            /**
            * Установить текущий узел в качестве корня дерева
            */
            void createRoot();

            /**
            * Получить текущий узел дерева
            */
            asmTreeNodePtr getCurrentNode()	{	return currentNode;	}

            /**
            *	Создать новый узел, не прицепляя его к дереву
            * Если AsmNode = NULL, создается пустой узел
            */
            asmTreeNodePtr createNewTreeNode(AssemblyNode *AsmNode=NULL);

            /**
            *  Добавить узел сборки к узлу дерева. Если узел дерева = NULL, добавляется к текущему узлу
            */
            asmTreeNodePtr addChildAssemblyNode(AssemblyNode *AsmNode, asmTreeNodePtr _asmTreeNodePtr=NULL);
            
            /**
            *	Создать шаг сборки и попробовать вставить его в дерево
            * Граф при этом может переформировываться, если порядок был нарушен
            * Новый узел будет подцепляться к parent-у базового узла
            */
            asmTreeNodePtr createNewAssemblyStep(asmTreeNodePtr baseTreeNodePtr, asmTreeNodePtr dependTreeNodePtr);
                      
            /**
            *	Удалить узел дерева. Все потомки подцепляются к предку. Возврат - указатель на предка
            */
            asmTreeNodePtr deleteTreeNode(asmTreeNodePtr _Node);
            
            /**
            *	Найти МАССИВ узлов дерева, где встречается данная деталь (отсортирован по убыванию уровня сборки)
            */
            //asmTreeNodePtrList findTreeNodes(Gepard::GPDSolid *_solid);
            void findTreeNodes(Gepard::Topology_Geometry::GPDSolid *_solid, asmTreeNodePtrList  &_asmTNPtrList);

            /**
            *	Автоматически назначить уровни сборки по умолчанию во всем графе
            */
            void createAssemblyLevels();

            /**
             *  Применить условие сопряжения
             *  Возврат - сформированный узел
             */
            AssemblyNode* ApplyMatingRelation(Gepard::Assembly::MatingRelation &matingRelation);

            /**
             *  Отменить условие сопряжения
             */
            void DropMatingRelation( AssemblyNode* nodePtr, Gepard::Assembly::MatingRelation &matingRelation );

            /**
             *  Установить указатель на мат. модель
             */
            void setMathModel(Gepard::MathModel *mathModelPtr);

            /**
             *  Сохранить граф в поток
             */
            void saveToFile(std::ostream& os);

            /**
             *  Загрузить граф сборки из потока
             */
            void loadFromFile(std::istream& is);
            
            /**
             *  Удалить деталь (узел) из графа сборки
             */
            void DeleteSolid(Gepard::Topology_Geometry::GPDSolid *_solid);

            /**
             *  Удалить условие сопряжения
             */
            void DeleteMatingRelation(Gepard::Assembly::MatingRelation *mrPtr);

        private:
            /**
            * Сформировать третий узел (предок двух данных) - сюда копируются указатели на детали.
            * Новый узел не добавляется в дерево!
            */
            asmTreeNodePtr createParentTreeNode(asmTreeNodePtr baseTreeNodePtr, asmTreeNodePtr dependTreeNodePtr);

            /**
            *	Проверка на общего предка кроме ROOT
            */
            bool checkParents(asmTreeNodePtr baseTreeNodePtr, asmTreeNodePtr dependTreeNodePtr);


            /**
            * Добавить детали в граф сборки - начиная от заданного узла и выше
            */
            void addSolidsToAsseblyGraph(asmTreeNodePtr fromTreeNodePtr);

            /**
            * Удалить детали из графа сборки - начиная от заданного узла и выше
            */
            void deleteSolidsFromAssemblyGraph(asmTreeNodePtr fromTreeNodePtr);

            /**
            *	Установить потомка для всех предков
            */
            void setChildrensParent(asmTreeNodePtr _NodePtr, asmTreeNodePtr _NewParent);
            
            /**
             *	Получить номер узла графа сборки
             */
            unsigned int getLastNodeNum();            

            /**
             *  Родительская математическая модель
             */
            Gepard::MathModel *mathModel;

        
        protected:

            /**
            *	Переформировать уровни всего графа сборки
            */
            void updateAssemblyLevels(asmTreeNodePtr _NodePtr, int curLevel);

            /**
             *	Последний созданный номер узла
             */
            unsigned int LastNodeNumber;

        };


//-------------------------------------------------------------------------------------------------------------------------

    }

}
#endif // !defined(EA_C081D8AF_827D_4686_B9C6_C401F2A61E9B__INCLUDED_)
