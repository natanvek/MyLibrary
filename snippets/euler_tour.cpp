#include "/home/natanvek/0-COMPUTER/0-PROGRAMACION/8-COMPETENCIA/Template/macros.cpp"
//--------------------------------------

/*----------------------------------------------------------------*
    name: euler_tour 
*----------------------------------------------------------------*/

/*----------------------------------------------------------------*
    prefix: euler_tour 
*----------------------------------------------------------------*/

/*----------------------------------------------------------------*
    description: es una vectorizacion del dfs, cada vertice aparece en el vector en el orden en el que aparecen en el dfs, es muy util para hacer segment tree de a rangos para un arbol 
*----------------------------------------------------------------*/

//----------------------------------------------------------------
//  body:
        vb esta(n, false);
        vi tour, size(n, 1);
        function<int(int)> euler_tour = [&](int v) {
            esta[v] = true;
            tour.pb(v);
            for (int u : g[v]) {
                if (!esta[u]) size[v] += euler_tour(u);
            }
            return size[v];
        };
        euler_tour(0);

        vi posInTour(n);
        forn(i, 0, n) posInTour[tour[i]] = i;