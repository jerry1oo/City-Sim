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


class Window
{
public:
	static int width;
	static int height;
	static int movement;
	static const char* windowTitle;
	static Cube* cube;
	static Triangle * bear;
	static Triangle * bunny;
	static Triangle * dragon;
	static SkyBox * skybox;
	static BoundSphere * car;
	static Bezier * curve;
	static Track * track;

	static Geometry * R_head;
	static Geometry * R_body;
	static Geometry * R_eye;
	static Geometry * R_ant;
	static Geometry * R_arm;
	static BoundSphere * R_bound;
	static Transform * bound;
	
	static Transform * Army;

	static Transform * Armyrow1;
	static Transform * Armyrow1col1;
	static Transform * Armyrow1col2;
	static Transform * Armyrow1col3;
	static Transform * Armyrow1col4;
	static Transform * Armyrow1col5;
	static Transform * Armyrow1col6;
	static Transform * Armyrow1col7;
	static Transform * Armyrow1col8;
	static Transform * Armyrow1col9;
	static Transform * Armyrow1col10;
	   
	static Transform * Armyrow2;
	static Transform * Armyrow2col1;
	static Transform * Armyrow2col2;
	static Transform * Armyrow2col3;
	static Transform * Armyrow2col4;
	static Transform * Armyrow2col5;
	static Transform * Armyrow2col6;
	static Transform * Armyrow2col7;
	static Transform * Armyrow2col8;
	static Transform * Armyrow2col9;
	static Transform * Armyrow2col10;

	static Transform * Armyrow3;
	static Transform * Armyrow3col1;
	static Transform * Armyrow3col2;
	static Transform * Armyrow3col3;
	static Transform * Armyrow3col4;
	static Transform * Armyrow3col5;
	static Transform * Armyrow3col6;
	static Transform * Armyrow3col7;
	static Transform * Armyrow3col8;
	static Transform * Armyrow3col9;
	static Transform * Armyrow3col10;

	static Transform * Armyrow4;
	static Transform * Armyrow4col1;
	static Transform * Armyrow4col2;
	static Transform * Armyrow4col3;
	static Transform * Armyrow4col4;
	static Transform * Armyrow4col5;
	static Transform * Armyrow4col6;
	static Transform * Armyrow4col7;
	static Transform * Armyrow4col8;
	static Transform * Armyrow4col9;
	static Transform * Armyrow4col10;

	static Transform * Armyrow5;
	static Transform * Armyrow5col1;
	static Transform * Armyrow5col2;
	static Transform * Armyrow5col3;
	static Transform * Armyrow5col4;
	static Transform * Armyrow5col5;
	static Transform * Armyrow5col6;
	static Transform * Armyrow5col7;
	static Transform * Armyrow5col8;
	static Transform * Armyrow5col9;
	static Transform * Armyrow5col10;

	static Transform * Armyrow6;
	static Transform * Armyrow6col1;
	static Transform * Armyrow6col2;
	static Transform * Armyrow6col3;
	static Transform * Armyrow6col4;
	static Transform * Armyrow6col5;
	static Transform * Armyrow6col6;
	static Transform * Armyrow6col7;
	static Transform * Armyrow6col8;
	static Transform * Armyrow6col9;
	static Transform * Armyrow6col10;

	static Transform * Armyrow7;
	static Transform * Armyrow7col1;
	static Transform * Armyrow7col2;
	static Transform * Armyrow7col3;
	static Transform * Armyrow7col4;
	static Transform * Armyrow7col5;
	static Transform * Armyrow7col6;
	static Transform * Armyrow7col7;
	static Transform * Armyrow7col8;
	static Transform * Armyrow7col9;
	static Transform * Armyrow7col10;

	static Transform * Armyrow8;
	static Transform * Armyrow8col1;
	static Transform * Armyrow8col2;
	static Transform * Armyrow8col3;
	static Transform * Armyrow8col4;
	static Transform * Armyrow8col5;
	static Transform * Armyrow8col6;
	static Transform * Armyrow8col7;
	static Transform * Armyrow8col8;
	static Transform * Armyrow8col9;
	static Transform * Armyrow8col10;

	static Transform * Armyrow9;
	static Transform * Armyrow9col1;
	static Transform * Armyrow9col2;
	static Transform * Armyrow9col3;
	static Transform * Armyrow9col4;
	static Transform * Armyrow9col5;
	static Transform * Armyrow9col6;
	static Transform * Armyrow9col7;
	static Transform * Armyrow9col8;
	static Transform * Armyrow9col9;
	static Transform * Armyrow9col10;

	static Transform * Armyrow10;
	static Transform * Armyrow10col1;
	static Transform * Armyrow10col2;
	static Transform * Armyrow10col3;
	static Transform * Armyrow10col4;
	static Transform * Armyrow10col5;
	static Transform * Armyrow10col6;
	static Transform * Armyrow10col7;
	static Transform * Armyrow10col8;
	static Transform * Armyrow10col9;
	static Transform * Armyrow10col10;

	static Transform * Satellite;
	static Transform * Head;
	static Transform * Body;
	static Transform * LeftAnt;
	static Transform * RightAnt;
	static Transform * LeftEye;
	static Transform * RightEye;
	static Transform * RightArm;
	static Transform * LeftArm;
	static Transform * RightLeg;
	static Transform * LeftLeg;


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
