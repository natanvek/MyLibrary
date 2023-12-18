#include "/home/natanvek/0-COMPUTER/0-PROGRAMACION/8-COMPETENCIA/Template/macros.cpp"
//--------------------------------------


/*----------------------------------------------------------------*
    name: inverso_modular 
*----------------------------------------------------------------*/

/*----------------------------------------------------------------*
    prefix: modInverse 
*----------------------------------------------------------------*/

/*----------------------------------------------------------------*
    description: sirve para calcular probas, tambien incluye un gcd extendaporta una propiedad matematica interesante al gcd convencional 
*----------------------------------------------------------------*/

//----------------------------------------------------------------
//  body:
// Función para calcular el máximo común divisor (GCD) usando el algoritmo de Euclides extendido.
// También calcula los coeficientes 'x' y 'y' de la identidad de Bezout: a*x + b*y = GCD(a, b)
int gcd_ext (int a, int b, int & x, int & y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	int x1, y1;
	int d = gcd_ext (b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}

// Función para calcular el inverso modular de 'a' en modulo 'm'.
int modInverse(int a, int m) {
    int x, y;
    int gcd = gcd_ext(a, m, x, y);
    // Asegurarse de que el inverso esté en el rango [0, m-1]
    return (x % m + m) % m;
}