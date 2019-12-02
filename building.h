#ifndef _BUILDING_H_
#define _BUILDING_H_

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



class Building {
public:
	glm::mat4 model;
	GLuint modelLoc, colorLoc;
	glm::vec3 color;
private:
	glm::vec3 pos;
	std::vector<glm::vec3> vertices;
	std::vector<glm::ivec3> indices;
	std::vector<glm::vec2> texcords;

	float length;
	float width;
	float height;

	GLuint vao, vbo, vbot, ebo;
	GLuint texture;


public:

	Building(glm::vec3 pos, float l, float w, float h);
	~Building();
	GLuint loadTexture();
	void draw(GLuint shaderProgram);
	void update();
};

#endif
