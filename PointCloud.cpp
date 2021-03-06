#include "PointCloud.h"
#include<fstream>
#include<iostream>
#include<sstream>

PointCloud::PointCloud(std::string objFilename, GLfloat pointSize) 
	: pointSize(pointSize)
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
		}
	}
	else
	{
		std::cerr << "Can't open the file " << objFilename << std::endl;
	}

	objFile.close();
	/////File Read In///////
	
	
	
	///////////Centering////////////
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

	for (int i = 0; i < points.size();i++) {
		points[i] = points[i] - c;
	}
	///////////Centering////////////

	///////////Scaleing/////////////
	GLfloat scale = 1;
	GLfloat max_l = 0;

	for (int i = 0; i < points.size(); i++) {
		GLfloat mag = (sqrt(points[i].x*points[i].x + points[i].y * points[i].y + points[i].z * points[i].z));
		if (mag > max_l) { 
			max_l = mag; 
		}
	}
	if((max_l*scale) < 10){
		while ((max_l*scale) < 10) { scale = scale * 1.05; }
	}
	else {
		while ((max_l*scale) > 10) { scale = scale * .99; }
	}
	for (int i = 0; i < points.size(); i++) {
		points[i] = points[i] * scale;
	}
	///////////Scaleing/////////////


	

	// Set the model matrix to an identity matrix. 
	model = glm::mat4(1);
	// Set the color. 
	color = glm::vec3(1, 0, 0);

	// Generate a vertex array (VAO) and a vertex buffer objects (VBO).
	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);

	// Bind to the VAO.
	glBindVertexArray(vao);

	// Bind to the first VBO. We will use it to store the points.
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	// Pass in the data.
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * points.size(),
		points.data(), GL_STATIC_DRAW);
	// Enable vertex attribute 0. 
	// We will be able to access points through it.
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), 0);

	// Unbind from the VBO.
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	// Unbind from the VAO.
	glBindVertexArray(0);
}

PointCloud::~PointCloud() 
{
	// Delete the VBO and the VAO.
	glDeleteBuffers(1, &vbo);
	glDeleteVertexArrays(1, &vao);
}

void PointCloud::draw()
{
	// Bind to the VAO.
	glBindVertexArray(vao);
	// Set point size.
	glPointSize(pointSize);
	// Draw points 
	glDrawArrays(GL_POINTS, 0, points.size());
	// Unbind from the VAO.
	glBindVertexArray(0);
}

void PointCloud::update()
{
	// Spin the cube by 1 degree.
	spin(0.1f);
}

void PointCloud::updatePointSize(GLfloat size) 
{
	if (size == 1) {
		pointSize++;
	}
	else {
		pointSize--;
	}
}

void PointCloud::spin(float deg)
{
	// Update the model matrix by multiplying a rotation matrix
	model = glm::rotate(model, glm::radians(deg), glm::vec3(0.0f, 1.0f, 0.0f));
}

