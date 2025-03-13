#include "/home/natanvek/0-COMPUTER/0-PROGRAMACION/8-COMPETENCIA/Template/macros.cpp"
//-----------------------------



/*----------------------------------------------------------------*
    name: Mo's Algorithm for Queries 
*----------------------------------------------------------------*/

/*----------------------------------------------------------------*
    prefix: MosQueries 
*----------------------------------------------------------------*/

/*----------------------------------------------------------------*
    description: Es un algoritmo para resolver queries de manera offline que permite observar la totalidad del rango del query y las ordena de forma que queda O(n * sq(n)) 
*----------------------------------------------------------------*/

//----------------------------------------------------------------
//  body:
vector<array<int,3>> qs(q);
for (int i=0;i<q;i++) cin >> qs[i][0] >> qs[i][1], qs[i][2] = i;

int K = 700;
auto cmp = [&](array<int,3> &a, array<int,3> &b){return make_pair(make_pair(a[0]/K,a[1]/K),a) < make_pair(make_pair(b[0]/K,b[1]/K),b);};
sortvc(qs, cmp);

int l = 0, r = 0;

vector<bool> rta(q);

for (auto &c : qs){
    c[0]--,c[1]--;

    while (r < c[1]){ ++r; 
        // agregar a la estructura activa el elemento en r
    }

    while (l > c[0]){ --l;
        // agregar a la estructura activa el elemento en l
    }

    for (; l < c[0]; ++l){
        // sacar de la estructura activa el elemento en l
        
    }

    for (;r > c[1]; --r){
        // sacar de la estructura activa el elemento en r
    }

    rta[c[2]] = false/*la respuesta de la query*/;
}
put(rta);