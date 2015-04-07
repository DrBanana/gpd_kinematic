///////////////////////////////////////////////////////////
//  GPDSolid.h
//  Реализация Class GPDSolid
//  Создано:      15-ноя-2012 14:45:14
//  Автор: Dr_Freeman
///////////////////////////////////////////////////////////

#if !defined(EA_0EA5FD15_D6DA_4bae_94E1_9358EC1042CA__INCLUDED_)
#define EA_0EA5FD15_D6DA_4bae_94E1_9358EC1042CA__INCLUDED_

#include "../BasicMath/GPDReper.h"
#include "../Surfaces/GPDSurface.h"
#include "../Callbacks/CB_OutputMessages.h"
#include "GPDFace.h"


namespace Gepard
{
    namespace Topology_Geometry
    {
        /**
         * Класс тела. Состоит из граней.
         */
        class GPDSolid
        {

        public:
            GPDSolid();
            virtual ~GPDSolid();

            /**
             * Репер тела. Реперы всех поверхностей (граней) заданы в нем
             */
            Gepard::BasicMath::GPDReper SolidReper;
          
            /**
             * Массив граней.
             */
            Gepard::Topology_Geometry::GPDFaceList Faces;

            /**
             *	Добавить грань
             */
            Gepard::Topology_Geometry::GPDFacePtr AddFace(Gepard::Topology_Geometry::GPDFaceRef face);

            /**
             *	Выставить флаг удаления геометрии граней в деструкторе
             */
            void setDeleteGeometryFacesFlag(bool isDelFacesGeom);

            /**
             *  Функция запускает расчет внутренней геометрии детали - 
             *  граней и ребер
             */
            void CalcSolidGeometry();

            /**
             *  Функция рассчитывает триангуляцию для всех граней тела
             */
            void CalcTriangulation(int numFace = -1);

            /**
             *  Функция копирует деталь и помещает ее в заданный массив.
             *  Возврат - указатель на скопированную деталь
             */
            GPDSolid* CopySolidToList(Gepard::General::basicList<GPDSolid>& solidList);

            /**
             *  Обновить положение детали в соответствии с новым репером
             */
            void UpdateSolidPosition(Gepard::BasicMath::GPDReper PosReper);

            /**
             *  Получить имя тела
             */
            const char* GetSolidName();

            /**
             *  Получить имя тела
             */
            std::string GetSolidNameStr();

            /**
             *  Установить имя тела
             */
            void SetSolidName(std::string _solidName);

            /**
             *  Получить номер тела
             */
            unsigned int GetSolidUIN();

            /**
             *  Найти грань по UIN
             */
            Gepard::Topology_Geometry::GPDFace* FindFaceByUIN(unsigned int f_uin);

            /**
             *  Сформировать массив соответствий - указатель на грань - номер грани
             */
            void FillFacesIdArray(GPDFacePtrToComplexIndex &facesComplexIndexes);

            /**
             *  Установить номер тела
             */
            void SetSolidUIN(unsigned int _uin);

            /**
             *	Получить накрывающий параллелепипед
             */
            Gepard::BasicMath::BoundingBox GetBoundingBox();


            //перегруженный оператор вывода
            friend ostream& GPDSolid::operator<<(ostream& os, Gepard::Topology_Geometry::GPDSolid &solid)
            {	
                os.write((char *) &solid.m_UIN, sizeof solid.m_UIN);

                int nameSize = solid.SolidName.size();
                os.write((char *) &nameSize, sizeof nameSize);                
                if (nameSize > 0) os.write(solid.SolidName.c_str(), solid.SolidName.size());
                
                os << solid.SolidReper;

                auto faces_of_solid = &solid.Faces;
                unsigned int faces_count = faces_of_solid->getCount();

                os.write((char *) &faces_count,sizeof faces_count);

                unsigned int _ind = 0;
                faces_of_solid->set_start();
                while(auto facePtr = faces_of_solid->get_next())
                {                    
                    os << *facePtr; 
                    _ind++;
                }//while faces                

                return os;
            }

            //перегруженный оператор ввода
            friend istream& operator>>(istream& is, Gepard::Topology_Geometry::GPDSolid &solid)
            {
                char sName[255];

                //Номер тела                
                is.read((char *) &solid.m_UIN, sizeof solid.m_UIN);

                //Имя тела
                int nameSize = 0;
                is.read((char *) &nameSize, sizeof nameSize);

                if (nameSize>0) {                    
                    is.read(sName, nameSize);
                    sName[nameSize] = '\0';
                    solid.SolidName = sName;                    
                }

                is >> solid.SolidReper;

                //считываем количество граней
                int _faces_count = 0;
                is.read((char* ) &_faces_count, sizeof _faces_count);

                for (int i=0; i<_faces_count; i++)
                {
                    auto facePtr = solid.AddFace(GPDFace());                    
                    is >> *facePtr;
                    facePtr->parentSolidPtr = &solid;
                }//for

                return is;
            }
            
        private:

            /**
             *	Флаг удаления памяти геометрии граней в деструкторе тела
             */
            bool isDeleteFacesGeometryFlag;

            /**
             *  Имя тела
             */
            std::string SolidName;

            /**
             * Номер тела в сборке.
             */
            unsigned int m_UIN;

            /**
             *	Накрывающий параллелепипед для тела
             */
            Gepard::BasicMath::BoundingBox boundingBox;

            /**
             *	Посчитать ограничивающий параллелепипед
             */
            void CalcBoundingBox();

        };
        typedef GPDSolid* GPDSolidPtr;
        typedef GPDSolid& GPDSolidRef;
        typedef Gepard::General::basicArray<GPDSolid> GPDSolidArray;
        typedef Gepard::General::basicArray<GPDSolidPtr> GPDSolidPtrArray;
        typedef Gepard::General::basicList<GPDSolid> GPDSolidList;
        typedef Gepard::General::basicList<GPDSolidPtr> GPDSolidPtrList;
    }

}
#endif // !defined(EA_0EA5FD15_D6DA_4bae_94E1_9358EC1042CA__INCLUDED_)
