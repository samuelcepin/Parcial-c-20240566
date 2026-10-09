# Análisis del Problema: Reto 16

## Lo primero entradas, salidas y reglas del juego 


### Datos que recibimos (Entradas)
Al arrancar, el programa lee cuatro números enteros en una sola línea: N para las filas, M para las columnas, L como límite inferior y U como límite superior. Inmediatamente después, leemos todos los datos de la matriz, que tendrá un tamaño de N por M. 

### Validaciones estrictas (Restricciones)
Las dimensiones de la matriz (N y M) tienen que estar obligatoriamente entre 1 y 30. Los límites L y U pueden ir de 0 a 1000, pero L nunca puede ser mayor que U. Además, ninguna latencia individual puede salirse del rango de 0 a 1000. Si algún dato rompe estas reglas, el programa frena en seco, imprime la palabra ERROR y termina la ejecución.   

### Lo mostrado al final (Salidas)
Vamos a imprimir una línea por cada fila detallando cuántos eventos tuvo, su impacto total, su racha más larga y en qué columna empezó esa racha. Después, sacamos una línea con la suma de eventos de cada columna. Por último, evaluamos los desempates para imprimir cuál fue la fila con mayor prioridad y la columna con más fallos. Un detalle clave: a la hora de imprimir, numeraremos las filas y columnas empezando desde el 1, no desde el 0.   


## Lo segundo es variables y arreglos que voy a usar

### Para los parámetros de entrada: Variables de tipo entero estándar para N, M, L, y U.

### Estructuras en memoria
Declararé una matriz estática matriz[30][30] para almacenar todas las latencias de forma segura sin exceder el límite. También usaré un vector eventos_por_columna[30] para ir acumulando los fallos que ocurran en cada columna a medida que analizo los datos.   

### Para procesar la lógica
Las clásicas variables i y j para controlar los ciclos, y una variable d donde guardaré la distancia absoluta de los saltos. A nivel de cada fila, usaré acumuladores como eventos_fila, impacto_fila, racha_actual y max_racha. Como el impacto acumulado puede llegar a ser un número bastante grande, usaré enteros de al menos 32 bits (como pide el mandato) para evitar problemas de memoria.   

### Para decidir al final (Desempates)
Un grupo de variables globales (como max_racha_global, max_impacto_global, etc.) que me servirán para ir comparando los récords y así determinar cuál es la fila_prioritaria y la columna_destacada.