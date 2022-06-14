#include "Obstaculo1.h"
void Obstaculo1::Update() {
	// Obstaculo 1 crece
	if (tamaño == true) {
		this->SetSize(GetSize() + 0.01);
		if (this->GetSize() > 3) {
			tamaño = false;
		}
	}

	// Obstaculo 1 decrece
	if (tamaño == false) {
		this->SetSize(GetSize() - 0.01);
		if (this->GetSize() < 0.5) {
			tamaño = true;
		}
	}
}

