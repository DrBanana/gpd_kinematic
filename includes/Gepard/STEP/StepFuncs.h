///////////////////////////////////////////////////////////
//  StepFuncs.h
//  �������:    19-���-2015 14:22
//  �����:      Dr_Freeman
//  ��������:   �������������� ������� ��� ������ STEP, 
//              � �������������� StepCode
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
        *  �������� ������ ���� double
        */
        void GetReals(RealAggregate *R_AGGR, step_Doubles_Vector&_dArray);

        /**
        *  �������� ������ ����� int
        */
        void GetInts(IntAggregate *I_AGGR, step_Ints_Vector &_iArray);

        /**
        *  ���������� ���������� �����/�������
        */
        void SetVecCoords(RealAggregate *R_AGGR, basicGPDVector *vec);      

        /**
         *	�������� �������� �� �����
         */
        STEPattribute* GetAttribute(STEPentity *_entity, const char *name);

        /**
         *	�������� ������ ���������
         */
        void GetListOfEntities(STEPentity *_entity, const char *name, step_Entity_List &ent_list);

        /**
        *	�������� ������ ���������
        */
        void GetListOfEntities(EntityAggregate_ptr ent_aggr, step_Entity_List &ent_list);

        /**
         *	�������� ������ ����������
         */
        void GetSuperTypesMap(STEPentity *_entity, step_Map_of_Supertypes &m);

        /**
         *	�������� �������� �� �����
         */
        STEPentity* GetSuperType(STEPentity *_entity, const char *name);

        /**
        *	�������� ������ ��������
        */
        void GetListOfSelects(STEPentity *_entity, const char *name, step_Selects_List &sel_list);

    }
}



#endif // !STEPFUNCS_H