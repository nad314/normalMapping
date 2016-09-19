#pragma once

namespace core {
	class glTexture {
	private:
		GLuint t;
	public:
		glTexture() : t(0) {}
		~glTexture();
		
		inline operator GLuint&() { return t; }
		inline void bind() { glBindTexture(GL_TEXTURE_2D, t); }
		inline static void unbind() { glBindTexture(GL_TEXTURE_2D, 0); }
		void dispose();
		bool make(Image& img);
		bool loadPng(char* path);
		void genMipmaps();
		
	};
}
