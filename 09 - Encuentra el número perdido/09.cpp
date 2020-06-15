// Marina Lozano Lahuerta
// E31


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
/*
	T(1)=c; 
	T(2)=c;
	T(n)=T(n/2)+c = T(n/2^2)+c+c = T(n/2^3)+c+c+c = T(n/2^k)+k*c = T(1)+log(n)*c;

	T(n) pertenece a O(log(n))
*/
int resolver(std::vector<int> const& v, int ini, int fin) {
	if (ini + 1 == fin) //vector de un elemento
		return v[ini];
	else if (ini + 2 == fin){ //vector de 2 elementos
		if (v[ini] % 2 == 0) return v[ini + 1];
		else return v[ini];
	}
	else{
		int m = (ini + fin) / 2;
		if ((v[m] - v[ini]) / 2 != m - ini) return resolver(v, ini, m + 1);
		else return resolver(v, m + 1, fin);
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int tam;
	std::cin >> tam;
	
	if (tam==0)
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


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}