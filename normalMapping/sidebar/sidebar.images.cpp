#include <main/main.h>

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

void Sidebar::adjustImage(core::Image& dest, const core::Image& source) {
	core::Image img = source;
	const int border = 6;
	dest.make(52, 52);
	img.linearDownscale(52-2* border, 52-2* border);
	core::Core2D::clearImage(dest, core::Color(0,0,0,0));
	core::Core2D::drawRect(core::Rect(0, 0, 52, 52), controlBorderColor, dest);
	core::Core2D::blendImage(core::Rect(border, border, 52- border, 52- border), img, dest);
}
