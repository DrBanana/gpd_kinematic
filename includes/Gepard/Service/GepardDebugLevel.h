///////////////////////////////////////////////////////////
//  GepardDebugLevel.h
//  Реализация Class GepardDebugLevel
//  Создано:      06-дек-2012 12:59:27
//  Автор: Dr_Freeman
///////////////////////////////////////////////////////////

#if !defined(GPD_41D7FBFC_E148_4b02_A0E4_86EFD414BDDD__INCLUDED_)
#define GPD_41D7FBFC_E148_4b02_A0E4_86EFD414BDDD__INCLUDED_

namespace Gepard
{
	namespace Service
	{
		enum GepardDebugLevel
		{
			DEBUG_OFF = 0,	// ошибки самого самого верхнего уровня 
							// (например, критические ошибки) 
							// - выводятся в любом случае
			DEBUG_USR1 = 1, //
			DEBUG_USR2 = 2, //
			DEBUG_USR3 = 3, // - пользовательские ошибки (уровни выбираются самостоятельно)
			DEBUG_USR4 = 4, // 
			DEBUG_USR5 = 5, //
			DEBUG_ALL = 20	//	- ошибки самого нижнего уровня (самые подробные ошибки)
		};

	}

}
#endif // !defined(GPD_41D7FBFC_E148_4b02_A0E4_86EFD414BDDD__INCLUDED_)
