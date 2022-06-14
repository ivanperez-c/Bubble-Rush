#pragma once
#include "Sphere.h"

class Jugador : public Sphere
{
	double vida;
	double puntuacion;

public:
	Jugador(Color col = Color(0.5, 0.5, 1), int vida = 100, int puntuacion = 0) :Sphere() { // Constructor
		this->setColor(col);
		this->setPos(Vector3D(5, 1, -15));
		this->setSpeed(Vector3D(0, 0, -2));
		this->setOrientationSpeed(Vector3D(0, 20, 0));
		this->setVida(vida);
		this->SetSize(1);
	}

	inline double getVida() { return vida; }
	inline void setVida(double v) { vida = v; }
	inline double getPuntuacion() { return -this->getPos().getZ(); }
	inline void setPuntuacion(double p) { puntuacion = p; }

	void Update(double dt);
	void CambiarDireccion(float d);

};