#include "Solid.h"
void Solid::Render() {
	glPushMatrix();
	glTranslated(getPos().getX(), getPos().getY(), getPos().getZ());
	glColor3d(getColor().getR(), getColor().getG(), getColor().getB());
	glutWireTeapot(this->GetSize());
	
	glPopMatrix();
}

void Solid::Update(const float& time) {
	this->setOrientation(Vector3D(this->getOrientation() + this->getOrientationSpeed() * time));
	this->setPos(Vector3D(this->getPos() + this->getSpeed() * time));

}