#include "Obstaculo1.h"
void Obstaculo1::Update() {
	// Obstaculo 1 crece
	if (tama�o == true) {
		this->SetSize(GetSize() + 0.01);
		if (this->GetSize() > 3) {
			tama�o = false;
		}
	}

	// Obstaculo 1 decrece
	if (tama�o == false) {
		this->SetSize(GetSize() - 0.01);
		if (this->GetSize() < 0.5) {
			tama�o = true;
		}
	}
}

