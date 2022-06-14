#include "Triangle.h"
void Triangle::Render() {
	glBegin(GL_TRIANGLES);
	glColor3f(color1.getR(), color1.getG(), color1.getB());
	glNormal3f(normal1.getX(), normal1.getY(), normal1.getZ());
	glVertex3f(vertex1.getX(), vertex1.getY(), vertex1.getZ());

	glColor3f(color2.getR(), color2.getG(), color2.getB());
	glNormal3f(normal2.getX(), normal2.getY(), normal2.getZ());
	glVertex3f(vertex2.getX(), vertex2.getY(), vertex2.getZ());

	glColor3f(color3.getR(), color3.getG(), color3.getB());
	glNormal3f(normal3.getX(), normal3.getY(), normal3.getZ());
	glVertex3f(vertex3.getX(), vertex3.getY(), vertex3.getZ());
	glEnd();
}