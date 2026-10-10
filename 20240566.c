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

    // Validamos las restricciones críticas según el mandato del profe
    if (N < 1 || N > 30 || M < 1 || M > 30 || 
        L < 0 || L > 1000 || U < 0 || U > 1000 || L > U) {
        printf("ERROR\n");
        return 0;
    }

    // 3. Ahora voy con la declaracion de la matriz y leer los datos
    int matriz[30][30];
    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            // Aqui se lee un numero actual
            if (scanf("%d", &matriz[i][j]) != 1) {
                printf("ERROR\n");
                return 0;
            }
            
            // Validamos que la latencia se encuentre entre 0 y 1000
            if (matriz[i][j] < 0 || matriz[i][j] > 1000) {
                printf("ERROR\n");
                return 0;
            }
        }
    }

    // El siguiente movimiento es preparar variables para el análisis
    
    // Un vector (arreglo) para ir sumando el impacto de cada columna.
    // Usamos un ciclo para asegurarnos de que todas empiecen en 0.
    int impacto_columnas[30];
    int col;
    for (col = 0; col < M; col++) {
        impacto_columnas[col] = 0; 
    }

    // Variables globales para recordar quién va ganando como "Fila prioritaria"
    int fila_prioritaria = 0;
    int max_racha_matriz = -1;
    int max_impacto_matriz = -1;

    return 0;
}     