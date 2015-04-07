///////////////////////////////////////////////////////////
//  KeyFeature.h
//  Ключевое свойство (результирующее/выходное)
//  Создано:  1-окт-2014
//	Оригинальный автор: Anton
///////////////////////////////////////////////////////////

#pragma once

#include "../../General/basicList.h"
#include "../../General/basicArray.h"

namespace Gepard 
{
    class MathModel;

    namespace Analysis 
    {
        /**
         *  Тип ключевого свойства
         */
        enum KEY_FEATURE_TYPE 
        {
             KFT_UNKNOWN = -1        //Не задано
            ,KFT_PRECISION_DIGRAM    //Диаграмма точности
            ,KFT_MINMAX_AXES_ANGLE   //Минимальный и максимальный угол между заданными осями
            ,KFT_MINMAX_CLEARANCE    //Минимальный и максимальный зазор
            ,KFT_MINMAX_INTERSECTION //Минимальное и максимальное пересечение (врезание)

            ,KFT_END                 //Это значение используется для определения количества типов (всегда в конце)
        };

        /**
         *  Ключевое свойство (результирующее/выходное)
         */
        class KeyFeature 
        {
        public:
            KeyFeature() { kft_type = KFT_UNKNOWN; }

            /**
             *  Получить тип ключевого свойства
             */
            KEY_FEATURE_TYPE getType() { return kft_type; }

            /**
             *  Создать ключевое свойство по типу
             */
            static Gepard::Analysis::KeyFeature* CreateKeyFeature(KEY_FEATURE_TYPE fType);

            /**
             *  Шаблонная функция создает ключевое свойство по типу
             */
            template <class T>
            static Gepard::Analysis::KeyFeature* CreateKeyFeature();
                      
            /**
             *  Функция копирования ключевого свойства
             */
            virtual void CopyTo(Gepard::Analysis::KeyFeature* kf);

            /**
             *  Удалить результаты анализа для ключевого свойства
             */
            virtual void ClearResults();

            /**
             *  Есть ли результаты для данного свойства
             */
            virtual bool hasResults();

            /**
             *  Сохранить данные в файл
             */
            virtual void saveToFile(std::ostream &os);

            /**
             *  Загрузить данные из файла
             */
            virtual void readFromFile(std::istream &is, Gepard::MathModel *mathModelPtr);

        private:
              /**
             *  Шаблонная функция копирует данные одного свойства в другое
             */
            template <class T>
            void CopyTo(Gepard::Analysis::KeyFeature* toKF);

        protected:

            /**
             *  Тип ключевого параметра
             */
            KEY_FEATURE_TYPE kft_type;
        };

        typedef KeyFeature* KeyFeaturePtr;

        /**
         *  Список указателей на ключевые свойства
         */
        class KeyFeaturePtrList: public Gepard::General::basicList<KeyFeature*>
        {
        public:
            ~KeyFeaturePtrList();

            /**
             *  Удалить текущее ключевое свойство из списка
             */
            void DeleteKeyFeature(KeyFeature *kf);

            /**
             *  Удалить все ключевые свойства
             */
            void DeleteKeyFeatures();

            /**
             * Есть ли уже такое свойство 
             */
            bool isExist(KeyFeature *kf);

            /**
             *  Очистить результаты прошлого анализа во всех свойствах
             */
            void ClearResults();

        };       

    }//Analysis
}//Gepard