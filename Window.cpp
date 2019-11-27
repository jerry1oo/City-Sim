#include "Window.h"

int Window::width;
int Window::height;

const char* Window::windowTitle = "GLFW Starter Project";

// Objects to display.
//Cube * Window::cube;
Triangle * Window::bear;
Triangle * Window::bunny;
Triangle * Window::dragon;
SkyBox * Window::skybox;
BoundSphere * Window::car;
Bezier * Window::curve;
Track * Window::track;
int Window::movement = 0;


Geometry * Window::R_head;
Geometry * Window::R_body;
Geometry * Window::R_eye;
Geometry * Window::R_ant;
Geometry * Window::R_arm;
BoundSphere * Window::R_bound;
Transform * Window::bound;

Transform * Window::Army;


Transform * Window::Armyrow1;
Transform * Window::Armyrow1col1;
Transform * Window::Armyrow1col2;
Transform * Window::Armyrow1col3;
Transform * Window::Armyrow1col4;
Transform * Window::Armyrow1col5;
Transform * Window::Armyrow1col6;
Transform * Window::Armyrow1col7;
Transform * Window::Armyrow1col8;
Transform * Window::Armyrow1col9;
Transform * Window::Armyrow1col10;

Transform * Window::Armyrow2;
Transform * Window::Armyrow2col1;
Transform * Window::Armyrow2col2;
Transform * Window::Armyrow2col3;
Transform * Window::Armyrow2col4;
Transform * Window::Armyrow2col5;
Transform * Window::Armyrow2col6;
Transform * Window::Armyrow2col7;
Transform * Window::Armyrow2col8;
Transform * Window::Armyrow2col9;
Transform * Window::Armyrow2col10;

Transform * Window::Armyrow3;
Transform * Window::Armyrow3col1;
Transform * Window::Armyrow3col2;
Transform * Window::Armyrow3col3;
Transform * Window::Armyrow3col4;
Transform * Window::Armyrow3col5;
Transform * Window::Armyrow3col6;
Transform * Window::Armyrow3col7;
Transform * Window::Armyrow3col8;
Transform * Window::Armyrow3col9;
Transform * Window::Armyrow3col10;

Transform * Window::Armyrow4;
Transform * Window::Armyrow4col1;
Transform * Window::Armyrow4col2;
Transform * Window::Armyrow4col3;
Transform * Window::Armyrow4col4;
Transform * Window::Armyrow4col5;
Transform * Window::Armyrow4col6;
Transform * Window::Armyrow4col7;
Transform * Window::Armyrow4col8;
Transform * Window::Armyrow4col9;
Transform * Window::Armyrow4col10;

Transform * Window::Armyrow5;
Transform * Window::Armyrow5col1;
Transform * Window::Armyrow5col2;
Transform * Window::Armyrow5col3;
Transform * Window::Armyrow5col4;
Transform * Window::Armyrow5col5;
Transform * Window::Armyrow5col6;
Transform * Window::Armyrow5col7;
Transform * Window::Armyrow5col8;
Transform * Window::Armyrow5col9;
Transform * Window::Armyrow5col10;

Transform * Window::Armyrow6;
Transform * Window::Armyrow6col1;
Transform * Window::Armyrow6col2;
Transform * Window::Armyrow6col3;
Transform * Window::Armyrow6col4;
Transform * Window::Armyrow6col5;
Transform * Window::Armyrow6col6;
Transform * Window::Armyrow6col7;
Transform * Window::Armyrow6col8;
Transform * Window::Armyrow6col9;
Transform * Window::Armyrow6col10;

Transform * Window::Armyrow7;
Transform * Window::Armyrow7col1;
Transform * Window::Armyrow7col2;
Transform * Window::Armyrow7col3;
Transform * Window::Armyrow7col4;
Transform * Window::Armyrow7col5;
Transform * Window::Armyrow7col6;
Transform * Window::Armyrow7col7;
Transform * Window::Armyrow7col8;
Transform * Window::Armyrow7col9;
Transform * Window::Armyrow7col10;

Transform * Window::Armyrow8;
Transform * Window::Armyrow8col1;
Transform * Window::Armyrow8col2;
Transform * Window::Armyrow8col3;
Transform * Window::Armyrow8col4;
Transform * Window::Armyrow8col5;
Transform * Window::Armyrow8col6;
Transform * Window::Armyrow8col7;
Transform * Window::Armyrow8col8;
Transform * Window::Armyrow8col9;
Transform * Window::Armyrow8col10;

Transform * Window::Armyrow9;
Transform * Window::Armyrow9col1;
Transform * Window::Armyrow9col2;
Transform * Window::Armyrow9col3;
Transform * Window::Armyrow9col4;
Transform * Window::Armyrow9col5;
Transform * Window::Armyrow9col6;
Transform * Window::Armyrow9col7;
Transform * Window::Armyrow9col8;
Transform * Window::Armyrow9col9;
Transform * Window::Armyrow9col10;

Transform * Window::Armyrow10;
Transform * Window::Armyrow10col1;
Transform * Window::Armyrow10col2;
Transform * Window::Armyrow10col3;
Transform * Window::Armyrow10col4;
Transform * Window::Armyrow10col5;
Transform * Window::Armyrow10col6;
Transform * Window::Armyrow10col7;
Transform * Window::Armyrow10col8;
Transform * Window::Armyrow10col9;
Transform * Window::Armyrow10col10;

Transform * Window::Satellite;
Transform * Window::Head;
Transform * Window::Body;
Transform * Window::LeftAnt;
Transform * Window::RightAnt;
Transform * Window::LeftEye;
Transform * Window::RightEye;
Transform * Window::RightArm;
Transform * Window::LeftArm;
Transform * Window::RightLeg;
Transform * Window::LeftLeg;


Lighting * Window::LightSource;

std::vector<plane> Window::Planes;

double Window::mx = 0;
double Window::my = 0;

bool Window::LDown = false;
bool Window::NormCord = true;
bool Window::Bswitch = false;
bool Window::Fswitch = true;
bool Window::Dswitch = false;
bool Window::Pswitch = false;

bool Window::Down1 = true;
bool Window::Down2 = false;
bool Window::Down3 = false;

// The object currently displaying.
Transform * Window::currentObj;

glm::mat4 Window::projection; // Projection matrix.
double Window::fov = 60.0;

GLuint Window::campos;
GLuint Window::campos1;
GLuint Window::campos2;

glm::vec3 Window::eye(0, 0, 0); // Camera position.
glm::vec3 Window::center(0, 0, 1); // The point we are looking at.
glm::vec3 Window::up(0, 1, 0); // The up direction of the camera.

// View matrix, defined by eye, center and up.
glm::mat4 Window::view = glm::lookAt(Window::eye, Window::center, Window::up);

glm::vec3 Window::fc;
glm::vec3 Window::ftl;
glm::vec3 Window::ftr;
glm::vec3 Window::fbl;
glm::vec3 Window::fbr;
glm::vec3 Window::nc;
glm::vec3 Window::ntl;
glm::vec3 Window::ntr;
glm::vec3 Window::nbl;
glm::vec3 Window::nbr;
glm::vec3 Window::a;
glm::vec3 Window::normalRight;
glm::vec3 Window::right;

GLuint Window::program; // The shader program id.
GLuint Window::program1;
GLuint Window::program2;
GLuint Window::Beziershader;

