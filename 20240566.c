/*************************************************************************************/
/*                   Programación para mecatrónicos                                  */
/*  Nombre:    Samuel Cepin                                                          */
/*  Matricula: 2024-0566                                                             */
/*  Seccion:   Sabados                                                               */
/*  Practica:  Parcial 1                                                             */
/*  Fecha:     10/10/2026                                                            */
/*  Link Practica: https://github.com/samuelcepin/Parcial-c-20240566.git             */
/*************************************************************************************/

#include <stdio.h>

int main() {
    int N, M, L, U;

    // 1. Lo primero es hacer que lea los cuatro parámetros iniciales
    if (scanf("%d %d %d %d", &N, &M, &L, &U) != 4) {
        printf("ERROR\n");
        return 0;
    }

    // 2. Validamos las restricciones críticas según el mandato del profesor
    if (N < 1 || N > 30 || M < 1 || M > 30 || 
        L < 0 || L > 1000 || U < 0 || U > 1000 || L > U) {
        printf("ERROR\n");
        return 0;
    }


    return 0;
}