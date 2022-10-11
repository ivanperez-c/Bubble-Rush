#pragma once
#include "Obstaculos.h"
#include "scene.h"

class Obstaculo3 : public Obstaculos
{
	int velY = 5;
	int velX = 3;

public:
	Obstaculo3(Color col = Color(10, 10, 10)) : Obstaculos() { // Constructor
		this->setColor(col);
		this->setPos(Vector3D(3, -5, 3));
		this->setSpeed(Vector3D(velX, velY, 0));
		this->setOrientationSpeed(Vector3D(0, 20, 0));
		this->SetSize(2.5);
	}

	inline double getvelY() { return velY; }
	inline void setvelY(int v) { velY = v; }

	inline double getvelX() { return velX; }
	inline void setvelX(int v) { velX = v; }

	Obstaculo3* Disparar(Scene* mainScene); // Metodo para disparar
};