GLuint Window::projectionLoc1; // Location of projection in shader.
GLuint Window::projectionLoc2; // Location of projection in shader.
GLuint Window::projectionLoc3; // Location of projection in shader.
GLuint Window::viewLoc1; // Location of view in shader.
GLuint Window::viewLoc2; // Location of view in shader.
GLuint Window::viewLoc3; // Location of view in shader.

GLuint Window::projectionLoc; // Location of projection in shader.
GLuint Window::viewLoc; // Location of view in shader.
GLuint Window::modelLoc; // Location of model in shader.
GLuint Window::colorLoc; // Location of color in shader.
GLuint Window::lightLoc;

GLuint Window::lightColLoc;
GLuint Window::lightPosLoc;


GLuint Window::lightAmbi;
GLuint Window::lightDiff;
GLuint Window::lightSpec;

GLuint Window::lightConst;
GLuint Window::lightlin;
GLuint Window::lightquad;


GLuint Window::MatAmbi;
GLuint Window::MatDiff;
GLuint Window::Matspec;
GLuint Window::Matshine;

GLuint Window::NormCordLoc;



bool Window::initializeProgram() {
	// Create a shader program with a vertex shader and a fragment shader.
	program = LoadShaders("shaders/shader.vert", "shaders/shader.frag");
	program1 = LoadShaders("shaders/Skybox.vert", "shaders/Skybox.frag");
	program2 = LoadShaders("shaders/car.vert", "shaders/car.frag");
	Beziershader = LoadShaders("shaders/Bezier.vert", "shaders/Bezier.frag");

	// Check the shader program.
	if (!program)
	{
		std::cerr << "Failed to initialize shader program" << std::endl;
		return false;
	}
	if (!program1)
	{
		std::cerr << "Failed to initialize shader program" << std::endl;
		return false;
	}

	// Activate the shader program.

	glUseProgram(program2);
	projectionLoc2 = glGetUniformLocation(program2, "projection");
	viewLoc2 = glGetUniformLocation(program2, "view");
	campos2 = glGetUniformLocation(program2, "cameraPos");
	
	glUseProgram(program1);
	projectionLoc1 = glGetUniformLocation(program1, "projection");
	viewLoc1 = glGetUniformLocation(program1, "view");

	glUseProgram(Beziershader);
	projectionLoc3 = glGetUniformLocation(Beziershader, "projection");
	viewLoc3 = glGetUniformLocation(Beziershader, "view");

	// Activate the shader program.
	glUseProgram(program);
	// Get the locations of uniform variables.
	projectionLoc = glGetUniformLocation(program, "projection");
	viewLoc = glGetUniformLocation(program, "view");
	modelLoc = glGetUniformLocation(program, "model");
	colorLoc = glGetUniformLocation(program, "color");
	lightLoc = glGetUniformLocation(program, "lights");
	

	lightColLoc = glGetUniformLocation(program, "light.color");
	lightPosLoc = glGetUniformLocation(program, "light.position");
	lightConst = glGetUniformLocation(program, "light.constant");
	lightlin = glGetUniformLocation(program, "light.linear");
	lightquad = glGetUniformLocation(program, "light.quadratic");
	lightAmbi = glGetUniformLocation(program, "light.ambient");
	lightDiff = glGetUniformLocation(program, "light.diffuse");
	lightSpec = glGetUniformLocation(program, "light.specular");

	MatAmbi = glGetUniformLocation(program, "material.ambient");
	MatDiff = glGetUniformLocation(program, "material.diffuse");
	Matspec = glGetUniformLocation(program, "material.specular");
	Matshine = glGetUniformLocation(program, "material.shininess");


	
	NormCordLoc = glGetUniformLocation(program, "Normcord");
	return true;
}

