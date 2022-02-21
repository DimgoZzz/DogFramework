#pragma once
#include "DogFW/DogBasicTypes.h"

#include "DogFW/Math/Vector/SIMDVector.h"
#include "DogFW/Math/Vector/SIMDVectorA.h"

#include "DogFW/Math/Vector/Vector2IntP.h"
#include "DogFW/Math/Vector/Vector3IntP.h"
#include "DogFW/Math/Vector/Vector4IntP.h"

#include "DogFW/Math/Vector/Vector2FloatP.h"
#include "DogFW/Math/Vector/Vector3FloatP.h"
#include "DogFW/Math/Vector/Vector4FloatP.h"


namespace DogFW :: inline basictypes
{
	//Primitive(NoSIMD) 2D Int32 Vector
	using Vector2IP = math::vector::Vector2IntPrimitive;

	//Old ToDo refactor
	//using Vector4 = math::SIMDVector4DAligned;
}