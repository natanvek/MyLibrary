#include "/home/natanvek/0-COMPUTER/0-PROGRAMACION/8-COMPETENCIA/Template/macros.cpp"
//--------------------------------------

/*----------------------------------------------------------------*
    name: MinNode 
*----------------------------------------------------------------*/

/*----------------------------------------------------------------*
    prefix: MinNode 
*----------------------------------------------------------------*/

/*----------------------------------------------------------------*
    description:  
*----------------------------------------------------------------*/

//----------------------------------------------------------------
//  body:

template <class T>
struct MinNode {
    using TYPE = T;
    int l, r; 
    MinNode *leftChild, *rightChild;
    TYPE lazy = 0, mn = 0;
    int pos;
    bool lazyDesactualizado = false;

    void leaf(TYPE val) {
        // dado v vector original del segtree si v[i] = val que queres guardar en la leaf i
        mn = val;
        pos = l;
    }

    void merge() {
        if(leftChild->mn <= rightChild->mn) {
            mn = leftChild->mn;
            pos = leftChild->pos;
        } else {
            mn = rightChild->mn;
            pos = rightChild->pos;
        }
    }

    void push() { // esto solo sirve para el update de a rangos
        // puede ser necesario modificar la condicion y como se stackLazy
        if (!lazyDesactualizado) return;

        if (l != r) {
            leftChild->stackLazy(lazy);
            rightChild->stackLazy(lazy);
        }

        leaf(lazy);
        lazyDesactualizado = false;
        
    }

    void stackLazy(TYPE val) {
        // aca hay que tener cuidado esto es lo que efectua el update 
        lazyDesactualizado = true;
        lazy = val;
    }
};