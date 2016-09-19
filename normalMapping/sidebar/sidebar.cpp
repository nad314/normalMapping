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
		Sidebar& p = dynamic_cast<Sidebar&>(f);
		if (!p) return;
		core::Debug::print("Loading Diffuse Texture...\n");
		core::Path::pushDir();
		std::string path = core::Path::getOpenFileName("Image\0*.png\0\0");
		if (!p.difImage.loadPng(path.c_str()))
			core::Debug::print("Couldn't load image\n");
		else {
			Controller::get().storage().diffuse.make(p.difImage);
			Controller::get().invalidate();
			p.adjustImage(p.difImage, p.difImage);
			p.difButton.setImage(&p.difImage);
			core::Debug::print("Success!\n");
		}
		core::Path::popDir();
	}));

	push(norButton.make(core::vec4i(bsize+4, 2, bsize*2+4, bsize+2), &norImage, *this, [](core::Form& f)->void {
		Sidebar& p = dynamic_cast<Sidebar&>(f);
		if (!p) return;
		core::Debug::print("Loading Normal Texture...\n");
		core::Path::pushDir();
		std::string path = core::Path::getOpenFileName("Image\0*.png\0\0");
		if (!p.norImage.loadPng(path.c_str()))
			core::Debug::print("Couldn't load image\n");
		else {
			Controller::get().storage().normal.make(p.norImage);
			Controller::get().invalidate();
			p.adjustImage(p.norImage, p.norImage);
			p.norButton.setImage(&p.norImage);
			core::Debug::print("Success!\n");
		}
		core::Path::popDir();
	}));

	push(relButton.make(core::vec4i(bsize*2+6, 2, bsize*3+6, bsize+2), &relImage, *this, [](core::Form& f)->void {
		core::Debug::print("Reloading Textures...\n");
	}));

	setControlColors();
}

void Sidebar::onEndPaint(const core::eventInfo& e) {
	Form::onEndPaint(e);
}

