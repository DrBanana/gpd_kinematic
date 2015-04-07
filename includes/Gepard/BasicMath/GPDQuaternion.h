///////////////////////////////////////////////////////////
//  GPDQuaternion.cpp
//  Реализация 	Class GPDQuaternion
//  Создана:   	15-фев-2010 16:35:49
//  Автор: 		Anton
///////////////////////////////////////////////////////////
#pragma once

#include <string>
#include "basicGPDVector.h"

namespace Gepard
{
    namespace BasicMath
    {
        class GPDVector;

        /**
         *	Класс кватерниона
         */
        class GPDQuaternion : public Gepard::BasicMath::basicGPDVector
        {

        public:
            GPDQuaternion();
            ~GPDQuaternion();
            double R;

            /**
             * Сумма кватернионов
             */
            GPDQuaternion getSum(GPDQuaternion &Q);
            /**
             * Сумма кватернионов
             */
            GPDQuaternion operator+(GPDQuaternion &Q);
            /**
             * Произведение на скаляр
             */
            GPDQuaternion getScalarProduct(double scalar);
            /**
            * Произведение на скаляр
            */
            GPDQuaternion operator *(double scalar);
            /**
             * произведение кватернионов
             */
            GPDQuaternion getProduct(GPDQuaternion &Q);
            /**
             * произведение кватернионов
             */
            GPDQuaternion operator*(GPDQuaternion &Q);
            /**
             * Сопряженный кватернион
             */
            GPDQuaternion getConjugated();

            /**
             *	Получить сопряженный кватернион
             */
            GPDQuaternion operator--();

            /**
             * Получить норму кватерниона
             */
            double getNormalized();
            /**
            * Перевод кватерниона в вектор
            */
            GPDVector toVector();
            /**
             * Перевод кватерниона в строку
             */
            std::string toString();
            /**
             * обнулить
             */
            void setNull();
            /**
             * является ли нулем
             */
            bool isNull();
            /**
             * равны ли два кватерниона
             */
            bool isEquals(GPDQuaternion &Q);
            /**
             * равны ли два кватерниона
             */
            bool operator==(GPDQuaternion &Q);
            /**
            * Установка кватерниона
            */
            void setQuaternion(GPDQuaternion &Q);
            /**
            * Установка кватерниона
            */
            void operator=(GPDQuaternion &Q);
            /**
            * Установка кватерниона
            */
            void operator=(GPDVector &V);
            /**
            * Установка кватерниона
            */
            void setQuaternion(double r, double X, double Y, double Z);
            /**
            * Установка кватерниона
            */
            void setQuaternion(double r, GPDVector &V);

            /**
             *	Быстрое вычисление поворота кватерниона
             *	аналог: (--QTarget)*QAxis*QTarget
             */
            static void FastRotateQuaternionA(GPDQuaternion &QAxis, GPDQuaternion &QTarget, GPDQuaternion &QResult);
            /**
             *	Быстрое вычисление поворота кватерниона
             *	аналог: QTarget*QAxis*(--QTarget)
             */
            static void FastRotateQuaternionB(GPDQuaternion &QAxis, GPDQuaternion &QTarget, GPDQuaternion &QResult);

            /**
             *	Быстрое произведение кватернионов
             */
            static void FastProduct(GPDQuaternion &A, GPDQuaternion &B, GPDQuaternion &QResult);

        };

        typedef GPDQuaternion* GPDQuaternionPtr;	//Указатель на кватернион
        typedef GPDQuaternion& GPDQuaternionRef;	//Ссылка на кватернион

    }

}

