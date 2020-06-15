
// Marina Lozano Lahuerta
// Usuario del juez de clase  E31

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <vector>


// Explicacion del algoritmo de vuelta atras. 
// Como es la solucion del problema y el arbol de ejecucion
// Coste de la funcion esValida 


/*
	Coste de la funcion esValida
*/




// Aqui las funciones implementadas por el alumno

bool esValida(std::vector<int> const& sol, int k, std::vector<int> const& precipitacion, std::vector<int> const& abrigos,
	std::vector<int>const& contAbrigo) {
	if (abrigos[sol[k]] < precipitacion[k])return false;
	if (k > 0) {
		if (sol[k] == sol[k - 1])return false;
	}
	int dias = 0;
	for (int i = 0; i < abrigos.size(); ++i) {
		if (dias < contAbrigo[i])
			dias = contAbrigo[i];
	}
	
	if (dias > (2 + k / 3))return false;
	
	return true;
}


void abrigos(std::vector<int> const& precipitacion, std::vector<int> const& abrigo, int numDias, int numAbrigos, int k, 
	std::vector<int> &sol, std::vector<int>& contAbrigo, int& cont) {
	for (int i = 0; i < numAbrigos; ++i) {
		sol[k] = i;
		++contAbrigo[i];
		if (esValida(sol, k, precipitacion, abrigo, contAbrigo)) {//Es válida
			if (k == numDias - 1) {//Es solución
				if (sol[k] != sol[0]) {
					++cont;
				}
			}
			else {//No es solución
				abrigos(precipitacion, abrigo, numDias, numAbrigos, k + 1, sol, contAbrigo, cont);
			}
		}
		--contAbrigo[i];
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int numDias, numAbrigos;
	std::cin >> numDias;
	if (numDias == 0) return false;
	std::cin >> numAbrigos;

	// leer probabilidad de precipitacion
	std::vector<int> precipitacion(numDias);

	for (int i = 0; i < numDias; ++i) {
		std::cin >> precipitacion[i];
	}
	// leer caracteristicas de los abrigos
	std::vector<int> abrigo(numAbrigos);

	for (int i = 0; i < numAbrigos; ++i) {
		std::cin >> abrigo[i];
	}

	std::vector<int>sol(numDias);
	std::vector<int>contAbrigo(numAbrigos,0);
	int numSoluciones = 0;
	// LLamar a la funcion de vuelta atras
	
	abrigos(precipitacion, abrigo, numDias, numAbrigos, 0, sol, contAbrigo, numSoluciones);
	// Escribir resultado
	if (numSoluciones == 0) std::cout << "Lo puedes comprar\n";
	else std::cout << numSoluciones << '\n';

	return true;
}


 int main() {
     // Para la entrada por fichero.
 #ifndef DOMJUDGE
 std::ifstream in("datos.txt");
 auto cinbuf = std::cin.rdbuf(in.rdbuf());
 #endif

 while (resuelveCaso());

     // Para restablecer entrada.
 #ifndef DOMJUDGE // para dejar todo como estaba al principio
 std::cin.rdbuf(cinbuf);
 system("PAUSE");
 #endif

 return 0;

}
