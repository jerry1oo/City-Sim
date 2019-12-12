#include "Window.h"

int Window::width;
int Window::height;

const char* Window::windowTitle = "GLFW Starter Project";

// Objects to display.

Triangle * Window::bear;
Triangle * Window::bunny;
Triangle * Window::dragon;
SkyBox * Window::skybox;
glm::mat4 Window::taximod = glm::mat4(1);
//BoundSphere * Window::car;
Bezier * Window::curve;
Track * Window::track;
Car * Window::taxi;
int Window::movement = 0;
int Window::sound1 = 0;

int Window::frames = 4;
int Window::framescounter = 10;
bool Window::blur = false;
irrklang::ISound* Window::music;
irrklang::ISound* Window::back;
irrklang::ISound* Window::TiredSound;
irrklang::ISoundEngine*  Window::SoundEngine = irrklang::createIrrKlangDevice();
irrklang::ISoundEngine*  Window::SoundEngineB = irrklang::createIrrKlangDevice();
irrklang::ISoundEngine*  Window::SoundEngineT = irrklang::createIrrKlangDevice();

//Road * Window::road;
//Building * Window::building;
City * Window::city;
//Ground * Window::ground;

bool Window::firstMouse = true;
float Window::yaw = -90.0f;
float Window::pitch = 0.0f;

Lighting * Window::LightSource;

std::vector<plane> Window::Planes;

double Window::mx = 0;
double Window::my = 0;

float Window::deltaTime = 0.0f;
float Window::lastFrame = 0.0f;

bool Window::LDown = false;
bool Window::NormCord = true;
bool Window::Bswitch = false;
bool Window::Fswitch = false;
bool Window::Dswitch = false;

bool Window::Pswitch = false;
bool Window::Tswitch = false;
bool Window::Gswitch = false;
bool Window::Cswitch = true;
bool Window::Lswitch = false;
bool Window::Eswitch = false;

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

glm::vec3 Window::eye(0, -8, 0); // Camera position.
glm::vec3 Window::center(0, 0, -1); // The point we are looking at.
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
GLuint Window::RoadShader;
GLuint Window::BuildingShader;
GLuint Window::FBOShader;

GLuint Window::projectionLocRoad;
GLuint Window::viewLocRoad;

GLuint Window::projectionLocBuilding;
GLuint Window::viewLocBuilding;

GLuint Window::projectionLocFBO;
GLuint Window::viewLocFBO;

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

unsigned int Window::FBO;
unsigned int Window::texture;
unsigned int Window::rbo;
unsigned int Window::quadVAO, Window::quadVBO;

bool Window::initializeProgram() {
	// Create a shader program with a vertex shader and a fragment shader.
	program = LoadShaders("shaders/shader.vert", "shaders/shader.frag");
	program1 = LoadShaders("shaders/Skybox.vert", "shaders/Skybox.frag");
	program2 = LoadShaders("shaders/car.vert", "shaders/car.frag");
	Beziershader = LoadShaders("shaders/Bezier.vert", "shaders/Bezier.frag");
	RoadShader = LoadShaders("shaders/Road.vert", "shaders/Road.frag");
	BuildingShader = LoadShaders("shaders/Building.vert", "shaders/Building.frag");
	FBOShader = LoadShaders("shaders/FBO.vert", "shaders/FBO.frag");
	
	float quadVertices[] = { // vertex attributes for a quad that fills the entire screen in Normalized Device Coordinates.
	// positions   // texCoords
	-1.0f,  1.0f,  0.0f, 1.0f,
	-1.0f, -1.0f,  0.0f, 0.0f,
	 1.0f, -1.0f,  1.0f, 0.0f,

	-1.0f,  1.0f,  0.0f, 1.0f,
	 1.0f, -1.0f,  1.0f, 0.0f,
	 1.0f,  1.0f,  1.0f, 1.0f
	};

	
	glGenVertexArrays(1, &quadVAO);
	glGenBuffers(1, &quadVBO);
	glBindVertexArray(quadVAO);
	glBindBuffer(GL_ARRAY_BUFFER, quadVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(quadVertices), &quadVertices, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));
	
	glGenFramebuffers(1, &FBO);
	glBindFramebuffer(GL_FRAMEBUFFER, FBO);
	// create a color attachment texture
	
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, texture, 0);
	// create a renderbuffer object for depth and stencil attachment (we won't be sampling these)
	
	glGenRenderbuffers(1, &rbo);
	glBindRenderbuffer(GL_RENDERBUFFER, rbo);
	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, width, height); // use a single renderbuffer object for both a depth AND stencil buffer.
	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, rbo); // now actually attach it
	// now that we actually created the framebuffer and added all attachments we want to check if it is actually complete now
	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
		std::cout << "ERROR::FRAMEBUFFER:: Framebuffer is not complete!" << std::endl;
	glBindFramebuffer(GL_FRAMEBUFFER, 0);


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
	//music->setMinDistance(10.0f);
	back = SoundEngineB->play2D("CityBack1.mp3",GL_TRUE);
	//back->setVolume(0);

	

	music = SoundEngine->play3D("SF_Sound.mp3", irrklang::vec3df(0, 0, 0), true, false, true);
	music->setIsPaused();

	/*SoundEngineB->setListenerPosition(irrklang::vec3df(eye.x, eye.y, eye.z),
		irrklang::vec3df(center.x, center.y, center.z));*/
	SoundEngine->setListenerPosition(irrklang::vec3df(eye.x, eye.y, eye.z),
		irrklang::vec3df(center.x, center.y, center.z));
	glUseProgram(RoadShader);
	projectionLocRoad = glGetUniformLocation(RoadShader, "projection");
	viewLocRoad = glGetUniformLocation(RoadShader, "view");

	glUseProgram(BuildingShader);
	projectionLocBuilding = glGetUniformLocation(BuildingShader, "projection");
	viewLocBuilding = glGetUniformLocation(BuildingShader, "view");

	//glUseProgram(program2);
	//projectionLoc2 = glGetUniformLocation(program2, "projection");
	//viewLoc2 = glGetUniformLocation(program2, "view");
	//campos2 = glGetUniformLocation(program2, "cameraPos");
	
	glUseProgram(program1);
	projectionLoc1 = glGetUniformLocation(program1, "projection");
	viewLoc1 = glGetUniformLocation(program1, "view");

	Window::view = glm::lookAt(Window::eye, Window::center, Window::up);


	return true;
}

