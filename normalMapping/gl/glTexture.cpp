#include <main/main.h>

namespace core {
	glTexture::~glTexture() {
		dispose();
	}

	void glTexture::dispose() {
		if (glIsTexture(t))
			glDeleteTextures(1, &t);
		t = 0;
	}

	bool glTexture::make(Image& img) {
		if (img.width == 0 || img.height == 0)
			return 0;
		dispose();
		glBindTexture(GL_TEXTURE_2D, 0);
		glGenTextures(1, &t);
		glBindTexture(GL_TEXTURE_2D, t);
		if (!glIsTexture(t))
			return 0;
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		int format;
		int internalFormat;
		switch (img.bits) {
		case 8: format = GL_R; internalFormat = GL_R;  break;
		case 24: format = GL_RGB; internalFormat = GL_RGB8;  break;
		case 32: format = GL_RGBA; internalFormat = GL_RGBA8;  break;
		default: format = GL_RGBA; internalFormat = GL_RGBA8; break;
		}
		glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, img.width, img.height, 0, format, GL_UNSIGNED_BYTE, img.data);
		return 1;
	}

	bool glTexture::loadPng(char* path) {
		Image img;
		if (!img.loadPng(path))
			return 0;
		return make(img);
	}
}
