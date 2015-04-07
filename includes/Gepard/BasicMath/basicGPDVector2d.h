///////////////////////////////////////////////////////////
//  basicGPDVector2d.h
//  ����������	Class basicGPDVector2d
//  �������:    08-���-2012 21:09:32
//  �����:      Anton
///////////////////////////////////////////////////////////

#if !defined(EA_4BBA0A0B_CE25_4705_9FC4_473F4D059CB9__INCLUDED_)
#define EA_4BBA0A0B_CE25_4705_9FC4_473F4D059CB9__INCLUDED_

namespace Gepard
{
    namespace BasicMath
    {
        /**
         * ������� ����� ����������� �������
         */
        class basicGPDVector2d 
        {

        public:
            /**
             * ���������� �������
             */
            double u;
            /**
             * ���������� �������
             */
            double v;

            basicGPDVector2d();
            ~basicGPDVector2d();
            
            /**
             * ����� �� �������
             */
            virtual bool isEquals(basicGPDVector2d& Vector2d);
            /**
             * ����� �� ����
             */
            virtual bool isNull();
            /**
             * �� ����� �� �������
             */
            virtual bool operator!=(basicGPDVector2d& Vector2d);
            /**
             * ����� �� �������
             */
            virtual bool operator==(basicGPDVector2d& Vector2d);
            /**
             * ���������� ����������
             */
            virtual void setCoords(double U, double V);
            /**
             * ���������� ����������
             */
            virtual void setCoords(basicGPDVector2d& Vector2d);
            /**
             * ��������
             */
            virtual void setNull();

        };
    }
}
#endif // !defined(EA_4BBA0A0B_CE25_4705_9FC4_473F4D059CB9__INCLUDED_)
