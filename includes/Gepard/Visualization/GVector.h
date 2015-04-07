#pragma once

#include <math.h>
#include <fstream>

namespace Gepard {
    namespace Visualization {

        class GVector
        {
            float V[3];
        public:
            GVector(float X = 0, float Y = 0, float Z = 0);
    
            ~GVector();
    
    
            void SetVector(float X = 0, float Y = 0, float Z = 0);
            void SetVector(float (&vec)[3]);
               
            void Normalize();
            float X(); float Y(); float Z();	
                        
            float GetLength();

            float* Get();

            GVector operator + (GVector &vec);
            GVector operator - (GVector &vec);
            GVector operator = (GVector &vec);
            GVector operator * (float v);
            bool operator == (GVector &vec);
            float operator[](int i);
            void operator +=(GVector &vec);
            void operator -=(GVector &vec);
            void operator +=(float (&vec)[3]);
            void operator -=(float (&vec)[3]);
            void operator *=(float v);

            //скалярное произведение
            float dot(GVector &vec);

            //векторное произведение
            GVector cross(GVector &vec);

            //перегруженный оператор вывода
            friend std::ostream& operator<<(std::ostream& os, const GVector &v)
            {
                os.write((char*) &v.V, sizeof(float)*3);
                return os;
            }
            //перегруженный оператор ввода
            friend std::istream& operator>>(std::istream& is, GVector &v)
            {
                is.read((char*) &v.V, sizeof(float)*3);
                return is;
            }
        };
    }
}




