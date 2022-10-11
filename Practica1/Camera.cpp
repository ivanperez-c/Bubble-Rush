#include "Camera.h"
void Camera::Render() {
	glTranslatef(-1 * getPos().getX(), -1 * getPos().getY(), -1 * getPos().getZ());
	glRotated(getOrientation().getX(), 1, 0, 0);
	glRotated(getOrientation().getY(), 0, 1, 0);
	glRotated(getOrientation().getZ(), 0, 0, 1);
}
