// Marina Lozano Lahuerta
// E31


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

/*
	T(n) pertenece a O(n)
*/

// función que resuelve el problema
bool estaBalanceado(int &peso){
	int pesoIz, distIz, pesoDr, distDr;

	std::cin >> pesoIz >> distIz >> pesoDr >> distDr;

	bool iz = true, dr = true;
	if (pesoIz == 0) {
		iz = estaBalanceado(peso);
		pesoIz = peso;
	}

	if (pesoDr == 0) {
		dr = estaBalanceado(peso);
		pesoDr = peso;
	}
	peso = pesoIz + pesoDr;

	return dr && iz && (pesoIz*distIz == pesoDr*distDr);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int peso = 0;

	// escribir sol
	if (estaBalanceado(peso)) std::cout << "SI\n";
	else std::cout << "NO\n";
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