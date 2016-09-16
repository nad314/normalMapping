#pragma once

namespace core {
	class View {
	public:
		matrixf projection;
		matrixf modelview;
		float fov;

		void perspective(const int& width, const int& height, const float& FoV, const float& znear, const float& zfar);
		void perspective(Window& wnd, const float& FoV, const float& znear, const float& zfar);
	};
}

