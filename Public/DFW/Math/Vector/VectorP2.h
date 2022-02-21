#pragma once
#include "DFW/DBasicTypes.h"

namespace DogFW::math::vector
{
	template<class T>
	class VectorP2
	{
	public:
		VectorP2(T inV = 0) : x_(inV), y_(inV) {};
		VectorP2(T inX, T inY) : x_(inX), y_(inY) {};
		VectorP2(VectorP2 const & inV) : x_(inV.x_), y_(inV.y_) {};
		~VectorP2() {};

	public:
		Int32 getX() const { return x_; };
		Int32 getY() const { return y_; };
		void setX(Int32 inX) { x_ = inX; };
		void setY(Int32 inY) { y_ = inY; };

	public:
		inline VectorP2 operator-() const { return Vector2IntPrimitive(-x_, -y_); };

		//VectorP2
		VectorP2& operator+=(VectorP2 const& inV) 
		{
			x_ += inV.x_;
			y_ += inV.y_;

			return *this;
		};
		VectorP2& operator-=(VectorP2 const& inV)
		{
			x_ -= inV.x_;
			y_ -= inV.y_;

			return *this;
		};
		VectorP2& operator*=(VectorP2 const& inV) 
		{
			x_ *= inV.x_;
			y_ *= inV.y_;

			return *this;
		};
		VectorP2& operator/=(VectorP2 const& inV)
		{
			x_ /= inV.x_;
			y_ /= inV.y_;

			return *this;
		};

		VectorP2 operator+(VectorP2 const& inV) const { return Vector2IntPrimitive(x_ + inV.x_, y_ + inV.y_); };
		VectorP2 operator-(VectorP2 const& inV) const { return Vector2IntPrimitive(x_ - inV.x_, y_ - inV.y_); };
		VectorP2 operator*(VectorP2 const& inV) const { return Vector2IntPrimitive(x_ * inV.x_, y_ * inV.y_); };
		VectorP2 operator/(VectorP2 const& inV) const { return Vector2IntPrimitive(x_ / inV.x_, y_ / inV.y_); };

		//Type T
		VectorP2& operator+=(T const& inV) 
		{
			x_ += inV;
			y_ += inV;
			return *this;
		};
		VectorP2& operator-=(T const& inV) 
		{
			x_ -= inV;
			y_ -= inV;
			return *this;
		};
		VectorP2& operator*=(T const& inV) 
		{
			x_ *= inV;
			y_ *= inV;
			return *this;
		};
		VectorP2& operator/=(T const& inV) 
		{
			x_ /= inV;
			y_ /= inV;
			return *this;
		};

		VectorP2 operator+(T const& inV) const { return Vector2IntPrimitive(x_ + inV, y_ + inV); };
		VectorP2 operator-(T const& inV) const { return Vector2IntPrimitive(x_ - inV, y_ - inV); };
		VectorP2 operator*(T const& inV) const { return Vector2IntPrimitive(x_ * inV, y_ * inV); };
		VectorP2 operator/(T const& inV) const { return Vector2IntPrimitive(x_ / inV, y_ / inV); };
	public:
		VectorP2 abs()const { return VectorP2(math::abs(x_), math::abs(y_)); };

	private:
		T x_ = 0;
		T y_ = 0;
	};
}

namespace DogFW::math
{
	template<class T>
	vector::VectorP2<T> abs(vector::VectorP2<T> const& inV) { return inV.abs(); };
}
