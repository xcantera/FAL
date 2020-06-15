// Marina Lozano Lahuerta
// E31


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


//Coste lineal O(n)

// función que resuelve el problema
int resolver(std::vector<int> const& v) {
	int i = 0;
	int numCeros = 0, numUnos = 0;
	int p = -1;

	while (i < v.size()){
		if (v[i] == 0) ++numCeros;
		if (v[i] == 1) ++numUnos;

		if (numCeros == numUnos){
			p = i;
		}
		++i;
	}

	return p;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int tam;
	std::cin >> tam;

	std::vector<int>v(tam);
	for (int i = 0; i < tam; ++i)
		std::cin >> v[i];

	int sol = resolver(v);
	// escribir sol

	std::cout << sol << "\n";
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