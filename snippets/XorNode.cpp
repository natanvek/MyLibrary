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
        // dado v vector original del segtree si v[i] = val que queres guardar en la leaf i
        value = val;
    }

    void merge() {
        value = leftChild->value ^ rightChild->value;
    }

    void push() { // esto solo sirve para el update de a rangos
        // puede ser necesario modificar la condicion y como se stackLazy
        if (lazyDesactualizado) return;

        if (l != r) {
            leftChild->stackLazy(lazy);
            rightChild->stackLazy(lazy);
        }         

        // actualizar mi lazy
        if(!even(r - l + 1)) value ^= lazy;
        lazy = 0;
        lazyDesactualizado = false;
        
    }

    void stackLazy(TYPE val) {
        // aca hay que tener cuidado esto es lo que efectua el update 
        lazyDesactualizado = true;
        lazy ^= val;
        
    }
};