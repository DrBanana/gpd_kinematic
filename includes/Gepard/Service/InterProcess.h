///////////////////////////////////////////////////////////
//  InterProcess
//  ���������� 	������ �������������� ��������������
//  �������:   	12-���-2014 21:05:22
//  �����: 		Anton
///////////////////////////////////////////////////////////

#pragma once

#include "..\gepardDefines.h"
#include <windows.h>
#include <stdio.h>
#include <string>

namespace Gepard 
{
    namespace Service 
    {

        /**
         * ������ ����������� �������
         */
        class NamedPipeServer
        {
        protected:
            /**
             *  ������� ������
             */
            bool StartServer();

        public:
            NamedPipeServer();
            ~NamedPipeServer();

            /**
             *  ������� ������
             */
            void StopServer();

            /**
             *  ������� �������� ����� �� ������ �������
             */
            virtual void GetAnswerToRequest( char* pchRequest,DWORD cbBytesRead, char* pchReply, LPDWORD pchBytes );

            /**
             *  �������� �������� ������������ ������
             */
            std::string GetPipeName();

             /**
             *  ����� ������������ ������
             */
            HANDLE hPipe;

        private:
             /**
             *  ����� ������ ������� ����������� �������
             */
            DWORD dwServerThread;

            /**
             *  ����� ������ ������� ����������� �������
             */
            HANDLE ServerThreadHandle;
                        
          
       
            /**
             *  �������� ������������ ������
             */
            std::string PipeName;		

        };

        /**
         *  ���������� ������� ������
         */
      //  extern NamedPipeServer GPDNamedPipeServer;

    }//Service
}//Gepard