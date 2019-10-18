#include "Window.h"

int Window::width;
int Window::height;

const char* Window::windowTitle = "GLFW Starter Project";

// Objects to display.
//Cube * Window::cube;
Triangle * Window::bear;
Triangle * Window::bunny;
Triangle * Window::dragon;

Lighting * Window::LightSource;

double Window::mx = 0;
double Window::my = 0;

bool Window::LDown = false;
bool Window::NormCord = false;

bool Window::Down1 = true;
bool Window::Down2 = false;
bool Window::Down3 = false;

// The object currently displaying.
Triangle * Window::currentObj;

glm::mat4 Window::projection; // Projection matrix.

glm::vec3 Window::eye(0, 0, 20); // Camera position.
glm::vec3 Window::center(0, 0, 0); // The point we are looking at.
glm::vec3 Window::up(0, 1, 0); // The up direction of the camera.

// View matrix, defined by eye, center and up.
glm::mat4 Window::view = glm::lookAt(Window::eye, Window::center, Window::up);

GLuint Window::program; // The shader program id.

GLuint Window::projectionLoc; // Location of projection in shader.
GLuint Window::viewLoc; // Location of view in shader.
GLuint Window::modelLoc; // Location of model in shader.
GLuint Window::colorLoc; // Location of color in shader.

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

	// Check the shader program.
	if (!program)
	{
		std::cerr << "Failed to initialize shader program" << std::endl;
		return false;
	}

	// Activate the shader program.
	glUseProgram(program);
	// Get the locations of uniform variables.
	projectionLoc = glGetUniformLocation(program, "projection");
	viewLoc = glGetUniformLocation(program, "view");
	modelLoc = glGetUniformLocation(program, "model");
	colorLoc = glGetUniformLocation(program, "color");
	
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
	//cube = new Cube(10.0f);
	// Create a point cloud consisting of cube vertices.

	Material MBear;
	MBear.ambient = glm::vec3(3*0.0215f, 3*0.1745f, 3*0.0215f);
	MBear.diffuse = glm::vec3(0.0f, 0.0f, 0.0f);
	MBear.specular = glm::vec3(3*0.633f, 3*0.727811f, 3*0.633f);
	MBear.shininess = 3*0.6f;

	Material MBunny;
	MBunny.ambient = glm::vec3(3*0.2125f, 3*0.1275f, 3*0.054f);
	MBunny.diffuse = glm::vec3(3*0.714f, 3*0.4284f, 3*0.18144f);
	MBunny.specular = glm::vec3(0.0f, 0.0f, 0.0f);
	MBunny.shininess = 0.0f;

	Material MDragon;
	MDragon.ambient = glm::vec3(3*0.25f, 3*0.20725f, 3*0.20725f);
	MDragon.diffuse = glm::vec3(3*1.0f, 3*0.829f, 3*0.829f);
	MDragon.specular = glm::vec3(3*0.296648f, 3*0.296648f, 3*0.296648f);
	MDragon.shininess = 3*0.088f;

	Light LightSourceObj;
	LightSourceObj.color = glm::vec3(2*0.1745f, 2*0.01175f, 2*0.01175f);

	LightSourceObj.ambient = glm::vec3(2*0.1745f, 2*0.01175f, 2*0.01175f);
	LightSourceObj.diffuse = glm::vec3(1.0f, 1.0f, 1.0f);
	LightSourceObj.specular = glm::vec3(1.0f, 1.0f, 1.0f);

	LightSourceObj.position = glm::vec3(4.0f, 4.0f, 4.0f);
	LightSourceObj.constant = 1.0f;
	LightSourceObj.linear = 0.022f;
	LightSourceObj.quadratic = 0.0019f;


	
	bear = new Triangle("bear.obj", 1, MBear);
	bunny = new Triangle("bunny.obj", 1, MBunny);
	dragon = new Triangle("dragon.obj", 1, MDragon);

	LightSource = new Lighting("sphere.obj", 1, LightSourceObj);
	// Set cube to be the first to display
	currentObj = bear;

	return true;
}

void Window::cleanUp()
{
	// Deallcoate the objects.
	//delete cube;
	delete bear;
	delete bunny;
	delete dragon;

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
	Window::projection = glm::perspective(glm::radians(60.0), 
		double(width) / (double)height, 1.0, 1000.0);
}

void Window::idleCallback()
{
	// Perform any updates as necessary. 
	currentObj->update();
}

void Window::displayCallback(GLFWwindow* window)
{	
	// Clear the color and depth buffers.
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	

	// Specify the values of the uniform variables we are going to use.
	glm::mat4 model = currentObj->getModel();
	glm::vec3 color = currentObj->getColor();
	Material mat = currentObj->getMaterial();
	Light light = LightSource->getLight();
	glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
	glUniform3fv(colorLoc, 1, glm::value_ptr(color));
	glUniform3fv(colorLoc, 1, glm::value_ptr(color));
	
	glUniform3fv(lightColLoc, 1, glm::value_ptr(light.color));
	glUniform3fv(lightPosLoc, 1, glm::value_ptr(light.position));

	glUniform3fv(lightAmbi, 1, glm::value_ptr(light.ambient));
	glUniform3fv(lightDiff, 1, glm::value_ptr(light.diffuse));
	glUniform3fv(lightSpec, 1, glm::value_ptr(light.specular));

	glUniform1f(lightConst, light.constant);
	glUniform1f(lightlin, light.linear);
	glUniform1f(lightquad, light.quadratic);
	

	glUniform3fv(MatAmbi, 1, glm::value_ptr(mat.ambient));
	glUniform3fv(MatDiff, 1, glm::value_ptr(mat.diffuse));
	glUniform3fv(Matspec, 1, glm::value_ptr(mat.specular));
	glUniform1f(Matshine, mat.shininess); 
	glUniform1i(NormCordLoc, NormCord);

	

	// Render the object.
	currentObj->draw();
	LightSource->draw();

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
		case GLFW_KEY_F1:
			// Set currentObj to bear
			currentObj = bear;
			bear->error();
			break;
		case GLFW_KEY_F2:
			// Set currentObj to bunny
			currentObj = bunny;
			bunny->error();
			break;
		case GLFW_KEY_F3:
			// Set currentObj to dragon
			currentObj = dragon;
			dragon->error();
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
		case GLFW_KEY_P:
			// change size
			if (mods == GLFW_MOD_SHIFT) {
				currentObj->updatePointSize(1);
			}
			else {
				currentObj->updatePointSize(-1);
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
		glm::vec3 lastPos = trackBallMapping(glm::vec2(mx, my));
		glm::vec3 curPos = trackBallMapping(glm::vec2(x, y));
		glm::vec3 dir = curPos - lastPos;
		float vel = glm::length(dir);
		if (vel > 0.0001) {
			glm::vec3 rotAxis = glm::cross(lastPos, curPos);
			float rot_angle = vel*50;
			currentObj->Rotating(rot_angle, rotAxis);
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
	//std::cerr << y << std::endl;
	if (Down1 == true) {
		currentObj->Scaleing(0.01f, y);
	}
	else if (Down2 == true) {
		LightSource->Scaleing(0.01f, y);
	}
	else if (Down2 == true) {
		currentObj->Scaleing(0.01f, y);
	}
}



