// Marina Lozano Lahuerta
// E31


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
bool resolver(std::vector<int> const& a, int p) {
	int mayor = a[0];
	bool c = true;

		for (int i = 0; i <= p; ++i){
			if (a[i]>mayor) mayor = a[i];
		}
		int i = p + 1;
		while (c && i < a.size()){
			if (mayor >= a[i]) 
				c = false;
			++i;
		}
	
	return c;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int numElem, p;
	std::cin >> numElem >> p;

	std::vector<int> a(numElem);

	for (int i = 0; i < numElem; ++i)
		std::cin >> a[i];

	bool sol = resolver(a, p);
	// escribir sol
	if (sol)std::cout << "SI";
	else std::cout << "NO";

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