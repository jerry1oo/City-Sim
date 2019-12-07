#ifndef _CAR_H_
#define _CAR_H_

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



class Car {
public:
	glm::mat4 model;
	GLuint modelLoc, colorLoc;
	glm::vec3 color;
private:
	std::vector<glm::vec3> pos;
	std::vector<glm::vec3> vertices;
	std::vector<glm::ivec3> indices;
	std::vector<glm::vec2> texcords;

	float length;
	float width;
	float height;

	GLchar* Fside;
	GLchar* Ftop;

	GLuint vao, vbo, vbot, ebo;
	GLuint texture;
	GLuint textureR;


public:
	glm::vec3 posb;
	Car(glm::vec3 pos, float l, float w, float h, GLchar* Tside, GLchar* Ttop);
	~Car();
	GLuint loadTexture(GLchar* image);
	float RandomFloat(float a, float b);

	void CarGen();
	void translate(glm::vec3 pos_e);

	void draw(GLuint shaderProgram, glm::mat4 C);
	void Car::spin(float deg);
	void update();
};

#endif

