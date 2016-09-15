#pragma once
#include <gl/glExtensions.defines.h>
namespace core {
	class glExt {
	private:
		static int errCounter;
		static void* get(const char* name);
	public:
		static buffer<int> error;

		typedef int GLsizeiptrARB;
		typedef int GLintptrARB;

		static void init();

		static void (APIENTRY* bindBuffer) (GLenum target, GLuint buffer);
		static void (APIENTRY* bufferData) (GLenum target, GLsizeiptrARB size, const GLvoid* data, GLenum usage);
		static void (APIENTRY* bufferSubData) (GLenum target, GLintptrARB offset, GLsizeiptrARB size, const GLvoid* data);
		static void (APIENTRY* deleteBuffers) (GLsizei n, const GLuint* buffers);
		static void (APIENTRY* genBuffers) (GLsizei n, GLuint* buffers);
		static void (APIENTRY* getBufferParameteriv) (GLenum target, GLenum pname, GLint* params);
		static void (APIENTRY* getBufferPointerv) (GLenum target, GLenum pname, GLvoid** params);
		static void (APIENTRY* getBufferSubData) (GLenum target, GLintptrARB offset, GLsizeiptrARB size, GLvoid* data);
		static GLboolean (APIENTRY* isBuffer) (GLuint buffer);
		static GLvoid* (APIENTRY* mapBuffer) (GLenum target, GLenum access);
		static GLvoid* (APIENTRY* mapBufferRange) (GLenum target, GLintptrARB offset, GLsizeiptrARB length, GLenum access);
		static GLboolean (APIENTRY* unmapBuffer) (GLenum target);
		static void (APIENTRY* bufferStorage) (GLenum, GLsizeiptrARB, const GLvoid*, GLbitfield);
		static void (APIENTRY* bindBufferBase) (GLenum target, GLuint index, GLuint buffer);

		static void (APIENTRY* genVertexArrays) (GLsizei n, GLuint *arrays);
		static void (APIENTRY* bindVertexArray) (GLuint array);
		static void (APIENTRY* deleteVertexArrays) (GLsizei n, GLuint *arrays);
		static void (APIENTRY* enableVertexAttribArray) (GLuint index);
		static void (APIENTRY* vertexAttribPointer) (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid* pointer);

		static void (APIENTRY* genFramebuffers) (GLsizei n, GLuint *framebuffers);
		static void (APIENTRY* deleteFramebuffers) (GLsizei n, const GLuint *framebuffers);
		static void (APIENTRY* bindFramebuffer) (GLenum target, GLuint framebuffer);
		static void (APIENTRY* framebufferTexture2D) (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
		static void (APIENTRY* genRenderBuffers) (GLsizei n, GLuint *buffer);
		static void (APIENTRY* deleteRenderBuffers) (GLsizei n, const GLuint *buffer);
		static void (APIENTRY* bindRenderBuffer) (GLenum target, const GLuint buffer);
		static void (APIENTRY* franebufferRenderbuffer) (GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
		static void (APIENTRY* renderbufferStorage) (GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
		static GLenum (APIENTRY* checkFramebufferStatus) (GLenum target);
		static void (APIENTRY* blitFramebuffer) (GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
		static void (APIENTRY* drawBuffers) (GLsizei n, const GLenum *bufs);

		static void (APIENTRY* memoryBarrier) (GLbitfield barriers);
		static void (APIENTRY* texStorage2D) (GLenum target, GLsizei levels, GLenum internalFormat, GLsizei width, GLsizei height);
	};
}