#include "window.h"

namespace core
{
	namespace graphics {
		Window::Window(const char* title, int width, int height)
		{
			mTitle = title;
			mWidth = width;
			mHeight = height;

			if (glfwInit())
			{
				if (!InitGLFWWindow())
				{
					glfwTerminate();
					return;
				};
			}
			else
			{				
				std::cout << "Error occured during GLFW InitGLFWWindowializing!" << std::endl;				
				return;
			}

			if (glewInit()!=GLEW_OK)
			{
				glfwTerminate();
				std::cout << "GLEW is not initialized" << std::endl;
				return;
			}

			glClearColor(1.0f, 1.0f, 1.0f, 1.0f);	
			glfwSetWindowUserPointer(mWindow, this);
		}


		Window::~Window()
		{
			glfwTerminate();
		}

		bool Window::InitGLFWWindow()
		{
			mWindow = glfwCreateWindow(mWidth, mHeight, mTitle, NULL, NULL);
			if (mWindow == nullptr)
			{				
				std::cout << "GLFW window is not created!" << std::endl;
				return false;
			}
			glfwMakeContextCurrent(mWindow);
			glfwSetWindowSizeCallback(mWindow, ResizeOnChanges);
			glfwSetKeyCallback(mWindow, KeyCallback);
			glfwSetMouseButtonCallback(mWindow, MouseButtonCallback);
			glfwSetCursorPosCallback(mWindow, CursorPositionCallback);
			return true;
		}

		void Window::Clear() const 
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		void Window::Update() 
		{						
			glfwPollEvents();			
			glfwSwapBuffers(mWindow);			
		}
		
		bool Window::IsClosed() const { return glfwWindowShouldClose(mWindow) == 1; }
		bool Window::IsKeyPressed(int key){ return mKyes[key]; }
		bool Window::IsMouseButtonPressed(int key){ return mMouseButtons[key]; }
		Vector Window::getCursorPosition() const{ return CursorPosition; }

		void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
		{			
			Window* CurrentWindow = static_cast<Window*>(glfwGetWindowUserPointer(window));
			CurrentWindow->mKyes[key] = action != GLFW_RELEASE;
		}

		void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
		{
			Window* CurrentWindow = static_cast<Window*>(glfwGetWindowUserPointer(window));
			CurrentWindow->mMouseButtons[button] = action != GLFW_RELEASE;
		}

		void ResizeOnChanges(GLFWwindow* window, int width, int height)
		{
			glViewport(0, 0, width, height);
		}

		void CursorPositionCallback(GLFWwindow* window, double xpos, double ypos)
		{
			Window* CurrentWindow = static_cast<Window*>(glfwGetWindowUserPointer(window));
			CurrentWindow->CursorPosition.xPos = xpos;
			CurrentWindow->CursorPosition.yPos = ypos;
		}
	}	
}