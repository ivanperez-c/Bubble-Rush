#include "Escenario.h"

void Escenario::CrearArcoMeta(double dist, Scene* mainScene) {
	Cylinder* cilindro5 = new Cylinder();
	cilindro5->setPos(Vector3D(-5, 7.6, dist));
	cilindro5->setColor(Color(1, 1, 0));
	cilindro5->setOrientationSpeed(Vector3D(0, 0, 0));
	cilindro5->setOrientation(Vector3D(90, 0, 0));
	cilindro5->setAltura(35);
	cilindro5->setRadioBase(0.5);
	cilindro5->setRadioSuperior(0.5);
	mainScene->addGameObjects(cilindro5);

	Cylinder* cilindro6 = new Cylinder();
	cilindro6->setPos(Vector3D(15, 7.6, dist));
	cilindro6->setColor(Color(1, 1, 0));
	cilindro6->setOrientationSpeed(Vector3D(0, 0, 0));
	cilindro6->setOrientation(Vector3D(90, 0, 0));
	cilindro6->setAltura(35);
	cilindro6->setRadioBase(0.5);
	cilindro6->setRadioSuperior(0.5);
	mainScene->addGameObjects(cilindro6);

	Cuboid* tela3 = new Cuboid();
	tela3->setPos(Vector3D(5, 6, dist));
	tela3->setColor(Color(1, 0, 1));
	tela3->setLongitud(3);
	tela3->setAnchura(20);
	tela3->setAltura(0.1);
	tela3->setOrientationSpeed(Vector3D(0, 0, 0));
	tela3->setOrientation(Vector3D(90, 90, 0));
	mainScene->addGameObjects(tela3);
}

void Escenario::ColorSegunVida(float vida)
{
	if (vida > 100) {
		this->setColor(Color(0, 3, 0)); //verde inicial
	}
	if (vida <= 100 && vida > 80) {
		this->setColor(Color(3.31, 3.24, 0)); //verde amarillento
	}
	if (vida <= 80 && vida > 60) {
		this->setColor(Color(255, 213, 0)); //amarillo
	}
	if (vida <= 60 && vida > 40) {
		this->setColor(Color(3.82, 2.92, 0)); //naranja
	}
	if (vida <= 40 && vida > 20) {
		this->setColor(Color(248, 0, 0)); // rojo brillante 
	}
	if (vida <= 20 && vida > 1) {
		this->setColor(Color(2, 0, 0)); // rojo oscuro
	}
	if (vida == 0) {
		this->setColor(Color(0, 0, 0)); // negro
	}

}