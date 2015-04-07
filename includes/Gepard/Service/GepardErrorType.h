///////////////////////////////////////////////////////////
//  GepardErrorType.h
//  Реализация GepardErrorType
//  Создано:   06-дек-2012 12:59:16
//  Автор: Dr_Freeman
///////////////////////////////////////////////////////////

#if !defined(GPD_AB73FB48_2A2C_4b9d_AA34_2A2CAE915CEE__INCLUDED_)
#define GPD_AB73FB48_2A2C_4b9d_AA34_2A2CAE915CEE__INCLUDED_

namespace Gepard
{
	namespace Service
	{
		/**
		 * Типы ошибок
		 */
		typedef enum GepardErrorType
		{
			/**
			 * нет ошибки
			 */
			GPD_ET_NULL = 0,
			/**
			 * Фатальная ошибка (не восстановимая)
			 */
			GPD_ET_FATALERROR = 1,
			/**
			 * баг - просто ошибка
			 */
			GPD_ET_BUG = 2,
			/**
			 * ошибка ввода (или входных данных)
			 */
			GPD_ET_INPUT_ERROR = 3,
			/**
			 * ошибка вывода
			 */
			GPD_ET_OUTPUT_ERROR = 4,
			/**
			 * предупреждение (некритическая ошибка)
			 */
			GPD_ET_WARNING = 5,
			/**
			 * просто любая ошибка
			 */
			GPD_ET_ANY = 6
		} GepardErrorType;

	}

}
#endif // !defined(GPD_AB73FB48_2A2C_4b9d_AA34_2A2CAE915CEE__INCLUDED_)
