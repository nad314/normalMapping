#pragma once
#include <gl/glExtensions.defines.h>
namespace core {
	namespace opengl {
		class glExt {
		private:
			static int errCounter;
			static void* get(const char* name);
		public:
			static buffer<int> error;

			typedef int GLsizeiptrARB;
			typedef int GLintptrARB;
			typedef unsigned int GLhandleARB;
			typedef char GLcharARB;

			static void init();

			//buffers
			static void (APIENTRY* bindBuffer) (GLenum target, GLuint buffer);
			static void (APIENTRY* bufferData) (GLenum target, GLsizeiptrARB size, const GLvoid* data, GLenum usage);
			static void (APIENTRY* bufferSubData) (GLenum target, GLintptrARB offset, GLsizeiptrARB size, const GLvoid* data);
			static void (APIENTRY* deleteBuffers) (GLsizei n, const GLuint* buffers);
			static void (APIENTRY* genBuffers) (GLsizei n, GLuint* buffers);
			static void (APIENTRY* getBufferParameteriv) (GLenum target, GLenum pname, GLint* params);
			static void (APIENTRY* getBufferPointerv) (GLenum target, GLenum pname, GLvoid** params);
			static void (APIENTRY* getBufferSubData) (GLenum target, GLintptrARB offset, GLsizeiptrARB size, GLvoid* data);
			static GLboolean(APIENTRY* isBuffer) (GLuint buffer);
			static GLvoid* (APIENTRY* mapBuffer) (GLenum target, GLenum access);
			static GLvoid* (APIENTRY* mapBufferRange) (GLenum target, GLintptrARB offset, GLsizeiptrARB length, GLenum access);
			static GLboolean(APIENTRY* unmapBuffer) (GLenum target);
			static void (APIENTRY* bufferStorage) (GLenum, GLsizeiptrARB, const GLvoid*, GLbitfield);
			static void (APIENTRY* bindBufferBase) (GLenum target, GLuint index, GLuint buffer);

			//arrays
			static void (APIENTRY* genVertexArrays) (GLsizei n, GLuint *arrays);
			static void (APIENTRY* bindVertexArray) (GLuint array);
			static void (APIENTRY* deleteVertexArrays) (GLsizei n, GLuint *arrays);
			static void (APIENTRY* enableVertexAttribArray) (GLuint index);
			static void (APIENTRY* vertexAttribPointer) (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid* pointer);
			static GLboolean(APIENTRY* isVertexArray) (GLuint array);

			//framebuffers
			static void (APIENTRY* genFramebuffers) (GLsizei n, GLuint *framebuffers);
			static void (APIENTRY* deleteFramebuffers) (GLsizei n, const GLuint *framebuffers);
			static void (APIENTRY* bindFramebuffer) (GLenum target, GLuint framebuffer);
			static void (APIENTRY* framebufferTexture2D) (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
			static void (APIENTRY* genRenderBuffers) (GLsizei n, GLuint *buffer);
			static void (APIENTRY* deleteRenderBuffers) (GLsizei n, const GLuint *buffer);
			static void (APIENTRY* bindRenderBuffer) (GLenum target, const GLuint buffer);
			static void (APIENTRY* franebufferRenderbuffer) (GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
			static void (APIENTRY* renderbufferStorage) (GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
			static GLenum(APIENTRY* checkFramebufferStatus) (GLenum target);
			static void (APIENTRY* blitFramebuffer) (GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
			static void (APIENTRY* drawBuffers) (GLsizei n, const GLenum *bufs);

			//misc
			static void (APIENTRY* memoryBarrier) (GLbitfield barriers);
			static void (APIENTRY* texStorage2D) (GLenum target, GLsizei levels, GLenum internalFormat, GLsizei width, GLsizei height);

			//shaders
			static GLint(APIENTRY* deleteObject) (GLenum object);
			static void (APIENTRY* shaderSource) (GLenum shader, GLenum number_strings, const char **strings, GLint *length);
			static void (APIENTRY* compileShader) (GLenum shader);
			static void (APIENTRY* attachObject) (GLenum program, GLenum shader);
			static void (APIENTRY* linkProgram) (GLenum program);
			static void (APIENTRY* useProgramObject) (GLhandleARB object);
			static void (APIENTRY* useProgram) (GLuint program);
			static GLhandleARB(APIENTRY* createProgramObject) ();
			static GLhandleARB(APIENTRY* createShaderObject) (GLenum shaderType);
			static void (APIENTRY* activeTexture) (GLenum texture);
			static GLint (APIENTRY* getUniformLocation) (GLhandleARB program, const GLcharARB *name);
			static GLint (APIENTRY* getAttribLocation) (GLhandleARB program, const GLcharARB *name);
			static void (APIENTRY* getShaderInfoLog) (GLuint shader, GLsizei maxLength, GLsizei *length, GLcharARB *infoLog);
			static void (APIENTRY* bindFragDataLocation) (GLuint program, GLuint colorNumber, const char *name);
			static void (APIENTRY* uniform1i) (GLint location, GLint v0);
			static void (APIENTRY* uniformMatrix4fv) (GLint location, GLsizei count, bool transpose, const GLfloat *value);
			static void (APIENTRY* uniformMatrix4dv) (GLint location, GLsizei count, bool transpose, const GLdouble *value);
			static void (APIENTRY* uniform4fv) (GLint location, int count, GLfloat *v0);
			static void (APIENTRY* uniformMatrix3fv) (GLint location, GLsizei count, bool transpose, const GLfloat *value);
			static void (APIENTRY* uniform1f) (GLint location, GLfloat v0);
			static void (APIENTRY* uniform4iv) (GLint location, int count, GLint *v0);
			static void (APIENTRY* uniform3fv) (GLint location, int count, GLfloat *v0);
			static void (APIENTRY* uniform2fv) (GLint location, int count, GLfloat* v0);
			static GLboolean (APIENTRY* isProgram) (GLuint program);
			static GLboolean (APIENTRY* isShader) (GLuint shader);


			//compute
			static void (APIENTRY* dispatchCompute) (GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z);
			static GLuint(APIENTRY* getProgramResourceIndex) (GLuint program, GLenum programInterface, const char* name);
			static void (APIENTRY* shaderStorageBlockBinding) (GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding);
			static void (APIENTRY* bindImageTexture) (GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format);
		};
	}
}