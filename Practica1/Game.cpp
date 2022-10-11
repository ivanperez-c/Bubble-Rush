#include "Game.h"
#include <iostream>

void Game::ProcessKeyPressed(unsigned char key, int px, int py)
{
	switch (key)
	{
	case 'a':
	case 'A':
		jugadores[0]->CambiarDireccion(-2);
		break;
	case 'd':
	case 'D':
		jugadores[0]->CambiarDireccion(2);
		break;
	}
}

void Game::ProcessMouseMovement(int x, int y)
{
	// de momento no hacemos nada...
	std::cout << "Movimiento del mouse: " << x << ", " << y << std::endl;
}

void Game::ProcessMouseClick(int button, int state, int x, int y)
{
	// de momento no hacemos nada...
	std::cout << "Clic: " << button << std::endl;
}

void Game::Init() { 
	// Luz
	Light* light = new Light(Vector3D(1, 0, 0));
	mainScene->addGameObjects(light);

	cam->setPos(Vector3D(0, 3, 0));
	mainScene->addGameObjects(cam);

	// Jugador
	player = new Jugador();
	mainScene->addGameObjects(player);
	this->jugadores.push_back(player);

	// Escenario
	escenario1 = new Escenario();
	escenario1->CrearArcoMeta(-400, mainScene);
	mainScene->addGameObjects(escenario1);
	
	//Crear obstáculos genéricos
	Obstaculos* obsGen1 = new Obstaculos();
	obsGen1->setPos(Vector3D(10, 1, -50));
	mainScene->addGameObjects(obsGen1);
	this->obs.push_back(obsGen1);

	Obstaculos* obsGen2 = new Obstaculos();
	obsGen2->setPos(Vector3D(0, 1, -50));
	mainScene->addGameObjects(obsGen2);
	this->obs.push_back(obsGen2);

	Obstaculos* obsGen3 = new Obstaculos();
	obsGen3->setPos(Vector3D(8, 1, -250));
	mainScene->addGameObjects(obsGen3);
	this->obs.push_back(obsGen3);

	Obstaculos* obsGen4 = new Obstaculos();
	obsGen4->setPos(Vector3D(7, 1, -140));
	mainScene->addGameObjects(obsGen4);
	this->obs.push_back(obsGen4);

	//Obstáculos que se mueven de izquierda a derecha
	cre1 = new Obstaculo1();
	cre1->setPos(Vector3D(10, 1, -75));
	cre1->setvelH(4);
	
	mainScene->addGameObjects(cre1);
	this->obs.push_back(cre1);

	cre2 = new Obstaculo1();
	cre2->setPos(Vector3D(10, 1, -150));
	cre2->setvelH(5);
	mainScene->addGameObjects(cre2);
	this->obs.push_back(cre2);

	cre3 = new Obstaculo1();
	cre3->setPos(Vector3D(6, 1, -225));
	cre3->setvelH(6);
	mainScene->addGameObjects(cre3);
	this->obs.push_back(cre3);

	cre4 = new Obstaculo1();
	cre4->setPos(Vector3D(1, 1, -320));
	cre4->setvelH(7);
	mainScene->addGameObjects(cre4);
	this->obs.push_back(cre4);

	// Obstaculos de tipo 2 
	disp1 = new Obstaculo2();
	disp1->setPos(Vector3D(5, 1, -60));
	disp1->setvelV(5);
	mainScene->addGameObjects(disp1);
	this->obs.push_back(disp1);
	
	disp2 = new Obstaculo2();
	disp2->setPos(Vector3D(3, 1, -160));
	disp2->setvelV(6);
	mainScene->addGameObjects(disp2);
	this->obs.push_back(disp2);
	
	disp3 = new Obstaculo2();
	disp3->setPos(Vector3D(8, 1, -200));
	disp3->setvelV(7);
	mainScene->addGameObjects(disp3);
	this->obs.push_back(disp3);

	disp4 = new Obstaculo2();
	disp4->setPos(Vector3D(6, 1, -360));
	disp4->setvelV(8);
	mainScene->addGameObjects(disp4);
	this->obs.push_back(disp4);

	disp5 = new Obstaculo2();
	disp5->setPos(Vector3D(3, 1, -350));
	disp5->setvelV(9);
	mainScene->addGameObjects(disp5);
	this->obs.push_back(disp5);

	//Obstáculos de tipo 3
	tramp1 = new Obstaculo3();
	tramp1->setPos(Vector3D(7, 1, -55));
	mainScene->addGameObjects(tramp1);
	this->obs.push_back(tramp1);
	this->disparos.push_back(tramp1);

	//Obstáculos de tipo 3
	tramp2 = new Obstaculo3();
	tramp2->setPos(Vector3D(7, 3, -200));
	mainScene->addGameObjects(tramp2);
	this->obs.push_back(tramp2);
	this->disparos.push_back(tramp2);
	

	// Power Ups - te dan vida
	PowerUps* PU1 = new PowerUps();
	PU1->setPos(Vector3D(5, 1, -100));
	mainScene->addGameObjects(PU1);
	this->PUs.push_back(PU1);

	PowerUps* PU2 = new PowerUps();
	PU2->setPos(Vector3D(5, 1, -200));
	mainScene->addGameObjects(PU2);
	this->PUs.push_back(PU2);

	PowerUps* PU3 = new PowerUps();
	PU3->setPos(Vector3D(5, 1, -300));
	mainScene->addGameObjects(PU3);
	this->PUs.push_back(PU3);

	//Escena de juego
	this->scenes.push_back(mainScene);

	//Escenas de victoria y derrota
	
	this->scenes.push_back(winScene);

	Interfaz* interfazVictoria = new Interfaz();
	winScene->addGameObjects(interfazVictoria);
	interfazVictoria->TextoVictoria(winScene);

	
	this->scenes.push_back(loseScene);

	Interfaz* interfazDerrota = new Interfaz();
	loseScene->addGameObjects(interfazDerrota);
	interfazDerrota->TextoDerrota(loseScene);

	this->activeScene = mainScene;
}

