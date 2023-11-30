//#include <stdio.h>
//#include <string.h>
//#include <cmath>
//
//#include <GL/glew.h>
//#include <GLFW/glfw3.h>
//
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
//
//// Window dimensions
//const GLint WIDTH = 800, HEIGHT = 600;
//const float toRadians = 3.14159265f / 180.0f;
//
//GLuint VAO, VBO, IBO, shader, uniformModel, uniformProjection;
//
//bool direction = true;
//float triOffset = 0.0f;
//float triMaxOffset = 0.7f;
//float triIncrement = 0.005f;
//float curbAngle = 0.0f;
//
//bool sizeDirection = true;
//float curSize = 0.4f;
//float maxSize = 0.8f;
//float minSize = 0.1f;
//
//// Vertex Shader
//static const char* vShader = "													\n\
//	#version 330																\n\
//																				\n\
//	layout (location = 0) in vec3 pos;											\n\
//																				\n\
//	out vec4 vertexColor;														\n\
//																				\n\
//	uniform mat4 model;															\n\
//	uniform mat4 projection;													\n\
//																				\n\
//	void main()																	\n\
//	{																			\n\
//		gl_Position = projection * model * vec4(pos, 1.0);						\n\
//		vertexColor = vec4(clamp(pos, 0.0f, 1.0f), 1.0f);						\n\
//	}";
//
//// Fragment Shader
//static const char* fShader = "													\n\
//	#version 330																\n\
//																				\n\
//	in vec4 vertexColor;														\n\
//																				\n\
//	out vec4 color;																\n\
//																				\n\
//	void main()																	\n\
//	{																			\n\
//		color = vertexColor;													\n\
//	}";
//
//void CreateTriangle()
//{
//	unsigned int indices[] = { 
//		0, 3, 1, 
//		1, 3, 2, 
//		2, 3, 0,
//		0, 1, 2
//	};
//
//	GLfloat vertices[] = 
//	{
//		-1.0f, -1.0f, 0.0f, // Lower left corner
//		0.0f, -1.0f, 1.0f, // Added point
//		1.0f, -1.0f, 0.0f, // Lower right corner
//		0.0f, 1.0f, 0.0f // Top corner
//	};
//
//	// Create vertex array object
//	glGenVertexArrays(1, &VAO);
//	glBindVertexArray(VAO);
//
//	// Create index buffer object
//	glGenBuffers(1, &IBO);
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
//	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//
//	// Create vertex buffer object
//	glGenBuffers(1, &VBO);
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//
//	// Copy vertices to buffer
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//	// Specify attribute pointer
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
//	glEnableVertexAttribArray(0);
//
//	// Unbind VBO and VAO
//	glBindVertexArray(0);
//	glBindBuffer(GL_ARRAY_BUFFER, 0);
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
//}
//
//void AddShader(GLuint theProgram, const char* shaderCode, GLenum shaderType)
//{
//	// Create shader object
//	GLuint theShader = glCreateShader(shaderType);
//
//	// Create shader source
//	const GLchar* theCode[1];
//	theCode[0] = shaderCode;
//
//	GLint codeLength[1];
//	codeLength[0] = strlen(shaderCode);
//
//	// Compile shader
//	glShaderSource(theShader, 1, theCode, codeLength);
//	glCompileShader(theShader);
//
//	// Check for errors
//	GLint result = 0;
//	GLchar eLog[1024] = { 0 };
//
//	glGetShaderiv(theShader, GL_COMPILE_STATUS, &result);
//	if (!result)
//	{
//		glGetShaderInfoLog(theShader, sizeof(eLog), NULL, eLog);
//		printf("Error compiling the %d shader: '%s'\n", shaderType, eLog);
//		return;
//	}
//
//	// Attach shader to program
//	glAttachShader(theProgram, theShader);
//}
//
//void CompileShaders() {
//	shader = glCreateProgram();
//
//	if (!shader) {
//		printf("Error creating shader program!\n");
//		return;
//	}
//
//	AddShader(shader, vShader, GL_VERTEX_SHADER);
//	AddShader(shader, fShader, GL_FRAGMENT_SHADER);
//
//	GLint result = 0;
//	GLchar eLog[1024] = { 0 };
//
//	// Link program
//	glLinkProgram(shader);
//	glGetProgramiv(shader, GL_LINK_STATUS, &result);
//	if (!result)
//	{
//		glGetProgramInfoLog(shader, sizeof(eLog), NULL, eLog);
//		printf("Error linking program: '%s'\n", eLog);
//		return;
//	}
//
//	// Validate program
//	glValidateProgram(shader);
//	glGetProgramiv(shader, GL_VALIDATE_STATUS, &result);
//	if (!result)
//	{
//		glGetProgramInfoLog(shader, sizeof(eLog), NULL, eLog);
//		printf("Error validating program: '%s'\n", eLog);
//		return;
//	}
//
//	uniformModel = glGetUniformLocation(shader, "model");
//	uniformProjection = glGetUniformLocation(shader, "projection");
//}
//
//int main() 
//{
//	// Initialize GLFW
//	if (!glfwInit()) 
//	{
//		printf("GLFW initialization failed!");
//		glfwTerminate();
//		return 1;
//	}
//
//	// Setup GLFW window properties
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); 
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//
//	// Core profile = No Backwards Compatibility
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
//
//	// Create the window
//	GLFWwindow *mainWindow = glfwCreateWindow(WIDTH, HEIGHT, "Test Window", NULL, NULL);
//	if (!mainWindow)
//	{
//		printf("GLFW window creation failed!");
//		glfwTerminate();
//		return 1;
//	}
//
//	// Get buffer size information
//	int bufferWidth, bufferHeight;
//	glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);
//
//	// Set context for GLEW to use
//	glfwMakeContextCurrent(mainWindow);
//
//	// Allow modern extension features
//	glewExperimental = GL_TRUE;
//
//	GLenum error = glewInit();
//	if (error != GLEW_OK)
//	{
//		printf("GLEW initialization failed!");
//		glfwDestroyWindow(mainWindow);
//		glfwTerminate();
//		return 1;
//	}
//
//	glEnable(GL_DEPTH_TEST);
//
//	// Create viewport
//	glViewport(0, 0, bufferWidth, bufferHeight);
//
//	CreateTriangle();
//	CompileShaders();
//
//	glm::mat4 projection = glm::perspective(45.0f, (GLfloat)bufferWidth / (GLfloat)bufferHeight, 0.1f, 100.0f);
//
//	// Loop until window closed
//	while (!glfwWindowShouldClose(mainWindow))
//	{
//		if (direction)
//		{
//			triOffset += triIncrement;
//		}
//		else
//		{
//			triOffset -= triIncrement;
//		}
//
//		if (abs(triOffset) >= triMaxOffset)
//		{
//			direction = !direction;
//		}
//
//		curbAngle += 0.5f;
//		if(curbAngle >= 360.0f) curbAngle = 0.0f;
//
//		if (sizeDirection)
//		{
//			curSize += 0.01f;
//		}
//		else
//		{
//			curSize -= 0.01f;
//		}
//
//		if (curSize >= maxSize || curSize <= minSize)
//		{
//			sizeDirection = !sizeDirection;
//		}
//
//		//printf("%f\n", triOffset);
//
//		// Clear window
//		glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Color
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//		glUseProgram(shader);
//
//		glm::mat4 model(1.0f);
//		model = glm::translate(model, glm::vec3(triOffset, 0, -4.5));
//		model = glm::scale(model, glm::vec3(.4f, .4f, 1.0f));
//		model = glm::rotate(model, curbAngle * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
//		model = glm::scale(model, glm::vec3(curSize, 1.0f, 1.0f));
//
//		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
//		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
//
//		glBindVertexArray(VAO);
//		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
//		glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, 0);
//		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
//		glBindVertexArray(0);
//
//		glUseProgram(0);
//
//		glfwSwapBuffers(mainWindow);
//	}
//
//	return 0;	
//} 

#include <stdio.h>
#include <string.h>
#include <cmath>
#include <vector>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Window.h"
#include "Mesh.h"
#include "Shader.h"

const float toRadians = 3.14159265f / 180.0f;

Window mainWindow;
std::vector<Mesh*> meshList;
std::vector<Shader> shaderList;

// Vertex Shader
static const shar* vShader = "shaders/shader.vert";

