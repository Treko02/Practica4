#include <iostream>
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

using namespace std;

//PRACTICA4 PARTE 2


// Ejercicio 1. FunciÃ³n recursiva que calcule longitud de cadena de caractÃ©res
/*
{Pre: }
{Post: }
*/


int auxlong(char cadena[], int p) {
    if('\0'==cadena[p]){
        return p;
    }else {
        p= auxlong(cadena, p+1);
        return p;
    }



}
int longitud(char cadena[]){
    int longi=0;
    if ('\0' == cadena[longi]){
        return longi;
    }else{

        return longi=auxlong(cadena, longi);
    }
}


// Ejercicio 2. FunciÃ³n recursiva que dada una cadena de caracteres sin espacios en blanco,
// devuelve verdad si dicha cadena contiene la letra â€˜Aâ€™ y falso en caso contrario.
/*
{Pre: }
{Post: }
*/

bool aux1(char cadena[], int n){
    bool exA=false;
    if(n<= longitud(cadena)) {
        if (cadena[n] == 'A') {
            exA=true;
            return exA;
        } else {
            aux1(cadena, n+1);
        }
    }
    else{
        return exA;
    }
}
bool contieneLaA(char cadena[]){
    bool esA= false;
    if (longitud(cadena)==0){
        return esA;
    }
    else{
        esA=aux1(cadena, 0);
        return esA;

    }
}

// Ejercicio 3. FunciÃ³n recursiva que dada una cadena de caracteres sin espacios
// en blanco, devuelve verdad si dicha cadena es un palÃ­ndromo y falso en caso contrario.
/*
{Pre: }
{Post:b jbbu}
*/
bool aux2(char cadena[], int p, int x) {
    bool pal= true;
    if (cadena[p]!=cadena[x]){
        pal= false;
        return pal;
    }else if (p>=x){
        return pal;
    }else{
        return aux2(cadena,p+1, x-1);
    }
}
bool palindromo(char cadena[]){
    int pali=0, ult= longitud(cadena);
    if (longitud(cadena)==0){
        return true;
    }else{
        return aux2(cadena, pali, ult-1
        );
    }
}


// Casos de prueba
TEST_CASE( "Calculando longitudes", "[longitud]" ) {
    REQUIRE( longitud((char *)"Hola") == 4 );
    REQUIRE( longitud((char *)"Adios") == 5 );
    REQUIRE( longitud((char *)"") == 0 );
}

TEST_CASE( "Comprobando si cadenas contienen la letra A", "[contieneLaA]" ) {

    REQUIRE( contieneLaA((char *)"Pepa") == false );
    REQUIRE( contieneLaA((char *)"PEPA") == true );
    REQUIRE( contieneLaA((char *)"") == false );
    REQUIRE( contieneLaA((char *)"Pepe") == false );
    REQUIRE( contieneLaA((char *)"ABCDE") == true );
    REQUIRE( contieneLaA((char *)"BCADC") == true );
}

TEST_CASE( "Comprobando palindromos", "[palindromos]" ) {
    REQUIRE( palindromo((char *)"abcde") == false );

    REQUIRE( palindromo((char *)"abba") == true );
    REQUIRE( palindromo((char *)"dabaleelabad") == true );
    REQUIRE( palindromo((char *)"abcdecba") == false );
    REQUIRE( palindromo((char *)"") == true );
    REQUIRE( palindromo((char *)"arrozalazorra") == true );
}