bool Window::initializeObjects()
{
	// Create a cube of size 5.
	skybox = new SkyBox(400.0f);
	car = new BoundSphere("sphere.obj", 1,skybox->getTex());
	curve = new Bezier(glm::vec3(1.0f, 0.0f, 1.0f), glm::vec3(3.0f, -1.0f, 1.0f), glm::vec3(0.0f, 1.0f, 1.0f), glm::vec3(-1.0f, 0.0f, 1.0f));
	track = new Track();
	// Create a point cloud consisting of cube vertices.

	/*Material MBear;
	MBear.ambient = glm::vec3(1*0.0215f, 1*0.1745f, 1*0.0215f);
	MBear.diffuse = glm::vec3(0.0f, 0.0f, 0.0f);
	MBear.specular = glm::vec3(6*0.633f, 6*0.727811f, 6*0.633f);
	MBear.shininess = 6*0.6f;

	Material MBunny;
	MBunny.ambient = glm::vec3(1*0.2125f, 1*0.1275f, 1*0.054f);
	MBunny.diffuse = glm::vec3(2*0.714f, 2*0.4284f, 2*0.18144f);
	MBunny.specular = glm::vec3(0.0f, 0.0f, 0.0f);
	MBunny.shininess = 0.0f;

	Material MDragon;
	MDragon.ambient = glm::vec3(1*0.25f, 1*0.20725f, 1*0.20725f);
	MDragon.diffuse = glm::vec3(1*1.0f, 1*0.829f, 1*0.829f);
	MDragon.specular = glm::vec3(1*0.296648f, 1*0.296648f, 1*0.296648f);
	MDragon.shininess = 1*0.088f;*/


	Light LightSourceObj;
	LightSourceObj.color = glm::vec3(3*0.1745f, 3*0.01175f, 3*0.01175f);
	LightSourceObj.ambient = glm::vec3(3*0.1745f, 3*0.01175f, 3*0.01175f);
	LightSourceObj.diffuse = glm::vec3(1.0f, 1.0f, 1.0f);
	LightSourceObj.specular = glm::vec3(1.0f, 1.0f, 1.0f);
	LightSourceObj.position = glm::vec3(0.0f, 10.0f, 30.0f);
	LightSourceObj.constant = 1.0f;
	LightSourceObj.linear = 0.022f;
	LightSourceObj.quadratic = 0.0019f;

	Material MLight;
	MLight.ambient = glm::vec3(3 * 0.1745f, 3 * 0.01175f, 3 * 0.01175f);
	MLight.diffuse = glm::vec3(1.0f, 1.0f, 1.0f);
	MLight.specular = glm::vec3(0.0f, 0.0f, 0.0f);
	MLight.shininess = 1.0f;

	Material Mhead;
	Mhead.ambient = glm::vec3(3 * 0.0215f, 3 * 0.1745f, 3 * 0.0215f);
	Mhead.diffuse = glm::vec3(3 * 0.07568f, 3 * 0.61424f, 3 * 0.07568f);
	Mhead.specular = glm::vec3(0 * 0.633f, 3 * 0.727811f, 0 * 0.633f);
	Mhead.shininess = 3 * 0.6f;
	
	Material Meye;
	Meye.ambient = glm::vec3(3 * 0.05375f, 3 * 0.05f, 3 * 0.06625f);
	Meye.diffuse = glm::vec3(3 * 0.18275f, 3 * 0.17f, 3 * 0.22525f);
	Meye.specular = glm::vec3(0 * 0.332741f, 0 * 0.328634f, 0 * 0.346435f);
	Meye.shininess = 0 * 0.3f;

	Army = new Transform(glm::mat4(1));

	double tx = 5.9;
	double ty = 5.9;

	Armyrow1 = new Transform(glm::mat4(1));
	Armyrow1col1 = new Transform(glm::translate(glm::mat4(1), glm::vec3(tx, 0, 0)));
	Armyrow1col2 = new Transform(glm::translate(glm::mat4(1), glm::vec3(2*tx, 0, 0)));
	Armyrow1col3 = new Transform(glm::translate(glm::mat4(1), glm::vec3(3*tx, 0, 0)));
	Armyrow1col4 = new Transform(glm::translate(glm::mat4(1), glm::vec3(4*tx, 0, 0)));
	Armyrow1col5 = new Transform(glm::translate(glm::mat4(1), glm::vec3(5*tx, 0, 0)));
	Armyrow1col6 = new Transform(glm::translate(glm::mat4(1), glm::vec3(0, 0, 0)));
	Armyrow1col7 = new Transform(glm::translate(glm::mat4(1), glm::vec3(-1*tx, 0, 0)));
	Armyrow1col8 = new Transform(glm::translate(glm::mat4(1), glm::vec3(-2*tx, 0, 0)));
	Armyrow1col9 = new Transform(glm::translate(glm::mat4(1), glm::vec3(-3*tx, 0, 0)));
	Armyrow1col10 = new Transform(glm::translate(glm::mat4(1), glm::vec3(-4*tx, 0, 0)));

	Armyrow2 = new Transform(glm::mat4(1));
	Armyrow2col1 = new Transform(glm::translate(glm::mat4(1), glm::vec3(tx, 0, ty)));
	Armyrow2col2 = new Transform(glm::translate(glm::mat4(1), glm::vec3(2 * tx, 0, ty)));
	Armyrow2col3 = new Transform(glm::translate(glm::mat4(1), glm::vec3(3 * tx, 0, ty)));
	Armyrow2col4 = new Transform(glm::translate(glm::mat4(1), glm::vec3(4 * tx, 0, ty)));
	Armyrow2col5 = new Transform(glm::translate(glm::mat4(1), glm::vec3(5 * tx, 0, ty)));
	Armyrow2col6 = new Transform(glm::translate(glm::mat4(1), glm::vec3(0, 0, ty)));
	Armyrow2col7 = new Transform(glm::translate(glm::mat4(1), glm::vec3(-1 * tx, 0, ty)));
	Armyrow2col8 = new Transform(glm::translate(glm::mat4(1), glm::vec3(-2 * tx, 0, ty)));
	Armyrow2col9 = new Transform(glm::translate(glm::mat4(1), glm::vec3(-3 * tx, 0, ty)));
	Armyrow2col10 = new Transform(glm::translate(glm::mat4(1), glm::vec3(-4 * tx, 0, ty)));

	Armyrow3 = new Transform(glm::mat4(1));
	Armyrow3col1 = new Transform(glm::translate(glm::mat4(1), glm::vec3(tx, 0, 2*ty)));
	Armyrow3col2 = new Transform(glm::translate(glm::mat4(1), glm::vec3(2 * tx, 0, 2*ty)));
	Armyrow3col3 = new Transform(glm::translate(glm::mat4(1), glm::vec3(3 * tx, 0, 2*ty)));
	Armyrow3col4 = new Transform(glm::translate(glm::mat4(1), glm::vec3(4 * tx, 0, 2*ty)));
	Armyrow3col5 = new Transform(glm::translate(glm::mat4(1), glm::vec3(5 * tx, 0, 2*ty)));
	Armyrow3col6 = new Transform(glm::translate(glm::mat4(1), glm::vec3(0, 0, 2*ty)));
	Armyrow3col7 = new Transform(glm::translate(glm::mat4(1), glm::vec3(-1 * tx, 0, 2*ty)));
	Armyrow3col8 = new Transform(glm::translate(glm::mat4(1), glm::vec3(-2 * tx, 0, 2*ty)));
	Armyrow3col9 = new Transform(glm::translate(glm::mat4(1), glm::vec3(-3 * tx, 0, 2*ty)));
	Armyrow3col10 = new Transform(glm::translate(glm::mat4(1), glm::vec3(-4 * tx, 0, 2*ty)));

	Armyrow4 = new Transform(glm::mat4(1));
	Armyrow4col1 = new Transform(glm::translate(glm::mat4(1), glm::vec3(tx, 0, 3 * ty)));
	Armyrow4col2 = new Transform(glm::translate(glm::mat4(1), glm::vec3(2 * tx, 0, 3 * ty)));
	Armyrow4col3 = new Transform(glm::translate(glm::mat4(1), glm::vec3(3 * tx, 0, 3 * ty)));
	Armyrow4col4 = new Transform(glm::translate(glm::mat4(1), glm::vec3(4 * tx, 0, 3 * ty)));
	Armyrow4col5 = new Transform(glm::translate(glm::mat4(1), glm::vec3(5 * tx, 0, 3 * ty)));
	Armyrow4col6 = new Transform(glm::translate(glm::mat4(1), glm::vec3(0, 0, 3 * ty)));
	Armyrow4col7 = new Transform(glm::translate(glm::mat4(1), glm::vec3(-1 * tx, 0, 3 * ty)));
	Armyrow4col8 = new Transform(glm::translate(glm::mat4(1), glm::vec3(-2 * tx, 0, 3 * ty)));
	Armyrow4col9 = new Transform(glm::translate(glm::mat4(1), glm::vec3(-3 * tx, 0, 3 * ty)));
	Armyrow4col10 = new Transform(glm::translate(glm::mat4(1), glm::vec3(-4 * tx, 0, 3 * ty)));

	Armyrow5 = new Transform(glm::mat4(1));
	Armyrow5col1 = new Transform(glm::translate(glm::mat4(1), glm::vec3(tx, 0, 4 * ty)));
	Armyrow5col2 = new Transform(glm::translate(glm::mat4(1), glm::vec3(2 * tx, 0, 4 * ty)));
	Armyrow5col3 = new Transform(glm::translate(glm::mat4(1), glm::vec3(3 * tx, 0, 4 * ty)));
	Armyrow5col4 = new Transform(glm::translate(glm::mat4(1), glm::vec3(4 * tx, 0, 4 * ty)));
	Armyrow5col5 = new Transform(glm::translate(glm::mat4(1), glm::vec3(5 * tx, 0, 4 * ty)));
	Armyrow5col6 = new Transform(glm::translate(glm::mat4(1), glm::vec3(0, 0, 4 * ty)));
	Armyrow5col7 = new Transform(glm::translate(glm::mat4(1), glm::vec3(-1 * tx, 0, 4 * ty)));
	Armyrow5col8 = new Transform(glm::translate(glm::mat4(1), glm::vec3(-2 * tx, 0, 4 * ty)));
	Armyrow5col9 = new Transform(glm::translate(glm::mat4(1), glm::vec3(-3 * tx, 0, 4 * ty)));
	Armyrow5col10 = new Transform(glm::translate(glm::mat4(1), glm::vec3(-4 * tx, 0, 4 * ty)));

	Armyrow6 = new Transform(glm::mat4(1));
	Armyrow6col1 = new Transform(glm::translate(glm::mat4(1), glm::vec3(tx, 0, 5 * ty)));
	Armyrow6col2 = new Transform(glm::translate(glm::mat4(1), glm::vec3(2 * tx, 0, 5 * ty)));
	Armyrow6col3 = new Transform(glm::translate(glm::mat4(1), glm::vec3(3 * tx, 0, 5 * ty)));
	Armyrow6col4 = new Transform(glm::translate(glm::mat4(1), glm::vec3(4 * tx, 0, 5 * ty)));
	Armyrow6col5 = new Transform(glm::translate(glm::mat4(1), glm::vec3(5 * tx, 0, 5 * ty)));
	Armyrow6col6 = new Transform(glm::translate(glm::mat4(1), glm::vec3(0, 0, 5 * ty)));
	Armyrow6col7 = new Transform(glm::translate(glm::mat4(1), glm::vec3(-1 * tx, 0, 5 * ty)));
	Armyrow6col8 = new Transform(glm::translate(glm::mat4(1), glm::vec3(-2 * tx, 0, 5 * ty)));
	Armyrow6col9 = new Transform(glm::translate(glm::mat4(1), glm::vec3(-3 * tx, 0, 5 * ty)));
	Armyrow6col10 = new Transform(glm::translate(glm::mat4(1), glm::vec3(-4 * tx, 0, 5 * ty)));

	Armyrow7 = new Transform(glm::mat4(1));
	Armyrow7col1 = new Transform(glm::translate(glm::mat4(1), glm::vec3(tx, 0, -1 * ty)));
	Armyrow7col2 = new Transform(glm::translate(glm::mat4(1), glm::vec3(2 * tx, 0, -1 * ty)));
	Armyrow7col3 = new Transform(glm::translate(glm::mat4(1), glm::vec3(3 * tx, 0, -1 * ty)));
	Armyrow7col4 = new Transform(glm::translate(glm::mat4(1), glm::vec3(4 * tx, 0, -1 * ty)));
	Armyrow7col5 = new Transform(glm::translate(glm::mat4(1), glm::vec3(5 * tx, 0, -1 * ty)));
	Armyrow7col6 = new Transform(glm::translate(glm::mat4(1), glm::vec3(0, 0, -1 * ty)));
	Armyrow7col7 = new Transform(glm::translate(glm::mat4(1), glm::vec3(-1 * tx, 0, -1 * ty)));
	Armyrow7col8 = new Transform(glm::translate(glm::mat4(1), glm::vec3(-2 * tx, 0, -1 * ty)));
	Armyrow7col9 = new Transform(glm::translate(glm::mat4(1), glm::vec3(-3 * tx, 0, -1 * ty)));
	Armyrow7col10 = new Transform(glm::translate(glm::mat4(1), glm::vec3(-4 * tx, 0, -1 * ty)));

	Armyrow8 = new Transform(glm::mat4(1));
	Armyrow8col1 = new Transform(glm::translate(glm::mat4(1), glm::vec3(tx, 0, -2 * ty)));
	Armyrow8col2 = new Transform(glm::translate(glm::mat4(1), glm::vec3(2 * tx, 0, -2 * ty)));
	Armyrow8col3 = new Transform(glm::translate(glm::mat4(1), glm::vec3(3 * tx, 0, -2 * ty)));
	Armyrow8col4 = new Transform(glm::translate(glm::mat4(1), glm::vec3(4 * tx, 0, -2 * ty)));
	Armyrow8col5 = new Transform(glm::translate(glm::mat4(1), glm::vec3(5 * tx, 0, -2 * ty)));
	Armyrow8col6 = new Transform(glm::translate(glm::mat4(1), glm::vec3(0, 0, -2 * ty)));
	Armyrow8col7 = new Transform(glm::translate(glm::mat4(1), glm::vec3(-1 * tx, 0, -2 * ty)));
	Armyrow8col8 = new Transform(glm::translate(glm::mat4(1), glm::vec3(-2 * tx, 0, -2 * ty)));
	Armyrow8col9 = new Transform(glm::translate(glm::mat4(1), glm::vec3(-3 * tx, 0, -2 * ty)));
	Armyrow8col10 = new Transform(glm::translate(glm::mat4(1), glm::vec3(-4 * tx, 0, -2 * ty)));

	Armyrow9 = new Transform(glm::mat4(1));
	Armyrow9col1 = new Transform(glm::translate(glm::mat4(1), glm::vec3(tx, 0, -3 * ty)));
	Armyrow9col2 = new Transform(glm::translate(glm::mat4(1), glm::vec3(2 * tx, 0, -3 * ty)));
	Armyrow9col3 = new Transform(glm::translate(glm::mat4(1), glm::vec3(3 * tx, 0, -3 * ty)));
	Armyrow9col4 = new Transform(glm::translate(glm::mat4(1), glm::vec3(4 * tx, 0, -3 * ty)));
	Armyrow9col5 = new Transform(glm::translate(glm::mat4(1), glm::vec3(5 * tx, 0, -3 * ty)));
	Armyrow9col6 = new Transform(glm::translate(glm::mat4(1), glm::vec3(0, 0, -3 * ty)));
	Armyrow9col7 = new Transform(glm::translate(glm::mat4(1), glm::vec3(-1 * tx, 0, -3 * ty)));
	Armyrow9col8 = new Transform(glm::translate(glm::mat4(1), glm::vec3(-2 * tx, 0, -3 * ty)));
	Armyrow9col9 = new Transform(glm::translate(glm::mat4(1), glm::vec3(-3 * tx, 0, -3 * ty)));
	Armyrow9col10 = new Transform(glm::translate(glm::mat4(1), glm::vec3(-4 * tx, 0, -3 * ty)));

	Armyrow10 = new Transform(glm::mat4(1));
	Armyrow10col1 = new Transform(glm::translate(glm::mat4(1), glm::vec3(tx, 0, -4 * ty)));
	Armyrow10col2 = new Transform(glm::translate(glm::mat4(1), glm::vec3(2 * tx, 0, -4 * ty)));
	Armyrow10col3 = new Transform(glm::translate(glm::mat4(1), glm::vec3(3 * tx, 0, -4 * ty)));
	Armyrow10col4 = new Transform(glm::translate(glm::mat4(1), glm::vec3(4 * tx, 0, -4 * ty)));
	Armyrow10col5 = new Transform(glm::translate(glm::mat4(1), glm::vec3(5 * tx, 0, -4 * ty)));
	Armyrow10col6 = new Transform(glm::translate(glm::mat4(1), glm::vec3(0, 0, -4 * ty)));
	Armyrow10col7 = new Transform(glm::translate(glm::mat4(1), glm::vec3(-1 * tx, 0, -4 * ty)));
	Armyrow10col8 = new Transform(glm::translate(glm::mat4(1), glm::vec3(-2 * tx, 0, -4 * ty)));
	Armyrow10col9 = new Transform(glm::translate(glm::mat4(1), glm::vec3(-3 * tx, 0, -4 * ty)));
	Armyrow10col10 = new Transform(glm::translate(glm::mat4(1), glm::vec3(-4 * tx, 0, -4 * ty)));

	Army->addChild(Armyrow1);
	Armyrow1->addChild(Armyrow1col1);
	Armyrow1->addChild(Armyrow1col2);
	Armyrow1->addChild(Armyrow1col3);
	Armyrow1->addChild(Armyrow1col4);
	Armyrow1->addChild(Armyrow1col5);
	Armyrow1->addChild(Armyrow1col6);
	Armyrow1->addChild(Armyrow1col7);
	Armyrow1->addChild(Armyrow1col8);
	Armyrow1->addChild(Armyrow1col9);
	Armyrow1->addChild(Armyrow1col10);

	Army->addChild(Armyrow2);
	Armyrow2->addChild(Armyrow2col1);
	Armyrow2->addChild(Armyrow2col2);
	Armyrow2->addChild(Armyrow2col3);
	Armyrow2->addChild(Armyrow2col4);
	Armyrow2->addChild(Armyrow2col5);
	Armyrow2->addChild(Armyrow2col6);
	Armyrow2->addChild(Armyrow2col7);
	Armyrow2->addChild(Armyrow2col8);
	Armyrow2->addChild(Armyrow2col9);
	Armyrow2->addChild(Armyrow2col10);

	Army->addChild(Armyrow3);
	Armyrow3->addChild(Armyrow3col1);
	Armyrow3->addChild(Armyrow3col2);
	Armyrow3->addChild(Armyrow3col3);
	Armyrow3->addChild(Armyrow3col4);
	Armyrow3->addChild(Armyrow3col5);
	Armyrow3->addChild(Armyrow3col6);
	Armyrow3->addChild(Armyrow3col7);
	Armyrow3->addChild(Armyrow3col8);
	Armyrow3->addChild(Armyrow3col9);
	Armyrow3->addChild(Armyrow3col10);

	Army->addChild(Armyrow4);
	Armyrow4->addChild(Armyrow4col1);
	Armyrow4->addChild(Armyrow4col2);
	Armyrow4->addChild(Armyrow4col3);
	Armyrow4->addChild(Armyrow4col4);
	Armyrow4->addChild(Armyrow4col5);
	Armyrow4->addChild(Armyrow4col6);
	Armyrow4->addChild(Armyrow4col7);
	Armyrow4->addChild(Armyrow4col8);
	Armyrow4->addChild(Armyrow4col9);
	Armyrow4->addChild(Armyrow4col10);

	Army->addChild(Armyrow5);
	Armyrow5->addChild(Armyrow5col1);
	Armyrow5->addChild(Armyrow5col2);
	Armyrow5->addChild(Armyrow5col3);
	Armyrow5->addChild(Armyrow5col4);
	Armyrow5->addChild(Armyrow5col5);
	Armyrow5->addChild(Armyrow5col6);
	Armyrow5->addChild(Armyrow5col7);
	Armyrow5->addChild(Armyrow5col8);
	Armyrow5->addChild(Armyrow5col9);
	Armyrow5->addChild(Armyrow5col10);

	Army->addChild(Armyrow6);
	Armyrow6->addChild(Armyrow6col1);
	Armyrow6->addChild(Armyrow6col2);
	Armyrow6->addChild(Armyrow6col3);
	Armyrow6->addChild(Armyrow6col4);
	Armyrow6->addChild(Armyrow6col5);
	Armyrow6->addChild(Armyrow6col6);
	Armyrow6->addChild(Armyrow6col7);
	Armyrow6->addChild(Armyrow6col8);
	Armyrow6->addChild(Armyrow6col9);
	Armyrow6->addChild(Armyrow6col10);

	Army->addChild(Armyrow7);
	Armyrow7->addChild(Armyrow7col1);
	Armyrow7->addChild(Armyrow7col2);
	Armyrow7->addChild(Armyrow7col3);
	Armyrow7->addChild(Armyrow7col4);
	Armyrow7->addChild(Armyrow7col5);
	Armyrow7->addChild(Armyrow7col6);
	Armyrow7->addChild(Armyrow7col7);
	Armyrow7->addChild(Armyrow7col8);
	Armyrow7->addChild(Armyrow7col9);
	Armyrow7->addChild(Armyrow7col10);

	Army->addChild(Armyrow8);
	Armyrow8->addChild(Armyrow8col1);
	Armyrow8->addChild(Armyrow8col2);
	Armyrow8->addChild(Armyrow8col3);
	Armyrow8->addChild(Armyrow8col4);
	Armyrow8->addChild(Armyrow8col5);
	Armyrow8->addChild(Armyrow8col6);
	Armyrow8->addChild(Armyrow8col7);
	Armyrow8->addChild(Armyrow8col8);
	Armyrow8->addChild(Armyrow8col9);
	Armyrow8->addChild(Armyrow8col10);

	Army->addChild(Armyrow9);
	Armyrow9->addChild(Armyrow9col1);
	Armyrow9->addChild(Armyrow9col2);
	Armyrow9->addChild(Armyrow9col3);
	Armyrow9->addChild(Armyrow9col4);
	Armyrow9->addChild(Armyrow9col5);
	Armyrow9->addChild(Armyrow9col6);
	Armyrow9->addChild(Armyrow9col7);
	Armyrow9->addChild(Armyrow9col8);
	Armyrow9->addChild(Armyrow9col9);
	Armyrow9->addChild(Armyrow9col10);

	Army->addChild(Armyrow10);
	Armyrow10->addChild(Armyrow10col1);
	Armyrow10->addChild(Armyrow10col2);
	Armyrow10->addChild(Armyrow10col3);
	Armyrow10->addChild(Armyrow10col4);
	Armyrow10->addChild(Armyrow10col5);
	Armyrow10->addChild(Armyrow10col6);
	Armyrow10->addChild(Armyrow10col7);
	Armyrow10->addChild(Armyrow10col8);
	Armyrow10->addChild(Armyrow10col9);
	Armyrow10->addChild(Armyrow10col10);
		
	bound = new Transform(glm::scale(glm::mat4(1), glm::vec3(2.8)));
	R_bound = new BoundSphere("sphere.obj", 1,skybox->getTex());
	Satellite = new Transform(glm::mat4(1),0);	
	Head = new Transform(glm::translate(glm::mat4(1),glm::vec3(0,1.1,0)),4);
	Body = new Transform(glm::mat4(1),4);
	LeftAnt = new Transform(glm::scale(glm::rotate(glm::translate(glm::mat4(1), glm::vec3(0.5, 1.9, 0)), glm::radians(40.0f), glm::vec3(0.0, 0.0, -1.0)), glm::vec3(0.3)),3);
	RightAnt = new Transform(glm::scale(glm::rotate(glm::translate(glm::mat4(1), glm::vec3(-0.5, 1.9, 0)), glm::radians(40.0f), glm::vec3(0.0, 0.0, 1.0)), glm::vec3(0.3)),3);
	LeftEye = new Transform(glm::translate(glm::mat4(1), glm::vec3(0.5, 1.6, 0.7)),4);
	RightEye = new Transform(glm::translate(glm::mat4(1), glm::vec3(-0.5, 1.6, 0.7)),4);
	RightArm = new Transform(glm::rotate(glm::translate(glm::mat4(1), glm::vec3(1.3, 0, 0)), glm::radians(40.0f), glm::vec3(0.0, 0.0, 1.0)),5);
	LeftArm = new Transform(glm::rotate(glm::translate(glm::mat4(1), glm::vec3(-1.3, 0, 0)), glm::radians(40.0f), glm::vec3(0.0, 0.0, -1.0)),6);
	RightLeg = new Transform(glm::translate(glm::mat4(1), glm::vec3(0.6, -1.4, 0)),2);
	LeftLeg = new Transform(glm::translate(glm::mat4(1), glm::vec3(-0.6, -1.4, 0)),1);
	Satellite->addChild(Head);
	Satellite->addChild(Body);
	Satellite->addChild(LeftAnt);
	Satellite->addChild(RightAnt);
	Satellite->addChild(LeftEye);
	Satellite->addChild(RightEye);
	Satellite->addChild(RightArm);
	Satellite->addChild(LeftArm);
	Satellite->addChild(RightLeg);
	Satellite->addChild(LeftLeg);
	Satellite->addBound(bound);
	
	R_head = new Geometry("head_s.obj", 1, Mhead);
	R_body = new Geometry("body_s.obj", 1, Mhead);
	R_ant = new Geometry("antenna_s.obj", 1, Mhead);
	R_eye = new Geometry("eyeball_s.obj", 1, Meye);
	R_arm = new Geometry("limb_s.obj", 1, Mhead);

	

	//Satellite->addChild(bound);
	bound->addChild(R_bound);
	Head->addChild(R_head);
	Body->addChild(R_body);
	RightAnt->addChild(R_ant);
	LeftAnt->addChild(R_ant);
	RightEye->addChild(R_eye);
	LeftEye->addChild(R_eye);
	RightArm->addChild(R_arm);
	LeftArm->addChild(R_arm);
	RightLeg->addChild(R_arm);
	LeftLeg->addChild(R_arm);

	Armyrow1col1->addChild(Satellite);
	Armyrow1col2->addChild(Satellite);
	Armyrow1col3->addChild(Satellite);
	Armyrow1col4->addChild(Satellite);
	Armyrow1col5->addChild(Satellite);
	Armyrow1col6->addChild(Satellite);
	Armyrow1col7->addChild(Satellite);
	Armyrow1col8->addChild(Satellite);
	Armyrow1col9->addChild(Satellite);
	Armyrow1col10->addChild(Satellite);

	Armyrow2col1->addChild(Satellite);
	Armyrow2col2->addChild(Satellite);
	Armyrow2col3->addChild(Satellite);
	Armyrow2col4->addChild(Satellite);
	Armyrow2col5->addChild(Satellite);
	Armyrow2col6->addChild(Satellite);
	Armyrow2col7->addChild(Satellite);
	Armyrow2col8->addChild(Satellite);
	Armyrow2col9->addChild(Satellite);
	Armyrow2col10->addChild(Satellite);

	Armyrow3col1->addChild(Satellite);
	Armyrow3col2->addChild(Satellite);
	Armyrow3col3->addChild(Satellite);
	Armyrow3col4->addChild(Satellite);
	Armyrow3col5->addChild(Satellite);
	Armyrow3col6->addChild(Satellite);
	Armyrow3col7->addChild(Satellite);
	Armyrow3col8->addChild(Satellite);
	Armyrow3col9->addChild(Satellite);
	Armyrow3col10->addChild(Satellite);

	Armyrow4col1->addChild(Satellite);
	Armyrow4col2->addChild(Satellite);
	Armyrow4col3->addChild(Satellite);
	Armyrow4col4->addChild(Satellite);
	Armyrow4col5->addChild(Satellite);
	Armyrow4col6->addChild(Satellite);
	Armyrow4col7->addChild(Satellite);
	Armyrow4col8->addChild(Satellite);
	Armyrow4col9->addChild(Satellite);
	Armyrow4col10->addChild(Satellite);

	Armyrow5col1->addChild(Satellite);
	Armyrow5col2->addChild(Satellite);
	Armyrow5col3->addChild(Satellite);
	Armyrow5col4->addChild(Satellite);
	Armyrow5col5->addChild(Satellite);
	Armyrow5col6->addChild(Satellite);
	Armyrow5col7->addChild(Satellite);
	Armyrow5col8->addChild(Satellite);
	Armyrow5col9->addChild(Satellite);
	Armyrow5col10->addChild(Satellite);

	Armyrow6col1->addChild(Satellite);
	Armyrow6col2->addChild(Satellite);
	Armyrow6col3->addChild(Satellite);
	Armyrow6col4->addChild(Satellite);
	Armyrow6col5->addChild(Satellite);
	Armyrow6col6->addChild(Satellite);
	Armyrow6col7->addChild(Satellite);
	Armyrow6col8->addChild(Satellite);
	Armyrow6col9->addChild(Satellite);
	Armyrow6col10->addChild(Satellite);

	Armyrow7col1->addChild(Satellite);
	Armyrow7col2->addChild(Satellite);
	Armyrow7col3->addChild(Satellite);
	Armyrow7col4->addChild(Satellite);
	Armyrow7col5->addChild(Satellite);
	Armyrow7col6->addChild(Satellite);
	Armyrow7col7->addChild(Satellite);
	Armyrow7col8->addChild(Satellite);
	Armyrow7col9->addChild(Satellite);
	Armyrow7col10->addChild(Satellite);

	Armyrow8col1->addChild(Satellite);
	Armyrow8col2->addChild(Satellite);
	Armyrow8col3->addChild(Satellite);
	Armyrow8col4->addChild(Satellite);
	Armyrow8col5->addChild(Satellite);
	Armyrow8col6->addChild(Satellite);
	Armyrow8col7->addChild(Satellite);
	Armyrow8col8->addChild(Satellite);
	Armyrow8col9->addChild(Satellite);
	Armyrow8col10->addChild(Satellite);

	Armyrow9col1->addChild(Satellite);
	Armyrow9col2->addChild(Satellite);
	Armyrow9col3->addChild(Satellite);
	Armyrow9col4->addChild(Satellite);
	Armyrow9col5->addChild(Satellite);
	Armyrow9col6->addChild(Satellite);
	Armyrow9col7->addChild(Satellite);
	Armyrow9col8->addChild(Satellite);
	Armyrow9col9->addChild(Satellite);
	Armyrow9col10->addChild(Satellite);

	Armyrow10col1->addChild(Satellite);
	Armyrow10col2->addChild(Satellite);
	Armyrow10col3->addChild(Satellite);
	Armyrow10col4->addChild(Satellite);
	Armyrow10col5->addChild(Satellite);
	Armyrow10col6->addChild(Satellite);
	Armyrow10col7->addChild(Satellite);
	Armyrow10col8->addChild(Satellite);
	Armyrow10col9->addChild(Satellite);
	Armyrow10col10->addChild(Satellite);

	/*bear = new Triangle("bear.obj", 1, MBear, modelLoc);
	bunny = new Triangle("bunny.obj", 1, MBunny, modelLoc);
	dragon = new Triangle("dragon.obj", 1, MDragon, modelLoc);*/



	LightSource = new Lighting("sphere.obj", 1, MLight, LightSourceObj, modelLoc);
	// Set cube to be the first to display
	currentObj = Satellite;

	return true;
}

