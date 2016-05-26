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

	//loop until the user closes the window
	while (!glfwWindowShouldClose(window)){
		glClear(GL_COLOR_BUFFER_BIT);

		//render the OpenGL here
		glEnableClientState(GL_VERTEX_ARRAY);

		glDisableClientState(GL_VERTEX_ARRAY);

		//sweap front and back buffers
		glfwSwapBuffers(window);

		//pool for and process events
		glfwPollEvents();
	}
	glfwTerminate();
}