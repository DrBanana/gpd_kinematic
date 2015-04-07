///////////////////////////////////////////////////////////
//  GSceneItem
//  Часть объектов графической сцены
//  Created on:      17-фев-2014 17:32:15
//  Original author: Anton
///////////////////////////////////////////////////////////

#pragma once

#include "GPrimitive.h"
#include "GText.h"

namespace Gepard
{
    namespace Visualization
    {   
        class GCamera;

        /**
         *  Графический объект, состоящий из примитивов
         */
        typedef std::list<GPrimitive> GObject;

        /**
         *  Хэш-таблица, связывающая тип примитива с парой: размер массива и сам массив идексов
         */
        typedef boost::unordered_map<GPRIMITIVE_TYPE, PIndexes> IndexesPointsHash;               

        /**
         *  Класс представляет часть графической сцены для камеры
         */
        class GSceneItem 
        {
        public:
            GSceneItem();
            ~GSceneItem();
                    
            /**
             *  Массив координат вершин для рендеринга (вершинный мега-массив)
             */
            float *VertexArray;

            /**
             *  Массив координат нормалей вершин
             */
            float *NormalArray;

            /** 
             *  Массив цвета вершин
             */
            float *ColorArray;           

            /**
             *	Общее число вершин
             */
            unsigned int VertexCount;

            /**
             *	Параметры индексов объектов для VBO
             */
            ObjVBOBufferIndexes _vbo;

            /**
             *  Список геометрических объектов, состоящих из примитивов
             */
            std::list<GObject> GObjectsList;

            /**
             *  Индексный массив вершин для объектов, сгруппированный по типам примитивов
             */
            std::list< IndexesPointsHash >  ObjectVertexIndexes;

            /**
             *  Массив тектовых объектов для отображения в данном участке граф. сцены
             */
            std::list<GText> TextObjects;

            /**
             *  Объекты, на которые установлен цвет (а не материал)
             */
            boost::unordered_set< GObject* > ObjColored;

            /**
             *  Родительская камера
             */
            GCamera* parentCamera;
                       
            /**
             *  Функция подготавливает геометрию для отображения
             */
            void PrepareRenderData();
                       
            /**
             *  Функция очищает все графические данные камеры
             */
            void ClearSceneItemData();

            /**
             *  Получить настройки текущего участка сцены
             */
            unsigned long GetSettings();

            /**
             *  Установить флаги настройки
             */
            void SetSettings(unsigned long _flags);          

            /**
             *  Есть ли такая настройка
             */
            bool Is(GSCENE_ITEM_SETTINGS setting);

            /**
             *  Установить видимость объекта
             */
            void SetVisible(bool _visible);

            /**
             *  Видимый ли участок
             */
            bool isVisible();

            /**
             *  Получить указатель на графический объект по индексу
             */
            GObject* getGObjectByIndex(int index);

            /**
             *  Добавить текстовый объект
             */
            GText* AddGText(GText _text = GText());

            /**
             *  Удалить текстовый объект по индексу
             */
            void DeleteGText(GText* _text);

            /**
             *  Удалить все текстовые объекты
             */
            void DeleteGTexts();
            
            /**
             *  Получить индекс вершин для объекта по номеру
             */
            IndexesPointsHash* FindIndexesPointsHash(int obj_index);

            /**
             * Изменить координаты графического объекта (по индексу объекта в массиве)
             * Второй аргумент - ссылка на лямбда-функцию.
             * Параметр лямбда-функции - указатель на вершинный массив 
             * (по этому адресу находится конкретная точка объекта).
             */
            void ModifyObject(int obj_index, std::function<void(float *)> &funcRef);

             /**
              * Установить эквивалентные номинальному (n_index) 
              * координаты целевого объекта (t_index) данной сцены.
              * Объекты должны быть идентичные.
              * Номинальный объект содержится в n_item
              */
             void SetEquivalent(int t_index, GSceneItem* n_item, int n_index);

            /**
             *  Функция устанавливает цвет графического объекта по индексу
             */
            void SetObjectColor( int obj_index, float R, float G, float B, float Alpha, bool isDropColor = false );

            /**
             *  Сбрасывает цвет объекта по индексу
             */
            void DropObjectColor(int obj_index);

            /**
             *  Функция создает буферы VBO для данного участка сцены
             */
            void BuildVBO( unsigned int filteredV );

            /**
             *	Очистка буферов VBO
             */
            void ClearVBOData();

        private:

            /**
             *  Видимый ли участок
             */
            bool visible;

            /**
             *  Настройки участка сцены
             */
            unsigned long _settings;
          
            /**
             *  Функция очищает временные массивы, используемые для рендеринга
             */
            void ClearTempRenderData(bool isDeleteVBOData = true);

             /**
             *  Функция выделяет необходимое количество памяти для хранения массива
             *  В случае возврата -1 - ошибка выделения памяти!
             *  0 - все окей.
             */
            int CreateArrays();
        };

    }
}
