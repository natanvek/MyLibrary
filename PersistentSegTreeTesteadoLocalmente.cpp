#include <bits/stdc++.h>
using namespace std;
//--------------- MACROS ---------------
// clang-format off
#ifdef LOCAL
    #define exeLOCAL(...) { __VA_ARGS__; }
#else
    #define exeLOCAL(...)  // do nothing
#endif
#define debug(x) lput(#x, '=', x)
#define RAYA lput("------------------------")
using u64 = unsigned long long; using u32 = unsigned int; using uint = unsigned int;using ll = long long;using ld = long double;using pii = pair<int, int>;using pll = pair<ll, ll>;using vi = vector<int>;using vvi = vector<vector<int>>;using vvvi = vector<vector<vector<int>>>;using vll = vector<ll>;using vvll = vector<vector<ll>>;using vvvll = vector<vector<vector<ll>>>;using vb = vector<bool>;using vvb = vector<vector<bool>>;using vvvb = vector<vector<vector<bool>>>;using vpii = vector<pii>;using vvpii = vector<vector<pii>>;using vvvpii = vector<vector<vector<pii>>>;using vpll = vector<pll>;using vvpll = vector<vector<pll>>;using vvvpll = vector<vector<vector<pll>>>;template <typename T> using vt = vector<T>;template <typename T> using vvt = vector<vector<T>>;template <typename T> using vvvt =  vector<vector<vector<T>>>; template <class T> using pqmax = priority_queue<T>; template <class T> using pqmin = priority_queue<T, vector<T>, greater<T>>;using sti = set<int>; using stll = set<ll>;
#define vv(T, name, h, ...) vvt<T> name(h, vt<T>(__VA_ARGS__))
#define vvv(T, name, h, w, ...) vvvt<T> name(h, vvt<T>(w, vt<T>(__VA_ARGS__)))
#define ar(T, n) array<T, n>
#define aar(T, n, m) array<array<T, m>, n>
#define aaar(T, n, m, l) array<array<array<T, l>, m>, n>
int topbit(int x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }; int topbit(u32 x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); };int topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); };int topbit(u64 x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }
int popcnt(int x) { return __builtin_popcount(x); }; int popcnt(u32 x) { return __builtin_popcount(x); }; int popcnt(ll x) { return __builtin_popcountll(x); }; int popcnt(u64 x) { return __builtin_popcountll(x); };
int lowbit(int x) { return (x == 0 ? -1 : __builtin_ctz(x)); };int lowbit(u32 x) { return (x == 0 ? -1 : __builtin_ctz(x)); };int lowbit(ll x) { return (x == 0 ? -1 : __builtin_ctzll(x)); };int lowbit(u64 x) { return (x == 0 ? -1 : __builtin_ctzll(x)); };
template <typename T> std::istream& operator>>(std::istream& is, std::vector<T>& vec) {for (auto& elem : vec) {is >> elem;};return is;};template <typename T1, typename T2>std::istream& operator>>(std::istream& is, std::pair<T1, T2>& p) {is >> p.first >> p.second;return is;};
template <typename T> ostream& operator<<(ostream& os, const set<T>& vec) {for (const T& elem : vec) os << elem << " ";return os;};template <typename T1, typename T2> ostream& operator<<(ostream& os, const pair<T1, T2>& p) {return os << p.first << " " << p.second;};template <typename T> ostream& operator<<(ostream& os, const vector<T>& vec) {for (const T& elem : vec) os << elem << " ";return os;};
void put() { cout << endl;};void pute() {};template <typename T, typename... TAIL>void pute(const T& t, TAIL... tail) {cout << t << ' ';pute(tail...);};template <typename... ARGS>void put(ARGS... args) {pute(args...); put();};void putb(bool b) { put((b) ? "YES" : "NO"); };void lput() { cerr << endl; };template <typename T, typename... TAIL>void lput(const T& t, TAIL... tail) {  cerr << t << ' ';  lput(tail...);};
void cinall() {};template <class H, class... T>void cinall(H &h, T &... t) { cin >> h;cinall(t...);};
#define rd(...) __VA_ARGS__; cinall(__VA_ARGS__)
#define pb push_back
#define ppb pop_back
#define sz size()
#define whilen(i,a,callback) for (ll i = (a); (b); callback) 
#define intwh(i,a,callback) ll i = (a); for (; (b); callback) 
#define forv(i,v) for (ll i = 0ll; i < (ll)v.sz; ++i) 
#define forvi(i, e, v) forv(i, v) if(auto& e = v[i]; true)
#define forn(i,a,n) for (ll i = (a); i < (n); ++i) 
#define fori(i,a,n) for (ll i = (a); i <= (n); ++i) 
#define forc(i,a,n,c) for (ll i = (a); i < (n); ++i)  if(c)
#define forb(i,a,n,b) for (ll i = (a); i < (n) && (b); ++i) 
#define fors(i,a,n,s) for (ll i = (a); i < (n); i+=(s)) 
#define forr(i,n,a) for (ll i = (n); i >= (a); --i) 
#define infi (ll)INT32_MAX
#define infll (ll)3e18
#define all(v) v.begin(), v.end()
#define revv(x) reverse(all(x))
#define sortv(v) sort(all(v))
#define sortvc(v, comp) sort(all(v), comp)
#define lowbpos(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define uppbpos(c, x) distance((c).begin(), upper_bound(all(c), (x)))
#define break(b,...) if(b){__VA_ARGS__; break;}
#define continue(b,...) if(b){__VA_ARGS__; continue;}
#define ret(b,...) if(b){__VA_ARGS__; return;}
#define retx(b,x,...) if(b){__VA_ARGS__; return x;}
#define filterv(v,...) v.erase(remove_if(all(v), [&](auto& x){return (__VA_ARGS__);}), v.end())
#define filterc(v,newv,...) auto newv = v; filterv(newv, (__VA_ARGS__))
#define applyv(v,...) forv(i, v) {auto& x = v[i]; x = (__VA_ARGS__);}
#define applyc(v,newv,...) auto newv = v; applyv(newv, (__VA_ARGS__))
template <typename T> bool mineq(T& a, T b) {return (a > b ? a = b, true : false);}; template <typename T> bool maxeq(T& a, T b) {return (a < b ? a = b, true : false);};template <typename T> bool even(T x) {return (x % 2) == 0;};template <typename T> T lowb(vt<T>& v, T x, T mx) { auto it = lower_bound(all(v), (x)); if(it == v.end()) return mx; else return *it;};template <typename T> T llowb(vt<T>& v, T x, T mn) { if(v.sz == 0) {return mn;} int pos = lowbpos(v, x); if(pos == 0) {return mn;} return v[pos-1];};template <typename T> T uppb(vt<T>& v, T x, T mx) { auto it = upper_bound(all(v), (x)); if(it == v.end()) return mx; else return *it;};template <typename T> T minv(vt<T>& v, int desde = 0, int hasta = infi) {assert(hasta == infi || hasta <= (int)v.sz);mineq(hasta, (int)v.sz); assert(desde < hasta);return *min_element(v.begin() + desde, v.begin() + hasta);};template <typename T> T maxv(vt<T>& v, int desde = 0, int hasta = infi) {assert(hasta == infi || hasta <= (int)v.sz);mineq(hasta, (int)v.sz); assert(desde < hasta);return *max_element(v.begin() + desde, v.begin() + hasta);};template <typename T> T  sumv(vt<T>& v, int desde = 0, int hasta = infi) {assert(hasta == infi || hasta <= (int)v.sz);mineq(hasta, (int)v.sz) ; if(desde >= hasta) {return 0ll;}; return accumulate(v.begin() + desde, v.begin() + hasta, 0LL);}; int ceil(int a, int b) {return a / b + (a % b > 0);};ll ceil(ll a, ll b) {return a / b + (a % b > 0);}; template<typename T> T max(T& arg) {return arg;} template<typename T, typename... Args> T max(T arg, Args... args) {return max(arg, max(args...));} template<typename T> T min(T arg) {return arg;} template<typename T, typename... Args> T min(T arg, Args... args) {return min(arg, min(args...));};
template <typename T> bool eraseOne(multiset<T>& m, T k) { auto it = m.find(k); if(it == m.end()) {return false; } m.erase(it); return true; }
// clang-format on
//--------------------------------------