void Window::cleanUp()
{
	// Deallcoate the objects.
	//delete cube;
	//delete bear;
	//delete bunny;
	//delete dragon;

	// Delete the shader program.
	glDeleteProgram(program);
}

GLFWwindow* Window::createWindow(int width, int height)
{
	// Initialize GLFW.
	if (!glfwInit())
	{
		std::cerr << "Failed to initialize GLFW" << std::endl;
		return NULL;
	}

	// 4x antialiasing.
	glfwWindowHint(GLFW_SAMPLES, 4);

#ifdef __APPLE__ 
	// Apple implements its own version of OpenGL and requires special treatments
	// to make it uses modern OpenGL.

	// Ensure that minimum OpenGL version is 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// Enable forward compatibility and allow a modern OpenGL context
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

	// Create the GLFW window.
	GLFWwindow* window = glfwCreateWindow(width, height, windowTitle, NULL, NULL);

	// Check if the window could not be created.
	if (!window)
	{
		std::cerr << "Failed to open GLFW window." << std::endl;
		glfwTerminate();
		return NULL;
	}

	// Make the context of the window.
	glfwMakeContextCurrent(window);

#ifndef __APPLE__
	// On Windows and Linux, we need GLEW to provide modern OpenGL functionality.

	// Initialize GLEW.
	if (glewInit())
	{
		std::cerr << "Failed to initialize GLEW" << std::endl;
		return NULL;
	}
#endif

	// Set swap interval to 1.
	glfwSwapInterval(0);

	// Call the resize callback to make sure things get drawn immediately.
	Window::resizeCallback(window, width, height);

	return window;
}

