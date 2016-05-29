#include "triangle3.h"

int Triangle3::drawTriangle()
{
	GLfloat verticesTriangle2[] =
	{
		20, 100, 0,
		100, 300, 0,
		500, 50, 0,
		500, 450, 0,
		600, 320, 0
	};

	glClear(GL_COLOR_BUFFER_BIT);
	//render the OpenGL here
	glEnableClientState(GL_VERTEX_ARRAY);

	glVertexPointer(3, GL_FLOAT, 0, verticesTriangle2);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 5);
	/*glDrawArrays(GL_TRIANGLE_FAN, 0, 5);*/ //fan triangle

	glDisableClientState(GL_VERTEX_ARRAY);

	return 0;
}