#include "/home/natanvek/0-COMPUTER/0-PROGRAMACION/8-COMPETENCIA/Template/macros.cpp"
//--------------------------------------


/*----------------------------------------------------------------*
    name: max_flow 
*----------------------------------------------------------------*/

/*----------------------------------------------------------------*
    prefix: flujo
*----------------------------------------------------------------*/

/*----------------------------------------------------------------*
    description: algoritmo para calcular el maximo flujo de un sistema, o el corte minimo 
*----------------------------------------------------------------*/

//----------------------------------------------------------------
//  body:
class Flujo {
private:
    int INF = 1e8;
    vector<vector<int>> capacity;
    vector<vector<int>> adj;

    int bfs(vector<int>& parent) {
        fill(parent.begin(), parent.end(), -1);
        parent[canilla] = -2;
        queue<pair<int, int>> q;
        q.push({canilla, INF});

        while (!q.empty()) {
            int cur = q.front().first;
            int flow = q.front().second;
            q.pop();

            for (int next : adj[cur]) {
                if (parent[next] == -1 && capacity[cur][next]) {
                    parent[next] = cur;
                    int new_flow = min(flow, capacity[cur][next]);
                    if (next == agujero)
                        return new_flow;
                    q.push({next, new_flow});
                }
            }
        }

        return 0;
    }

public:
    int n, canilla, agujero;
    Flujo(int _n, int _canilla, int _agujero) {
        n = _n;
        capacity.resize(n, vector<int>(n));
        adj.resize(n);
        canilla = _canilla;
        agujero = _agujero;
    }
    
    int maxflow() {
        int flow = 0;
        vector<int> parent(n);
        int new_flow;

        while (new_flow = bfs(parent)) {
            flow += new_flow;
            int cur = agujero;
            while (cur != canilla) {
                int prev = parent[cur];
                capacity[prev][cur] -= new_flow;
                capacity[cur][prev] += new_flow;
                cur = prev;
            }
        }

        return flow;
    }

    void addEdge(int u, int v, int capacidad_ida, int capacidad_vuelta = 0) {
        adj[u].pb(v);
        adj[v].pb(u);
        capacity[u][v] = capacidad_ida;
        capacity[v][u] = capacidad_vuelta;
    }
};