void Window::resizeCallback(GLFWwindow* window, int width, int height)
{
#ifdef __APPLE__
	// In case your Mac has a retina display.
	glfwGetFramebufferSize(window, &width, &height); 
#endif
	Window::width = width;
	Window::height = height;
	// Set the viewport size.
	glViewport(0, 0, width, height);

	// Set the projection matrix.
	Window::projection = glm::perspective(glm::radians(fov),
		double(width) / (double)height, 1.0, 1000.0);
}

void Window::idleCallback()
{
	// Perform any updates as necessary. 
	//currentObj->update(glm::mat4(1));
	if (Pswitch) {
		if (movement > 10) {
			track->trackposup();
			movement = 0;
		}
		movement++;
	}
}

std::vector<plane> Window::frustum(float f) {
	std::vector<plane> P;
	float farDist = 1000.0;
	float nearDist = 1.0;
	glm::vec3 d = glm::normalize(center - eye);
	glm::vec3 right = glm::cross(up, d);
	float Hnear = 2 * tan(glm::radians(f) / 2) * 1.0;
	float Wnear = Hnear * (double(width) / (double)height);
	float Hfar = 2 * tan(glm::radians(f) / 2) * farDist;
	float Wfar = Hfar * (double(width) / (double)height);
	fc = eye + d * farDist;
	ftl = fc + (glm::normalize(up) * (Hfar / 2)) - (right * (Wfar / 2));
	ftr = fc + (glm::normalize(up) * (Hfar / 2)) + (right * (Wfar / 2));
	fbl = fc - (glm::normalize(up) * (Hfar / 2)) - (right * (Wfar / 2));
	fbr = fc - (glm::normalize(up) * (Hfar / 2)) + (right * (Wfar / 2));
	nc = eye + d * nearDist;
	ntl = nc + (glm::normalize(up) * (Hnear / 2)) - (right * (Wnear / 2));
	ntr = nc + (glm::normalize(up) * (Hnear / 2)) + (right * (Wnear / 2));
	nbl = nc - (glm::normalize(up) * (Hnear / 2)) - (right * (Wnear / 2));
	nbr = nc - (glm::normalize(up) * (Hnear / 2)) + (right * (Wnear / 2));

	glm::vec3 v1 = fbr - ftr;
	glm::vec3 u1 = ftl - ftr;
	glm::vec3 cross1 = glm::normalize(glm::cross(v1, u1));
	float A1 = cross1.x;
	float B1 = cross1.y;
	float C1 = cross1.z;
	float D1 = glm::dot(cross1, ftr) / -1;

	plane P1;
	P1.normal = cross1;
	P1.Dist = D1;
	P.push_back(P1);

	glm::vec3 v2 = ntl - ntr;
	glm::vec3 u2 = nbr - ntr;
	glm::vec3 cross2 = glm::normalize(glm::cross(v2, u2));
	float A2 = cross2.x;
	float B2 = cross2.y;
	float C2 = cross2.z;
	float D2 = glm::dot(cross2, ntr) / -1;

	plane P2;
	P2.normal = cross2;
	P2.Dist = D2;
	P.push_back(P2);

	glm::vec3 v3 = ftl - ntl;
	glm::vec3 u3 = nbl - ntl;
	glm::vec3 cross3 = glm::normalize(glm::cross(v3, u3));
	float A3 = cross3.x;
	float B3 = cross3.y;
	float C3 = cross3.z;
	float D3 = glm::dot(cross3, ntl) / -1;

	plane P3;
	P3.normal = cross3;
	P3.Dist = D3;
	P.push_back(P3);

	glm::vec3 v4 = ftr - fbr;
	glm::vec3 u4 = nbr - fbr;
	glm::vec3 cross4 = glm::normalize(glm::cross(v4, u4));
	float A4 = cross4.x;
	float B4 = cross4.y;
	float C4 = cross4.z;
	float D4 = glm::dot(cross4, fbr) / -1;

	plane P4;
	P4.normal = cross4;
	P4.Dist = D4;
	P.push_back(P4);

	glm::vec3 v5 = nbr - fbr;
	glm::vec3 u5 = fbl - fbr;
	glm::vec3 cross5 = glm::normalize(glm::cross(v5, u5));
	float A5 = cross5.x;
	float B5 = cross5.y;
	float C5 = cross5.z;
	float D5 = glm::dot(cross5, fbr) / -1;

	plane P5;
	P5.normal = cross5;
	P5.Dist = D5;
	P.push_back(P5);

	glm::vec3 v6 = ftl - ftr;
	glm::vec3 u6 = ntr - ftr;
	glm::vec3 cross6 = glm::normalize(glm::cross(v6, u6));
	float A6 = cross6.x;
	float B6 = cross6.y;
	float C6 = cross6.z;
	float D6 = glm::dot(cross6, ftr) / -1;

	plane P6;
	P6.normal = cross6;
	P6.Dist = D6;
	P.push_back(P6);

	return P;
}

