// Marina Lozano Lahuerta
// E31


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

int maximo(std::vector<int> const& v, int ini, int fin){
	int max = 0;
	for (int i = ini; i < fin; ++i)
		if (v[i]>max) max = v[i];
	
	return max;
}

int minimo(std::vector<int> const& v, int ini, int fin){
	int min = v[ini];
	for (int i = ini; i < fin; ++i)
		if (v[i]<min) min = v[i];

	return min;
}

/*
	T(n)=c			n=1,2
	T(n)=2T(n/2)+n	n>2

	T(n)= 2T(n/2)+n = 2(2T(n/2^2)+n)+n = 2^2T(n/2^2)+2*n = 
		= 2^kT(n/2^k)+k*n = n * c +log(n)*n

		n/2^k=1; n=2^k; k=log(n);

	T(n) pertenece a O(nlog(n))
*/
// función que resuelve el problema
bool ordenado(std::vector<int> const& v, int ini, int fin) {
	if (ini == fin) return true;
	if (ini + 1 == fin) // vector con 1 elemento
		return true;
	if (ini + 2 == fin){ // vector con 2 elementos
		return v[ini] <= v[fin - 1];
	}
	else{ // vector de 4 o más elementos.
		int m = (ini + fin) / 2;
		//COMPRUEBA SI EL LADO DERECHO ESTÁ PARCIALMENTE ORDENADO
		int maxDr = maximo(v, m, fin); //O(n)
		int maxIz = maximo(v, ini, m);
		//comparar con todos los de iz
		bool ordDr = maxDr>=maxIz;
		

		//COMPRUEBA SI EL LADO IZQUIERDO ESTÁ PARCIALMENTE ORDENADO
		int minIz = minimo(v, ini, m); // O(n)
		int minDr = minimo(v, m, fin);
		//comparar con todos der
		bool ordIz = minIz<=minDr;
		

		return ordIz && ordDr && ordenado(v, ini, m) && ordenado(v, m, fin);
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int aux;
	std::cin >> aux;

	if (aux == 0)
		return false;

	std::vector<int> v;

	while (aux != 0){
		v.push_back(aux);
		std::cin >> aux;
	}
	
	bool sol = ordenado(v, 0, v.size());

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