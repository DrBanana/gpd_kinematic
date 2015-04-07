///////////////////////////////////////////////////////////
//  CB_OutputMessages.h
//  ���������� 	CB_OutputMessages
//  �������:   	17-���-2013 14:25:02
//  �����: 		Dr_Freeman
///////////////////////////////////////////////////////////

#pragma once
#include <string>

namespace Gepard 
{
    namespace Callbacks
    {
        /**
         *  ����� ���������
         */
        class OutputMessageEvent
        {
        public:
            OutputMessageEvent();
            ~OutputMessageEvent();

            /**
             *  ������� ������ ����������
             */
            virtual void OutputMessage( std::string _Message="" );

            /**
             *  ������� ������ ���������� �� ������
             */
            virtual void OutputErrorMessage( std::string _Message="" );
        };

        /**
         *  ��������� �� ����� ������ ���������
         */
        extern OutputMessageEvent* CB_OutputMessageEventClassPtr;

        /**
         *  ���������� ��������� �� ����� - ����� ���������
         */
        extern void CB_SetOutputMessageEvent( OutputMessageEvent* _outputMessageEventPtr );

        /**
         *  ���������� ������� ��� ������ ���������
         */
        extern void CB_OutputInfoMsgEvent( std::string _Message );

        /**
         *  ���������� ������� ��� ������ ������
         */
        extern void CB_OutputErrorMsgEvent( std::string _Message );

    }
}