#include "/home/natanvek/0-COMPUTER/0-PROGRAMACION/8-COMPETENCIA/Template/macros.cpp"
//--------------------------------------

/*----------------------------------------------------------------*
    name: gcd 
*----------------------------------------------------------------*/

/*----------------------------------------------------------------*
    prefix: gcd 
*----------------------------------------------------------------*/

/*----------------------------------------------------------------*
    description: greates common divisor 
*----------------------------------------------------------------*/

//----------------------------------------------------------------
//  body:
int gcd(int a, int b){
    if(a==0) return b;
    return gcd(b%a, a);
}
