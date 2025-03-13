#include "/home/natanvek/0-COMPUTER/0-PROGRAMACION/8-COMPETENCIA/Template/macros.cpp"
//-----------------------------



/*----------------------------------------------------------------*
    name: GCDNode 
*----------------------------------------------------------------*/

/*----------------------------------------------------------------*
    prefix: GCDNode 
*----------------------------------------------------------------*/

/*----------------------------------------------------------------*
    description: sirve para calcular gcds con el segtree 
*----------------------------------------------------------------*/

//----------------------------------------------------------------
//  body:
ll gcd(ll a, ll b){
    if(a==0) return b;
    return gcd(b%a, a);
}


template <class T>
struct GCDNode {
    using TYPE = T;
    int l, r; 
    GCDNode *leftChild, *rightChild;
    TYPE lazy = 0, g = 0;
    bool lazyDesactualizado = false;

    void leaf(TYPE val) {
        // dado v vector original del segtree si v[i] = val que queres guardar en la leaf i
        g = val;
    }

    void merge() {
        g = gcd(leftChild->g, rightChild->g);
    }

    void push() {
        // puede ser necesario modificar la condicion y como se stackLazy
        if (!lazyDesactualizado) return;

        // aviso a mis hijos
        if (l != r) {
            leftChild->stackLazy(lazy);
            rightChild->stackLazy(lazy);
        }

        // actualizar mi lazy
        leaf(lazy);
        lazyDesactualizado = false;
        
    }

    void stackLazy(TYPE val) {
        // aca hay que tener cuidado esto es lo que efectua el update 
        lazyDesactualizado = true;
        lazy = val;
    }
};