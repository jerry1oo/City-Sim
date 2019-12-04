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
#include "building.h"
#include "Road.h"
#include "Ground.h"

class City{
private:
public:

	City();
	~City() {};

	glm::mat4 Model;
	std::list<Building*> Buildings;
	std::list<Road*> Roads;
	std::list<Ground*> Grounds;

	void addBuilding(Building* BuildingNode);
	void addRoad(Road* RoadNode);
	void addGround(Ground* GroundNode);
	float RandomFloat(float a, float b);
	void BuildCity();
	void GenB1(glm::vec3 pos1);
	void draw(GLuint shaderProgram);
	void update();
};

#endif

