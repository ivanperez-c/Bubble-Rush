#pragma once
#include <vector>
#include "Triangle.h"
using namespace std;

class Model : public Solid {
	Color color1, color2, color3;
	vector <Triangle> triangles;
public:
	void addTriangle(Triangle t) { triangles.push_back(t); }
	void paintColor(Color color);
	void clear();

	void Render();
};

