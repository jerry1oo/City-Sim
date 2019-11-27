#ifndef _NODE_H_
#define _NODE_H_

#ifdef __APPLE__
#include <OpenGL/gl3.h>
#else
#include <GL/glew.h>
#endif

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <vector>

struct plane {
	glm::vec3 normal;
	float Dist;
};

struct Material {
	glm::vec3 ambient;
	glm::vec3 diffuse;
	glm::vec3 specular;
	float shininess;
};

class Node
{
private:
public:
	Node(){};
	~Node(){};

	virtual void draw(GLuint shaderProgram, glm::mat4 C, bool bound, bool Frustum, std::vector<plane> P, int &count) = 0;
	virtual void update(glm::mat4 C) = 0;
	virtual bool inview(glm::vec3 center, float radi) = 0;
};

#endif
