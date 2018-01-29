#pragma once
#ifndef _GLEW 
#define _GLEW 
#include "GL/glew.h"	
#endif 
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include <iostream>
#include <map>
#include "../math/Mat4.h"

namespace core 
{
	namespace graphics
	{
		struct Vector {
			double xPos = 0.0;
			double yPos = 0.0;
		};

		/// Callback functions that will be called during user dialog 
		void ResizeOnChanges(GLFWwindow* window, int width, int height);		

		class Window
		{

		private:
			int mWidth;
			int mHeight;
			const char* mTitle;
			GLFWwindow* mWindow = nullptr;			

			std::map<int, bool> mKyes;			
			std::map<int, bool> mMouseButtons;

			Vector CursorPosition;			
			
		public:
			Window(const char* name, int width, int height);			
			~Window();

			void Update();
			void Clear() const;
			bool IsClosed() const;
			bool IsKeyPressed(int);
			bool IsMouseButtonPressed(int);

			Vector getCursorPosition() const;

			friend void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
			friend void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
			friend void CursorPositionCallback(GLFWwindow* window, double xpos, double ypos);
		private:
			bool InitGLFWWindow();							
		};
	}
}

