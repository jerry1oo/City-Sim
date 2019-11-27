#ifndef _BEZIER_H_
#define _BEZIER_H_

#ifdef __APPLE__
#include <OpenGL/gl3.h>
#else
#include <GL/glew.h>
#endif

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/transform.hpp>
#include<vector>
#include <cmath>
#include<iostream>

class Bezier{
private:
	glm::mat4 model;
	glm::vec3 color;
	GLuint vaoS, vaoP, vboS, vboP;
	std::vector<glm::vec3> spoints;
	std::vector<glm::vec3> cpoints;
	GLuint modelLoc, colorLoc;
public:
	

	Bezier(glm::vec3 p_0, glm::vec3 p_1, glm::vec3 p_2, glm::vec3 p_3);
	~Bezier();
	
	glm::vec3 p0;
	glm::vec3 p1;
	glm::vec3 p2;
	glm::vec3 p3;

	glm::vec3 curvepoint(float t);
	glm::vec3 GetPoint(int t);
	void draw(GLuint shaderProgram,int col);
	void update();
	glm::vec3 Lerp(glm::vec3 P0, glm::vec3 P1, float t);
	
};

#endif