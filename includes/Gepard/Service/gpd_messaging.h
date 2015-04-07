///////////////////////////////////////////////////////////
//  gpd_messaging
//  Реализация 	Базовые функции форматирования и 
//				вывода сообщений
//  Создана:   	1-дек-2012 13:33:14
//  Автор: 		Anton
///////////////////////////////////////////////////////////
#pragma once

#include <string>
#include <vector>
#include <list>

#include "..\gepardDefines.h"
#include "..\Surfaces\SURFACE_TYPES.h"

typedef std::vector<std::string> std_stringsVector; //Массив строк
typedef std::list<std::string> std_stringsList;     //Список строк

namespace Gepard 
{
    namespace Service 
    {

        /**
        *	Функция для удобного формирования строки
        */
        std::string formatMessage(char *fmt, ...);

        /**
         *  Получить строку с типом поверхности
         *  Тип поверхности задается через Gepard::Surfaces::SURFACE_TYPES
         */
        std::string getSurfaceTypeStr(Gepard::Surfaces::SURFACE_TYPES surfType);

//директивы препроцессора см. в "..\gepardDefines.h"
#ifdef GPD_WIN
        /**
        *	Функция вывода сообщения в окне AfxMessageExt
        *	Работает только для Windows
        */
        void gpd_ShowMessageWIN(char *fmt, ...);

        /**
        *	Функция вывода сообщения в окне AfxMessageExt
        *	Работает только для Windows
        */
        void gpd_ShowMessageWIN(std::string _message);
#endif

    }; //namespace Service
}; //namespace Gepard