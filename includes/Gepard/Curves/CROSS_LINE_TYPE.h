///////////////////////////////////////////////////////////
//  CROSS_LINE_TYPE.h
//  ����������	Class CROSS_LINE_TYPE
//  �������:    21-���-2012 13:10:06
//  �����:		Dr_Freeman
///////////////////////////////////////////////////////////

#if !defined(GPD_E921A0A9_FD6D_4263_8162_47B8CED8D5CB__INCLUDED_)
#define GPD_E921A0A9_FD6D_4263_8162_47B8CED8D5CB__INCLUDED_

namespace Gepard
{
    namespace Curves
    {
        /**
         * ��� ����������� �����
         */
        enum CROSS_LINE_TYPE
        {
            /**
             * ����� �����������
             */
            CLT_COLLINEAR = 1,
            /**
             * ������������ �����
             */
            CLT_PARALLEL = 2,
            /**
             * ��� ��������
             */
            CLT_SKEW = 3,
            /**
             * ������������
             */
            CLT_SKEW_CROSS = 4,
            /**
             * �� ������������
             */
            CLT_SKEW_NO_CROSS = 5
        };

    }

}
#endif // !defined(GPD_E921A0A9_FD6D_4263_8162_47B8CED8D5CB__INCLUDED_)
