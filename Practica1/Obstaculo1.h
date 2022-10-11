#pragma once
#include "Obstaculos.h"
class Obstaculo1 :
    public Obstaculos
{
	int velH = 3;
	bool tamaño = true;
public:
	Obstaculo1(Color col = Color(0, 0, 0)) : Obstaculos() { // Constructor
		this->setColor(col);
		this->setPos(Vector3D(3, 1, 3));
		this->setSpeed(Vector3D(velH, 0, 0));
		this->setOrientationSpeed(Vector3D(0, 20, 0));
		this->SetSize(1.5);
		this->setPuntuacionResta(20);
		this->setVidaResta(0.0001);
	}

	inline double getvelH() { return velH; }
	inline void setvelH(int v) { velH = v; }

	void Update();
	
};

