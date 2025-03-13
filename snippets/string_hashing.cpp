#include "/home/natanvek/0-COMPUTER/0-PROGRAMACION/8-COMPETENCIA/Template/macros.cpp"
//-----------------------------



/*----------------------------------------------------------------*
    name: string_hashing 
*----------------------------------------------------------------*/

/*----------------------------------------------------------------*
    prefix: strHash 
*----------------------------------------------------------------*/

/*----------------------------------------------------------------*
    description: sirve para comparar strings en O(1) maneja las colisiones 
*----------------------------------------------------------------*/

//----------------------------------------------------------------
//  body:
struct RollingHash {
    static constexpr u64 mod = MOD;
    const mint base;
    vt<mint> power;

    static inline mint generate_base() { return randInt(0, MOD - 1); }

    inline void expand(size_t sz) {
        if (power.size() < sz + 1) {
            int pre_sz = (int)power.size();
            power.resize(sz + 1);
            forn(i, pre_sz - 1, sz) power[i + 1] = power[i] * base;
        }
    }

    explicit RollingHash(mint base = generate_base()) : base(base), power{1} {}

    template <typename STRING>
    vector<mint> build(const STRING& s) const {
        int sz = s.size();
        vector<mint> hashed(sz + 1, mint(0));
        for (int i = 0; i < sz; i++) {
            hashed[i + 1] = hashed[i] * base + s[i];
        }
        return hashed;
    }

    template <typename STRING>
    mint eval(STRING& s) {
        mint x = 0;
        for (auto& ch : s) x = base * x + ch;
        return x;
    }

    mint query(const vt<mint>& s, int l, int r) {
        assert(0 <= l && l <= r && r < len(s));
        expand(r - l);
        return (s[r] - s[l] * power[r - l]);
    }

    mint combine(mint h1, mint h2, int h2len) {
        expand(h2len);
        return h1 * power[h2len] + h2;
    }

    mint add_char(mint h, int x) { return h * base + mint(x); }

    int lcp(const vt<mint>& a, int l1, int r1, const vt<mint>& b, int l2, int r2) {
        int len = min(r1 - l1, r2 - l2);
        int low = 0, high = len + 1;
        while (high - low > 1) {
            int mid = (low + high) / 2;
            if (query(a, l1, l1 + mid) == query(b, l2, l2 + mid))
                low = mid;
            else
                high = mid;
        }
        return low;
    }
};

RollingHash strHash;

/*

    si quiero el hash de un char es mint(char)

    si quiero el hash de un string puedo hacer strHash.eval(string) o
    strHash.build(string) que retorna un vector de prefijos del string hasheados, que es bastante util

    si tengo un string y le quiero agregar un char es add_char(hash, char)

    si quiero concatenar strings es combine(hash1, hash2, largo_del_string_h2)


*/
