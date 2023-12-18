#include "/home/natanvek/0-COMPUTER/0-PROGRAMACION/8-COMPETENCIA/Template/macros.cpp"
//--------------------------------------

/*----------------------------------------------------------------*
    name: ternary 
*----------------------------------------------------------------*/

/*----------------------------------------------------------------*
    prefix: ternary 
*----------------------------------------------------------------*/

/*----------------------------------------------------------------*
    description: ternary search para vectores o funciones con distribucion cuadratica 
*----------------------------------------------------------------*/

//----------------------------------------------------------------
//  body:
ll busco; cin >> busco;
ll ii = -infi, jj = infi;
while (ii + 2 < jj) {
    ll kk1 = ii + (jj - ii) / 3;
    ll kk2 = jj - (jj - ii) / 3;

    if (busco < kk1) {
        jj = kk1;
    } else if (busco > kk2) {
        ii = kk2 + 1;
    } else {
        ii = kk1;
        jj = kk2+1;
    }
}
// ii o ii+1 tienen la respuesta