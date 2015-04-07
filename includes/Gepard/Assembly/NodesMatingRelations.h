///////////////////////////////////////////////////////////
//  NodesMatingRelations.cpp
//  Реализация 	Class NodesMatingRelations
//  Создана:   	20-июл-2010 15:24:36
//  Автор: 		Dr_Freeman
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
         * Условия сопряжений узлов
         */
        class AssemblyNode;
        class NodesMatingRelations
        {

        public:
            NodesMatingRelations();
            ~NodesMatingRelations();
            /**
             * Указатель на базовый узел
             */
            Gepard::Assembly::AssemblyNode *baseNode;
            /**
             * указатель на зависимый узел
             */
            Gepard::Assembly::AssemblyNode *dependNode;

            /**
             *  Указатель на родительский узел
             */
            Gepard::Assembly::AssemblyNode *parentNode;

            /**
             * Условия сопряжений конкретных поверхностей узлов. По этим данным вычисляются
             * 1)Номинальные положения узлов, 2) векторы сдвига при имитации
             */
            Gepard::Assembly::MatingRelationList matingRelations;
        
            /**
             * ограничивающие условия для зависимого репера 
             * при вычислении номинального положения по условиям сопряжений
             */
            Gepard::Assembly::FixingRelationArray fixingMatingRelations;

            /**
             *	Вычисление номинального положения зависимого узла (в заданном), 
             *  в зависимости от параметров сопряжений
             *  Учитывать все параметры сопряжений, начиная с start_mr_index
             */
            int CalcDependNominalPosition(unsigned int start_mr_index = 0);

            /**
             *  Отменить последнее вычисление номинального положения
             *  Если isReturnToNominal=true - вернуть номинальные значения
             */
            void CancelLastNodeMove(bool isReturnToNominal=false);

            /**
             *  Отменить указанное условие сопряжения
             */
            void DropMatingRelation(Gepard::Assembly::MatingRelation &matingRelation);

            /**
             *  Найти условие сопряжения
             */
            int FindMatingRelation(Gepard::Assembly::MatingRelation &matingRelation);

            /**
             *  Найти условие сопряжения по UIN
             */
            Gepard::Assembly::MatingRelation* FindMatingRelationByUIN(unsigned int mr_uin);

            /**
             *  Удалить условия сопряжений, связанных с деталью
             */
            void DeleteSolid(Gepard::Topology_Geometry::GPDSolid *solPtr);

            /**
             *  Удалить условиe сопряжения
             */
            void DeleteMatingRelation(Gepard::Assembly::MatingRelation *mrPtr);

            /**
             *  Получить номинальный репер узла
             */
            Gepard::BasicMath::GPDReper GetNominalNodeReper();

            /**
             *  Сохранить в файл
             */
            void saveToFile(ostream &os);
          
            /**
             *  Загрузить данные из файла
             */
            void loadFromFile(istream &is, Gepard::MathModel *mathModelPtr);

        private:

            /**
             *  Номинальный репер зависимого узла
             */
            //Gepard::BasicMath::GPDReper DependNominalReper;

            /**
             *  Массив предыдущих реперов зависимого узла (в том числе номинальный - 0)
             */
            Gepard::BasicMath::GPDReperList DependReperList;

            /**
             *  Получить репер базовой поверхности
             */
            void GetBaseReper(MatingRelation *_matingRelation, Gepard::BasicMath::GPDReper &reper);

            /**
             *  Получить репер зависимой поверхности
             */
            void GetDependReper(MatingRelation *_matingRelation, Gepard::BasicMath::GPDReper &reper);


            /**
             *	Функция вычисляет ось N и угол поворота fi по данным условия сопряжения и двум реперам
             *	Если вернулось false - невозможно найти ось
             */
            bool CalcRotationalAngleAndAxis( MatingRelation *_matingRelation,
                                             Gepard::BasicMath::GPDVector &N, double &fi );


            /**
             *	Функция вычисляет ось N и угол fi по данному условию сопряжения и для заданного репера
             *	(Используется для переноса+поворота тела)
             */
            void CalcTranslationalAngleAndAxis(	MatingRelation *_matingRelation, 
                                                Gepard::BasicMath::GPDReperPtr _reperPtr,
                                                Gepard::BasicMath::GPDVector &N, double &fi);

            /**
             *	Функция поиска оси инвертирования
             *  true - ось найдена
             */
            bool CalcInvertAxis(Gepard::BasicMath::GPDVector reper_axis, Gepard::BasicMath::GPDVector &rotate_axis);

            /**
             *	Функция проверки данной оси на возможность поворота на угол fi
             *	true - можно вращать	
             */
            bool CheckRotationAxis(MatingRelation *_matingRelation, Gepard::BasicMath::GPDVector _axis, double fi);

            /**
             *	Найти репер(в условиях закреплений) и повернуть узел на заданный угол fi относительно оси axis
             */
            void FindReperAndRotateNode(Gepard::BasicMath::GPDReper rotational_reper, 
                                        Gepard::BasicMath::GPDVector axis, double fi);

            /**
             *	Функция поиска репера для поворота в условиях закреплений
             */
            bool FindRotationalReper(Gepard::BasicMath::GPDVector axis, double fi, Gepard::BasicMath::GPDReper &_reper);

            /**
             *	Поворот заданного узла на угол fi относительно оси axis репера reper
             */
            void RotateNode(Gepard::Assembly::AssemblyNode *Node, 
                            Gepard::BasicMath::GPDReper rotational_reper, 
                            Gepard::BasicMath::GPDVector axis, double fi);
            /**
             *	Функция сдвига узла на заданный вектор
             */
            void MoveNode(Gepard::Assembly::AssemblyNode *Node,Gepard::BasicMath::GPDVector dir_vector);

            /**
             *	Функция определения нарушения сдвигов
             */
            bool CheckRotationalTranslation(Gepard::BasicMath::GPDReper _reper, Gepard::BasicMath::GPDVector _axis, double fi);

            /**
             *	Функция вычисляет вектор сдвига для текущего условия сопряжения
             *  если задан _reper - относительно него
             */
            Gepard::BasicMath::GPDVector GetDirectoryVector(MatingRelation *_matingRelation);
            /**
             *	Функция поворота или сдвига узла на вектор с учетом условий закреплений 
             */
            void MoveOrRotateNodeByVector(Gepard::Assembly::AssemblyNode *Node, MatingRelation *_matingRelation);

            /**
             *	Функция создает условие закрепления для данного условия сопряжения
             */
            void CreateFixingRelation(MatingRelation *_matingRelation);

            /**
             *  Удалить условия закреплений 
             */
            void DeleteFixingRelations();

        };

    }

}
#endif // !defined(EA_050A250A_B220_448d_AF75_581F5ED2F6B5__INCLUDED_)
