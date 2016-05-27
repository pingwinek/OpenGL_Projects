#include "triangle2.h"

GLfloat verticesTriangle[] =
{
	0.0, 0.5, 0.0, //middle top corner
	-0.5, -0.5, 0.0, //bottom left corner
	0.5, -0.5, 0.0 //bottom right corner
};

int Triangle2::drawTriangle()
{
	//render the OpenGL here
	glEnableClientState(GL_VERTEX_ARRAY);

	glVertexPointer(3, GL_FLOAT, 0, verticesTriangle);
	glDrawArrays(GL_TRIANGLES, 0, 3);

	glDisableClientState(GL_VERTEX_ARRAY);

	return 0;
}