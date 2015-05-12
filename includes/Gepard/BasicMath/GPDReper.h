///////////////////////////////////////////////////////////
//  GPDReper.cpp
//  Реализация 	Class GPDReper
//  Создана:   	15-фев-2010 16:35:49
//  Автор: 		Anton
///////////////////////////////////////////////////////////

#pragma once

#include "GPDVector.h"
#include "..\General\basicArray.h"
#include "..\General\basicList.h"

namespace Gepard
{
    namespace BasicMath
    {
        using namespace std;

        class GPDVector;
        class GPDPoint;

        /**
         * Класс репер
         */
        class GPDReper
        {		
        public:
            GPDReper();
            ~GPDReper();
            GPDReper(Gepard::BasicMath::GPDVector e1, Gepard::BasicMath::GPDVector e2, Gepard::BasicMath::GPDVector e3, Gepard::BasicMath::GPDVector r);			
            /**
             * Вектор репера
             */
            Gepard::BasicMath::GPDVector E1,E2,E3,R;
                        
            /**
             * получить глобальный репер
             */
            static GPDReper getGlobalReper();
            /**
             * получить расстояние между реперами
             */
            double getLength(GPDReper Rep);
            /**
             * перевод текущего репера из старой системы координат в новую. Текущий репер не
             * меняется, если rewritecurrent=false
             */
            GPDReper getTransformed(GPDReper &OLD, GPDReper &NEW, bool rewriteCurrent=false);
            /**
             * перевод текущего репера из старой системы координат в новую. Меняется текущий репер
             */
            void Transform(GPDReper &OLD, GPDReper &NEW);
            /**
             * Перевод репера в строку
             */
            std::string toString();
            /**
             * перевод репера (вектора r) в точку
             */
            Gepard::BasicMath::GPDPoint toPoint();
            /**
             * обнулить репер
             */
            void setNull();
            /**
             * Приравнять реперы
             */
            void setReper(GPDReper Rep);
            /**
             * Приравнять реперы
             */
            void operator=(GPDReper Rep);
            /**
             * равны ли
             */
            bool isEquals(GPDReper Rep);
            /**
             * равны ли
             */
            bool operator==(GPDReper Rep);

            /**
             *  Инвертировать оси репера
             */
            void InvertAxes();

            /**
            * Преобразование репера по двум углам и оси репера
            * Входные параметры:
            * vector_index - вектор, который будет отклоняться в текущем репере (E1,E2,E3)
            * n - ось (в глобальных координатах), от которой заданы отклонения fi psi
            * Углы fi и psi (наклона и поворота соответственно)
             */
            void morphByAngleAndReperAxis(GPDVector n, int vector_index, double fi, double psi);

            /**
            * Преобразование репера по двум углам и оси репера
            * Входные параметры:
            * vector_index - вектор, который будет отклоняться в текущем репере (E1,E2,E3)
            * vector_index так же является осью, от которой будут заданы отклонения
            * Углы fi и psi (наклона и поворота соответственно)
             */
            void morphByAngleAndReperAxis(int vector_index, double fi, double psi);

            /**
            * Поворот репера на вектор вокруг заданной точки
            * Входные параметры:
            * Репер E={f0, f1, f2, f3} , который надо повернуть
            * Точка A  В ГЛОБАЛЬНЫХ КООРДИНАТАХ!
            * Точка B  В ГЛОБАЛЬНЫХ КООРДИНАТАХ!
            * (Т.е. AB - вектор, на который надо повернуть поверхность)
            * Точка O1'  В ГЛОБАЛЬНЫХ КООРДИНАТАХ!
            * O1' - точка, вокруг которой поворачиваем
            */
            //void morphByVectorAroundPoint(GPDPoint A, GPDPoint B, GPDPoint O1);

            /**
            Функция переносит репер на вектор
            */
            void moveOnVector(GPDVector Vec);

            /**
             * Преобразование репера по двум углам и оси
             * входные параметры:
             * n - ось в глобальных координатах, относительно которой будет отклоняться репер
             * угол fi
             */
            void morphByAngleAndAxis(GPDVector N, double fi);

        private:
            /**
            * Расчет детерминанта матрицы - нужно для getTransformed
            */
            inline double CalcDeterminant(double Matr[3][3]){
                double d1, d2;
                d1=Matr[0][0]*Matr[1][1]*Matr[2][2];
                d1+=Matr[0][2]*Matr[1][0]*Matr[2][1];
                d1+=Matr[0][1]*Matr[1][2]*Matr[2][0];

                d2=Matr[0][2]*Matr[1][1]*Matr[2][0];
                d2+=Matr[2][1]*Matr[1][2]*Matr[0][0];
                d2+=Matr[1][0]*Matr[0][1]*Matr[2][2];

                return d2-d1;
            }
        public:

            //перегруженный оператор вывода
            friend ostream& operator<<(ostream& os, const GPDReper &reper)
            {				
                os.write((char *)&reper,sizeof(GPDReper));
                return os;

            }
            //перегруженный оператор ввода
            friend istream& operator>>(istream& is, GPDReper &reper)
            {
                is.read((char *)&reper,sizeof(GPDReper));
                return is;
            }


        };		
        typedef GPDReper* GPDReperPtr;	//Указатель на репер
        typedef GPDReper& GPDReperRef;	//Ссылка на репер
        typedef Gepard::General::basicArray<GPDReper> GPDReperArray; //Массив реперов
        typedef Gepard::General::basicList<GPDReper> GPDReperList;	 //Список реперов
        typedef Gepard::General::basicArray<GPDReperPtr> GPDReperPtrArray;	//Массив указателей на репер. НЕ ЗАБУДЬ УДАЛИТЬ! (Если надо).
        typedef Gepard::General::basicList<GPDReperPtr> GPDReperPtrList;	//Список указателей на репер. НЕ ЗАБУДЬ УДАЛИТЬ! (Если надо).

    };//end namespace

};//end namespace

