#pragma once

#include "maths.h"


#define NUMBER_OF_ELEMENTS 16
#define DIMENSION 4

namespace core
{
	namespace math
	{
		float ToRadians(float degrees);

		class Mat4
		{
		public:
			union
			{
				float elements[NUMBER_OF_ELEMENTS];
				Vector4 columns[DIMENSION];
			};			

			Mat4();
			Mat4(float diagonal);

			Mat4& Multiply(const Mat4& other);

			Mat4& operator*=(const Mat4& right);

			friend Mat4 operator*(Mat4 left, const Mat4& right);			

			static Mat4 Identity();
			static Mat4 Orthographic(float left, float right, float bottom, float top, float near, float far);
			static Mat4 Persepctive(float fieldOfView, float aspectRation, float near, float far);
			static Mat4 Translation(const Vector3& vector);
			static Mat4 Rotation(float angle, const Vector3& axis);
			static Mat4 Scale(const Vector3& vector);			
		private:
			
		};
	}
}


