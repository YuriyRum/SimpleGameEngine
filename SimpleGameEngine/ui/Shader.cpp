#include "Shader.h"
#include <iostream>
#include <vector>


namespace core
{
	namespace graphics
	{
		Shader::Shader(const char* vertPath, const char* fragPath) :
			VertPath(vertPath), FragPath(fragPath)
		{
			shaderId = Load();
		}

		Shader::~Shader()
		{
			glDeleteProgram(shaderId);
		}

		void Shader::SetUniform1f(const GLchar* name, float value)
		{
			glUniform1f(GetUniformLocation(name), value);
		};

		void Shader::SetUniform2f(const GLchar* name, const math::Vector2& vector)
		{
			glUniform2f(GetUniformLocation(name), vector.GetxPos(), vector.GetyPos());
		};

		void Shader::SetUniform3f(const GLchar* name, const math::Vector3& vector)
		{
			glUniform3f(GetUniformLocation(name), vector.GetxPos(), vector.GetyPos(), vector.GetzPos());
		};

		void Shader::SetUniform4f(const GLchar* name, const math::Vector4& vector)
		{
			glUniform4f(GetUniformLocation(name), vector.GetxPos(), vector.GetyPos(), vector.GetzPos(), vector.GetwPos());
		};
		void Shader::SetUniform1i(const GLchar* name, int value)
		{
			glUniform1i(GetUniformLocation(name), value);
		};
		void Shader::SetUniformMat4(const GLchar* name, const math::Mat4 matrix)
		{
			glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, matrix.elements);
		};

		void Shader::Enable() const
		{
			glUseProgram(shaderId);
		}

		void Shader::Disable() const
		{
			glUseProgram(0);
		}

		GLuint Shader::GetId() const
		{
			return shaderId;
		}

		GLuint Shader::Load()
		{
			GLuint program = glCreateProgram();
			GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
			GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);			

			std::string vertexShaderSource = utils::ReadFile(VertPath);
			std::string fragmentShaderSource = utils::ReadFile(FragPath);
			const char* vertexShaderSourceChar = vertexShaderSource.c_str();
			const char* fragmentShaderSourceChar = fragmentShaderSource.c_str();


			glShaderSource(vertexShader, 1, &vertexShaderSourceChar, NULL);
			glCompileShader(vertexShader);

			GLint status;
			glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &status);
			if (status == GL_FALSE)
			{
				GLint length;
				glGetShaderiv(vertexShader, GL_INFO_LOG_LENGTH, &length);
				std::vector<char> errorLog(length);
				glGetShaderInfoLog(vertexShader, length, &length, &errorLog[0]);

				std::cout << "Vertex shader error: " << &errorLog[0] << std::endl;
				glDeleteShader(vertexShader);
				return 0;
			}

			glShaderSource(fragmentShader, 1, &fragmentShaderSourceChar, NULL);
			glCompileShader(fragmentShader);

			glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &status);
			if (status == GL_FALSE)
			{
				GLint length;
				glGetShaderiv(fragmentShader, GL_INFO_LOG_LENGTH, &length);
				std::vector<char> errorLog(length);
				glGetShaderInfoLog(fragmentShader, length, &length, &errorLog[0]);

				std::cout << "Fragment shader error: " << &errorLog[0] << std::endl;
				glDeleteShader(fragmentShader);
				return 0;
			}

			glAttachShader(program, vertexShader);
			glAttachShader(program, fragmentShader);

			glLinkProgram(program);
			glValidateProgram(program);

			glDeleteShader(vertexShader);
			glDeleteShader(fragmentShader);

			return program;
		}

		GLint Shader::GetUniformLocation(const GLchar* name)
		{
			GLint result = uniformLocationCach[name];			
			if (result == 0)
			{
				result = uniformLocationCach[name] = glGetUniformLocation(shaderId, name);

			}
			return result;
		}

	}
}