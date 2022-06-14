#include "Obstaculo3.h"

Obstaculo3* Obstaculo3::Disparar(Scene* mainScene) {
	// Se crean nuevos cubos (obstaculos 2) a modo de disparo y se añaden a la escena
	Obstaculo3* obs = new Obstaculo3();
	mainScene->addGameObjects(obs);
	obs->setPos(Vector3D(getPos().getX(), getPos().getY(), getPos().getZ()));
	obs->setSpeed(Vector3D(0, 0, 5));
	obs->SetSize(1);
	obs->setColor(Color(0, 0, 0));
	return obs;
}
