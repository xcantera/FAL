// Marina Lozano Lahuerta  E31
// Ana Álava Papí  E71

// Intercambio del valor de dos posiciones de un vector
// Version correcta

method swap (v : array<int>, i : int, j : int) 
requires 0 <= i < v.Length && 0 <= j < v.Length
ensures old(v[i])==v[j] && old(v[j])==v[i]
modifies v
{
	var aux := v[i];
	v[i] := v[j];
	v[j] := aux;
}


// Funcion que comprueba que todos los elementos de un vector son pares
predicate par (n : int)
{n%2 == 0}

method verificaPar (v : array<int>) returns (b : bool)
requires v.Length > 0
ensures b == forall w :: 0 <= w < v.Length ==> par(v[w])
{
	var i := 0;
	while (i < v.Length && v[i]%2 == 0) 
	invariant 0 <= i <= v.Length
	invariant forall w :: 0 <= w < i ==> par(v[w])
	{
		i := i + 1;
	}
	b := i == v.Length;
}


// Funcion que calcula el valor maximo de un vector
method maximo (v : array<int>) returns (m : int)
requires v.Length > 0
ensures forall w:: 0<=w<v.Length ==> m >= v[w]
ensures exists k :: 0<=k<v.Length && v[k]==m
{
	var i := 1;
	m := v[0];
	while (i < v.Length) 
	invariant 0 <= i <= v.Length
	invariant forall k :: 0 <= k < i ==> m >= v[k]
	invariant m in v[..i]
	decreases v.Length - i
	{
		if (m < v[i]) {m := v[i];}
		i := i+1;
	}
}