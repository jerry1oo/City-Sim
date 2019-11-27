#ifndef _Lighting_H_
#define _Lighting_H_

#ifdef __APPLE__
#include <OpenGL/gl3.h>
#else
#include <GL/glew.h>
#endif


#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/transform.hpp>
#include <vector>
#include <string>


#include "Object.h"
//#include "Window.h"


struct Light {
	glm::vec3 position;

	glm::vec3 color;

	glm::vec3 ambient;
	glm::vec3 diffuse;
	glm::vec3 specular;

	float constant;
	float linear;
	float quadratic;
};

class Lighting : public Object
{
private:
	std::vector<glm::vec3> points;
	std::vector<glm::vec3> normals;
	std::vector<glm::ivec3> triangles;
	GLuint vao, vboV, vboN, ebo;
	GLfloat pointSize;
	GLfloat scale;
	Material material;
	Light light;
	GLuint modelLoc;
public:
	Lighting(std::string objFilename, GLfloat pointSize, Material M, Light L, GLuint modelL);
	~Lighting();

	void draw();
	void update();

	void updatePointSize(GLfloat size);
	void Rotating(float deg, glm::vec3 rotAxis);

	void error();
	void Scaleing(float scaler, double y);
	Light getLight() { return light; };
	Material getMaterial() { return material; };
};

#endif

