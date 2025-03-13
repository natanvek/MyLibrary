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
struct Peso {
    ll t;
    bool operator<(const Peso& b) const {
        return tie(t) < tie(b.t);
    }

    Peso operator+(const Peso& b) {
        return {t + b.t};
    }
};

vector<Peso> dijkstra_mlogm(vector<vector<pair<int, Peso>>>& grafo, ll v) {
    ll n = grafo.size();
    ll m = 0;
    forn(i, 0, n) m += grafo[i].size();

    if (n * n < m * log(m)) {
        return dijkstran2(grafo, v);
    } else {
        return dijkstra_mlogm(grafo, v);
    }
}
vector<Peso> dijkstra_mlogm(vector<vector<pair<int, Peso>>>& grafo, ll v) {
    ll n = grafo.size();

    vector<Peso> dist(n, {infll});
    dist[v] = {0};

    auto compPeso = [&dist](int a, int b) { return dist[b] < dist[a]; };
    priority_queue<int, vi, decltype(compPeso)> heap(compPeso);

    heap.push(v);
    vector<bool> esta(n, false);

    while (!heap.empty()) {
        int w = heap.top();
        heap.pop();
        if (esta[w]) continue;
        esta[w] = true;
        for (auto& [u, p] : grafo[w])
            if (mineq(dist[u], p + dist[w]))
                heap.push(u);
    }

    return dist;
}

vector<Peso> dijkstran2(vector<vector<pair<int, Peso>>>& grafo, ll v) { // falta testear
    ll n = grafo.size();

    vector<Peso> dist(n, {infll});
    dist[v] = {0};
    vector<bool> esta(n, false);

    forn (_, 0, n) {
        Peso peor = {infll};
        int w;
        forn(i, 0, n) 
            if(!esta[i] && mineq(peor, dist[i])) w = i;

        esta[w] = true;

        for (auto& [u, p] : grafo[w])
            mineq(dist[u], p + dist[w]);        
    }

    return dist;
}