#include "Obstaculo2.h"

void Obstaculo2::Update() {
    if (this->getPos().getY() > 7 && this->getSpeed().getY() > 0) {
        this->setSpeed(Vector3D(this->getSpeed().getX(), this->getSpeed().getY() * -3, this->getSpeed().getZ()));
    }

    if (this->getPos().getY() < 1 && this->getSpeed().getY() < 0) {
        this->setSpeed(Vector3D(this->getSpeed().getX(), this->getSpeed().getY() * -0.33, this->getSpeed().getZ()));
    }
}

