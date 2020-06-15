// Marina Lozano Lahuerta
// E31


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

//Coste lineal O(n)

struct tsol{
	int ganancia;
	int vagon;
};

// función que resuelve el problema
tsol resolver(std::vector<int> const& v, int m) {
	int i = 0;
	int sumParcial = 0;
	tsol sol;
	while (i < m){
		sumParcial += v[i];
		++i;
	}
	sol.ganancia = sumParcial;
	sol.vagon = 0;
	int j = 0;
	while (j < v.size() - m){
		sumParcial += v[j + m];
		sumParcial -= v[j];
		if (sumParcial >= sol.ganancia) {
			sol.ganancia = sumParcial;
			sol.vagon = j + 1;
		}
		++j;
	}
	return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int numVagones, vagonesAsalto;//ventana

	std::cin >> numVagones >> vagonesAsalto;

	std::vector<int> v(numVagones);

	for (int i = 0; i < numVagones; ++i)
		std::cin >> v[i];

	
	tsol sol = resolver(v, vagonesAsalto);
	// escribir sol
	std::cout << sol.vagon << " " << sol.ganancia << "\n";

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