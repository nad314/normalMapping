#include <main/main.h>
namespace core {
	void glShader::dispose() {
		if (glExt::isProgram(program))
			glExt::deleteObject(program);
		if (glExt::isShader(fragment))
			glExt::deleteObject(fragment);
		if (glExt::isShader(vertex))
			glExt::deleteObject(vertex);
		vertex = fragment = program = 0;
	}

	bool glShader::load(const char* vertexPath, const char* fragmentPath, const char* fragName) {
		char *v=NULL, *f=NULL;
		if (!Path::fileToString(vertexPath, &v)) return 0;
		if (!Path::fileToString(fragmentPath, &f)) { delete[] v; return 0; }

		program = vertex = fragment = 0;

		program = glExt::createProgramObject();
		vertex = glExt::createShaderObject(GL_VERTEX_SHADER_ARB);
		fragment = glExt::createShaderObject(GL_FRAGMENT_SHADER_ARB);

		glExt::shaderSource(vertex, 1, const_cast<const char**>(&v), NULL);
		glExt::shaderSource(fragment, 1, const_cast<const char**>(&f), NULL);

		glExt::compileShader(vertex);
		glExt::compileShader(fragment);

		glExt::attachObject(program, vertex);
		glExt::attachObject(program, fragment);

		glExt::bindFragDataLocation(program, 0, fragName);
		glExt::linkProgram(program);

		delete[] v;
		delete[] f;

		Debug::print("Shader Error: %d\n", glGetError());

		return 1;
	}

	void glShader::printDebugInfo() {
		char c[256];
		int l;
		glExt::getShaderInfoLog(vertex, 256, &l, c);
		Debug::print("Vertex Shader Log:\n%s\n", c);
		glExt::getShaderInfoLog(fragment, 256, &l, c);
		Debug::print("Fragment Shader Log:\n%s\n", c);
	}
}
