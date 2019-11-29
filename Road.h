#ifndef _Road_H_
#define _Road_H_

#ifdef __APPLE__
#include <OpenGL/gl3.h>
#else
#include <GL/glew.h>
#endif

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/transform.hpp>
#include <vector>
#include <iostream>
#include "stb_image.h"



class Road {
private:

	std::vector<glm::vec3> vertices;
	std::vector<glm::vec3> normals;
	std::vector<glm::ivec3> indices;
	//std::vector<glm::ivec3> indicesT;
	//std::vector<glm::ivec3> indicesN;
	// vertices[];

	GLuint modelLoc;
	glm::mat4 model;
	//float length;
	//float width;
	glm::vec3 BL;
	glm::vec3 BR;
	glm::vec3 TL;
	glm::vec3 TR;
	GLuint texture;
	GLuint vao, vbo, ebo;

public:

	Road(glm::vec3 tl, glm::vec3 tr, glm::vec3 bl, glm::vec3 br);
	~Road();
	GLuint loadtex();
	void draw(GLuint shaderProgram);

};

#endif

