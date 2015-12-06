#pragma once
#include "src\Engine\Model\Model.h"
#include "glm\glm.hpp"

class Entity{

public:

	Entity(Model &model){ this->model = &model; };
	Model *model;

	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 scale;

	glm::vec3 color;

	float get_x_max() { return position.x + scale.x; }
	float get_x_min() { return position.x - scale.x; }
	float get_y_max() { return position.y + scale.y; }
	float get_y_min() { return position.y - scale.y; }
};