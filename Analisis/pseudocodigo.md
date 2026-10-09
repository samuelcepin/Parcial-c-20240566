# Pseudocódigo: Reto 5

## 1. Detección de eventos y cálculo de impacto

Para empezar, recorro la matriz fila por fila. Dentro de cada fila, evalúo las columnas arrancando desde la segunda:

1. Calcular la distancia absoluta (`d`) restando el valor actual menos el valor de la columna anterior.
2. Si (`d` < `L`) O (`d` > `U`) entonces:
   - Se detectó un Evento.
   - Sumar 1 al contador de eventos de esta fila.
   - Sumar 1 al vector de eventos de esta columna.
   - Calcular el impacto:
     - Si (`d` < `L`), el impacto es `L - d`.
     - Sino, el impacto es `d - U`.
   - Sumar este resultado al acumulador de impacto total de la fila.
3. Si la distancia estaba dentro de los límites, no hay evento y el impacto es 0.

--

## 2. Rachas, resúmenes y desempates

### Controlando las rachas
Mientras recorro las columnas de una fila:
- Si (hubo evento):
  - Sumar 1 a `racha_actual`.
  - Si (`racha_actual` == 1) entonces guardar el número de esta columna como el inicio de la racha.
  - Si (`racha_actual` > `max_racha_fila`) entonces actualizar `max_racha_fila` y guardar su posición de inicio.
- Sino (no hubo evento):
  - `racha_actual` = 0 (la racha se rompe).

### Definiendo las prioridades (Desempates)
Al terminar de revisar una fila completa, comparo para ver si es la Fila Prioritaria:
- Si (`max_racha_fila` > récord_global_racha) -> Es la nueva prioritaria.
- Sino, si hay empate en racha, pero (`impacto_fila` > récord_global_impacto) -> Es la nueva prioritaria.
- Sino, si hay empate en racha e impacto, pero (`eventos_fila` > récord_global_eventos) -> Es la nueva prioritaria.
- Si hay empate en todo lo anterior, gana la fila de menor número (se deja la primera encontrada).

### Columna destacada
Al terminar de analizar toda la matriz:
- Recorrer el vector de `eventos_por_columna`.
- La columna con el valor más alto es la destacada. En caso de empate, me quedo con la primera que alcanzó ese número.