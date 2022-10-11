#include "Model.h"
void Model::Render() {
	glPushMatrix();
	glTranslatef(this->getPos().getX(), this->getPos().getY(), this->getPos().getZ());
	glColor3f(color1.getR(), color1.getG(), color1.getB());
	glRotatef(this->getOrientation().getX(), 1, 0, 0);
	glRotatef(this->getOrientation().getY(), 0, 1, 0);
	glRotatef(this->getOrientation().getZ(), 0, 0, 1);
	for (Triangle& t : triangles)
		t.Render();
	glPopMatrix();
}

void Model::paintColor(Color color) {
	for (Triangle& triangle : this->triangles) {
		triangle.setColor1(color);
		triangle.setColor2(color);
		triangle.setColor3(color);
	}
}

void Model::clear() {
	for (Triangle& t : triangles)
		triangles.clear();
}

