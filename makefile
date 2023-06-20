# // 3 partes 1.- objetivos, 2.- dependecias y 

# Esta tarea nos sirve para compilar el programa

bin/proyecto.exe : src/main.cpp
	@echo Compilando codigo fuente.....
	g++ -o bin/proyecto src/main.cpp -Iinclude