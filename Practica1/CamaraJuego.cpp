#include "CamaraJuego.h"
void CamaraJuego::Update(double time) {
	this->setPos(Vector3D(this->getPos() + this->getVel() * time));
}