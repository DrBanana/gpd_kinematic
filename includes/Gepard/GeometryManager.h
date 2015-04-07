///////////////////////////////////////////////////////////
//  GeometryManager.h
//  Менеджер геометрии ГеПАРД
//  Создано:  29-авг-2013 15:41:21
//  Автор:    Dr_Freeman
///////////////////////////////////////////////////////////

#ifndef GEOMETRYMANAGER_H
#define GEOMETRYMANAGER_H

#include "MathModel.h"
#include "Visualization/GPDGeometryRender.h"
#include <map>

namespace Gepard {

    using namespace Visualization;

    class GeometryManager 
    {
    public:
        GeometryManager();
        ~GeometryManager();
               

        /**
        * импорт данных из STEP
        */
        int importSTEP(std::string stpFileName, GPDGeometryRender *gCamera=nullptr);


        /**
         *	Сохранить данные в формат GPD
         */
        void saveGPD(std::string gpdFileName);

        /**
        *	импорт данных из GPD
        */
        int importGPD(std::string gpdFileName, GPDGeometryRender *gCamera=nullptr);
                      

        /**
        *	Получить граф сборки
        */
        Gepard::Assembly::AssemblyGraph* getAssemblyGraph();

         /**
         *	"Закрыть" - удаляет всю геометрию
         */
        void CloseAll();

        /**
         *  Заполнить массив номеров рендеров, в которых находится деталь
         */
        void FillSolidRendersList( Gepard::Topology_Geometry::GPDSolidPtr SolidPtr, 
                                   std::list<Gepard::Visualization::GPDGeometryRender*> &RendersList );

        /**
         *  Получить указатель на мат-модель
         */
        Gepard::MathModel* GetMathModelPtr();

        /**
         *  Установить цвет детали в рендерах
         */
        void SetSolidColor( Gepard::Topology_Geometry::GPDSolidPtr solPtr, 
                            Gepard::Visualization::GColor _color);

        /**
         *  Сбросить цвет детали
         */
        void DropSolidColor(Gepard::Topology_Geometry::GPDSolidPtr solPtr);

        /**
         *  Спрятать деталь (удалить из всех рендеров)
         */
        void HideSolid(Gepard::Topology_Geometry::GPDSolidPtr solPtr);

        /**
         *  Показать деталь в заданной камере
         */
        void ShowSolidInRender( Gepard::Topology_Geometry::GPDSolidPtr solPtr, 
                                Gepard::Visualization::GCamera *camera, 
                                bool isUpdateCam = true );

        /**
         *  Удалить деталь
         */
        void DeleteSolid( Gepard::Topology_Geometry::GPDSolidPtr solPtr );

        /**
         *  Удалить условие сопряжения
         */
        void DeleteMatingRelation( Gepard::Assembly::MatingRelation* mrPtr);

        /**
         *  Удалить ключевую характеристику
         */
        void DeleteKeyCharacteristic( Gepard::Analysis::KeyCharacteristics *kcPtr );

        /**
        *	Добавить посадку
        */
        void AddFit(Gepard::Tolerances::Fit fit_);

        /**
         *	Удалиить посадку
         */
        void DeleteFit(Gepard::Tolerances::Fit *fit);

        private:
        /**
         *  Математическая модель - все данные для ГеПАРДа содержатся здесь
         */
        MathModel gpdMathModel;

        /**
         *  Ассоциативный массив: деталь и ее цвет
         */
        std::map< Gepard::Topology_Geometry::GPDSolid*,
                  Gepard::Visualization::GColor >   Solid2Color;

        /**
         *  Ассоциативный массив: деталь и ее материал
         */
        std::map< Gepard::Topology_Geometry::GPDSolid*,
                  Gepard::Visualization::ObjectMaterial > Solid2Material;
    };
}


#endif



