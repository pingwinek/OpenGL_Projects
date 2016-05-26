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

	GLfloat pointVertex[] =
	{
		SCREEN_WIDTH * 0.3, SCREEN_HIGH / 2
	};

	GLfloat pointVertex2[] =
	{
		SCREEN_WIDTH * 0.75, SCREEN_HIGH / 2
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

		glEnable(GL_POINT_SMOOTH);
		glPointSize(200);
		glVertexPointer(2, GL_FLOAT, 0, pointVertex);
		glDrawArrays(GL_POINTS, 0, 1);
		glDisable(GL_POINT_SMOOTH);

		glPointSize(100);
		glVertexPointer(2, GL_FLOAT, 0, pointVertex2);
		glDrawArrays(GL_POINTS, 0, 1);

		glDisableClientState(GL_VERTEX_ARRAY);

		//sweap front and back buffers
		glfwSwapBuffers(window);

		//pool for and process events
		glfwPollEvents();
	}
	glfwTerminate();
}