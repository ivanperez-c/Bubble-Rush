#pragma once
#include "Solid.h"
class Cube:public Solid
{
private:
	
public:
	Cube(Vector3D p = Vector3D(-1.0, 0, -2.0), Color c = Color(0.0, 0.0, 1.0), float s = 2.5, Vector3D o = Vector3D(0, 0, -45)) : Solid (p,c,s,o) {}

	void Render();
};

