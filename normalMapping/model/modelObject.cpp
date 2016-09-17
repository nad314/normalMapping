#include <main/main.h>

namespace core {
	glGameMesh::~glGameMesh() {
		if (glExt::isBuffer(buff[0]))
			glExt::deleteBuffers(4, buff);
		if (glExt::isVertexArray(vao))
			glExt::deleteVertexArrays(1, &vao);
		memset(buff, 0, sizeof(buff));
		ind = 0;
	}

	bool glGameMesh::make(GameMesh& mesh, glShader& shader, const char* pos, const char* nor, const char* tex) {
		if (mesh.position.count() < 1 || mesh.indices.count() < 0)
			return 0;

		ind = mesh.indices.count();
		int index;

		vao = 0;
		glExt::genVertexArrays(1, &vao);
		glExt::genBuffers(4, buff);
		glExt::bindVertexArray(vao);

		glExt::bindBuffer(GL_ARRAY_BUFFER, buff[0]);
		glExt::bufferData(GL_ARRAY_BUFFER, mesh.position.count() * sizeof(vec3), mesh.position, GL_STATIC_DRAW);
		index = glExt::getAttribLocation(shader.program, pos);
		glExt::enableVertexAttribArray(index);
		glExt::vertexAttribPointer(index, 3, GL_FLOAT, false, 0, 0);
		
		glExt::bindBuffer(GL_ARRAY_BUFFER, buff[1]);
		glExt::bufferData(GL_ARRAY_BUFFER, mesh.normal.count() * sizeof(vec3), mesh.normal, GL_STATIC_DRAW);
		index = glExt::getAttribLocation(shader.program, nor);
		glExt::enableVertexAttribArray(index);
		glExt::vertexAttribPointer(index, 3, GL_FLOAT, false, 0, 0);

		glExt::bindBuffer(GL_ARRAY_BUFFER, buff[2]);
		glExt::bufferData(GL_ARRAY_BUFFER, mesh.texcoord.count() * sizeof(vec2), mesh.texcoord, GL_STATIC_DRAW);
		index = glExt::getAttribLocation(shader.program, tex);
		glExt::enableVertexAttribArray(index);
		glExt::vertexAttribPointer(index, 2, GL_FLOAT, false, 0, 0);

		glExt::bindBuffer(GL_ELEMENT_ARRAY_BUFFER, buff[3]);
		glExt::bufferData(GL_ELEMENT_ARRAY_BUFFER, mesh.indices.count() * sizeof(int), mesh.indices, GL_STATIC_DRAW);

		glExt::bindVertexArray(0);


		return 1;
	}

	void glGameMesh::drawTriangles() {
		glExt::bindVertexArray(vao);
		glDrawElements(GL_TRIANGLES, ind, GL_UNSIGNED_INT, 0);
	}

	void glGameMesh::drawQuads() {
		glExt::bindVertexArray(vao);
		glDrawElements(GL_QUADS, ind, GL_UNSIGNED_INT, 0);
	}
}
