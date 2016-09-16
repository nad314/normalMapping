#version 430
in vdata {
	vec3 pos;
	vec3 nor;
	vec2 tex;
} vIn;

out vec4 fragColor;

void main(void) {
	vec3 normal = normalize(vIn.nor);
	vec3 lightDir = normalize(vIn.pos.xyz - vec3(1.0f, 1.0f, 3.0f));
	vec2 texcoord = vIn.tex;
	fragColor = vec4(smoothstep(0.0f, 1.0f, vec3(1.0)*dot(lightDir, normal)), 1.0);
}
