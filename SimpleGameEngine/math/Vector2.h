#pragma once

#include <iostream>

namespace core 
{
	namespace math
	{
		class Vector2 
		{
		public:
			Vector2();
			Vector2(const float& x, const float& y);

			Vector2& Add(const Vector2& vector);
			Vector2& Multiply(const Vector2& vector);
			Vector2& Subtruct(const Vector2& vector);
			Vector2& Divide(const Vector2& vector);

			float GetxPos() const;
			float GetyPos() const;

			friend std::ostream& operator<<(std::ostream& os, const Vector2& vector)
			{
				os << "X - " << vector.GetxPos() << " Y - " << vector.GetyPos() << std::endl;
				return os;
			}

			/// overload unary operators
			Vector2& operator+=(const Vector2&);
			Vector2& operator-=(const Vector2&);
			Vector2& operator*=(const Vector2&);
			Vector2& operator/=(const Vector2&);
			bool operator==(const Vector2&);
			bool operator!=(const Vector2&);

			/// overload binary operators
			friend Vector2 operator+(Vector2 left, const Vector2& right);
			friend Vector2 operator-(Vector2 left, const Vector2& right);
			friend Vector2 operator*(Vector2 left, const Vector2& right);
			friend Vector2 operator/(Vector2 left, const Vector2& right);

		private:
			float xPos;
			float yPos;
		};
	}
}
