#pragma once
#include <stdint.h>

namespace DogFW :: inline basictypes
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

namespace DogFW :: math
{
	Int8  abs (Int8  inV);
	Int16 abs (Int16 inV);
	Int32 abs (Int32 inV);
	Int64 abs (Int64 inV);
}
