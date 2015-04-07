///////////////////////////////////////////////////////////
//  CB_OutputMessages.h
//  Реализация 	CB_OutputMessages
//  Создана:   	17-окт-2013 14:25:02
//  Автор: 		Dr_Freeman
///////////////////////////////////////////////////////////

#pragma once
#include <string>

namespace Gepard 
{
    namespace Callbacks
    {
        /**
         *  Вывод сообщений
         */
        class OutputMessageEvent
        {
        public:
            OutputMessageEvent();
            ~OutputMessageEvent();

            /**
             *  Событие вывода информации
             */
            virtual void OutputMessage( std::string _Message="" );

            /**
             *  Событие вывода информации об ошибке
             */
            virtual void OutputErrorMessage( std::string _Message="" );
        };

        /**
         *  Указатель на класс вывода сообщений
         */
        extern OutputMessageEvent* CB_OutputMessageEventClassPtr;

        /**
         *  Установить указатель на класс - вывод сообщений
         */
        extern void CB_SetOutputMessageEvent( OutputMessageEvent* _outputMessageEventPtr );

        /**
         *  Глобальная функция для вывода сообщений
         */
        extern void CB_OutputInfoMsgEvent( std::string _Message );

        /**
         *  Глобальная функция для вывода ошибок
         */
        extern void CB_OutputErrorMsgEvent( std::string _Message );

    }
}