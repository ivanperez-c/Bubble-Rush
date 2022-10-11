#pragma once
#include "Cube.h"
#include "Text.h"
class Obstaculos :
    public Cube
{
private: 
	int puntuacionResta;
	float vidaResta;
	bool colision = true;
	Cube* cubo;
public:
	Obstaculos(Color col = Color(0, 10, 0)) : cubo() { // Constructor
		this->setColor(col);
		this->setPos(Vector3D(0, 0, 0));
		this->setSpeed(Vector3D(0, 0, 0));
		this->setOrientationSpeed(Vector3D(0, 0, 0));
		this->setOrientation(Vector3D(0, 0, 0));
		this->SetSize(1.5);
		this->setPuntuacionResta(10);
		this->setVidaResta(0.001);
	}
	
	inline float getPuntuacionResta() const { return this->puntuacionResta; }
	inline void setPuntuacionResta(const float& puntuacionRestaToSet) { this->puntuacionResta = puntuacionRestaToSet; }
	float getVidaResta() const { return this->vidaResta; }
	inline void setVidaResta(const float& puntuacionToSet) { this->vidaResta = puntuacionToSet; }

	Text* mensajePuntuacion(Vector3D posJugador);
	Text* mensajeVida(Vector3D posJugador);
};

