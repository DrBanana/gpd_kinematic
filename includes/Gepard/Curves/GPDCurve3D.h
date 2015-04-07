///////////////////////////////////////////////////////////
//  GPDCurve.h
//  ����������	Class GPDCurve
//  �������:    15-���-2012 16:15:33
//  �����:		Dr_Freeman
///////////////////////////////////////////////////////////

#if !defined(EA_05916F1D_D6E7_43e5_9EE8_82360E9A3782__INCLUDED_)
#define EA_05916F1D_D6E7_43e5_9EE8_82360E9A3782__INCLUDED_

#include "../BasicMath/GPDPoint.h"
#include "../General/basicArray.h"
#include "../BasicMath/basicFuncs.h"
#include "CURVE_3D_TYPE.h"


namespace Gepard
{
    namespace Curves
    {

        class GPDLine;
        class GPDCircle;
        class GPDEllipse;        
        class GPDBezierCurve;
        class GPDNurbsCurve;

        /**
         * ������� ����� ������
         */
        class GPDCurve3D
        {           

        public:
            /**
             * ������ 3D ����� ������
             */
            Gepard::BasicMath::GPDPointArray Points;

            GPDCurve3D();
            virtual ~GPDCurve3D();
        
            /**
             * �������� ��� ������
             */
            CURVE_3D_TYPE getCurveType();

            /**
             * ��������� ������ � �������� ������ �����
             */
            virtual void calcCurve(unsigned int numPoints=0);

            /**
             *  ������������� � �����
             */
            GPDLine* toLine();

            /**
             *  ������������� � ����������
             */
            GPDCircle* toCircle();

            /**
             *  ������������� � ������
             */
            GPDEllipse* toEllipse();           

            /**
             *	������������� � ������ NURBS
             */
            GPDNurbsCurve* toNURBS();

            /**
             *	�������� ������� ����� A
             */
            Gepard::BasicMath::GPDPoint getPointA();

            /**
            *	�������� ������� ����� B
            */
            Gepard::BasicMath::GPDPoint getPointB();

            /**
             *	���������� ������� ����� A
             */
            virtual void setPointA(Gepard::BasicMath::GPDPoint _a);

            /**
             *	���������� ������� ����� B
             */
            virtual void setPointB(Gepard::BasicMath::GPDPoint _b);

            /**
             *  �������� �������� ����� ����������� ������
             */
            bool IsClosed();

            /**
             *  ������������� � �������� ������
             */
            template <class T>
            T* Convert();

            /**
             *  ����������� ����� ������ �� ������� ��������� oldReper � ������� ��������� newReper
             */
            virtual void ConvertToBasis( Gepard::BasicMath::GPDReper &oldReper, 
                                         Gepard::BasicMath::GPDReper &newReper);

            /**
             *  ���������� ������ ������ ������������� ��������� ������ fromCurvePtr
             */
            virtual void SetEquivalentParameters(GPDCurve3D* curvePtr);

            /**
             *  ��������� ������ ������ � �����
             */
            virtual void saveToFile(std::ostream& os);

            /**
             *  ��������� ������ �� ������
             */
            virtual void readFromFile(std::istream& _is);

            /**
             *	������ ���������
             */
            virtual bool isEquivalent(GPDCurve3D* curve3dPtr);

            /**
             *	�������� �������������� ��������������
             */
            Gepard::BasicMath::BoundingBox GetBoundingBox();

        protected:
            /**
             *	��������� � �������� ����� ������
             */
            Gepard::BasicMath::GPDPoint A, B;
        
            /**
             * ��� ������
             */
            Gepard::Curves::CURVE_3D_TYPE CurveType;

            /**
             *	����� ����� ������ �� ���������
             */
            int defaultPointsCount;

            /**
             *  ��������� ������
             */
            bool isCurveClosed;

            /**
             *	����������� �������������� ��� ������
             */
            Gepard::BasicMath::BoundingBox boundingBox;

        private:
             /**
             *	��������� ���������� �� ���������
             */
            virtual void setDefaultParameters();
        };
        typedef Gepard::Curves::GPDCurve3D* GPDCurve3DPtr;						//��������� �� ������� ������ 3D
        typedef Gepard::Curves::GPDCurve3D& GPDCurve3DRef;						//������ �� ������� ������ 3D
        typedef Gepard::General::basicArray<GPDCurve3DPtr> GPDCurve3DPtrArray;  //������ ���������� �� ������ 3D. �� ������ �������! (���� ����).
        typedef Gepard::General::basicList<GPDCurve3DPtr>  GPDCurve3DPtrList;   //������ ���������� �� ������ 3D. �� ������ �������! (���� ����).		
    }

}
#endif // !defined(EA_05916F1D_D6E7_43e5_9EE8_82360E9A3782__INCLUDED_)
