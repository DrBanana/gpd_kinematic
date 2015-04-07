///////////////////////////////////////////////////////////
//  StepFuncs.h
//  Создано:    19-фев-2015 14:22
//  Автор:      Dr_Freeman
//  Описание:   Дополнительные функции для чтения STEP, 
//              с использованием StepCode
///////////////////////////////////////////////////////////

#ifndef STEPFUNCS_H
#define STEPFUNCS_H

#include <STEPfile.h>
#include <STEPcomplex.h>
#include <STEPaggregate.h>

#include "StepDefines.h"
#include "../BasicMath/basicGPDVector.h"


namespace Gepard 
{
    namespace STEP 
    {
        using namespace Gepard::BasicMath;

        /**
        *  Получить массив типа double
        */
        void GetReals(RealAggregate *R_AGGR, step_Doubles_Vector&_dArray);

        /**
        *  Получить массив типов int
        */
        void GetInts(IntAggregate *I_AGGR, step_Ints_Vector &_iArray);

        /**
        *  Установить координаты точки/вектора
        */
        void SetVecCoords(RealAggregate *R_AGGR, basicGPDVector *vec);      

        /**
         *	Получить аттрибут по имени
         */
        STEPattribute* GetAttribute(STEPentity *_entity, const char *name);

        /**
         *	Получить список сущностей
         */
        void GetListOfEntities(STEPentity *_entity, const char *name, step_Entity_List &ent_list);

        /**
        *	Получить список сущностей
        */
        void GetListOfEntities(EntityAggregate_ptr ent_aggr, step_Entity_List &ent_list);

        /**
         *	Получить дерево супертипов
         */
        void GetSuperTypesMap(STEPentity *_entity, step_Map_of_Supertypes &m);

        /**
         *	Получить супертип по имени
         */
        STEPentity* GetSuperType(STEPentity *_entity, const char *name);

        /**
        *	Получить список селектов
        */
        void GetListOfSelects(STEPentity *_entity, const char *name, step_Selects_List &sel_list);

    }
}



#endif // !STEPFUNCS_H