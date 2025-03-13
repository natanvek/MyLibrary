#include "/home/natanvek/0-COMPUTER/0-PROGRAMACION/8-COMPETENCIA/Template/macros.cpp"
//-----------------------------



/*----------------------------------------------------------------*
    name: tree 
*----------------------------------------------------------------*/

/*----------------------------------------------------------------*
    prefix: tree 
*----------------------------------------------------------------*/

/*----------------------------------------------------------------*
    description: para hacer dfs con varias funciones utiles ya codeadas, hijos, p, etc 
*----------------------------------------------------------------*/

//----------------------------------------------------------------
//  body:
struct Tree {
    int n, estoy = 0;
    vvi g;
    int root;
    vi entre, sali, p, hijos, prof, dist_root;
    Tree(int _n, int _root) : n(_n), root(_root) {
        g.resize(n);
        forn(i, 0, n - 1) {
            int rd(u, v);
            --u, --v;
            g[u].pb(v);
            g[v].pb(u);
        }
        entre.resize(n, -1); sali.resize(n, -1);
        p.resize(n, -1); hijos.resize(n, 1);
        prof.resize(n, 0); dist_root.resize(n, 1);
        dfs(root);
    }

    bool esHijo(int hijo, int padre) {
        return entre[padre] <= entre[hijo] && sali[hijo] <= sali[padre];
    }

    void dfs(int v) {
        entre[v] = estoy++;
        for (int u : g[v]) {
            if (entre[u] != -1) continue;
            p[u] = v;
            dist_root[u] = dist_root[v] + 1;
            dfs(u);
            maxeq(prof[v], prof[u] + 1);
            hijos[v] += hijos[u];
        }
        sali[v] = estoy++;
    }

    vi camino(int a, int b) {  // a .. p .. b
        vi rta = {a};
        while (!esHijo(b, a)) {
            a = p[a];
            rta.pb(a);
        }

        vi pbs = {};
        while (b != a) {
            pbs.pb(b);
            b = p[b];
        }
        while (len(pbs)) {
            rta.pb(pbs.back());
            pbs.ppb();
        };
        return rta;
    }
};