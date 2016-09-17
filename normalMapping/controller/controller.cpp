#include <main\main.h>

bool Controller::repaint = 0;

Controller::Controller(core::Window* ptr, Storage* storage) {
	parent = ptr;
	parent->attach(this);
	lpdata = storage;
	invalidate();

	core::Window* mw = dynamic_cast<core::Window*>(parent->getParent());
	core::Monitor::Enumerate();
	mw->centerToMonitor(core::Monitor::MonitorFromId(1));

	initGL();
	rotation.init();
	rotation.rotate(20.0f, 1.0f, 0.0f, 0.0f);
	rotation.rotate(-30.0f, 0.0f, 1.0f, 0.0f);
	translation.init();
	translation.translate(0.0f, 0.0f, -6.0f);
	lpdata->view.perspective(*parent, 41.5f, 0.1f, 100.0f);
	lpdata->view.modelview = rotation*translation;
}

Controller::~Controller() {
	if (parent)
		parent->detach();
	lpdata = NULL;
}

void Controller::drawScene() {
	if (!parent||!repaint)
		return;
	Storage& data = *lpdata;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	data.shader.start();
	data.view.sendTo(data.shader, "modelview", "projection");
	data.model.drawTris();
	data.shader.stop();
	glDisable(GL_DEPTH_TEST);
	GL::swapBuffers(*parent);
	repaint = 0;
}

void Controller::initGL() {
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glClearColor(0.1f, 0.1f, 0.11f, 1.0f);
}
