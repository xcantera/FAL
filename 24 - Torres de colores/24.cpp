// Marina Lozano Lahuerta
// E31


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

enum color { AZUL, ROJO, VERDE};

bool esValida(std::vector<int> const&sol, int k, int sumA, int sumV) {
	if (sol[k] == VERDE && sol[k - 1] == VERDE) return false;
	if (sumV > sumA) return false;
	return true;
}

void tratarSolucion(std::vector<int> const&sol) {
	for (int i = 0; i < sol.size(); ++i){
		switch (sol[i]){
		case AZUL:std::cout << "azul "; break;
		case ROJO:std::cout << "rojo "; break;
		case VERDE:std::cout << "verde "; break;
		}
	}
	std::cout << "\n";
}


// función que resuelve el problema
void torre(int alt, std::vector<int> &numColor, std::vector<int> & sol, int k, int &sumaA, int &sumaV, int &sumaR, bool& exito) {

	for (int i = 0; i < numColor.size(); ++i) {
		if (numColor[i] > 0) {
			sol[k] = i;
			switch (i){
			case AZUL: ++sumaA; break;
			case ROJO: ++sumaR; break;
			case VERDE: ++sumaV; break;
			}
			if (esValida(sol, k, sumaA, sumaV)) {
				--numColor[i];
				if (k == alt - 1){
					if (sumaR > (sumaA + sumaV)) { // Si es válida
						tratarSolucion(sol);
						exito = true;
					}
				}
				else{
					torre(alt, numColor, sol, k + 1, sumaA, sumaV, sumaR, exito);
				}
				++numColor[i];
			}
			switch (i){
			case AZUL: --sumaA; break;
			case ROJO: --sumaR; break;
			case VERDE: --sumaV; break;
			}
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int altura;
	std::cin >> altura;
	
	std::vector<int> sol(altura);
	std::vector<int> numColor(3);
	for (int i = 0; i < numColor.size(); ++i)
		std::cin >> numColor[i];

	if (altura == 0 && numColor[0] == 0 && numColor[1] == 0 && numColor[2] == 0)
		return false;

	sol[0] = ROJO;
	int sumaAzu = 0, sumaRojo = 1, sumaVerde=0;
	--numColor[1];

	bool exito = false;
	torre(altura, numColor, sol, 1, sumaAzu, sumaVerde, sumaRojo,exito);
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