/*************************************************************************************/
/*                  Programación para mecatrónicos                                   */
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

    // Lo siguiente es que vamos ahora con el recorrer la matriz y calcular 'd'
    
    // Volvemos a recorrer la matriz exactamente fila por fila
    for (i = 0; i < N; i++) {
        // esto son los marcadores de la fila actual se ponen en cero al iniciar cada fila
        int racha_actual = 0;
        int max_racha_fila = 0;
        int impacto_fila = 0;

        for (j = 0; j < M; j++) {
            // Ahora bien lo que toca es Calcular la distancia 'd' solo si no estamos en la primera columna
            int d = 0;
            if (j > 0) {
                d = matriz[i][j] - matriz[i][j-1];
                
                // Aqui lo que toca es evaluar si la distancia 'd' genera un evento
                if (d < L || d > U) {
                    // Sacamos el impacto
                    int impacto_actual = d;
                    if (impacto_actual < 0) {
                        impacto_actual = -impacto_actual;
                    }
                    
                    // Sumamos el impacto al total de esta fila y de esta columna
                    impacto_fila = impacto_fila + impacto_actual;
                    impacto_columnas[j] = impacto_columnas[j] + impacto_actual;
                    
                    // Aumentamos la racha y verificamos si rompimos el record de la fila
                    racha_actual++;
                    if (racha_actual > max_racha_fila) {
                        max_racha_fila = racha_actual;
                    }
                } else {
                    // Si el numero esta dentro del limite normal lo que la racha como tal se rompe
                    racha_actual = 0;
                }
            }
        }
        
        // Lo siguiente sera hacer que la fila se convierte en la prioritaria

        // Comparamos los records de esta fila con los records de toda la matriz
        if (max_racha_fila > max_racha_matriz) {
            max_racha_matriz = max_racha_fila;
            max_impacto_matriz = impacto_fila;
            fila_prioritaria = i;
        } else if (max_racha_fila == max_racha_matriz) {
            // En caso de que haya un empate en las rachas, va a ganar el que tenga mayor impacto
            if (impacto_fila > max_impacto_matriz) {
                max_impacto_matriz = impacto_fila;
                fila_prioritaria = i;
            }
        }
    }
    
    return 0;
}