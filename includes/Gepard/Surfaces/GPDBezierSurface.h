///////////////////////////////////////////////////////////
//  GPDBezierSurface.h
//  Реализация Class GPDBezierSurface
//  Создано:      15-ноя-2012 17:35:15
//  Автор: Dr_Freeman
///////////////////////////////////////////////////////////

#if !defined(EA_6031D69B_8F8D_43fa_A783_1EEEB9727055__INCLUDED_)
#define EA_6031D69B_8F8D_43fa_A783_1EEEB9727055__INCLUDED_

#include "Surfaces\GPDSurface.h"

namespace Gepard
{
	namespace Surfaces
	{
		/**
		 * Поверхность Безье
		 */
		class GPDBezierSurface : public Gepard::Surfaces::GPDSurface
		{

		public:
			GPDBezierSurface();
			virtual ~GPDBezierSurface();

		};

	}

}
#endif // !defined(EA_6031D69B_8F8D_43fa_A783_1EEEB9727055__INCLUDED_)
