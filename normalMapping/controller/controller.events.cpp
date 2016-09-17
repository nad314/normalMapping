#include <main/main.h>

int Controller::onResize(const core::eventInfo& e) {
	EventListener::onResize(e);
	lpdata->view.perspective(*parent, 41.5f, 0.1f, 100.0f);
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
		lpdata->view.modelview = rotation*translation;
		invalidate();
	}
	return EventListener::onMouseMove(e);
}


int Controller::onPaint(const core::eventInfo& e) {
	drawScene();
	return EventListener::onPaint(e);
}
