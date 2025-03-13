#include "/home/natanvek/0-COMPUTER/0-PROGRAMACION/8-COMPETENCIA/Template/macros.cpp"
//-----------------------------



/*----------------------------------------------------------------*
    name: segtree 
*----------------------------------------------------------------*/

/*----------------------------------------------------------------*
    prefix: segtree 
*----------------------------------------------------------------*/

/*----------------------------------------------------------------*
    description: es una version de segtree que es como un arbol donde el vertice inicial representa el vector entero y almacena un struct con memoria por rangos que es bastante poderosa 
*----------------------------------------------------------------*/

//----------------------------------------------------------------
//  body:


template <class Node>
struct SegmentTree {

    vector<Node> auxiliar;
    Node root;
    using TYPE = typename Node::TYPE;

    int n; 

    SegmentTree(const vector<TYPE> &a) : n(a.size()) {
        if(_a.empty()) return;
        int SIZE = 1 << (__lg(n) + bool(__builtin_popcount(n) - 1));
        auxiliar.reserve(2 * SIZE);
        build(root, 0, n-1, a);
    }

    void build(Node& ran, int l, int r, const vector<TYPE> &a) {
        ran.l = l; 
        ran.r = r;
        if(l == r) {
            return ran.leaf(a[l]);
        }

        auxiliar.pb(Node()); Node& izq = auxiliar.back();
        auxiliar.pb(Node()); Node& der = auxiliar.back();

        int m = (l + r) / 2;
        build(izq, l, m, a);
        build(der, m+1, r, a);
        
        ran.leftChild = &izq;
        ran.rightChild = &der;

        ran.merge();
    }

    void update(Node& ran, int i, int j, TYPE val) { // aca no hay que cambiar nada creo [i, j] el update
        if (ran.l == i && ran.r == j) {
            ran.stackLazy(val);
            ran.push();
            return;
        }

        ran.push();

        int m = (ran.l + ran.r) / 2;
        if (j <= m) {
            update(*ran.leftChild, i, j, val);
            ran.rightChild->push();
        } else if (i > m) {
            ran.leftChild->push();
            update(*ran.rightChild, i, j, val);
        } else {
            update(*ran.leftChild, i, m, val);
            update(*ran.rightChild, m+1, j, val);
        }
        ran.merge();
    }

    void update(int i, int j, TYPE val) { // esto reemplaza todos los valores de una zona por val
        assert(0 <= i && i <= j && j < n);
        update(root, i, j, val);
    }

    void set(int i, TYPE val) { // aca no hay que cambiar nada creo [i, j] el update
        assert(0 <= i && i < n);
        update(i, i, val);
    }

    Node query(Node& ran, int i, int j) { 
        // en teoria no habria que tocar esta funcion
        ran.push();
        if (i == ran.l && ran.r == j) return ran;
        

        int m = (ran.l + ran.r) / 2;

        
        if (j <= m) {
            return query(*ran.leftChild, i, j);
        } else if (i > m) {
            return query(*ran.rightChild, i, j);
        } else {
            Node rta;
            Node izq = query(*ran.leftChild, i, m); rta.leftChild = &izq;
            Node der = query(*ran.rightChild, m+1, j); rta.rightChild = &der;          
            rta.merge();
            return rta;
        }
    }
 
    
    Node query(int i, int j) { // [i, j]
        assert(0 <= i && i <= j && j < n);
        return query(root, i, j);
    }

    Node get(int i) { // [i, j]
        assert(0 <= i && i < n);
        return query(i, i);
    }
};