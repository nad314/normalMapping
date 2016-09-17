#include <main/main.h>

Storage::Storage() {
	core::Path::pushDir();
	core::Path::goHome();
	core::Path::cd("../data/");
	Cube cube;
	if (!shader.load("vertex.glsl", "fragment.glsl", "fragColor"))
		core::Debug::print("Could not load shaders\n");
	else shader.printDebugInfo();
	model.make(cube, shader, "pos", "nor", "tan", "btan", "tex");
	if (!diffuse.loadPng("dirt_diffuse.png"))
		core::Debug::print("Couldn't load texture map\n");
	if (!normal.loadPng("dirt_normal.png"))
		core::Debug::print("Couldn't load normal map\n");
	core::Path::popDir();
}
