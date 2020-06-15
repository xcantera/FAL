// Marina Lozano Lahuerta
// E31


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


//Coste lineal O(n)


// función que resuelve el problema
int resolver(std::vector<int> const& v) {

	int max = v[0];
	int suma = v[0];
	int cont = 1;
	for (int i = 1; i < v.size(); ++i){
		if (v[i] == max){
			++cont;
		}
		if (v[i]>max){
			max = v[i];
			cont = 1;
		}
		suma += v[i];
	}


	suma -= max*cont;

	return suma;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int tam;
	std::cin >> tam;

	std::vector<int> v(tam);

	for (int i = 0; i < tam; ++i)
		std::cin >> v[i];

	int s = resolver(v);
	// escribir sol

	std::cout << s << "\n";
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