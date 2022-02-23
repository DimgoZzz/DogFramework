#pragma once
#include "DFW/DBasicTypes.h"

namespace DogFW::inline math :: inline vector
{
	template<class T>
	class Vector2P
	{
	public:
		Vector2P(T inV = 0) : x_(inV), y_(inV) {};
		Vector2P(T inX, T inY) : x_(inX), y_(inY) {};
		Vector2P(Vector2P const & inV) : x_(inV.x_), y_(inV.y_) {};
		~Vector2P() {};

	public:
		Int32 getX() const { return x_; };
		Int32 getY() const { return y_; };
		void setX(Int32 inX) { x_ = inX; };
		void setY(Int32 inY) { y_ = inY; };

	public:
		inline Vector2P operator-() const { return Vector2IntPrimitive(-x_, -y_); };

		//Vector2P
		Vector2P& operator+=(Vector2P const& inV) 
		{
			x_ += inV.x_;
			y_ += inV.y_;

			return *this;
		};
		Vector2P& operator-=(Vector2P const& inV)
		{
			x_ -= inV.x_;
			y_ -= inV.y_;

			return *this;
		};
		Vector2P& operator*=(Vector2P const& inV) 
		{
			x_ *= inV.x_;
			y_ *= inV.y_;

			return *this;
		};
		Vector2P& operator/=(Vector2P const& inV)
		{
			x_ /= inV.x_;
			y_ /= inV.y_;

			return *this;
		};

		Vector2P operator+(Vector2P const& inV) const { return Vector2IntPrimitive(x_ + inV.x_, y_ + inV.y_); };
		Vector2P operator-(Vector2P const& inV) const { return Vector2IntPrimitive(x_ - inV.x_, y_ - inV.y_); };
		Vector2P operator*(Vector2P const& inV) const { return Vector2IntPrimitive(x_ * inV.x_, y_ * inV.y_); };
		Vector2P operator/(Vector2P const& inV) const { return Vector2IntPrimitive(x_ / inV.x_, y_ / inV.y_); };

		//Type T
		Vector2P& operator+=(T const& inV) 
		{
			x_ += inV;
			y_ += inV;
			return *this;
		};
		Vector2P& operator-=(T const& inV) 
		{
			x_ -= inV;
			y_ -= inV;
			return *this;
		};
		Vector2P& operator*=(T const& inV) 
		{
			x_ *= inV;
			y_ *= inV;
			return *this;
		};
		Vector2P& operator/=(T const& inV) 
		{
			x_ /= inV;
			y_ /= inV;
			return *this;
		};

		Vector2P operator+(T const& inV) const { return Vector2IntPrimitive(x_ + inV, y_ + inV); };
		Vector2P operator-(T const& inV) const { return Vector2IntPrimitive(x_ - inV, y_ - inV); };
		Vector2P operator*(T const& inV) const { return Vector2IntPrimitive(x_ * inV, y_ * inV); };
		Vector2P operator/(T const& inV) const { return Vector2IntPrimitive(x_ / inV, y_ / inV); };
	public:
		Vector2P abs()const { return Vector2P(math::abs(x_), math::abs(y_)); };

	private:
		T x_ = 0;
		T y_ = 0;
	};
}

namespace DogFW::math
{
	template<class T>
	vector::Vector2P<T> abs(vector::Vector2P<T> const& inV) { return inV.abs(); };
}
