#include "/home/natanvek/0-COMPUTER/0-PROGRAMACION/8-COMPETENCIA/Template/macros.cpp"
//-----------------------------



/*----------------------------------------------------------------*
    name: PersistentSegTree 
*----------------------------------------------------------------*/

/*----------------------------------------------------------------*
    prefix: PersistentSegTree 
*----------------------------------------------------------------*/

/*----------------------------------------------------------------*
    description:  
*----------------------------------------------------------------*/

//----------------------------------------------------------------
//  body:
template <class Node>
class PersistentSegmentTree {
   public:
    using TYPE = typename Node::TYPE;
    vector<Node*> versiones;
    vb hojas;
    int n;
    PersistentSegmentTree(vt<TYPE>& a) {
        n = a.size();
        hojas.pb(true);
        versiones.pb(build(a, 0, n - 1));
    }
 
    // ---------------------------------------------------------------
    Node query(int version, int i, int j) {  // [i, j]
        assert(0 <= i && i <= j && j < n && version < (int)versiones.sz);
        return query(versiones[version], i, j);
    }
 
    Node get(int version, int i) {  // [i, j]
        return query(version, i, i);
    }
    Node query(int i, int j) {  // [i, j]
        return query(versiones.sz - 1, i, j);
    }
 
    Node get(int i) {  // [i, j]
        return query(i, i);
    }
    // ---------------------------------------------------------------
 
    void update(int version, int i, int j, TYPE new_val) {
        assert(0 <= i && i <= j && j < n && version < (int)versiones.sz && hojas[version]);
        update(versiones[version], i, j, new_val);
    }
 
    void set(int version, int i, TYPE new_val) {
        update(version, i, i, new_val);
    }
 
    void update(int i, int j, TYPE new_val) {
        update(versiones.sz - 1, i, j, new_val);
    }
 
    void set(int i, TYPE new_val) {
        update(versiones.sz - 1, i, i, new_val);
    }
 
    //  ---------------------------------------------------------------
    int newVersion(int version) {
        versiones.pb(new Node(*versiones[version]));
        hojas[version] = false;
        hojas.pb(true);
        return versiones.sz - 1;
    }
 
   private:
    Node* build(vt<TYPE>& a, int tl, int tr) {
        if (tl == tr) return new Node(tl, tr, a[tl]);
        ll tm = (tl + tr) / 2;
        return new Node(tl, tr, build(a, tl, tm), build(a, tm + 1, tr));
    }
 
    void update(Node* v, int i, int j, TYPE val) {  // aca no hay que cambiar nada creo [i, j] el update
        if (v->l == i && v->r == j) {
            v->stackLazy(val);
            v->push();
            return;
        }
 
        v->push();
 
        int m = (v->l + v->r) / 2;
        if (j <= m) {
            update(v->leftChild, i, j, val);
            v->rightChild->push();
        } else if (i > m) {
            v->leftChild->push();
            update(v->rightChild, i, j, val);
        } else {
            update(v->leftChild, i, m, val);
            update(v->rightChild, m + 1, j, val);
        }
        v->merge();
    }
 
    Node query(Node* ran, int i, int j) {
        // en teoria no habria que tocar esta funcion
        ran->push();
        if (i == ran->l && ran->r == j) return *ran;
 
        int m = (ran->l + ran->r) / 2;
 
        if (j <= m) {
            return query(ran->leftChild, i, j);
        } else if (i > m) {
            return query(ran->rightChild, i, j);
        } else {
            Node izq = query(ran->leftChild, i, m);
            Node der = query(ran->rightChild, m + 1, j);
            return Node(izq.l, der.r, &izq, &der);
        }
    }
};