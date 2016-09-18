#include <main/main.h>

void Statusbar::onOpening() {
	Form::onOpening();
	setSize(256, 256);
	setStyle(WS_CHILD | WS_CLIPSIBLINGS | WS_CLIPCHILDREN);
	setBackColor(core::Theme::controlBackColor);
	setControlColors();
	setClass("MaterialPreviewStatusbar");
}

void Statusbar::onOpened() {
	Form::onOpened();
	setBackColor(App::Theme::FormBackColor);
}

void Statusbar::onEndPaint(const core::eventInfo& e) {
	Form::onEndPaint(e);
	core::Font::get().print("Statusbar ready.", *this, 4, 4);
}
