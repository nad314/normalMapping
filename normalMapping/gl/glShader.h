#pragma once

namespace core {
	class glShader {
	protected:
		GLuint vertex;
		GLuint fragment;
		GLuint program;
	public:
		glShader() : vertex(0), fragment(0), program(0) {}
		glShader(const char* vp, const char* fp, const char* fragName) { load(vp, fp, fragName); }
		~glShader() { dispose(); }
		void dispose();
		bool load(const char* vertexPath, const char* fragmentPath, const char* fragName);
		inline void start() { glExt::useProgramObject(program); }
		inline void stop() { glExt::useProgramObject(0); }
		inline operator GLuint() { return program; }
	};
}

