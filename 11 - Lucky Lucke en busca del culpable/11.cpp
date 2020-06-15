// Marina Lozano Lahuerta
// E31


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

/*
	T(n)= c			n=1
	T(n)=T(n/2)+c	n>1

	T(n)=T(n/2)+c = T(n/2^2)+c+c = T(n/2^k)+k*c = T(1)+log(n)*c
		=c+log(n)*c 

	1=n/2^k; 2^k=n; k=log(n)

	T(n) pertenece a O(log(n))
*/

int buscarIz(std::vector<int> const& v, int ini, int fin, int alt) {
	if (ini + 1 == fin){//1 elemento
		if (v[ini] == alt) return ini;
		else return -1;
	}
	else{
		int m = (ini + fin-1) / 2;
		
		if (v[m] < alt) return buscarIz(v, m+1, fin, alt); 
		else return buscarIz(v, ini, m+1, alt);
	}

}
int buscarDr(std::vector<int> const& v, int ini, int fin, int alt) {
	if (ini + 1 == fin){//1 elemento
		if (v[ini] == alt) return ini;
		else return -1;
	}
	else{
		int m = (ini + fin) / 2;
		if (v[m] > alt) return buscarDr(v, ini, m, alt);
		else return buscarDr(v, m, fin, alt);
	}

}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int tam, altura;
	std::cin >> tam;
	if (!std::cin)
		return false;
	std::cin >> altura;
	std::vector<int> v(tam);
	for (int i = 0; i < tam; ++i)
		std::cin >> v[i];

	int solIz = buscarIz(v, 0, v.size(), altura);

	if (solIz == -1 || v[solIz] != altura)
		std::cout << "NO  EXISTE";
	else {
		// Si  existe  el  elemento  busca  en el lado  derecho
		int  solDr = buscarDr(v, 0, v.size(), altura);
		if (solIz == solDr) std::cout << solIz;
		else  std::cout << solIz << " " << solDr;
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


	while (resuelveCaso());


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}