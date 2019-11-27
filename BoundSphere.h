#ifndef _BOUNDSPHERE_H_
#define _BOUNDSPHERE_H_

#ifdef __APPLE__
#include <OpenGL/gl3.h>
#else
#include <GL/glew.h>
#endif

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/transform.hpp>
#include "Node.h"
#include <vector>



class BoundSphere : public Node {
private:

protected:
	glm::mat4 model;
	glm::mat4 lightmod;
	glm::vec3 color;

public:

	static GLuint modelLoc, colorLoc;
	static GLuint MatAmbi, MatDiff, Matspec, Matshine;
	static GLuint cubemapTexture;

	static glm::vec3 boundCenter;
	static double boundRadius;

private:

	std::vector<glm::vec3> points;
	std::vector<glm::vec3> normals;
	std::vector<glm::ivec3> indicesV;

	std::vector<glm::ivec3> indicesT;
	std::vector<glm::ivec3> indicesN;

	std::vector<glm::vec3> vertices_;
	std::vector<glm::vec3> normals_;
	std::vector<unsigned int> indices_;

	GLuint vao, vboV, vboN, ebo;
	GLfloat pointSize;
	GLfloat scale;
	Material material;


public:

	BoundSphere(std::string objFilename, GLfloat pointSize, GLuint tex);
	~BoundSphere();

	void draw(GLuint shaderProgram, glm::mat4 C, bool bound, bool Frustum, std::vector<plane> P, int &count);
	void update(glm::mat4 C);


	glm::mat4 getModel() { return model; }
	glm::vec3 getColor() { return color; }

	void updatePointSize(GLfloat size);
	void Rotating(float deg, glm::vec3 rotAxis);
	void error();

	void Scaleing(float scaler, double y);
	Material getMaterial() { return material; }
	bool inview(glm::vec3 center, float radi) { return false; };
};

#endif
