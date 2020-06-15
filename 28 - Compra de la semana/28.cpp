// Marina Lozano Lahuerta
// E31


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using tMatriz = std::vector < std::vector<int> > ;

bool esValida(std::vector<int> const& marcaSuper, int k, std::vector<int> const&sol, int numProd, std::vector<bool> const& marcaProd){
	if (marcaProd[k])return false;
	if (marcaSuper[sol[k]] >= 3)return false;
	return true;
}

// función que resuelve el problema
void compra(tMatriz const& precios, int numSuper, int numProd, int k, std::vector<int> &sol, std::vector<int> &marcaSuper,
	std::vector<bool> &marcaProd, int& mejorPrecio, int& precioAct, std::vector<int> const& minimosAcu) {

	for (int i = 0; i < numSuper; ++i){
		sol[k] = i;
		if (esValida(marcaSuper, k, sol, numProd, marcaProd)){
			precioAct += precios[i][k];
			marcaProd[k] = true;
			++marcaSuper[i];
			if (k == numProd - 1){
				if (precioAct < mejorPrecio){//mejor solucion
					mejorPrecio = precioAct;
				}
			}
			else{
				
				if (minimosAcu[k+1]+precioAct< mejorPrecio)
					compra(precios, numSuper, numProd, k + 1, sol, marcaSuper, marcaProd, mejorPrecio, precioAct, minimosAcu);
			}
			precioAct -= precios[i][k];
			marcaProd[k] = false;
			--marcaSuper[i];
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int numSuper, numProd;
	std::cin >> numSuper >> numProd;

	tMatriz precios(numSuper, std::vector<int>(numProd));

	for (int i = 0; i < numSuper; ++i)
		for (int j = 0; j < numProd;++j)
		std::cin >> precios[i][j];

	std::vector<int> sol(numProd);
	std::vector<int> marcaSuper(numSuper);
	std::vector<bool> marcaProd(numProd);
	int mejorPrecio = numProd * 9999;
	int precioAct = 0;

	std::vector<int> minimos(numProd);
	minimos[0] = precios[0][0];
	
	for (int j = 0; j < numProd; ++j){
		minimos[j] = precios[0][j];
		for (int i = 0; i < numSuper; ++i){
			if (minimos[j]>precios[i][j])
				minimos[j] = precios[i][j];
		}
	}
	std::vector<int> minimosAcu(numProd,0);


	minimosAcu[minimos.size() - 1] = minimos[minimos.size() - 1];

	for (int i = minimosAcu.size()-2; i > -1; --i){
		minimosAcu[i] = minimos[i]+minimosAcu[i+1];
	}

	compra(precios, numSuper, numProd, 0, sol, marcaSuper, marcaProd, mejorPrecio,precioAct, minimosAcu);
	// escribir sol
	std::cout << mejorPrecio << "\n";

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