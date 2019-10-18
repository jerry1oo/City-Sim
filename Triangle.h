#ifndef _Triangle_H_
#define _Triangle_H_

#ifdef __APPLE__
#include <OpenGL/gl3.h>
#else
#include <GL/glew.h>
#endif

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <vector>
#include <string>

#include "Object.h"

struct Material {
	glm::vec3 ambient;
	glm::vec3 diffuse;
	glm::vec3 specular;
	float shininess;
};



class Triangle : public Object
{
private:
	std::vector<glm::vec3> points;
	std::vector<glm::vec3> normals;
	std::vector<glm::ivec3> triangles;
	GLuint vao, vboV, vboN, ebo;
	GLfloat pointSize;
	GLfloat scale;
	Material material;
	
public:
	Triangle(std::string objFilename, GLfloat pointSize, Material M);
	~Triangle();

	void draw();
	void update();

	void updatePointSize(GLfloat size);
	void Rotating(float deg, glm::vec3 rotAxis);

	void error();
	void Scaleing(float scaler, double y);
	Material getMaterial() { return material; }
};

#endif
