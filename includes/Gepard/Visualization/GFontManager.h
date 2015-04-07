///////////////////////////////////////////////////////////
//  GFontManager.h
//  �������� ������� ��� ������ ������������
//  Created on:      06-������-2013 21:59:30
//  Original author: Anton
///////////////////////////////////////////////////////////

#ifndef GFONTMANAGER_H
#define GFONTMANAGER_H

#include <string>
#include <FTGL/ftgl.h>
#include <map>

//TODO: ������� �������� ������� �� �������� �����

namespace Gepard 
{
    namespace Visualization
    {                
        /**
         *  ���� �������
         */
        enum GFontType { GFT_BITMAP, GFT_PIXMAP, GFT_OUTLINE, GFT_POLYGON, GFT_EXTRUDE, GFT_TEXTURE };

        /**
         *  ���: ������ �������
         */
        typedef std::map<std::string, FTFont*> FontList;

        /**
         *  �������� �������
         */
        class GFontManager
        {
        public:
            GFontManager();
            ~GFontManager();

            /**
             *  ������� � �������� �����
             */
            FTFont* createFont(const char *filename, int size, GFontType fontType);

            /**
             *  ������� � �������� ����� ��� ����������� �����
             */
            FTFont* createLabelFont(int size);

            /**
             *  ������� � �������� ����� ��� ����������� 3D ������
             */
            FTFont* create3DFont(int size);

            /**
             *  ���������� ���������� �� ��������
             */
            void SetFontPath(std::string _Path);

        private:
            /**
             *  ������ �������
             */
            FontList fonts;

            /**
             *  ���������� �� ��������
             */
            std::string FontsPath;

            /**
             *  ������ ������ �� �������� (��� ������ - ���� �� �����)
             */
            std::map<std::string,std::string> FontsPathsList;
        };

        /**
         *  ���������� ������� ������
         */
        //extern GFontManager FONT_MANAGER;

    }//Visualization
}//namespace Gepard

#endif
