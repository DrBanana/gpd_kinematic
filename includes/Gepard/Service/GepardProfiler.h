///////////////////////////////////////////////////////////
//  GepardProfiler.h
//  Профилировщик
//  Создано:  11-окт-2013 15:37:11
//  Автор:    Dr_Freeman
///////////////////////////////////////////////////////////

#pragma once

#include <string>
#include <boost/unordered_map.hpp>
#include <Windows.h>


namespace Gepard 
{
    namespace Service
    {
        

        /**
         *  Структура - информация профилировки
         */
        struct ProfilerInfo
        {               
            DWORD _start_ticks;  //Последнее время в тиках
            DWORD dwTotalCalls;  //Всего вызовов
            DWORD dwAvgTime;     //Среднее время
            DWORD dwTotalTime;   //всего времени

            ProfilerInfo()
            {
                dwTotalCalls = 0;
                dwAvgTime = 0;
                dwTotalTime = 0;
                _start_ticks = 0;
            }
        };

        /**
         *  Данные профилировщика
         */        
        extern boost::unordered_map<std::string, ProfilerInfo> _ProfilerData;

        /**
         *  Класс профилировщика
         */
        class GepardProfiler
        {
        public:
            GepardProfiler();
            
            /**
             *  Начало вычислительного процесса
             */
            static void Begin(std::string _ProcName);
            /**
             *  Конец вычислительного процесса
             */
            static void End(std::string _ProcName);

            /**
             *  Распечатать результаты в файл или в консоль
             */
            static void PrintResults( std::string _FileName="" );

            /**
             *  Распечатать результаты в файл gpd_profiler.log
             */
            static void PrintResDefault();                  

            /**
             *  Удалить данные профилировщика
             */
            static void ClearData();

        private:
            /**
             *  Данные профилировщика
             */
            //static std::unordered_map<std::string, ProfilerInfo> _ProfilerData;
            
        };

    }
}