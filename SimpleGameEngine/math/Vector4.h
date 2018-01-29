#pragma once

#include <iostream>

namespace core
{
	namespace math
	{
		class Vector4
		{
		public:
			Vector4() = default;
			Vector4(const float& x, const float& y, const float& z, const float& w);

			Vector4& Add(const Vector4& vector);
			Vector4& Multiply(const Vector4& vector);
			Vector4& Subtruct(const Vector4& vector);
			Vector4& Divide(const Vector4& vector);

			float GetxPos() const;
			float GetyPos() const;
			float GetzPos() const;
			float GetwPos() const;

			friend std::ostream& operator<<(std::ostream& os, const Vector4& vector)
			{
				os << "X - " << vector.GetxPos() << " Y - " << vector.GetyPos() << " Z - " << vector.GetxPos() << " W -  " << vector.GetwPos() << std::endl;
				return os;
			}

			/// overload unary operators
			Vector4& operator+=(const Vector4&);
			Vector4& operator-=(const Vector4&);
			Vector4& operator*=(const Vector4&);
			Vector4& operator/=(const Vector4&);
			bool operator==(const Vector4&);
			bool operator!=(const Vector4&);

			/// overload binary operators
			friend Vector4 operator+(Vector4 left, const Vector4& right);
			friend Vector4 operator-(Vector4 left, const Vector4& right);
			friend Vector4 operator*(Vector4 left, const Vector4& right);
			friend Vector4 operator/(Vector4 left, const Vector4& right);

		private:
			float xPos;
			float yPos;
			float zPos;
			float wPos;
		};
	}
}

