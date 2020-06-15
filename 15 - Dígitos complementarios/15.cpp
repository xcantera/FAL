// Marina Lozano Lahuerta
// E31


#include <iostream>
#include <iomanip>
#include <fstream>

/*
	T(n)=c			n<10
	T(n)=T(n-1)+c	n>10

	T(n)=T(n-1)+c = T(n-2)+2*c = ... = T(n-k)+k*c 
		= c+n*c

	n-k=0; n=k

	T(n) pertenece a O(n)

*/
// función que resuelve el problema
int complementario(int num) {
	if (num < 10)
		return 9 - num;
	else
		return complementario(num / 10) * 10 + (9 - num % 10);
}

struct tSol{
	int num;
	int pot;
};

tSol inverso(int num) {
	tSol sol;
	if (num < 10){
		sol.num = complementario(num);
		sol.pot = 1;
	}
	else{
		sol = inverso(num / 10);
		sol.pot *= 10;
		sol.num += (complementario(num) % 10)*sol.pot;
	}
	return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int num;
	std::cin >> num;

	int sol = complementario(num);
	// escribir sol
	std::cout << sol << " ";

	tSol inv = inverso(num);
	std::cout << inv.num << "\n";

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