#pragma once
#ifndef _GLEW 
#define _GLEW 
#include "GL/glew.h"	
#endif 
#include "../utils/FileReaderUtil.h"
#include "../math/Mat4.h"
#include <map>
#include <string>

namespace core
{
	namespace graphics
	{
		class Shader
		{

		public:
			Shader(const char* vertPath, const char* fragPath);
			~Shader();
						
			void SetUniform1f(const GLchar* name, float value);
			void SetUniform2f(const GLchar* name, const math::Vector2& vector);				 
			void SetUniform3f(const GLchar* name, const math::Vector3& vector);
			void SetUniform4f(const GLchar* name, const math::Vector4& vector);
			void SetUniform1i(const GLchar* name, int value);
			void SetUniformMat4(const GLchar* name, const math::Mat4 matrix);

			void Enable() const;
			void Disable() const;
			GLuint GetId() const;

		private:
			const char* VertPath;
			const char* FragPath;

			GLuint shaderId;

			GLuint Load();
			GLint GetUniformLocation(const GLchar* name);

			std::map<std::string, GLint> uniformLocationCach;
		};
	}
}