bool Window::initializeObjects()
{
	// Create a cube of size 5.
	city = new City();
	city->BuildCity(Gswitch,Tswitch);
	//taxi = new Car(glm::vec3(0.0f , 0.0f, 0.0f), 1.25, 2, 1.25, "BlackRoof.jpg", "BlackRoof.jpg");
	//glm::translate(taximod, glm::vec3(0.0f + 20.0f * 0, 2.5f, -1 * 5.0f - 5.0f * 1));
	skybox = new SkyBox(400.0f);
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
	if (music->getIsPaused()) {
		music->setIsPaused(false);
	}
	glm::vec3 L = city->SF_L->posr;
	float x = L.x;
	float y = L.y;
	float z = L.z;
	/*SoundEngineB->setListenerPosition(irrklang::vec3df(eye.x, eye.y, eye.z),
		irrklang::vec3df(center.x, center.y, center.z));*/
	SoundEngine->setListenerPosition(irrklang::vec3df(eye.x, eye.y, eye.z),
		irrklang::vec3df(center.x, center.y, center.z));
	music->setPosition(irrklang::vec3df(x, -9.0f, z));
	music->setMinDistance(3.0f);
	music->setVolume(50);
	// Perform any updates as necessary. 
	//currentObj->update(glm::mat4(1));
	std::cout << "Pswitch: " << Pswitch << std::endl;
	std::cout << "Cswitch: " << Cswitch << std::endl;
	std::cout << "Tswitch: " << Tswitch << std::endl;
	std::cout << "Gswitch: " << Gswitch << std::endl;
	std::cout << "Lswitch: " << Lswitch << std::endl;
	std::cout << "Eswitch: " << Eswitch << std::endl;
	std::cout << "/////////" << std::endl;
	if (Pswitch) {
		if (movement > 1000) {
			city->update(Gswitch, Tswitch, Cswitch, Lswitch);
			movement = 0;
		}
		movement++;
	}
	if (Fswitch) {
		if (sound1 > 1000) {			
			/*TiredSound = SoundEngineT->play3D("tired.mp3", irrklang::vec3df(eye.x, eye.y, eye.z), true, false, true);
			TiredSound->setVolume(100);
			TiredSound->setIsLooped(false);*/			
			SoundEngineT->play2D("tired.mp3", GL_FALSE);
			sound1 = 0;
		}		
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
	float currentFrame = glfwGetTime();
	deltaTime = currentFrame - lastFrame;
	lastFrame = currentFrame;
	if (Fswitch) {
		eye.y = -8.0f;
	}
	Window::view = glm::lookAt(Window::eye, Window::center + Window::eye, Window::up);
	/*std::vector<plane> PL;
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
	}*/
	

	// first pass
	glBindFramebuffer(GL_FRAMEBUFFER, FBO);
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
	// Clear the color and depth buffers.
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	
	
	glUseProgram(RoadShader);
	glUniformMatrix4fv(projectionLocRoad, 1, GL_FALSE, glm::value_ptr(projection));
	glUniformMatrix4fv(viewLocRoad, 1, GL_FALSE, glm::value_ptr(view));
	city->draw(RoadShader,Cswitch);
	//taxi->draw(RoadShader, taximod);
	//ground->draw(RoadShader);

	glUseProgram(program1);
	// Specify the values of the uniform variables we are going to use.
	glUniformMatrix4fv(projectionLoc1, 1, GL_FALSE, glm::value_ptr(projection));
	glUniformMatrix4fv(viewLoc1, 1, GL_FALSE, glm::value_ptr(view));
	skybox->draw(program1);
	//LightSource->draw();

	// now bind back to default framebuffer and draw a quad plane with the attached framebuffer color texture
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	glDisable(GL_DEPTH_TEST); // disable depth test so screen-space quad isn't discarded due to depth test.
	// clear all relevant buffers
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // set clear color to white (not really necessery actually, since we won't be able to see behind the quad anyways)
	glClear(GL_COLOR_BUFFER_BIT);

	glUseProgram(FBOShader);
	glBindVertexArray(quadVAO);
	glBindTexture(GL_TEXTURE_2D, texture);	// use the color attachment texture as the texture of the quad plane
	glDrawArrays(GL_TRIANGLES, 0, 6);

	// Gets events, including input such as keyboard and mouse or window resizing.
	glfwPollEvents();
	// Swap buffers.
	glfwSwapBuffers(window);
}


void Window::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{

	float dx = 0;
	float dz = 0;
	
	// Check for a key press.
	if (action == GLFW_PRESS || action == GLFW_REPEAT)
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
		/*case GLFW_KEY_W:
			blur = true;
			sound1++;
			dz = 2;
			break;
		case GLFW_KEY_A:
			blur = true;
			sound1++;
			dx = -2;
			break;
		case GLFW_KEY_S:
			blur = true;
			sound1++;
			dz = -2;
			break;
		case GLFW_KEY_D:
			blur = true;
			sound1++;
			dx = 2;
			break;*/
		case GLFW_KEY_LEFT:
			std::cout << "left" << std::endl;
			//track->cpdec();
			break;
		case GLFW_KEY_X:
			if (mods == GLFW_MOD_SHIFT) {
				std::cout << "-x" << std::endl;
				//track->decAxis('X');
			}
			else {
				std::cout << "x" << std::endl;
				//track->incAxis('x');
			}
			break;
		case GLFW_KEY_Y:
			if (mods == GLFW_MOD_SHIFT) {
				std::cout << "-y" << std::endl;
				//track->decAxis('Y');
			}
			else {
				std::cout << "y" << std::endl;
				//track->incAxis('y');
			}
			break;
		case GLFW_KEY_Z:
			if (mods == GLFW_MOD_SHIFT) {
				std::cout << "-z" << std::endl;
				//track->decAxis('Z');
			}
			else {
				std::cout << "z" << std::endl;
				//track->incAxis('z');
			}
			break;
		case GLFW_KEY_F3:
			// Set currentObj to dragon
			//currentObj = dragon;
			//dragon->error();
			break;
		case GLFW_KEY_1:
			// Set currentObj to dragon
			
			break;
		case GLFW_KEY_2:
			// Set currentObj to dragon
			
			break;
		case GLFW_KEY_E:
			// change size
			if (Eswitch == true) {
				Eswitch = false;
			}
			else {
				Eswitch = true;
			}
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
		case GLFW_KEY_M:
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
				//eye = taxi->posb;
				//Window::view = glm::lookAt(Window::eye, Window::center, Window::up);
			}
			else {
				Fswitch = true;
			}
			break;
		case GLFW_KEY_T:
			// change size
			if (Tswitch == true) {
				Tswitch = false;
			}
			else {
				Tswitch = true;
			}
			break;
		case GLFW_KEY_G:
			// change size
			if (Gswitch == true) {
				Gswitch = false;
			}
			else {
				Gswitch = true;
			}
			break;
		case GLFW_KEY_C:
			// change size
			if (Cswitch == true) {
				Cswitch = false;
			}
			else {
				Cswitch = true;
			}
			break;
		case GLFW_KEY_L:
			// change size
			if (Lswitch == true) {
				Lswitch = false;
			}
			else {
				Lswitch = true;
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

		//glm::vec3 forward(view[0][2], view[1][2], view[2][2]);
		//glm::vec3 strafe(view[0][0], view[1][0], view[2][0]);
		//float speed = 0.20f;
		//eye += (-1 * dz*forward + dx * strafe) * speed;
		////glm::translate(taximod, eye);
		//if (Fswitch) {			
		//	eye.y = -8.0f;
		//	//taxi = new Car(eye, 1.25, 2, 1.25, "BlackRoof.jpg", "BlackRoof.jpg");
		//}
		////center += (-1 * dz*forward + dx * strafe) * speed;
		//Window::view = glm::lookAt(Window::eye, Window::center, Window::up);

	}
	else if (action == GLFW_RELEASE) {
		switch (key) {
			case GLFW_KEY_W:
				blur = false;
				break;
			case GLFW_KEY_A:
				blur = false;
				break;
			case GLFW_KEY_S:
				blur = false;
				break;
			case GLFW_KEY_D:
				blur = false;
				break;
		}
	}
	float cameraSpeed = 0.5;
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
		eye += cameraSpeed * center;
		if (Fswitch) {
			sound1++;
		}
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
		eye -= cameraSpeed * center;
		if (Fswitch) {
			sound1++;
		}
	}
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
		eye -= glm::normalize(glm::cross(center, up)) * cameraSpeed;
		if (Fswitch) {
			sound1++;
		}
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
		eye += glm::normalize(glm::cross(center, up)) * cameraSpeed;
		if (Fswitch) {
			sound1++;
		}
	}
	//Window::view = glm::lookAt(Window::eye, Window::center, Window::up);
}

