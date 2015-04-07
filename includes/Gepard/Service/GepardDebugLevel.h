///////////////////////////////////////////////////////////
//  GepardDebugLevel.h
//  ���������� Class GepardDebugLevel
//  �������:      06-���-2012 12:59:27
//  �����: Dr_Freeman
///////////////////////////////////////////////////////////

#if !defined(GPD_41D7FBFC_E148_4b02_A0E4_86EFD414BDDD__INCLUDED_)
#define GPD_41D7FBFC_E148_4b02_A0E4_86EFD414BDDD__INCLUDED_

namespace Gepard
{
	namespace Service
	{
		enum GepardDebugLevel
		{
			DEBUG_OFF = 0,	// ������ ������ ������ �������� ������ 
							// (��������, ����������� ������) 
							// - ��������� � ����� ������
			DEBUG_USR1 = 1, //
			DEBUG_USR2 = 2, //
			DEBUG_USR3 = 3, // - ���������������� ������ (������ ���������� ��������������)
			DEBUG_USR4 = 4, // 
			DEBUG_USR5 = 5, //
			DEBUG_ALL = 20	//	- ������ ������ ������� ������ (����� ��������� ������)
		};

	}

}
#endif // !defined(GPD_41D7FBFC_E148_4b02_A0E4_86EFD414BDDD__INCLUDED_)
