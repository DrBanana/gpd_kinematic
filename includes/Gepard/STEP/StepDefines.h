///////////////////////////////////////////////////////////
//  StepDefines.h
//  Создано:    19-фев-2015 15:04
//  Автор:      Dr_Freeman
//  Описание:   Общие определения для классов чтения STEP
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
         *	Список сущностей
         */
        typedef std::list<SDAI_Application_instance*> step_Entity_List;

        /**
         *	Список селектов
         */
        typedef std::list<SDAI_Select*> step_Selects_List;

        /**
         *	Список строк
         */
        typedef std::list<std::string> step_Strings_List;

        /**
         *	Вектор чисел с плав. точкой двойной точности
         */
        typedef std::vector<double> step_Doubles_Vector;

        /**
        *	Список целых чисел 
        */
        typedef std::list<int> step_Ints_List;

        /**
        *	Вектор целых чисел
        */
        typedef std::vector<int> step_Ints_Vector;

        /**
        *	Список чисел с плав. точкой двойной точности
        */
        typedef std::list<double> step_Doubles_List;

        /**
        *	Список списков чисел с плав. точкой двойной точности
        */
        typedef std::list<step_Doubles_List *> step_Doubles_List_List;

        /**
         *	Дерево супертипов
         */
        typedef std::map<std::string, STEPcomplex *> step_Map_of_Supertypes;


    }//STEP
}//Gepard

#endif