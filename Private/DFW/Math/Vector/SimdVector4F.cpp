#include "DFW/Math/Vector/SimdVector4F.h"

namespace DogFW::vector::simd
{
	Vector4F::Vector4F() noexcept : xmFloat_(DirectX::XMFLOAT4(0.f, 0.f, 0.f, 0.f))  {};
	Vector4F::Vector4F(Float value) noexcept : xmFloat_(DirectX::XMFLOAT4(value, value, value, value)) {};
	Vector4F::Vector4F(Float x, Float y, Float z, Float w) noexcept : xmFloat_(DirectX::XMFLOAT4(x, y, z, w)) {};

	Vector4F::Vector4F(DirectX::XMFLOAT4 infloat) noexcept : xmFloat_(infloat) {};

	Vector4F::~Vector4F()noexcept {};


	Vector4F::Vector4F(const Vector4F& in) noexcept : xmFloat_(in.xmFloat_) {};
	Vector4F::Vector4F(Vector4F&& in) noexcept : xmFloat_(in.xmFloat_) {};

	Vector4F& Vector4F::operator=(Vector4F const& in) noexcept
	{
		if (&in != this)
		{
			xmFloat_ = in.xmFloat_;
		}
		return *this;
	};
	Vector4F& Vector4F::operator=(Vector4F&& in) noexcept
	{
		if (&in != this)
		{
			xmFloat_ = in.xmFloat_;
		}
		return *this;
	}


	Vector4F Vector4F::operator-() const noexcept
	{
		Vector4F temp;
		DirectX::XMStoreFloat4(&(temp.xmFloat_), DirectX::XMVectorNegate(DirectX::XMLoadFloat4(&xmFloat_)));
		return temp;
	}

	Vector4F& Vector4F::operator+=(Vector4F const& in)noexcept
	{
		DirectX::XMStoreFloat4(&xmFloat_, DirectX::XMVectorAdd(DirectX::XMLoadFloat4(&xmFloat_), DirectX::XMLoadFloat4(&in.xmFloat_)));
		return *this;
	}
	Vector4F& Vector4F::operator-=(Vector4F const& in)noexcept
	{
		DirectX::XMStoreFloat4(&xmFloat_, DirectX::XMVectorSubtract(DirectX::XMLoadFloat4(&xmFloat_), DirectX::XMLoadFloat4(&in.xmFloat_)));
		return *this;
	}
	Vector4F& Vector4F::operator*=(Vector4F const& in)noexcept
	{
		DirectX::XMStoreFloat4(&xmFloat_, DirectX::XMVectorMultiply(DirectX::XMLoadFloat4(&xmFloat_), DirectX::XMLoadFloat4(&in.xmFloat_)));
		return *this;
	}
	Vector4F& Vector4F::operator/=(Vector4F const& in)noexcept
	{
		DirectX::XMStoreFloat4(&xmFloat_, DirectX::XMVectorDivide(DirectX::XMLoadFloat4(&xmFloat_), DirectX::XMLoadFloat4(&in.xmFloat_)));
		return *this;
	}

	Vector4F Vector4F::operator+ (Vector4F const& rin)const noexcept
	{
		DirectX::XMFLOAT4 temp;
		DirectX::XMStoreFloat4(&temp, DirectX::XMVectorAdd(DirectX::XMLoadFloat4(&xmFloat_), DirectX::XMLoadFloat4(&rin.xmFloat_)));
		return Vector4F(temp);
	}
	Vector4F Vector4F::operator- (Vector4F const& rin)const noexcept
	{
		DirectX::XMFLOAT4 temp;
		DirectX::XMStoreFloat4(&temp, DirectX::XMVectorSubtract(DirectX::XMLoadFloat4(&xmFloat_), DirectX::XMLoadFloat4(&rin.xmFloat_)));
		return Vector4F(temp);
	}
	Vector4F Vector4F::operator* (Vector4F const& rin)const noexcept
	{
		DirectX::XMFLOAT4 temp;
		DirectX::XMStoreFloat4(&temp, DirectX::XMVectorMultiply(DirectX::XMLoadFloat4(&xmFloat_), DirectX::XMLoadFloat4(&rin.xmFloat_)));
		return Vector4F(temp);
	}
	Vector4F Vector4F::operator/ (Vector4F const& rin)const noexcept
	{
		DirectX::XMFLOAT4 temp;
		DirectX::XMStoreFloat4(&temp, DirectX::XMVectorDivide(DirectX::XMLoadFloat4(&xmFloat_), DirectX::XMLoadFloat4(&rin.xmFloat_)));
		return Vector4F(temp);
	}

	DirectX::XMFLOAT4 Vector4F::getData()const noexcept { return xmFloat_; }
	DirectX::XMFLOAT4& Vector4F::getDataR()noexcept { return xmFloat_; }
}
