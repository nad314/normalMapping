#include <main/main.h>

namespace core {
	namespace opengl {
		buffer<int> glExt::error;
		int glExt::errCounter;

		//buffers
		void (APIENTRY* glExt::bindBuffer) (GLenum target, GLuint buffer);
		void (APIENTRY* glExt::bufferData) (GLenum target, GLsizeiptrARB size, const GLvoid* data, GLenum usage);
		void (APIENTRY* glExt::bufferSubData) (GLenum target, GLintptrARB offset, GLsizeiptrARB size, const GLvoid* data);
		void (APIENTRY* glExt::deleteBuffers) (GLsizei n, const GLuint* buffers);
		void (APIENTRY* glExt::genBuffers) (GLsizei n, GLuint* buffers);
		void (APIENTRY* glExt::getBufferParameteriv) (GLenum target, GLenum pname, GLint* params);
		void (APIENTRY* glExt::getBufferPointerv) (GLenum target, GLenum pname, GLvoid** params);
		void (APIENTRY* glExt::getBufferSubData) (GLenum target, GLintptrARB offset, GLsizeiptrARB size, GLvoid* data);
		GLboolean(APIENTRY* glExt::isBuffer) (GLuint buffer);
		GLvoid* (APIENTRY* glExt::mapBuffer) (GLenum target, GLenum access);
		GLvoid* (APIENTRY* glExt::mapBufferRange) (GLenum target, GLintptrARB offset, GLsizeiptrARB length, GLenum access);
		GLboolean(APIENTRY* glExt::unmapBuffer) (GLenum target);
		void (APIENTRY* glExt::bufferStorage) (GLenum, GLsizeiptrARB, const GLvoid*, GLbitfield);
		void (APIENTRY* glExt::bindBufferBase) (GLenum target, GLuint index, GLuint buffer);

		//arrays
		void (APIENTRY* glExt::genVertexArrays) (GLsizei n, GLuint *arrays);
		void (APIENTRY* glExt::bindVertexArray) (GLuint array);
		void (APIENTRY* glExt::deleteVertexArrays) (GLsizei n, GLuint *arrays);
		void (APIENTRY* glExt::enableVertexAttribArray) (GLuint index);
		void (APIENTRY* glExt::vertexAttribPointer) (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid* pointer);
		GLboolean (APIENTRY* glExt::isVertexArray) (GLuint array);

