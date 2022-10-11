#pragma once
#include "cuboid.h"
#include "cylinder.h"
#include "scene.h"

class Escenario : public Cuboid
{
public:
	Escenario(Color col = Color(0, 3, 0), float largo = 3000, float ancho = 20) : Cuboid() { 
		this->setColor(col);
		this->setPos(Vector3D(5, -1, -20));
		this->setSpeed(Vector3D(0, 0, 0));
		this->setOrientationSpeed(Vector3D(0, 0, 0));
		this->setOrientation(Vector3D(0, 0, 0));
		this->setAltura(1);
		this->setAnchura(largo);
		this->setLongitud(ancho);
	}

	void CrearArcoMeta(double dist, Scene* mainScene); 
	void ColorSegunVida(float vida);
};