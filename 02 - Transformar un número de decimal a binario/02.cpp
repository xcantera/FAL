﻿// Nombre del alumno ..... Marina Lozano Lahuerta
// Usuario del Juez ...... E31


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>


// función que resuelve el problema
std::string resolver(int n) {
	
	if (n == 1) return "1";
	else if (n == 0) return "0";
	else {
		return resolver(n / 2) + char('0' + n % 2);
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int n;
	std::cin >> n;

	std::string sol = resolver(n);
	// escribir sol
	std::cout << sol << std::endl;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}