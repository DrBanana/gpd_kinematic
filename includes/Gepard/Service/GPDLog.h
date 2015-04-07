///////////////////////////////////////////////////////////
//  GPDLog.h
//  Реализация Class GPDLog
//  Создано:      04-дек-2012 18:32:33
//  Автор: Dr_Freeman
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
         * Класс для ведения лог-а.
         */
        class GPDLog
        {

        public:
            GPDLog();			
            ~GPDLog();

            /**
             *	 Инициализация класса
             */
            GPDLog(std::string _fileName);

            /**
             *	Открыть файл для записи лог-а
             */
            void init(std::string _fileName);

            /**
             * Сохранить текущее время в ЛОГ файл
             */
            void logTime();

            /**
             * Добавить сообщение в лог
             */
            void log(std::string _message);

            /**
             * Добавить сообщение в message_data
             */
            void add(std::string _message);

            /**
             * Сохранить данные message_data в лог
             */
            void logData();

            /**
             * Получить данные из message_data
             */
            std::string getData();

            /**
             * включить/отключить ведение лога
             */
            void set_logging(bool log_flag);
                      
            /**
             *	Закрыть файл с логом
             */
            void close_log();

        private:
            /**
             * буффер сообщений
             */
            std::string message_data;
            /**
             * имя файла для записи ЛОГа
             */
            std::string file_name;
            /**
             * флаг записи лога
             * true - лог пишется
             */
            bool isLogging;
            /**
             *	открыт ли файл в данный момент
             */
            bool isOpened;
            /**
             *	файл записи лога
             */
            FILE *log_file;

        };

    }

}
#endif // !defined(GPD_4B05BCEF_6B1A_4643_966F_18C9971CF448__INCLUDED_)
