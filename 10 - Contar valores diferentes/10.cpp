// Marina Lozano Lahuerta
// E31


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema

/*
	T(n)=c			n=1
	T(n)=2T(n/2)+c	n>1

	T(n)=2T(n/2)+c	= 2(2T(n/2^2)+c)+c = 2^2(2T(n/2^3)+c)+2*c =
					= 2^3T(2/n^3)+3*c = 2^kT(n/2^k)+k*c =
					= 2^log(n)T(1)+log(n)*c 

					k=log(n)

		T(n) pertenece a O(n)


*/
int contar(std::vector<int> const&v, int ini, int fin) {

	if (ini + 1 == fin){ // vector de 1 elemento
		return 1;
	}
	else{
		int m = (ini + fin) / 2;
		if (v[m] == v[ini]) // Por el lado izquierdo es el mismo número.
			return contar(v, m, fin); // Sólo se va por la derecha.
		else{
			int iz = contar(v, ini, m);
			if (v[m] == v[m - 1]) --iz; // Si el número está a ambos lados lo resto del izquierdo
										// Se sumará en el derecho.
			int dr = contar(v, m, fin);
			return iz + dr;
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int tam;
	std::cin >> tam;

	if (tam == 0)
		return false;

	std::vector<int> v(tam);

	for (int i = 0; i < tam; ++i)
		std::cin >> v[i];
	int num = 0;
	int sol = contar(v, 0, tam);

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


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}