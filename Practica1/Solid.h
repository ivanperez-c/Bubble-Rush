#pragma once
#include <GL/glut.h>
#include "Vector3d.h"
#include "Color.h"

#include <string>

class Solid
{
private:
	float size;
	Vector3D pos;
	Color col;
	Vector3D orientation;
	Vector3D orientationSpeed;
	Vector3D Speed;

public:
	Solid(Vector3D p = Vector3D(0, 0, -2.0), Color c = Color(0.2, 0.3, 0.4), float s = 0.4, Vector3D o = Vector3D(0, 0, 0), Vector3D oS = Vector3D(0, 0, 0), 
		Vector3D sP = Vector3D(0, 0, 0)) : size(s), pos(p), col(c), orientation(o), orientationSpeed(oS), Speed(Vector3D()) {}

	inline Vector3D getPos() { return pos; }
	inline void setPos(Vector3D p) { pos = p; }

	inline Color getColor() { return col; }
	inline void setColor(Color c) { col = c; }

	inline Vector3D getOrientation() { return orientation; }
	inline void setOrientation(Vector3D o) { orientation = o; }

	inline float GetSize() const { return this->size; }
	inline void SetSize(const float& sizeToSet) { this->size = sizeToSet; }

	inline Vector3D getOrientationSpeed() { return orientationSpeed; }
	inline void setOrientationSpeed(Vector3D oS) { orientationSpeed = oS; }

	Vector3D getSpeed() { return Speed; }
	void setSpeed(Vector3D sP) { Speed = sP; }

	virtual void Render() = 0;
	virtual void Update(const float& time);
};

