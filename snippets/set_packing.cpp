#include "/home/natanvek/0-COMPUTER/0-PROGRAMACION/8-COMPETENCIA/Template/macros.cpp"
//-----------------------------

/*----------------------------------------------------------------*
    name: set_packing
*----------------------------------------------------------------*/

/*----------------------------------------------------------------*
    prefix: set_packing
*----------------------------------------------------------------*/

/*----------------------------------------------------------------*
    description: es un problema NP que se basa en tomar la mayor cantidad de conjuntos tal que su interseccion dos a dos es vacia
*----------------------------------------------------------------*/

//----------------------------------------------------------------
//  body:
template <typename T>
int set_packing(const vt<uset<T>>& sets) {  
    uset<T> U;
    for (const uset<T>& s : sets)
        for (const T& x : s) U.insert(x);

    int n = sets.size();

    vb bad(1 << n);
    for (const T& x : U) {
        int meTienen = 0;
        forn(i, 0, n) if (sets[i].count(x)) meTienen |= 1 << i;
        if(popcnt(meTienen) > 1) bad[meTienen] = true;
    }

    forr(i, (1 << n)-1, 0) 
        if(bad[i] && popcnt(i) > 1) 
            forn(b, 0, n) 
                bad[i | (1 << b)] = true;
    
    forn(i, 0, 1 << n) 
        if(bad[i] && popcnt(i) > 1) 
            forn(b, 0, n) 
                bad[i | (1 << b)] = true;



    // todos los que cumplen !bad[i] son conjuntos de sets tomables, aca almacena cuantos bits tiene el maximo
    // es decir cual es la mayor cantidad de sets tomables, si retornamos i tenemos un numero cuyos bits
    // representan que sets tenemos que tomar
    int rta = 0;
    forn(i, 0, 1 << n) 
        if (!bad[i] && popcnt(i) > popcnt(rta)) rta = i;

    // rta la minima cantidad de sets que hay que tomar
    return rta;
}