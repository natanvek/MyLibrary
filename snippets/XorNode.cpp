#include "/home/natanvek/0-COMPUTER/0-PROGRAMACION/8-COMPETENCIA/Template/macros.cpp"
//--------------------------------------

/*----------------------------------------------------------------*
    name: XorNode 
*----------------------------------------------------------------*/

/*----------------------------------------------------------------*
    prefix: XorNode 
*----------------------------------------------------------------*/

/*----------------------------------------------------------------*
    description:  
*----------------------------------------------------------------*/

//----------------------------------------------------------------
//  body:


struct XorNode {
    using TYPE = ll;
    int l, r; 
    XorNode *leftChild, *rightChild;
    TYPE lazy = 0, value;
    int pos;
    bool lazyDesactualizado = false;

    void leaf(TYPE val) {
        value = val;
    }

    void merge() {
        value = leftChild->value ^ rightChild->value;
    }

    void push() {
        if (lazyDesactualizado) {
            if (l != r) {
                leftChild->stackLazy(lazy);
                rightChild->stackLazy(lazy);
            } 
            
            if(!even(r - l + 1)) value ^= lazy;

            lazy = 0;
            lazyDesactualizado = false;
        }
    }

    void stackLazy(TYPE val) {
        lazyDesactualizado = true;
        lazy ^= val;
        
    }
};