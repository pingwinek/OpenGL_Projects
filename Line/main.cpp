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

	glViewport((GLfloat)0.0, (GLfloat)0.0, SCREEN_WIDTH, SCREEN_HIGH); // specifies the part of the window to which OpenGL will draw (in pixels), convert from normalised to pixels
	glMatrixMode(GL_PROJECTION); // projection matrix defines the properties of the camera that views the objects in the world coordinate frame. Here you typically set the zoom factor, aspect ratio and the near and far clipping planes
	glLoadIdentity(); // replace the current matrix with the identity matrix and starts us a fresh because matrix transforms such as glOrpho and glRotate cumulate, basically puts us at (0, 0, 0)
	glOrtho(0, SCREEN_WIDTH, 0, SCREEN_HIGH, 0, 1); // essentially set coordinate system
	glMatrixMode(GL_MODELVIEW); // (default matrix mode) modelview matrix defines how your objects are transformed (meaning translation, rotation and scaling) in your world
	glLoadIdentity(); // same as above comment

	GLfloat lineVertices[] =
	{
		250, 150, 0,
		50, 250, 0
	};

	GLfloat lineVertices2[] =
	{
		300, 200, 0,
		200, 400, 0
	};

	GLfloat lineVertices3[] =
	{
		200, 100, 0,
		100, 300, 0,
		500, 50, 0,
		320, 100, 0,
		10, 10, 0
	};

	//loop until the user closes the window
	while (!glfwWindowShouldClose(window)){
		glClear(GL_COLOR_BUFFER_BIT);

		//render the OpenGL here
		glEnableClientState(GL_VERTEX_ARRAY);

		glEnable(GL_LINE_SMOOTH); // snooth line
		glEnable(GL_LINE_STIPPLE); // stipple line
		glPushAttrib(GL_LINE_BIT);
		glLineWidth(5); // width line
		glLineStipple(3, 0x00FF);
		glVertexPointer(3, GL_FLOAT, 0, lineVertices);
		glDrawArrays(GL_LINES, 0, 2);
		glPopAttrib();
		glDisable(GL_LINE_STIPPLE);
		glDisable(GL_LINE_SMOOTH);

		glEnable(GL_LINE_SMOOTH); // snooth line
		glEnable(GL_LINE_STIPPLE); // stipple line
		glPushAttrib(GL_LINE_BIT);
		glVertexPointer(3, GL_FLOAT, 0, lineVertices2);
		glDrawArrays(GL_LINES, 0, 2);
		glPopAttrib();
		glDisable(GL_LINE_STIPPLE);
		glDisable(GL_LINE_SMOOTH);

		glVertexPointer(3, GL_FLOAT, 0, lineVertices3);
		glDrawArrays(GL_LINE_LOOP, 0, 5); //if use "GL_LINE_STRIPE" then line will be stripped

		glDisableClientState(GL_VERTEX_ARRAY);

		//sweap front and back buffers
		glfwSwapBuffers(window);

		//pool for and process events
		glfwPollEvents();
	}
	glfwTerminate();
}