///////////////////////////////////////////////////////////
//  
//  ���������� 	Class axisFixingType
//  �������:   	25-���-2010 13:35:52
//  �����: 		Dr_Freeman
///////////////////////////////////////////////////////////

#if !defined(EA_A41622C5_E0B4_4512_9681_9FB426CD7D3A__INCLUDED_)
#define EA_A41622C5_E0B4_4512_9681_9FB426CD7D3A__INCLUDED_

namespace Gepard
{
	namespace Assembly
	{
		/**
		 * ��� ����������� ���
		 */
		enum axisFixingType
		{
			/**
			 * ������������� - ��� ��������/��������
			 */
			AFT_FIXED = 1,
			/**
			 * ����� �����������/�������
			 */
			AFT_UNFIXED = 2,
			/**
			 * ����� �������/���������� ������ � �������� �������� value
			 */
			AFT_UNFIXED_VALUE = 3,
			/**
			 * ����� �������� ������ �� Min � Max
			 */
			AFT_UNFIXED_VALUES_MIN_MAX = 4
		};

	}

}
#endif // !defined(EA_A41622C5_E0B4_4512_9681_9FB426CD7D3A__INCLUDED_)
