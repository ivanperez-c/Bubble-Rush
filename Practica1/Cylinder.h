#pragma once
#include "Solid.h"
class Cylinder:public Solid
{
	float radioBase;
	float radioSuperior;
	float altura;
	float slices;
	float stacks;
public:
	Cylinder(Vector3D p = Vector3D(-1.7, 1, -5.0), Color c = Color(0.0, 1.0, 0.0), float s = 0.2, Vector3D o = Vector3D(0, 90, 30), float rB = 0.3, float rS = 0.3, float al = 0.75, float sl=16, float st=16) : Solid(p, c, s, o), radioBase(rB), radioSuperior(rS), altura(al), slices(sl), stacks(st){}

	inline float getRadioBase() const { return this->radioBase; }
	inline void setRadioBase(const float& radioBaseToSet) { this->radioBase = radioBaseToSet; }
	inline float getRadioSuperior() const { return this->radioSuperior; }
	inline void setRadioSuperior(const float& radioSuperiorToSet) { this->radioSuperior = radioSuperiorToSet; }
	inline float getAltura() const { return this->altura; }
	inline void setAltura(const float& heightToSet) { this->altura = heightToSet; }
	inline float getSlices() const { return this->slices; }
	inline void setSlices(const float& slicesToSet) { this->slices = slicesToSet; }
	inline float getStacks() const { return this->stacks; }
	inline void setStacks(const float& stacksToSet) { this->stacks = stacksToSet; }

	void Render();
};

