#include "DFW/Math/Vector/VectorF4S_XMF4.h"

namespace DogFW::inline math::inline vector::simdvector
{
	VectorF4S_XMF4::VectorF4S_XMF4() noexcept : xmFloat_(DirectX::XMFLOAT4(0.f, 0.f, 0.f, 0.f))  {};
	VectorF4S_XMF4::VectorF4S_XMF4(Float value) noexcept : xmFloat_(DirectX::XMFLOAT4(value, value, value, value)) {};
	VectorF4S_XMF4::VectorF4S_XMF4(Float x, Float y, Float z, Float w) noexcept : xmFloat_(DirectX::XMFLOAT4(x, y, z, w)) {};

	VectorF4S_XMF4::VectorF4S_XMF4(DirectX::XMFLOAT4 infloat) noexcept : xmFloat_(infloat) {};

	VectorF4S_XMF4::~VectorF4S_XMF4()noexcept {};


	VectorF4S_XMF4::VectorF4S_XMF4(const VectorF4S_XMF4& in) noexcept : xmFloat_(in.xmFloat_) {};
	VectorF4S_XMF4::VectorF4S_XMF4(VectorF4S_XMF4&& in) noexcept : xmFloat_(in.xmFloat_) {};

	VectorF4S_XMF4& VectorF4S_XMF4::operator=(VectorF4S_XMF4 const& in) noexcept
	{
		if (&in != this)
		{
			xmFloat_ = in.xmFloat_;
		}
		return *this;
	};
	VectorF4S_XMF4& VectorF4S_XMF4::operator=(VectorF4S_XMF4&& in) noexcept
	{
		if (&in != this)
		{
			xmFloat_ = in.xmFloat_;
		}
		return *this;
	}


	VectorF4S_XMF4 VectorF4S_XMF4::operator-() const noexcept
	{
		VectorF4S_XMF4 temp;
		DirectX::XMStoreFloat4(&(temp.xmFloat_), DirectX::XMVectorNegate(DirectX::XMLoadFloat4(&xmFloat_)));
		return temp;
	}

	VectorF4S_XMF4& VectorF4S_XMF4::operator+=(VectorF4S_XMF4 const& in)noexcept
	{
		DirectX::XMStoreFloat4(&xmFloat_, DirectX::XMVectorAdd(DirectX::XMLoadFloat4(&xmFloat_), DirectX::XMLoadFloat4(&in.xmFloat_)));
		return *this;
	}
	VectorF4S_XMF4& VectorF4S_XMF4::operator-=(VectorF4S_XMF4 const& in)noexcept
	{
		DirectX::XMStoreFloat4(&xmFloat_, DirectX::XMVectorSubtract(DirectX::XMLoadFloat4(&xmFloat_), DirectX::XMLoadFloat4(&in.xmFloat_)));
		return *this;
	}
	VectorF4S_XMF4& VectorF4S_XMF4::operator*=(VectorF4S_XMF4 const& in)noexcept
	{
		DirectX::XMStoreFloat4(&xmFloat_, DirectX::XMVectorMultiply(DirectX::XMLoadFloat4(&xmFloat_), DirectX::XMLoadFloat4(&in.xmFloat_)));
		return *this;
	}
	VectorF4S_XMF4& VectorF4S_XMF4::operator/=(VectorF4S_XMF4 const& in)noexcept
	{
		DirectX::XMStoreFloat4(&xmFloat_, DirectX::XMVectorDivide(DirectX::XMLoadFloat4(&xmFloat_), DirectX::XMLoadFloat4(&in.xmFloat_)));
		return *this;
	}

	VectorF4S_XMF4 VectorF4S_XMF4::operator+ (VectorF4S_XMF4 const& rin)const noexcept
	{
		DirectX::XMFLOAT4 temp;
		DirectX::XMStoreFloat4(&temp, DirectX::XMVectorAdd(DirectX::XMLoadFloat4(&xmFloat_), DirectX::XMLoadFloat4(&rin.xmFloat_)));
		return VectorF4S_XMF4(temp);
	}
	VectorF4S_XMF4 VectorF4S_XMF4::operator- (VectorF4S_XMF4 const& rin)const noexcept
	{
		DirectX::XMFLOAT4 temp;
		DirectX::XMStoreFloat4(&temp, DirectX::XMVectorSubtract(DirectX::XMLoadFloat4(&xmFloat_), DirectX::XMLoadFloat4(&rin.xmFloat_)));
		return VectorF4S_XMF4(temp);
	}
	VectorF4S_XMF4 VectorF4S_XMF4::operator* (VectorF4S_XMF4 const& rin)const noexcept
	{
		DirectX::XMFLOAT4 temp;
		DirectX::XMStoreFloat4(&temp, DirectX::XMVectorMultiply(DirectX::XMLoadFloat4(&xmFloat_), DirectX::XMLoadFloat4(&rin.xmFloat_)));
		return VectorF4S_XMF4(temp);
	}
	VectorF4S_XMF4 VectorF4S_XMF4::operator/ (VectorF4S_XMF4 const& rin)const noexcept
	{
		DirectX::XMFLOAT4 temp;
		DirectX::XMStoreFloat4(&temp, DirectX::XMVectorDivide(DirectX::XMLoadFloat4(&xmFloat_), DirectX::XMLoadFloat4(&rin.xmFloat_)));
		return VectorF4S_XMF4(temp);
	}

	DirectX::XMFLOAT4 VectorF4S_XMF4::getData()const noexcept { return xmFloat_; }
	DirectX::XMFLOAT4& VectorF4S_XMF4::getDataR()noexcept { return xmFloat_; }

}
