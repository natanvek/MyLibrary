#include "/home/natanvek/0-COMPUTER/0-PROGRAMACION/8-COMPETENCIA/Template/macros.cpp"
//--------------------------------------

/*----------------------------------------------------------------*
    name: AndNode 
*----------------------------------------------------------------*/

/*----------------------------------------------------------------*
    prefix: AndNode 
*----------------------------------------------------------------*/

/*----------------------------------------------------------------*
    description:  
*----------------------------------------------------------------*/

//----------------------------------------------------------------
//  body:


struct AndNode {
    using TYPE = ll;
    int l, r; 
    AndNode *leftChild, *rightChild;
    TYPE lazy = INT64_MAX, value;
    int pos;
    bool lazyDesactualizado = false;

    void leaf(TYPE val) {
        value = val;
    }

    void merge() {
        value = leftChild->value & rightChild->value;
    }

    void push() {
        if (lazyDesactualizado) {
            if (l != r) {
                leftChild->stackLazy(lazy);
                rightChild->stackLazy(lazy);
            }

            value &= lazy;
            lazy = INT64_MAX;
            lazyDesactualizado = false;
        }
    }

    void stackLazy(TYPE val) {
        lazyDesactualizado = true;
        lazy &= val;
    }
};