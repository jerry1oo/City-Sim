#ifndef _CITY_H_
#define _CITY_H_

#ifdef __APPLE__
#include <OpenGL/gl3.h>
#else
#include <GL/glew.h>
#endif

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <list>
#include<vector>
#include<iostream>
#include <stdlib.h> 
#include "Building.h"
#include "Road.h"
#include "Ground.h"

class City{
private:
public:

	City();
	~City() {};

	int SF;
	bool first = true;

	glm::mat4 Model;
	std::list<Building*> Buildings;
	std::list<Road*> Roads;
	std::list<Ground*> Grounds;


	void addBuilding(Building* BuildingNode);
	void addRoad(Road* RoadNode);
	void addGround(Ground* GroundNode);
	float RandomFloat(float a, float b);
	void BuildCity();
	void GenB0(glm::vec3 pos1, GLchar* fs, GLchar* ft);
	void GenB1(glm::vec3 pos1, GLchar* fs, GLchar* ft);
	void GenB2(glm::vec3 pos1, GLchar* fs, GLchar* ft);
	void GenB3(glm::vec3 pos1, GLchar* fs, GLchar* ft);
	void GenB4(glm::vec3 pos1, GLchar* fs, GLchar* ft);
	void GenB5(glm::vec3 pos1, GLchar* fs, GLchar* ft);
	void GenB6(glm::vec3 pos1, GLchar* fs, GLchar* ft);
	void GenB7(glm::vec3 pos1, GLchar* fs, GLchar* ft);

	void GenB8(glm::vec3 pos1, GLchar* fs, GLchar* ft);
	void GenB9(glm::vec3 pos1, GLchar* fs, GLchar* ft);
	void GenB10(glm::vec3 pos1, GLchar* fs, GLchar* ft);
	void GenB11(glm::vec3 pos1, GLchar* fs, GLchar* ft);
	void GenB12(glm::vec3 pos1, GLchar* fs, GLchar* ft);
	void GenB13(glm::vec3 pos1, GLchar* fs, GLchar* ft);

	void GenRoad1();
	void GenRoad2();

	void BuildingGen(glm::vec3 pos1, GLchar* fs, GLchar* ft);
	void draw(GLuint shaderProgram);
	void update();
};

#endif

