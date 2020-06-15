// Marina Lozano Lahuerta
// E31


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct tsol{
	int maxLong;
	int cont;
	int racha;
};


// función que resuelve el problema
tsol resolver(std::vector<int> const& v) {
	int i = 0;
	tsol sol;
	sol.maxLong = 0;
	int ini = 0;
	int iniUltSeg = 0;
	sol.cont = 0;

	while (i < v.size()){
		if (v[i] > 0) {
			if (sol.maxLong <= i - iniUltSeg + 1) {
				if (sol.maxLong == i - iniUltSeg + 1)
					++sol.cont;
				else sol.cont = 1;
				ini = iniUltSeg;
				sol.maxLong = i - iniUltSeg + 1;
			}
		}
		else{
			iniUltSeg = i + 1;
		}
		++i;
	}
	sol.racha = v.size() - 1 - (ini + sol.maxLong - 1);

	return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int numPartidos;

	std::cin >> numPartidos;
	if (!std::cin)
		return false;

	std::vector<int> v(numPartidos);

	for (int i = 0; i < numPartidos; ++i)
		std::cin >> v[i];

	tsol sol = resolver(v);

	// escribir sol

	std::cout << sol.maxLong << " " << sol.cont << " " << sol.racha << "\n";
	return true;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso());


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}