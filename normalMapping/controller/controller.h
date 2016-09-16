#pragma once

class Controller : public core::EventListener {
protected:
	core::Window* parent;
	Storage* data;
	static bool repaint;
	core::vec2i mpos;
	bool dragging;

	core::matrixf rotation, translation;

public:
	Controller() : EventListener(), parent(NULL) {}
	Controller(core::Window* prt, Storage* storage);
	~Controller();

	int onPaint(const core::eventInfo& e) override;
	int onResize(const core::eventInfo& e) override;
	int onLButtonDown(const core::eventInfo& e) override;
	int onLButtonUp(const core::eventInfo& e) override;
	int onMouseMove(const core::eventInfo& e) override;

	void drawScene();
	void initGL();
	static inline void invalidate() { repaint = 1; }
};