void Game::Render() 
{ 
	this->activeScene->Render();
}

void Game::Update() { 
	milliseconds currentTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());

	if ((currentTime.count() - this->initialMilliseconds.count()) - this->lastUpdatedTime > UPDATE_PERIOD)
	{
		this->activeScene->Update(TIME_INCREMENT);
		this->lastUpdatedTime = currentTime.count() - this->initialMilliseconds.count();
	}

	comprobarColisiones();
	Trampa();

	// Deteccion de la victoria
	if (this->jugadores[0]->getPos().getZ() < -400 && win == true) {
		Victoria();
	}

	// Deteccion de la derrota
	if (this->jugadores[0]->getVida() <= 0 && lose == true) {
		Derrota();
	}

	cam->setPos(Vector3D(0, 0, this->jugadores[0]->getPos().getZ() + 20));

	cre1->Update();
	cre2->Update();
	cre3->Update();
	cre4->Update();

	disp1->Update();
	disp2->Update();
	disp3->Update();
	disp4->Update();
	disp5->Update();
}

void Game::Trampa() {
	for (int i = 0; i < disparos.size(); i++) {
		if ((this->jugadores[0]->getPos().distance(this->disparos[i]->getPos()) < 100) && this->disparos[i]->GetSize() == 2.5) {
			//cout << "Pium" << endl;
			aux = this->disparos[i]->Obstaculo3::Disparar(mainScene);
			this->obs.push_back(aux);
		}
	}
}

