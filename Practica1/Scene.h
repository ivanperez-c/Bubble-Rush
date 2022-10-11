#pragma once
#include <vector>
#include "Solid.h"
#include "Camera.h"
#include "CamaraJuego.h"

using namespace std;
class Scene
{
private:
	vector<Solid*> gameObjects;
	Vector3D boundary;
	CamaraJuego* cj;
	void checkBoundary();
public:
	Scene(Vector3D b = Vector3D(10,10,10)) : boundary(b) {
		this->cj = new CamaraJuego(Vector3D(5, 3, 0));
	}
	void addGameObjects(Solid* ps) { gameObjects.push_back(ps); }
	void Render();
	void Update(const double& dt);
};

