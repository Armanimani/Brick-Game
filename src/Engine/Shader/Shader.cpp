#include "src\Engine\Shader\Shader.h"
#include <fstream>
#include <iostream>
#include "glm\glm.hpp"
#include "src\Engine\GLMath\GLMath.h"

using glm::mat4;

void Shader::installShader(){

	vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
	const GLchar* adapter[1];
	std::string temp = readShaderCode("src/Engine/Shader/ShaderVS.glsl").c_str();
	adapter[0] = temp.c_str();
	glShaderSource(vertexShaderID, 1, adapter, 0);
	temp = readShaderCode("src/Engine/Shader/ShaderFS.glsl").c_str();
	adapter[0] = temp.c_str();
	glShaderSource(fragmentShaderID, 1, adapter, 0);

	glCompileShader(vertexShaderID);
	glCompileShader(fragmentShaderID);

	if (!checkShaderStatus(vertexShaderID) | !checkShaderStatus(fragmentShaderID)){
		return;
	}

	programID = glCreateProgram();
	glAttachShader(programID, vertexShaderID);
	glAttachShader(programID, fragmentShaderID);
	glLinkProgram(programID);
	glValidateProgram(programID);

	if (!checkProgramStatus(programID)){
		return;
	}

	getAllUniformLocations();
}

void Shader::startProgram(){

	glUseProgram(programID);
}

void Shader::stopProgram(){

	glUseProgram(0);
}


void Shader::render(Entity &entity){


	startProgram();

	//loadTransformationMatrix(GLMath::createTransformationMatrix(entity.position, entity.rotation, glm::vec3(entity.scale.x * 1.05, entity.scale.y * 1.05, entity.scale.z * 0.95)));
	//loadColor(glm::vec3(1.0, 1.0, 1.0));
	//glBindVertexArray(entity.model->vertexArrayObjectID);
	//glEnableVertexAttribArray(0);
	//glDrawElements(GL_TRIANGLES, entity.model->indicies.size(), GL_UNSIGNED_INT, 0);
	//glDisableVertexAttribArray(0);
	//glBindVertexArray(0);

	loadTransformationMatrix(GLMath::createTransformationMatrix(entity.position, entity.rotation, entity.color));
	loadColor(entity.color);
	glBindVertexArray(entity.model->vertexArrayObjectID);
	glEnableVertexAttribArray(0);
	glDrawElements(GL_TRIANGLES, entity.model->indicies.size(), GL_UNSIGNED_INT, 0);
	glDisableVertexAttribArray(0);
	glBindVertexArray(0);

	stopProgram();

}

void Shader::cleanUp(){

	glDetachShader(programID, vertexShaderID);
	glDetachShader(programID, fragmentShaderID);

	glDeleteShader(vertexShaderID);
	glDeleteShader(fragmentShaderID);

	glDeleteProgram(programID);
}


std::string Shader::readShaderCode(const GLchar* fileName){

	std::ifstream input(fileName);
	if (!input.good()){
		std::cout << "File failed to load" << std::endl;
		exit(1);
	}
	return std::string(std::istreambuf_iterator<char>(input), std::istreambuf_iterator<char>());
}


GLint Shader::getUniformLocation(std::string &uniformName){

	const GLchar* adapter[1];
	std::string temp = uniformName.c_str();
	adapter[0] = temp.c_str();
	return glGetUniformLocation(programID, adapter[0]);
}

void Shader::getAllUniformLocations(){

	std::string string = " ";

	string = "transformationMatrix";
	location_transformationMatrix = getUniformLocation(string);

	string = "color";
	location_color = getUniformLocation(string);
}


void Shader::loadToUniform(GLuint &location, bool &data){

	if (data == true){
		glUniform1f(location, data);
	}
	else {
		glUniform1f(location, data);
	}

}
void Shader::loadToUniform(GLuint &location, GLfloat &data){

	glUniform1f(location, data);
}

void Shader::loadToUniform(GLuint &location, glm::vec3 &data){

	glUniform3fv(location, 1, &data[0]);
}

void Shader::loadToUniform(GLuint &location, glm::mat4 &data){

	glUniformMatrix4fv(location, 1, GL_FALSE, &data[0][0]);
}


bool Shader::checkStatus(GLuint objectID, PFNGLGETSHADERIVPROC objectPropertyGetter,
	PFNGLGETSHADERINFOLOGPROC getInfoLogFun, GLenum statusType){

	GLint status;
	objectPropertyGetter(objectID, statusType, &status);
	if (status != GL_TRUE){
		GLint infoLogLength;
		objectPropertyGetter(objectID, GL_INFO_LOG_LENGTH, &infoLogLength);
		GLchar* buffer = new GLchar[infoLogLength];
		GLsizei bufferSize;
		getInfoLogFun(objectID, infoLogLength, &bufferSize, buffer);

		std::cout << buffer << std::endl;

		delete[] buffer;
		return false;
	}
	return true;
}

bool Shader::checkShaderStatus(GLuint ShaderID){

	return checkStatus(ShaderID, glGetShaderiv, glGetShaderInfoLog, GL_COMPILE_STATUS);
}

bool Shader::checkProgramStatus(GLuint programID){

	return checkStatus(programID, glGetProgramiv, glGetProgramInfoLog, GL_LINK_STATUS);

}

void Shader::loadTransformationMatrix(glm::mat4 &data){

	loadToUniform(location_transformationMatrix, data);
}

void Shader::loadColor(glm::vec3 &color){

	loadToUniform(location_color, color);
}