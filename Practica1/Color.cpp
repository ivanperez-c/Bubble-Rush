#include "Color.h"

Color::Color() :r(0), g(0), b(0) { }
Color::Color(double r, double g, double b) : r(r), g(g), b(b) {}

double Color::getR() { return r; }
double Color::getG() { return g; }
double Color::getB() { return b; }
void Color::setR(float d) { r = d; }
void Color::setG(float d) { g = d; }
void Color::setB(float d) { b = d; }
