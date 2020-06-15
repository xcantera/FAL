// Marina Lozano Lahuerta
// E31


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

//Coste lineal O(n)

enum piedrasPreciosas { diamante, rubi, esmeralda, zafiro, jade };


std::istream& operator>> (std::istream& entrada, piedrasPreciosas& p) {
	char num;
	entrada >> num;
	switch (num) {
	case 'd': p = diamante; break;
	case 'r': p = rubi; break;
	case 'e': p = esmeralda; break;
	case 'z': p = zafiro; break;
	case 'j': p = jade; break;
	}
	return entrada;
}

// función que resuelve el problema
int resolver(std::vector<piedrasPreciosas> const&v, int m, int numtipo1, int numtipo2, piedrasPreciosas tipo1, piedrasPreciosas tipo2) {
	int cont1 = 0;
	int cont2 = 0;
	int i = 0;
	int cont = 0;

	while (i < m){
		if (v[i] == tipo1) ++cont1;
		if (v[i] == tipo2) ++cont2;

		++i;
	}
	if (cont1 >= numtipo1 && cont2 >= numtipo2)
		++cont;

	int j = 0;
	while (j < v.size() - m){
		if (v[j+m] == tipo1) ++cont1;
		if (v[j+m] == tipo2) ++cont2;

		if (v[j] == tipo1) --cont1;
		if (v[j] == tipo2) --cont2;
		
		if (cont1 >= numtipo1 && cont2 >= numtipo2)
			++cont;
		++j;
	}
	return cont;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int numpiedras;
	int tamSec;
	int numtipo1, numtipo2; 
	piedrasPreciosas tipo1, tipo2;
	std::cin >> numpiedras >>tamSec>> tipo1 >> numtipo1 >> tipo2 >> numtipo2;

	std::vector<piedrasPreciosas> v(numpiedras);
	for (piedrasPreciosas& i : v) std::cin >> i;

	int sol = resolver(v, tamSec, numtipo1, numtipo2, tipo1, tipo2);
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