#include "hollowCircle.h"
#include <string>
#include <iostream>

#define M_PI 3.14159265359

void HollowCircle::drawCircle(GLfloat x, GLfloat y, GLfloat z, GLfloat radius, GLint numberOfSides)
{
	int numberOfVertices = numberOfSides + 1;

	GLfloat twicePi = 2.0f * M_PI;

	GLfloat *circleVerticesX = new GLfloat[numberOfVertices];
	GLfloat *circleVerticesY = new GLfloat[numberOfVertices];
	GLfloat *circleVerticesZ = new GLfloat[numberOfVertices];

	/*circleVerticesX[0] = x;
	circleVerticesY[0] = y;
	circleVerticesZ[0] = z;*/

	for (int i = 0; i < numberOfVertices; i++)
	{
		circleVerticesX[i] = x + (radius * cos(i *  twicePi / numberOfSides));
		circleVerticesY[i] = y + (radius * sin(i * twicePi / numberOfSides));
		circleVerticesZ[i] = z;
	}

	GLfloat *allCircleVertices = new GLfloat[numberOfVertices * 3];

	for (int i = 0; i < numberOfVertices; i++)
	{
		allCircleVertices[i * 3] = circleVerticesX[i];
		allCircleVertices[(i * 3) + 1] = circleVerticesY[i];
		allCircleVertices[(i * 3) + 2] = circleVerticesZ[i];
	}

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, allCircleVertices);
	glDrawArrays(GL_LINE_STRIP, 0, numberOfVertices);
	glColor3f(0, 0, 1);
	//glDrawArrays(GL_POLYGON, 0, numberOfVertices);
	glDisableClientState(GL_VERTEX_ARRAY);
}