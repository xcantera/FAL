// Marina Lozano Lahuerta
// E31


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

bool esValida(std::vector <int> const& juguetes, std::vector<int> const& sumaJug,std::vector <std::string> const& tipos, int k, 
	std::vector<int> const& sol, std::vector<int> const& sumaSatis, int satisMin){
	if (k %2!=0){
		if (tipos[sol[k - 1]] == tipos[sol[k]]) return false;
		if (sumaSatis[k/2] < satisMin) return false;
		if (sol[k] < sol[k - 1]) return false;
	}
	if (sumaJug[sol[k]] > juguetes[sol[k]]) return false;
	
	return true;
}

void tratarSolucion(std::vector<int> const & sol){
	for (int i = 0; i < sol.size(); ++i)
		std::cout << sol[i] << " ";
	std::cout << "\n";
}
// función que resuelve el problema
void repartir(std::vector < int > const& juguetes, std::vector <std::string> const& tipos, int satisMin, std::vector<int> const& satis, 
	int k, std::vector<int> & sol, std::vector<int> &sumaJug, std::vector<int> &sumaSatis, bool &exito) {

	for (int i = 0; i < juguetes.size(); ++i){
		sol[k] = i;
		++sumaJug[i];
		sumaSatis[k/2]+=satis[i+(k/2)*juguetes.size()];
		if (esValida(juguetes, sumaJug, tipos, k, sol, sumaSatis, satisMin)){//es válida
			if (k == sol.size()-1){//es solucion
				tratarSolucion(sol);
				exito = true;
			}
			else{//no es solución
				repartir(juguetes, tipos, satisMin, satis, k+1, sol, sumaJug, sumaSatis, exito);
			}
		}
		--sumaJug[i];
		sumaSatis[k/2] -= satis[i + (k / 2) * juguetes.size()];
	}

}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada

	int numJug, numNi, satisMin;

	std::cin >> numJug;
	if (!std::cin)
		return false;

	std::cin >> numNi >> satisMin;

	std::vector < int > juguetes(numJug);
	std::vector < std::string > tipos(numJug);

	for (int i = 0; i < numJug; ++i)
		std::cin >> juguetes[i];

	for (int i = 0; i < numJug; ++i)
		std::cin >> tipos[i];

	std::vector<int> sol(numNi * 2);
	std::vector<int> satis(numJug*numNi);

	int k = 0;

	std::vector<int> sumaJug(numJug);
	std::vector<int> sumaSatis(numNi);
	bool exito = false;
	int i = 0;

	for (int i = 0; i < satis.size(); ++i){
		std::cin >> satis[i];
	}
	repartir(juguetes, tipos, satisMin, satis, k, sol, sumaJug, sumaSatis, exito);


	// escribir sol
	if (!exito) std::cout << "SIN SOLUCION\n";
	std::cout << "\n";
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