#pragma once
#include"Solid.h"
class Torus:public Solid
{
	float radioInterno;
	float radioExterno;
	float caras;
	float anillos;
public:
	Torus(Vector3D p = Vector3D(3, 2, -6.0), Color c = Color(1.0, 1.0, 0.0), float s = 0.2, Vector3D o = Vector3D(-45, 30, 0), float rI = 0.1, float rE = 0.5, float ca = 22.0, float an = 22.0) : Solid(p, c, s, o), radioInterno(rI), radioExterno(rE), caras(ca), anillos(an) {}

	inline float getRadioInterno() const { return this->radioInterno; }
	inline void setRadioInterno(const float& radioInternoToSet) { this->radioInterno = radioInternoToSet; }
	inline float getRadioExterno() const { return this->radioExterno; }
	inline void setRadioExterno(const float& radioExternoToSet) { this->radioExterno = radioExternoToSet; }
	inline float getCaras() const { return this->caras; }
	inline void setCaras(const float& carasToSet) { this->caras = carasToSet; }
	inline float getAnillos() const { return this->anillos; }
	inline void setAnillos(const float& anillosToSet) { this->anillos = anillosToSet; }

	void Render();


};

