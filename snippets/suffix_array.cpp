#include "/home/natanvek/0-COMPUTER/0-PROGRAMACION/8-COMPETENCIA/Template/macros.cpp"
//--------------------------------------

/*----------------------------------------------------------------*
    name: suffix_array
*----------------------------------------------------------------*/

/*----------------------------------------------------------------*
    prefix: suffix
*----------------------------------------------------------------*/

/*----------------------------------------------------------------*
    description: es una funcion na un array de indices donde el i-esimo indice representa el inicio del suffix lexicograficamente iesimo, es decir si metieras todos los suffix en un array y los ordenas este te da los inicios de cada suffix ordenado. Ejemplo el array[0] es el suffix empezando en array[0] mas chico lexicograficamente
*----------------------------------------------------------------*/

//----------------------------------------------------------------
//  body:
struct suffix {
    int index; 
    int rank[2];
};
int cmp(suffix a, suffix b) {
    return (a.rank[0] == b.rank[0]) ? (a.rank[1] < b.rank[1] ? 1 : 0) : (a.rank[0] < b.rank[0] ? 1 : 0);
}
vector<int> buildSuffixArray(string& texto) {
    int n = texto.size();
    vector<suffix> suffixes(n);
    for (int i = 0; i < n; i++) {
        suffixes[i].index = i;
        suffixes[i].rank[0] = texto[i] - 'a';
        suffixes[i].rank[1] = ((i + 1) < n) ? (texto[i + 1] - 'a') : -1;
    }
    sort(suffixes.begin(), suffixes.end(), cmp);

    int ind[n];

    for (int k = 4; k < 2 * n; k = k * 2) {
        int rank = 0, prev_rank = suffixes[0].rank[0];
        suffixes[0].rank[0] = rank;
        ind[suffixes[0].index] = 0;

        for (int i = 1; i < n; i++) {
            if (suffixes[i].rank[0] == prev_rank &&
                suffixes[i].rank[1] == suffixes[i - 1].rank[1]) {
                prev_rank = suffixes[i].rank[0];
                suffixes[i].rank[0] = rank;
            } else {
                prev_rank = suffixes[i].rank[0];
                suffixes[i].rank[0] = ++rank;
            }
            ind[suffixes[i].index] = i;
        }

        for (int i = 0; i < n; i++) {
            int nextindex = suffixes[i].index + k / 2;
            suffixes[i].rank[1] = (nextindex < n) ? suffixes[ind[nextindex]].rank[0] : -1;
        }

        sort(suffixes.begin(), suffixes.end(), cmp);
    }

    vector<int> suffixArr(n);
    for (int i = 0; i < n; i++) suffixArr[i] = suffixes[i].index;

    return suffixArr;
}
