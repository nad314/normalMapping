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
		p.loadDifImage(path.c_str());
		core::Path::popDir();
	}));

	push(norButton.make(core::vec4i(bsize+4, 2, bsize*2+4, bsize+2), &norImage, *this, [](core::Form& f)->void {
		Sidebar& p = dynamic_cast<Sidebar&>(f);
		if (!p) return;
		core::Debug::print("Loading Normal Texture...\n");
		core::Path::pushDir();
		std::string path = core::Path::getOpenFileName("Image\0*.png\0\0");
		p.loadNorImage(path.c_str());
		core::Path::popDir();
	}));

	push(relButton.make(core::vec4i(bsize*2+6, 2, bsize*3+6, bsize+2), &relImage, *this, [](core::Form& f)->void {
		core::Debug::print("Reloading Textures...\n");
		Sidebar& p = dynamic_cast<Sidebar&>(f);
		if (!p) return;
		p.loadDifImage(p.difPath);
		p.loadNorImage(p.norPath);
	}));

	push(clearButton.make(core::vec4i(2, bsize + 4, App::Theme::sidebarWidth - 10, bsize + 24), "Clear All", *this, [](core::Form& f)->void {
		Sidebar& p = dynamic_cast<Sidebar&>(f);
		if (!p) return;
		Controller::get().clearTextures();
		Controller::get().invalidate();
		p.loadImages();
		p.difButton.setImage(&p.difImage);
		p.norButton.setImage(&p.norImage);
		p.relButton.setImage(&p.relImage);
		p.invalidate();
		core::Debug::print("Cleared Images\n");
	}));

	push(sizeSlider.make(core::vec4i(2, bsize + 28, App::Theme::sidebarWidth - 10, bsize + 48), 1, *this, [](float pos, core::Form& f)->void {
		float scale = pow(0.5f, (0.5f - pos) * 2);
		Storage& data = Controller::get().storage();
		data.material.scale = core::vec2(scale, scale);
		Controller::invalidate();
		core::Debug::print("Texture Scale: %.2f\n", scale);
	}));

	push(saveButton.make(core::vec4i(2, bsize + 52, App::Theme::sidebarWidth - 10, bsize + 72), "Save Material", *this, [](core::Form& f)->void {
		core::Debug::print("Cleared Images\n");
		core::Debug::print("Loading Diffuse Texture...\n");
		core::Path::pushDir();
		std::string path = core::Path::getSaveFileName("Materials (.mat)\0*.mat\0\0");
		path = core::Path::pushExt("mat", path);
		core::Path::popDir();
		if (!Controller::get().storage().material.save(path.c_str(), core::Path::getHomeDir().c_str()))
			core::Debug::print("Error occured while trying to save material\n");
	}));

	setControlColors();
}

void Sidebar::onEndPaint(const core::eventInfo& e) {
	Form::onEndPaint(e);
}

