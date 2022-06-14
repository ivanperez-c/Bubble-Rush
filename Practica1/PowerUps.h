#pragma once
#include "Cube.h"
#include "Text.h"
class PowerUps :
    public Cube
{
private:
	float puntuacionSuma;
	int vidaSuma;
	bool colision=true;
public:
	PowerUps() : Cube() { // Constructor
		this->setColor(Color(10, 10, 0));
		this->setPos(Vector3D(3, 1, 3));
		this->setSpeed(Vector3D(0, 0, 0));
		this->setOrientationSpeed(Vector3D(-10, 20, 5));
		this->SetSize(1);
		this->setVidaSuma(1);
		this->setPuntuacionSuma(10);
	}

	float getPuntuacionSuma() const { return this->puntuacionSuma; }
	void setPuntuacionSuma(const float& puntuacionSumaToSet) { this->puntuacionSuma = puntuacionSumaToSet; }
	float getVidaSuma() const { return this->vidaSuma; }
	void setVidaSuma(const float& puntuacionToSet) { this->vidaSuma = puntuacionToSet; }

	Text* mensajePuntuacion(Vector3D posJugador);
	Text* mensajeVida(Vector3D posJugador);
};

