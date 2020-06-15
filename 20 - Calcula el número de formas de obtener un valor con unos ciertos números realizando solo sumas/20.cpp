// Marina Lozano Lahuerta
// E31


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using tMatriz = std::vector < std::vector<int> > ;
using tVector = std::vector < int > ;

// función que resuelve el problema
int suma(tMatriz m, int i, int N, tVector const& v, int sum) {
	if (N == 0) return 1;
	else if (v.size() == 0) return 0;
	else if (i == 0 && N > 0) return N == sum;
	else{
		if (sum > N) return 0;
		else{
			int iz = 0, dr = 0;

			if (v[i - 1] + sum == N) iz = 1;
			else{
				if (v[i - 1] + sum <= N) {
					if (m[i - 1][v[i - 1] + sum] == -1){
						m[i - 1][v[i - 1] + sum] = suma(m, i - 1, N, v, v[i - 1] + sum);
						iz = m[i - 1][v[i - 1] + sum];
					}
				}
			}

			if (sum == N) dr = 1;
			else{
				if (m[i - 1][sum] == -1){
					m[i - 1][sum] = suma(m, i - 1, N, v, sum);
					dr = m[i - 1][sum];
				}
			}
			return m[i][sum]=iz + dr;
		}
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int tam, num;
	std::cin >> tam;
	if (!std::cin)
		return false;
	std::cin >> num;
	tVector v(tam);

	int mayor=0;
	for (int i = 0; i < tam; ++i){
		std::cin >> v[i];
		mayor += v[i];
	}

	tMatriz matriz(tam+1, std::vector<int>(num+1, -1));

	int i = tam;
	int sol = suma(matriz, i, num, v,0);

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