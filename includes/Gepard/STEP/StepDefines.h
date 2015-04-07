///////////////////////////////////////////////////////////
//  StepDefines.h
//  �������:    19-���-2015 15:04
//  �����:      Dr_Freeman
//  ��������:   ����� ����������� ��� ������� ������ STEP
///////////////////////////////////////////////////////////

#ifndef STEPDEFINES_H
#define STEPDEFINES_H 

#include <sdaiApplication_instance.h>
#include <sdaiSelect.h>
#include <STEPcomplex.h>

#include <list>
#include <vector>
#include <map>

namespace Gepard
{
    namespace STEP
    {
        
        /**
         *	������ ���������
         */
        typedef std::list<SDAI_Application_instance*> step_Entity_List;

        /**
         *	������ ��������
         */
        typedef std::list<SDAI_Select*> step_Selects_List;

        /**
         *	������ �����
         */
        typedef std::list<std::string> step_Strings_List;

        /**
         *	������ ����� � ����. ������ ������� ��������
         */
        typedef std::vector<double> step_Doubles_Vector;

        /**
        *	������ ����� ����� 
        */
        typedef std::list<int> step_Ints_List;

        /**
        *	������ ����� �����
        */
        typedef std::vector<int> step_Ints_Vector;

        /**
        *	������ ����� � ����. ������ ������� ��������
        */
        typedef std::list<double> step_Doubles_List;

        /**
        *	������ ������� ����� � ����. ������ ������� ��������
        */
        typedef std::list<step_Doubles_List *> step_Doubles_List_List;

        /**
         *	������ ����������
         */
        typedef std::map<std::string, STEPcomplex *> step_Map_of_Supertypes;


    }//STEP
}//Gepard

#endif