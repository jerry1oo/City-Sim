#ifndef _TRACK_H_
#define _TRACK_H_

#ifdef __APPLE__
#include <OpenGL/gl3.h>
#else
#include <GL/glew.h>
#endif

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/transform.hpp>
#include <vector>
#include <cmath>
#include <iostream>
#include "Bezier.h"

class Track {
private:

	std::vector<Bezier> curves;
	std::vector<glm::vec3> points;
	std::vector<glm::vec3> curvepoints;
	std::vector<glm::vec3> controlpoints;
	float carPos;
	float max_height_pos;
	float max_height_val;
	int cp;
	int curve;
	int curvepos;


public:


	Track();
	~Track();
	   	 
	void incAxis(char a);
	void decAxis(char a);
	void cpinc();
	void cpdec();
	void C1();
	void trackup();
	void trackposup();
	glm::vec3 getpos();
	void draw(GLuint shaderProgram);

};

#endif