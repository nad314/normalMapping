#pragma once

namespace core {
	class glGameMesh {
	public:
		GLuint buff[4];
		GLuint vao;
		int ind;
		glGameMesh() { memset(buff, 0, sizeof(buff)); ind = 0; }
		~glGameMesh();

		bool make(GameMesh& mesh, glShader& shader, const char* pos, const char* nor, const char* tex);
		void drawTris();
		void drawQuads();
	};
}
