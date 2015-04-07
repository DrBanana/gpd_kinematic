///////////////////////////////////////////////////////////
//  CROSS_LINE_POINT_TYPE.h
//  ���������� Class CROSS_LINE_POINT_TYPE
//  �������:      15-���-2012 14:23:18
//  �����: Dr_Freeman
///////////////////////////////////////////////////////////

#if !defined(GPD_E5D4E200_0F79_42f1_9E9B_671C9315CD1F__INCLUDED_)
#define GPD_E5D4E200_0F79_42f1_9E9B_671C9315CD1F__INCLUDED_

namespace Gepard
{
    namespace Curves
    {
        /**
         * ��� ����� ��� ����������� ����������� �����
         */
        enum CROSS_LINE_POINT_TYPE
        {
            /**
             *  ����������
             */
            CLPT_NONE = 0, 
            /**
             * ����� ����� �� �����
             */
            CLPT_LEFT = 1,
            /**
             * ����� ������ �� �����
             */
            CLPT_RIGHT = 2,
            /**
             * ����������� ����� ������ (����� ������ ������)
             */
            CLPT_BEYOND = 3,
            /**
             * ����� ������ ����� (����� ������. �����)
             */
            CLPT_BEHIND = 4,
            /**
             * ����� ����� ���. � ���. ������� �����
             */
            CLPT_BETWEEN = 5,
            /**
             * ����� ����� ��������� �����
             */
            CLPT_ORIGIN = 6,
            /**
             * ����� ����� �������� ����� �����
             */
            CLPT_DESTINATION = 7
        };

    }

}
#endif // !defined(GPD_E5D4E200_0F79_42f1_9E9B_671C9315CD1F__INCLUDED_)
