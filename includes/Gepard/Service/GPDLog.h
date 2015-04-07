///////////////////////////////////////////////////////////
//  GPDLog.h
//  ���������� Class GPDLog
//  �������:      04-���-2012 18:32:33
//  �����: Dr_Freeman
///////////////////////////////////////////////////////////

#if !defined(GPD_4B05BCEF_6B1A_4643_966F_18C9971CF448__INCLUDED_)
#define GPD_4B05BCEF_6B1A_4643_966F_18C9971CF448__INCLUDED_

#include <string>
#include <stdio.h>

namespace Gepard
{
    namespace Service
    {
        /**
         * ����� ��� ������� ���-�.
         */
        class GPDLog
        {

        public:
            GPDLog();			
            ~GPDLog();

            /**
             *	 ������������� ������
             */
            GPDLog(std::string _fileName);

            /**
             *	������� ���� ��� ������ ���-�
             */
            void init(std::string _fileName);

            /**
             * ��������� ������� ����� � ��� ����
             */
            void logTime();

            /**
             * �������� ��������� � ���
             */
            void log(std::string _message);

            /**
             * �������� ��������� � message_data
             */
            void add(std::string _message);

            /**
             * ��������� ������ message_data � ���
             */
            void logData();

            /**
             * �������� ������ �� message_data
             */
            std::string getData();

            /**
             * ��������/��������� ������� ����
             */
            void set_logging(bool log_flag);
                      
            /**
             *	������� ���� � �����
             */
            void close_log();

        private:
            /**
             * ������ ���������
             */
            std::string message_data;
            /**
             * ��� ����� ��� ������ ����
             */
            std::string file_name;
            /**
             * ���� ������ ����
             * true - ��� �������
             */
            bool isLogging;
            /**
             *	������ �� ���� � ������ ������
             */
            bool isOpened;
            /**
             *	���� ������ ����
             */
            FILE *log_file;

        };

    }

}
#endif // !defined(GPD_4B05BCEF_6B1A_4643_966F_18C9971CF448__INCLUDED_)
