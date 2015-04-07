///////////////////////////////////////////////////////////
//  GepardErrors.h
//  ����������  Class GepardErrors
//  �������:    06-���-2012 13:00:14
//  �����:		Dr_Freeman
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
         * ���������� ���� ����� � �������� ��� ���������� �� ������� �������� �������
         * ���������� ������, ����� ���� ������ � ���, ����� ��������� �� ����������
         */
        class GepardErrors
        {

        public:
            /**
             * �������� ������
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
             * �������� ������
             */
            std::string formatString(const char* fmt, ...){

                std::string s;
                s.clear();
                char    text[256];      // ����� ��� ����� ������
                va_list    ap;          // ��������� �� ������ ����������
    
                if (fmt == NULL)     // ���� ��� ������
                    return s;            // ������ �� ������
    
                va_start(ap, fmt);           // ������ ������ ����������
                _vsnprintf_s(text,256,256, fmt, ap); // � ��������������� �������� � �������� ����
                va_end(ap);        
                s = text;
                return s;
            }

        private:
            /**
             * ���������� �� �������������� ����������
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
