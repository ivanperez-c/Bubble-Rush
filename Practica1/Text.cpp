#include "Text.h"
void Text::Render() {
	glPushMatrix();
	glColor3f(this->getColor().getR(), this->getColor().getG(), this->getColor().getB());
	glTranslatef(this->getPos().getX(), this->getPos().getY(), this->getPos().getZ());
	glRasterPos3d(0, 0, 0);
	for (char c : text)
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, c);
	glPopMatrix();

}