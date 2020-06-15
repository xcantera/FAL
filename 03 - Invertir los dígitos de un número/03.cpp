// Marina Lozano Lahuerta
// E31


#include <iostream>
#include <iomanip>
#include <fstream>

struct sol{
	int numero;
	int pot;
};

// función que resuelve el problema
sol invertir(int n) {
	sol sol;

	if (n < 10){
		sol.pot = 1;
		sol.numero = n;
	}
	else{
		sol = invertir(n / 10);
		sol.pot *= 10;
		sol.numero += (n % 10)*sol.pot;
	}
	return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada

	int n;
	std::cin >> n;

	if (!std::cin)
		return false;

	// escribir sol

	std::cout << invertir(n).numero << std::endl;
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