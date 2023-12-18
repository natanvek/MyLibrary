#include "/home/natanvek/0-COMPUTER/0-PROGRAMACION/8-COMPETENCIA/Template/macros.cpp"
//--------------------------------------

/*----------------------------------------------------------------*
    name: dijkstra
*----------------------------------------------------------------*/

/*----------------------------------------------------------------*
    prefix: dijkstra
*----------------------------------------------------------------*/

/*----------------------------------------------------------------*
    description: calcula camino minimo
*----------------------------------------------------------------*/

//----------------------------------------------------------------
//  body:
struct arista {
    ll v, t, c;
    bool operator<(const arista& b) const {
        return tie(t, c) < tie(b.t, b.c);
    }

    arista operator+(const arista& b) {
        return {v, t + b.t, c + b.c};
    }
};

struct compArista {
    bool operator()(const arista& a, const arista& b) const {
        return b < a;  // This makes it a min-heap.
    }
};

arista minima = {-1, 0, 0}, maxima = {-1, INT64_MAX, INT64_MAX};

vector<arista> dijkstra(vector<vector<arista>>& grafo, ll v) {
    ll n = grafo.size();
    priority_queue<arista, vector<arista>, compArista> heap;
    vector<arista> dist(n, maxima);
    dist[v] = minima;
    dist[v].v = v;
    heap.push(dist[v]);
    vector<bool> esta(n, false);

    while (!heap.empty()) {
        ll w = heap.top().v; heap.pop();
        if (esta[w]) continue;
        esta[w] = true;
        for (arista& u : grafo[w]) {
            // ojo que la suma no es conmutativa
            arista k = (u + dist[w]); 
            if (k < dist[k.v]) {
                dist[k.v] = k;
                heap.push(k);
            }
        }
    }

    return dist;
}

