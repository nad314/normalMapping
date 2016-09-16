#pragma once

struct Storage: public core::SIMD {
public:
	core::glView view;
	core::glGameModel model;
	core::glShader shader;
	Storage();
};
