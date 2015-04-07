///////////////////////////////////////////////////////////
//  MathModel.h
//  Реализация Class MathModel
//  Создано:      19-ноя-2012 17:15:15
//  Автор: Dr_Freeman
///////////////////////////////////////////////////////////

#if !defined(GPD_C2A65ED7_44F2_4e00_B56F_59DAEA62C821__INCLUDED_)
#define GPD_C2A65ED7_44F2_4e00_B56F_59DAEA62C821__INCLUDED_

#include "Topology_Geometry\GPDSolid.h"
#include "Assembly\AssemblyStructure.h"
#include "Tolerances\DatumFaceReferenceList.h"
#include "Tolerances\Tolerance.h"
#include "Tolerances/Fit.h"
#include "Analysis\KeyCharacteristics.h"

namespace Gepard
{
    /**
     * Математическая модель - здесь содержится структура геометрии, список
     * допусков/посадок, граф сборки
     */
    class MathModel
    {

    public:
        MathModel();
        virtual ~MathModel();
       
        /**
         * Геометрическая топология - массив тел (CLOSED_SHELL)
         */
        Gepard::Topology_Geometry::GPDSolidList Solids;

        /**
         * Импорт файла в формате GPD
         */
        int importGPD(std::ifstream &gpd_file);
        /**
         * Импорт файла в формате STEP
         */
        int importSTEP(std::string _filenname);
        /**
         * Сохранить модель в формате GPD
         */
        void saveGPD(std::ostream &gpd_file);

        /**
         *  Подготовка геометрических данных - расчет геометрии и триангуляции
         */
        void PrepareGeometry();

        /**
         *  Закрыть модель - удалить всю информацию
         */
        void CloseModel();

        /**
         *  Получить ссылку на список последних импортированных деталей
         */
        Gepard::Topology_Geometry::GPDSolidPtrList& GetLastOpenedSolidsList();

        /**
         *  Получить указатель на граф сборки
         */
        Gepard::Assembly::AssemblyGraph* GetAssemblyGraphPtr();

        /**
         *  Получить указатель на допуск по номеру
         */
        Gepard::Tolerances::Tolerance* FindTolByUIN(unsigned int tUIN);

        /**
        * Установить зачение счётчика тел
        */
        void SetSolidsUINCounterValue(unsigned int cnt);

        /**
        * Возвращает текущий номер тела (последний+1)                           
        */
        unsigned int GetCurrentSolidUIN();

        /**
         *  Возвращает текущий номер допуска
         */
        unsigned int GetCurrentTolUIN();

         /**
         *  Возвращает текущий номер условия сопряжения
         */
        unsigned int GetCurrentMR_UIN();

        /**
        * Задаёт номера, последним загруженным телам                           
        */
        void SetLastSolidsUIN();

        /**
         *  Поиск детали по UIN
         */
        Gepard::Topology_Geometry::GPDSolidPtr FindSolidByUIN(unsigned int s_uin);

        /**
         *  Найти узел графа по номеру узла
         */
        Gepard::Assembly::AssemblyNode* FindAssemblyNodeByUIN(unsigned int asm_node_uin);

        /**
         *  Найти условие сопряжения по номеру
         */
        Gepard::Assembly::MatingRelation* FindMatingRelationByUIN(unsigned int mr_uin);

        /**
         *  Получить указатель на массив базовых поверхностей
         */
        Gepard::Tolerances::DatumFaceReferenceList* GetDatumFacesListPtr();
        
        /**
         *  Получить список тел
         */
        //Gepard::Topology_Geometry::GPDSolidList& GetSolidsList();

        /**
         *  Удалить тело
         */
        bool DeleteSolid(Gepard::Topology_Geometry::GPDSolidPtr solidPtr);

        /**
         *  Добавить копию допуска (указатель можно удалять)
         */
        Gepard::Tolerances::TolerancePtr AddToleranceCopy(Gepard::Tolerances::TolerancePtr _tolerance);

        /**
         *  Получить указатель на массив допусков
         */
        Gepard::Tolerances::TolerancePtrList* GetTolerancePtrListPtr();

        /**
         *  Получить указатель на массив КХ
         */
        Gepard::Analysis::KeyCharacteristicsPtrArray* GetKCArrayPtr();

        /**
         *  Добавить ключевую характеристику
         */
        Gepard::Analysis::KeyCharacteristics* AddKeyCharacteristics(Gepard::Analysis::KeyCharacteristics *kc);

        /**
         *  Удалить ключевую характеристику
         */
        void DeleteKeyCharacteristic(Gepard::Analysis::KeyCharacteristics *kc_ptr);

        /**
        *	Добавить посадку
        */
        void AddFit(Gepard::Tolerances::Fit _fit);

        /**
         *	Удаляет посадку
         */
        void DeleteFit(Gepard::Tolerances::Fit *fit);

        /**
         *	Получить указатель на массив посадок
         */

        Gepard::Tolerances::FitArray* getFitArrayPtr();

    private:

        /**
         * Счётчик тел
         */        
        unsigned int _soldsUINCounter;

        /**
         *  Счетчик допусков
         */
        unsigned int _tolUINCounter;

        /**
         *  Счетчик условий сопряжений
         */
        unsigned int _mrUINCounter;

        /**
         * Граф сборки
         */
        Gepard::Assembly::AssemblyGraph AsmGraph;

        /**
         *  Массив указателей на последние добавленные тела
         */
        Gepard::Topology_Geometry::GPDSolidPtrList lastSolidsPtrList;

        /**
         *  Массив базовых поверхностей
         */
        Gepard::Tolerances::DatumFaceReferenceList datumFacesArray;

        /**
         *  Массив допусков для данной модели
         */
        Gepard::Tolerances::TolerancePtrList tolerancePtrList;

        /**
         *  Массив посадок
         */
        Gepard::Tolerances::FitArray fitArray;

        /**
         *  Массив ключевых характеристик для данной модели
         */
        Gepard::Analysis::KeyCharacteristicsPtrArray KCPtrArray;

        /**
         *  Установить флаг удаления геометрии для всех тел
         */
        void SetSolidsDeleteFlag();

        /**
         *  Добавить в граф сборки указанные детали
         */
        void AddSolidsToAssmGraph(Gepard::Topology_Geometry::GPDSolidPtrList &solidList);

        /**
         *  Очистить список допусков
         */
        void ClearTolerances();

        /**
         *  Очистить список ключевых характеристик
         */
        void ClearKeyCharacteristics();

    };

}

#endif // !defined(GPD_C2A65ED7_44F2_4e00_B56F_59DAEA62C821__INCLUDED_)


