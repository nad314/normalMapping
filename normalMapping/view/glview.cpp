#include <main/main.h>

namespace core {
	glView& glView::sendTo(glShader& shader, const char* modelviewName, const char* projectionName) {
		int l[2];
		l[0] = glExt::getUniformLocation(shader, modelviewName);
		l[1] = glExt::getUniformLocation(shader, projectionName);
		glExt::uniformMatrix4fv(l[0], 1, false, modelview);
		glExt::uniformMatrix4fv(l[1], 1, false, projection);
		return *this;
	}
}
