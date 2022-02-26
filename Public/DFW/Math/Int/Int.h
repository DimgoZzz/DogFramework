#pragma once
#include <stdint.h>

namespace DogFW::basictypes
{
	using	Int8	= int8_t;
	using	Int16	= int16_t;
	using	Int32	= int32_t;
	using	Int64	= int64_t;
	using	UInt8	= uint8_t;
	using	UInt16	= uint16_t;
	using	UInt32	= uint32_t;
	using	UInt64	= uint64_t;
}

namespace DogFW::math
{
	basictypes::Int8  abs (basictypes::Int8  inV);
	basictypes::Int16 abs (basictypes::Int16 inV);
	basictypes::Int32 abs (basictypes::Int32 inV);
	basictypes::Int64 abs (basictypes::Int64 inV);
}
