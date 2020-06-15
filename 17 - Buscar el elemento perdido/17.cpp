// Marina Lozano Lahuerta
// E31


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


/*
	T(n)=c			n=0,1
	T(n)= T(n/2)+c	n>1

	T(n)=T(n/2)+c=T(n/2^2)+2*c=T(n/2^k)+k*c=
		= c+log(n)*c=log(n)

		n/2^k=1; n=2^k; k= log(n);

	T(n) pertenece a O(log(n))

*/
// función que resuelve el problema
int buscar(std::vector<int> const& vA, std::vector<int> const& vB, int ini, int fin) {
	if (ini == fin) // vector sin elementos
		return vA[ini];
	if (ini + 1 == fin){ // vector con 1 elemento
		if (vA[ini] == vB[ini]) return vA[ini + 1];
		else return vA[ini];
	}
	else{
		int m = (ini + fin) / 2;
		if (vA[m] != vB[m]) return buscar(vA, vB, ini, m);
		else return buscar(vA, vB, m, fin);

	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int tam;
	std::cin >> tam;
	std::vector<int> vA(tam);
	for (int i = 0; i < vA.size(); ++i)
		std::cin >> vA[i];
	std::vector<int> vB(tam-1);
	for (int i = 0; i < vB.size(); ++i)
		std::cin >> vB[i];

	int sol = buscar(vA,vB,0,vB.size());
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