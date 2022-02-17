#pragma once
#include "DogFW/Common/Math/Vector/SIMDVector.h"
#include "DogFW/Common/Math/Vector/SIMDVectorA.h"
#include "DogFW/Common/Math/Vector/PrimitiveInt2DVector.h"


namespace DogFW :: inline basictypes
{
	//NoSIMD Int32 2D Vector
	using VectorPI2D = math::PrimitiveInt2DVector;

	using Vector4 = math::SIMDVector4DAligned;
}