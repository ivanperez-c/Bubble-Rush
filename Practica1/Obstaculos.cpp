#include "Obstaculos.h"
Text* Obstaculos::mensajePuntuacion(Vector3D posJugador)
{
	if (colision == true) {
		Text* nuevoMensaje = new Text("-10 puntos");
		nuevoMensaje->setPos(Vector3D(4, 6, posJugador.getZ()));
		nuevoMensaje->setColor(Color(1, 0, 0));
		return nuevoMensaje;
	}
	
}

Text* Obstaculos::mensajeVida(Vector3D posJugador)
{
	if (colision == true) {
		Text* nuevoMensaje = new Text("- 1 vida");
		cout << posJugador << endl;
		nuevoMensaje->setPos(Vector3D(4, 4, posJugador.getZ()));
		nuevoMensaje->setSpeed(Vector3D(0, 0, 0));
		nuevoMensaje->setColor(Color(1, 0, 0));
		colision = false;
		return nuevoMensaje;
	}

}