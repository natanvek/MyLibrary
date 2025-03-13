#include "/home/natanvek/0-COMPUTER/0-PROGRAMACION/8-COMPETENCIA/Template/macros.cpp"
//-----------------------------



/*----------------------------------------------------------------*
    name: mex 
*----------------------------------------------------------------*/

/*----------------------------------------------------------------*
    prefix: mex 
*----------------------------------------------------------------*/

/*----------------------------------------------------------------*
    description: sirve para calular un vector con los primeros k minimos elementos excluidos del array empezando del 0 
*----------------------------------------------------------------*/

//----------------------------------------------------------------
//  body:
auto mex = [&](vll x, int k) -> vll {
    sortv(x);
    vll rta;
    ll m = 0;
    for(auto xi : x) {
        while(m < xi && k--) rta.pb(m++);   
        if(k <= 0) return rta;
        if(xi == m) ++m;
    }
    while(k--) rta.pb(m++);  
    return rta;
};