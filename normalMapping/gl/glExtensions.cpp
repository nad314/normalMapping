#include <main/main.h>

namespace core {
	buffer<int> glExt::error;
	int glExt::errCounter;

	void (APIENTRY* glExt::bindBuffer) (GLenum target, GLuint buffer);
	void (APIENTRY* glExt::bufferData) (GLenum target, GLsizeiptrARB size, const GLvoid* data, GLenum usage);
	void (APIENTRY* glExt::bufferSubData) (GLenum target, GLintptrARB offset, GLsizeiptrARB size, const GLvoid* data);
	void (APIENTRY* glExt::deleteBuffers) (GLsizei n, const GLuint* buffers);
	void (APIENTRY* glExt::genBuffers) (GLsizei n, GLuint* buffers);
	void (APIENTRY* glExt::getBufferParameteriv) (GLenum target, GLenum pname, GLint* params);
	void (APIENTRY* glExt::getBufferPointerv) (GLenum target, GLenum pname, GLvoid** params);
	void (APIENTRY* glExt::getBufferSubData) (GLenum target, GLintptrARB offset, GLsizeiptrARB size, GLvoid* data);
	GLboolean (APIENTRY* glExt::isBuffer) (GLuint buffer);
	GLvoid* (APIENTRY* glExt::mapBuffer) (GLenum target, GLenum access);
	GLvoid* (APIENTRY* glExt::mapBufferRange) (GLenum target, GLintptrARB offset, GLsizeiptrARB length, GLenum access);
	GLboolean (APIENTRY* glExt::unmapBuffer) (GLenum target);
	void (APIENTRY* glExt::bufferStorage) (GLenum, GLsizeiptrARB, const GLvoid*, GLbitfield);
	void (APIENTRY* glExt::bindBufferBase) (GLenum target, GLuint index, GLuint buffer);

	void (APIENTRY* glExt::genVertexArrays) (GLsizei n, GLuint *arrays);
	void (APIENTRY* glExt::bindVertexArray) (GLuint array);
	void (APIENTRY* glExt::deleteVertexArrays) (GLsizei n, GLuint *arrays);
	void (APIENTRY* glExt::enableVertexAttribArray) (GLuint index);
	void (APIENTRY* glExt::vertexAttribPointer) (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid* pointer);

	void (APIENTRY* glExt::genFramebuffers) (GLsizei n, GLuint *framebuffers);
	void (APIENTRY* glExt::deleteFramebuffers) (GLsizei n, const GLuint *framebuffers);
	void (APIENTRY* glExt::bindFramebuffer) (GLenum target, GLuint framebuffer);
	void (APIENTRY* glExt::framebufferTexture2D) (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
	void (APIENTRY* glExt::genRenderBuffers) (GLsizei n, GLuint *buffer);
	void (APIENTRY* glExt::deleteRenderBuffers) (GLsizei n, const GLuint *buffer);
	void (APIENTRY* glExt::bindRenderBuffer) (GLenum target, const GLuint buffer);
	void (APIENTRY* glExt::franebufferRenderbuffer) (GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
	void (APIENTRY* glExt::renderbufferStorage) (GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
	GLenum (APIENTRY* glExt::checkFramebufferStatus) (GLenum target);
	void (APIENTRY* glExt::blitFramebuffer) (GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
	void (APIENTRY* glExt::drawBuffers) (GLsizei n, const GLenum *bufs);

	void (APIENTRY* glExt::memoryBarrier) (GLbitfield barriers);
	void (APIENTRY* glExt::texStorage2D) (GLenum target, GLsizei levels, GLenum internalFormat, GLsizei width, GLsizei height);


	void* glExt::get(const char* name) {
		void *f = wglGetProcAddress(name);
		if (!f) error.push_back(errCounter);
		++errCounter;
		return f;
	}


	void glExt::init() {
		error.clear();
		errCounter = 0;
		bindBuffer = (decltype(bindBuffer))get("glBindBufferARB");
		bufferData = (decltype(bufferData))get("glBufferDataARB");
		bufferSubData = (decltype(bufferSubData))get("glBufferSubDataARB");
		deleteBuffers = (decltype(deleteBuffers))get("glDeleteBuffersARB");
		genBuffers = (decltype(genBuffers))get("glGenBuffersARB");
		getBufferParameteriv = (decltype(getBufferParameteriv))get("glGetBufferParameterivARB");
		getBufferPointerv = (decltype(getBufferPointerv))get("glGetBufferPointervARB");
		getBufferSubData = (decltype(getBufferSubData))get("glGetBufferSubDataARB");
		isBuffer = (decltype(isBuffer))get("glIsBufferARB");
		mapBuffer = (decltype(mapBuffer))get("glMapBufferARB");
		mapBufferRange = (decltype(mapBufferRange))get("glMapBufferRange");
		unmapBuffer = (decltype(unmapBuffer))get("glUnmapBufferARB");
		bufferStorage = (decltype(bufferStorage))get("glBufferStorage");
		bindBufferBase = (decltype(bindBufferBase))get("glBindBufferBase");

		genVertexArrays = (decltype(genVertexArrays))get("glGenVertexArrays");
		bindVertexArray = (decltype(bindVertexArray))get("glBindVertexArray");
		deleteVertexArrays = (decltype(deleteVertexArrays))get("glDeleteVertexArrays");
		enableVertexAttribArray = (decltype(enableVertexAttribArray))get("glEnableVertexAttribArray");
		vertexAttribPointer = (decltype(vertexAttribPointer))get("glVertexAttribPointer");

		genFramebuffers = (decltype(genFramebuffers))get("glGenFramebuffersEXT");
		deleteFramebuffers = (decltype(deleteFramebuffers))get("glDeleteFramebuffersEXT");
		bindFramebuffer = (decltype(bindFramebuffer))get("glBindFramebufferEXT");
		framebufferTexture2D = (decltype(framebufferTexture2D))get("glFramebufferTexture2DEXT");
		genRenderBuffers = (decltype(genRenderBuffers))get("glGenRenderbuffersEXT");
		deleteRenderBuffers = (decltype(deleteRenderBuffers))get("glDeleteRenderbuffersEXT");
		bindRenderBuffer = (decltype(bindRenderBuffer))get("glBindRenderbufferEXT");
		franebufferRenderbuffer = (decltype(franebufferRenderbuffer))get("glFramebufferRenderbufferEXT");
		renderbufferStorage = (decltype(renderbufferStorage))get("glRenderbufferStorageEXT");
		checkFramebufferStatus = (decltype(checkFramebufferStatus))get("glCheckFramebufferStatusEXT");
		blitFramebuffer = (decltype(blitFramebuffer))get("glBlitFramebufferEXT");
		drawBuffers = (decltype(drawBuffers))get("glDrawBuffers");

		memoryBarrier = (decltype(memoryBarrier))get("glMemoryBarrier");
		texStorage2D = (decltype(texStorage2D))get("glTexStorage2D");
	}
}