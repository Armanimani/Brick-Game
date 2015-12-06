#include "GL\glew.h"
#include "src\Game\Level\Level1.h"
#include "glm\glm.hpp"
#include "src\Engine\Model\ShapeGenerator.h"

using glm::vec3;

Level1::Level1(){




}

void Level1::load(){
	renderer.shader.installShader();
	circle = ShapeGenerator::createSphere();
	circle.load();
	rect = ShapeGenerator::createRectangular();
	rect.load();

	Entity entity(rect);
	entity.color = glm::vec3(1.0, 0.0, 0.0);
	entity.scale = vec3(0.5, 0.5, 0.5);
	entity.rotation = vec3(0.0, 0.0, 0.0);
	entity.position= vec3(0.0, 0.0, 0.0);
	renderer.processEntity(entity);

}

void Level1::render(){

	renderer.render();
}

void Level1::update(){


}
