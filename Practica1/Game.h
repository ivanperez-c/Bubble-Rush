#pragma once
#include "Vector3d.h"
#include <iostream>
#include <GL/glut.h>
#include "Cube.h"
#include "Sphere.h"
#include "Cuboid.h"
#include "Torus.h"
#include "Cylinder.h"
#include <vector> 
#include "Solid.h"
#include "Scene.h"
#include "Camera.h"
#include "Triangle.h"
#include "Model.h"
#include "ModelLoader.h"
#include "Text.h"
#include<chrono>

//Nuevas clases
#include"Light.h"
#include "Jugador.h"
#include "CamaraJuego.h"
#include "Obstaculos.h"
#include "Obstaculo1.h"
#include "Obstaculo2.h"
#include "Obstaculo3.h"
//#include "Obstaculo4.h"
#include "Escenario.h"
#include "PowerUps.h"
#include "Interfaz.h"

using namespace std::chrono;
using namespace std;
class Game
{
public:
	const double TIME_INCREMENT = 0.05;
	const int UPDATE_PERIOD = 10; 

	milliseconds initialMilliseconds;
	long lastUpdatedTime;

	bool win = true;
	bool lose = true;

	Scene* activeScene;
	vector<Scene*>scenes;
	Scene* mainScene = new(nothrow) Scene(); // Creacion de la escena
	Scene* winScene = new(nothrow) Scene(); // Creacion de la escena
	Scene* loseScene = new(nothrow) Scene(); // Creacion de la escena

	vector<Jugador*> jugadores; // Vector que almacena a los jugadores
	vector<Obstaculos*> obs; // Vector que almacena todos los obstaculos
	vector<PowerUps*> PUs; // Vector que almacena todos los power ups
	vector<Obstaculo3*> disparos; // Vector que almacena todos los obstaculos que disparan


	Jugador* player = new Jugador();

	Escenario* escenario1 = new Escenario();

	CamaraJuego* cam = new CamaraJuego();

	Obstaculo3* aux = new Obstaculo3(); // Obstaculo auxiliar para crear el disparo

	//Creación de obstáculos de tipo 1
	Obstaculo1* cre1;
	Obstaculo1* cre2;
	Obstaculo1* cre3;
	Obstaculo1* cre4;

	//Creación obstáculos de tipo 2
	Obstaculo2* disp1;
	Obstaculo2* disp2;
	Obstaculo2* disp3;
	Obstaculo2* disp4;
	Obstaculo2* disp5;

	//Creación obstáculos de tipo 2
	Obstaculo3* tramp1;
	Obstaculo3* tramp2;

	Game() : activeScene(nullptr), initialMilliseconds(duration_cast<milliseconds>(system_clock::now().time_since_epoch())), lastUpdatedTime(0), player(nullptr) {}

	void Init();
	void Render();
	void Update();
	void ProcessKeyPressed(unsigned char key, int px, int py);
	void ProcessMouseMovement(int x, int y);
	void ProcessMouseClick(int button, int state, int x, int y);

	void Trampa();
	void comprobarColisiones();
	void Victoria();
	void Derrota();
};

