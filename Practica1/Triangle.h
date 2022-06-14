#pragma once
#include "Solid.h"
class Triangle : public Solid {
	Vector3D vertex1, vertex2, vertex3;
	Vector3D normal1, normal2, normal3;
	Color color1, color2, color3;

public:
	Triangle(Vector3D vertex1, Vector3D vertex2, Vector3D vertex3,
		Color color1 = Color(1, 1, 0),
		Color color2 = Color(1, 1, 0),
		Color color3 = Color(1, 1, 0)) :
		Solid(), vertex1(vertex1), vertex2(vertex2), vertex3(vertex3),
		color1(color1), color2(color2), color3(color3) { }
	
	Vector3D getVertex1() { return vertex1; }
	void setVertex1(Vector3D p) { vertex1 = p; }
	Vector3D getVertex2() { return vertex2; }
	void setVertex2(Vector3D p) { vertex2 = p; }
	Vector3D getVertex3() { return vertex3; }
	void setVertex3(Vector3D p) { vertex3 = p; }
	Vector3D getNormal1() { return normal1; }
	void setNormal1(Vector3D p) { normal1 = p; }
	Vector3D getNormal2() { return normal2; }
	void setNormal2(Vector3D p) { normal2 = p; }
	Vector3D getNormal3() { return normal3; }
	void setNormal3(Vector3D p) { normal3 = p; }
	Color getColor1() { return color1; }
	void setColor1(Color p) { color1 = p; }
	Color getColor2() { return color2; }
	void setColor2(Color p) { color2 = p; }
	Color getColor3() { return color3; }
	void setColor3(Color p) { color3 = p; }

	void Render();
};

