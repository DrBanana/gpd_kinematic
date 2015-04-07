///////////////////////////////////////////////////////////
//  Tolerance.cpp
//  Реализация 	Class Tolerance
//  Создана:   	16-фев-2010 15:49:06
//  Автор: 		Anton
//  Рефакторинг: 31.01.14 г.
///////////////////////////////////////////////////////////

#pragma once

#include "TOLERANCE_TYPE.h"

#include "../BasicMath/GPDPoint.h"
#include "../BasicMath/GPDReper.h"
#include "../Topology_Geometry/GPDFace.h"
#include "DatumFaceReferenceList.h"
#include "ConfSpaceType.h"
#include "CSParam.h"

#include "../BasicMath/additionalFuncs.h"

namespace Gepard
{    
    namespace Assembly	        {class AssemblyNode;}

    class MathModel;

    using namespace BasicMath;
    using namespace Topology_Geometry;

    namespace Tolerances
    {        
        struct Fit;

        /**
         * Структура допуска
         */		
        class Tolerance
        {
            friend class CombinedTolerance;

        public:
            Tolerance();
            virtual ~Tolerance();

            /**
             * нижнее отклонение
             */
            double d_low;
            /**
             * верхнее отклонение
             */
            double d_high;
        
            /**
             *	Поверхность, на которую назначен допуск
             */
            Gepard::Topology_Geometry::GPDFacePtr tol_face;

            /**
             *  Массив базовых поверхностей (относительно которых назначен допуск)
             */
            DatumFaceReferenceList DatumRefList;

            /**
             * тип допуска
             */
            Gepard::Tolerances::TOLERANCE_TYPE TolType;
            
            /**
             *	Нормируемый участок на карте
             */
            double u0,u1,v0,v1;

            /**
             *	Контрольный репер нормируемого участка
             */
            Gepard::BasicMath::GPDReper Control_Reper;

            /**
             *	Узел графа сборки
             */	
            //Gepard::Assembly::AssemblyNode *parentAsmNode;

            /**
             *  Конфигурационное пространство, соответствующее данному допуску
             */
            ConfSpaceType SPACE_TYPE;

            /**
             *  Параметры К.П.
             */
            CSParamsList cs;

            /**
             *  Максимальное значение одного из параметров КП (в зависимости от типа)
             */
            double max_gamma;
                     
            /**
             *  Массив названий параметров для точек К.П. (fi, psi)
             */
            std::vector<std::string> csParNames;

            /**
             *  Номинальная грань была изменена
             */
            bool isNominalModified;

            /**
             *  Номер допуска
             */
            unsigned int UIN;

            /**
             *  Шаблонная функция создает допуск по типу
             */
            template <class T>
            static Gepard::Tolerances::Tolerance* CreateTolerance();

            /**
             *  Создать допуск по типу
             */
            static Gepard::Tolerances::Tolerance* CreateTolerance(TOLERANCE_TYPE tolType);

            /**
             *	Создать конфигурационное пространство по заданным параметрам
             */
            void CalcConfigurationSpace(unsigned int COUNT_CONF_POINTS=0);

            /**
             *	Вычислить положение контрольного репера норм. участка и отрезков a,b
             */
            void CalcControlSegmentReper();
          
            /**
             *	Обнулить значения допуска
             */
            void SetNull();

            /**
             *  Добавить точку К.П. к текущему пространству
             */
            CSParam* AddCSParam(double fi, double psi, bool calcTol=true);

            /**
             *  Найти индекс точки КП по параметру
             */
            int FindCS(Gepard::Tolerances::CSParam par);

            /**
             *  Удалить точку КП (вместе с гранью)
             */
            void DeleteCSPoint(Gepard::Tolerances::CSParam par);

            /**
             *  Получить число точек К.П.
             */
            virtual unsigned int GetCountCS() { return cs.getCount(); }

            /**
             *  Получить функцию модификации точек по значению точки КП             
             */
            virtual TModifyPointsFunc GetPointsModificationFunc(CSParam par);

            /**
             *  Получить функцию модификации точек по индексу точки КП
             *  isForVisual - нужно ли модифицировать параметры для визуализации
             */
            virtual TModifyPointsFunc GetPointsModificationFunc(unsigned int cs_index, bool isForVisual = false);

            /**
             *  Модифицировать параметры грани по значению точки КП
             */
            virtual void ModifyFaceParamsByCS(CSParam par);

