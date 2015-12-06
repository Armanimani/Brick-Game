#include "src\Game\Window\Window.h"
#include <iostream>
#include "src\Game\Level\Level1.h"

Window::Window(){

	
}

void Window::initializeGL(){

	glewInit();

	connect(&timer, SIGNAL(timeout()), this, SLOT(update()));
	timer.start(1000 / 60);

	level1.load();
}

void Window::paintGL(){

	glViewport(0, 0, width(), height());
	level1.render();

}

void Window::cleanUp(){

	

}

void Window::update(){

	checkKeyState();

}

void Window::checkKeyState(){


	if (GetAsyncKeyState('W')){

	}

	if (GetAsyncKeyState('S')){

	}

	if (GetAsyncKeyState('D')){

	}

	if (GetAsyncKeyState('A')){

	}
	if (GetAsyncKeyState(VK_UP)){

	}

	if (GetAsyncKeyState(VK_DOWN)){

	}
	repaint();

}