template <class T>
struct NodeBase {
    using TYPE = T;
    int l, r; 
    NodeBase *leftChild, *rightChild, *padre;
    
    bool lazyDesactualizado = false;
    
    // estas variables parece que hay que iniciarlas aca no supe bajarlas a SumNode aunque me gustaria
    TYPE lazy, sum;

    NodeBase(int _l, int _r) : l(_l), r(_r) {};

    NodeBase(int _l, int _r, NodeBase *left, NodeBase *right) : leftChild(left), rightChild(right), l(_l), r(_r) {
        leftChild->padre = this; rightChild->padre = this;
    }

    void push() {
        if (l != r) {
            if(leftChild->padre != this) {
                leftChild = leftChild->clone();
                leftChild->padre = this;
            }

            if(rightChild->padre != this) {
                rightChild = rightChild->clone();
                rightChild->padre = this;
            }
        }

        ret(!lazyDesactualizado);

        if (l != r) {
            leftChild->stackLazy(lazy);
            rightChild->stackLazy(lazy);
        }

        applyLazy();
    }
    
 
    virtual NodeBase* clone() const = 0;
    virtual void merge()= 0;
    virtual void applyLazy()= 0;
    virtual void stackLazy(TYPE val) = 0;
};

template <class T>
struct SumNode : public NodeBase<T> {
    using NodeBase<T>::NodeBase;
    using TYPE = typename NodeBase<T>::TYPE;
    
