#ifndef _WINDOW_H_
#define _WINDOW_H_

#ifdef __APPLE__
#define GLFW_INCLUDE_GLCOREARB
#include <OpenGL/gl3.h>
#else
#include <GL/glew.h>
#endif
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include <vector>
#include <memory>

#include "Object.h"
#include "Cube.h"
#include "PointCloud.h"
#include "Triangle.h"
#include "Lighting.h"
#include "shader.h"

class Window
{
public:
	static int width;
	static int height;
	static const char* windowTitle;
	static Cube* cube;
	static Triangle * bear;
	static Triangle * bunny;
	static Triangle * dragon;
	static Triangle * currentObj;
	static Lighting * LightSource;
	static double mx, my;
	static bool LDown;

	static bool Down1;
	static bool Down2;
	static bool Down3;

	static bool NormCord;
	static glm::mat4 projection;
	static glm::mat4 view;
	static glm::vec3 eye, center, up;
	static GLuint program, projectionLoc, viewLoc, modelLoc, colorLoc, lightLoc;

	static GLuint lightColLoc, lightPosLoc, lightConst, lightlin, lightquad, lightAmbi, lightDiff, lightSpec;

	static GLuint MatAmbi, MatDiff, Matspec, Matshine;

	static GLuint NormCordLoc;

	static bool initializeProgram();
	static bool initializeObjects();
	static void cleanUp();
	static GLFWwindow* createWindow(int width, int height);
	static void resizeCallback(GLFWwindow* window, int width, int height);
	static void idleCallback();
	static void displayCallback(GLFWwindow*);
	static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static glm::vec3 trackBallMapping(glm::vec2 point);
	static void scrollwheel(GLFWwindow* window, double x, double y);
	static void cursorPos(GLFWwindow* window, double xpos, double ypos);
	static void mouseClick(GLFWwindow* window, int button, int action, int mods);
};



#endif
