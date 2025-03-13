#include "/home/natanvek/0-COMPUTER/0-PROGRAMACION/8-COMPETENCIA/Template/macros.cpp"
//-----------------------------



/*----------------------------------------------------------------*
    name: testearTrees 
*----------------------------------------------------------------*/

/*----------------------------------------------------------------*
    prefix: testearTrees 
*----------------------------------------------------------------*/

/*----------------------------------------------------------------*
    description:  
*----------------------------------------------------------------*/

//----------------------------------------------------------------
//  body:
forn(T, 0, 1000) {
    int n = 5000;
    int x = x = rand() % n; 
    int entre[n+100], sali[n+100], padre[n+100];
    vvi g(n);

    // agregar asserts por todos lados en el codigo cuando se rompa algo
    // input.in va a tener el test que se rompio.
    // entonces si comentas estas lineas y descomentas las de abajo 

    ofstream writeInput("input.in");
    writeInput << n << endl;
    forn(i, 1, n){
        // armar grafo
        // padre[i] = i-1;
        int previos = min(i, i);
        padre[i] = rand() % previos + i - previos;
        g[padre[i]].pb(i);
        writeInput << padre[i]+1 << " " << i + 1 << endl;
    } 
    writeInput << x << endl;
    writeInput.close();


    // esto sirve para que 
    // ifstream file("input.in");
    // file >> n;
    // g.resize(n);
    // forn(i, 0, n-1) {
    //     int u, v; 
    //     file >> u >> v; --u, --v;
    //     g[u].pb(v);
    //     g[v].pb(u);
    // }
    // file >> x;
    // file.close();

    int estoy = 0;
    forn(i, 0, n) entre[i] = -1;
    function<void(int)> dfs = [&](int v) {
        entre[v] = estoy++;
        for (int u : g[v]) if(entre[u] == -1)dfs(u);
        sali[v] = estoy++;
    };
    dfs(0);
    solve();
    debug(x);
}