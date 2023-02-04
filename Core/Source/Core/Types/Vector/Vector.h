#pragma once

template <typename T>
struct TVector3
{
	// TODO: make check, whether T type is number
public:
	/* Ctors */
	TVector3() : TVector3(0, 0) {}
	TVector3(T InX, T InY, T InZ = 0) : X{ InX }, Y{ InY }, Z{ InZ } {}

public:
	/* Operators */
	TVector3 operator+(const TVector3& OtherVector) const
	{
		return TVector3(X + OtherVector.X, Y + OtherVector.Y, Z + OtherVector.Z);
	}

	TVector3 operator-(const TVector3& OtherVector) const
	{
		return TVector3(X - OtherVector.X, Y - OtherVector.Y, Z - OtherVector.Z);
	}

	TVector3 operator*(double Coef) const
	{
		return TVector3(X * Coef, Y * Coef, Z * Coef);
	}


public:
	union
	{
		struct 
		{
			T X;
			T Y;
			T Z;
		};

		T XYZ[3];
	};
};


template <typename T>
TVector3<T> operator*(double Coef, const TVector3<T>& TVector3)
{
	return TVector3 * Coef;
}