    // 
    // inicializamos el nodo hoja
    SumNode(int _l, int _r, TYPE val) : NodeBase<T>(_l, _r) {
        this->sum = val;
        this->lazy = 0;
    }

    void merge() override {
        this->sum = this->leftChild->sum + this->rightChild->sum;
    }

    void stackLazy(typename NodeBase<T>::TYPE val) override {
        this->lazyDesactualizado = true;
        this->lazy += val;
    } 

    void applyLazy() {
        this->sum += this->lazy * (this->r - this->l + 1);
        this->lazy = 0;
        this->lazyDesactualizado = false;
    } 

    // codigo repetido que no supe eliminar tiene que estar en cada clase hija
    NodeBase<T>* clone() const override { return new SumNode(*this); }
    SumNode(int _l, int _r, SumNode *left, SumNode *right) : NodeBase<T>(_l, _r, left, right) { merge(); this->lazy = 0;}
};
 
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
 
    void update(int version, int i, int j, TYPE val) {
        assert(0 <= i && i <= j && j < n && version < (int)versiones.sz);
        update(versiones[version], i, j, val);
    }
 
    void set(int version, int i, TYPE val) {
        update(version, i, i, val);
    }
 
    void update(int i, int j, TYPE val) {
        update(versiones.sz - 1, i, j, val);
    }
 
    void set(int i, TYPE val) {
        update(versiones.sz - 1, i, i, val);
    }
 
    //  ---------------------------------------------------------------
    int newVersion(int version) {
        versiones[version] = new Node(*versiones[version]);
        versiones.pb(new Node(*versiones[version]));
        return versiones.sz - 1;
    }
 
   private:
    Node* build(vt<TYPE>& a, int tl, int tr) {
        if (tl == tr) return new Node(tl, tr, a[tl]);
        int tm = (tl + tr) / 2;

        return new Node(tl, tr, build(a, tl, tm), build(a, tm + 1, tr));
    }
 
    // aca no hay que cambiar nada creo [i, j] el update
    void update(Node* v, int i, int j, TYPE val) {  
        ret((i <= v->l && v->r <= j), v->stackLazy(val); v->push());

        v->push();
        if(v->r < i || j < v->l) return;

        update((Node*)v->leftChild, i, j, val);
        update((Node*)v->rightChild, i, j, val);
        v->merge();
    }

    // en teoria no habria que tocar esta funcion
    Node query(Node* v, int i, int j) {
        v->push();
        if (i == v->l && v->r == j) return *v;
 
        int m = (v->l + v->r) / 2;
 
        if (j <= m) {
            return query((Node*)v->leftChild, i, j);
        } else if (i > m) {
            return query((Node*)v->rightChild, i, j);
        } else {
            Node izq = query((Node*)v->leftChild, i, m); 
            Node der = query((Node*)v->rightChild, m + 1, j); 
            return Node(izq.l, der.r, &izq, &der);
        }
    }

};

void solve() {
    const int N = 10000;

    int TANDAS = 5;
    int MODIFICACIONES = 2e4;
    int NUEVASVERSIONES = 1e5;
    int QUERYS = 1e5;

    QUERYS = ceil(QUERYS, TANDAS);
    NUEVASVERSIONES = ceil(NUEVASVERSIONES, TANDAS);
    MODIFICACIONES = ceil(MODIFICACIONES, TANDAS);

    //-------
    vll inicio(N);
    forn(i, 0, N) inicio[i] = rand() % 100;

    PersistentSegmentTree<SumNode<ll>> st(inicio);

    vvll v = {inicio};

    int versiones = 1;

    vi hojas = {0};
    vi pos = {0};

    forn(tanda, 0, TANDAS) {
        forn(creoVersion, 0, NUEVASVERSIONES) {
            int padre = rand() % versiones;
            ++versiones;

            int hijo = st.newVersion(padre);
            v.pb(v[padre]);
        }

        forn(modificacion, 0, MODIFICACIONES) {
            int version = rand() % versiones;
            int izq = rand() % N, der = rand() % N;
            if(izq > der) swap(izq, der);

            ll agrego = (rand() % 100 - 50);
            fori(i, izq, der) v[version][i] += agrego;
            st.update(version, izq, der, agrego);
        }

        forn(query, 0, QUERYS) {
            int version = rand() % versiones;
            int izq = rand() % N, der = rand() % N;
            if(izq > der) swap(izq, der);

            ll expected = sumv(v[version], izq, der+1);

            ll found = st.query(version, izq, der).sum;

            assert(expected == found);
            if(query % 5000 == 0) put(query / 5000, "-->", "sigo corriendo");

        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // exeLOCAL(freopen("input.in", "r", stdin));

    int T;
    T = 1;
    forn(Caso, 0, T) {
        debug(Caso);
        solve();
        RAYA;
    }
}
