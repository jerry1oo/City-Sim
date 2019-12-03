#include "Ground.h"


Ground::Ground(glm::vec3 pos1, float l, float w, bool m)
{
	model = glm::mat4(1.0f);
	color = glm::vec3(0.0f, 1.0f, 0.0f);
	length = l;
	width = w;
	posr = pos1;
	if (m) {
		float minX = posr.x - (width / 2.0);
		float maxX = posr.x + (width / 2.0);
		float minZ = posr.z - (length / 2.0);
		float maxZ = posr.z + (length / 2.0);
		float minY = -10.0f;
		//texture = t;

		vertices.push_back(glm::vec3(minX, minY, maxZ));
		vertices.push_back(glm::vec3(minX, minY, minZ));
		vertices.push_back(glm::vec3(maxX, minY, minZ));
		vertices.push_back(glm::vec3(maxX, minY, maxZ));

		//vertices.push_back(tl);//tl
		//vertices.push_back(bl);//tr
		//vertices.push_back(br);//bl
		//vertices.push_back(tr);//br

		indices.push_back(glm::ivec3(0, 1, 2));
		indices.push_back(glm::ivec3(2, 3, 0));

		tex.push_back(glm::vec2(0.0f, 1.0f));//0
		tex.push_back(glm::vec2(0.0f, 0.0f));//1
		tex.push_back(glm::vec2(1.0f, 0.0f));//2
		tex.push_back(glm::vec2(1.0f, 0.0f));//2
		tex.push_back(glm::vec2(1.0f, 1.0f));//3
		tex.push_back(glm::vec2(0.0f, 1.0f));//0

		pos.push_back(vertices[0]);
		pos.push_back(vertices[1]);
		pos.push_back(vertices[2]);
		pos.push_back(vertices[2]);
		pos.push_back(vertices[3]);
		pos.push_back(vertices[0]);
	}
	else {
		float minX = posr.x - (width / 2.0);
		float maxX = posr.x + (width / 2.0);
		float minZ = posr.z - (length / 2.0);
		float maxZ = posr.z + (length / 2.0);
		float minY = -10.0f;
		//texture = t;

		vertices.push_back(glm::vec3(minX, minY, maxZ));
		vertices.push_back(glm::vec3(minX, minY, minZ));
		vertices.push_back(glm::vec3(maxX, minY, minZ));
		vertices.push_back(glm::vec3(maxX, minY, maxZ));

		//vertices.push_back(tl);//tl
		//vertices.push_back(bl);//tr
		//vertices.push_back(br);//bl
		//vertices.push_back(tr);//br

		indices.push_back(glm::ivec3(1, 2, 3));
		indices.push_back(glm::ivec3(3, 0, 1));

		tex.push_back(glm::vec2(0.0f, 1.0f));//0
		tex.push_back(glm::vec2(0.0f, 0.0f));//1
		tex.push_back(glm::vec2(1.0f, 0.0f));//2
		tex.push_back(glm::vec2(1.0f, 0.0f));//2
		tex.push_back(glm::vec2(1.0f, 1.0f));//3
		tex.push_back(glm::vec2(0.0f, 1.0f));//0

		pos.push_back(vertices[1]);
		pos.push_back(vertices[2]);
		pos.push_back(vertices[3]);
		pos.push_back(vertices[3]);
		pos.push_back(vertices[0]);
		pos.push_back(vertices[1]);
	}

	texture = loadTexture();

	// Generate a vertex array (VAO) and two vertex buffer objects (VBO).
	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);
	glGenBuffers(1, &vbot);
	glGenBuffers(1, &ebo);

	// Bind to the VAO.
	glBindVertexArray(vao);

	// Bind to the first VBO. We will use it to store the vertices.
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	// Pass in the data.
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * pos.size(),
		pos.data(), GL_STATIC_DRAW);
	// Enable vertex attribute 0. 
	// We will be able to access vertices through it.
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), 0);

	// Bind to the second VBO. We will use it to store the tec cords.
	glBindBuffer(GL_ARRAY_BUFFER, vbot);
	// Pass in the data.
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec2) * tex.size(),
		tex.data(), GL_STATIC_DRAW);
	// Enable vertex attribute 1. 
	// We will be able to access vertices through it.
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), 0);

	// Bind to the second VBO. We will use it to store the indices.
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	// Pass in the data.
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(glm::ivec3) * indices.size(),
		indices.data(), GL_STATIC_DRAW);

	// Unbind from the VBOs.
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	// Unbind from the VAO.
	glBindVertexArray(0);


}

GLuint Ground::loadTexture()
{
	unsigned int texture1;
	glGenTextures(1, &texture1);
	glBindTexture(GL_TEXTURE_2D, texture1);
	// set the texture wrapping/filtering options (on the currently bound texture object)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	// load and generate the texture
	int width, height, nrChannels;
	unsigned char *data = stbi_load("GroundTex1.jpg", &width, &height, &nrChannels, 0);
	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}
	stbi_image_free(data);
	return texture1;
}

void Ground::draw(GLuint shaderProgram) {
	colorLoc = glGetUniformLocation(shaderProgram, "color");
	glUniform3fv(colorLoc, 1, glm::value_ptr(color));
	modelLoc = glGetUniformLocation(shaderProgram, "model");
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

	//glDepthMask(GL_FALSE);
	// Bind to the VAO.
	glBindVertexArray(vao);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture);

	// Set point size.
	// Draw points 
	//glDrawElements(GL_TRIANGLES, 3 * indices.size(), GL_UNSIGNED_INT, 0);
	glDrawArrays(GL_TRIANGLES, 0, pos.size());
	// Unbind from the VAO.
	glBindVertexArray(0);
	//glDepthMask(GL_TRUE);
}