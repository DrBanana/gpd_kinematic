///////////////////////////////////////////////////////////
//  GPDFace.h
//  Реализация Class GPDFace
//  Создано:      15-ноя-2012 16:53:48
//  Автор: Dr_Freeman
///////////////////////////////////////////////////////////

#if !defined(EA_27D69AAA_B986_4142_8602_0BD2ACFA8FCD__INCLUDED_)
#define EA_27D69AAA_B986_4142_8602_0BD2ACFA8FCD__INCLUDED_

#include "GPDFaceBound.h"
#include "../Surfaces/GPDSurface.h"
#include "../General/basicArray.h"

#include <map>
#include <BOOST/unordered_map.hpp>

namespace Gepard
{
    namespace Topology_Geometry
    {
        using namespace Gepard::Visualization::Triangulation;        

        class GPDSolid;
        /**
         * Грань.
         */
        class GPDFace
        {
        public:            
            /**
             *	Конструктор 
             */
            GPDFace();
            /**
             *	Создать грань с заданной геометрией
             */
            GPDFace( Gepard::Surfaces::GPDSurface* surf_geom, 
                     Gepard::Topology_Geometry::GPDSolid *parent_solidPtr, 
                     bool face_orientation=true);

            /**
             *	Создать грань по типу поверхности
             */
            GPDFace( Gepard::Surfaces::SURFACE_TYPES surface_type, 
                     Gepard::Topology_Geometry::GPDSolid *parent_solidPtr, 
                     bool face_orientation=true );

            virtual ~GPDFace();			

            /**
             * Массив ребер грани - границы.
             */
            Gepard::Topology_Geometry::GPDFaceBoundList Bounds;
            /**
             * Геометрический носитель грани
             */
            Gepard::Surfaces::GPDSurface* geometry;
            /**
             * Ориентация грани - для правильного определения нормалей контура на карте
             * поверхности.
             */
            bool orientation;
            /**
             * Родительский CLOSED_SHELL - GPDSolid
             */
            GPDSolid* parentSolidPtr;

            /**
             *  Массив секторов для триангуляции
             */
            Tri_MapSectorList tri_MapSectorList;            

            /**
             *	Удалить память геометрической составляющей из грани
             */
            void deleteGeometry();

            /**
             *	Удалить память у всех ребер и очистить список ребер
             */
            void deleteBounds();

            /**
             *	Задать геометрию грани, если геометрия еще не была задана
             *	Возвращаемые значения: NULL - не удалось создать,
             *	Иначе - указатель на геометрию
             */
            Gepard::Surfaces::GPDSurface* createFaceGeometry(Gepard::Surfaces::SURFACE_TYPES surface_type);

            /**
             *  Создать геометрию по типу и получить на нее указатель
             */
            static Gepard::Surfaces::GPDSurface* createGeometry(Gepard::Surfaces::SURFACE_TYPES surface_type);

            /**
             *	Выставить флаг удаления геометрии в деструкторе,
             *	в том числе удаления ребер
             */
            void setGeometryDeleteFlag(bool isDelGeom);

            /**
             *  Функция запускает расчет поверхности (геометрического носителя грани)
             *  и расчет всех ребер (их геометрич. носителей)
             */
            void CalcFaceGeometry(bool isSecondPass = false);

            /**
             *  Добавить границу грани
             */
            Gepard::Topology_Geometry::GPDFaceBoundPtr AddBound(Gepard::Topology_Geometry::GPDFaceBoundRef bound);

            /**
             *  Функция триангуляции грани
             */
            void Triangulate();    

            /**
             *  Функция вычисляет видимость точки (2D) на карте
             */
            bool CheckPoint2DVisibleDiscrete(Gepard::BasicMath::GPDPoint2dn *p2d);
           

             /**
             *  Хэш-таблица связывает номер сегмента карты с указателем на сегмент 
             *  (из массива tri_MapSectorList)
             */
            boost::unordered_map<unsigned int,Tri_MapSector*> MapSectors_hash;

            /**
             *  Массив номеров видимых секторов поверхности (без треугольников)
             */
            std::list<unsigned int> MapSectors_visible;

             /**
             *  Хэш-таблица соответствия 2D-точек 3D-точкам
            */
            boost::unordered_map<GPDPoint2dPtr,GPDPointPtr> MapPoints_hash;

            /**
             *  Функция копирует грань и помещает ее в заданное тело
             *  ВАЖНО - треугольники не копируются! 
             *  Возврат - указатель на скопированную грань
             */
            GPDFace* CopyFace(GPDSolid* solPtr);

            /**
             *  Функция копирует текущую грань в указанную
             */
            void CopyFace(GPDFace *targetFacePtr, GPDSolid *parentS = nullptr);

            /**
             *  Получить репер поверхности (с геометрического носителя)
             */
            Gepard::BasicMath::GPDReper GetFaceReper();

            /**
             *  Обновить положение грани по новому заданному реперу тела
             */
            void UpdateFacePosBySolidReper(Gepard::BasicMath::GPDReper PosReper);

            /**
             *  Получить строку - тип поверхности
             */
            std::string GetFaceTypeStr();

            /**
             *  Получить идентификатор типа поверхности
             */
            int GetFaceTypeId();

            /**
            * Получить номер тела
            */
            void SetUIN(unsigned int uin);

            /**
            * Задать номер тела
            */
            unsigned int GetUIN();

            /**
             *  Получить тип геометрического носителя
             */
            Gepard::Surfaces::SURFACE_TYPES GetFaceType();

            /**
             *  Функция копирования параметров геометрии по типу
             */
            void CopyGeometryTo(Gepard::Surfaces::GPDSurface* surfPtr);

