#pragma once
#include <cmath>
#include <fstream>
#include <sstream>
#include "Model.h"

class ModelLoader {
protected:
	double size;
	Model model; 
	vector<Vector3D> vertexes; 
	vector<Vector3D> normals; 

	double maxX, maxY, maxZ; 
	double minX, minY, minZ; 
	Vector3D scale = Vector3D(maxX - minX, maxY - minY, maxZ - minZ);
	inline double getWidth() { return maxX - minX; } 
	inline double getHeight() { return maxY - minY; } 
	inline double getLength() { return maxZ - minZ; } 
	Vector3D GetScale() { return scale; }

public:
	ModelLoader(double s = 1) :size(s) {}
	Model getModel() { return model; } 
	void LoadModel(const string& fileName); 
	Vector3D parseObjLineToVector3D(const string& line); 
	Triangle parseObjTriangle(const string& line); 
	void calcBoundaries(Vector3D vectorPoint); 
	Triangle center(Triangle triangle); 
};
