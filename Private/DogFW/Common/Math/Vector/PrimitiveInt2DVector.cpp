#include "DogFW/Common/Math/Vector/PrimitiveInt2DVector.h"

#include <cmath>

namespace DogFW::math::inline vector
{
#pragma region Contructors
	PrimitiveInt2DVector::PrimitiveInt2DVector(Int32 inV) :x_(inV),y_(inV) {};
	PrimitiveInt2DVector::PrimitiveInt2DVector(Int32 inX, Int32 inY) :x_(inX), y_(inY) {};
	PrimitiveInt2DVector::~PrimitiveInt2DVector() {};
#pragma endregion Constructors

#pragma region GetSet
	Int32 PrimitiveInt2DVector::getX() const
	{
		return x_;
	}
	Int32 PrimitiveInt2DVector::getY() const
	{
		return y_;
	}
	void PrimitiveInt2DVector::setX(Int32 inX)
	{
		x_ = inX;
	}
	void PrimitiveInt2DVector::setY(Int32 inY)
	{
		y_ = inY;
	}
#pragma endregion GetSet
	
#pragma region Operators

	inline PrimitiveInt2DVector PrimitiveInt2DVector::operator-() const
	{
		return PrimitiveInt2DVector(-x_,-y_);
	}

#pragma region PrimitiveInt2DVector
	//PrimitiveInt2DVector
	PrimitiveInt2DVector& PrimitiveInt2DVector::operator+=(PrimitiveInt2DVector const& inV)
	{
		x_ += inV.x_;
		y_ += inV.y_;

		return *this;
	}

	PrimitiveInt2DVector& PrimitiveInt2DVector::operator-=(PrimitiveInt2DVector const& inV)
	{
		x_ -= inV.x_;
		y_ -= inV.y_;

		return *this;
	}

	PrimitiveInt2DVector& PrimitiveInt2DVector::operator*=(PrimitiveInt2DVector const& inV)
	{
		x_ *= inV.x_;
		y_ *= inV.y_;

		return *this;
	}

	PrimitiveInt2DVector& PrimitiveInt2DVector::operator/=(PrimitiveInt2DVector const& inV)
	{
		x_ /= inV.x_;
		y_ /= inV.y_;

		return *this;
	}

	PrimitiveInt2DVector PrimitiveInt2DVector::operator+(PrimitiveInt2DVector const& inV) const
	{
		return PrimitiveInt2DVector(x_+inV.x_,y_+inV.y_);
	}

	PrimitiveInt2DVector PrimitiveInt2DVector::operator-(PrimitiveInt2DVector const& inV) const
	{
		return PrimitiveInt2DVector(x_ - inV.x_, y_ - inV.y_);
	}

	PrimitiveInt2DVector PrimitiveInt2DVector::operator*(PrimitiveInt2DVector const& inV) const
	{
		return PrimitiveInt2DVector(x_ * inV.x_, y_ * inV.y_);
	}

	PrimitiveInt2DVector PrimitiveInt2DVector::operator/(PrimitiveInt2DVector const& inV) const
	{
		return PrimitiveInt2DVector(x_ / inV.x_, y_ / inV.y_);
	}

#pragma endregion PrimitiveInt2DVector

#pragma region Int32
	//Int
	PrimitiveInt2DVector& PrimitiveInt2DVector::operator+=(Int32 const& inV)
	{
		x_ += inV;
		y_ += inV;
		return *this;
	}
	PrimitiveInt2DVector& PrimitiveInt2DVector::operator-=(Int32 const& inV)
	{
		x_ -= inV;
		y_ -= inV;
		return *this;
	}
	PrimitiveInt2DVector& PrimitiveInt2DVector::operator*=(Int32 const& inV)
	{
		x_ *= inV;
		y_ *= inV;
		return *this;
	}
	PrimitiveInt2DVector& PrimitiveInt2DVector::operator/=(Int32 const& inV)
	{
		x_ /= inV;
		y_ /= inV;
		return *this;
	}
	PrimitiveInt2DVector PrimitiveInt2DVector::operator+(Int32 const& inV) const
	{
		return PrimitiveInt2DVector(x_+inV,y_+inV);
	}
	PrimitiveInt2DVector PrimitiveInt2DVector::operator-(Int32 const& inV) const
	{
		return PrimitiveInt2DVector(x_-inV,y_-inV);
	}
	PrimitiveInt2DVector PrimitiveInt2DVector::operator*(Int32 const& inV) const
	{
		return PrimitiveInt2DVector(x_*inV,y_*inV);
	}
	PrimitiveInt2DVector PrimitiveInt2DVector::operator/(Int32 const& inV) const
	{
		return PrimitiveInt2DVector(x_/inV,y_/inV);
	}
#pragma endregion Int

#pragma endregion Operators

#pragma region Functions

	PrimitiveInt2DVector PrimitiveInt2DVector::abs() const
	{
		return PrimitiveInt2DVector(math::abs(x_),math::abs(y_));
	}

#pragma endregion Functions
}

namespace DogFW::math
{
	PrimitiveInt2DVector abs(PrimitiveInt2DVector const& inV)
	{
		return inV.abs();
	}
}
