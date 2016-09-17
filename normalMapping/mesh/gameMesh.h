#pragma once

namespace core {
	class GameMesh {
	public:
		buffer<vec3> position;
		buffer<vec3> normal;
		buffer<vec2> texcoord;
		buffer<int> indices;

		void computeNormals();
		void computeTangentSpace(buffer<vec3>& tangents, buffer<vec3>& bitangents);
	};
}