void Window::cursorPos(GLFWwindow* window, double x, double y)
{
	
	//if (LDown == true) {
	//	glm::vec3 lastPos2 = trackBallMapping(glm::vec2(mx, my));
	//	glm::vec3 curPos2 = trackBallMapping(glm::vec2(x, y));
	//	glm::vec3 dir2 = curPos2 - lastPos2;
	//	float vel2 = glm::length(dir2);
	//	if (vel2 > 0.0001) {
	//		glm::vec3 rotAxis = glm::cross(lastPos2, curPos2);
	//		float rotAngle = vel2*30;
	//		
	//		//glm::rotate(taximod, glm::radians(rotAngle), glm::vec3(1.0f, 0.0, 0.0));
	//		//taxi->spin(rotAngle);
	//		glm::mat4 TM = glm::translate(glm::mat4(1.0f),Window::eye);
	//		glm::mat4 TMI = glm::inverse(TM);
	//		glm::vec4 dirv = glm::vec4(center - eye, 0);			
	//		glm::mat4 rotM = glm::rotate(glm::mat4(1.0f),glm::radians(rotAngle), rotAxis);
	//		dirv = TM* dirv;
	//		dirv = rotM* dirv;
	//		dirv = TMI* dirv;
	//		Window::center = (glm::vec3(dirv));
	//		Window::view = glm::lookAt(Window::eye, Window::center + Window::eye, Window::up);
	//					
	//	}
	//	//glm::vec2 mouse_delta = glm::vec2(x, y) - glm::vec2(mx,my);
	//	//float mouseX_Sensitivity = 0.25f;
	//	//float mouseY_Sensitivity = 0.25f;

	//}

	//mx = x;
	//my = y;

	/*if (firstMouse)
	{
		mx = x;
		my = y;
		firstMouse = false;
	}*/
	if (LDown) {
		float xoffset = x - mx;
		float yoffset = my - y;
		mx = x;
		my = y;

		float sensitivity = 0.1;
		xoffset *= sensitivity;
		yoffset *= sensitivity;

		Window::yaw += xoffset;
		Window::pitch += yoffset;

		if (pitch > 89.0f)
			pitch = 89.0f;
		if (pitch < -89.0f)
			pitch = -89.0f;

		glm::vec3 front;
		front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
		front.y = sin(glm::radians(pitch));
		front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
		Window::center = glm::normalize(front);
		//Window::view = glm::lookAt(Window::eye, Window::center, Window::up);
	}
}

void Window::mouseClick(GLFWwindow* window, int button, int action, int mods) {
	if (action == GLFW_PRESS) {
		switch (button) {
			case GLFW_MOUSE_BUTTON_LEFT:
				blur = true;
				glfwGetCursorPos(window, &mx, &my);
				LDown = true;
				break;
		}
	}
	else if (action == GLFW_RELEASE) {
		switch (button) {
			case GLFW_MOUSE_BUTTON_LEFT:
				blur = false;
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

void Window::FBOcallback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}



