#pragma once
#include "GL\glew.h"
#include "src\Engine\Entity\Entity.h"
#include "src\Engine\Shader\Shader.h"
#include <vector>

class Renderer{

public:

	void prepare(){
		
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glEnable(GL_DEPTH_TEST);
		glClearColor(0.2f, 0.2f, 0.9f, 1.0f);
	}

	void processEntity(Entity entity){ entities.push_back(entity); }
	void render(){
		prepare();
		for (auto entity : entities){
			shader.render(entity);
		}
	}

	Shader shader;

private:

	std::vector<Entity> entities;
	
	
};