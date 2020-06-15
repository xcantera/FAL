// Marina Lozano Lahuerta
// E31


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

/*
	T(n)=c			n=1,2
	T(n)=2T(n/2)+n	n>2

	T(n)= 2T(n/2)+n = 2(2T(n/2^2)+n)+n = 2^2T(n/2^2)+2*n =
		= 2^kT(n/2^k)+k*n = n * c +log(n)*n

		n/2^k=1; n=2^k; k=log(n);
		
	T(n) pertenece a O(nlog(n))
*/
// función que resuelve el problema
bool resolver(std::vector<int> const& v, int ini, int fin) {
	if (ini + 1 == fin) // vector de 1 elemento
		return true;
	if (ini + 2 == fin){
		return v[ini] <= v[fin - 1];
	}
	else{
		int m = (ini + fin) / 2;
		
		int sumaIz=0;
		for (int i = ini; i < m; ++i)
			sumaIz += v[i];
		int sumaDr = 0;
		for (int i = m; i < fin; ++i)
			sumaDr += v[i];

		return (sumaIz <= sumaDr) && resolver(v, ini, m) && resolver(v, m, fin);
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int fila, col;
	std::cin >> fila;

	if (!std::cin)
		return false;
	std::cin >> col;

	std::vector<int> v(col);

	bool sol=true;
	for (int i = 0; i < fila; ++i){
		for (int i = 0; i < v.size(); ++i)
			std::cin >> v[i];

		sol = sol && resolver(v, 0, v.size());
	}

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