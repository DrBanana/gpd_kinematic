///////////////////////////////////////////////////////////
//  GepardErrorType.h
//  ���������� GepardErrorType
//  �������:   06-���-2012 12:59:16
//  �����: Dr_Freeman
///////////////////////////////////////////////////////////

#if !defined(GPD_AB73FB48_2A2C_4b9d_AA34_2A2CAE915CEE__INCLUDED_)
#define GPD_AB73FB48_2A2C_4b9d_AA34_2A2CAE915CEE__INCLUDED_

namespace Gepard
{
	namespace Service
	{
		/**
		 * ���� ������
		 */
		typedef enum GepardErrorType
		{
			/**
			 * ��� ������
			 */
			GPD_ET_NULL = 0,
			/**
			 * ��������� ������ (�� �������������)
			 */
			GPD_ET_FATALERROR = 1,
			/**
			 * ��� - ������ ������
			 */
			GPD_ET_BUG = 2,
			/**
			 * ������ ����� (��� ������� ������)
			 */
			GPD_ET_INPUT_ERROR = 3,
			/**
			 * ������ ������
			 */
			GPD_ET_OUTPUT_ERROR = 4,
			/**
			 * �������������� (������������� ������)
			 */
			GPD_ET_WARNING = 5,
			/**
			 * ������ ����� ������
			 */
			GPD_ET_ANY = 6
		} GepardErrorType;

	}

}
#endif // !defined(GPD_AB73FB48_2A2C_4b9d_AA34_2A2CAE915CEE__INCLUDED_)
