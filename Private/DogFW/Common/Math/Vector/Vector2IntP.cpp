#include "DogFW/Common/Math/Vector/Vector2IntP.h"

#include <cmath>

namespace DogFW::math::vector
{
#pragma region Contructors
	Vector2IntPrimitive::Vector2IntPrimitive(Int32 inV) :x_(inV),y_(inV) {};
	Vector2IntPrimitive::Vector2IntPrimitive(Int32 inX, Int32 inY) :x_(inX), y_(inY) {};
	Vector2IntPrimitive::~Vector2IntPrimitive() {};
#pragma endregion Constructors

#pragma region GetSet
	Int32 Vector2IntPrimitive::getX() const
	{
		return x_;
	}
	Int32 Vector2IntPrimitive::getY() const
	{
		return y_;
	}
	void Vector2IntPrimitive::setX(Int32 inX)
	{
		x_ = inX;
	}
	void Vector2IntPrimitive::setY(Int32 inY)
	{
		y_ = inY;
	}
#pragma endregion GetSet
	
#pragma region Operators

	inline Vector2IntPrimitive Vector2IntPrimitive::operator-() const
	{
		return Vector2IntPrimitive(-x_,-y_);
	}

#pragma region Vector2IntPrimitive
	//Vector2IntPrimitive
	Vector2IntPrimitive& Vector2IntPrimitive::operator+=(Vector2IntPrimitive const& inV)
	{
		x_ += inV.x_;
		y_ += inV.y_;

		return *this;
	}

	Vector2IntPrimitive& Vector2IntPrimitive::operator-=(Vector2IntPrimitive const& inV)
	{
		x_ -= inV.x_;
		y_ -= inV.y_;

		return *this;
	}

	Vector2IntPrimitive& Vector2IntPrimitive::operator*=(Vector2IntPrimitive const& inV)
	{
		x_ *= inV.x_;
		y_ *= inV.y_;

		return *this;
	}

	Vector2IntPrimitive& Vector2IntPrimitive::operator/=(Vector2IntPrimitive const& inV)
	{
		x_ /= inV.x_;
		y_ /= inV.y_;

		return *this;
	}

	Vector2IntPrimitive Vector2IntPrimitive::operator+(Vector2IntPrimitive const& inV) const
	{
		return Vector2IntPrimitive(x_+inV.x_,y_+inV.y_);
	}

	Vector2IntPrimitive Vector2IntPrimitive::operator-(Vector2IntPrimitive const& inV) const
	{
		return Vector2IntPrimitive(x_ - inV.x_, y_ - inV.y_);
	}

	Vector2IntPrimitive Vector2IntPrimitive::operator*(Vector2IntPrimitive const& inV) const
	{
		return Vector2IntPrimitive(x_ * inV.x_, y_ * inV.y_);
	}

	Vector2IntPrimitive Vector2IntPrimitive::operator/(Vector2IntPrimitive const& inV) const
	{
		return Vector2IntPrimitive(x_ / inV.x_, y_ / inV.y_);
	}

#pragma endregion Vector2IntPrimitive

#pragma region Int32
	//Int
	Vector2IntPrimitive& Vector2IntPrimitive::operator+=(Int32 const& inV)
	{
		x_ += inV;
		y_ += inV;
		return *this;
	}
	Vector2IntPrimitive& Vector2IntPrimitive::operator-=(Int32 const& inV)
	{
		x_ -= inV;
		y_ -= inV;
		return *this;
	}
	Vector2IntPrimitive& Vector2IntPrimitive::operator*=(Int32 const& inV)
	{
		x_ *= inV;
		y_ *= inV;
		return *this;
	}
	Vector2IntPrimitive& Vector2IntPrimitive::operator/=(Int32 const& inV)
	{
		x_ /= inV;
		y_ /= inV;
		return *this;
	}
	Vector2IntPrimitive Vector2IntPrimitive::operator+(Int32 const& inV) const
	{
		return Vector2IntPrimitive(x_+inV,y_+inV);
	}
	Vector2IntPrimitive Vector2IntPrimitive::operator-(Int32 const& inV) const
	{
		return Vector2IntPrimitive(x_-inV,y_-inV);
	}
	Vector2IntPrimitive Vector2IntPrimitive::operator*(Int32 const& inV) const
	{
		return Vector2IntPrimitive(x_*inV,y_*inV);
	}
	Vector2IntPrimitive Vector2IntPrimitive::operator/(Int32 const& inV) const
	{
		return Vector2IntPrimitive(x_/inV,y_/inV);
	}
#pragma endregion Int

#pragma endregion Operators

#pragma region Functions

	Vector2IntPrimitive Vector2IntPrimitive::abs() const
	{
		return Vector2IntPrimitive(math::abs(x_),math::abs(y_));
	}

#pragma endregion Functions
}

namespace DogFW::math
{
	vector::Vector2IntPrimitive abs(vector::Vector2IntPrimitive const& inV)
	{
		return inV.abs();
	}
}
