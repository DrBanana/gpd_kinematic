///////////////////////////////////////////////////////////
//  MatingRelation.cpp
//  Реализация 	Class MatingRelation
//  Создана:   	20-июл-2010 15:12:00
//  Автор: 		Freeman
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
         * Условия сопряжений
         */
        class MatingRelation
        {

        public:
            MatingRelation(bool useRelationForAnalisys = true);
            ~MatingRelation();

            /**
            *  Базовая поверхность - неподвижная
            */
            Gepard::Topology_Geometry::GPDFacePtr BaseFace;

            /**
            *  Зависимая поверхность - двигаем к Базовой
            */
            Gepard::Topology_Geometry::GPDFacePtr DependFace;

            /**
             * Тип сопряжения
             */
            Gepard::Assembly::MatingRelationType TypeRelation;

            /**
             * Совпадение осей
             */
            MRAxesDirection axesDirection;
                        
            /**
             *	Используется ли данное условие при анализе 
             *	false - значит это условие нужно только для расчета номинального положения
             */
            bool isUsedForAnalysis;

            /**
             *	Используется ли данное условие при расчете номинального положения
             *	если условие не используется при анализе и не используется при расчете ном. пол.
             *  то оно не нужно. Либо пользователь его на время отключил
             */
            bool isUsedForNominalPosition;

            /**
             *  Родительский класс - условия сопряжений для узла
             */
            NodesMatingRelations* parentNodesRelations;

            /**
             *  Номер условия сопряжения
             */
            unsigned int UIN;

            /**
             *	Получить название условия сопряжения
             */
            static std::string toString(Gepard::Assembly::MatingRelationType MR_relation_type);

            /**
             *  Получить название - совпадение осей (в зависимости от типа условия)
             */
            static std::string toString( Gepard::Assembly::MatingRelationType MR_relation_type, 
                                         Gepard::Assembly::MRAxesDirection axes_direction);

            /**
             *  Получить список поддерживаемых типов условий сопряжений для данных граней
             */
            static std::list<Gepard::Assembly::MatingRelationType>
                GetMatingRelationTypes( Gepard::Topology_Geometry::GPDFacePtr _baseFace,
                                        Gepard::Topology_Geometry::GPDFacePtr _dependFace );

            /**
             *  Очистить параметры условия сопряжения  
             */
            void Clear();

            /**
             *  Оператор сравнения условий сопряжений
             */
            bool operator==(MatingRelation &mr);

            /**
             *  Сохранить в файл
             */
            void saveToFile(ostream &os);

            /**
             *  Загрузить из файла
             */
            void loadFromFile(istream &is, Gepard::MathModel *mathModelPtr);

        };

        typedef MatingRelation* MatingRelationPtr;		
        typedef Gepard::General::basicList<MatingRelationPtr> MatingRelationPtrList;

    }

}
#endif // !defined(EA_C35EF362_C727_4c43_89B4_812D3FC6BCF3__INCLUDED_)
