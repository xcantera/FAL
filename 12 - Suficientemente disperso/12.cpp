// Marina Lozano Lahuerta
// E31


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
/*
	T(n) = c		n=2
	T(n)=2T(n/2)+c	n>2

	T(n)= 2T(n/2)+c = 2(2T(n/2^2)+c)+c = 2^2T(n/2^2)+2*c = 
		= 2^kT(n/2^k)+k*c = 2^log(n)T(1)+log(n)

		n/2^k=1;  n=2^k; K=log(n);

	T(n) pertenece a O(n)
*/

// función que resuelve el problema
bool disperso(std::vector<int> const& v, int ini, int fin, int disp) {
	if (ini + 1 == fin) // vector con 1 elemento
		return true;
	if (ini + 2 == fin) // vector con 2 elementos
		return std::abs(v[ini] - v[fin - 1]) >= disp;
	else{
		int m = (ini + fin) / 2;
		bool dispIz = disperso(v, ini, m, disp);
		bool dispDr = disperso(v, m, fin, disp);
		return (dispIz && dispDr) && std::abs(v[ini] - v[fin - 1]) >= disp;
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int tam,disp;
	std::cin >> tam;
	if (!std::cin)
		return false;
	std::cin >> disp;
	std::vector<int> v(tam);
	for (int i = 0; i < tam; ++i)
		std::cin >> v[i];

	bool sol = disperso(v, 0, v.size(), disp);

	// escribir sol
	if (sol) std::cout << "SI\n";
	else std::cout << "NO\n";

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