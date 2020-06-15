// Marina Lozano Lahuerta
// E31


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
std::vector<int> resolver(std::vector<int> const& v, int l) {
	std::vector<int> p;
	std::vector<int> s;

	int i = 0;
	int ini = 0;
	int iniUltSeg = 0;
	int maxLong = 1;
	int numLlanos = 0;
	//Tiene que ser de derecha a izquierda
	while (i < v.size() - 1){
		if (v[i] > 1 && v[i] == v[i + 1]){

			if (maxLong <= i - iniUltSeg + 2){
				if (ini != iniUltSeg) ++numLlanos;
				ini = iniUltSeg;
				maxLong = i - iniUltSeg + 2;
			}
			if ((i - iniUltSeg + 1) + 1 >= l){
				p.push_back(v.size() - 1 - iniUltSeg);
			}

		}
		else{
			iniUltSeg = i + 1;
		}
		++i;
	}
	s.push_back(maxLong);
	s.push_back(p.size());
	for (int i = 0; i < p.size(); ++i)
		s.push_back(p[i]);
	return s;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int tam,l;
	std::cin >> tam;

	if (!std::cin)
		return false;

	std::cin >> l;
	std::vector<int> v(tam);

	for (int i = 0; i < v.size(); ++i){
		std::cin >> v[i];
	}

	std::vector<int> s = resolver(v, l);

	// escribir sol

	std::cout << s[0] << " " << s[1];
	if (s[1]>0){
		for (int i = 2; i < s.size(); ++i){
			std::cout << " " << s[i];
		}
	}
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


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}