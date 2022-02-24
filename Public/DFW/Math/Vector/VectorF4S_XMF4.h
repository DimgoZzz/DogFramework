#pragma once
#include "DFW/DBasicTypes.h"
#include "DFW/External/DirectX/DogDirectX.h"

namespace DogFW::inline math::inline vector::simdvector
{
	//4D vector based on storing data into xmFloat_
	class VectorF4S_XMF4
	{
	public:
		VectorF4S_XMF4() noexcept;
		VectorF4S_XMF4(Float value) noexcept;
		VectorF4S_XMF4(Float x, Float y, Float z, Float w) noexcept;
		
		VectorF4S_XMF4(DirectX::XMFLOAT4 infloat) noexcept;

		~VectorF4S_XMF4() noexcept;

		//Copy Constr
		VectorF4S_XMF4(const VectorF4S_XMF4& in) noexcept;
		//Move Constr
		VectorF4S_XMF4(VectorF4S_XMF4&& in) noexcept;
		//Assign Copy
		VectorF4S_XMF4& operator=(VectorF4S_XMF4 const& in) noexcept;
		//Assign Move
		VectorF4S_XMF4& operator=(VectorF4S_XMF4 && in) noexcept;

	public:
		//Returns Negative(Vector)
		VectorF4S_XMF4 operator-() const noexcept;

		VectorF4S_XMF4& operator+=(VectorF4S_XMF4 const& in)noexcept;
		VectorF4S_XMF4& operator-=(VectorF4S_XMF4 const& in)noexcept;
		VectorF4S_XMF4& operator*=(VectorF4S_XMF4 const& in)noexcept;
		VectorF4S_XMF4& operator/=(VectorF4S_XMF4 const& in)noexcept;

		VectorF4S_XMF4 operator+ (VectorF4S_XMF4 const& rin)const noexcept;
		VectorF4S_XMF4 operator- (VectorF4S_XMF4 const& rin)const noexcept;
		VectorF4S_XMF4 operator* (VectorF4S_XMF4 const& rin)const noexcept;
		VectorF4S_XMF4 operator/ (VectorF4S_XMF4 const& rin)const noexcept;
	public:
		DirectX::XMFLOAT4 getData()const noexcept;
		DirectX::XMFLOAT4& getDataR()noexcept;
		
	private:
		DirectX::XMFLOAT4 xmFloat_;
	};
}