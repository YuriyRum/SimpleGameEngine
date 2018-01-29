#include "ui/window.h"
#include "ui/Shader.h"
int main() 
{
	core::graphics::Window window("Test",800,600);		

	GLuint vbo;	

	GLfloat vertices[] =
	{
		4,3,0,
		12,3,0,
		4,6,0,
		4,6,0,
		12,6,0,
		12,3,0
	};	

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0,3,GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);

	core::math::Mat4 ortho = core::math::Mat4::Orthographic(0.0f, 16.0f,0.0f,9.0f,-1.0f,1.0f);

	core::graphics::Shader shader("shaders/basic.vert", "shaders/basic.frag");
	shader.Enable();
	shader.SetUniformMat4("pr_matrix", ortho);
	shader.SetUniformMat4("ml_matrix", core::math::Mat4::Translation(core::math::Vector3(0,0,1)));

	shader.SetUniform2f("light_pos", core::math::Vector2(8.0f, 4.5f));
	shader.SetUniform4f("colour", core::math::Vector4(2.0f, 3.0f, 8.0f, 1.0f));

	while (!window.IsClosed())
	{
		window.Clear();
		
		glDrawArrays(GL_TRIANGLES,0,6);
		window.Update();				
	}
	
	return 0;
}
