#include <main/main.h>

namespace core {
	void GameMesh::computeNormals() {
		vec3 nor;
		int i;
		normal.reserve(position.count());
		normal.count() = position.count();
		for (i = 0; i < normal.count(); ++i)
			normal[i] = vec3(0.0f);
		for (i = 0; i < indices.count(); i += 3) {
			nor = vector::normal(position[indices[i]], position[indices[i+1]], position[indices[i+2]]);
			normal[indices[i]] += nor;
			normal[indices[i+1]] += nor;
			normal[indices[i+2]] += nor;
		}
		for (i = 0; i < normal.count(); ++i)
			normal[i].normalize();
	}

	void GameMesh::computeTangentSpace(buffer<vec3>& tangents, buffer<vec3>& bitangents) {

	}
}
