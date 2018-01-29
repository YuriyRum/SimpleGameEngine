#include "Mat4.h"

namespace core
{
	namespace math
	{
		Mat4::Mat4()
		{
			for (int i = 0; i < NUMBER_OF_ELEMENTS; i++)
				elements[i] = 0.0f;
		}

		Mat4::Mat4(float diagonal)
		{
			for (int i = 0; i < NUMBER_OF_ELEMENTS; i++)
				elements[i] = 0.0f;

			elements[0] = diagonal;
			elements[5] = diagonal;
			elements[10] = diagonal;
			elements[15] = diagonal;
			/*
			int diagonalIndex = 0;
			int diagonalIndexStep = NUMBER_OF_ELEMENTS / DIMENSION + 1;
			for (int i = 0; i < NUMBER_OF_ELEMENTS; i++)
			{
				if (diagonalIndex == i)
				{
					elements[i] = diagonal;
					i += diagonalIndexStep;
				}
				else
				{
					elements[i] = 0.0f;
				}				
			}
			*/
				
		}

		Mat4 Mat4::Identity() 
		{
			return Mat4(1.0f);
		}

		Mat4& Mat4::Multiply(const Mat4& other) 
		{
			/// for multiplication we mean column-ordering						
			float tempElements[NUMBER_OF_ELEMENTS];

			for (int y = 0; y < DIMENSION; y++)
			{
				for (int x = 0; x < DIMENSION; x++)
				{
					float sum = 0.0f;
					for (int e = 0; e < DIMENSION; e++)
					{
						sum += elements[x + e * DIMENSION] * other.elements[e + y *  DIMENSION];
					}
					tempElements[x + y * DIMENSION] = sum;
				}
			}
			for (int i = 0; i < NUMBER_OF_ELEMENTS; i++)
			{
				elements[i] = tempElements[i];
			}
			return *this;
		}

		Mat4& Mat4::operator*=(const Mat4& right) 
		{
			Multiply(right);
			return *this;
		};

		Mat4 Mat4::Orthographic(float left, float right, float bottom, float top, float near, float far)
		{
			Mat4 result(1.0f);
			result.elements[0 + 0 * 4] = 2.0f / (right - left);
			result.elements[1 + 1 * 4] = 2.0f / (top - bottom);
			result.elements[2 + 2 * 4] = 2.0f / (near - far);

			result.elements[0 + 3 * 4] = (left + right) / (left - right);
			result.elements[1 + 3 * 4] = (bottom + top) / (bottom - top);
			result.elements[2 + 3 * 4] = (far + near) / (far - near);

			return result;
		};

		Mat4 Mat4::Persepctive(float fieldOfView, float aspectRation, float near, float far) 
		{
			Mat4 result(1.0f);
			
			float q = 1.0f / tan(ToRadians(0.5f * fieldOfView));
			float a = q / aspectRation;
			float b = (near + far) / (near - far);
			float c = (2.0f * near * far) / (near - far);

			result.elements[0 + 0 * 4] = a;
			result.elements[1 + 1 * 4] = q;
			result.elements[2 + 2 * 4] = b;
			result.elements[3 + 2 * 4] = -1.f;
			result.elements[2 + 3 * 4] = c;

			return result;
		};

		Mat4 Mat4::Translation(const Vector3& vector)
		{
			Mat4 result(1.0f);

			result.elements[0 + 3 * 4] = vector.GetxPos();
			result.elements[1 + 3 * 4] = vector.GetyPos();
			result.elements[2 + 3 * 4] = vector.GetzPos();
			return result;
		};

		Mat4 Mat4::Rotation(float angle, const Vector3& axis)
		{
			Mat4 result(1.0f);

			float r = ToRadians(angle);
			float c = cos(r);
			float s = sin(r);

			float omc = 1.0f - c;

			float x = axis.GetxPos();
			float y = axis.GetyPos();
			float z = axis.GetzPos();

			result.elements[0 + 0 * 4] = x * omc + c;
			result.elements[1 + 0 * 4] = y * x * omc + z * s;
			result.elements[2 + 0 * 4] = x * z * omc - y * s;;

			result.elements[0 + 1 * 4] = x * y * omc - z * s;
			result.elements[1 + 1 * 4] = y * omc + c;
			result.elements[2 + 1 * 4] = y * z * omc + x * s;

			result.elements[0 + 2 * 4] = x * y * omc + y * s;
			result.elements[1 + 2 * 4] = y * z * omc - x * s;
			result.elements[2 + 2 * 4] = z * omc + c;

			return result;
		};

		Mat4 Mat4::Scale(const Vector3& vector)
		{
			Mat4 result(1.0f);

			result.elements[0 + 0 * 4] = vector.GetxPos();
			result.elements[1 + 1 * 4] = vector.GetyPos();
			result.elements[2 + 2 * 4] = vector.GetzPos();
			return result;
		};

		Mat4 operator*(Mat4 left, const Mat4& right)
		{
			return left.Multiply(right);
		};

		float ToRadians(float degrees)
		{
			return degrees * (M_PI / 180.0f);
		}

	}
}
