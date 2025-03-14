#include "/home/natanvek/0-COMPUTER/0-PROGRAMACION/8-COMPETENCIA/Template/macros.cpp"
//--------------------------------------

/*----------------------------------------------------------------*
    name: MaxNode
*----------------------------------------------------------------*/

/*----------------------------------------------------------------*
    prefix: MaxNode 
*----------------------------------------------------------------*/

/*----------------------------------------------------------------*
    description:  
*----------------------------------------------------------------*/

//----------------------------------------------------------------
//  body:

template <class T>
struct MaxNode {
    using TYPE = T;
    int l, r; 
    MaxNode *leftChild, *rightChild;
    TYPE lazy = 0, mx = 0;
    int pos;
    bool lazyDesactualizado = false;

    void leaf(TYPE val) {
        // dado v vector original del segtree si v[i] = val que queres guardar en la leaf i
        mx = val;
        pos = l;
    }

    void merge() {
        if(leftChild->mx >= rightChild->mx) {
            mx = leftChild->mx;
            pos = leftChild->pos;
        } else {
            mx = rightChild->mx;
            pos = rightChild->pos;
        }
    }

    void push() { // esto solo sirve para el update de a rangos
        // puede ser necesario modificar la condicion y como se stackLazy
        if(!lazyDesactualizado) return;

        // aviso a mis hijos
        if (l != r) {
            leftChild->stackLazy(lazy);
            rightChild->stackLazy(lazy);
        }

        // actualizar mi lazy
        mx = lazy;
        pos = l;
        lazyDesactualizado = false;
    }

    void stackLazy(TYPE val) {
        // aca hay que tener cuidado esto es lo que efectua el update 
        lazyDesactualizado = true;
        lazy = val;
    }
};