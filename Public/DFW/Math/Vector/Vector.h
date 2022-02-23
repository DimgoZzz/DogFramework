#pragma once
#include "DFW/DBasicTypes.h"

#include "DFW/Math/Vector/Vector2P.h"

#include "DFW/Math/Vector/VectorF4S_XMF4.h"

namespace DogFW::inline math:: inline vector
{
	using VectorI2P = Vector2P<Int32>;
	using VectorF2P = Vector2P<Float>;

	using VectorF4S = simdvector::VectorF4S_XMF4;
}
