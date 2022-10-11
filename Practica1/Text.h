#pragma once
#include <GL/glut.h>
using namespace std;
#include "Solid.h"
#include <string>

class Text :public Solid {
	string text;
public:
	Text(string t = "Default text") : Solid(), text(t) {}
	Text(const Text& c) :Solid(c), text(c.text) {}
	string getText() { return text; }
	void setText(string t) { text = t; }
	void Render();

};