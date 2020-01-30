// PlantillaGraficos.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <stdio.h> 
#include <stdlib.h> 
#define GLEW_STATIC 
 
#include"GL/glew.h"
#include "GLFW/glfw3.h"

#include <iostream> 

using namespace std;

void dibujarLineaContinua(){
	glBegin(GL_LINE_STRIP);
	glColor3f(0.1f, 0.3f, 0.75f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.2f, 0.0f);
	glVertex3f(0.4f, 0.2f, 0.0f);

	glEnd();
}
void dibujarLineas(){
	glBegin(GL_LINES);
	glColor3f(0.2f, 0.1f, 0.1f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.2f, -0.1f, 0.0f);
	glVertex3f(-0.3f, 0.1f, 0.0f);
	glVertex3f(-0.3f, -0.1f, 0.0f);
	glEnd();
}
void dibujarTriangulos() {
	glBegin(GL_TRIANGLES);

	//3f--> 3 flotantes 
	//Se agrega la f para no crear conflictor y especificar double
	//Establecemos Color
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-0.4f, 0.4f, 0.0f);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.4f, 0.4f, 0.0f);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.4f, -0.4f, 0.0f);
	////
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.4f, -0.4f, 0.0f);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-0.4f, 0.4f, 0.0f);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-0.4f, -0.4f, 0.0f);
	//Especificamos que dejaremos de dibujar 
	glEnd();

}
void dibujarTrianContinuo() {
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(1.0f,1.0f,1.0f);

	glVertex3f(0.0f,0.0f,0.0f);
	glVertex3f(0.1f, 0.1f, 0.0f);
	glVertex3f(0.2f, 0.0f, 0.0f);

	glColor3f(0.2f, 0.8f, 1.0f);

	glVertex3f(0.0f, 0.15f, 0.0f);

	glEnd();
}
void poligonos() {
	glBegin(GL_POLYGON);
	//Necesita por lo menos 3v
	glColor3f(1.0f,0.8f,0.1f);

	glVertex3f(0.0f,0.0f,0.0f);
	glVertex3f(0.0f, 0.5f, 0.0f);
	glVertex3f(0.2f, 0.3f, 0.0f);

	glColor3f(0.2f, 0.6f, 1.0f);
	glVertex3f(0.2f, -0.4f, 0.0f);
	glVertex3f(0.4f, -0.6f, 0.0f);

	glEnd();
}

void dibujar() {
	poligonos();
}
//$(ProjectDir)include 
int main()
{
	//Declarar una ventana 
	GLFWwindow* window;


	//Si no se pudo inicializar GLFW  //Terminamos Ejecución 
	if (!glfwInit()) {
		exit(EXIT_FAILURE);
	}
	window = glfwCreateWindow(600, 600, "Ventana Cookie", NULL, NULL);
	
	//Si no se pudo crear la ventana
	//Terminamos ejecución
	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	//Si se pudo inicializar GLFW
	//Inicializams la ventana


	//Establecemos la ventana como contexto
	glfwMakeContextCurrent(window);
	//UsarFuncionesdeOpengl
	//Una vez establecido el contexto. Se activan las funciones "modernas" (gpu)
	glewExperimental = true;
	
	GLenum errores = glewInit();
	if (errores != GLEW_OK) {
		glewGetErrorString(errores);
	}

	const GLubyte  *versionGL = glGetString(GL_VERSION);

	cout << "Version OpenGl: " << versionGL;

	//Clilo de dibujo (Draw loop)
	while (!glfwWindowShouldClose(window)) {

		//Establecer región de dibujo 
		glViewport(0, 0, 600, 600);
		//Establecemos el color de borrado
		glClearColor(3, 0.8, 0.4, 1);
		//Borrar
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		dibujar();
		//Se comunica con los dispositivos de entrada
		glfwPollEvents();
		// Actualizar los valores y dibujar 
		glfwSwapBuffers(window);
	}
	//Despues del ciclo de dibujo Eliminamos ventana y procesos de glfw
	glfwDestroyWindow(window);
	glfwTerminate();
}