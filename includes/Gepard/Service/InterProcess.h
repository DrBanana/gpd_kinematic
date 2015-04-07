///////////////////////////////////////////////////////////
//  InterProcess
//  Реализация 	Модуль межпроцессного взаимодействия
//  Создана:   	12-янв-2014 21:05:22
//  Автор: 		Anton
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
         * Сервер именованных каналов
         */
        class NamedPipeServer
        {
        protected:
            /**
             *  Создать сервер
             */
            bool StartServer();

        public:
            NamedPipeServer();
            ~NamedPipeServer();

            /**
             *  Закрыть сервер
             */
            void StopServer();

            /**
             *  Функция передает ответ на запрос клиента
             */
            virtual void GetAnswerToRequest( char* pchRequest,DWORD cbBytesRead, char* pchReply, LPDWORD pchBytes );

            /**
             *  Получить название именованного канала
             */
            std::string GetPipeName();

             /**
             *  Хэндл именованного канала
             */
            HANDLE hPipe;

        private:
             /**
             *  Номер потока сервера именованных каналов
             */
            DWORD dwServerThread;

            /**
             *  Хэндл потока сервера именованных каналов
             */
            HANDLE ServerThreadHandle;
                        
          
       
            /**
             *  Название именованного канала
             */
            std::string PipeName;		

        };

        /**
         *  Глобальный инстанс класса
         */
      //  extern NamedPipeServer GPDNamedPipeServer;

    }//Service
}//Gepard