		//framebuffers
		void (APIENTRY* glExt::genFramebuffers) (GLsizei n, GLuint *framebuffers);
		void (APIENTRY* glExt::deleteFramebuffers) (GLsizei n, const GLuint *framebuffers);
		void (APIENTRY* glExt::bindFramebuffer) (GLenum target, GLuint framebuffer);
		void (APIENTRY* glExt::framebufferTexture2D) (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
		void (APIENTRY* glExt::genRenderBuffers) (GLsizei n, GLuint *buffer);
		void (APIENTRY* glExt::deleteRenderBuffers) (GLsizei n, const GLuint *buffer);
		void (APIENTRY* glExt::bindRenderBuffer) (GLenum target, const GLuint buffer);
		void (APIENTRY* glExt::franebufferRenderbuffer) (GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
		void (APIENTRY* glExt::renderbufferStorage) (GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
		GLenum(APIENTRY* glExt::checkFramebufferStatus) (GLenum target);
		void (APIENTRY* glExt::blitFramebuffer) (GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
		void (APIENTRY* glExt::drawBuffers) (GLsizei n, const GLenum *bufs);

		//misc
		void (APIENTRY* glExt::memoryBarrier) (GLbitfield barriers);
		void (APIENTRY* glExt::texStorage2D) (GLenum target, GLsizei levels, GLenum internalFormat, GLsizei width, GLsizei height);

		//shaders
		GLint(APIENTRY* glExt::deleteObject) (GLenum object);
		void (APIENTRY* glExt::shaderSource) (GLenum shader, GLenum number_strings, const char **strings, GLint *length);
		void (APIENTRY* glExt::compileShader) (GLenum shader);
		void (APIENTRY* glExt::attachObject) (GLenum program, GLenum shader);
		void (APIENTRY* glExt::linkProgram) (GLenum program);
		void (APIENTRY* glExt::useProgramObject) (GLhandleARB object);
		glExt::GLhandleARB(APIENTRY* glExt::createProgramObject) ();
		glExt::GLhandleARB(APIENTRY* glExt::createShaderObject) (GLenum shaderType);
		void (APIENTRY* glExt::activeTexture) (GLenum texture);
		GLint(APIENTRY* glExt::getUniformLocation) (GLhandleARB program, const GLcharARB *name);
		GLint(APIENTRY* glExt::getAttribLocation) (GLhandleARB program, const GLcharARB *name);
		void (APIENTRY* glExt::getShaderInfoLog) (GLuint shader, GLsizei maxLength, GLsizei *length, GLcharARB *infoLog);
		void (APIENTRY* glExt::bindFragDataLocation) (GLuint program, GLuint colorNumber, const char *name);
		void (APIENTRY* glExt::uniform1i) (GLint location, GLint v0);
		void (APIENTRY* glExt::uniformMatrix4fv) (GLint location, GLsizei count, bool transpose, const GLfloat *value);
		void (APIENTRY* glExt::uniformMatrix4dv) (GLint location, GLsizei count, bool transpose, const GLdouble *value);
		void (APIENTRY* glExt::uniform4fv) (GLint location, int count, GLfloat *v0);
		void (APIENTRY* glExt::uniformMatrix3fv) (GLint location, GLsizei count, bool transpose, const GLfloat *value);
		void (APIENTRY* glExt::uniform1f) (GLint location, GLfloat v0);
		void (APIENTRY* glExt::uniform4iv) (GLint location, int count, GLint *v0);
		void (APIENTRY* glExt::uniform3fv) (GLint location, int count, GLfloat *v0);
		void (APIENTRY* glExt::uniform2fv) (GLint location, int count, GLfloat* v0);
		GLboolean (APIENTRY* glExt::isProgram) (GLuint program);
		GLboolean (APIENTRY* glExt::isShader) (GLuint shader);

		//compute
		void (APIENTRY* glExt::dispatchCompute) (GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z);
		GLuint(APIENTRY* glExt::getProgramResourceIndex) (GLuint program, GLenum programInterface, const char* name);
		void (APIENTRY* glExt::shaderStorageBlockBinding) (GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding);
		void (APIENTRY* glExt::bindImageTexture) (GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format);

		void* glExt::get(const char* name) {
			static char extName[256];
			void *f = wglGetProcAddress(name);
			if (!f) {
				memset(extName, 0, sizeof(extName));
				strcpy(extName, name);
				strcat(extName, "ARB");
				f = wglGetProcAddress(extName);
			}
			if (!f) {
				error.push_back(errCounter);
				printf("error: %s\n", name);
			}
			++errCounter;
			return f;
		}


		void glExt::init() {
			error.clear();
			errCounter = 0;
			//buffers
			bindBuffer = (decltype(bindBuffer))get("glBindBuffer");
			bufferData = (decltype(bufferData))get("glBufferData");
			bufferSubData = (decltype(bufferSubData))get("glBufferSubData");
			deleteBuffers = (decltype(deleteBuffers))get("glDeleteBuffers");
			genBuffers = (decltype(genBuffers))get("glGenBuffers");
			getBufferParameteriv = (decltype(getBufferParameteriv))get("glGetBufferParameteriv");
			getBufferPointerv = (decltype(getBufferPointerv))get("glGetBufferPointerv");
			getBufferSubData = (decltype(getBufferSubData))get("glGetBufferSubData");
			isBuffer = (decltype(isBuffer))get("glIsBuffer");
			mapBuffer = (decltype(mapBuffer))get("glMapBuffer");
			mapBufferRange = (decltype(mapBufferRange))get("glMapBufferRange");
			unmapBuffer = (decltype(unmapBuffer))get("glUnmapBuffer");
			bufferStorage = (decltype(bufferStorage))get("glBufferStorage");
			bindBufferBase = (decltype(bindBufferBase))get("glBindBufferBase");

			//arrays
			genVertexArrays = (decltype(genVertexArrays))get("glGenVertexArrays");
			bindVertexArray = (decltype(bindVertexArray))get("glBindVertexArray");
			deleteVertexArrays = (decltype(deleteVertexArrays))get("glDeleteVertexArrays");
			enableVertexAttribArray = (decltype(enableVertexAttribArray))get("glEnableVertexAttribArray");
			vertexAttribPointer = (decltype(vertexAttribPointer))get("glVertexAttribPointer");
			isVertexArray = (decltype(isVertexArray))get("glIsVertexArray");

			//framebuffers
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

			//misc
			memoryBarrier = (decltype(memoryBarrier))get("glMemoryBarrier");
			texStorage2D = (decltype(texStorage2D))get("glTexStorage2D");

			//shaders
			deleteObject = (decltype(deleteObject))get("glDeleteObject");
			shaderSource = (decltype(shaderSource))get("glShaderSource");
			compileShader = (decltype(compileShader))get("glCompileShader");
			attachObject = (decltype(attachObject))get("glAttachObject");
			linkProgram = (decltype(linkProgram))get("glLinkProgram");
			useProgramObject = (decltype(useProgramObject))get("glUseProgramObject");
			createProgramObject = (decltype(createProgramObject))get("glCreateProgramObject");
			createShaderObject = (decltype(createShaderObject))get("glCreateShaderObject");
			activeTexture = (decltype(activeTexture))get("glActiveTexture");
			getUniformLocation = (decltype(getUniformLocation))get("glGetUniformLocation");
			getAttribLocation = (decltype(getAttribLocation))get("glGetAttribLocation");
			getShaderInfoLog = (decltype(getShaderInfoLog))get("glGetShaderInfoLog");
			bindFragDataLocation = (decltype(bindFragDataLocation))get("glBindFragDataLocation");
			uniform1i = (decltype(uniform1i))get("glUniform1i");
			uniform1f = (decltype(uniform1f))get("glUniform1f");
			uniformMatrix4fv = (decltype(uniformMatrix4fv))get("glUniformMatrix4fv");
			uniformMatrix4dv = (decltype(uniformMatrix4dv))get("glUniformMatrix4dv");
			uniform4fv = (decltype(uniform4fv))get("glUniform4fv");
			uniformMatrix3fv = (decltype(uniformMatrix3fv))get("glUniformMatrix3fv");
			uniform3fv = (decltype(uniform3fv))get("glUniform3fv");
			uniform2fv = (decltype(uniform2fv))get("glUniform2fv");
			uniform4iv = (decltype(uniform4iv))get("glUniform4iv");
			isProgram = (decltype(isProgram))get("glIsProgram");
			isShader = (decltype(isShader))get("glIsShader");

			//compute
			dispatchCompute = (decltype(dispatchCompute))get("glDispatchCompute");
			getProgramResourceIndex = (decltype(getProgramResourceIndex))get("glGetProgramResourceIndex");
			shaderStorageBlockBinding = (decltype(shaderStorageBlockBinding))get("glShaderStorageBlockBinding");
			bindImageTexture = (decltype(bindImageTexture))get("glBindImageTexture");
		}
	}
}