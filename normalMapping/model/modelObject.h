#pragma once

namespace core {
	class ModelObject {
	public:
		buffer<vec4> position;
		buffer<int> indices;
	};

	class GameModel {
	public:
		buffer<vec3> position;
		buffer<vec3> normal;
		buffer<vec2> texcoord;
		buffer<int> indices;
	};

	class glGameModel {
	public:
		GLuint buff[4]; //buffers;
		GLuint vao;
		int ind;
		glGameModel() { memset(buff, 0, sizeof(buff)); ind = 0; }
		~glGameModel();

		bool make(GameModel& model, glShader& shader, const char* pos, const char* nor, const char* tex);
		void drawTriangles();
		void drawQuads();
	};
}
