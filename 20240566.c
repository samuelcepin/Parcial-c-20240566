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

    // Leer los parámetros iniciales
    if (scanf("%d %d %d %d", &N, &M, &L, &U) != 4) {
        printf("ERROR\n");
        return 0;
    }

    // Validar restricciones
    if (N < 1 || N > 30 || M < 1 || M > 30 || 
        L < 0 || L > 1000 || U < 0 || U > 1000 || L > U) {
        printf("ERROR\n");
        return 0; 
    }

    int matriz[30][30];
    int i, j;

    // Leer matriz
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            if (scanf("%d", &matriz[i][j]) != 1) {
                printf("ERROR\n");
                return 0;
            }
            if (matriz[i][j] < 0 || matriz[i][j] > 1000) {
                printf("ERROR\n");
                return 0;
            }
        }
    }

    int impacto_columnas[30];
    int col;
    for (col = 0; col < M; col++) {
        impacto_columnas[col] = 0; 
    }

    int fila_prioritaria = 0;
    int max_racha_matriz = -1;
    int max_impacto_matriz = -1;

    // Análisis fila por fila
    for (i = 0; i < N; i++) {
        int eventos_fila = 0;
        int impacto_fila = 0;
        int racha_actual = 0;
        int max_racha_fila = 0;
        int inicio_actual = 0;
        int inicio_max_racha = 0;

        for (j = 1; j < M; j++) {
            int d = matriz[i][j] - matriz[i][j-1];
            
            if (d < L || d > U) {
                eventos_fila++;
                
                int impacto_actual = d;
                if (impacto_actual < 0) {
                    impacto_actual = -impacto_actual;
                }
                
                impacto_fila = impacto_fila + impacto_actual;
                impacto_columnas[j] = impacto_columnas[j] + impacto_actual;
                
                // Si la racha apenas comienza, guardamos dónde inició
                if (racha_actual == 0) {
                    inicio_actual = j; 
                }
                
                racha_actual++;
                if (racha_actual > max_racha_fila) {
                    max_racha_fila = racha_actual;
                    inicio_max_racha = inicio_actual;
                }
            } else {
                racha_actual = 0;
            }
        }
        
        // Determinar el índice humano de inicio (si no hubo racha, es 0)
        int inicio_print = 0;
        if (max_racha_fila > 0) {
            inicio_print = inicio_max_racha + 1;
        }

        // Imprimir el reporte detallado exacto que pide el profesor por fila
        printf("FILA %d EVENTOS %d IMPACTO %d RACHA %d INICIO %d\n", 
               i + 1, eventos_fila, impacto_fila, max_racha_fila, inicio_print);

        // Desempate de prioridad
        if (max_racha_fila > max_racha_matriz) {
            max_racha_matriz = max_racha_fila;
            max_impacto_matriz = impacto_fila;
            fila_prioritaria = i;
        } else if (max_racha_fila == max_racha_matriz) {
            if (impacto_fila > max_impacto_matriz) {
                max_impacto_matriz = impacto_fila;
                fila_prioritaria = i;
            }
        }
    }

    // Imprimir el arreglo de columnas
    printf("COLUMNAS");
    for (col = 0; col < M; col++) {
        printf(" %d", impacto_columnas[col]);
    }
    printf("\n");

    // Buscar la columna ganadora
    int columna_destacada = 0;
    int max_impacto_col = -1;
    
    for (col = 0; col < M; col++) {
        if (impacto_columnas[col] > max_impacto_col) {
            max_impacto_col = impacto_columnas[col];
            columna_destacada = col;
        }
    }
    
    // Imprimir el resultado final exactamente con las palabras esperadas
    printf("PRIORIDAD %d\n", fila_prioritaria + 1);
    printf("COLUMNA %d\n", columna_destacada + 1);

    return 0;
}