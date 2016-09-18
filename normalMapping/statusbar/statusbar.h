#pragma once

class Statusbar final : public core::Form {
public:
	void onOpening() override;
	void onOpened() override;

	void onEndPaint(const core::eventInfo& e) override;
};
