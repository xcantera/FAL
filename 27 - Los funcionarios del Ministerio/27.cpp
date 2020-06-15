// Marina Lozano Lahuerta
// E31


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using tMatriz = std::vector < std::vector<int> > ;

bool esValida(int k, int numFun, std::vector<int> const& sol, std::vector<bool> marcaTra, std::vector<bool> marcaFun){
	if (k > 0){
		if (marcaTra[k]) return false; // Ese trabajo ya lo hace alguien
		if (marcaFun[sol[k]]) return false; // Ese funcionario ya hace un trabajo
	}
	return true;
}

// función que resuelve el problema
void resolver(tMatriz const& tiempos, int numFun, int k, std::vector<int> &sol, int &tiempoAct,int &tiempoMejor,
	std::vector<bool> & marcaTra, std::vector<bool> & marcaFun) {
	for (int i = 0; i < numFun; ++i){
		sol[k] = i;
		tiempoAct += tiempos[i][k];
		if (esValida(k, numFun, sol, marcaTra, marcaFun)){//es válida
			marcaTra[k] = true;
			marcaFun[i] = true;
			if (k == numFun - 1){//es solución
				if (tiempoAct < tiempoMejor){
					tiempoMejor = tiempoAct;
				}
			}
			else{ // No es solución
				resolver(tiempos, numFun, k + 1, sol,tiempoAct, tiempoMejor, marcaTra, marcaFun);
			}
			marcaTra[k] = false;
			marcaFun[i] = false;
		}
		tiempoAct -= tiempos[i][k];
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int numFun;
	std::cin >> numFun;

	if (numFun == 0)
		return false;

	int tiempo = 0;
	tMatriz tiempos(numFun, std::vector<int>(numFun));

	std::vector<int> sol(numFun);

	for (int i = 0; i < numFun; ++i)
		for (int j = 0; j < numFun;++j)
			std::cin >> tiempos[i][j];

	int k = 0;
	int tiempoMejor = 1000*numFun;
	int tiempoAct = 0;
	std::vector<bool> marcaTra(numFun);
	std::vector<bool> marcaFun(numFun);

	resolver(tiempos, numFun, k, sol,tiempoAct, tiempoMejor, marcaTra, marcaFun);

	std::cout << tiempoMejor << "\n";

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