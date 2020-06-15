// Marina Lozano Lahuerta
// E31


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema por recursión final
/*
			T(n)=c			n=1
			T(n)=T(n/2)+c	n>1

		T(n) pertenece O(log(n))
*/
char buscar(std::vector<char> const& v, int ini, int fin, char pri, char ult) {

	if (ini + 1 == fin){ //vector de un elemento
		if (v[ini] == pri) return v[ini] + 1;
		else return v[ini] - 1;
	}
	else{

		if (pri != v[ini]) //Si el primer elemento no coincide con el extremo izquierdo.
			return pri;
		else if (ult != v[fin - 1]) //Si el último elemento no coincide con el extremo derecho.
			return ult;

		int m = (ini + fin) / 2;

		if (v[m] - v[ini] == m - ini)  return buscar(v, m, fin, v[m], ult);
		else return buscar(v, ini, m, pri, v[m - 1]);
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	char ini;
	char fin;
	std::cin >> ini;
	std::cin >> fin;

	int tam = fin - ini;

	std::vector<char> v(tam);
	for (int i = 0; i < tam; ++i)
		std::cin >> v[i];

	char sol = buscar(v, 0, tam, ini, fin);
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