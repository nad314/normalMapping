#include <main\main.h>

bool Controller::repaint = 0;

Controller::Controller(core::Window* ptr, Storage* storage) {
	parent = ptr;
	parent->attach(this);
	data = storage;
	invalidate();

	core::Window* mw = dynamic_cast<core::Window*>(parent->getParent());
	core::Monitor::Enumerate();
	mw->centerToMonitor(core::Monitor::MonitorFromId(1));

	initGL();
	data->view.perspective(*parent, 41.5f, 0.1f, 100.0f);
	data->view.modelview.init();
	data->view.modelview.translate(0.0f, 0.0f, -5.0f);
}

Controller::~Controller() {
	if (parent)
		parent->detach();
	data = NULL;
}

int Controller::onResize(const core::eventInfo& e) {
	EventListener::onResize(e);
	data->view.perspective(*parent, 41.5f, 0.1f, 100.0f);
	return e;
}

int Controller::onPaint(const core::eventInfo& e) {
	drawScene();
	return EventListener::onPaint(e);
}

void Controller::drawScene() {
	Storage& dat = *data;
	if (!parent||!repaint)
		return;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	dat.shader.start();
	dat.view.sendTo(dat.shader, "modelview", "projection");
	dat.model.drawQuads();
	dat.shader.stop();
	glDisable(GL_DEPTH_TEST);
	GL::swapBuffers(*parent);
	repaint = 0;
}

void Controller::initGL() {
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glClearColor(0.1f, 0.1f, 0.11f, 1.0f);
}
