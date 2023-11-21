#ifndef SHADER_CLASS_H
#define SHADER_CLASS_H

#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cerrno>

std::string get_file_contents(const char* filename);

class Shader {
public:
	// Reference ID of the Shader Program
	GLuint ID;
	// Constructor that build the Shader Program from 2 different shaders
	Shader(const char* vertexPath, const char* fragmentPath);

	// Activate the shader
	void Activate();
	// Delete the shader
	void Delete();

private:
	// Error check
	void compileErrors(unsigned int shader, const char* type);
};

#endif
