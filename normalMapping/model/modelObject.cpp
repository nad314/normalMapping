#include <main/main.h>

namespace core {
	glGameModel::~glGameModel() {
		if (glExt::isBuffer(buff[0]))
			glExt::deleteBuffers(4, buff);
		if (glExt::isVertexArray(vao))
			glExt::deleteVertexArrays(1, &vao);
		memset(buff, 0, sizeof(buff));
		ind = 0;
	}

	bool glGameModel::make(GameModel& model, glShader& shader, const char* pos, const char* nor, const char* tex) {
		if (model.position.count() < 1 || model.indices.count() < 0)
			return 0;

		ind = model.indices.count();
		int index;

		vao = 0;
		glExt::genVertexArrays(1, &vao);
		glExt::genBuffers(4, buff);
		glExt::bindVertexArray(vao);

		glExt::bindBuffer(GL_ARRAY_BUFFER, buff[0]);
		glExt::bufferData(GL_ARRAY_BUFFER, model.position.count() * sizeof(vec3), model.position, GL_STATIC_DRAW);
		index = glExt::getAttribLocation(shader.program, pos);
		glExt::enableVertexAttribArray(index);
		glExt::vertexAttribPointer(index, 3, GL_FLOAT, false, 0, 0);
		
		glExt::bindBuffer(GL_ARRAY_BUFFER, buff[1]);
		glExt::bufferData(GL_ARRAY_BUFFER, model.normal.count() * sizeof(vec3), model.normal, GL_STATIC_DRAW);
		index = glExt::getAttribLocation(shader.program, nor);
		glExt::enableVertexAttribArray(index);
		glExt::vertexAttribPointer(index, 3, GL_FLOAT, false, 0, 0);

		glExt::bindBuffer(GL_ARRAY_BUFFER, buff[2]);
		glExt::bufferData(GL_ARRAY_BUFFER, model.texcoord.count() * sizeof(vec2), model.texcoord, GL_STATIC_DRAW);
		index = glExt::getAttribLocation(shader.program, tex);
		glExt::enableVertexAttribArray(index);
		glExt::vertexAttribPointer(index, 2, GL_FLOAT, false, 0, 0);

		glExt::bindBuffer(GL_ELEMENT_ARRAY_BUFFER, buff[3]);
		glExt::bufferData(GL_ELEMENT_ARRAY_BUFFER, model.indices.count() * sizeof(int), model.indices, GL_STATIC_DRAW);

		glExt::bindVertexArray(0);


		return 1;
	}

	void glGameModel::drawTriangles() {
		glExt::bindVertexArray(vao);
		glDrawElements(GL_TRIANGLES, ind, GL_UNSIGNED_INT, 0);
	}

	void glGameModel::drawQuads() {
		glExt::bindVertexArray(vao);
		glDrawArrays(GL_QUADS, 0, ind);
		//glDrawElements(GL_QUADS, ind, GL_UNSIGNED_INT, 0);
	}
}
