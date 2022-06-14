#pragma once
#include "Solid.h"

class Sphere:public Solid
{

public:
	Sphere(Vector3D p = Vector3D(1, 0, -2.0), Color c = Color(1.0, 0.5, 0.0), float s = 0.2, Vector3D o = Vector3D(0, -45, 0)) : Solid(p, c, s, o) {}

	void Render();
};

