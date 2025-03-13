#include "/home/natanvek/0-COMPUTER/0-PROGRAMACION/8-COMPETENCIA/Template/macros.cpp"
//--------------------------------------

/*----------------------------------------------------------------*
    name: SumNode 
*----------------------------------------------------------------*/

/*----------------------------------------------------------------*
    prefix: SumNode 
*----------------------------------------------------------------*/

/*----------------------------------------------------------------*
    description: SumNode es la definicion de la suma, se lo robe a maspy y sirve para range_segtree 
*----------------------------------------------------------------*/

//----------------------------------------------------------------
//  body:
template <class T>
struct SumNode {
    using TYPE = T;
    int l, r; 
    SumNode *leftChild, *rightChild;
    TYPE lazy = 0, sum = 0;
    bool lazyDesactualizado = false;

    void leaf(TYPE val) {
        // dado v vector original del segtree si v[i] = val que queres guardar en la leaf i
        sum = val;
    }

    void merge() {
        sum = leftChild->sum + rightChild->sum;
    }

    void push() {
        // puede ser necesario modificar la condicion y como se stackLazy
        if(!lazyDesactualizado) return;

        // aviso a mis hijos
        if (l != r) {
            leftChild->stackLazy(lazy);
            rightChild->stackLazy(lazy);
        }

        // actualizar mi lazy
        sum += lazy * (r - l + 1);
        lazy = 0;
        lazyDesactualizado = false;
    }

    void stackLazy(TYPE val) {
        lazyDesactualizado = true;
        lazy += val;
    }

};