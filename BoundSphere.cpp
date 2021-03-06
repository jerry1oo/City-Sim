#include "BoundSphere.h"
#include<fstream>
#include<iostream>
#include<sstream>


GLuint BoundSphere::modelLoc; // Location of model in shader.
GLuint BoundSphere::colorLoc; // Location of color in shader.
GLuint BoundSphere::cubemapTexture;

GLuint BoundSphere::MatAmbi;
GLuint BoundSphere::MatDiff;
GLuint BoundSphere::Matspec;
GLuint BoundSphere::Matshine;

glm::vec3 BoundSphere::boundCenter;
double BoundSphere::boundRadius;

BoundSphere::BoundSphere(std::string objFilename, GLfloat pointSize, GLuint tex)
	: pointSize(pointSize)
{
	cubemapTexture = tex;
	/////File Read In///////
	std::ifstream objFile(objFilename);

	// Check whether the file can be opened.
	if (objFile.is_open())
	{
		std::string line; // A line in the file.

		// Read lines from the file.
		while (std::getline(objFile, line))
		{
			// Turn the line into a string stream for processing.
			std::stringstream ss;
			ss << line;

			// Read the first word of the line.
			std::string label;
			ss >> label;

			// If the line is about vertex (starting with a "v").
			if (label == "v")
			{
				// Read the later three float numbers and use them as the 
				// coordinates.
				glm::vec3 point;
				ss >> point.x >> point.y >> point.z;

				// Process the point. For example, you can save it to a.
				points.push_back(point);
			}

			else if (label == "vn")
			{
				// Read the later three float numbers and use them as the 
				// coordinates.
				glm::vec3 normal;
				ss >> normal.x >> normal.y >> normal.z;

				// Process the point. For example, you can save it to a.
				normals.push_back(normal);
			}

			else if (label == "f")
			{
				// Read the later three float numbers and use them as the 
				// coordinates.

				glm::ivec3 triangle;
				glm::ivec3 temp;
				char temp1 = 0;
				char temp2 = 0;
				char temp3 = 0;
				char temp4 = 0;
				char temp5 = 0;
				char temp6 = 0;
				char temp7 = 0;
				char temp8 = 0;

				ss >> triangle.x >> temp1 >> temp2 >> temp.x >> triangle.y >> temp4 >> temp5 >> temp.y >> triangle.z >> temp6 >> temp7 >> temp.z;
				glm::ivec3 tempi = { 1, 1, 1 };
				triangle = triangle - tempi;
				// Process the point. For example, you can save it to a.
				indicesV.push_back(triangle);

			}
		}
		
	}
	else{
		std::cerr << "Can't open the file " << objFilename << std::endl;
	}

	objFile.close();
	/////File Read In///////



	///////////Centering points////////////
	GLfloat max_x = points[0].x;
	GLfloat max_y = points[0].y;
	GLfloat max_z = points[0].z;
	GLfloat min_x = points[0].x;
	GLfloat min_y = points[0].y;
	GLfloat min_z = points[0].z;
	for (int i = 0; i < points.size(); i++) {
		if (points[i].x < min_x) { min_x = points[i].x; }
		if (points[i].x > max_x) { max_x = points[i].x; }
		if (points[i].y < min_y) { min_y = points[i].y; }
		if (points[i].y > max_y) { max_y = points[i].y; }
		if (points[i].z < min_z) { min_z = points[i].z; }
		if (points[i].z > max_z) { max_z = points[i].z; }
	}
	float m_x = (min_x + max_x) / 2.0f;
	float m_y = (min_y + max_y) / 2.0f;
	float m_z = (min_z + max_z) / 2.0f;
	glm::vec3 c = { m_x, m_y, m_z };

	for (int i = 0; i < points.size(); i++) {
		points[i] = points[i] - c;
	}
	///////////Centering points////////////

	

	///////////Scaleing points/////////////
	scale = 1;
	GLfloat max_l = 0;

	for (int i = 0; i < points.size(); i++) {
		GLfloat mag = (sqrt(points[i].x*points[i].x + points[i].y * points[i].y + points[i].z * points[i].z));
		if (mag > max_l) {
			max_l = mag;
		}
	}
	if ((max_l*scale) < 10) {
		while ((max_l*scale) < 10) { scale = scale * 1.05; }
	}
	else {
		while ((max_l*scale) > 10) { scale = scale * .99; }
	}
	/*for (int i = 0; i < points.size(); i++) {
		points[i] = points[i] * scale;
	}*/
	///////////Scaleing points/////////////









	// Set the model matrix to an identity matrix. 
	model = glm::mat4(1);
	//model = glm::translate(c);
	//model = glm::scale(glm::vec3(scale));

	// Set the color. 
	color = glm::vec3(1, 0, 0);

	// Generate a vertex array (VAO) and a vertex buffer objects (VBO).
	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vboV);
	glGenBuffers(1, &vboN);
	glGenBuffers(1, &ebo);

	// Bind to the VAO.
	glBindVertexArray(vao);

	// Bind to the first VBO. We will use it to store the points.
	glBindBuffer(GL_ARRAY_BUFFER, vboV);
	// Pass in the data.
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * points.size(),
		points.data(), GL_STATIC_DRAW);
	// Enable vertex attribute 0. 
	// We will be able to access points through it.
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), 0);

	// Bind to the second VBO. We will use it to store the indices.
	glBindBuffer(GL_ARRAY_BUFFER, vboN);
	// Pass in the data.
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * normals.size(),
		normals.data(), GL_STATIC_DRAW);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), 0);

	// Bind to the first EBO. We will use it to store the faces.
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	// Pass in the data.
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(glm::ivec3) * indicesV.size(),
		indicesV.data(), GL_STATIC_DRAW);

	// Unbind from the VBO.
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	// Unbind from the VAO.
	glBindVertexArray(0);
}

