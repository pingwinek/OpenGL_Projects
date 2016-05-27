#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include "triangle1.h"
#include "triangle2.h"

using namespace std;

#define SCREEN_WIDTH 640
#define SCREEN_HIGH 480

int main(){

	string triangle;

	cout << "Please enter value (1 or 2): ";
	cin >> triangle;

	for (;;){
		if (triangle == "1" || triangle == "2")
			break;
		else{
			cout << "Not correct value. Please enter correct value (1 or 2): ";
			cin >> triangle;
		}
	}

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
		if (triangle == "1"){

			Triangle1 t1;
			t1.drawTriangle();
		}
		if (triangle == "2"){

			Triangle2 t2;
			t2.drawTriangle();
		}

		//sweap front and back buffers
		glfwSwapBuffers(window);

		//pool for and process events
		glfwPollEvents();
	}
	glfwTerminate();
}