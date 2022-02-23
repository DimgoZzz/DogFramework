#pragma once
#include "DFW/DBasicTypes.h"
#include "DFW/External/DirectX/DogDirectX.h"

namespace DogFW :: inline math
{
	//4D vector based on storing data into xmFloat_
	class VectorSI4
	{
#pragma region Contructors
	public:
		VectorSI4() : xmFloat_(DirectX::XMFLOAT4(0.f, 0.f, 0.f, 0.f)) {};
		VectorSI4(DirectX::XMFLOAT4 infloat) : xmFloat_(infloat) {};

		VectorSI4(Float x, Float y, Float z, Float w) : xmFloat_(DirectX::XMFLOAT4(x, y, z, w)) {};
		//VectorSI4(uint32 x, uint32 y, uint32 z, uint32 w) : xmFloat_(DirectX::xmfloattorSetInt(x, y, z, w)) {};

		VectorSI4(Float value) : xmFloat_(DirectX::XMFLOAT4(value, value, value, value)) {};
		//SIMDVector4D(uint32 value) :xmFloat_(DirectX::xmfloattorReplicateInt(value)) {};

		//Copy Constr
		VectorSI4(const VectorSI4& in) noexcept : xmFloat_(in.xmFloat_) {};
		//Assign Constr
		VectorSI4(VectorSI4&& in) noexcept : xmFloat_(in.xmFloat_) {};
#pragma endregion Contructors
#pragma region Operators
	public:
		//Assign By Copy
		VectorSI4& operator=(VectorSI4 const& in) noexcept
		{
			if (&in != this)
			{
				xmFloat_ = in.xmFloat_;
			}
			return *this;
		}
		//Assign by Move
		VectorSI4& operator=(VectorSI4 const&& in) noexcept
		{
			if (&in != this)
			{
				xmFloat_ = in.xmFloat_;
			}
			return *this;
		}

		//Returns Negative(Vector)
		VectorSI4 operator-() const
		{
			VectorSI4 temp;
			DirectX::XMStoreFloat4(&(temp.xmFloat_), DirectX::XMVectorNegate(DirectX::XMLoadFloat4(&xmFloat_)));
			return temp;
		}

		VectorSI4& operator+=(VectorSI4 const& in)
		{
			DirectX::XMStoreFloat4(&xmFloat_, DirectX::XMVectorAdd(DirectX::XMLoadFloat4(&xmFloat_), DirectX::XMLoadFloat4(&in.xmFloat_)));
			return *this;
		}
		VectorSI4& operator-=(VectorSI4 const& in)
		{
			DirectX::XMStoreFloat4(&xmFloat_, DirectX::XMVectorSubtract(DirectX::XMLoadFloat4(&xmFloat_), DirectX::XMLoadFloat4(&in.xmFloat_)));
			return *this;
		}
		VectorSI4& operator*=(VectorSI4 const& in)
		{
			DirectX::XMStoreFloat4(&xmFloat_, DirectX::XMVectorMultiply(DirectX::XMLoadFloat4(&xmFloat_), DirectX::XMLoadFloat4(&in.xmFloat_)));
			return *this;
		}
		VectorSI4& operator/=(VectorSI4 const& in)
		{
			DirectX::XMStoreFloat4(&xmFloat_, DirectX::XMVectorDivide(DirectX::XMLoadFloat4(&xmFloat_), DirectX::XMLoadFloat4(&in.xmFloat_)));
			return *this;
		}

		VectorSI4 operator+ (VectorSI4 const& rin)
		{
			DirectX::XMFLOAT4 temp;
			DirectX::XMStoreFloat4(&temp, DirectX::XMVectorAdd(DirectX::XMLoadFloat4(&xmFloat_), DirectX::XMLoadFloat4(&rin.xmFloat_)));
			return VectorSI4(temp);
		}
		VectorSI4 operator- (VectorSI4 const& rin)
		{
			DirectX::XMFLOAT4 temp;
			DirectX::XMStoreFloat4(&temp, DirectX::XMVectorSubtract(DirectX::XMLoadFloat4(&xmFloat_), DirectX::XMLoadFloat4(&rin.xmFloat_)));
			return VectorSI4(temp);
		}
		VectorSI4 operator* (VectorSI4 const& rin)
		{
			DirectX::XMFLOAT4 temp;
			DirectX::XMStoreFloat4(&temp, DirectX::XMVectorMultiply(DirectX::XMLoadFloat4(&xmFloat_), DirectX::XMLoadFloat4(&rin.xmFloat_)));
			return VectorSI4(temp);
		}
		VectorSI4 operator/ (VectorSI4 const& rin)
		{
			DirectX::XMFLOAT4 temp;
			DirectX::XMStoreFloat4(&temp, DirectX::XMVectorDivide(DirectX::XMLoadFloat4(&xmFloat_), DirectX::XMLoadFloat4(&rin.xmFloat_)));
			return VectorSI4(temp);
		}
#pragma endregion Operators
#pragma region GetSet
	public:
		DirectX::XMFLOAT4 getData() { return xmFloat_; }
		void  setData(DirectX::XMFLOAT4 in) { xmFloat_ = in; };
#pragma endregion GetSet
#pragma region Functions 
	public:
#pragma endregion Functions

	private:
		DirectX::XMFLOAT4 xmFloat_;
	};
}