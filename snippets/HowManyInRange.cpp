#include "/home/natanvek/0-COMPUTER/0-PROGRAMACION/8-COMPETENCIA/Template/macros.cpp"
//--------------------------------------


/*----------------------------------------------------------------*
    name: HowManyInRange 
*----------------------------------------------------------------*/

/*----------------------------------------------------------------*
    prefix: HowManyInRange 
*----------------------------------------------------------------*/

/*----------------------------------------------------------------*
    description: Es una estructura de datos basada en SegTree que resuelve queries de la siguiente forma, dados (l, r, mn, mx) te dice cuantos elementos dentro del rango del vector v[l],..,v[r-1] son mayores a mn y menores a mx o sea estan en el rango [mn, mx), tener en cuenta que es particularmente ineficiente esta estructura 
*----------------------------------------------------------------*/

//----------------------------------------------------------------
//  body:
struct HowManyInRangeTree {
    int n;
    vector<vector<ll>> tree;
 
    void build(vector<ll> &a, int x, int l, int r) {
        if (l + 1 == r) {
            tree[x] = {a[l]};
            return;
        }
 
        int m = (l + r) / 2;
        build(a, 2 * x + 1, l, m);
        build(a, 2 * x + 2, m, r);
        merge(all(tree[2 * x + 1]), all(tree[2 * x + 2]), back_inserter(tree[x]));
    }
 
    HowManyInRangeTree(vector<ll>& a) : n(a.size()) {
        int SIZE = 1 << (__lg(n) + bool(__builtin_popcount(n) - 1));
        tree.resize(2 * SIZE - 1);
        build(a, 0, 0, n);
    }
 
    int count(int lq, int rq, ll mn, ll mx, int x, int l, int r) {
        if (rq <= l || r <= lq) return 0;
        if (lq <= l && r <= rq) return lower_bound(all(tree[x]), mx) - lower_bound(all(tree[x]), mn);
 
        int m = (l + r) / 2;
        int a = count(lq, rq, mn, mx, 2 * x + 1, l, m);
        int b = count(lq, rq, mn, mx, 2 * x + 2, m, r);
        return a + b;
    }
 
    int count(int lq, int rq, ll mn, ll mx) { // [lq, rq) && [mn, mx)
        return count(lq, rq, mn, mx, 0, 0, n);
    }
};