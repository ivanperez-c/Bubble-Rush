#pragma once
#include"Solid.h"
class Cuboid:public Solid
{
	float longitud;
	float altura;
	float anchura;
public:
	Cuboid(Vector3D p = Vector3D(0, 2, -7.0), Color c = Color(1.0, 0.0, 0.0), float s = 0.2, Vector3D o = Vector3D(0, 90, 45), float lon = 0.5, float al = 0.5, float an=1.0) : Solid(p, c, s, o), longitud(lon), altura(al), anchura(an) {}
	
	inline float getLongitud() const { return this->longitud; }
	inline void setLongitud(const float& lengthToSet) { this->longitud = lengthToSet; }
	inline float getAltura() const { return this->altura; }
	inline void setAltura(const float& heightToSet) { this->altura = heightToSet; }
	inline float getAnchura() const { return this->anchura; }
	inline void setAnchura(const float& widthToSet) { this->anchura = widthToSet; }

	void Render();
};

