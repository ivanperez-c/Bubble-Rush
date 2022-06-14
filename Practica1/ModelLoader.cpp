#include "ModelLoader.h"

void ModelLoader::LoadModel(const string& filePath) {

	try {
		ifstream objFile(filePath);
		if (objFile.is_open()) {
			string line;
			int count = 0;
			while (getline(objFile, line)) {
				if (line[0] == 'v' && line[1] == 'n') {
					Vector3D normal = this->parseObjLineToVector3D(line);
					this->normals.push_back(normal);
				}
				else if (line[0] == 'v')
				{
					Vector3D vertex = parseObjLineToVector3D(line);
					this->calcBoundaries(vertex);
					this->vertexes.push_back(vertex);
				}
				else if (line[0] == 'f')
				{
					Triangle triangle = this->parseObjTriangle(line);
					this->model.addTriangle(this->center(triangle));
				}
			}
			objFile.close();
		}
		else {
			throw runtime_error("No se ha podido abrir el archivo: " + filePath);
		}
	}
	catch (exception& ex) {
		throw runtime_error("Excepcion al procesar el archivo: " + filePath);
		throw runtime_error(ex.what());
	}
	
}


Vector3D ModelLoader::parseObjLineToVector3D(const string& line) {
	string typeOfPoint;
	float xCoordinate, yCoordinate, zCoordinate;
	istringstream stringStream(line);
	stringStream >> typeOfPoint >> xCoordinate >> yCoordinate >> zCoordinate;
	Vector3D vectorPoint = Vector3D(xCoordinate, yCoordinate, zCoordinate);
	return vectorPoint * size;
}


Triangle ModelLoader::parseObjTriangle(const string& line) {
	char c;
	int idxVertex0, idxVertex1, idxVertex2;
	int idxNormal0, idxNormal1, idxNormal2;

	istringstream stringStream(line);
	stringStream >> c;
	stringStream >> idxVertex0 >> c >> c >> idxNormal0;
	stringStream >> idxVertex1 >> c >> c >> idxNormal1;
	stringStream >> idxVertex2 >> c >> c >> idxNormal2;

	Vector3D vertex0 = this->vertexes[idxVertex0 - 1];
	Vector3D vertex1 = this->vertexes[idxVertex1 - 1];
	Vector3D vertex2 = this->vertexes[idxVertex2 - 1];
	Vector3D normal = this->vertexes[idxNormal0 - 1];

	Triangle parsedTriangle(vertex0, vertex1, vertex2);  
	parsedTriangle.setNormal1(normal);
	parsedTriangle.setNormal2(normal);
	parsedTriangle.setNormal3(normal);
	
	return parsedTriangle;
}

void ModelLoader::calcBoundaries(Vector3D vectorPoint) {
	this->maxX = fmax(this->maxX, vectorPoint.getX());
	this->maxY = fmax(this->maxY, vectorPoint.getY());
	this->maxZ = fmax(this->maxZ, vectorPoint.getZ());
	this->minX = fmin(this->minX, vectorPoint.getX());
	this->minY = fmin(this->minY, vectorPoint.getY());
	this->minZ = fmin(this->minZ, vectorPoint.getZ());
}

Triangle ModelLoader::center(Triangle triangle) {
	Vector3D modelCenter(this->minX + this->getWidth() / 2.0, 
		this->minY + this->getHeight() / 2.0, 
		this->minZ + this->getLength() / 2);

	Vector3D p0 = triangle.getVertex1() - modelCenter;
	Vector3D p1 = triangle.getVertex2() - modelCenter;
	Vector3D p2 = triangle.getVertex3() - modelCenter;

	Triangle centeredTriangle(p0, p1, p2);

	centeredTriangle.setNormal1(triangle.getNormal1());
	centeredTriangle.setNormal2(triangle.getNormal2());
	centeredTriangle.setNormal3(triangle.getNormal3());
	return centeredTriangle;
}
