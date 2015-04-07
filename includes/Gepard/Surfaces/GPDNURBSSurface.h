///////////////////////////////////////////////////////////
//  GPDNURBSSurface.h
//  ���������� Class GPDNURBSSurface
//  �������:      03-���-2015 10:13
//  �����: Dr_Freeman
///////////////////////////////////////////////////////////

#ifndef GPDNURBSSURFACE_H
#define GPDNURBSSURFACE_H

#include "GPDSurface.h"

namespace Gepard
{
    namespace Surfaces
    {
        using namespace Gepard::BasicMath;

        /**
        *	��������� ��������� ��������� ������ ��� ���������� ����� � ����������� � ���
        */
        struct NURBSEvaluationTmpData
        {
            /**
            *	��������� ������ ��� �������� ������������� �������� ����� (�� j)
            *   ������ ������� ������� - ��� �����������
            */
            std::vector<GPDPointArray> points_j_array[2];

            /**
            *	��������� ������ ��� �������� ������������� �������� ����� (�� i)
            *   ������ ������� ������� - ��� �����������
            */
            std::vector<GPDPointArray> points_i_array[2];

            /**
            *  ��������� ������ ��� �������� ������������� �������� ����� (�� j)
            *   ������ ������� ������� - ��� �����������
            */
            std::vector<GPDPointArray> weights_j_array[2];

            /**
            *  ��������� ������ ��� �������� ������������� �������� ����� (�� i)
            *   ������ ������� ������� - ��� �����������
            */
            std::vector<GPDPointArray> weights_i_array[2];

            /**
            *	���������� �� ������
            */
            bool isExist;
            NURBSEvaluationTmpData() { isExist = false; }
        };

        /**
         *	����������� ���� NURBS: (B-spline ������������ � ��������������)
         */
        class GPDNURBSSurface : public Gepard::Surfaces::GPDSurface
        {
            friend class GPDBSplineWithKnotsSurface;
            friend class GPDRationalBSplineSurface;
            friend class GPDBSplineSurface;                      

        public:
            GPDNURBSSurface();
            GPDNURBSSurface( int order_u, int order_v, bool is_rational,
                             Gepard::BasicMath::GPDPointArray &control_points,
                             const std::vector<double> &u_knots = std::vector<double>(),
                             const std::vector<int> &u_mult = std::vector<int>(),
                             const std::vector<double> &v_knots = std::vector<double>(),
                             const std::vector<int> &v_mult = std::vector<int>(),
                             const std::vector<std::vector<double>> &W = std::vector<std::vector<double>>());

            ~GPDNURBSSurface();

            /**
            *  ���������� ��������� �����������
            */
            void setParameters( int order_u, int order_v, bool is_rational, 
                                Gepard::BasicMath::GPDPointArray &control_points,
                                const std::vector<double> &u_knots = std::vector<double>(), 
                                const std::vector<int> &u_mult = std::vector<int>(),
                                const std::vector<double> &v_knots = std::vector<double>(), 
                                const std::vector<int> &v_mult = std::vector<int>(),
                                const std::vector<std::vector<double>> &W = std::vector<std::vector<double>>());

            /**
            * ������� ����������� � ���������� ����������� ��������
            */
            void CalcSurface(unsigned int _numU = 0, unsigned int _numV = 0, double _stepU = 0, double _stepV = 0)  override;

           /**
            *	������ 2� ����� �� ����� �� �� 3� �����������
            */
            void CalcMapPoint(Gepard::BasicMath::GPDPointRef P3D,
                              Gepard::BasicMath::GPDPoint2dRef p2d) override;

            /**
            *  ������ 2� ������� �� ����� �� 3� ������
            */
            void CalcMapContour(Gepard::Curves::GPDCurve3DPtr curve3DPtr,
                                Gepard::General::basicList<Gepard::BasicMath::GPDPoint2dn> &curve2DRef) override;

            /**
            *  ������ �������� ��� ������� �� ����������� (3D)
            */
            void CalcContourNormals(Gepard::Curves::GPDCurve3DPtr curve3DPtr) override;

            /**
            *  ������ 3� ����� ����������� �� �� 2� ����������
            */
            void CalcSurfacePoint(Gepard::BasicMath::GPDPoint2dRef p2d,
                                  Gepard::BasicMath::GPDPointRef P3D) override;

            /**
            *  ��������� ����������� � �����
            */
            void saveToFile(std::ostream& os) override;

            /**
            *  ��������� ����������� �� ������
            */
            void readFromFile(std::istream& _is) override;
          
            /**
             *	�������� ����� ����������� �����
             */
            unsigned int GetControlPointsCount();

            /**
             *	�������� ����� ����� �� u
             */
            unsigned int GetKnotsUCount();

            /**
            *	�������� ����� ����� �� v
            */
            unsigned int GetKnotsVCount();

            /**
             *	�������� ������� �� u
             */
            unsigned int GetOrderUCount();

            /**
             *	�������� ������� �� v
             */
            unsigned int GetOrderVCount();

        private:
            /**
            *	���� ������������ B-Spline �����������
            */
            bool isRational;

            /**
            *	������� ����������� � ����������� U (�������U +1)
            */
            int Ku;

            /**
            *	������� ����������� � ����������� V (�������V +1)
            */
            int Kv;

            /**
            *	������ ����� � ����������� U
            */
            std::vector<double> Knots_u;

            /**
            *	������ ����� � ����������� V
            */
            std::vector<double> Knots_v;

            /**
            *	�������� ����� - ��������� ������ (UxV)
            */
            Gepard::BasicMath::GPDPointArray Control_points;

            /**
             *	���� ����� � ������ ������������� B-SPLINE
             */
            std::vector<std::vector<double>> weights;
               
            /**
             *	��������� ������
             */
            NURBSEvaluationTmpData evTmpData;            

            /**
             *	�������� ��������� ������
             */
            void ClearTmpData();

            /**
             *  ��������� ��������� ������� ��� �������� ������� �����
             */
            void CalcTempArrays();

            /**
             *	����������� ��������� ������ � ������������ 
             */
            void PrepareTempDerivativeArrays(int uv, std::vector<GPDPointArray> &dp_array, std::vector<GPDPointArray> &dw_array);


            /**
             *	��������� ����������� � ����� � ���������� ������� 
             *  (coef - �������� �� ���������� ���� �����������)
             */
            void CalcDerivativesAndNormal( Gepard::BasicMath::GPDPoint2dRef p2d,
                                           Gepard::BasicMath::GPDPointRef P3D, 
                                           int interval_u, int interval_v, double coef );
                       
            /**
            *	��������� ���������� ����������� �� ���������
            */
            void setDefaultParameters() override;                     


            /**
             *	����� ��������� ����� �� �����������
             */
            double FindClosestPoint3D( Gepard::BasicMath::GPDPointArray &_PointArray, 
                                       Gepard::BasicMath::GPDPoint &P3d, unsigned int &uu, unsigned int &vv );
            /**
            *	��������, �������� �� ���� �� ������ ����������� - ������
            */
            void CheckSidesIsPoint();

            /**
            *	������������� �������� ����� ��� ������, ����� ���� �� ������ - �����
            */
            void CorrectNormalOnSideAsPoint();

            /**
             *  �������� ����� ������� �����������
             */
            void ProcessAfterCalcSurface() override;
            

            /**
            *	����� �� ������ ����������� ���� � �����
            *  ( 1 - {u:0;v=0-1}; 2 - {u:0-1;v=1};
            *    3 - {u:1;v=1-0}; 4 - {u:1-0;v=0}; )
            */
            std::vector<int> sideIsPoint;
        };
    }
}

#endif