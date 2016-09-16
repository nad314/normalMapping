#include <main/main.h>

void Cube::make(const float& r) {
	position.push_back(core::vec3(-r, -r, -r));
	position.push_back(core::vec3(r, -r, -r));
	position.push_back(core::vec3(r, r, -r));
	position.push_back(core::vec3(-r, r, -r));

	position.push_back(core::vec3(r, -r, r));
	position.push_back(core::vec3(-r, -r, r));
	position.push_back(core::vec3(-r, r, r));
	position.push_back(core::vec3(r, r, r));

	position.push_back(core::vec3(-r, -r, -r));
	position.push_back(core::vec3(-r, r, -r));
	position.push_back(core::vec3(-r, r, r));
	position.push_back(core::vec3(-r, -r, r));

	position.push_back(core::vec3(r, r, -r));
	position.push_back(core::vec3(r, -r, -r));
	position.push_back(core::vec3(r, -r, r));
	position.push_back(core::vec3(r, r, r));

	position.push_back(core::vec3(-r, -r, -r));
	position.push_back(core::vec3(r, -r, -r));
	position.push_back(core::vec3(r, -r, r));
	position.push_back(core::vec3(-r, -r, r));

	position.push_back(core::vec3(-r, r, -r));
	position.push_back(core::vec3(r, r, -r));
	position.push_back(core::vec3(r, r, r));
	position.push_back(core::vec3(-r, r, r));

	normal.push_back(core::vec3(0.0f, 0.0f, -1.0f));
	normal.push_back(core::vec3(0.0f, 0.0f, -1.0f));
	normal.push_back(core::vec3(0.0f, 0.0f, -1.0f));
	normal.push_back(core::vec3(0.0f, 0.0f, -1.0f));

	normal.push_back(core::vec3(0.0f, 0.0f, 1.0f));
	normal.push_back(core::vec3(0.0f, 0.0f, 1.0f));
	normal.push_back(core::vec3(0.0f, 0.0f, 1.0f));
	normal.push_back(core::vec3(0.0f, 0.0f, 1.0f));

	normal.push_back(core::vec3(-1.0f, 0.0f, 0.0f));
	normal.push_back(core::vec3(-1.0f, 0.0f, 0.0f));
	normal.push_back(core::vec3(-1.0f, 0.0f, 0.0f));
	normal.push_back(core::vec3(-1.0f, 0.0f, 0.0f));

	normal.push_back(core::vec3(1.0f, 0.0f, 0.0f));
	normal.push_back(core::vec3(1.0f, 0.0f, 0.0f));
	normal.push_back(core::vec3(1.0f, 0.0f, 0.0f));
	normal.push_back(core::vec3(1.0f, 0.0f, 0.0f));

	normal.push_back(core::vec3(0.0f, -1.0f, 0.0f));
	normal.push_back(core::vec3(0.0f, -1.0f, 0.0f));
	normal.push_back(core::vec3(0.0f, -1.0f, 0.0f));
	normal.push_back(core::vec3(0.0f, -1.0f, 0.0f));

	normal.push_back(core::vec3(0.0f, 1.0f, 0.0f));
	normal.push_back(core::vec3(0.0f, 1.0f, 0.0f));
	normal.push_back(core::vec3(0.0f, 1.0f, 0.0f));
	normal.push_back(core::vec3(0.0f, 1.0f, 0.0f));

	for (int i = 0; i < 6; ++i) {
		texcoord.push_back(core::vec2(0, 0));
		texcoord.push_back(core::vec2(1, 0));
		texcoord.push_back(core::vec2(1, 1));
		texcoord.push_back(core::vec2(0, 1));
	}

	for (int i=0;i<24;++i)
		indices.push_back(i);
}