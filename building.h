#ifndef _BOXBUILDING_H_
#define _BOXBUILDING_H_

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
	std::vector<glm::vec3> pos;
	glm::vec3 posb;
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
	int type;


public:

	Building(glm::vec3 pos, float l, float w, float h, int t, GLchar* Tside, GLchar* Ttop);
	~Building();
	GLuint loadTexture(GLchar* image);
	float RandomFloat(float a, float b);

	void BuildingGen1();
	void BuildingGen2();
	void BuildingGen3();
	void BuildingGen4();
	void BuildingGen5();

	void draw(GLuint shaderProgram,bool tex);
	void update();
};

#endif
