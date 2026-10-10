# Programacion para mecatronicos sabados


# Parcial de algoritmo en C

* **Estudiante:** Samuel R. Cepin
* **Matrícula:** 2024-0566
* **Reto Asignado:** Red: variaciones de latencia anormales


## Descripción
El programa recibe como entrada una matriz de N filas y M columnas, junto con los límites inferior L y superior U. Primero verifica que las dimensiones, los límites y los datos ingresados cumplan con las restricciones establecidas. Luego, procesa las distancias absolutas entre los valores adyacentes de cada fila para determinar cuáles cumplen la condición de quedar fuera del rango permitido y ser considerados eventos.

Para cada fila, el programa calcula la cantidad de eventos, el impacto total (sumando el exceso por el cual la distancia superó los límites), la racha consecutiva más larga de dichos eventos y la posición exacta donde comienza esta racha. También contabiliza la cantidad de eventos que aparecen de forma individual en cada columna a lo largo de toda la matriz.

Finalmente, el programa determina cuál es la fila prioritaria basándose en la mayor racha alcanzada y utilizando el mayor impacto como criterio de desempate. Asimismo, determina cuál es la columna destacada según la mayor cantidad de eventos acumulados. Los resultados se muestran siguiendo estrictamente el formato de salida automatizado solicitado por el ejercicio.

## Compilación y ejecución
gcc -std=c11 -Wall -Wextra 20240566.c -o parcial

## Diseño
En la carpeta de analisis

## Pruebas
No las subi

## Estado actual
Completado
        
