#include "/home/natanvek/0-COMPUTER/0-PROGRAMACION/8-COMPETENCIA/Template/macros.cpp"
//--------------------------------------


/*----------------------------------------------------------------*
    name: bfs 
*----------------------------------------------------------------*/

/*----------------------------------------------------------------*
    prefix: bfs 
*----------------------------------------------------------------*/

/*----------------------------------------------------------------*
    description: ya sabes lo que es 
*----------------------------------------------------------------*/

//----------------------------------------------------------------
//  body:
vector<int> bfs(vector<vector<int>>& grafo, int v) {
    queue<int> que;
    vector<int> dist(grafo.size(), -1);
    dist[v] = 0; que.push(v);

    while (!que.empty()) {
        int w = que.front(); que.pop();
        for (int& u : grafo[w]) {
            if (dist[u] == -1) {
                dist[u] = dist[w] + 1;
                que.push(u);
            }
        }
    }

    return dist;
}