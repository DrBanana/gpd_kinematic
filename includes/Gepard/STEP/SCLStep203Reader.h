///////////////////////////////////////////////////////////
//  SCLStep203Reader.h
//  Реализация  class SCLStep203Reader
//  Создано:    15-дек-2013 11:08:20
//  Автор:      Dr_Freeman
//  Описание:   Класс для чтения STEP (AP203)
//  URL: http://stepcode.org/mw/index.php?title=STEPcode
//       https://github.com/stepcode/stepcode
///////////////////////////////////////////////////////////

#include <string>
#include <vector>
#include <ap203/schema.h>

#include "StepFuncs.h"
#include "AP203_additional_funcs.h"

#include "../Topology_Geometry/GPDSolid.h"
#include "../Surfaces/GPDSurfaces_inc.h"
#include "../Curves/GPDCurve_inc.h"
#include "../BasicMath/basicfuncs.h"

namespace Gepard 
{
    namespace STEP
    {
        /**
         *  Класс импорта геометрии по протоколу AP203 (STEP)
         */
        class SCLStep203Reader
        {
        private:
            /* Указатели на объекты SCL */
            InstMgr *instance_list; ///Массив сущностей
            Registry *registry;		///Словарь
            STEPfile *sfile;		///класс для доступа к объектам STEP

            std::string Schema203;    //Название схемы AP203

        public:
            SCLStep203Reader();
            ~SCLStep203Reader();

            /** 
             * Открыть STEP файл
             * filename - имя файла STEP (AP203)
             * solid_array - массив тел, куда нужно добавить новые
             * Возврат функции:
             * 0 - файл прочитан успешно
             * -1 - файл не может быть открыт и прочитан
             * -2 - неверное имя файла
             * -3 - неверная схема
             */
            int ReadSTEP203( const char* filename, 
                             Gepard::Topology_Geometry::GPDSolidList &solid_array );
            

            /**
             *  Получить ошибки
             */
            std::vector<std::string>& GetErrors();

        private:
            /** 
             * Открыть STEP файл
             * Возврат функции:
             * 0 - файл открыт успешно
             * -1 - файл не может быть открыт и прочитан
             * -2 - неверное имя файла
             * -3 - неверная схема
             */
            int OpenSTEP203(const char* filename);
            
            /** 
             * Добавить к сообщению об ошибке
             */
            void AddError(char *fmt, ...);

            /**
             *  Функция проверяет, верна ли схема файла
             */            
            bool CheckSchema();	

            /**
             * Является ли данный файл сборкой
             */            
            bool isAssembly();

            /** 
             * Функция парсит поверхность STP_ent и добавляет ее к телу solidPtr
             */
            void ParseSurface(STEPentity *STP_ent, Gepard::Topology_Geometry::GPDSolid *solidPtr);
            
            /**
             *	Функция парсит комплексную сущность и выдергивает необходимые параметры
             */
            Gepard::Surfaces::GPDSurface* ParseComplexSurface(STEPentity *STP_ent);

            /**
            *	Функция парсит параметры поверхности B-Spline
            */
            Gepard::Surfaces::GPDSurface* ParseBSplineSurface(STEPentity *STP_ent);
                        
            /**
             *	Функция парсит комплексную сущность, которая задает кривую
             */
            Gepard::Curves::GPDCurve3D* ParseComplexCurve(STEPentity *STP_ent);

            /**
            *	Функция парсит параметры кривой B_spline
            */
            Gepard::Curves::GPDCurve3D* ParseBSplineCurve(STEPentity *STP_ent);

            /**
             *	Вычислить репер по трем точкам (для поверхностей типа B_Spline)
             */
            Gepard::BasicMath::GPDReper CalcSurfReper( Gepard::BasicMath::GPDPoint P0, 
                                                       Gepard::BasicMath::GPDPoint P1, 
                                                       Gepard::BasicMath::GPDPoint P2 );

            /**
             *  Функция парсит границы грани
             */
            void ParseBounds(EntityAggregate *EntAggrPtr, Gepard::Topology_Geometry::GPDFace* facePtr);

            /**
             *	Функция читает параметры контекстов из Advanced_Brep_Shape_Representation
             */
            void ReadAbrepContextItems(STEPentity *STP_ent);

            /* Для обработки ошибок */                        
            std::vector<std::string> _STP203Errors;  ///Все ошибки тут

            /**
             *	Коэффициент для перевода углов
             */
            double angle_factor;

        };

    }//namespace STEP

}//namespace Gepard