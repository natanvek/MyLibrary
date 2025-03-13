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
        // dado v vector original del segtree si v[i] = val que queres guardar en la leaf i
        value = val;
    }

    void Merge() {
        return;
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
        value = lazy;
        lazyDesactualizado = false;
        
    }

    void stackLazy(TYPE val) {
        // aca hay que tener cuidado esto es lo que efectua el update 
        lazyDesactualizado = true;
        lazy = val;
        
    }
};