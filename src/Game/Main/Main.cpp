#include <GL\glew.h>
#include <QtWidgets\qapplication.h>
#include "src\Game\Window\Window.h"

int main(int argc, char* argv[]){

	QApplication application(argc, argv);

	Window window;

	window.show();

	window.cleanUp();


	return application.exec();
}