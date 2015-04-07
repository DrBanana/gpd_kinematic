///////////////////////////////////////////////////////////
//  FacesRelation.h
//  Отношение между гранями
//  Создано:  3-окт-2014
//  Оригинальный автор: Anton
//  Описание: Виртуальная сущность - для реализации
//  Ключевых свойств, связанных с базовой/зависимой гранями
///////////////////////////////////////////////////////////

#pragma once

#include "KeyFeature.h"
#include "../DeviationVector.h"

namespace Gepard 
{
    class MathModel;

    namespace Assembly { class MatingRelation; }
    namespace Topology_Geometry { class GPDFace; }

    namespace Analysis 
    {
        /**
         *  Виртуальная сущность - Отношение между гранями
         */
        class FacesRelation : public KeyFeature
        {
        public:
            FacesRelation();                       
           
            /**
             *  Указатель на базовую грань
             */
            Gepard::Topology_Geometry::GPDFace* baseFace;

            /**
             *  Указатель на зависимую грань
             */
            Gepard::Topology_Geometry::GPDFace* dependFace;

             /**
             *  Получить базовую и зависимую грани из сопряжения
             */
            void SetMatingRelation(Gepard::Assembly::MatingRelation *mr);

             /**
             *  Получить базовую и зависимую грани из посадки
             */
            //TODO: Сделать установку базовой и зависимой грани из посадки
            //void SetFit();

             /**
             *  Сохранить данные в файл
             */
            void saveToFile(std::ostream &os) override;

            /**
             *  Загрузить данные из файла
             */
            void readFromFile(std::istream &is, Gepard::MathModel *mathModelPtr) override;
        };
    }
}