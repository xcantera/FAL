// Marina Lozano Lahuerta
// E31


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

/*
	T(n)=c			n=0,1
	T(n)=2T(n/2)+c	n>1

	T(n)=2T(n/2)+c= 2^kT(n/2^k)+c*k= nlog(n)

	2^k=n k=log(n)

	T(n) pertenece a O(nlog(n))

*/


// función que resuelve el problema
bool caucasico(std::vector<int> const& v, int ini, int fin) {
	if (ini == fin) return true;
	if (ini + 1 == fin) return true;
	else{
		int m = (ini + fin) / 2;
		bool iz = caucasico(v,ini,m);
		bool dr = caucasico(v, m, fin);

		int auxIz=0;
		for (int i = ini; i < m; ++i)
			if (v[i] % 2 == 0) ++auxIz;
		

		int auxDr = 0;
		for (int j = m; j < fin; ++j)
			if (v[j] % 2 == 0) ++auxDr;
		

		return iz && dr && std::abs(auxIz-auxDr)<=2;
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
	for (int i = 0; i < v.size(); ++i)
		std::cin >> v[i];

	bool sol = caucasico(v, 0, tam);

	// escribir sol
	if (sol)std::cout << "SI\n";
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


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}