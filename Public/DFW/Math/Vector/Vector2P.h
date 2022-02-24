#pragma once
#include "DFW/DBasicTypes.h"

namespace DogFW::inline math::inline vector
{
	template<class T>
	class Vector2P
	{
	public:
		Vector2P(T inV = 0) noexcept : x_(inV), y_(inV) {};
		Vector2P(T inX, T inY) noexcept : x_(inX), y_(inY) {};
		Vector2P(Vector2P const & inV) noexcept : x_(inV.x_), y_(inV.y_) {};
		~Vector2P() noexcept {};

	public:
		Int32 getX() const noexcept { return x_; };
		Int32 getY() const noexcept { return y_; };
		void setX(Int32 inX) noexcept { x_ = inX; };
		void setY(Int32 inY) noexcept { y_ = inY; };

	public:
		inline Vector2P operator-() const noexcept { return Vector2IntPrimitive(-x_, -y_); };

		//Vector2P
		Vector2P& operator+=(Vector2P const& inV)  noexcept
		{
			x_ += inV.x_;
			y_ += inV.y_;

			return *this;
		};
		Vector2P& operator-=(Vector2P const& inV) noexcept
		{
			x_ -= inV.x_;
			y_ -= inV.y_;

			return *this;
		};
		Vector2P& operator*=(Vector2P const& inV) noexcept
		{
			x_ *= inV.x_;
			y_ *= inV.y_;

			return *this;
		};
		Vector2P& operator/=(Vector2P const& inV) noexcept
		{
			x_ /= inV.x_;
			y_ /= inV.y_;

			return *this;
		};

		Vector2P operator+(Vector2P const& inV) const noexcept { return Vector2IntPrimitive(x_ + inV.x_, y_ + inV.y_); };
		Vector2P operator-(Vector2P const& inV) const noexcept { return Vector2IntPrimitive(x_ - inV.x_, y_ - inV.y_); };
		Vector2P operator*(Vector2P const& inV) const noexcept { return Vector2IntPrimitive(x_ * inV.x_, y_ * inV.y_); };
		Vector2P operator/(Vector2P const& inV) const noexcept { return Vector2IntPrimitive(x_ / inV.x_, y_ / inV.y_); };

		//Type T
		Vector2P& operator+=(T const& inV) noexcept
		{
			x_ += inV;
			y_ += inV;
			return *this;
		};
		Vector2P& operator-=(T const& inV) noexcept
		{
			x_ -= inV;
			y_ -= inV;
			return *this;
		};
		Vector2P& operator*=(T const& inV) noexcept
		{
			x_ *= inV;
			y_ *= inV;
			return *this;
		};
		Vector2P& operator/=(T const& inV) noexcept
		{
			x_ /= inV;
			y_ /= inV;
			return *this;
		};

		Vector2P operator+(T const& inV) const noexcept { return Vector2IntPrimitive(x_ + inV, y_ + inV); };
		Vector2P operator-(T const& inV) const noexcept { return Vector2IntPrimitive(x_ - inV, y_ - inV); };
		Vector2P operator*(T const& inV) const noexcept { return Vector2IntPrimitive(x_ * inV, y_ * inV); };
		Vector2P operator/(T const& inV) const noexcept { return Vector2IntPrimitive(x_ / inV, y_ / inV); };
	public:
		Vector2P abs()const noexcept { return Vector2P(math::abs(x_), math::abs(y_)); };

	private:
		T x_ = 0;
		T y_ = 0;
	};
}

namespace DogFW::math
{
	template<class T>
	vector::Vector2P<T> abs(vector::Vector2P<T> const& inV) noexcept { return inV.abs(); };
}
