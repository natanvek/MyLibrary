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

    void push() {
        if (lazyDesactualizado) {
            if (l != r) {
                leftChild->stackLazy(lazy);
                rightChild->stackLazy(lazy);
            }

            leaf(lazy);
            lazyDesactualizado = false;
        }
    }

    void stackLazy(TYPE val) {
        lazyDesactualizado = true;
        lazy = val;
    }
};