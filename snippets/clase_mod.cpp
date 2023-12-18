#include "/home/natanvek/0-COMPUTER/0-PROGRAMACION/8-COMPETENCIA/Template/macros.cpp"
//--------------------------------------


/*----------------------------------------------------------------*
    name: clase_mod 
*----------------------------------------------------------------*/

/*----------------------------------------------------------------*
    prefix: clase_mod 
*----------------------------------------------------------------*/

/*----------------------------------------------------------------*
    description: genere un tipo de datos y todas las overloaddistintas operaciones aritmeticas para trabajar con congruencias con 'sintaxis sugar' 
*----------------------------------------------------------------*/

//----------------------------------------------------------------
//  body:
struct mod {
    int x;
    mod(int val) : x(val) {}
    operator int() const {
        return x;
    }

    mod operator*(const int& other) const {
        return x * 1ll * other % MOD;
    }

    friend mod operator*(const int& ent, const mod& modulo) {
        return modulo * ent;
    }

    void operator*=(const int& other) {
        x = x * 1ll * other % MOD;
    }

    friend void operator*=(int& ent, const mod& modulo) {
        ent = ent * modulo;
    }


    mod operator/(const int& other) const {
        return x * mod(other).inv();
    }

    friend mod operator/(const int& ent, const mod& modulo) {
        return ent / modulo;
    }

    friend void operator/=(int& ent, const mod& modulo) {
        ent = ent / modulo;
    }
    
    void operator/=(const int& other) {
        x *= mod(other).inv();
    }


    mod operator+(const int& other) const {
        return ((x + other) % MOD + MOD) % MOD;
    }

    friend mod operator+(const int& ent, const mod& modulo) {
        return modulo + ent;
    }

    
    void operator+=(const int& other) {
        x = ((x + other) % MOD + MOD) % MOD;
    }

    friend void operator+=(int& ent, const mod& modulo) {
        ent = ent + modulo;
    }

    mod operator-(const int& other) const {
        return ((x - other) % MOD + MOD) % MOD;
    }

    friend mod operator-(const int& ent, const mod& modulo) {
        return ent - modulo;
    }

    void operator-=(const int& other) {
        x = ((x - other) % MOD + MOD) % MOD;
    }

    friend void operator-=(int& ent, const mod& modulo) {
        ent = ent - modulo;
    }

    mod operator^(int k) const {
        mod res = 1, y = x % MOD;
        while (k) {
            if (k & 1) res *= y;
            y *= y;
            k >>= 1;
        }
        return res;
    }
    friend mod operator^(const int& ent, const mod& modulo) {
        return ((mod) ent) ^ ((int) modulo);
    }

    void operator^=(int k) {
        x = (mod) x ^ k;
    }

    mod inv() const {
        mod res = (mod) x ^ (MOD - 2);
        return res; 
    }

};

const int MOD = 998244353;