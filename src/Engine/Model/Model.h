#pragma once
#include "GL\glew.h"
#include <vector>

class Model{

public:

	GLuint vertexArrayObjectID;
	GLuint vertexBufferID;
	GLuint indexBufferID;

	std::vector<float> verts;
	std::vector<GLuint> indicies;

	void load(){

		glGenVertexArrays(1, &vertexArrayObjectID);
		glBindVertexArray(vertexArrayObjectID);

		glGenBuffers(1, &vertexBufferID);
		glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID);
		glBufferData(GL_ARRAY_BUFFER, verts.size() * sizeof(float), &verts[0], GL_STATIC_DRAW);


		glGenBuffers(1, &indexBufferID);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferID);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicies.size() * sizeof(GLuint), &indicies[0], GL_STATIC_DRAW);

		glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);

	}

private:



};