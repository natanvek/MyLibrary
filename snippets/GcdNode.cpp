#include "/home/natanvek/0-COMPUTER/0-PROGRAMACION/8-COMPETENCIA/Template/macros.cpp"
//--------------------------------------

/*----------------------------------------------------------------*
    name: GcdNode 
*----------------------------------------------------------------*/

/*----------------------------------------------------------------*
    prefix: monoid_gcd 
*----------------------------------------------------------------*/

/*----------------------------------------------------------------*
    description: es de la libreria de maspy es para funciones tipo segtree usando monoid_gcd 
*----------------------------------------------------------------*/

//----------------------------------------------------------------
//  body:

struct GcdNode {
    using TYPE = ll;
    int l, r; 
    GcdNode *leftChild, *rightChild;
    TYPE lazy = 0, value;
    int pos;
    bool lazyDesactualizado = false;

    void leaf(TYPE val) {
        value = val;
    }

    void Merge() {
        value = gcd(leftChild->value, rightChild->value);
    }

    void push() {
        if (lazyDesactualizado) {
            if (l != r) {
                leftChild->stackLazy(lazy);
                rightChild->stackLazy(lazy);
            }

            value = gcd(value, lazy);
            lazy = 0;
            lazyDesactualizado = false;
        }
    }

    void stackLazy(TYPE val) {
        lazyDesactualizado = true;
        lazy = gcd(lazy, val);
    }
};