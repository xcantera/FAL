// Marina Lozano Lahuerta
// E31


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
/*
	T(1)=1; T(n)=T(n/2)+1

	T(n) pertenece a O(log(n))
*/
int tachar(std::vector<int> const& v, int ini, int fin, int n) {
	if (ini + 1 == fin){ // el vector tiene 1 elemento
		if (n + ini == v[ini]) return v[ini];
		else return 0;
	}
	else{
		int m = (ini + fin) / 2;
		if (n + m < v[m]) return tachar(v, ini, m, n);
		else return tachar(v, m, fin, n);
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int tam, num;
	std::cin >> tam >> num;

	std::vector<int> v(tam);

	for (int i = 0; i < tam; ++i){
		std::cin >> v[i];
	}
	int sol = tachar(v, 0, tam, num);
	// escribir sol
	if (sol == 0) std::cout << "NO";
	else std::cout << sol;
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