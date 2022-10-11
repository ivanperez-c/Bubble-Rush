#include "PowerUps.h"
Text* PowerUps::mensajePuntuacion(Vector3D posJugador)
{
	if (colision == true) {
		Text* nuevoMensaje = new Text("+ 5 puntos");
		nuevoMensaje->setPos(Vector3D(4, 6, posJugador.getZ()));
		nuevoMensaje->setSpeed(Vector3D(0, 0, 0));
		return nuevoMensaje;
	}
}

Text* PowerUps::mensajeVida(Vector3D posJugador)
{
	if (colision == true) {
		Text* nuevoMensaje = new Text("+ 1 vida");
		nuevoMensaje->setPos(Vector3D(4, 4, posJugador.getZ()));
		nuevoMensaje->setSpeed(Vector3D(0, 0, 0));
		nuevoMensaje->setColor(Color(0, 1, 0));
		colision = false;
		return nuevoMensaje;
	}
}
