# Trabajo Práctico N°1.1 – Nociones de Conjuntos

## Mini-desafío de programación 0: Generador de conjuntos

### Contexto

En programación, los conjuntos aparecen como colecciones de datos. Este desafío propone modelar **conjuntos definidos por reglas**, no sólo por enumeración explícita.

### Desafío

1. Considere conjuntos definidos por comprensión (por ejemplo: números pares, múltiplos de 3, potencias de 2).
2. Diseñe algoritmos que generen los primeros *n* elementos de cada conjunto.
3. Compare las representaciones por extensión y por comprensión.

### Consignas

* Implemente una función que reciba una regla y un límite, y devuelva un conjunto finito.
* Pruebe el programa con distintos valores de *n*.
* Analice qué ocurre cuando se elimina el límite establecido por *n*.

Ejemplo: 
Sea el conjunto:

A = { x ∈ ℤ | x = 4k − 1, |k| ≤ 3 }

Los valores posibles de *k* son:

k ∈ {−3, −2, −1, 0, 1, 2, 3}

Calculando x = 4k − 1 para cada valor:

| k  | x = 4k − 1 |
|----|-----------|
| −3 | −13 |
| −2 | −9 |
| −1 | −5 |
| 0  | −1 |
| 1  | 3  |
| 2  | 7  |
| 3  | 11 |

Por lo tanto, el conjunto por extensión es:

A = {−13, −9, −5, −1, 3, 7, 11}

Código:
```python
def generar_conjunto():
    A = set()
    for k in range(-3, 4):  # k = -3, -2, -1, 0, 1, 2, 3
        x = 4 * k - 1
        A.add(x)
    return A

```
---

## Bloque A – Conjuntos y operaciones

**Actividades**

### 1. Refrescar las definiciones de operaciones unión, intersección, diferencia, complemento, comjunto de partes y resuelva para los siguientes conjuntos:

A = {2, 3, 4, 6}  
B = {3, 5, 6, 8}

a) (A∪B)−[(A∩B)−{3}]

b) A−({1,2,3,4,5}∩B)

c) P(A)−P(B)

d) P(B)∩P({8})

### Indicaciones

- Resolver mostrando los conjuntos intermedios.
- En los ítems (c) y (d), listar explícitamente los conjuntos involucrados.
- Justificar por qué ciertos elementos **no pueden pertenecer** al resultado.

### Complemento computacional

* Implementar operaciones de unión, intersección, diferencia, conjunto de partes utilizando listas en Python.
* Verificar los resultados obtenidos.

> Recordar: la verificación computacional **no reemplaza** la justificación matemática.

* Piense cómo implementaría el complemento de un conjunto. ¿Qué problemáticas encuentra?

### 2. Sean los conjuntos:

A = {a, b, c}
B = {1, 2}

a) Una relación en A × B

b) Una función A → B

c) Una relación en A × B que no sea función.

### 3. Dar ejemplos de relaciones que cumplan:

a) Simétrica y transitiva, pero no reflexiva

b) Reflexiva y simétrica, pero no transitiva

c) Reflexiva y transitiva, pero no simétrica

### 4.Dado el conjunto

A = {(a, b), (b, c), (d, a), (a, c)}

Obtener:

a) La clausura transitiva de A

b) La clausura reflexiva y transitiva de A

c) La clausura simétrica de A

## Mini-desafío de programación 1: Analizador de relaciones
1. Dado un conjunto finito y una relación representada como pares ordenados:

   * Determine si es reflexiva, simétrica y/o transitiva.
2. Implemente funciones para calcular:

   * clausura reflexiva
   * clausura simétrica
   * clausura transitiva

### Consignas

* Represente la relación mediante una estructura adecuada.
* Aplique el programa al conjunto de la actividad.

## Bloque B – cardinalidad e infinito

### 5. Busque información y bosqueje demostraciones para las siguientes afirmaciones:

* El conjunto de los números naturales pares tiene la misma cardinalidad que el conjunto de los números naturales impares.

* Probar que |ℕ| = |ℚ|. Sugerencia: probar que |ℕ| = |ℤ × ℤ|.

* El conjunto de todos los números reales es incontable.
