#ifndef _SKYBOX_H_
#define _SKYBOX_H_

#ifdef __APPLE__
#include <OpenGL/gl3.h>
#else
#include <GL/glew.h>
#endif

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>

#include "Object.h"
#include "stb_image.h"

class SkyBox
{
private:
	std::vector<glm::vec3> vertices;
	std::vector<glm::ivec3> indices;
	std::vector<const GLchar*> faces;

	GLuint vao;
	GLuint vbos[2];

	glm::mat4 model;
	glm::vec3 color;
	GLuint cubemapTexture;

public:

	GLuint modelLoc, colorLoc;

	SkyBox(float size);
	~SkyBox();

	void draw(GLuint shaderProgram);
	void update();
	GLuint loadCubemap(std::vector<const GLchar*> faces);

	glm::mat4 getModel() { return model; }
	glm::vec3 getColor() { return color; }
	GLuint getTex() { return cubemapTexture; }
};

#endif

