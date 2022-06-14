#include "Interfaz.h"
void Interfaz::TextoVictoria(Scene* winScene) {
	Text* pWin1 = new Text("¡Enhorabuena!");
	pWin1->setPos(Vector3D(-5, 4, -15));
	winScene->addGameObjects(pWin1);

	Text* pWin2 = new Text("Has completado el juego");
	pWin2->setPos(Vector3D(-5, 3, -15));
	winScene->addGameObjects(pWin2);

	Text* pWin4 = new Text("Para salir pulsa la tecla 'F1'");
	pWin4->setPos(Vector3D(-5, 2, -15));
	winScene->addGameObjects(pWin4);

	Text* pWin5 = new Text("Creado por Juan Higuero Lopez e Ivan Perez Ciruelos");
	pWin5->setPos(Vector3D(-5, 0, -15));
	winScene->addGameObjects(pWin5);
}

void Interfaz::TextoDerrota(Scene* loseScene) {
	Text* pLose1 = new Text("¡GAME OVER!");
	pLose1->setPos(Vector3D(-5, 4, -15));
	loseScene->addGameObjects(pLose1);

	Text* pLose4 = new Text("Para salir pulsa la tecla 'F1'");
	pLose4->setPos(Vector3D(-5, 2, -15));
	loseScene->addGameObjects(pLose4);

	Text* pLose5 = new Text("Creado por Juan Higuero Lopez e Ivan Perez Ciruelos");
	pLose5->setPos(Vector3D(-5, 0, -15));
	loseScene->addGameObjects(pLose5);
}