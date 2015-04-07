///////////////////////////////////////////////////////////
//  GColor.h
//  Implementation of the Class GColor
//  Created on:      19-авг-2013 18:28:29
//  Original author: Anton
///////////////////////////////////////////////////////////

#if !defined(GPD_A9B33A70_69F5_4a44_A7F5_56786592CC07__INCLUDED_)
#define GPD_A9B33A70_69F5_4a44_A7F5_56786592CC07__INCLUDED_

#include <fstream>

namespace Gepard
{
    namespace Visualization
    {
        /**
         * Операции с цветом
         */
        class GColor
        {

        public:
            GColor();
            GColor(float Red, float Green, float Blue, float Alpha=1.0f);
            GColor(float _color[4]);
            virtual ~GColor();
            
            /**
             *	Цвет объекта
             */
            float Color[4];			
            
            /**
             *	Установить цвет
             */
            void SetColor(float Red, float Green, float Blue, float Alpha=1.0f);
            /**
             *	Получить цвет
             */
            float *GetColor();

            /**
             *  Установить цвет
             */
            void operator=(float _color[4]);

            /**
             *  Получить цвет
             */
            float operator[](int i);

            /**
             *  Установлен ли цвет
             */
            bool isColorSet;

            /**
             *  Сбросить цвет
             */
            void DropColor();

            friend std::ostream& operator<<(std::ostream& os, const GColor &col)
            {
                os.write((char*) &col.Color, sizeof(float)*4);
                return os;
            }

            friend std::istream& operator>>(std::istream& is, GColor &col)
            {
                is.read((char*) &col.Color, sizeof(float)*4);
                col.isColorSet = true;
                return is;
            }

        };

    }

}
#endif // !defined(GPD_A9B33A70_69F5_4a44_A7F5_56786592CC07__INCLUDED_)
