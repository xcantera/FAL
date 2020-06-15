// Marina Lozano Lahuerta
// E31


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
/*
	T(n)=c			n=1
	T(n)=T(n/2)+c	n>1

	T(n) pertenece a O(log(n))
*/
int resolver(std::vector<int> const&v, int ini, int fin) {

	if (ini + 1 == fin) // vector con 1 elemento
		return v[ini];
	else{
		int m = (ini + fin) / 2;

		if (v[m] > v[ini]) return resolver(v, ini, m);
		else return resolver(v, m , fin);
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int tam;
	std::cin >> tam;
	if (!std::cin)
		return false;

	std::vector<int> v(tam);

	for (int i = 0; i < tam; ++i)
		std::cin >> v[i];


	int sol = resolver(v, 0, tam);

	// escribir sol
	std::cout << sol << "\n";

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