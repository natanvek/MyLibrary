#include "/home/natanvek/0-COMPUTER/0-PROGRAMACION/8-COMPETENCIA/Template/macros.cpp"
//-----------------------------



/*----------------------------------------------------------------*
    name: AssignNode 
*----------------------------------------------------------------*/

/*----------------------------------------------------------------*
    prefix: AssignNode 
*----------------------------------------------------------------*/

/*----------------------------------------------------------------*
    description: monoid_assign para comp ejecuta la operacion de asignacion 
*----------------------------------------------------------------*/

//----------------------------------------------------------------
//  body:

struct AssignNode {
    using TYPE = ll;
    int l, r; 
    AssignNode *leftChild, *rightChild;
    TYPE lazy = 0, value;
    int pos;
    bool lazyDesactualizado = false;

    void leaf(TYPE val) {
        value = val;
    }

    void Merge() {
        return;
    }

    void push() {
        if (lazyDesactualizado) {
            if (l != r) {
                leftChild->stackLazy(lazy);
                rightChild->stackLazy(lazy);
            } 
            
            value = lazy;
            lazyDesactualizado = false;
        }
    }

    void stackLazy(TYPE val) {
        lazyDesactualizado = true;
        lazy = val;
        
    }
};