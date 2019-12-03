#ifndef _GROUND_H_
#define _GROUND_H_

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



class Ground {
private:

	std::vector<glm::vec3> vertices;
	std::vector<glm::vec2> tex;
	std::vector<glm::ivec3> indices;
	//std::vector<glm::ivec3> indicesT;
	//std::vector<glm::ivec3> indicesN;
	// vertices[];

	std::vector<glm::vec3> pos;
	glm::vec3 posr;
	glm::mat4 model;
	float length;
	float width;
	glm::vec3 BL;
	glm::vec3 BR;
	glm::vec3 TL;
	glm::vec3 TR;
	GLuint texture;
	glm::vec3 color;
	GLuint modelLoc, colorLoc;
	GLuint vao, vbo, vbot, ebo;

public:

	Ground(glm::vec3 pos1, float l, float w, bool m);
	~Ground();
	GLuint loadTexture();
	void draw(GLuint shaderProgram);

};

#endif