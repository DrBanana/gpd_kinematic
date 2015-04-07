///////////////////////////////////////////////////////////
//  CB_Progress.h
//  ���������� 	Class CB_Progress
//  �������:   	08-���-2013 18:13:22
//  �����: 		Dr_Freeman
///////////////////////////////////////////////////////////

#pragma once
#include <string>

namespace Gepard 
{
    namespace Callbacks
    {

        /**
         *  ����������� ����� - �������� ����������
         */
        class ProgressEvent
        {
        public:
            ProgressEvent();
            ~ProgressEvent();

            /**
             *  ���������� ������� �������� ���������
             */
            virtual void SetCurrentProgress( int _progress, std::string _Message="" );

            /**
             *  ���������� ������� �������� �������� ���������
             */
            virtual void SetCurrentMainProgress( int _progress );
        };

        /**
         *  ��������� �� ����� ��������� ����������
         */
        extern ProgressEvent* CB_ProgressEventPtr;

        /**
         *  ���������� ��������� �� ����� ���������
         */
        extern void CB_SetProgressClassPtr(ProgressEvent* _progressClassPtr);

        /**
         *  ���������� ������� - ��������� �������� �������� ���������
         */
        extern void CB_SetCurrentProgress( int _progress, std::string _Message="" );

        /**
         *  ���������� ������� - ��������� ������� ��������� (������ ��������� ��������)
         */
        extern void CB_SetCurrentMainProgress( int _progress );

    }
}