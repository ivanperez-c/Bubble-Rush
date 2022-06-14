#include "Jugador.h"


void Jugador::CambiarDireccion(float p)
{
	this->setSpeed(Vector3D(p, 0, this->getSpeed().getZ()));
}

void Jugador::Update(double dt)
{
	this->setPuntuacion(this->getPuntuacion() + 1);
	this->setPos(Vector3D(this->getPos() + this->getSpeed() * dt));
}