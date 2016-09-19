#pragma once

class Sidebar final : public core::Form {
public:
	core::Image difImage;
	core::Image norImage;
	core::Image relImage;

	core::ImageButton difButton; //diffuse texture load
	core::ImageButton norButton; //normal texture load
	core::ImageButton relButton; //reload textures

	void onOpening() override;
	void onOpened() override;
	void loadImages();

	void onEndPaint(const core::eventInfo& e) override;
};
