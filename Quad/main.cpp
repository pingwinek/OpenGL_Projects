#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
#include <iostream>
#include "quadStrip.h"
#include "Quad.h"

using namespace std;

#define SCREEN_WIDTH 640
#define SCREEN_HIGH 480

int check();
void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods);
void characterCallback(GLFWwindow *window, unsigned int keyCode);
void characterModCallback(GLFWwindow *window, unsigned int keyCode, int modifierKey);

int main(){

	while (true)
	{
		int quad = check();

		GLFWwindow *window;

		//initialize the GLFW
		if (!glfwInit()){
			return -1;
		}

		//create a windowed mode and its OpenGL Context
		window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HIGH, "OpenGL Projects", NULL, NULL);

		//glfwSetCharCallback(window, characterCallback);
		//glfwSetKeyCallback(window, keyCallback);
		//glfwSetInputMode(window, GLFW_STICKY_KEYS, 1);

		glfwSetCharCallback(window, characterCallback);
		//glfwSetCharModsCallback(window, characterModCallback);
		
		int width, height;
		glfwGetFramebufferSize(window, &width, &height);

		if (!window){
			glfwTerminate();
			return -1;
		}

		//make the window's context current
		glfwMakeContextCurrent(window);

		glViewport((GLfloat)0.0, (GLfloat)0.0, width, height);
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

			switch (quad)
			{
			case 1:
				Quad q1;
				q1.drawQuad();
				break;
			case 2:
				QuadStrip q2;
				q2.drawQuad();
				break;
			}

			glDisableClientState(GL_VERTEX_ARRAY);

			//sweap front and back buffers
			glfwSwapBuffers(window);

			//pool for and process events
			glfwPollEvents();
		}
		glfwTerminate();
	}
}

int check()
{
	string s;
	cout << "Please enter value (1 or 2): ";
start:
	cin >> s;
	if (s.length() == 1)
	{
		switch (s[0])
		{
		case '1':
		case '2':
			return s[0] - '0';
			break;
		default:
			cout << "Not correct value. Please enter correct value (1 or 2): ";
			goto start;
		}
	}
	else{

		cout << "Not correct value. Please enter correct value (1 or 2): ";
		goto start;
	}

	return 0;
}

void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods){

	cout << key << endl;

	if (key == GLFW_KEY_SPACE){
		switch (action)
		{
		case GLFW_PRESS:
			cout << "Space is pressed" << endl;
			break;
		case GLFW_REPEAT:
			cout << "Space is repeat" << endl;
			break;
		case GLFW_RELEASE:
			cout << "Space is release" << endl;
			break;
		default:
			break;
		}
	}
}

void characterCallback(GLFWwindow *window, unsigned int keyCode){

	std::cout << keyCode << std::endl;
}

void characterModCallback(GLFWwindow *window, unsigned int keyCode, int modifierKey){

	std::cout << keyCode << " : " << modifierKey << std::endl;

	if (modifierKey == 1)
	{
		std::cout << "Shift key pressed aswell" << std::endl;
	}
}