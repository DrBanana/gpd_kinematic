///////////////////////////////////////////////////////////
//  GepardErrorDescriptor.h
//  Реализация Class GepardErrorDescriptor
//  Создано:      06-дек-2012 12:59:51
//  Автор: Dr_Freeman
///////////////////////////////////////////////////////////

#if !defined(GPD_5072FC7A_8141_435a_A2F9_0FF8918FC23A__INCLUDED_)
#define GPD_5072FC7A_8141_435a_A2F9_0FF8918FC23A__INCLUDED_

#include "GepardErrorType.h"
#include "GepardDebugLevel.h"
#include <string>

namespace Gepard
{
    namespace Service
    {
        /**
         * Класс-описатель ошибки
         */
        class GepardErrorDescriptor
        {

        public:
            GepardErrorDescriptor();
            /**
             * тип ошибки
             */
            Gepard::Service::GepardErrorType _errortype;
            /**
             * уровень отладки
             */
            Gepard::Service::GepardDebugLevel _debug_level;
            /**
             * имя модуля
             */
            std::string _moduleName;
            /**
             * название функции
             */
            std::string _funcName;
            /**
             * Сообщение об ошибке
             */
            std::string _errorMsg;

            GepardErrorDescriptor(Gepard::Service::GepardErrorType errortype, Gepard::Service::GepardDebugLevel debuglevel, std::string modulename, std::string funcname, std::string errormsg)
                : _errortype(errortype),_errorMsg(errormsg),_moduleName(modulename),_funcName(funcname),_debug_level(debuglevel)
            {
            }
            ~GepardErrorDescriptor(){}
            /**
             *	Получить сообщение об ошибке
             */
            std::string ErrorMsg()
            {
                return _errorMsg;
            }
            /**
             *	Присвоить сообщение об ошибке
             */
            void ErrorMsg(std::string ErrMSG)
            {
                _errorMsg=ErrMSG;
            }
            /**
             *	Получить имя модуля
             */
            std::string ModuleName()
            {
                return _moduleName;
            }
            /**
             *	Задать имя модуля
             */
            void ModuleName(std::string modulename)
            {
                _moduleName=modulename;
            }
            /**
             *	Получить имя функции с ошибкой
             */	
            std::string FuncName()
            {
                return _funcName;
            }
            /** 
             *	Задать имя функции
             */
            void FuncName(std::string funcname)
            {
                _funcName=funcname;
            }
            /**
             *	Получить тип ошибки
             */
            Gepard::Service::GepardErrorType ErrorType()
            {
                return _errortype;
            }
            /**
             *	Задать тип ошибки
             */
            void ErrorType(Gepard::Service::GepardErrorType ET)
            {
                _errortype=ET;
            }
            /**
             *	Получить уровень отладки
             */
            Gepard::Service::GepardDebugLevel debug_level()
            {
                return _debug_level;
            }
            /**
             *	Задать уровень отладки
             */
            void debug_level(Gepard::Service::GepardDebugLevel DL)
            {
                _debug_level=DL;
            }

        };

    }

}
#endif // !defined(GPD_5072FC7A_8141_435a_A2F9_0FF8918FC23A__INCLUDED_)
