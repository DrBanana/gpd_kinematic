///////////////////////////////////////////////////////////
//  GepardErrors.h
//  Реализация  Class GepardErrors
//  Создано:    06-дек-2012 13:00:14
//  Автор:		Dr_Freeman
///////////////////////////////////////////////////////////

#if !defined(GPD_D1FF9800_6B62_4974_8F9B_C3BE8577BE8E__INCLUDED_)
#define GPD_D1FF9800_6B62_4974_8F9B_C3BE8577BE8E__INCLUDED_

#include "GepardDebugLevel.h"
#include "GepardErrorType.h"
#include "GepardErrorDescriptor.h"
#include <list>
#include <stdarg.h>

namespace Gepard
{
    namespace Service
    {
        /**
         * Собственно этот класс и содержит всю информацию об ошибках Содержит функции
         * добавления ошибок, вывод всех ошибок в ЛОГ, вывод сообщений по параметрам
         */
        class GepardErrors
        {

        public:
            /**
             * Описания ошибок
             */
            std::list<Gepard::Service::GepardErrorDescriptor> ErrorDescriptorList;

            /**
             * --------------------------------------------------------------------------------
             * ---------------------------------------- =======================GetDebugLevel,
             * GetErrorType
             */
            GepardErrors();
            ~GepardErrors();
            void SetShowInfo(bool isShow){

                isShowInfo=isShow;
            }
            /**
             * --------------------------------------------------------------------------------
             * ----------------------------------------
             * =======================AddErrorDescription
             */
            void AddErrorDescription(Gepard::Service::GepardErrorType errortype, Gepard::Service::GepardDebugLevel debuglevel, std::string modulename, std::string funcname, std::string errormsg);
            void AddErrorDescription(std::string errormsg);
            void AddErrorDescription(std::string modulename, std::string errormsg);
            void AddErrorDescription(std::string modulename, std::string funcname, std::string errormsg);
            void AddErrorDescription(Gepard::Service::GepardDebugLevel debuglevel, std::string errormsg);
            void AddErrorDescription(Gepard::Service::GepardDebugLevel debuglevel, std::string modulename, std::string errormsg);
            void AddErrorDescription(Gepard::Service::GepardDebugLevel debuglevel, std::string modulename, std::string funcname, std::string errormsg);
            void AddErrorDescription(Gepard::Service::GepardErrorType errortype, std::string errormsg);
            void AddErrorDescription(Gepard::Service::GepardErrorType errortype, std::string modulename, std::string errormsg);
            void AddErrorDescription(Gepard::Service::GepardErrorType errortype, std::string modulename, std::string funcname, std::string errormsg);
            void AddErrorDescription(Gepard::Service::GepardErrorType errortype, Gepard::Service::GepardDebugLevel debuglevel, std::string errormsg);
            void AddErrorDescription(Gepard::Service::GepardErrorType errortype, Gepard::Service::GepardDebugLevel debuglevel, std::string modulename, std::string errormsg);
            unsigned int GetErrorsCount();
            unsigned int GetErrorsCount(std::string modulename);
            unsigned int GetErrorsCount(std::string modulename, std::string funcname);
            unsigned int GetErrorsCount(Gepard::Service::GepardDebugLevel debuglevel);
            unsigned int GetErrorsCount(Gepard::Service::GepardErrorType errortype);
            unsigned int GetErrorsCount(Gepard::Service::GepardDebugLevel debuglevel, Gepard::Service::GepardErrorType errortype);
            unsigned int GetErrorsCount(Gepard::Service::GepardDebugLevel debuglevel, Gepard::Service::GepardErrorType errortype, std::string modulename);
            unsigned int GetErrorsCount(Gepard::Service::GepardDebugLevel debuglevel, Gepard::Service::GepardErrorType errortype, std::string modulename, std::string funcname);
            std::string GetErrors();
            std::string GetErrors(std::string modulename);
            std::string GetErrors(std::string modulename, std::string funcname);
            std::string GetErrors(Gepard::Service::GepardDebugLevel debuglevel);
            std::string GetErrors(Gepard::Service::GepardErrorType errortype);
            std::string GetErrors(Gepard::Service::GepardDebugLevel debuglevel, Gepard::Service::GepardErrorType errortype);
            std::string GetErrors(Gepard::Service::GepardDebugLevel debuglevel, Gepard::Service::GepardErrorType errortype, std::string modulename);
            std::string GetErrors(Gepard::Service::GepardDebugLevel debuglevel, Gepard::Service::GepardErrorType errortype, std::string modulename, std::string funcname);
            std::string GetLastError();
            void ClearErrors(){

                ErrorDescriptorList.clear();
            }
            /**
             * =======================GetErrors -----------------------------------------------
             * -------------------------------------------------------------------------
             */
            void SaveToLog(std::string FileName);
            /**
             * создание строки
             */
            std::string formatString(const char* fmt, ...){

                std::string s;
                s.clear();
                char    text[256];      // Место для нашей строки
                va_list    ap;          // Указатель на список аргументов
    
                if (fmt == NULL)     // Если нет текста
                    return s;            // Ничего не делать
    
                va_start(ap, fmt);           // Разбор строки переменных
                _vsnprintf_s(text,256,256, fmt, ap); // И конвертирование символов в реальные коды
                va_end(ap);        
                s = text;
                return s;
            }

        private:
            /**
             * Показывать ли дополнительную информацию
             */
            bool isShowInfo;

            /**
             * --------------------------------------------------------------------------------
             * ---------------------------------------- =======================GetErrorsCount
             */
            unsigned int GetErrorsCount_(int variant, Gepard::Service::GepardDebugLevel debuglevel, Gepard::Service::GepardErrorType errortype, std::string modulename, std::string funcname);
            /**
             * --------------------------------------------------------------------------------
             * ---------------------------------------- =======================GetErrors
             */
            std::string GetErrors_(int variant, Gepard::Service::GepardDebugLevel debuglevel, Gepard::Service::GepardErrorType errortype, std::string modulename, std::string funcname);
            std::string GetErrorType(Gepard::Service::GepardErrorType errortype);
            std::string GetDebugLevel(Gepard::Service::GepardDebugLevel debuglevel);

        };

    }

}
#endif // !defined(GPD_D1FF9800_6B62_4974_8F9B_C3BE8577BE8E__INCLUDED_)
