#include "quadStrip.h"

void QuadStrip::drawQuad(){

	GLfloat verticesQuad[] =
	{
		200, 300, 0.0, //top right
		300, 300, 0.0, //top left
		200, 250, 0.0, //bottom right
		300, 250, 0.0, //bottom left

		320, 150, 0,
		350, 200, 0,
		400, 50, 0,
		450, 120, 0
	};

	glVertexPointer(3, GL_FLOAT, 0, verticesQuad);
	glDrawArrays(GL_QUAD_STRIP, 0, 8);
}