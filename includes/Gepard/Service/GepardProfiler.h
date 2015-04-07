///////////////////////////////////////////////////////////
//  GepardProfiler.h
//  �������������
//  �������:  11-���-2013 15:37:11
//  �����:    Dr_Freeman
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
         *  ��������� - ���������� ������������
         */
        struct ProfilerInfo
        {               
            DWORD _start_ticks;  //��������� ����� � �����
            DWORD dwTotalCalls;  //����� �������
            DWORD dwAvgTime;     //������� �����
            DWORD dwTotalTime;   //����� �������

            ProfilerInfo()
            {
                dwTotalCalls = 0;
                dwAvgTime = 0;
                dwTotalTime = 0;
                _start_ticks = 0;
            }
        };

        /**
         *  ������ ��������������
         */        
        extern boost::unordered_map<std::string, ProfilerInfo> _ProfilerData;

        /**
         *  ����� ��������������
         */
        class GepardProfiler
        {
        public:
            GepardProfiler();
            
            /**
             *  ������ ��������������� ��������
             */
            static void Begin(std::string _ProcName);
            /**
             *  ����� ��������������� ��������
             */
            static void End(std::string _ProcName);

            /**
             *  ����������� ���������� � ���� ��� � �������
             */
            static void PrintResults( std::string _FileName="" );

            /**
             *  ����������� ���������� � ���� gpd_profiler.log
             */
            static void PrintResDefault();                  

            /**
             *  ������� ������ ��������������
             */
            static void ClearData();

        private:
            /**
             *  ������ ��������������
             */
            //static std::unordered_map<std::string, ProfilerInfo> _ProfilerData;
            
        };

    }
}