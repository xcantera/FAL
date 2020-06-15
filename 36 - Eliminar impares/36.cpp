// Marina Lozano Lahuerta
// E31


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
void resolver(std::vector<int> &v) {
	int j = 0;
	int tam = v.size();
	for (int i = 0; i < tam; ++i){
		if (v[i] % 2 == 0){
			v[j] = v[i];
			++j;
		}
	}
	v.resize(j);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int numElem;
	std::cin >> numElem;
	std::vector<int> v(numElem);

	for (int i = 0; i < numElem; ++i){
		std::cin >> v[i];
	}

	resolver(v);
	// escribir sol

	for (int i = 0; i < v.size(); ++i){
		std::cout << v[i] << " ";
	}
	std::cout << "\n";
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