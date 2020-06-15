// Marina Lozano Lahuerta
// E31


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>

/*

	T(n)=c			n=2
	T(n)=2T(n/2)+c	n>2

	T(n)=2^kT(n/2^k)+k*c = n*c+log(n)*c=n

	n/2^k=1; n=2^k; log(n)=log(2^k); log(n)=k; 

	T(n) pertenece a O(n)
*/


// función que resuelve el problema
int resolver(std::vector<std::string> const& v, int ini, int fin, int numRonda, bool &presentado, int &rondaAct) {
	if (ini + 2 == fin){ // Vector con 2 elementos
		if (v[ini] == "NP" && v[fin - 1] == "NP") presentado = false;
		else presentado = true;

		if (v[ini] == "NP" || v[fin - 1] == "NP") return 0;
		else return 1;
	}
	else{
		int m = (ini + fin) / 2;
		int iz = resolver(v, ini, m, numRonda, presentado, rondaAct);
		bool presentIz = presentado;
		int dr = resolver(v, m, fin, numRonda, presentado, rondaAct);
		bool presentDr = presentado;
		if (rondaAct < numRonda){
			int aux = 0;

			if (v.size() == fin)
				++rondaAct;
		
			if (!presentIz&&!presentDr)presentado = false;
			else presentado = true;
			if (pow(2, numRonda) == v.size() || pow(2, numRonda) >= (fin - ini)){
				if (presentIz && presentDr) ++aux;
			}

			return aux + dr + iz;
		}
		else{
			return iz + dr;
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int tam, ronda;
	std::cin >> tam;
	if (!std::cin)
		return false;

	std::cin >> ronda;

	std::vector<std::string> v(tam);

	for (int i = 0; i < tam; ++i)
		std::cin >> v[i];

	int sol;
	bool presentado = false;
	int rondaAct=0;
	sol = resolver(v,0,tam, ronda, presentado, rondaAct);

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


	while (resuelveCaso());


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}