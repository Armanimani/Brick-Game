#pragma once
#include <GL\glew.h>
#include <QtOpenGL\qglwidget>
#include "QtCore\qtimer.h"
#include "src\Engine\Renderer\Renderer.h"
#include "src\Game\Level\Level1.h"

class Window : public QGLWidget{

	Q_OBJECT

public:

	Window();
	void cleanUp();

protected:

	QTimer timer;
	Level level1;

	void initializeGL();
	void paintGL();
	void checkKeyState();

	private slots:
	void update();
};