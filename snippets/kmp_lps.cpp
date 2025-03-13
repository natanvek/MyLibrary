#include "/home/natanvek/0-COMPUTER/0-PROGRAMACION/8-COMPETENCIA/Template/macros.cpp"
//--------------------------------------


/*----------------------------------------------------------------*
    name: kmp_lps 
*----------------------------------------------------------------*/

/*----------------------------------------------------------------*
    prefix: kmp 
*----------------------------------------------------------------*/

/*----------------------------------------------------------------*
    description: lps es un algoritmo para calcular longest prefix-suffix en todos los prefijos del string 
*----------------------------------------------------------------*/

//----------------------------------------------------------------
//  body:
vector<int> calclps(const string& pattern) {
    // longest prefix que tambien es suffix ABCXXXABC
    // retorna un vector donde en cada posicion tenes el tamaño del maximo pre-suf de 0..i
    int m = pattern.length();
    vector<int> lps(m, 0);
    int len = 0;
    
    for (int i = 1; i < m; i++) {
        while (len > 0 && pattern[i] != pattern[len]) len = lps[len - 1];
        if (pattern[i] == pattern[len]) lps[i] = ++len;
    }
    
    return lps;
}

int kmp(const string& text, const string& pattern) {
    // en O(n + m) encuentra dado un string todas las posiciones en las que aparece en el text
    vector<int> lps = calclps(pattern);
    int n = text.length(), m = pattern.length(), j = 0, rta = 0;
    for (int i = 0; i < n; i++) {
        while (j > 0 && text[i] != pattern[j]) j = lps[j - 1];
        if (text[i] == pattern[j] && ++j == m) {
            // encontre un match en la posicion i - m + 1 
            ++rta;
            j = lps[j - 1];
        }
    }
    return rta;
}


