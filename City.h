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
	bool Tswitch;
	bool Gswitch;
	bool lag;

	glm::mat4 Model;
	std::vector<Building*> Buildings;
	Road* SF_L;
	std::vector<std::vector<Building*>> B_Blocks;
	std::vector<Road*> Roads;
	std::vector<std::vector<Road*>> R_Blocks;
	std::list<Ground*> Grounds;


	void addBuilding1(std::vector<Building*> BuildingNode);
	void addRoad1(std::vector<Road*> RoadNode);
	void addBuilding(Building* BuildingNode);
	void addRoad(Road* RoadNode);
	void addGround(Ground* GroundNode);
	float RandomFloat(float a, float b);
	void BuildCity(bool bg, bool tg);
	void BuildCity1(bool bg, bool tg);
	void BuildCity2(bool bg, bool tg);
	void BuildRE(bool bg, bool tg, bool l);
	
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

	void GenB0_1(glm::vec3 pos1, GLchar* fs, GLchar* ft);
	void GenB1_1(glm::vec3 pos1, GLchar* fs, GLchar* ft);
	void GenB2_1(glm::vec3 pos1, GLchar* fs, GLchar* ft);
	void GenB3_1(glm::vec3 pos1, GLchar* fs, GLchar* ft);
	void GenB4_1(glm::vec3 pos1, GLchar* fs, GLchar* ft);
	void GenB5_1(glm::vec3 pos1, GLchar* fs, GLchar* ft);
	void GenB6_1(glm::vec3 pos1, GLchar* fs, GLchar* ft);
	void GenB7_1(glm::vec3 pos1, GLchar* fs, GLchar* ft);

	void GenB8_1(glm::vec3 pos1, GLchar* fs, GLchar* ft);
	void GenB9_1(glm::vec3 pos1, GLchar* fs, GLchar* ft);
	void GenB10_1(glm::vec3 pos1, GLchar* fs, GLchar* ft);
	void GenB11_1(glm::vec3 pos1, GLchar* fs, GLchar* ft);
	void GenB12_1(glm::vec3 pos1, GLchar* fs, GLchar* ft);
	void GenB13_1(glm::vec3 pos1, GLchar* fs, GLchar* ft);

	void GenRoad1();
	void GenRoad2();

	void BuildingGen(glm::vec3 pos1, GLchar* fs, GLchar* ft);
	void BuildingGen1(glm::vec3 pos1, GLchar* fs, GLchar* ft);
	void draw(GLuint shaderProgram, bool Cs);
	void update(bool bg, bool tg, bool cg, bool l);
};

#endif