void Window::displayCallback(GLFWwindow* window)
{	

	std::vector<plane> PL;
	int counter = 0;
	if (Dswitch == true) {
		PL = frustum(fov);
		Window::projection = glm::perspective(glm::radians(fov + 50.0f),
			double(width) / (double)height, 1.0, 1000.0);
	}
	else {
		PL = frustum(fov);
		Window::projection = glm::perspective(glm::radians(fov),
			double(width) / (double)height, 1.0, 1000.0);
	}
	


	// Clear the color and depth buffers.
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	
	

	glUseProgram(Beziershader);
	glUniformMatrix4fv(projectionLoc3, 1, GL_FALSE, glm::value_ptr(projection));
	glUniformMatrix4fv(viewLoc3, 1, GL_FALSE, glm::value_ptr(view));
	track->draw(Beziershader);

	glUseProgram(program2);
	// Specify the values of the uniform variables we are going to use.
	glUniformMatrix4fv(projectionLoc2, 1, GL_FALSE, glm::value_ptr(projection));
	glUniformMatrix4fv(viewLoc2, 1, GL_FALSE, glm::value_ptr(view));
	glUniformMatrix4fv(campos2, 1, GL_FALSE, glm::value_ptr(eye));
	car->draw(program2, glm::scale(glm::translate(glm::mat4(1), track->getpos()), glm::vec3(1.0f)), false, false, PL, counter);

	glUseProgram(program);
	Light light = LightSource->getLight();
	Material lightmat = LightSource->getMaterial();
	glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
	
	
	glUniform3fv(lightLoc, 1, glm::value_ptr(light.position));
	
	glUniform3fv(lightColLoc, 1, glm::value_ptr(light.color));
	glUniform3fv(lightPosLoc, 1, glm::value_ptr(light.position));

	glUniform3fv(lightAmbi, 1, glm::value_ptr(light.ambient));
	glUniform3fv(lightDiff, 1, glm::value_ptr(light.diffuse));
	glUniform3fv(lightSpec, 1, glm::value_ptr(light.specular));

	glUniform1f(lightConst, light.constant);
	glUniform1f(lightlin, light.linear);
	glUniform1f(lightquad, light.quadratic);

	glUniform1i(NormCordLoc, NormCord);

	

	// Render the object.
	//currentObj->draw(program,glm::scale(glm::translate(glm::mat4(1), glm::vec3(0,0,10)), glm::vec3(1.0f)), Bswitch, Fswitch,PL,counter);
	counter = counter / 10;
	glm::mat4 model = LightSource->getModel();
	glm::vec3 color = LightSource->getColor();
	glUniform3fv(colorLoc, 1, glm::value_ptr(color));
	glUniform3fv(lightAmbi, 1, glm::value_ptr(glm::vec3(1.0f)));
	glUniform3fv(lightDiff, 1, glm::value_ptr(glm::vec3(1.0f)));
	glUniform3fv(lightSpec, 1, glm::value_ptr(glm::vec3(1.0f)));
	glUniform3fv(MatAmbi, 1, glm::value_ptr(lightmat.ambient));
	glUniform3fv(MatDiff, 1, glm::value_ptr(lightmat.diffuse));
	glUniform3fv(Matspec, 1, glm::value_ptr(lightmat.specular));
	glUniform1f(Matshine, lightmat.shininess);
	glUniform1i(NormCordLoc, NormCord);

	glUseProgram(program1);
	// Specify the values of the uniform variables we are going to use.
	glUniformMatrix4fv(projectionLoc1, 1, GL_FALSE, glm::value_ptr(projection));
	glUniformMatrix4fv(viewLoc1, 1, GL_FALSE, glm::value_ptr(view));
	skybox->draw(program1);
	//LightSource->draw();

	// Gets events, including input such as keyboard and mouse or window resizing.
	glfwPollEvents();
	// Swap buffers.
	glfwSwapBuffers(window);
}


