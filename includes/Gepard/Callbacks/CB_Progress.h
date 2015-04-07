///////////////////////////////////////////////////////////
//  CB_Progress.h
//  Реализация 	Class CB_Progress
//  Создана:   	08-окт-2013 18:13:22
//  Автор: 		Dr_Freeman
///////////////////////////////////////////////////////////

#pragma once
#include <string>

namespace Gepard 
{
    namespace Callbacks
    {

        /**
         *  Виртуальный класс - прогресс выполнения
         */
        class ProgressEvent
        {
        public:
            ProgressEvent();
            ~ProgressEvent();

            /**
             *  Установить текущее значение прогресса
             */
            virtual void SetCurrentProgress( int _progress, std::string _Message="" );

            /**
             *  Установить текущее значение главного прогресса
             */
            virtual void SetCurrentMainProgress( int _progress );
        };

        /**
         *  Указатель на класс прогресса выполнения
         */
        extern ProgressEvent* CB_ProgressEventPtr;

        /**
         *  Установить указатель на класс прогресса
         */
        extern void CB_SetProgressClassPtr(ProgressEvent* _progressClassPtr);

        /**
         *  Глобальная функция - установка текущего значения прогресса
         */
        extern void CB_SetCurrentProgress( int _progress, std::string _Message="" );

        /**
         *  Глобальная функция - установка второго прогресса (общего прогресса действий)
         */
        extern void CB_SetCurrentMainProgress( int _progress );

    }
}