            /**
             *  Модифицировать параметры грани по индексу точки КП
             */
            virtual void ModifyFaceParamsByCS(int csIndex);

            /**
             *  Сбросить параметры грани в номинал
             */
            virtual void DropFaceParamsToNominal();

            /**
             *  Изменить параметры для отображения данного КП
             */
            void ModifyParamsForVisualization(CSParam &par);

            /**
             *  Посчитать значение отклонения для данного параметра точки К.П.
             */
            double CalcToleranceByCSParams(CSParam par);

            /**
             *  Посчитать значение gamma (для каждого допуска разное)
             *  по значению допуска и параметрам поверхности
             */
            virtual double CalcGammaByTolValue(double tolValue);

            /**
             *  Подходит ли данная поверхность для данного допуска
             */
            virtual bool CheckFace(Gepard::Topology_Geometry::GPDFacePtr facePtr);

            /**
             *  Является ли допуск комбинированным
             */
            virtual bool isCombined();

            /**
             *  Допуск задан с помощью посадки (на диаметр)
             */
            virtual bool isFit();

            /**
             * сохранение в файл
             */
            virtual void saveToFile(std::ostream& os);

            /**
             * чтение из файла
             */
            virtual void readFromFile(std::istream& is, Gepard::MathModel *mathModelPtr);
                   
        protected:

            /**
             *  Получить параметры поверхности, на которую назначен допуск
             */
            void GetTolFaceParams(Gepard::Surfaces::SURFACE_TYPES &sType, double &A, double &B);

            /**
             *  Вычислить конфигурационное пространство для допуска
             */            
            virtual double calcConfigurationSpaceTol( unsigned int COUNT_CONF_POINTS );

            /**
             *  Вычислить значение допуска по значению параметра точки К.П.
             */
            virtual double calcTolValueByCSParam(CSParam par, double A=0.0, double B=0.0);           
          
            /**
             *  Получить коэффициент для визуализации допуска
             */
            virtual double GetVisualKoeff();

            /**
             *	Расчет конфигурационного пространства сферы
             */
            void calcSphereConfigurationSpace(double gamma, unsigned int COUNT_CONF_POINTS);

            /**
             *	Расчет конфигурационного пространства дуги
             */
            void calcArcConfigurationSpace(double gamma, unsigned int COUNT_CONF_POINTS);

            /**
             *	Расчет конфигурационного пространства линии
             */
            void calcLineConfigurationSpace(unsigned int COUNT_CONF_POINTS);

            /**
             *	Расчет конфигурационного пространства круга
             */
            void calcCircleConfigurationSpace(double gamma, unsigned int COUNT_CONF_POINTS);


            //функции расчета нормируемого участка - репера и отрезков в зависимости от допуска

            /**
             *	Вычислимть параметры репера нормирующего участка
             */
            void calcSegReper(); 

             /**
             *  Номинальный репер грани - для реализации отмены изменений
             */
            GPDReper nPoint_Reper;

        };

        typedef Tolerance* TolerancePtr;
        typedef Gepard::General::basicList<Tolerance>     ToleranceList;
        typedef Gepard::General::basicList<TolerancePtr>  TolerancePtrList;
        typedef Gepard::General::basicArray<Tolerance>    ToleranceArray;
        typedef Gepard::General::basicArray<TolerancePtr> TolerancePtrArray;


        /**
         *  Номинальная грань с параметрами изменения
         */
        struct TolCSFace 
        {
            TolCSFace();
            TolCSFace( Gepard::Tolerances::Tolerance* t ) : _tolPtr(t), _facePtr(t->tol_face) {};
            TolCSFace( Gepard::Tolerances::Tolerance* t,
                       Gepard::Tolerances::CSParam cs) 
                       : _tolPtr(t), _facePtr(t->tol_face), _par(cs) {};
            TolCSFace( Gepard::Topology_Geometry::GPDFacePtr f, 
                       Gepard::Tolerances::Tolerance* t, 
                       Gepard::Tolerances::CSParam cs )
                       : _facePtr(f), _tolPtr(t), _par(cs) {};

            Gepard::Topology_Geometry::GPDFacePtr _facePtr; //Номинальная грань
            Gepard::Tolerances::Tolerance*        _tolPtr;  //Указатель на допуск
            Gepard::Tolerances::CSParam           _par;     //Параметр точки К.П.
        };

        typedef Gepard::General::basicList<TolCSFace> TolCSFaceList;

    }

}

