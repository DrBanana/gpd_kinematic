///////////////////////////////////////////////////////////
//  Tolerance.cpp
//  ���������� 	Class Tolerance
//  �������:   	16-���-2010 15:49:06
//  �����: 		Anton
//  �����������: 31.01.14 �.
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
         * ��������� �������
         */		
        class Tolerance
        {
            friend class CombinedTolerance;

        public:
            Tolerance();
            virtual ~Tolerance();

            /**
             * ������ ����������
             */
            double d_low;
            /**
             * ������� ����������
             */
            double d_high;
        
            /**
             *	�����������, �� ������� �������� ������
             */
            Gepard::Topology_Geometry::GPDFacePtr tol_face;

            /**
             *  ������ ������� ������������ (������������ ������� �������� ������)
             */
            DatumFaceReferenceList DatumRefList;

            /**
             * ��� �������
             */
            Gepard::Tolerances::TOLERANCE_TYPE TolType;
            
            /**
             *	����������� ������� �� �����
             */
            double u0,u1,v0,v1;

            /**
             *	����������� ����� ������������ �������
             */
            Gepard::BasicMath::GPDReper Control_Reper;

            /**
             *	���� ����� ������
             */	
            //Gepard::Assembly::AssemblyNode *parentAsmNode;

            /**
             *  ���������������� ������������, ��������������� ������� �������
             */
            ConfSpaceType SPACE_TYPE;

            /**
             *  ��������� �.�.
             */
            CSParamsList cs;

            /**
             *  ������������ �������� ������ �� ���������� �� (� ����������� �� ����)
             */
            double max_gamma;
                     
            /**
             *  ������ �������� ���������� ��� ����� �.�. (fi, psi)
             */
            std::vector<std::string> csParNames;

            /**
             *  ����������� ����� ���� ��������
             */
            bool isNominalModified;

            /**
             *  ����� �������
             */
            unsigned int UIN;

            /**
             *  ��������� ������� ������� ������ �� ����
             */
            template <class T>
            static Gepard::Tolerances::Tolerance* CreateTolerance();

            /**
             *  ������� ������ �� ����
             */
            static Gepard::Tolerances::Tolerance* CreateTolerance(TOLERANCE_TYPE tolType);

            /**
             *	������� ���������������� ������������ �� �������� ����������
             */
            void CalcConfigurationSpace(unsigned int COUNT_CONF_POINTS=0);

            /**
             *	��������� ��������� ������������ ������ ����. ������� � �������� a,b
             */
            void CalcControlSegmentReper();
          
            /**
             *	�������� �������� �������
             */
            void SetNull();

            /**
             *  �������� ����� �.�. � �������� ������������
             */
            CSParam* AddCSParam(double fi, double psi, bool calcTol=true);

            /**
             *  ����� ������ ����� �� �� ���������
             */
            int FindCS(Gepard::Tolerances::CSParam par);

            /**
             *  ������� ����� �� (������ � ������)
             */
            void DeleteCSPoint(Gepard::Tolerances::CSParam par);

            /**
             *  �������� ����� ����� �.�.
             */
            virtual unsigned int GetCountCS() { return cs.getCount(); }

            /**
             *  �������� ������� ����������� ����� �� �������� ����� ��             
             */
            virtual TModifyPointsFunc GetPointsModificationFunc(CSParam par);

            /**
             *  �������� ������� ����������� ����� �� ������� ����� ��
             *  isForVisual - ����� �� �������������� ��������� ��� ������������
             */
            virtual TModifyPointsFunc GetPointsModificationFunc(unsigned int cs_index, bool isForVisual = false);

            /**
             *  �������������� ��������� ����� �� �������� ����� ��
             */
            virtual void ModifyFaceParamsByCS(CSParam par);

            /**
             *  �������������� ��������� ����� �� ������� ����� ��
             */
            virtual void ModifyFaceParamsByCS(int csIndex);

            /**
             *  �������� ��������� ����� � �������
             */
            virtual void DropFaceParamsToNominal();

            /**
             *  �������� ��������� ��� ����������� ������� ��
             */
            void ModifyParamsForVisualization(CSParam &par);

            /**
             *  ��������� �������� ���������� ��� ������� ��������� ����� �.�.
             */
            double CalcToleranceByCSParams(CSParam par);

            /**
             *  ��������� �������� gamma (��� ������� ������� ������)
             *  �� �������� ������� � ���������� �����������
             */
            virtual double CalcGammaByTolValue(double tolValue);

            /**
             *  �������� �� ������ ����������� ��� ������� �������
             */
            virtual bool CheckFace(Gepard::Topology_Geometry::GPDFacePtr facePtr);

            /**
             *  �������� �� ������ ���������������
             */
            virtual bool isCombined();

            /**
             *  ������ ����� � ������� ������� (�� �������)
             */
            virtual bool isFit();

            /**
             * ���������� � ����
             */
            virtual void saveToFile(std::ostream& os);

            /**
             * ������ �� �����
             */
            virtual void readFromFile(std::istream& is, Gepard::MathModel *mathModelPtr);
                   
        protected:

            /**
             *  �������� ��������� �����������, �� ������� �������� ������
             */
            void GetTolFaceParams(Gepard::Surfaces::SURFACE_TYPES &sType, double &A, double &B);

            /**
             *  ��������� ���������������� ������������ ��� �������
             */            
            virtual double calcConfigurationSpaceTol( unsigned int COUNT_CONF_POINTS );

            /**
             *  ��������� �������� ������� �� �������� ��������� ����� �.�.
             */
            virtual double calcTolValueByCSParam(CSParam par, double A=0.0, double B=0.0);           
          
            /**
             *  �������� ����������� ��� ������������ �������
             */
            virtual double GetVisualKoeff();

            /**
             *	������ ����������������� ������������ �����
             */
            void calcSphereConfigurationSpace(double gamma, unsigned int COUNT_CONF_POINTS);

            /**
             *	������ ����������������� ������������ ����
             */
            void calcArcConfigurationSpace(double gamma, unsigned int COUNT_CONF_POINTS);

            /**
             *	������ ����������������� ������������ �����
             */
            void calcLineConfigurationSpace(unsigned int COUNT_CONF_POINTS);

            /**
             *	������ ����������������� ������������ �����
             */
            void calcCircleConfigurationSpace(double gamma, unsigned int COUNT_CONF_POINTS);


            //������� ������� ������������ ������� - ������ � �������� � ����������� �� �������

            /**
             *	���������� ��������� ������ ������������ �������
             */
            void calcSegReper(); 

             /**
             *  ����������� ����� ����� - ��� ���������� ������ ���������
             */
            GPDReper nPoint_Reper;

        };

        typedef Tolerance* TolerancePtr;
        typedef Gepard::General::basicList<Tolerance>     ToleranceList;
        typedef Gepard::General::basicList<TolerancePtr>  TolerancePtrList;
        typedef Gepard::General::basicArray<Tolerance>    ToleranceArray;
        typedef Gepard::General::basicArray<TolerancePtr> TolerancePtrArray;


        /**
         *  ����������� ����� � ����������� ���������
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

            Gepard::Topology_Geometry::GPDFacePtr _facePtr; //����������� �����
            Gepard::Tolerances::Tolerance*        _tolPtr;  //��������� �� ������
            Gepard::Tolerances::CSParam           _par;     //�������� ����� �.�.
        };

        typedef Gepard::General::basicList<TolCSFace> TolCSFaceList;

    }

}

