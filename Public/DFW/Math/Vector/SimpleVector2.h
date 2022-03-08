#pragma once
#include "DFW/DBase.h"

namespace DogFW::vector::simple
{
	template<class T>
	class Vector2
	{
	public:
		Vector2(T inV = 0) noexcept : x_(inV), y_(inV) {};
		Vector2(T inX, T inY) noexcept : x_(inX), y_(inY) {};
		Vector2(Vector2 const & inV) noexcept : x_(inV.x_), y_(inV.y_) {};
		~Vector2() noexcept {};

	public:
		Int32 getX() const noexcept { return x_; };
		Int32 getY() const noexcept { return y_; };
		void setX(Int32 inX) noexcept { x_ = inX; };
		void setY(Int32 inY) noexcept { y_ = inY; };

	public:
		Vector2 operator-() const noexcept { return Vector2IntPrimitive(-x_, -y_); };

		//Vector2
		Vector2& operator+=(Vector2 const& inV)  noexcept
		{
			x_ += inV.x_;
			y_ += inV.y_;

			return *this;
		};
		Vector2& operator-=(Vector2 const& inV) noexcept
		{
			x_ -= inV.x_;
			y_ -= inV.y_;

			return *this;
		};
		Vector2& operator*=(Vector2 const& inV) noexcept
		{
			x_ *= inV.x_;
			y_ *= inV.y_;

			return *this;
		};
		Vector2& operator/=(Vector2 const& inV) noexcept
		{
			x_ /= inV.x_;
			y_ /= inV.y_;

			return *this;
		};

		Vector2 operator+(Vector2 const& inV) const noexcept { return Vector2IntPrimitive(x_ + inV.x_, y_ + inV.y_); };
		Vector2 operator-(Vector2 const& inV) const noexcept { return Vector2IntPrimitive(x_ - inV.x_, y_ - inV.y_); };
		Vector2 operator*(Vector2 const& inV) const noexcept { return Vector2IntPrimitive(x_ * inV.x_, y_ * inV.y_); };
		Vector2 operator/(Vector2 const& inV) const noexcept { return Vector2IntPrimitive(x_ / inV.x_, y_ / inV.y_); };

		//Type T
		Vector2& operator+=(T const& inV) noexcept
		{
			x_ += inV;
			y_ += inV;
			return *this;
		};
		Vector2& operator-=(T const& inV) noexcept
		{
			x_ -= inV;
			y_ -= inV;
			return *this;
		};
		Vector2& operator*=(T const& inV) noexcept
		{
			x_ *= inV;
			y_ *= inV;
			return *this;
		};
		Vector2& operator/=(T const& inV) noexcept
		{
			x_ /= inV;
			y_ /= inV;
			return *this;
		};

		Vector2 operator+(T const& inV) const noexcept { return Vector2IntPrimitive(x_ + inV, y_ + inV); };
		Vector2 operator-(T const& inV) const noexcept { return Vector2IntPrimitive(x_ - inV, y_ - inV); };
		Vector2 operator*(T const& inV) const noexcept { return Vector2IntPrimitive(x_ * inV, y_ * inV); };
		Vector2 operator/(T const& inV) const noexcept { return Vector2IntPrimitive(x_ / inV, y_ / inV); };
	public:
		Vector2 abs()const noexcept { return Vector2(math::abs(x_), math::abs(y_)); };

	private:
		T x_ = 0;
		T y_ = 0;
	};
}

namespace DogFW::math
{
	template<class T>
	vector::simple::Vector2<T> abs(vector::simple::Vector2<T> const& inV) noexcept { return inV.abs(); };
}
