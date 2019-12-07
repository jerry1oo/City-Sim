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
#include <string>
#include <sstream> 

#include "Object.h"
#include "Cube.h"
#include "PointCloud.h"
#include "Triangle.h"
#include "Lighting.h"
#include "shader.h"
#include "Geometry.h"
#include "Transform.h"
#include "BoundSphere.h"
#include "SkyBox.h"
#include "Track.h"
//#include "Road.h"
//#include "building.h"
#include "City.h"
//#include "Ground.h"
#include "Car.h"

class Window
{
public:
	static int frames;
	static int framescounter;
	static bool blur;

	static glm::mat4 taximod;
	static glm::mat4 taxitran;
	
	//static bool First;

	static int width;
	static int height;
	static int movement;
	static const char* windowTitle;
	static Cube* cube;
	static Triangle * bear;
	static Triangle * bunny;
	static Triangle * dragon;
	static SkyBox * skybox;
	//static BoundSphere * car;
	static Bezier * curve;
	static Track * track;
	//static Road * road;
	//static Building * building;
	static City * city;
	static Car * taxi;
	//static Ground * ground;


	static glm::vec3 CullCenter;
	static double CullRadius;

	static Transform * currentObj;
	static Lighting * LightSource;
	static double mx, my;
	static bool LDown;
	static bool Bswitch;
	static bool Fswitch;
	static bool Dswitch;

	static bool Pswitch;
	static bool Tswitch;
	static bool Gswitch;
	static bool Cswitch;
	static bool Lswitch;

	static bool Down1;
	static bool Down2;
	static bool Down3;

	static bool NormCord;
	static glm::mat4 projection;
	static double fov;
	static glm::mat4 view;
	static glm::vec3 eye, center, up;


	

	static glm::vec3 fc, ftl, ftr, fbl, fbr, nc, ntl, ntr, nbl, nbr, a, normalRight, right;
	static std::vector<plane> Planes;

	static GLuint campos, campos1, campos2;

	static GLuint RoadShader, projectionLocRoad, viewLocRoad;
	static GLuint BuildingShader, projectionLocBuilding, viewLocBuilding;

	static GLuint program, program1, program2, Beziershader, projectionLoc, viewLoc, modelLoc, colorLoc, lightLoc, projectionLoc1, viewLoc1, projectionLoc2, viewLoc2, projectionLoc3, viewLoc3;

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

	static std::vector<plane> frustum(float f);

};



#endif
