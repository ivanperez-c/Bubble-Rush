#include "Scene.h"
void Scene::Render() {
	this->cj->Render();
	this->cj->Update(0.07);
	for (Solid* ps : gameObjects)
		ps->Render();
}

void Scene::Update(const double& dt) {
	for (Solid* ps : gameObjects)
		ps->Update(dt);

	checkBoundary();
}

void Scene::checkBoundary() {
	for (Solid* ps : gameObjects) {
		Vector3D pos = ps->getPos();

		if (pos.getX() > boundary.getX()) {
			ps->setSpeed(Vector3D((ps->getSpeed().getX() * -1), (ps->getSpeed().getY()), (ps->getSpeed().getZ())));
		}

		if (pos.getX() < 0) {
			ps->setSpeed(Vector3D((ps->getSpeed().getX() * -1), (ps->getSpeed().getY()), (ps->getSpeed().getZ())));
		}

		if (pos.getY() > boundary.getY()) {
			ps->setSpeed(Vector3D((ps->getSpeed().getX()), (ps->getSpeed().getY()* -1), (ps->getSpeed().getZ())));
		}

		if (pos.getY() < 0) {
			ps->setSpeed(Vector3D((ps->getSpeed().getX()), (ps->getSpeed().getY() * -1), (ps->getSpeed().getZ())));
		}

		/*if (pos.getZ() > boundary.getZ()) {
			ps->setSpeed(Vector3D((ps->getSpeed().getX()), (ps->getSpeed().getY()), (ps->getSpeed().getZ()* -1)));
		}

		if (pos.getZ() < 0) {
			ps->setSpeed(Vector3D((ps->getSpeed().getX()), (ps->getSpeed().getY()), (ps->getSpeed().getZ() * -1)));
		}*/
	}
}