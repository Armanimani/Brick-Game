#pragma once
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtx\transform.hpp>

class GLMath{

public:
	static glm::mat4 createTransformationMatrix(glm::vec3 &translation, glm::vec3 &rotation, glm::vec3 &scale){
		glm::mat4 translationMatrix = glm::translate(translation);
		glm::mat4 rotationMatrix_x = glm::rotate(translationMatrix, glm::radians(rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
		glm::mat4 rotationMatrix_y = glm::rotate(rotationMatrix_x, glm::radians(rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
		glm::mat4 rotationMatrix_z = glm::rotate(rotationMatrix_y, glm::radians(rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
		glm::mat4 scaleMatrix = glm::scale(rotationMatrix_z, scale);

		return scaleMatrix;
	}


};