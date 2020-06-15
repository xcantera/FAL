// Marina Lozano Lahuerta
// E31

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

//Coste lineal O(n)

struct tsol{
	int ini;
	int fin;
};

// función que resuelve el problema
tsol resolver(std::vector<int> const& v, int alt) {
	int i = 0;
	int iniUltSeg = 0;
	int maxLong = 0;
	tsol sol;
	sol.ini = 0;

	while (i < v.size()){
		if(v[i] > alt) {
			if (maxLong < i - iniUltSeg + 1) {
				sol.ini = iniUltSeg;
				maxLong = i - iniUltSeg + 1;
			}
		}
		else {
			iniUltSeg = i + 1;
		}
		++i;
	}
	sol.fin = sol.ini + maxLong - 1;

	return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int numEdificios, altTrans;

	std::cin >> numEdificios >> altTrans;

	std::vector<int> v(numEdificios);

	for (int i = 0; i < numEdificios; ++i)
		std::cin >> v[i];

	tsol sol = resolver(v, altTrans);
	// escribir sol

	std::cout << sol.ini << " " << sol.fin << "\n";
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