#include "Bezier.h"



Bezier::Bezier(glm::vec3 p_0, glm::vec3 p_1, glm::vec3 p_2, glm::vec3 p_3) {
	model = glm::mat4(1.0f);
	color = glm::vec3(1.0f, 0.0f, 0.0f);
	p0 = p_0;
	p1 = p_1;
	p2 = p_2;
	p3 = p_3;
	cpoints.push_back(p0);
	cpoints.push_back(p1);
	cpoints.push_back(p2);
	cpoints.push_back(p3);
	//preConsts();
	for (int i = 0; i <= 150; i++) {
		float t = i * (1.0F / 150.0F);
		glm::vec3 sp = curvepoint(t);
		spoints.push_back(sp);
	}

	glGenVertexArrays(1, &vaoP);
	glGenBuffers(1, &vboP);

	// Bind to the VAO.
	glBindVertexArray(vaoP);

	// Bind to the first VBO. We will use it to store the points.
	glBindBuffer(GL_ARRAY_BUFFER, vboP);
	// Pass in the data.
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * cpoints.size(),
		cpoints.data(), GL_STATIC_DRAW);
	// Enable vertex attribute 0. 
	// We will be able to access points through it.
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), 0);

	/////////////

	glGenVertexArrays(1, &vaoS);
	glGenBuffers(1, &vboS);

	// Bind to the VAO.
	glBindVertexArray(vaoS);

	// Bind to the first VBO. We will use it to store the points.
	glBindBuffer(GL_ARRAY_BUFFER, vboS);
	// Pass in the data.
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * spoints.size(),
		spoints.data(), GL_STATIC_DRAW);
	// Enable vertex attribute 0. 
	// We will be able to access points through it.
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), 0);

	// Unbind from the VBO.
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	// Unbind from the VAO.
	glBindVertexArray(0);
}
Bezier::~Bezier() {

}

void Bezier::update() {
	//std::cout << "here1" << std::endl;
	cpoints.clear();
	cpoints.push_back(p0);
	cpoints.push_back(p1);
	cpoints.push_back(p2);
	cpoints.push_back(p3);
	//preConsts();
	spoints.clear();
	for (int i = 0; i <= 150; i++) {
		float t = i * (1.0F / 150.0F);
		glm::vec3 sp = curvepoint(t);
		spoints.push_back(sp);
	}
	//std::cout << "here2" << std::endl;

	glGenVertexArrays(1, &vaoP);
	glGenBuffers(1, &vboP);

	// Bind to the VAO.
	glBindVertexArray(vaoP);

	// Bind to the first VBO. We will use it to store the points.
	glBindBuffer(GL_ARRAY_BUFFER, vboP);
	// Pass in the data.
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * cpoints.size(),
		cpoints.data(), GL_STATIC_DRAW);
	// Enable vertex attribute 0. 
	// We will be able to access points through it.
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), 0);

	// Unbind from the VBO.
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	// Unbind from the VAO.
	glBindVertexArray(0);

	//////

	glGenVertexArrays(1, &vaoS);
	glGenBuffers(1, &vboS);

	// Bind to the VAO.
	glBindVertexArray(vaoS);

	// Bind to the first VBO. We will use it to store the points.
	glBindBuffer(GL_ARRAY_BUFFER, vboS);
	// Pass in the data.
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * spoints.size(),
		spoints.data(), GL_STATIC_DRAW);
	// Enable vertex attribute 0. 
	// We will be able to access points through it.
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), 0);

	// Unbind from the VBO.
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	// Unbind from the VAO.
	glBindVertexArray(0);
}

glm::vec3 Bezier::Lerp(glm::vec3 P0, glm::vec3 P1, float t) {
	return ((1.0f - t)*P0 + t * P1);
}


glm::vec3 Bezier::curvepoint(float t) {

	glm::vec3 q0 = Lerp(p0, p1, t);
	glm::vec3 q1 = Lerp(p1, p2, t);
	glm::vec3 q2 = Lerp(p2, p3, t);

	glm::vec3 r0 = Lerp(q0, q1, t);
	glm::vec3 r1 = Lerp(q1, q2, t);

	glm::vec3 x = Lerp(r0, r1, t);
	return x;

}

void Bezier::draw(GLuint shaderProgram,int pos) {

	modelLoc = glGetUniformLocation(shaderProgram, "model");
	colorLoc = glGetUniformLocation(shaderProgram, "color");
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
	glUniform3fv(colorLoc, 1, glm::value_ptr(glm::vec3(0.0f, 0.0f, 0.0f)));

	 //Bind to the VAO.
	glBindVertexArray(vaoS);
	// Draw points 
	glLineWidth(5.0f);
	glDrawArrays(GL_LINE_STRIP, 0, spoints.size());
	//std::cout << "point Size" << spoints.size()  << std::endl;
	// Unbind from the VAO.
	glBindVertexArray(0);

	glUniform3fv(colorLoc, 1, glm::value_ptr(glm::vec3(1.0f, 0.0f, 0.0f)));

	// Bind to the VAO.
	glBindVertexArray(vaoP);
	glPointSize(20.0f);
	// Draw points 
	glUniform3fv(colorLoc, 1, glm::value_ptr(glm::vec3(1.0f, 0.0f, 0.0f)));
	if (pos == 0) {
		glUniform3fv(colorLoc, 1, glm::value_ptr(glm::vec3(0.0f, 0.0f, 1.0f)));
	}
	glDrawArrays(GL_POINTS, 0, 1);
	glUniform3fv(colorLoc, 1, glm::value_ptr(glm::vec3(1.0f, 0.0f, 0.0f)));
	if (pos == 3) {
		glUniform3fv(colorLoc, 1, glm::value_ptr(glm::vec3(0.0f, 0.0f, 1.0f)));
	}
	glDrawArrays(GL_POINTS, 3, 1);
	glUniform3fv(colorLoc, 1, glm::value_ptr(glm::vec3(0.0f, 1.0f, 0.0f)));
	if (pos == 1) {
		glUniform3fv(colorLoc, 1, glm::value_ptr(glm::vec3(0.0f, 0.0f, 1.0f)));
	}
	glDrawArrays(GL_POINTS, 1, 1);
	glUniform3fv(colorLoc, 1, glm::value_ptr(glm::vec3(0.0f, 1.0f, 0.0f)));
	if (pos == 2) {
		glUniform3fv(colorLoc, 1, glm::value_ptr(glm::vec3(0.0f, 0.0f, 1.0f)));
	}
	glDrawArrays(GL_POINTS, 2, 1);
	glUniform3fv(colorLoc, 1, glm::value_ptr(glm::vec3(1.0f, 1.0f, 0.0f)));
	glDrawArrays(GL_LINE_STRIP, 0, 2);
	glDrawArrays(GL_LINE_STRIP, 2, 2);
	// Unbind from the VAO.
	glBindVertexArray(0);


}

glm::vec3 Bezier::GetPoint(int t) {
	return spoints[t];
}
