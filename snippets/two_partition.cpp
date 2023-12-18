#include "/home/natanvek/0-COMPUTER/0-PROGRAMACION/8-COMPETENCIA/Template/macros.cpp"
//--------------------------------------


/*----------------------------------------------------------------*
    name: two_partition 
*----------------------------------------------------------------*/

/*----------------------------------------------------------------*
    prefix: two_part 
*----------------------------------------------------------------*/

/*----------------------------------------------------------------*
    description: dado un conjunto de numeros, intenta dividir estos en 2 grupos que sumen lo mas cercano posible 
*----------------------------------------------------------------*/

//----------------------------------------------------------------
//  body:
int two_part(vector<int>& v, int s) {
    // dado un vector de elementos, posiblemente repetidos, trata de armar 2 grupos que sumen lo mas cerca posible 
    // s corresponde con la suma de todos los elementos del vector;
    ++s;

    // si no hay repetidos se puede eliminar esta parte del algoritmo
    vector<int> count(s, 0);
    for(int k : v) count[k]++;

    v = {};
    forn(i, 1, s) {
        if(!count[i]) continue;
        if(count[i] >= 3) count[i << 1] += (count[i]-1) >> 1;
        count[i] = 1 + ((count[i]-1) & 1);
        v.pb(i);
        if(count[i] == 2) v.pb(i);
    }
    // hasta aca

    vector<bool> b(s, false); b[0] = true;
    for(int k : v) { 
        fornn(i, s-1, 0) if(b[i]) b[i + k] = true;
    }

    int mn = 0;
    forn(i, 1, s) if(b[i]) mineq(mn, i - (s - i - 1));
    return mn;
}

