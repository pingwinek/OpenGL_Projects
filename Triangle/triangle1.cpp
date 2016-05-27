#include "triangle1.h"

int Triangle1::drawTriangle()
{
		glBegin(GL_TRIANGLES);

		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(-1.0f, -1.0f, 1.0f);

		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(-0.0f, 1.0f, 1.0f);

		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(1.0f, -1.0f, 1.0f);
		glEnd();

	return 0;
}