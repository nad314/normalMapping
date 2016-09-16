#version 430

in vec3 pos;
in vec3 nor;
in vec2 tex;

uniform mat4 modelview;
uniform mat4 projection;

out vdata {
	vec3 pos;
	vec3 nor;
	vec2 tex;
} vOut;

void main(void) {
	vOut.pos = pos;
	vOut.nor = nor;
	vOut.tex = tex;
	gl_Position = projection*modelview*vec4(pos.xyz, 1.0);
}
