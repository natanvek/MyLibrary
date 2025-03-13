#include "/home/natanvek/0-COMPUTER/0-PROGRAMACION/8-COMPETENCIA/Template/macros.cpp"
//-----------------------------



/*----------------------------------------------------------------*
    name: leftMinRightMin 
*----------------------------------------------------------------*/

/*----------------------------------------------------------------*
    prefix: leftMinRightMin 
*----------------------------------------------------------------*/

/*----------------------------------------------------------------*
    description: Es un algoritmo para que dado un vector, sabercada posicion en O(n) cual es el primero mas chico a su izq y der 
*----------------------------------------------------------------*/

//----------------------------------------------------------------
//  body:
    vll min_izq(n, -1), min_der(n, n);
    forn(i, 1, n) {
        min_izq[i] = i-1;
        while(min_izq[i] > -1 && v[min_izq[i]] > v[i]) min_izq[i] = min_izq[min_izq[i]];
    }

    forr(i, n-2, 0) {
        min_der[i] = i+1;
        while(min_der[i] < n && v[min_der[i]] > v[i]) min_der[i] = min_der[min_der[i]];
    }