///////////////////////////////////////////////////////////
//  GPDFreeformSurface.h
//  ���������� Class GPDFreeformSurface
//  �������:      15-���-2012 17:35:16
//  �����: Dr_Freeman
///////////////////////////////////////////////////////////

#if !defined(EA_CA183F0C_10DE_49e3_9E7E_3619013A7072__INCLUDED_)
#define EA_CA183F0C_10DE_49e3_9E7E_3619013A7072__INCLUDED_

#include "Surfaces\GPDSurface.h"

namespace Gepard
{
	namespace Surfaces
	{
		/**
		 * �����������, ����������� ������� ����������� ��������������
		 */
		class GPDFreeformSurface : public Gepard::Surfaces::GPDSurface
		{

		public:
			GPDFreeformSurface();
			virtual ~GPDFreeformSurface();

		};

	}

}
#endif // !defined(EA_CA183F0C_10DE_49e3_9E7E_3619013A7072__INCLUDED_)
