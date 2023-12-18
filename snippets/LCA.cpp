#include "/home/natanvek/0-COMPUTER/0-PROGRAMACION/8-COMPETENCIA/Template/macros.cpp"
//--------------------------------------


/*----------------------------------------------------------------*
    name: LCA 
*----------------------------------------------------------------*/

/*----------------------------------------------------------------*
    prefix: lca 
*----------------------------------------------------------------*/

/*----------------------------------------------------------------*
    description: lowest-common-ancestor es un algoritmo que sirve para obten, dados dos vertices cual es el padre mas cercano que tienen ambos nodos en comun 
*----------------------------------------------------------------*/

//----------------------------------------------------------------
//  body:
struct LCA {
    int n, l;
    int timer;
    vector<int> tin, tout;
    vector<vector<int>> up;

    LCA(vector<vector<int>> &adj, int root = 0) {
        n = adj.size();
        tin.resize(n);
        tout.resize(n);
        timer = 0;
        l = ceil(log2(n));
        up.assign(n, vector<int>(l + 1));
        dfs(root, root, adj);
    }

    void dfs(int v, int p, vector<vector<int>> &adj) {
        tin[v] = ++timer;
        up[v][0] = p;
        for (int i = 1; i <= l; ++i)
            up[v][i] = up[up[v][i - 1]][i - 1];

        for (int u : adj[v]) {
            if (u != p)
                dfs(u, v, adj);
        }

        tout[v] = ++timer;
    }

    bool is_ancestor(int u, int v) {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }

    int lca(int u, int v) {
        if (is_ancestor(u, v)) return u;
        if (is_ancestor(v, u)) return v;

        for (int i = l; i >= 0; --i) {
            if (!is_ancestor(up[u][i], v))
                u = up[u][i];
        }
        return up[u][0];
    }
};