#pragma once

#include <iostream>

namespace core
{
	namespace math
	{
		class Vector3
		{
		public:
			Vector3();
			Vector3(const float& x, const float& y, const float& z);

			Vector3& Add(const Vector3& vector);
			Vector3& Multiply(const Vector3& vector);
			Vector3& Subtruct(const Vector3& vector);
			Vector3& Divide(const Vector3& vector);

			float GetxPos() const;
			float GetyPos() const;
			float GetzPos() const;

			friend std::ostream& operator<<(std::ostream& os, const Vector3& vector)
			{
				os << "X - " << vector.GetxPos() << " Y - " << vector.GetyPos() <<  " Z - " << vector.GetxPos() << std::endl;
				return os;
			}

			/// overload unary operators
			Vector3& operator+=(const Vector3&);
			Vector3& operator-=(const Vector3&);
			Vector3& operator*=(const Vector3&);
			Vector3& operator/=(const Vector3&);
			bool operator==(const Vector3&);
			bool operator!=(const Vector3&);

			/// overload binary operators
			friend Vector3 operator+(Vector3 left, const Vector3& right);
			friend Vector3 operator-(Vector3 left, const Vector3& right);
			friend Vector3 operator*(Vector3 left, const Vector3& right);
			friend Vector3 operator/(Vector3 left, const Vector3& right);

		private:
			float xPos;
			float yPos;
			float zPos;
		};		
	}
}

