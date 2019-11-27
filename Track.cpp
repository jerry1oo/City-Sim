#include "Track.h"


Track::Track() {

	cp = 0;
	curve = 0;
	curvepos = 0;
	for (int i = 0; i < 360; i += 360 / 24)
	{
		float rad = (i / 180.0f * glm::pi<float>());//Convert to radians.
		glm::vec3 point = glm::vec3(15 * sin(rad), fmod(i, 8.0f) - 10.0f, 15 * cos(rad) + 20.0f);
		points.push_back(point);
	}
	points[24] = points[0];

	
	for (int i = 0; i < 8; i++)	{
		Bezier curve = Bezier(points[3 * i], points[(3 * i) + 1], points[(3 * i) + 2], points[(3 * i) + 3]);
		curves.push_back(curve);
	}
	for (int i = 1; i < curves.size()-1; i++)	{		
		glm::vec3 edge = curves[i].p1 - curves[i].p0;
		glm::vec3 other = curves[i-1].p3;
		curves[i-1].p2 = other - edge;
		curves[i-1].update();

		glm::vec3 edge1 = curves[i].p2 - curves[i].p3;
		glm::vec3 other1 = curves[i + 1].p0;
		curves[i + 1].p1 = other1 - edge1;
		curves[i + 1].update();
	}

	glm::vec3 edge = curves[0].p1 - curves[0].p0;
	glm::vec3 other = curves[7].p3;
	curves[7].p2 = other - edge;
	curves[7].update();

	glm::vec3 edge1 = curves[0].p2 - curves[0].p3;
	glm::vec3 other1 = curves[1].p0;
	curves[1].p1 = other1 - edge1;
	curves[1].update();
}
Track::~Track() {

}

void Track::C1() {
	int index = ceil(cp / 4);
	int pos = cp % 4;

	if (index > 0 && index < 7) {

		if (pos == 0) {
			glm::vec3 edge = curves[index].p1 - curves[index].p0;
			glm::vec3 other = curves[index - 1].p3;
			curves[index - 1].p2 = other - edge;
			curves[index - 1].update();

			//glm::vec3 edge1 = curves[index].p2 - curves[index].p3;
			//glm::vec3 other1 = curves[index + 1].p0;
			//curves[index + 1].p2 = other1 - edge1;
			//curves[index + 1].update();
		}
		else if (pos == 1) {
			glm::vec3 edge = curves[index].p1 - curves[index].p0;
			glm::vec3 other = curves[index - 1].p3;
			curves[index - 1].p2 = other - edge;
			curves[index - 1].update();

			//glm::vec3 edge1 = curves[index].p2 - curves[index].p3;
			//glm::vec3 other1 = curves[index + 1].p0;
			//curves[index + 1].p2 = other1 - edge1;
			//curves[index + 1].update();
		}
		else if (pos == 2) {
			/*glm::vec3 edge = curves[index].p1 - curves[index].p0;
			glm::vec3 other = curves[index - 1].p3;
			curves[index - 1].p2 = other - edge;
			curves[index - 1].update();*/

			glm::vec3 edge1 = curves[index].p2 - curves[index].p3;
			glm::vec3 other1 = curves[index + 1].p0;
			curves[index + 1].p1 = other1 - edge1;
			curves[index + 1].update();
		}
		else if (pos == 3) {
			//glm::vec3 edge = curves[index].p1 - curves[index].p0;
			//glm::vec3 other = curves[index - 1].p3;
			//curves[index - 1].p2 = other - edge;
			//curves[index - 1].update();

			glm::vec3 edge1 = curves[index].p2 - curves[index].p3;
			glm::vec3 other1 = curves[index + 1].p0;
			curves[index + 1].p1 = other1 - edge1;
			curves[index + 1].update();
		}
	}
	else if (index <= 0) {
		if (pos == 0) {
			glm::vec3 edge = curves[index].p1 - curves[index].p0;
			glm::vec3 other = curves[7].p3;
			curves[7].p2 = other - edge;
			curves[7].update();

			//glm::vec3 edge1 = curves[index].p2 - curves[index].p3;
			//glm::vec3 other1 = curves[index + 1].p0;
			//curves[index + 1].p1 = other1 - edge1;
			//curves[index + 1].update();
		}
		else if (pos == 1) {
			glm::vec3 edge = curves[index].p1 - curves[index].p0;
			glm::vec3 other = curves[7].p3;
			curves[7].p2 = other - edge;
			curves[7].update();

			//glm::vec3 edge1 = curves[index].p2 - curves[index].p3;
			//glm::vec3 other1 = curves[index + 1].p0;
			//curves[index + 1].p1 = other1 - edge1;
			//curves[index + 1].update();
		}
		else if (pos == 2) {
			/*glm::vec3 edge = curves[index].p1 - curves[index].p0;
			glm::vec3 other = curves[index - 1].p3;
			curves[index - 1].p2 = other - edge;
			curves[index - 1].update();*/

			glm::vec3 edge1 = curves[index].p2 - curves[index].p3;
			glm::vec3 other1 = curves[index + 1].p0;
			curves[index + 1].p1 = other1 - edge1;
			curves[index + 1].update();
		}
		else if (pos == 3) {
			//glm::vec3 edge = curves[index].p1 - curves[index].p0;
			//glm::vec3 other = curves[7].p3;
			//curves[7].p1 = other - edge;
			//curves[7].update();

			glm::vec3 edge1 = curves[index].p2 - curves[index].p3;
			glm::vec3 other1 = curves[index + 1].p0;
			curves[index + 1].p1 = other1 - edge1;
			curves[index + 1].update();
		}
	}
	else if (index >= 7) {
		if (pos == 0) {
			glm::vec3 edge = curves[index].p1 - curves[index].p0;
			glm::vec3 other = curves[index - 1].p3;
			curves[index - 1].p2 = other - edge;
			curves[index - 1].update();

			//glm::vec3 edge1 = curves[index].p2 - curves[index].p3;
			//glm::vec3 other1 = curves[0].p0;
			//curves[0].p1 = other1 - edge1;
			//curves[0].update();
		}
		else if (pos == 1) {
			glm::vec3 edge = curves[index].p1 - curves[index].p0;
			glm::vec3 other = curves[index - 1].p3;
			curves[index - 1].p2 = other - edge;
			curves[index - 1].update();

			//glm::vec3 edge1 = curves[index].p2 - curves[index].p3;
			//glm::vec3 other1 = curves[0].p0;
			//curves[0].p1 = other1 - edge1;
			//curves[0].update();
		}
		else if (pos == 2) {
			/*glm::vec3 edge = curves[index].p1 - curves[index].p0;
			glm::vec3 other = curves[index - 1].p3;
			curves[index - 1].p2 = other - edge;
			curves[index - 1].update();*/

			glm::vec3 edge1 = curves[index].p2 - curves[index].p3;
			glm::vec3 other1 = curves[0].p0;
			curves[0].p1 = other1 - edge1;
			curves[0].update();
		}
		else if (pos == 3) {
			//glm::vec3 edge = curves[index].p1 - curves[index].p0;
			//glm::vec3 other = curves[index - 1].p3;
			//curves[index - 1].p1 = other - edge;
			//curves[index - 1].update();

			glm::vec3 edge1 = curves[index].p2 - curves[index].p3;
			glm::vec3 other1 = curves[0].p0;
			curves[0].p1 = other1 - edge1;
			curves[0].update();
		}
	}

}

