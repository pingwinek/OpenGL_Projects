#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include "triangle1.h"
#include "triangle2.h"
#include "triangle3.h"

using namespace std;

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

int main(){

	string triangle;

	cout << "Please enter value (1, 2 or 3): ";
	cin >> triangle;

	for (;;){
		if (triangle == "1" || triangle == "2" || triangle == "3")
			break;
		else{
			cout << "Not correct value. Please enter correct value (1, 2 or 3): ";
			cin >> triangle;
		}
	}

	GLFWwindow *window;

	//initialize the GLFW
	if (!glfwInit()){
		return -1;
	}

	//create a windowed mode and its OpenGL Context
	window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "OpenGL Projects", NULL, NULL);

	if (!window){
		glfwTerminate();
		return -1;
	}

	//make the window's context current
	glfwMakeContextCurrent(window);

	glViewport(0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT); // specifies the part of the window to which OpenGL will draw (in pixels), convert from normalised to pixels
	glMatrixMode(GL_PROJECTION); // projection matrix defines the properties of the camera that views the objects in the world coordinate frame. Here you typically set the zoom factor, aspect ratio and the near and far clipping planes
	glLoadIdentity(); // replace the current matrix with the identity matrix and starts us a fresh because matrix transforms such as glOrpho and glRotate cumulate, basically puts us at (0, 0, 0)
	glOrtho(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT, 0, 1); // essentially set coordinate system
	glMatrixMode(GL_MODELVIEW); // (default matrix mode) modelview matrix defines how your objects are transformed (meaning translation, rotation and scaling) in your world
	glLoadIdentity(); // same as above comment

	//loop until the user closes the window
	while (!glfwWindowShouldClose(window)){
		
		if (triangle == "1"){

			Triangle1 t1;
			t1.drawTriangle();
		}
		if (triangle == "2"){

			Triangle2 t2;
			t2.drawTriangle();
		}
		if (triangle == "3"){

			Triangle3 t3;
			t3.drawTriangle();
		}

		//sweap front and back buffers
		glfwSwapBuffers(window);

		//pool for and process events
		glfwPollEvents();
	}
	glfwTerminate();
}