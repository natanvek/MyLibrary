#include "/home/natanvek/0-COMPUTER/0-PROGRAMACION/8-COMPETENCIA/Template/macros.cpp"
//-----------------------------



/*----------------------------------------------------------------*
    name: set_cover 
*----------------------------------------------------------------*/

/*----------------------------------------------------------------*
    prefix: set_cover 
*----------------------------------------------------------------*/

/*----------------------------------------------------------------*
    description: es un problema NP, dado un conjunto de sets saber cual es la menor cantidad de sets cuya union es el universo 
*----------------------------------------------------------------*/

//----------------------------------------------------------------
//  body:
template <typename T>
int set_cover(const vt<uset<T>>& sets) { 
    uset<T> U;
    for (const uset<T>& s : sets) U.insert(all(s));
    
    int n = sets.size();

    vb bad(1 << n);
    for(const T& x : U) {
        int noMeTienen = 0;
        forn(i, 0, n) if(!sets[i].count(x)) noMeTienen |= 1 << i;
        bad[noMeTienen] = true; 
    }

    forr(i, (1 << n)-1, 0) 
        forn(b, 0, n) 
            bad[i] = bad[i] || bad[i | (1 << b)];

    // todos los que cumplen !bad[i] son conjuntos de sets tomables, aca almacena cuantos bits tiene el minimo
    // es decir cual es la menor cantidad de sets tomables, si retornamos i tenemos un numero cuyos bits 
    // representan que sets tenemos que tomar
    int rta = n;
    forn(i, 0, 1 << n) 
        if(!bad[i]) mineq(rta, popcnt(i));
    

    // rta la minima cantidad de sets que hay que tomar
    return rta;
    
}
