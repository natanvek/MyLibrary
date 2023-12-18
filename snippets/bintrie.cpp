#include "/home/natanvek/0-COMPUTER/0-PROGRAMACION/8-COMPETENCIA/Template/macros.cpp"
//--------------------------------------


/*----------------------------------------------------------------*
    name: bintrie 
*----------------------------------------------------------------*/

/*----------------------------------------------------------------*
    prefix: bintrie 
*----------------------------------------------------------------*/

/*----------------------------------------------------------------*
    description: es un trie para almacenar enteros por su representacion binaria y sirve mucho para encontrar xors 
*----------------------------------------------------------------*/

//----------------------------------------------------------------
//  body:
class bintrie {
private:
    struct nodo {
        nodo* children[2];
        nodo() {
            children[0] = nullptr;
            children[1] = nullptr;
        }
        int hijos = 0;
        ~nodo() {
            if(children[0]) delete children[0];
            if(children[1]) delete children[1];
        }
    };

public:
    int bits;
    nodo* root;
    bintrie(int _bits) {
        bits = _bits;
        root = new nodo();
    }
    ~bintrie() {
        delete root; // Calls the recursive destructor
    }
    // dado un x cuya representacion binaria tiene <= 30 bits, lo inserta en el trie
    void insert(int x) {
        nodo* p = root;
        for (int i = bits-1; i >= 0; --i) {
            bool bit = (x & (1 << i));
            if (!p->children[bit]) p->children[bit] = new nodo();
            p->hijos++;
            p = p->children[bit];
        }
        p->hijos++;
    }

    void erase(int x) {
        nodo* p = root;
        for (int i = bits-1; i >= 0; --i) {
            bool bit = (x & (1 << i));
            if(p->children[bit]->hijos == 1) {
                delete p->children[bit];
                p->children[bit] = nullptr;
                break;
            }
            p->hijos--;
            p = p->children[bit];
        }
        p->hijos--;
    }
};


    int desimo_xor(int x, int d = 0) { // d = 0 devuelve el minimo xor con x, d = n el maximo
        nodo *p = root, *h = root;
        int bit = 1 << (bits-1), rta = 0;
        while(h && (bit || d)) {
            if(h->hijos > d) {
                p = h;
                int camino = (h->children[ (x & bit) ? 1 : 0]) ? (x & bit) : ((~x) & bit);
                h = h->children[camino ? 1 : 0];
                rta |= camino;
                bit >>= 1;
            } else {
                d -= h->hijos;
                int bitAnterior = bit == 0 ? 1 : (bit << 1);
                rta ^= bitAnterior;
                h = p->children[(x & bitAnterior) ? 0 : 1];                  
            }
        }
        return rta;
    }
};