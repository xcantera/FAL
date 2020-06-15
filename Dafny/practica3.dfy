// Marina Lozano Lahuerta  E31
// Ana Álava Papí  E71

// Implementar un metodo que calcule el n-esimo numero de la sucesion de fibonacci
// Definicion de la funcion de Fibonacci para usarla en la especificacion
function Fib (n : int) : int
requires n >= 0
{ if (n < 2) then n else Fib(n -2) + Fib(n -1) }

// Metodo que calcula el n-esimo termino de la sucesion
method Fibonacci (n : int) returns (f : int)
requires n >= 0
ensures f == Fib(n)
{
	// Resolver el problema para los casos n == 0 y n == 1 antes de entrar en el bucle
	if (n == 0) { f := 0; }
	else if (n == 1) {f := 1;}
	else {
		// Inicializar las variables
		f:=1; var f1:=1; var f2:=0; var i:=2;
		// Bucle con invariante y funcion cota
		while (i <= n) 
    invariant 2<= i <= n+1
		invariant f == Fib(i-1) && f1==Fib(i-1) && f2==Fib(i-2)
		{
			// Cuerpo del bucle
      f:=f1+f2;
      
			f2:=f1;
      f1:=f;
      
      i:=i+1;
		}
	}

}




// Implementar un metodo que dado un vector devuelva en otro vector los valores acumulados
// Se acumulan los valores de derecha a izquierda. El elemento de la posicion cero del 
// nuevo vector es la suma del vector original completo y el ultimo elemento del nuevo vector
// coincide con el valor del ultimo elemento del vector original
// Escribir el invariante para probar la correccion del bucle (invariant)
// Dar una funcion cota del bucle (decreases) y comprobar que Dafny realiza la prueba con ella.
function suma (s : seq<int>) : int
ensures s==[] ==> suma(s) == 0;
ensures s!=[] ==> suma(s) == s[0] + suma(s[1..])

// Realizar un bucle que recorre el vector de derecha a izquierda
// Comenzar con el calculo de w[v.Length-1]
method acumulado (v : array<int>) returns (w : array<int>)
requires /*v != null &&*/ v.Length > 0
ensures /*w != null &&*/ w.Length == v.Length
ensures forall k :: 0 <= k < v.Length ==> w[k] == suma(v[k..])
{
	w := new int[v.Length];  // Reserva memoria para el vector
	// Inicializacion de las variable
	var i := v.Length-1; var sum:=0;
	
	// Bucle que recorre el vector de derecha a izquierda
	while (i >= 0)
  invariant 0 <= i < v.Length
	invariant forall k:: i <= k < v.Length ==> w[k]== suma(v[k..])
  decreases i-1
	{
	sum := sum +v[i];
  w[i]:=sum;
	i:=i-1;
	}
}

// Implementar un metodo que cuente el numero de posiciones de un vector que son
// mayores que todas las posiciones que tienen a su izquierda. 
// Por ejemplo, el vector: 8 5 6 10 12 4 7 5 14 7, tiene como picos el 8, 10, 12, 14

// Definir un predicado que sea cierto si la posicion i del vector tiene un pico
predicate espico(s:seq<int>,i:int)
requires 0<=i<|s|
ensures espico(s,i) == forall w:: 0 <= w < i ==> s[i]>=s[w]

// funcion que cuenta el numero de picos de una secuencia
function CountPicos(s:seq<int>,i:int):nat
requires 0 <= i < |s| && |s| > 0
ensures i==0 ==> CountPicos(s,i)==1
ensures i > 0 && espico(s,i) ==> CountPicos(s,i) == 1 + CountPicos(s,i-1)
ensures i > 0 && !espico(s,i) ==> CountPicos(s,i) == CountPicos(s,i-1)


// metodo que cuenta el numero de picos de un vector
method numPicos(v:array<int>) returns (n:int) 
requires v.Length > 0
ensures n == CountPicos(v[..],v.Length-1)
{
	// Inicializacion de las variables
	var i := 1;
  var mayor := 0;
  n:=1;
	// Bucle con invariante funcion cota
	while(i<v.Length)
	invariant 1 <= i <= v.Length && 0 <= mayor < i
  invariant forall k:: 0 <= k < i ==> v[mayor] >= v[k]
  invariant n == CountPicos(v[..],i-1)
  decreases v.Length - i
	{
		// Cuerpo del bucle
    if(v[i]>=v[mayor]){
    mayor:=i;
    n:=n+1;
  }
  i:=i+1;
	}
}