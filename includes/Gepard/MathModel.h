///////////////////////////////////////////////////////////
//  MathModel.h
//  ���������� Class MathModel
//  �������:      19-���-2012 17:15:15
//  �����: Dr_Freeman
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
     * �������������� ������ - ����� ���������� ��������� ���������, ������
     * ��������/�������, ���� ������
     */
    class MathModel
    {

    public:
        MathModel();
        virtual ~MathModel();
       
        /**
         * �������������� ��������� - ������ ��� (CLOSED_SHELL)
         */
        Gepard::Topology_Geometry::GPDSolidList Solids;

        /**
         * ������ ����� � ������� GPD
         */
        int importGPD(std::ifstream &gpd_file);
        /**
         * ������ ����� � ������� STEP
         */
        int importSTEP(std::string _filenname);
        /**
         * ��������� ������ � ������� GPD
         */
        void saveGPD(std::ostream &gpd_file);

        /**
         *  ���������� �������������� ������ - ������ ��������� � ������������
         */
        void PrepareGeometry();

        /**
         *  ������� ������ - ������� ��� ����������
         */
        void CloseModel();

        /**
         *  �������� ������ �� ������ ��������� ��������������� �������
         */
        Gepard::Topology_Geometry::GPDSolidPtrList& GetLastOpenedSolidsList();

        /**
         *  �������� ��������� �� ���� ������
         */
        Gepard::Assembly::AssemblyGraph* GetAssemblyGraphPtr();

        /**
         *  �������� ��������� �� ������ �� ������
         */
        Gepard::Tolerances::Tolerance* FindTolByUIN(unsigned int tUIN);

        /**
        * ���������� ������� �������� ���
        */
        void SetSolidsUINCounterValue(unsigned int cnt);

        /**
        * ���������� ������� ����� ���� (���������+1)                           
        */
        unsigned int GetCurrentSolidUIN();

        /**
         *  ���������� ������� ����� �������
         */
        unsigned int GetCurrentTolUIN();

         /**
         *  ���������� ������� ����� ������� ����������
         */
        unsigned int GetCurrentMR_UIN();

        /**
        * ����� ������, ��������� ����������� �����                           
        */
        void SetLastSolidsUIN();

        /**
         *  ����� ������ �� UIN
         */
        Gepard::Topology_Geometry::GPDSolidPtr FindSolidByUIN(unsigned int s_uin);

        /**
         *  ����� ���� ����� �� ������ ����
         */
        Gepard::Assembly::AssemblyNode* FindAssemblyNodeByUIN(unsigned int asm_node_uin);

        /**
         *  ����� ������� ���������� �� ������
         */
        Gepard::Assembly::MatingRelation* FindMatingRelationByUIN(unsigned int mr_uin);

        /**
         *  �������� ��������� �� ������ ������� ������������
         */
        Gepard::Tolerances::DatumFaceReferenceList* GetDatumFacesListPtr();
        
        /**
         *  �������� ������ ���
         */
        //Gepard::Topology_Geometry::GPDSolidList& GetSolidsList();

        /**
         *  ������� ����
         */
        bool DeleteSolid(Gepard::Topology_Geometry::GPDSolidPtr solidPtr);

        /**
         *  �������� ����� ������� (��������� ����� �������)
         */
        Gepard::Tolerances::TolerancePtr AddToleranceCopy(Gepard::Tolerances::TolerancePtr _tolerance);

        /**
         *  �������� ��������� �� ������ ��������
         */
        Gepard::Tolerances::TolerancePtrList* GetTolerancePtrListPtr();

        /**
         *  �������� ��������� �� ������ ��
         */
        Gepard::Analysis::KeyCharacteristicsPtrArray* GetKCArrayPtr();

        /**
         *  �������� �������� ��������������
         */
        Gepard::Analysis::KeyCharacteristics* AddKeyCharacteristics(Gepard::Analysis::KeyCharacteristics *kc);

        /**
         *  ������� �������� ��������������
         */
        void DeleteKeyCharacteristic(Gepard::Analysis::KeyCharacteristics *kc_ptr);

        /**
        *	�������� �������
        */
        void AddFit(Gepard::Tolerances::Fit _fit);

        /**
         *	������� �������
         */
        void DeleteFit(Gepard::Tolerances::Fit *fit);

        /**
         *	�������� ��������� �� ������ �������
         */

        Gepard::Tolerances::FitArray* getFitArrayPtr();

    private:

        /**
         * ������� ���
         */        
        unsigned int _soldsUINCounter;

        /**
         *  ������� ��������
         */
        unsigned int _tolUINCounter;

        /**
         *  ������� ������� ����������
         */
        unsigned int _mrUINCounter;

        /**
         * ���� ������
         */
        Gepard::Assembly::AssemblyGraph AsmGraph;

        /**
         *  ������ ���������� �� ��������� ����������� ����
         */
        Gepard::Topology_Geometry::GPDSolidPtrList lastSolidsPtrList;

        /**
         *  ������ ������� ������������
         */
        Gepard::Tolerances::DatumFaceReferenceList datumFacesArray;

        /**
         *  ������ �������� ��� ������ ������
         */
        Gepard::Tolerances::TolerancePtrList tolerancePtrList;

        /**
         *  ������ �������
         */
        Gepard::Tolerances::FitArray fitArray;

        /**
         *  ������ �������� ������������� ��� ������ ������
         */
        Gepard::Analysis::KeyCharacteristicsPtrArray KCPtrArray;

        /**
         *  ���������� ���� �������� ��������� ��� ���� ���
         */
        void SetSolidsDeleteFlag();

        /**
         *  �������� � ���� ������ ��������� ������
         */
        void AddSolidsToAssmGraph(Gepard::Topology_Geometry::GPDSolidPtrList &solidList);

        /**
         *  �������� ������ ��������
         */
        void ClearTolerances();

        /**
         *  �������� ������ �������� �������������
         */
        void ClearKeyCharacteristics();

    };

}

#endif // !defined(GPD_C2A65ED7_44F2_4e00_B56F_59DAEA62C821__INCLUDED_)


