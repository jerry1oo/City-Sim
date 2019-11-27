#ifndef _TRANSFORM_H_
#define _TRANSFORM_H_

#ifdef __APPLE__
#include <OpenGL/gl3.h>
#else
#include <GL/glew.h>
#endif

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include "Node.h"
#include <list>
#include<vector>
#include<iostream>

class Transform : public Node {
private:
public:

	glm::vec3 BC;
	double BR;
	Node * BoundSphere;
	int poslimb;
	int anicount;
	bool anipos;
	std::vector<plane> PS;

	Transform(glm::mat4 C) { M = C; poslimb = -1; anicount = -1; anipos = true;};
	Transform(glm::mat4 C, int l) { M = C; poslimb = l; anicount = -1; anipos = true;};
	Transform(glm::mat4 C, Transform * bs, int l) { M = C; BoundSphere = bs; poslimb = 0;};
	~Transform(){};

	glm::mat4 M;
	std::list<Node*> ChildNodes;
	std::list<Node*> BoundNodes;

	void addChild(Node* childNode);
	void addBound(Node* boundNode);
	void draw(GLuint shaderProgram, glm::mat4 C, bool bound, bool Frustum, std::vector<plane> P, int &count);
	void update(glm::mat4 C);
	bool inview(glm::vec3 center, float radi);
};

#endif
