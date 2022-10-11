#pragma once
#include "Camera.h"
class CamaraJuego:public Camera
{
	Vector3D vel = Vector3D(0, 0, 0);

public:
	CamaraJuego(Vector3D p = Vector3D(0, 0, 0)) : Camera() {
		setPos(p);
		setVel(vel);
	}

	void Update(double time);

	inline Vector3D getVel() { return vel; }
	inline void setVel(Vector3D v) { vel = v; }
};
