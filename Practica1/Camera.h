#pragma once
#include "Solid.h"
class Camera : public Solid
{
public:
	Camera(Vector3D p = Vector3D(0, 0, 0)) :Solid() {setPos(p);}
	void Render();
};

