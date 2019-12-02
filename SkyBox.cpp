#include "SkyBox.h"

SkyBox::SkyBox(float size)
{
	// Model matrix. Since the original size of the cube is 2, in order to
	// have a cube of some size, we need to scale the cube by size / 2.
	model = glm::scale(glm::vec3(size / 2.f));

	// The color of the cube. Try setting it to something else!
	color = glm::vec3(1.0f, 0.95f, 0.1f);

	/*
	 * Cube indices used below.
	 *    4----7
	 *   /|   /|
	 *  0-+--3 |
	 *  | 5--+-6
	 *  |/   |/
	 *  1----2
	 *
	 */

	 // The 8 vertices of a cube.
	vertices.push_back(glm::vec3(-size, size, size));
	vertices.push_back(glm::vec3(-size, -size, size));
	vertices.push_back(glm::vec3(size, -size, size));
	vertices.push_back(glm::vec3(size, size, size));
	vertices.push_back(glm::vec3(-size, size, -size));
	vertices.push_back(glm::vec3(-size, -size, -size));
	vertices.push_back(glm::vec3(size, -size, -size));
	vertices.push_back(glm::vec3(size, size, -size));
			
	// Each ivec3(v1, v2, v3) define a triangle consists of vertices v1, v2 
	// and v3 in counter-clockwise order.

		// Front face.
	indices.push_back(glm::ivec3(2, 1, 0));
	indices.push_back(glm::ivec3(0, 3, 2));
		// Back face.
	indices.push_back(glm::ivec3(5, 6, 7));
	indices.push_back(glm::ivec3(7, 4, 5));
		// Right face.
	indices.push_back(glm::ivec3(6, 2, 3));
	indices.push_back(glm::ivec3(3, 7, 6));
		// Left face.
	indices.push_back(glm::ivec3(1, 5, 4));
	indices.push_back(glm::ivec3(4, 0, 1));
		// Top face.
	indices.push_back(glm::ivec3(3, 0, 4));
	indices.push_back(glm::ivec3(4, 7, 3));
		// Bottom face.
	indices.push_back(glm::ivec3(6, 5, 1));
	indices.push_back(glm::ivec3(1, 2, 6));

	faces.push_back("right.jpg");
	faces.push_back("left.jpg");
	faces.push_back("top.jpg");
	faces.push_back("bottom.jpg");
	faces.push_back("front.jpg");
	faces.push_back("back.jpg");
	
	cubemapTexture = loadCubemap(faces);

	// Generate a vertex array (VAO) and two vertex buffer objects (VBO).
	glGenVertexArrays(1, &vao);
	glGenBuffers(2, vbos);

	// Bind to the VAO.
	glBindVertexArray(vao);

	// Bind to the first VBO. We will use it to store the vertices.
	glBindBuffer(GL_ARRAY_BUFFER, vbos[0]);
	// Pass in the data.
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * vertices.size(),
		vertices.data(), GL_STATIC_DRAW);
	// Enable vertex attribute 0. 
	// We will be able to access vertices through it.
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), 0);

	// Bind to the second VBO. We will use it to store the indices.
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbos[1]);
	// Pass in the data.
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(glm::ivec3) * indices.size(),
		indices.data(), GL_STATIC_DRAW);

	// Unbind from the VBOs.
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	// Unbind from the VAO.
	glBindVertexArray(0);
}

SkyBox::~SkyBox()
{
	// Delete the VBOs and the VAO.
	glDeleteBuffers(2, vbos);
	glDeleteVertexArrays(1, &vao);
}

GLuint SkyBox::loadCubemap(std::vector<const GLchar*> faces)
{

	GLuint textureID;

	int width, height, channels;
	unsigned char * data;

	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_CUBE_MAP, textureID);

	//Generate the texture.
	for (GLuint i = 0; i < faces.size(); i++)
	{
		data = stbi_load(faces[i], &width, &height, &channels, 0);
		if (data) {
			glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
			stbi_image_free(data);
		}
		else {
			stbi_image_free(data);
		}
	}
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

	return textureID;
}


void SkyBox::draw(GLuint shaderProgram)
{

	////colorLoc = glGetUniformLocation(shaderProgram, "color");

	//glUniform3fv(colorLoc, 1, glm::value_ptr(color));




	// Bind to the VAO.
	glDepthMask(GL_FALSE);
	glBindVertexArray(vao);
	glBindTexture(GL_TEXTURE_CUBE_MAP, cubemapTexture);
	// Make sure no bytes are padded:
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	// Use bilinear interpolation:
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	// Use clamp to edge to hide skybox edges:
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
	// Draw triangles using the indices in the second VBO, which is an 
	// elemnt array buffer.
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
	// Unbind from the VAO.
	glBindVertexArray(0);
	glDepthMask(GL_TRUE);
	//glEnable(GL_CULL_FACE);
	//glCullFace(GL_BACK);
	//glFrontFace(GL_CW);
}

void SkyBox::update()
{
	
}
