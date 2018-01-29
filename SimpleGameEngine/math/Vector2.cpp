#include "Vector2.h"

namespace core
{
	namespace math
	{
		Vector2::Vector2()
		{
			xPos = 0.0f;
			yPos = 0.0f;
		}

		Vector2::Vector2(const float& x, const float& y)
		{
			xPos = x;
			yPos = y;
		}
		// define getters
		float Vector2::GetxPos() const { return xPos; }
		float Vector2::GetyPos() const { return yPos; }

		Vector2& Vector2::Add(const Vector2& otherVector)
		{
			xPos += otherVector.GetxPos();
			yPos += otherVector.GetyPos();
			return *this;
		}

		Vector2& Vector2::Multiply(const Vector2& otherVector)
		{
			xPos *= otherVector.GetxPos();
			yPos *= otherVector.GetyPos();
			return *this;
		}

		Vector2& Vector2::Subtruct(const Vector2& otherVector)
		{
			xPos -= otherVector.GetxPos();
			yPos -= otherVector.GetyPos();
			return *this;
		}

		Vector2& Vector2::Divide(const Vector2& otherVector)
		{
			xPos /= otherVector.GetxPos();
			yPos /= otherVector.GetyPos();
			return *this;
		}		

		Vector2& Vector2::operator+=(const Vector2& right){ return this->Add(right); }
		Vector2& Vector2::operator-=(const Vector2& right) { return this->Subtruct(right); }
		Vector2& Vector2::operator*=(const Vector2& right) { return this->Multiply(right); }
		Vector2& Vector2::operator/=(const Vector2& right) { return this->Divide(right); }
		bool Vector2::operator==(const Vector2& right){ return this->GetxPos() == right.GetxPos() && this->GetyPos() == right.GetyPos(); }
		bool Vector2::operator!=(const Vector2& right) { return this->GetxPos() != right.GetxPos() || this->GetyPos() != right.GetyPos(); }

		Vector2 operator+(Vector2 left, const Vector2& right){ return left.Add(right); }
		Vector2 operator-(Vector2 left, const Vector2& right){ return left.Subtruct(right); }
		Vector2 operator*(Vector2 left, const Vector2& right){ return left.Multiply(right); }
		Vector2 operator/(Vector2 left, const Vector2& right){ return left.Divide(right); }

	}
}
