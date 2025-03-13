#include "/home/natanvek/0-COMPUTER/0-PROGRAMACION/8-COMPETENCIA/Template/macros.cpp"
//-----------------------------



/*----------------------------------------------------------------*
    name: criba 
*----------------------------------------------------------------*/

/*----------------------------------------------------------------*
    prefix: criba 
*----------------------------------------------------------------*/

/*----------------------------------------------------------------*
    description: criba de Eratosthenes para calcular el menor primo de cada numero y poder factorizar rapidamente 
*----------------------------------------------------------------*/

//----------------------------------------------------------------
//  body:
const int MX = 1e6 + 100; 
vi primes;
vi primeFacts[MX]; // 1 por primo, borrar esta linea 
int mndivp[MX];
void criba() {
    memset(mndivp, 0, sizeof(mndivp));
    forn(i, 2, MX)
        if (mndivp[i] == 0) {
            mndivp[i] = i;
            primes.pb(i);
            forn(j, i, MX, i) primeFacts[j].pb(i); // borrar esto si no se necesita

            forn(j, i*i, MX, i) 
                if(mndivp[j] == 0) mndivp[j] = i;                
        }
} 
// acordate te ponerlo en el main y no en el solve