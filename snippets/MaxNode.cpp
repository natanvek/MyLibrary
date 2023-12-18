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