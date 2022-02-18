#pragma once
#include "DogFW/DogBasicTypes.h"

namespace DogFW::math::vector
{
	class Vector2IntPrimitive
	{
	public:
		Vector2IntPrimitive(Int32 inV = 0);
		Vector2IntPrimitive(Int32 inX, Int32 inY);
		~Vector2IntPrimitive();

	public:
		Int32 getX() const;
		Int32 getY() const;
		void setX(Int32 inX);
		void setY(Int32 inY);

	public:
		inline Vector2IntPrimitive operator-() const;

		//Vector2IntPrimitive
		Vector2IntPrimitive& operator+=(Vector2IntPrimitive const &inV);
		Vector2IntPrimitive& operator-=(Vector2IntPrimitive const& inV);
		Vector2IntPrimitive& operator*=(Vector2IntPrimitive const& inV);
		Vector2IntPrimitive& operator/=(Vector2IntPrimitive const& inV);

		Vector2IntPrimitive operator+(Vector2IntPrimitive const& inV) const;
		Vector2IntPrimitive operator-(Vector2IntPrimitive const& inV) const;
		Vector2IntPrimitive operator*(Vector2IntPrimitive const& inV) const;
		Vector2IntPrimitive operator/(Vector2IntPrimitive const& inV) const;

		//Int
		Vector2IntPrimitive& operator+=(Int32 const& inV);
		Vector2IntPrimitive& operator-=(Int32 const& inV);
		Vector2IntPrimitive& operator*=(Int32 const& inV);
		Vector2IntPrimitive& operator/=(Int32 const& inV);

		Vector2IntPrimitive operator+(Int32 const& inV) const;
		Vector2IntPrimitive operator-(Int32 const& inV) const;
		Vector2IntPrimitive operator*(Int32 const& inV) const;
		Vector2IntPrimitive operator/(Int32 const& inV) const;

		//Float?

	public:
		Vector2IntPrimitive abs()const;

	private:
		Int32 x_ = 0;
		Int32 y_ = 0;
	};
}

namespace DogFW::math
{
	vector::Vector2IntPrimitive abs(vector::Vector2IntPrimitive const& inV);
}

