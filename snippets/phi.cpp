#include "/home/natanvek/0-COMPUTER/0-PROGRAMACION/8-COMPETENCIA/Template/macros.cpp"
//--------------------------------------

/*----------------------------------------------------------------*
    name: phi 
*----------------------------------------------------------------*/

/*----------------------------------------------------------------*
    prefix: phi 
*----------------------------------------------------------------*/

/*----------------------------------------------------------------*
    description: phi de euler para calcular cantidad coprima menor al numero 
*----------------------------------------------------------------*/

//----------------------------------------------------------------
//  body:
int phi(int n) {
    // description: phi de euler para
    // calcular cantidad coprima menor al numero 
    int result = n;
    for(int p = 2; p * p <= n; ++p){
        if (n % p == 0){
            while (n % p == 0) n /= p;
            result -= result / p;
        }
    }
    if (n > 1) result -= result / n;
    return result;
}