//metodo para comprobar las colisiones
void Game::comprobarColisiones() {
	int resta;
	int puntuacionActual;
	int nuevaPuntuacion;
	int vidaNueva;

	//colisiones con los obstaculos
	if (this->jugadores[0]->getVida() > 0) {
		for (int i = 0; i < obs.size(); i++) {
			if ((this->jugadores[0]->getPos().distance(this->obs[i]->getPos()) < 1.5)) {

				puntuacionActual = this->jugadores[0]->getPuntuacion();
				resta = this->obs[i]->getPuntuacionResta();
				nuevaPuntuacion = puntuacionActual - resta;
				this->jugadores[0]->setPuntuacion(nuevaPuntuacion);

				vidaNueva = this->jugadores[0]->getVida() - this->obs[i]->getVidaResta();
				this->jugadores[0]->setVida(vidaNueva);

				this->escenario1->ColorSegunVida(this->jugadores[0]->getVida());

				Vector3D posJugador = this->jugadores[0]->getPos();
				Text* mensajePuntos = obs[i]->mensajePuntuacion(posJugador);
				this->activeScene->addGameObjects(mensajePuntos);

				Text* mensajeVida = obs[i]->mensajeVida(posJugador);
				this->activeScene->addGameObjects(mensajeVida);

				cout << "Vida: " << this->jugadores[0]->getVida() << endl;
				cout << "Puntuacion : " << this->jugadores[0]->getPuntuacion() << endl;
			}

		}
	}
	int suma;

	//colisiones con los powerUps
	for (int i = 0; i < PUs.size(); i++) {

		if ((this->jugadores[0]->getPos().distance(this->PUs[i]->getPos()) < 1.5)) {

			puntuacionActual = this->jugadores[0]->getPuntuacion();
			suma = this->PUs[i]->getPuntuacionSuma();
			nuevaPuntuacion = puntuacionActual + suma;
			this->jugadores[0]->setPuntuacion(nuevaPuntuacion);

			vidaNueva = this->jugadores[0]->getVida() + this->PUs[i]->getVidaSuma();
			this->jugadores[0]->setVida(vidaNueva);

			this->escenario1->ColorSegunVida(this->jugadores[0]->getVida());

			Text* mensajePuntos = PUs[i]->mensajePuntuacion(jugadores[0]->getPos());
			this->activeScene->addGameObjects(mensajePuntos);

			Text* mensajeVida = PUs[i]->mensajeVida(jugadores[0]->getPos());
			this->activeScene->addGameObjects(mensajeVida);

			cout << "Vida: " << this->jugadores[0]->getVida() << endl;
			cout << "Puntuacion : " << this->jugadores[0]->getPuntuacion() << endl;
		}
	}
}


void Game::Victoria() {
	win = false;
	int puntuacion = this->jugadores[0]->getPuntuacion();
	this->activeScene = winScene;
	cam->setVel(Vector3D(0, 0, 0));
	player->setSpeed(Vector3D(0, 0, 0));
	player->setPos(Vector3D(0, 0, 0));

	//Escritura de texto
	ofstream fPrueba("puntuacion.file", ios::out);
	if (fPrueba.is_open()) {
		fPrueba << "¡Enhorabuena! Has ganado. Tu puntuacion es: " << puntuacion << endl;
		fPrueba.close();
	}
	else {
		cout << "Error al abrir el fichero de salida." << endl;
	}

	//Lectura ficheros texto
	string line;
	ifstream fPruebaEntrada("puntuacion.file");
	if (fPruebaEntrada.is_open()) {
		while (getline(fPruebaEntrada, line)) {
			cout << line << endl;
		}
		fPruebaEntrada.close();
	}
	else {
		cout << "El fichero parece que no existe." << endl;
	}
}

void Game::Derrota() {
	lose = false;
	int puntuacion = this->jugadores[0]->getPuntuacion();
	this->activeScene = loseScene;

	cam->setVel(Vector3D(0, 0, 0));
	player->setSpeed(Vector3D(0, 0, 0));
	player->setPos(Vector3D(0, 0, 0));

	//Escritura de texto
	ofstream fPrueba("puntuacion.file", ios::out);
	if (fPrueba.is_open()) {
		fPrueba << "Has perdido. Tu puntuacion es: " << puntuacion << endl;
		fPrueba.close();
	}
	else {
		cout << "Error al abrir el fichero de salida." << endl;
	}

	//Lectura ficheros texto
	string line;
	ifstream fPruebaEntrada("puntuacion.file");
	if (fPruebaEntrada.is_open()) {
		while (getline(fPruebaEntrada, line)) {
			cout << line << endl;
		}
		fPruebaEntrada.close();
	}
	else {
		cout << "El fichero parece que no existe." << endl;
	}
}
