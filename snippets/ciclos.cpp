#include "/home/natanvek/0-COMPUTER/0-PROGRAMACION/8-COMPETENCIA/Template/macros.cpp"
//--------------------------------------


/*----------------------------------------------------------------*
    name: ciclos 
*----------------------------------------------------------------*/

/*----------------------------------------------------------------*
    prefix: ciclos 
*----------------------------------------------------------------*/

/*----------------------------------------------------------------*
    description: dado un grafo no necesariamente arbol donde cada nodo tiene exactamente una arista saliente hallar los ciclos que se forman 
*----------------------------------------------------------------*/

//----------------------------------------------------------------
//  body:

vvi armarCiclos(vi& a) {
    int n = a.sz;

    vvi ciclos;
    vi vis(n, 0);
    forn(i, 0, n) {
        if(vis[i]) continue; 
        int cur = i;
        for(; !vis[cur]; cur = a[cur]) vis[cur]++;
    
        if(vis[cur] < 2) {
            ciclos.pb({});
            for(; vis[cur] < 2; cur = a[cur]) {
                ciclos.back().pb(cur);
                vis[cur]++;
            };
        }
        for(cur = i; vis[cur] < 2; cur = a[cur]) vis[cur]++;
    }

    return ciclos;
} 


int main() {
    vi a; int n;

    vi h(n, 0), indep;
    forn(i, 0, n) h[a[i]]++;
    forc(i, 0, n, h[i] == 0) indep.pb(i);            

    vi rta;
    while(indep.size()) {
        int p = indep.back(); indep.ppb();

        // editar codigo para recorrer por ramas

        if(--h[a[p]] == 0) indep.pb(a[p]); 
    }

    vvi ciclos = armarCiclos(a);
    vi enCiclo(n, -1);
    forvi(i, ciclo, ciclos) {
        // aca ciclo es una REFERENCIA a v[i] y i recorre de 0 <= i < n
        for(int elem : ciclo) enCiclo[elem] = i;
    }
}