void Window::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	
	// Check for a key press.
	if (action == GLFW_PRESS)
	{
		switch (key)
		{
		case GLFW_KEY_ESCAPE:
			// Close the window. This causes the program to also terminate.
			glfwSetWindowShouldClose(window, GL_TRUE);				
			break;
		//case GLFW_KEY_1:
		//	// Set currentObj to bear
		//	currentObj = cube;
		//	break;
		case GLFW_KEY_RIGHT:
			std::cout << "right" << std::endl;
			track->cpinc();
			break;
		case GLFW_KEY_LEFT:
			std::cout << "left" << std::endl;
			track->cpdec();
			break;
		case GLFW_KEY_X:
			if (mods == GLFW_MOD_SHIFT) {
				std::cout << "-x" << std::endl;
				track->decAxis('X');
			}
			else {
				std::cout << "x" << std::endl;
				track->incAxis('x');
			}
			break;
		case GLFW_KEY_Y:
			if (mods == GLFW_MOD_SHIFT) {
				std::cout << "-y" << std::endl;
				track->decAxis('Y');
			}
			else {
				std::cout << "y" << std::endl;
				track->incAxis('y');
			}
			break;
		case GLFW_KEY_Z:
			if (mods == GLFW_MOD_SHIFT) {
				std::cout << "-z" << std::endl;
				track->decAxis('Z');
			}
			else {
				std::cout << "z" << std::endl;
				track->incAxis('z');
			}
			break;
		case GLFW_KEY_F3:
			// Set currentObj to dragon
			//currentObj = dragon;
			//dragon->error();
			break;
		case GLFW_KEY_1:
			// Set currentObj to dragon
			Down1 = true;
			Down2 = false;
			Down3 = false;
			break;
		case GLFW_KEY_2:
			// Set currentObj to dragon
			Down1 = false;
			Down2 = true;
			Down3 = false;
			break;
		case GLFW_KEY_3:
			// Set currentObj to dragon
			Down1 = false;
			Down2 = false;
			Down3 = true;
			break;
		case GLFW_KEY_B:
			// change size
			if (Bswitch == true) {
				Bswitch = false;
			}
			else {
				Bswitch = true;
			}			
			break;
		case GLFW_KEY_P:
			// change size
			if (Pswitch == true) {
				Pswitch = false;
			}
			else {
				Pswitch = true;
			}
			break;
		case GLFW_KEY_D:
			// change size
			if (Dswitch == true) {
				Dswitch = false;
			}
			else {
				Dswitch = true;
			}
			break;
		case GLFW_KEY_F:
			// change size
			if (Fswitch == true) {
				Fswitch = false;
			}
			else {
				Fswitch = true;
			}
			break;
		case GLFW_KEY_N:
			// change size
			if (NormCord == true) {
				NormCord = false;
			}
			else {
				NormCord = true;
			}
			break;
		default:
			break;
		}
	}
}

