#include "Quad.h"

void Quad::drawQuad(){

	GLfloat verticesQuad[] =
	{
		300, 300, 0.0, //top left
		200, 300, 0.0, //top right
		200, 250, 0.0, //bottom right
		300, 250, 0.0, //bottom left
	};

	glVertexPointer(3, GL_FLOAT, 0, verticesQuad);
	glDrawArrays(GL_QUADS, 0, 6);
}