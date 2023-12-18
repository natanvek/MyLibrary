#include "/home/natanvek/0-COMPUTER/0-PROGRAMACION/8-COMPETENCIA/Template/macros.cpp"
//--------------------------------------


/*----------------------------------------------------------------*
    name: kosaraju 
*----------------------------------------------------------------*/

/*----------------------------------------------------------------*
    prefix: kosaraju 
*----------------------------------------------------------------*/

/*----------------------------------------------------------------*
    description: kosaraju es un algoritmo que sirve para encontrar las componentes fuertemente conexas dentro de un grafo, estas son conjuntos de nodotal que de cada nodo existe un camino a otro nodo de la componente, en un grafo dirigido 
*----------------------------------------------------------------*/

//----------------------------------------------------------------
//  body:
vvi kosaraju(const vvi& g) {
    int n = g.size();
    vb done(n);
    vi pos(n, -1), stack;
    vvi res;
    function<int(int)> dfs = [&](int u) {
        int low = pos[u] = stack.size();
        stack.push_back(u);
        for (int v : g[u]) {
            if (!done[v]) low = min(low, ~pos[v] ? pos[v] : dfs(v)); 
        }
        if (low == pos[u]) {
            res.emplace_back(stack.begin() + low, stack.end());
            for (int v : res.back()) done[v] = true;
            stack.resize(low);
        }
        return low;
    };
    forc(i, 0, n, !done[i]) dfs(i);
    
    reverse(all(res));
    return res;
}