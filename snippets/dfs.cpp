#include "/home/natanvek/0-COMPUTER/0-PROGRAMACION/8-COMPETENCIA/Template/macros.cpp"
//--------------------------------------


/*----------------------------------------------------------------*
    name: dfs 
*----------------------------------------------------------------*/

/*----------------------------------------------------------------*
    prefix: dfs 
*----------------------------------------------------------------*/

/*----------------------------------------------------------------*
    description: ya sabes lo que hace 
*----------------------------------------------------------------*/

//----------------------------------------------------------------
//  body:
void dfs(int v, vvec<int>& adj, vec<bool>& esta) {
    esta[v] = true;
    for(int u : adj[v]) {
        if(!esta[u]){
            dfs(u, adj, esta);
        }
    }
} 