void Track::cpinc() {
	if (cp >= 31) {
		cp = 0;
	}
	else {
		cp++;
	}
	std::cout << cp << std::endl;
}
void Track::cpdec() {
	if (cp <= 0) {
		cp = 31;
	}
	else {
		cp--;
	}
	std::cout << cp << std::endl;
}

void Track::draw(GLuint shaderProgram) {
	int index = ceil(cp / 4);
	int pos = cp % 4;
	for (int i = 0; i < curves.size(); i++) {
		curves[i].draw(shaderProgram, -1);
	}
	curves[index].draw(shaderProgram, pos);

}

void Track::trackup() {
	std::cout << curve << std::endl;
	curve++;
	if (curve == 8) {
		curve = 0;
	}
}
void Track::trackposup() {
	//std::cout << curvepos << std::endl;
	if (curvepos == 150) {
		trackup();
		curvepos = 0;
	}
	else {
		curvepos++;
	}
}

glm::vec3 Track::getpos() {
	return curves[curve].GetPoint(curvepos);
}

void Track::incAxis(char a) {
	int index = ceil(cp / 4);
	int pos = cp % 4;
	float scale = 0.5f;
	glm::vec3 incx = glm::vec3(scale*1.0f, 0.0f, 0.0f);
	glm::vec3 incy = glm::vec3(0.0f, scale*1.0f, 0.0f);
	glm::vec3 incz = glm::vec3(0.0f, 0.0f, scale*1.0f);
	if (pos == 0) {
		std::cout << 0 << std::endl;
		if (a == 'x') {
			curves[index].p0 = curves[index].p0 + incx;
			if (index > 0) {
				curves[index - 1].p3 = curves[index - 1].p3 + incx;
			}
			else {
				curves[7].p3 = curves[7].p3 + incx;
			}
		}
		if (a == 'y') {
			curves[index].p0 = curves[index].p0 + incy;
			if (index > 0) {
				curves[index - 1].p3 = curves[index - 1].p3 + incy;
			}
			else {
				curves[7].p3 = curves[7].p3 + incy;
			}
		}
		if (a == 'z') {
			curves[index].p0 = curves[index].p0 + incz;
			if (index > 0){
				curves[index - 1].p3 = curves[index - 1].p3 + incz;
			}
			else {
				curves[7].p3 = curves[7].p3 + incz;
			}
		}
	}
	else if (pos == 1) {
		std::cout << 1 << std::endl;
		if (a == 'x') {
			curves[index].p1 = curves[index].p1 + incx;
		}
		if (a == 'y') {
			curves[index].p1 = curves[index].p1 + incy;
		}
		if (a == 'z') {
			curves[index].p1 = curves[index].p1 + incz;
		}
	}
	else if (pos == 2) {
		if (a == 'x') {
			std::cout << "x" << 2 << std::endl;
			curves[index].p2 = curves[index].p2 + incx;
		}
		if (a == 'y') {
			std::cout << "y" << 2 << std::endl;
			curves[index].p2 = curves[index].p2 + incy;
		}
		if (a == 'z') {
			std::cout << "z" << 2 << std::endl;
			curves[index].p2 = curves[index].p2 + incz;
		}
		curves[index].update();
	}

	else if (pos == 3) {
		std::cout << 3 << std::endl;
		if (a == 'x') {
			curves[index].p3 = curves[index].p3 + incx;
			if (index < 7) {
				curves[index + 1].p0 = curves[index + 1].p0 + incx;
			}
			else {
				curves[0].p0 = curves[0].p0 + incx;
			}
		}
		if (a == 'y') {
			curves[index].p3 = curves[index].p3 + incy;
			if (index < 7) {
				curves[index + 1].p0 = curves[index + 1].p0 + incy;
			}
			else {
				curves[0].p0 = curves[0].p0 + incy;
			}
		}
		if (a == 'z') {
			curves[index].p3 = curves[index].p3 + incz;
			if (index < 7) {
				curves[index + 1].p0 = curves[index + 1].p0 + incz;
			}
			else {
				curves[0].p0 = curves[0].p0 + incz;
			}
		}
	}
	C1();
	for (int i = 0; i < curves.size(); i++)
	{
		curves[i].update();
	}
}
void Track::decAxis(char a) {
	int index = ceil(cp / 4);
	int pos = cp % 4;
	float scale = 0.5f;
	glm::vec3 decx = glm::vec3(scale*1.0f, 0.0f, 0.0f);
	glm::vec3 decy = glm::vec3(0.0f, scale*1.0f, 0.0f);
	glm::vec3 decz = glm::vec3(0.0f, 0.0f, scale*1.0f);
	if (pos == 0) {
		if (a == 'X') {
			curves[index].p0 = curves[index].p0 - decx;
			if (index > 0) {
				curves[index - 1].p3 = curves[index - 1].p3 - decx;
			}
			else {
				curves[7].p3 = curves[7].p3 - decx;
			}
		}
		if (a == 'Y') {
			curves[index].p0 = curves[index].p0 - decy;
			if (index > 0) {
				curves[index - 1].p3 = curves[index - 1].p3 - decy;
			}
			else {
				curves[7].p3 = curves[7].p3 - decy;
			}
		}
		if (a == 'Z') {
			curves[index].p0 = curves[index].p0 - decz;
			if (index > 0) {
				curves[index - 1].p3 = curves[index - 1].p3 - decz;
			}
			else {
				curves[7].p3 = curves[7].p3 - decz;
			}
		}
	}
	else if (pos == 1) {
		if (a == 'X') {
			curves[index].p1 = curves[index].p1 - decx;
		}
		if (a == 'Y') {
			curves[index].p1 = curves[index].p1 - decy;
		}
		if (a == 'Z') {
			curves[index].p1 = curves[index].p1 - decz;
		}
	}
	else if (pos == 2) {
		if (a == 'X') {
			curves[index].p2 = curves[index].p2 - decx;
		}
		if (a == 'Y') {
			curves[index].p2 = curves[index].p2 - decy;
		}
		if (a == 'Z') {
			curves[index].p2 = curves[index].p2 - decz;
		}
	}

	else if (pos == 3) {
		if (a == 'X') {
			curves[index].p3 = curves[index].p3 - decx;
			if (index < 7) {
				curves[index + 1].p0 = curves[index + 1].p0 - decx;
			}
			else {
				curves[0].p0 = curves[0].p0 - decx;
			}
		}
		if (a == 'X') {
			curves[index].p3 = curves[index].p3 - decy;
			if (index < 7) {
				curves[index + 1].p0 = curves[index + 1].p0 - decy;
			}
			else {
				curves[0].p0 = curves[0].p0 - decy;
			}
		}
		if (a == 'Z') {
			curves[index].p3 = curves[index].p3 - decz;
			if (index < 7) {
				curves[index + 1].p0 = curves[index + 1].p0 - decz;
			}
			else {
				curves[0].p0 = curves[0].p0 - decz;
			}
		}
	}
	C1();
	for (int i = 0; i < curves.size(); i++)
	{
		curves[i].update();
	}

}

