#include "Vector3.h"

namespace core
{
	namespace math
	{
		Vector3::Vector3()
		{
			xPos = 0.0f;
			yPos = 0.0f;
			zPos = 0.0f;
		}

		Vector3::Vector3(const float& x, const float& y, const float& z)
		{
			xPos = x;
			yPos = y;
			zPos = z;
		}
		// define getters
		float Vector3::GetxPos() const { return xPos; }
		float Vector3::GetyPos() const { return yPos; }
		float Vector3::GetzPos() const { return zPos; }

		Vector3& Vector3::Add(const Vector3& otherVector)
		{
			xPos += otherVector.GetxPos();
			yPos += otherVector.GetyPos();
			zPos += otherVector.GetzPos();
			return *this;
		}

		Vector3& Vector3::Multiply(const Vector3& otherVector)
		{
			xPos *= otherVector.GetxPos();
			yPos *= otherVector.GetyPos();
			zPos *= otherVector.GetzPos();
			return *this;
		}

		Vector3& Vector3::Subtruct(const Vector3& otherVector)
		{
			xPos -= otherVector.GetxPos();
			yPos -= otherVector.GetyPos();
			zPos -= otherVector.GetzPos();
			return *this;
		}

		Vector3& Vector3::Divide(const Vector3& otherVector)
		{
			xPos /= otherVector.GetxPos();
			yPos /= otherVector.GetyPos();
			zPos /= otherVector.GetzPos();
			return *this;
		}

		Vector3& Vector3::operator+=(const Vector3& right) { return this->Add(right); }
		Vector3& Vector3::operator-=(const Vector3& right) { return this->Subtruct(right); }
		Vector3& Vector3::operator*=(const Vector3& right) { return this->Multiply(right); }
		Vector3& Vector3::operator/=(const Vector3& right) { return this->Divide(right); }
		bool Vector3::operator==(const Vector3& right) { return this->GetxPos() == right.GetxPos() && this->GetyPos() == right.GetyPos() && this->GetzPos() == right.GetzPos(); }
		bool Vector3::operator!=(const Vector3& right) { return this->GetxPos() != right.GetxPos() || this->GetyPos() != right.GetyPos() || this->GetzPos() != right.GetzPos(); }

		Vector3 operator+(Vector3 left, const Vector3& right) { return left.Add(right); }
		Vector3 operator-(Vector3 left, const Vector3& right) { return left.Subtruct(right); }
		Vector3 operator*(Vector3 left, const Vector3& right) { return left.Multiply(right); }
		Vector3 operator/(Vector3 left, const Vector3& right) { return left.Divide(right); }

	}
}
