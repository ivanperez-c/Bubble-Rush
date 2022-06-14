#pragma once
#include "Cuboid.h"
#include "Text.h"
#include "Scene.h"
class Interfaz : public Cuboid
{
public:
	Interfaz(Color col = Color(3, 3, 3), float ancho = 1, float alto = 1) : Cuboid() { // Constructor
		this->setColor(col);
		this->setPos(Vector3D(0, 0, 0));
		this->setSpeed(Vector3D(0, 0, 0));
		this->setOrientationSpeed(Vector3D(0, 0, 0));
		this->setOrientation(Vector3D(0, 0, 0));
		this->setAltura(alto);
		this->setAnchura(ancho);
		this->setLongitud(1);
	}

	void TextoVictoria(Scene* winScene);
	void TextoDerrota(Scene* loseScene);
};

