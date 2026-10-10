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

// Funcion auxiliar para sacar el valor absoluto de una resta
// Asi evitamos tener distancias negativas en los calculos
int valor_absoluto(int x) {
    if (x < 0) return -x;
    return x;
}

int main() {
    int N, M, L, U;

    // Leemos los 4 parametros iniciales (Filas, Columnas, Limite Inferior, Limite Superior)
    if (scanf("%d %d %d %d", &N, &M, &L, &U) != 4) {
        printf("ERROR\n");
        return 0;
    }

    // Validamos que las dimensiones y limites no rompan las reglas del sistema
    if (N < 1 || N > 30 || M < 1 || M > 30 || 
        L < 0 || L > 1000 || U < 0 || U > 1000 || L > U) {
        printf("ERROR\n");
        return 0; 
    }

    int matriz[30][30];
    int i, j;

    // Llenamos la matriz con los datos de entrada
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            if (scanf("%d", &matriz[i][j]) != 1) {
                printf("ERROR\n");
                return 0;
            }
            // Si algun valor de la matriz es negativo o mayor a 1000, lanzamos error
            if (matriz[i][j] < 0 || matriz[i][j] > 1000) {
                printf("ERROR\n");
                return 0;
            }
        }
    }

    // Arreglo para llevar la cuenta de los eventos de cada columna
    int eventos_columnas[30];
    int col;
    for (col = 0; col < M; col++) {
        eventos_columnas[col] = 0; 
    }

    // Variables para guardar a los ganadores globales (fila prioritaria)
    int fila_prioritaria = 0;
    int max_racha_matriz = -1;
    int max_impacto_matriz = -1;
    
    // Contador global para saber si la matriz fue un desierto de eventos (Caso 02)
    int total_eventos_matriz = 0; 

    // Empezamos a analizar la matriz fila por fila
    for (i = 0; i < N; i++) {
        int eventos_fila = 0;
        int impacto_fila = 0;
        int racha_actual = 0;
        int max_racha_fila = 0;
        int inicio_actual = 0;
        int inicio_max_racha = 0;

        // Revisamos las columnas de la fila actual (empezando desde la segunda para poder restar)
        for (j = 1; j < M; j++) {
            // Calculamos la distancia absoluta entre el numero actual y el anterior
            int d = valor_absoluto(matriz[i][j] - matriz[i][j-1]);
            
            // Verificamos si la distancia se sale del rango de normalidad (es un evento)
            if (d < L || d > U) {
                eventos_fila++;
                total_eventos_matriz++; // Sumamos al contador total
                
                // Calculamos el impacto: que tanto se paso del limite (exceso)
                int impacto_actual = 0;
                if (d < L) {
                    impacto_actual = L - d; // Cuanto le falto para llegar a L
                } else if (d > U) {
                    impacto_actual = d - U; // Cuanto se paso de U
                }
                
                impacto_fila += impacto_actual;
                eventos_columnas[j] += 1; // Le sumamos un evento a esta columna
                
                // Si es el primer evento de la racha, guardamos donde inicio
                if (racha_actual == 0) {
                    inicio_actual = j; 
                }
                
                racha_actual++;
                // Actualizamos el record de racha de esta fila
                if (racha_actual > max_racha_fila) {
                    max_racha_fila = racha_actual;
                    inicio_max_racha = inicio_actual;
                }
            } else {
                // Si el dato es normal, se rompe la racha
                racha_actual = 0;
            }
        }
        
        // Calculamos la posicion inicial para humanos (sumando 1 a los indices)
        int inicio_print = 0;
        if (max_racha_fila > 0) {
            inicio_print = inicio_max_racha + 1;
        }

        // Imprimimos el reporte de esta fila exactamente como lo pide el evaluador
        printf("FILA %d EVENTOS %d IMPACTO %d RACHA %d INICIO %d\n", 
               i + 1, eventos_fila, impacto_fila, max_racha_fila, inicio_print);

        // Logica para elegir la fila ganadora de toda la matriz
        if (max_racha_fila > max_racha_matriz) {
            max_racha_matriz = max_racha_fila;
            max_impacto_matriz = impacto_fila;
            fila_prioritaria = i;
        } else if (max_racha_fila == max_racha_matriz) {
            // Desempate por impacto si las rachas son iguales
            if (impacto_fila > max_impacto_matriz) {
                max_impacto_matriz = impacto_fila;
                fila_prioritaria = i;
            }
        }
    }

    // Imprimimos el arreglo con los eventos de todas las columnas
    printf("COLUMNAS");
    for (col = 0; col < M; col++) {
        printf(" %d", eventos_columnas[col]);
    }
    printf("\n");

    // Buscamos la columna con mas eventos acumulados
    int columna_destacada = 0;
    int max_eventos_col = -1;
    
    for (col = 0; col < M; col++) {
        if (eventos_columnas[col] > max_eventos_col) {
            max_eventos_col = eventos_columnas[col];
            columna_destacada = col;
        }
    }
    
    // Si no hubo eventos en toda la matriz, los ganadores son cero por defecto
    if (total_eventos_matriz == 0) {
        printf("PRIORIDAD 0\n");
        printf("COLUMNA 0\n");
    } else {
        // Imprimimos a los ganadores (sumando 1 para formato humano)
        printf("PRIORIDAD %d\n", fila_prioritaria + 1);
        printf("COLUMNA %d\n", columna_destacada + 1);
    }

    return 0;
}