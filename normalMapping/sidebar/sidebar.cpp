#include <main/main.h>

void Sidebar::onOpening() {
	Form::onOpening();
	setSize(256, 256);
	setStyle(WS_CHILD | WS_CLIPSIBLINGS | WS_CLIPCHILDREN);
	setClass("MaterialPreviewSidebar");
}

void Sidebar::onOpened() {
	Form::onOpened();
	setBackColor(App::Theme::FormBackColor);
	loadImages();

	const int bsize = 52;
	push(difButton.make(core::vec4i(2, 2, bsize+2, bsize+2), &difImage, *this, [](core::Form& f)->void {
		core::Debug::print("Loading Diffuse Texture...\n");
	}));
	push(norButton.make(core::vec4i(bsize+4, 2, bsize*2+4, bsize+2), &norImage, *this, [](core::Form& f)->void {
		core::Debug::print("Loading Normal Texture...\n");
	}));
	push(relButton.make(core::vec4i(bsize*2+6, 2, bsize*3+6, bsize+2), &relImage, *this, [](core::Form& f)->void {
		core::Debug::print("Reloading Textures...\n");
	}));

	setControlColors();
}

void Sidebar::onEndPaint(const core::eventInfo& e) {
	Form::onEndPaint(e);
}

void Sidebar::loadImages() {
	core::Path::pushDir();
	core::Path::goHome();
	core::Path::cd("../data/");

	difImage.loadPng("img/plus.png");
	norImage.loadPng("img/plus.png");
	relImage.loadPng("img/rot.png");
	relImage.flipV();

	core::Core2D::drawRect(core::Rect(0, 0, difImage.width, difImage.height), core::Theme::controlBorderColor, difImage);
	core::Core2D::drawRect(core::Rect(0, 0, norImage.width, norImage.height), core::Theme::controlBorderColor, norImage);
	core::Core2D::drawRect(core::Rect(0, 0, relImage.width, relImage.height), core::Theme::controlBorderColor, relImage);

	core::Path::popDir();
}

