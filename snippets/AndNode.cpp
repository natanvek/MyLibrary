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
        // dado v vector original del segtree si v[i] = val que queres guardar en la leaf i
        value = val;
    }

    void merge() {
        value = leftChild->value & rightChild->value;
    }

    void push() { // esto solo sirve para el update de a rangos
        // puede ser necesario modificar la condicion y como se stackLazy
        if (!lazyDesactualizado) return;

        // aviso a mis hijos
        if (l != r) {
            leftChild->stackLazy(lazy);
            rightChild->stackLazy(lazy);
        }

        // actualizar mi lazy
        value &= lazy;
        lazy = INT64_MAX;
        lazyDesactualizado = false;
    }

    void stackLazy(TYPE val) {
        // aca hay que tener cuidado esto es lo que efectua el update 
        lazyDesactualizado = true;
        lazy &= val;
    }
};