#include "Vector4.h"

namespace core
{
	namespace math
	{
		Vector4::Vector4(const float& x, const float& y, const float& z, const float& w)
		{
			xPos = x;
			yPos = y;
			zPos = z;
			wPos = w;
		}
		// define getters
		float Vector4::GetxPos() const { return xPos; }
		float Vector4::GetyPos() const { return yPos; }
		float Vector4::GetzPos() const { return zPos; }
		float Vector4::GetwPos() const { return wPos; }

		Vector4& Vector4::Add(const Vector4& otherVector)
		{
			xPos += otherVector.GetxPos();
			yPos += otherVector.GetyPos();
			zPos += otherVector.GetzPos();
			wPos += otherVector.GetwPos();
			return *this;
		}

		Vector4& Vector4::Multiply(const Vector4& otherVector)
		{
			xPos *= otherVector.GetxPos();
			yPos *= otherVector.GetyPos();
			zPos *= otherVector.GetzPos();
			wPos *= otherVector.GetwPos();
			return *this;
		}

		Vector4& Vector4::Subtruct(const Vector4& otherVector)
		{
			xPos -= otherVector.GetxPos();
			yPos -= otherVector.GetyPos();
			zPos -= otherVector.GetzPos();
			wPos -= otherVector.GetwPos();
			return *this;
		}

		Vector4& Vector4::Divide(const Vector4& otherVector)
		{
			xPos /= otherVector.GetxPos();
			yPos /= otherVector.GetyPos();
			zPos /= otherVector.GetzPos();
			wPos /= otherVector.GetwPos();
			return *this;
		}

		Vector4& Vector4::operator+=(const Vector4& right) { return this->Add(right); }
		Vector4& Vector4::operator-=(const Vector4& right) { return this->Subtruct(right); }
		Vector4& Vector4::operator*=(const Vector4& right) { return this->Multiply(right); }
		Vector4& Vector4::operator/=(const Vector4& right) { return this->Divide(right); }
		bool Vector4::operator==(const Vector4& right) { 
			return this->GetxPos() == right.GetxPos() && this->GetyPos() == right.GetyPos() && this->GetzPos() == right.GetzPos() && this->GetwPos() == right.GetwPos();
		}
		bool Vector4::operator!=(const Vector4& right) { 
			return this->GetxPos() != right.GetxPos() || this->GetyPos() != right.GetyPos() || this->GetzPos() != right.GetzPos() || this->GetwPos() != right.GetwPos();
		}

		Vector4 operator+(Vector4 left, const Vector4& right) { return left.Add(right); }
		Vector4 operator-(Vector4 left, const Vector4& right) { return left.Subtruct(right); }
		Vector4 operator*(Vector4 left, const Vector4& right) { return left.Multiply(right); }
		Vector4 operator/(Vector4 left, const Vector4& right) { return left.Divide(right); }

	}
}
