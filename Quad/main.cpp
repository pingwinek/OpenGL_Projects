#include <GL/glew.h>
#include <GLFW/glfw3.h>

using namespace std;

#define SCREEN_WIDTH 640
#define SCREEN_HIGH 480

int main(){

	GLFWwindow *window;

	//initialize the GLFW
	if (!glfwInit()){
		return -1;
	}

	//create a windowed mode and its OpenGL Context
	window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HIGH, "OpenGL Projects", NULL, NULL);

	if (!window){
		glfwTerminate();
		return -1;
	}

	//make the window's context current
	glfwMakeContextCurrent(window);

	GLfloat verticesQuad[] =
	{
		50, 300, 0.0, //top left
		300, 300, 0.0, //top right
		300, 50, 0.0, //bottom right
		50, 50, 0.0 //bottom left
	};

	glViewport((GLfloat)0.0, (GLfloat)0.0, SCREEN_WIDTH, SCREEN_HIGH);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, SCREEN_WIDTH, 0, SCREEN_HIGH, 0, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//loop until the user closes the window
	while (!glfwWindowShouldClose(window)){
		glClear(GL_COLOR_BUFFER_BIT);

		//render the OpenGL here
		glEnableClientState(GL_VERTEX_ARRAY);

		glVertexPointer(3, GL_FLOAT, 0, verticesQuad);
		glDrawArrays(GL_QUADS, 0, 4);

		glDisableClientState(GL_VERTEX_ARRAY);

		//sweap front and back buffers
		glfwSwapBuffers(window);

		//pool for and process events
		glfwPollEvents();
	}
	glfwTerminate();
}