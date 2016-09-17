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
	rotation.init();
	rotation.rotate(20.0f, 1.0f, 0.0f, 0.0f);
	rotation.rotate(-30.0f, 0.0f, 1.0f, 0.0f);
	translation.init();
	translation.translate(0.0f, 0.0f, -6.0f);
	data->view.perspective(*parent, 41.5f, 0.1f, 100.0f);
	data->view.modelview = rotation*translation;
}

Controller::~Controller() {
	if (parent)
		parent->detach();
	data = NULL;
}

int Controller::onResize(const core::eventInfo& e) {
	EventListener::onResize(e);
	data->view.perspective(*parent, 41.5f, 0.1f, 100.0f);
	invalidate();
	return e;
}

int Controller::onLButtonDown(const core::eventInfo& e) {
	dragging = 1;
	return EventListener::onLButtonDown(e);
}

int Controller::onLButtonUp(const core::eventInfo& e) {
	dragging = 0;
	return EventListener::onLButtonUp(e);
}

int Controller::onMouseMove(const core::eventInfo& e) {
	core::vec2i lpos = mpos;
	mpos = core::vec2i(LOWORD(e.lP), HIWORD(e.lP));
	if (dragging) {
		core::matrixf rot;
		rot.rotate(0.25f*(mpos.x - lpos.x), 0.0f, 1.0f, 0.0f);
		rot.rotate(0.25f*(mpos.y - lpos.y), 1.0f, 0.0f, 0.0f);
		rotation = rotation*rot;
		data->view.modelview = rotation*translation;
		invalidate();
	}
	return EventListener::onMouseMove(e);
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
