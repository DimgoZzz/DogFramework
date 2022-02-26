#pragma once
#include "DFW/DBasicTypes.h"

#include "DFW/Math/Vector/SimpleVector2.h"

#include "DFW/Math/Vector/SimdVector4F.h"

namespace DogFW::vector
{
	using VectorI2P = simple::Vector2<Int32>;
	using VectorF2P = simple::Vector2<Float>;

	using VectorF4S = simd::Vector4F;
}
