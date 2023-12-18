#include "/home/natanvek/0-COMPUTER/0-PROGRAMACION/8-COMPETENCIA/Template/macros.cpp"
//--------------------------------------

/*----------------------------------------------------------------*
    name: MaspySegmentTree
*----------------------------------------------------------------*/

/*----------------------------------------------------------------*
    prefix: MaspySegTree
*----------------------------------------------------------------*/

/*----------------------------------------------------------------*
    description: Estrategia para calcular en logn una funcion sobre un segmento de un vector
*----------------------------------------------------------------*/

//----------------------------------------------------------------
//  body:
template <class Monoid>
struct SegTree {
    using MX = Monoid;
    using X = typename MX::value_type;
    using value_type = X;
    vt<X> dat;
    int n, log, size;

    SegTree() {}
    SegTree(int n) { build(n); }
    template <typename F>
    SegTree(int n, F f) {
        build(n, f);
    }
    SegTree(const vt<X>& v) { build(v); }

    void build(int m) {
        build(m, [](int i) -> X { return MX::unit(); });
    }
    void build(const vt<X>& v) {
        build(v.size(), [&](int i) -> X { return v[i]; });
    }
    template <typename F>
    void build(int m, F f) {
        n = m, log = 1;
        while ((1 << log) < n) ++log;
        size = 1 << log;
        dat.assign(size << 1, MX::unit());
        forn(i, 0, n) dat[size + i] = f(i);
        forr(i, size - 1, 1) update(i);
    }

    X get(int i) { return dat[size + i]; }
    vt<X> get_all() { return {dat.begin() + size, dat.begin() + size + n}; }

    void update(int i) { dat[i] = Monoid::op(dat[2 * i], dat[2 * i + 1]); }
    void set(int i, const X& x) {
        assert(i < n);
        dat[i += size] = x;
        while (i >>= 1) update(i);
    }

    void multiply(int i, const X& x) {
        assert(i < n);
        i += size;
        dat[i] = Monoid::op(dat[i], x);
        while (i >>= 1) update(i);
    }

    X query(int L, int R) {
        assert(0 <= L && L <= R && R <= n);
        X vl = Monoid::unit(), vr = Monoid::unit();
        L += size, R += size;
        while (L < R) {
            if (L & 1) vl = Monoid::op(vl, dat[L++]);
            if (R & 1) vr = Monoid::op(dat[--R], vr);
            L >>= 1, R >>= 1;
        }
        return Monoid::op(vl, vr);
    }

    X query_all() { return dat[1]; }

    // dado una funcion booleana check y un L chequea cual es el maximo R que cumple check(query(L, Rmax))
    template <class F>
    int max_right(F check, int L) {
        assert(0 <= L && L <= n && check(Monoid::unit()));
        if (L == n) return n;
        L += size;
        X sm = Monoid::unit();
        do {
            while (L % 2 == 0) L >>= 1;
            if (!check(Monoid::op(sm, dat[L]))) {
                while (L < size) {
                    L = 2 * L;
                    if (check(Monoid::op(sm, dat[L]))) {
                        sm = Monoid::op(sm, dat[L++]);
                    }
                }
                return L - size;
            }
            sm = Monoid::op(sm, dat[L++]);
        } while ((L & -L) != L);
        return n;
    }

    // dado una funcion booleana check y un R chequea cual es el minimo L que cumple check(query(Lmin, R))
    template <class F>
    int min_left(F check, int R) {
        assert(0 <= R && R <= n && check(Monoid::unit()));
        if (R == 0) return 0;
        R += size;
        X sm = Monoid::unit();
        do {
            --R;
            while (R > 1 && (R % 2)) R >>= 1;
            if (!check(Monoid::op(dat[R], sm))) {
                while (R < size) {
                    R = 2 * R + 1;
                    if (check(Monoid::op(dat[R], sm))) {
                        sm = Monoid::op(dat[R--], sm);
                    }
                }
                return R + 1 - size;
            }
            sm = Monoid::op(dat[R], sm);
        } while ((R & -R) != R);
        return 0;
    }

    // query_{l<=i<r} A[i xor x]
    X xor_query(int l, int r, int xor_val) {
        static_assert(Monoid::commute);
        X x = Monoid::unit();
        for (int k = 0; k < log + 1; ++k) {
            if (l >= r) break;
            if (l & 1) {
                x = Monoid::op(x, dat[(size >> k) + ((l++) ^ xor_val)]);
            }
            if (r & 1) {
                x = Monoid::op(x, dat[(size >> k) + ((--r) ^ xor_val)]);
            }
            l /= 2, r /= 2, xor_val /= 2;
        }
        return x;
    }
};

struct Mono {
    using value_type = aar(ll, 2, 2);
    using X = value_type;
    static X op(X x, X y) {
        if (x[1][1] == infll) return y;
        if (y[1][1] == infll) return x;
        X z;
        forn(i, 0, 2) forn(j, 0, 2) z[i][j] = infll;
        forn(i, 0, 2) forn(j, 0, 2) {
            mineq(z[i][j], x[i][0] + y[1][j]); 
            mineq(z[i][j], x[i][1] + y[1][j]); 
            mineq(z[i][j], x[i][1] + y[0][j]); 
        }
        return z;
    }
    static X unit() {
        X x;
        x[0][0] = infll;
        x[0][1] = infll;
        x[1][0] = infll;
        x[1][1] = infll;
        return x;
    }
    static constexpr bool commute = 0;
};

template <typename X>
struct Monoid_Add {
    using value_type = X;
    static constexpr X op(const X &x, const X &y) noexcept { return x + y; }
    static constexpr X inverse(const X &x) noexcept { return -x; }
    static constexpr X power(const X &x, ll n) noexcept { return X(n) * x; }
    static constexpr X unit() { return X(0); }
    static constexpr bool commute = true;
};