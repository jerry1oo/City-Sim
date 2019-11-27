#include "Geometry.h"
#include<fstream>
#include<iostream>
#include<sstream>

//glm::vec3 Geometry::boundCenter;
//double Geometry::boundRadius;

GLuint Geometry::modelLoc; // Location of model in shader.
GLuint Geometry::colorLoc; // Location of color in shader.

GLuint Geometry::MatAmbi;
GLuint Geometry::MatDiff;
GLuint Geometry::Matspec;
GLuint Geometry::Matshine;

Geometry::Geometry(std::string objFilename, GLfloat pointSize, Material M)
	: pointSize(pointSize), material(M)
{

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

				glm::ivec3 V;
				glm::ivec3 VT;
				glm::ivec3 VN;
				char temp1 = 0;
				char temp2 = 0;
				char temp3 = 0;
				char temp4 = 0;
				char temp5 = 0;
				char temp6 = 0;
				char temp7 = 0;
				char temp8 = 0;
				char temp9 = 0;
				char temp10 = 0;
				char temp11 = 0;
				char temp12 = 0;
				
				ss >> V.x >> temp1 >> VT.x >> temp3 >> VN.x >> V.y >> temp5 >> VT.y >> temp7 >> VN.y >> V.z >> temp9 >> VT.z >> temp11 >> VN.z;
				glm::ivec3 tempi = { 1, 1, 1 };
				V = V - tempi;
				VN = VN - tempi;
				VT = VT - tempi;
				// Process the point. For example, you can save it to a.
				indicesV.push_back(V);
				indicesN.push_back(VN);
				indicesT.push_back(VT);

			}
		}
		for (unsigned i = 0; i < indicesV.size(); i++) {
			vertices_.push_back(points[indicesV[i].x]);
			vertices_.push_back(points[indicesV[i].y]);
			vertices_.push_back(points[indicesV[i].z]);
			normals_.push_back(normals[indicesN[i].x]);
			normals_.push_back(normals[indicesN[i].y]);
			normals_.push_back(normals[indicesN[i].z]);			
			indices_.push_back(3*i);
			indices_.push_back(3*i+1);
			indices_.push_back(3*i+2);
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
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * vertices_.size(),
		vertices_.data(), GL_STATIC_DRAW);
	// Enable vertex attribute 0. 
	// We will be able to access points through it.
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), 0);

	// Bind to the second VBO. We will use it to store the indices.
	glBindBuffer(GL_ARRAY_BUFFER, vboN);
	// Pass in the data.
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * normals_.size(),
		normals_.data(), GL_STATIC_DRAW);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), 0);

	// Bind to the first EBO. We will use it to store the faces.
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	// Pass in the data.
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * indices_.size(),
		indices_.data(), GL_STATIC_DRAW);

	// Unbind from the VBO.
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	// Unbind from the VAO.
	glBindVertexArray(0);
}

Geometry::~Geometry()
{
	// Delete the VBO and the VAO.
	glDeleteBuffers(1, &vboV);
	glDeleteBuffers(1, &vboN);
	glDeleteBuffers(1, &ebo);
	glDeleteVertexArrays(1, &vao);
}

void Geometry::draw(GLuint shaderProgram, glm::mat4 C, bool bound, bool Frustum, std::vector<plane> P, int &count)
{
	model = C;

	modelLoc = glGetUniformLocation(shaderProgram, "model");
	colorLoc = glGetUniformLocation(shaderProgram, "color");

	MatAmbi = glGetUniformLocation(shaderProgram, "material.ambient");
	MatDiff = glGetUniformLocation(shaderProgram, "material.diffuse");
	Matspec = glGetUniformLocation(shaderProgram, "material.specular");
	Matshine = glGetUniformLocation(shaderProgram, "material.shininess");
	
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
	glUniform3fv(colorLoc, 1, glm::value_ptr(color));


	glUniform3fv(MatAmbi, 1, glm::value_ptr(material.ambient));
	glUniform3fv(MatDiff, 1, glm::value_ptr(material.diffuse));
	glUniform3fv(Matspec, 1, glm::value_ptr(material.specular));
	glUniform1f(Matshine, material.shininess);



	// Bind to the VAO.
	glBindVertexArray(vao);
	// Set point size.
	glPointSize(pointSize);
	// Draw points 
	glDrawElements(GL_TRIANGLES, indices_.size(), GL_UNSIGNED_INT, 0);;
	// Unbind from the VAO.
	glBindVertexArray(0);
}

void Geometry::update(glm::mat4 C)
{
	
}

void Geometry::updatePointSize(GLfloat size)
{
	if (size == 1) {
		pointSize++;
	}
	else {
		pointSize--;
	}
}

void Geometry::Rotating(float deg, glm::vec3 rotAxis)
{
	// Update the model matrix by multiplying a rotation matrix
	glm::mat4 tempM = model;
	model = glm::mat4(1);
	model = glm::rotate(glm::radians(deg), rotAxis);
	model = model * tempM;
}

void Geometry::error()
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; i++) {
			std::cerr << model[j][i] << " ";
		}	
		std::cerr << std::endl;
	}
	std::cerr << std::endl;
}

void Geometry::Scaleing(float scaler, double y)
{
	// Update the model matrix by multiplying a scaling matrix
	scale = 1;
	scale += (scaler*y)*scale;
	glm::mat4 tempM = model;
	model = glm::mat4(1);
	model = glm::scale(glm::vec3(scale));
	model = model * tempM;
}
