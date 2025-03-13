#include "/home/natanvek/0-COMPUTER/0-PROGRAMACION/8-COMPETENCIA/Template/macros.cpp"
//-----------------------------



/*----------------------------------------------------------------*
    name: Treap 
*----------------------------------------------------------------*/

/*----------------------------------------------------------------*
    prefix: Treap 
*----------------------------------------------------------------*/

/*----------------------------------------------------------------*
    description: Treap es una estructura de datos al estilo de AVL pero con balanceo randomizado que sirve para editar en el medio y hacer queries de rango en O(log) 
*----------------------------------------------------------------*/

//----------------------------------------------------------------
//  body:

template <typename T>
struct Treap;

template <typename T>
using pTreap = Treap<T>*;

template <typename T>
struct Treap {
   public:
    int priority;
    int sz = 0;
    pTreap<T> l, r;
    static pTreap<T> nullNode;
    T root;
    Treap() {};
    Treap(T _root) {
        sz = 1;
        root = _root;
        l = getNullNode();
        r = getNullNode();
        priority = rand();
    }

    static pTreap<T> getNullNode() {
        static pTreap<T> nullNode = new Treap<T>();
        return nullNode;
    }

    bool empty() { return sz == 0; }

    void recalc() {  // resetear el root y recalcular sus propiedades HAY que tocar
        if (empty()) return;
        sz = 1 + l->size() + r->size();
        root.recalc(l, r);
    }

    void prop() {
        if (empty()) return;
        root.prop(l, r);
        recalc();
    }

    vt<decltype(T::val)> vectorize() {
        if (empty()) return {};
        vt<decltype(T::val)> rta;
        vt<pair<pTreap<T>, int>> stack = {{this, 1}};

        while (len(stack)) {
            auto [v, cnt] = stack.back();
            v->prop();
            if (cnt == 1) {
                stack.back().second++;
                if (!v->l->empty()) stack.pb({v->l, 1});
            } else {
                stack.pop_back();
                rta.pb(v->root.val);
                if (!v->r->empty()) stack.pb({v->r, 1});
            }
        }
        return rta;
    }

    int size() {
        return sz;
    }
};


template <typename T>
pTreap<T> meld(pTreap<T> t1, pTreap<T> t2) {  // NO hay que tocarlo
    if (t1->empty()) return t2;
    if (t2->empty()) return t1;
    t1->prop();
    t2->prop();
    if (t1->priority < t2->priority) {
        t1->r = meld(t1->r, t2);
        t1->recalc();
        return t1;
    } else {
        t2->l = meld(t1, t2->l);
        t2->recalc();
        return t2;
    }
}

template <typename T, typename... Args>
pTreap<T> meld(pTreap<T> first, Args... rest) {
    if constexpr (sizeof...(rest) == 1)
        return meld(first, rest...);
    else
        return meld(first, meld(rest...));
}


/// @brief
/// @param me puntero al Treap que hay que splittear
/// @param nInLeft cantidad de elementos que querés que queden en el root izquierdo
/// @return un array de 2 Treaps rta[0] contiene los nInLeft menores y rta[1] el resto
template <typename T>
array<pTreap<T>, 2> split(pTreap<T>& me, int nInLeft) {  // NO hay que tocarlo
    if (me->empty()) return {Treap<T>::getNullNode(), Treap<T>::getNullNode()};
    me->prop();
    if (me->l->size() >= nInLeft) {
        array<pTreap<T>, 2> leftRes = split(me->l, nInLeft);
        me->l = leftRes[1];
        me->recalc();
        return {leftRes[0], me};
    } else {
        nInLeft = nInLeft - me->l->size() - 1;
        array<pTreap<T>, 2> rightRes = split(me->r, nInLeft);
        me->r = rightRes[0];
        me->recalc();
        return {me, rightRes[1]};
    }
}

template <typename T, typename... Positions>
auto split(pTreap<T>& me, Positions... pos) {  // [l, r) para cada pos;
    std::array<pTreap<T>, sizeof...(Positions) + 1> rta;
    int idx = 0;
    int suma = 0;
    auto split_one = [&](pTreap<T> treap, int pos) {
        array<pTreap<T>, 2> arr = split(treap, pos - suma);
        suma += pos;
        rta[idx++] = arr[0];
        return arr[1];
    };

    ((me = split_one(me, pos)), ...);

    rta[idx] = me;

    return rta;
}

struct treapVal {  // debe si o si tener val, recalc, prop y los incializadores
    bool esNulo;
    
    bool val;

    // mint sum = 0;
    treapVal(decltype(val) _val) : val(_val) {
        esNulo = false;
    }

    treapVal() {}
    void prop(pTreap<treapVal>& l, pTreap<treapVal>& r) {
        if (esNulo) return;
    }

    void recalc(pTreap<treapVal>& l, pTreap<treapVal>& r) {
        if (esNulo) return;
    }
};

using TreapT = Treap<treapVal>;
using pTreapT = pTreap<treapVal>;