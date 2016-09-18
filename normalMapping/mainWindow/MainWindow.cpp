#include <main/main.h>

void MainWindow::onOpening() {
	WindowForm::onOpening();
	setTitle("Material Preview");
	setClass("CoreMaterialPreview");
	setFlags(glw_hidden);
	setSize(696, 540);
}

void MainWindow::onClosing() {
	statusbar.close();
	sidebar.close();
	renderWindow.close();
	WindowForm::onClosing();
}

void MainWindow::onOpened() {
	WindowForm::onOpened();
	renderWindow.setParent(this);
	renderWindow.open();
	sidebar.setParent(this);
	sidebar.open();
	statusbar.setParent(this);
	statusbar.open();
	reshape();
}

int MainWindow::onResize(const core::eventInfo& e) {
	WindowForm::onResize(e);
	if (width < 1 || height < 1)
		return e;
	reshape();
	return e;
}

void MainWindow::reshape() {
	//MoveWindow(renderWindow.hWnd, 6, 40, width - 12, height - 46, false);
	SetWindowPos(renderWindow, NULL, 8, 40, width - 16 - 256, height - 46 - 24, SWP_NOCOPYBITS|SWP_DEFERERASE|SWP_NOSENDCHANGING);
	SetWindowPos(sidebar, NULL, width - 256, 40, 256 - 8, height - 46 - 24, SWP_NOCOPYBITS | SWP_DEFERERASE | SWP_NOSENDCHANGING);
	SetWindowPos(statusbar, NULL, 4, height-24, width - 8, 20, SWP_NOCOPYBITS | SWP_DEFERERASE | SWP_NOSENDCHANGING);
}

void MainWindow::onEndPaint(const core::eventInfo& e) {
	WindowForm::onEndPaint(e);
	core::Core2D::drawRect(renderWindow.getChildRect().expand(1), core::Color(10), *this);
	core::Core2D::drawRect(sidebar.getChildRect().expand(1), core::Color(10), *this);
	core::Core2D::drawRect(statusbar.getChildRect().expand(1), core::Color(10), *this);
	InvalidateRect(renderWindow, NULL, false);
}
