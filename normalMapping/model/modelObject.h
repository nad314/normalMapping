#pragma once

namespace core {
	class GameMesh {
	public:
		buffer<vec3> position;
		buffer<vec3> normal;
		buffer<vec2> texcoord;
		buffer<int> indices;
	};

	class glGameMesh {
	public:
		GLuint buff[4];
		GLuint vao;
		int ind;
		glGameMesh() { memset(buff, 0, sizeof(buff)); ind = 0; }
		~glGameMesh();

		bool make(GameMesh& mesh, glShader& shader, const char* pos, const char* nor, const char* tex);
		void drawTriangles();
		void drawQuads();
	};
}
