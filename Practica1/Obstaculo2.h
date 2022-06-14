#pragma once
#include "Obstaculos.h"
#include "Scene.h"
class Obstaculo2 :
    public Obstaculos
{
	int velV = 2;

public:
	Obstaculo2(Color col = Color(10, 10, 10)) : Obstaculos() { // Constructor
		this->setColor(col);
		this->setPos(Vector3D(3, 1, 3));
		this->setSpeed(Vector3D(0, velV, 0));
		this->setOrientationSpeed(Vector3D(0, 0, 0));
		this->SetSize(1.5);
		this->setPuntuacionResta(30);
		this->setVidaResta(3);
	}

	inline double getvelV() { return velV; }
	inline void setvelV(int v) { velV = v; }

	void Update();
	
};

