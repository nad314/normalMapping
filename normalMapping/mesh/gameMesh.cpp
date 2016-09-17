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
		tangents.reserve(position.count());
		tangents.count() = position.count();
		bitangents.reserve(position.count());
		bitangents.count() = position.count();
		int i;
		for (i = 0; i < tangents.count(); ++i) {
			tangents[i] = vec3(0.0f);
			bitangents[i] = vec3(0.0f);
		}

		for (i = 0; i < indices.count(); i += 3) {
			vec3 d1 = position[indices[i + 1]] - position[indices[i]];
			vec3 d2 = position[indices[i + 2]] - position[indices[i]];
			vec2 uv1 = texcoord[indices[i + 1]] - texcoord[indices[i]];
			vec2 uv2 = texcoord[indices[i + 2]] - texcoord[indices[i]];

			float r = 1.0f / (uv1.x*uv2.y - uv1.y*uv2.x);
			vec3 tg = ((d1*uv2.y - d2*uv1.y)*r).normalize();
			vec3 btg = ((d2*uv1.x - d1*uv2.x)*r).normalize();

			tangents[indices[i]] += tg;
			tangents[indices[i+1]] += tg;
			tangents[indices[i+2]] += tg;

			bitangents[indices[i]] += btg;
			bitangents[indices[i+1]] += btg;
			bitangents[indices[i+2]] += btg;
		}

		for (i = 0; i < tangents.count(); ++i) {
			tangents[i].normalize();
			bitangents[i].normalize();
		}

	}
}
