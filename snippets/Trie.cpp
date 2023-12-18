#include "/home/natanvek/0-COMPUTER/0-PROGRAMACION/8-COMPETENCIA/Template/macros.cpp"
//--------------------------------------

/*----------------------------------------------------------------*
    name: Trie 
*----------------------------------------------------------------*/

/*----------------------------------------------------------------*
    prefix: Trie 
*----------------------------------------------------------------*/

/*----------------------------------------------------------------*
    description: string  
*----------------------------------------------------------------*/

//----------------------------------------------------------------
//  body:

struct Trie {
    using MP = map<char, int>;
    int n_node;
    vector<MP> TO;
    vector<int> PAR;
    vector<int> CUANTOS;

    Trie() : n_node(1), TO({MP()}), PAR({-1}), CUANTOS({0}) {}

    int add(string S) {
        int v = 0;
        for (auto&& s : S) {
            if (!TO[v].count(s)) {
                TO[v][s] = create_node();
                PAR[TO[v][s]] = v;
            }
            v = TO[v][s];
            CUANTOS[v] += 1;
        }
        return v;
    }

    vi occ(string S){
        vi rta;
        int v = 0;
        for (auto&& s : S) {
            if (!TO[v].count(s)) break;
            v = TO[v][s];
            rta.pb(CUANTOS[v]);
        }
        return rta;
    };

    int create_node() {
        TO.emplace_back(MP());
        PAR.emplace_back(-1);
        CUANTOS.emplace_back(0);
        return n_node++;
    }
};