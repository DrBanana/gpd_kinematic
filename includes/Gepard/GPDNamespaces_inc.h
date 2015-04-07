///////////////////////////////////////////////////////////
//  GPDNamespaces_inc.h
//  Подключение всех пространств имен Gepard-а
//  Создано:    11-апр-2014 13:35
///////////////////////////////////////////////////////////

namespace Gepard
{
	namespace Assembly {};
    namespace Analysis{};
	namespace BasicMath{};
	namespace Callbacks{};
	namespace Curves{};
	namespace General{};
	namespace STEP{};
	namespace Surfaces{};
	namespace Tolerances{};
	namespace Topology_Geometry{};
	namespace Visualization
	{
		namespace SpecialObjects{};
	};

	namespace Service
	{
		namespace Integration {};
	};
};

using namespace Gepard;
using namespace Gepard::Assembly;
using namespace Gepard::Analysis;
using namespace Gepard::BasicMath;
using namespace Gepard::Callbacks;
using namespace Gepard::Curves;
using namespace Gepard::General;
using namespace Gepard::Service;
using namespace Gepard::Service::Integration;
using namespace Gepard::STEP;
using namespace Gepard::Surfaces;
using namespace Gepard::Tolerances;
using namespace Gepard::Topology_Geometry;
using namespace Gepard::Visualization;
using namespace Gepard::Visualization::SpecialObjects;