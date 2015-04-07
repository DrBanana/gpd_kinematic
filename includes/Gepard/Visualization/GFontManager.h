///////////////////////////////////////////////////////////
//  GFontManager.h
//  Менеджер шрифтов для модуля визуализации
//  Created on:      06-ноября-2013 21:59:30
//  Original author: Anton
///////////////////////////////////////////////////////////

#ifndef GFONTMANAGER_H
#define GFONTMANAGER_H

#include <string>
#include <FTGL/ftgl.h>
#include <map>

//TODO: Сделать загрузку шрифтов из заданной папки

namespace Gepard 
{
    namespace Visualization
    {                
        /**
         *  Типы шрифтов
         */
        enum GFontType { GFT_BITMAP, GFT_PIXMAP, GFT_OUTLINE, GFT_POLYGON, GFT_EXTRUDE, GFT_TEXTURE };

        /**
         *  Тип: массив шрифтов
         */
        typedef std::map<std::string, FTFont*> FontList;

        /**
         *  Менеджер шрифтов
         */
        class GFontManager
        {
        public:
            GFontManager();
            ~GFontManager();

            /**
             *  Создать и получить шрифт
             */
            FTFont* createFont(const char *filename, int size, GFontType fontType);

            /**
             *  Создать и получить шрифт для отображения меток
             */
            FTFont* createLabelFont(int size);

            /**
             *  Создать и получить шрифт для отображения 3D текста
             */
            FTFont* create3DFont(int size);

            /**
             *  Установить директорию со шрифтами
             */
            void SetFontPath(std::string _Path);

        private:
            /**
             *  Массив шрифтов
             */
            FontList fonts;

            /**
             *  Директория со шрифтами
             */
            std::string FontsPath;

            /**
             *  Массив файлов со шрифтами (имя шрифта - путь до файла)
             */
            std::map<std::string,std::string> FontsPathsList;
        };

        /**
         *  Глобальный инстанс класса
         */
        //extern GFontManager FONT_MANAGER;

    }//Visualization
}//namespace Gepard

#endif
