#pragma once
#include <GL\glew.h>
#include <glm\glm.hpp>
#include <fstream>
#include "src\Engine\Entity\Entity.h"

class Shader
{
public:
	void startProgram();
	void stopProgram();
	void installShader();
	void render(Entity &entity);
	void loadTransformationMatrix(glm::mat4 &data);
	void loadColor(glm::vec3 &data);
	void cleanUp();

protected:
	GLuint location_transformationMatrix;
	GLuint location_color;

	GLuint programID;
	GLuint vertexShaderID;
	GLuint fragmentShaderID;

	std::string readShaderCode(const GLchar* fileName);

	GLint getUniformLocation(std::string &uniformName);
	virtual void getAllUniformLocations();

	void loadToUniform(GLuint &location, bool &data);
	void loadToUniform(GLuint &location, GLfloat &data);
	void loadToUniform(GLuint &location, glm::vec3 &data);
	void loadToUniform(GLuint &location, glm::mat4 &data);

	bool checkStatus(GLuint objectID, PFNGLGETSHADERIVPROC objectPropertyGetter,
		PFNGLGETSHADERINFOLOGPROC getInfoLogFun, GLenum statusType);
	bool checkShaderStatus(GLuint ShaderID);
	bool checkProgramStatus(GLuint programID);

};

