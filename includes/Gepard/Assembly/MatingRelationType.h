///////////////////////////////////////////////////////////
//  
//  ���������� 	Class MatingRelationType
//  �������:   	20-���-2010 15:22:06
//  �����: 		Dr_Freeman
///////////////////////////////////////////////////////////

#if !defined(EA_480FAC82_AE95_4fca_A58C_97554F4B3287__INCLUDED_)
#define EA_480FAC82_AE95_4fca_A58C_97554F4B3287__INCLUDED_

namespace Gepard
{
	namespace Assembly
	{
		/**
		 * ��� ������� ����������
		 * SI - Surface Interaction (�������������� ������������)
		 */
		enum MatingRelationType
		{
			/**
			 * ��� ����������
			 */
			MRT_NONE = 0,
			/**
			 * ��������� � ���������
			 */
			MRT_SI_PLANE_TO_PLANE = 1,
			/**
			 * ������� � ��������� - ��� �������� ��������������� � ���������
			 */
			MRT_SI_CYLINDRICAL_TO_PLANE = 2,
			/**
			 * ������� � �������� - ��� ��������� ���������
			 */
			MRT_SI_CYLINDRICAL_TO_CYLINDRICAL = 3,
			/**
			 * ������� ������������
			 */
			MRT_CONTACT_SURFACES = 4,
			/**
			 * ������� �������� �����
			 */
			MRT_CONTACT_POINTS = 5,
			/**
			 * ������� �������� �����
			 */
			MRT_CONTACT_EDGES = 6
		};

		/**
		 *	����������� ��������
		 */
		enum MRAxesDirection
		{
			/**
			 *	����������� ���������
			 */
			MRAD_SAME = 0,
			/**
			 *	����������� �� ���������
			 */
			MRAD_DIFFERENT = 1,
			/**
			 *	����������� �� ������
			 */
			MRAD_UNKNOWN = 2
		};

	}

}
#endif // !defined(EA_480FAC82_AE95_4fca_A58C_97554F4B3287__INCLUDED_)
