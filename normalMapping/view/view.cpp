#include <main/main.h>

namespace core {
	void View::perspective(const int& width, const int& height, const float& FoV, const float& znear, const float& zfar) {
		if (height == 0)
			return;
		projection.projection(FoV, (float)width / height, 0.01f, 100.0f);
		fov = FoV;
	}

	void View::perspective(Window& window, const float &FoV, const float& znear, const float& zfar) {
		perspective(window.width, window.height, FoV, znear, zfar);
	}
}
