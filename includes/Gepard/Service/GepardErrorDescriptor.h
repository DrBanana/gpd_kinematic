///////////////////////////////////////////////////////////
//  GepardErrorDescriptor.h
//  ���������� Class GepardErrorDescriptor
//  �������:      06-���-2012 12:59:51
//  �����: Dr_Freeman
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
         * �����-��������� ������
         */
        class GepardErrorDescriptor
        {

        public:
            GepardErrorDescriptor();
            /**
             * ��� ������
             */
            Gepard::Service::GepardErrorType _errortype;
            /**
             * ������� �������
             */
            Gepard::Service::GepardDebugLevel _debug_level;
            /**
             * ��� ������
             */
            std::string _moduleName;
            /**
             * �������� �������
             */
            std::string _funcName;
            /**
             * ��������� �� ������
             */
            std::string _errorMsg;

            GepardErrorDescriptor(Gepard::Service::GepardErrorType errortype, Gepard::Service::GepardDebugLevel debuglevel, std::string modulename, std::string funcname, std::string errormsg)
                : _errortype(errortype),_errorMsg(errormsg),_moduleName(modulename),_funcName(funcname),_debug_level(debuglevel)
            {
            }
            ~GepardErrorDescriptor(){}
            /**
             *	�������� ��������� �� ������
             */
            std::string ErrorMsg()
            {
                return _errorMsg;
            }
            /**
             *	��������� ��������� �� ������
             */
            void ErrorMsg(std::string ErrMSG)
            {
                _errorMsg=ErrMSG;
            }
            /**
             *	�������� ��� ������
             */
            std::string ModuleName()
            {
                return _moduleName;
            }
            /**
             *	������ ��� ������
             */
            void ModuleName(std::string modulename)
            {
                _moduleName=modulename;
            }
            /**
             *	�������� ��� ������� � �������
             */	
            std::string FuncName()
            {
                return _funcName;
            }
            /** 
             *	������ ��� �������
             */
            void FuncName(std::string funcname)
            {
                _funcName=funcname;
            }
            /**
             *	�������� ��� ������
             */
            Gepard::Service::GepardErrorType ErrorType()
            {
                return _errortype;
            }
            /**
             *	������ ��� ������
             */
            void ErrorType(Gepard::Service::GepardErrorType ET)
            {
                _errortype=ET;
            }
            /**
             *	�������� ������� �������
             */
            Gepard::Service::GepardDebugLevel debug_level()
            {
                return _debug_level;
            }
            /**
             *	������ ������� �������
             */
            void debug_level(Gepard::Service::GepardDebugLevel DL)
            {
                _debug_level=DL;
            }

        };

    }

}
#endif // !defined(GPD_5072FC7A_8141_435a_A2F9_0FF8918FC23A__INCLUDED_)
