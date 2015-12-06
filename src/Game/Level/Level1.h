#pragma once
#include "src\Game\Level\Level.h"
#include "src\Engine\Renderer\Renderer.h"
#include "src\Engine\Model\Model.h"

class Level1 : public Level{

public:

	Level1();

	void load();
	void render();
	void update();
	

	Renderer renderer;

	Model rect;
	Model circle;

};