BoundSphere::~BoundSphere()
{
	// Delete the VBO and the VAO.
	glDeleteBuffers(1, &vboV);
	glDeleteBuffers(1, &vboN);
	glDeleteBuffers(1, &ebo);
	glDeleteVertexArrays(1, &vao);
}

void BoundSphere::draw(GLuint shaderProgram, glm::mat4 C, bool bound, bool Frustum,std::vector<plane> P, int &count)
{
	model = C;

	modelLoc = glGetUniformLocation(shaderProgram, "model");
	//colorLoc = glGetUniformLocation(shaderProgram, "color");

	//MatAmbi = glGetUniformLocation(shaderProgram, "material.ambient");
	//MatDiff = glGetUniformLocation(shaderProgram, "material.diffuse");
	//Matspec = glGetUniformLocation(shaderProgram, "material.specular");
	//Matshine = glGetUniformLocation(shaderProgram, "material.shininess");
	
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
	//glUniform3fv(colorLoc, 1, glm::value_ptr(color));


	//glUniform3fv(MatAmbi, 1, glm::value_ptr(material.ambient));
	//glUniform3fv(MatDiff, 1, glm::value_ptr(material.diffuse));
	//glUniform3fv(Matspec, 1, glm::value_ptr(material.specular));
	//glUniform1f(Matshine, material.shininess);



	// Bind to the VAO.
	glBindVertexArray(vao);
	glBindTexture(GL_TEXTURE_CUBE_MAP, cubemapTexture);
	// Set point size.
	glPointSize(pointSize);
	// Draw points 
	glDrawElements(GL_TRIANGLES, indicesV.size() * 3, GL_UNSIGNED_INT, 0);;
	// Unbind from the VAO.
	glBindVertexArray(0);
}

void BoundSphere::update(glm::mat4 C)
{
	
}

void BoundSphere::updatePointSize(GLfloat size)
{
	if (size == 1) {
		pointSize++;
	}
	else {
		pointSize--;
	}
}

void BoundSphere::Rotating(float deg, glm::vec3 rotAxis)
{
	// Update the model matrix by multiplying a rotation matrix
	glm::mat4 tempM = model;
	model = glm::mat4(1);
	model = glm::rotate(glm::radians(deg), rotAxis);
	model = model * tempM;
}

void BoundSphere::error()
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; i++) {
			std::cerr << model[j][i] << " ";
		}	
		std::cerr << std::endl;
	}
	std::cerr << std::endl;
}

void BoundSphere::Scaleing(float scaler, double y)
{
	// Update the model matrix by multiplying a scaling matrix
	scale = 1;
	scale += (scaler*y)*scale;
	glm::mat4 tempM = model;
	model = glm::mat4(1);
	model = glm::scale(glm::vec3(scale));
	model = model * tempM;
}