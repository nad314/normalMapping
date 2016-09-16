#pragma once

namespace core {
	class glView : public View {
	public:
		glView& sendTo(glShader& shader, const char* modelviewName, const char* projectionName);
	};
}
