#pragma once
#include "DFW/DBase.h"
#include "DFW/DDX12.h"

namespace DogFW::vector::simd
{
	//4D vector based on storing data into xmFloat_
	class Vector4F
	{
	public:
		Vector4F() noexcept;
		Vector4F(Float value) noexcept;
		Vector4F(Float x, Float y, Float z, Float w) noexcept;
		
		Vector4F(DirectX::XMFLOAT4 infloat) noexcept;

		~Vector4F() noexcept;

		//Copy Constr
		Vector4F(const Vector4F& in) noexcept;
		//Move Constr
		Vector4F(Vector4F&& in) noexcept;
		//Assign Copy
		Vector4F& operator=(Vector4F const& in) noexcept;
		//Assign Move
		Vector4F& operator=(Vector4F && in) noexcept;

	public:
		//Returns Negative(Vector)
		Vector4F operator-() const noexcept;

		Vector4F& operator+=(Vector4F const& in)noexcept;
		Vector4F& operator-=(Vector4F const& in)noexcept;
		Vector4F& operator*=(Vector4F const& in)noexcept;
		Vector4F& operator/=(Vector4F const& in)noexcept;

		Vector4F operator+ (Vector4F const& rin)const noexcept;
		Vector4F operator- (Vector4F const& rin)const noexcept;
		Vector4F operator* (Vector4F const& rin)const noexcept;
		Vector4F operator/ (Vector4F const& rin)const noexcept;
	public:
		DirectX::XMFLOAT4 getData()const noexcept;
		DirectX::XMFLOAT4& getDataR()noexcept;
		
	private:
		DirectX::XMFLOAT4 xmFloat_;
	};
}