            /**
             *  Установить у текущей грани эквивалентные параметры грани fromFacePtr (сбросить грань до номинала)
             *  Текущая грань должна быть копией грани fromFacePtr
             */
            void SetEquivalentParamsFrom(Gepard::Topology_Geometry::GPDFace* fromFacePtr);
           
            /**
             *  Преобразовать точки пересечения с секторами
             *  из старого репера в новый
             */
            void ConvertMapSectorsToBasis( Gepard::BasicMath::GPDReper& oldReper,
                                           Gepard::BasicMath::GPDReper& newReper );

            /**
             *  Преобразовать границы
             *  из старого репера в новый
             */
            void ConvertBoundsToBasis(Gepard::BasicMath::GPDReper& oldReper,
                                      Gepard::BasicMath::GPDReper& newReper );

            /**
             *  Преобразовать в локальную систему координат (GReper->point_reper)
             */
            void ConvertToLocalBasis();

            /**
             *  Преобразовать в глобальную систему координат (point_reper->GReper)
             */
            void ConvertToGlobalBasis();

             /**
             *  Преобразовать границы с помощью функции преобразования
             *  Шаблон функции: GPDPoint2d p2d - координаты контура на карте, GPDPoint &P - 3D точка контура
             */
            void ModifyBounds(Gepard::BasicMath::TModifyPointsFunc &funcRef);

            /**
             *  Преобразовать точки пересечения с секторами функцией преобразования
             *  Шаблон функции: GPDPoint2d p2d - координаты контура на карте, GPDPoint &P - 3D точка контура
             */
            void ModifyMapSectors(Gepard::BasicMath::TModifyPointsFunc &funcRef);

            /**
             *	Получить ограничивающий параллелепипед
             */
            Gepard::BasicMath::BoundingBox GetBoundingBox();

#ifdef TRIANGULATION_CHECK_TRI
            public:
#else
            private:
#endif
            /**
            *  Функция предтриангуляции - для теста
            */
            void PreTriangulate();

        private:

            /**
            *  Функция формирует массив видимых секторов
            */
            void ProcessVisibleMapSectors();

            /**
             * Уникальный номер поверхности
             */
            unsigned long m_UIN;       

            /**
             *	Флаг удаления геометрии грани в деструкторе
             */
            bool isDeleteGeometryFlag;

            /**
             *	Накрывающий параллелепипед по трем осям (x,y,z)
             */
            BoundingBox boundingBox;

            /**
             *	Посчитать накрывающий параллелепипед из границ
             */
            void CalcBoundingBox();

            /**
             *  Шаблонная функция присваивает геометрические параметры по типу
             */
            template <class T>
            void SetGeometryData(Gepard::Surfaces::GPDSurface* geometryPtr);

            /**
             *  Шаблонная функция создает геометрию по типу
             */
            template <class T>
            static Gepard::Surfaces::GPDSurface* CreateGeometry();
           

            //перегруженный оператор вывода
            friend ostream& GPDFace::operator<<(ostream& os, Gepard::Topology_Geometry::GPDFace &face)
            {	
                //получаем и записываем тип грани
                int _tst = face.GetFaceTypeId();      
                os.write((char *) &_tst,sizeof _tst);
                                
                //сохраняем геометрию грани
                face.geometry->saveToFile(os);
            
                //получаем и записываем колличество bounds
                unsigned int _bound_count = face.Bounds.getCount();
                os.write((char *) &_bound_count,sizeof _bound_count);

                //для каждого bound записываем ребра и геометрию
                face.Bounds.set_start();
                while(auto boundPtr = face.Bounds.get_next())
                {
                    os << *boundPtr;
                }//while bounds

                os.write((char *) &face.m_UIN, sizeof face.m_UIN);                
                os.write((char *) &face.orientation,sizeof face.orientation);

                return os;

            }//end of <<           
         
            //перегруженный оператор ввода
            friend istream& operator>>(istream& is, Gepard::Topology_Geometry::GPDFace &face)
            {
                //Загружаем геометрию грани
                
                //считываем тип грани
                unsigned int _face_type = 0;
                is.read((char *) &_face_type , sizeof _face_type);

                //исходя из считанного типа считываем геометрию грани
                Gepard::Surfaces::GPDSurface* _surfPtr =                     
                    face.createFaceGeometry((Gepard::Surfaces::SURFACE_TYPES)_face_type);
                _surfPtr->readFromFile(is);

                //Количество границ
                unsigned int _bound_count = 0;
                is.read((char* ) &_bound_count, sizeof _bound_count);

                for (unsigned int i=0; i<_bound_count; i++ )
                {                    
                    //добавляем границу к грани
                    auto boundPtr = face.AddBound(GPDFaceBound());
                    is >> *boundPtr;

                }//for i

                is.read((char *) &face.m_UIN, sizeof face.m_UIN);
                is.read((char *) &face.orientation, sizeof face.orientation);

                return is;
            }

        };


        typedef GPDFace* GPDFacePtr;
        typedef GPDFace& GPDFaceRef;
        typedef	Gepard::General::basicArray<GPDFace> GPDFaceArray;
        typedef	Gepard::General::basicArray<GPDFacePtr> GPDFacePtrArray;
        typedef	Gepard::General::basicList<GPDFace> GPDFaceList;
        typedef	Gepard::General::basicList<GPDFacePtr> GPDFacePtrList;

        //Ассоциативный массив - Указатель на поверхность = индекс (тело, грань)
        typedef std::map<GPDFacePtr,std::pair<int,int>> GPDFacePtrToComplexIndex;   

    }

}
#endif // !defined(EA_27D69AAA_B986_4142_8602_0BD2ACFA8FCD__INCLUDED_)
