#pragma once
#include "DogFW/DogBasicTypes.h"

namespace DogFW::math::inline vector
{
	class PrimitiveInt2DVector
	{
	public:
		PrimitiveInt2DVector(Int32 inV = 0);
		PrimitiveInt2DVector(Int32 inX, Int32 inY);
		~PrimitiveInt2DVector();

	public:
		Int32 getX() const;
		Int32 getY() const;
		void setX(Int32 inX);
		void setY(Int32 inY);

	public:
		inline PrimitiveInt2DVector operator-() const;

		//PrimitiveInt2DVector
		PrimitiveInt2DVector& operator+=(PrimitiveInt2DVector const &inV);
		PrimitiveInt2DVector& operator-=(PrimitiveInt2DVector const& inV);
		PrimitiveInt2DVector& operator*=(PrimitiveInt2DVector const& inV);
		PrimitiveInt2DVector& operator/=(PrimitiveInt2DVector const& inV);

		PrimitiveInt2DVector operator+(PrimitiveInt2DVector const& inV) const;
		PrimitiveInt2DVector operator-(PrimitiveInt2DVector const& inV) const;
		PrimitiveInt2DVector operator*(PrimitiveInt2DVector const& inV) const;
		PrimitiveInt2DVector operator/(PrimitiveInt2DVector const& inV) const;

		//Int
		PrimitiveInt2DVector& operator+=(Int32 const& inV);
		PrimitiveInt2DVector& operator-=(Int32 const& inV);
		PrimitiveInt2DVector& operator*=(Int32 const& inV);
		PrimitiveInt2DVector& operator/=(Int32 const& inV);

		PrimitiveInt2DVector operator+(Int32 const& inV) const;
		PrimitiveInt2DVector operator-(Int32 const& inV) const;
		PrimitiveInt2DVector operator*(Int32 const& inV) const;
		PrimitiveInt2DVector operator/(Int32 const& inV) const;

		//Float?

	public:
		PrimitiveInt2DVector abs()const;

	private:
		Int32 x_ = 0;
		Int32 y_ = 0;
	};
}

namespace DogFW::math
{
	PrimitiveInt2DVector abs(PrimitiveInt2DVector const& inV);
}