void Window::cursorPos(GLFWwindow* window, double x, double y)
{
	
	if (LDown == true) {
		glm::vec3 lastPos2 = trackBallMapping(glm::vec2(mx, my));
		glm::vec3 curPos2 = trackBallMapping(glm::vec2(x, y));
		glm::vec3 dir2 = curPos2 - lastPos2;
		float vel2 = glm::length(dir2);
		if (vel2 > 0.0001) {
			glm::vec3 rotAxis = glm::cross(lastPos2, curPos2);
			float rotAngle = vel2*30;
			
			glm::mat4 TM = glm::translate(glm::mat4(1.0f),Window::eye);
			glm::mat4 TMI = glm::inverse(TM);
			glm::vec4 dirv = glm::vec4(center - eye, 0);			
			glm::mat4 rotM = glm::rotate(glm::mat4(1.0f),glm::radians(rotAngle), rotAxis);
			dirv = TM* dirv;
			dirv = rotM* dirv;
			dirv = TMI* dirv;
			Window::center = (glm::vec3(dirv));
			Window::view = glm::lookAt(Window::eye, Window::center + Window::eye, Window::up);
						
		}
	}

	mx = x;
	my = y;
}

void Window::mouseClick(GLFWwindow* window, int button, int action, int mods) {
	if (action == GLFW_PRESS) {
		switch (button) {
			case GLFW_MOUSE_BUTTON_LEFT:
				glfwGetCursorPos(window, &mx, &my);
				LDown = true;
				break;
		}
	}
	else if (action == GLFW_RELEASE) {
		switch (button) {
			case GLFW_MOUSE_BUTTON_LEFT:
				LDown = false;
				break;
		}
	}
	
}

glm::vec3 Window::trackBallMapping(glm::vec2 point) {

	glm::vec3 v;
	float d;

	v.x = (2.0f * point.x - width) / width;
	v.y = (height - 2.0f * point.y) / height;
	v.z = 0.0f;

	d = glm::length(v);

	d = (d < 1.0f) ? d : 1.0f;
	v.z = sqrtf(1.001f - d * d);

	v = glm::normalize(v);
	return v;

}

void Window::scrollwheel(GLFWwindow* window, double x, double y) {

	if (fov >= 1.0f && fov <= 180.0f) {
		fov -= y;
	}
	if (fov <= 1.0f) {
		fov = 1.0f;
	}
	if (fov >= 180.0f) {
		fov = 180.0f;
	}
	Window::projection = glm::perspective(glm::radians(fov),
		double(width) / (double)height, 1.0, 1000.0);

}



