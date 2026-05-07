# Propuestas de Modelado de Autómatas Finitos en C

## Contexto

Se dispone de un conjunto de TAD genéricos:

* `LIST`
* `SET`
* `STR`

implementados mediante:

```c
Tdata
```

El objetivo es construir estructuras para representar:

* AFD (Autómatas Finitos Deterministas)
* AFND (Autómatas Finitos No Deterministas)

utilizando la definición formal:

[
A = (Q, Σ, δ, q0, F)
]

Donde:

* `Q` = conjunto de estados
* `Σ` = alfabeto
* `δ` = función de transición
* `q0` = estado inicial
* `F` = conjunto de estados de aceptación

---

# Propuesta 1 — Delta como Lista de Transiciones

## Idea General

Cada transición se almacena como:

[
(q_i, a, q_j)
]

En AFND:

[
(q_i, a, {q_j,q_k})
]

---

# Estructuras

## Estado y símbolo

```c
typedef str State;
typedef str Symbol;
```

---

## Transición

```c
typedef struct{
    State from;
    Symbol symbol;

    Tdata to; // SET de estados destino
} Transition;
```

---

## Nodo de transición

```c
typedef struct transitionNode{
    Transition t;
    struct transitionNode* next;
} TransitionNode;
```

---

## Autómata

```c
typedef struct{
    Tdata Q;
    Tdata Sigma;

    TransitionNode* Delta;

    State q0;

    Tdata F;

    int deterministic;
} Automata;
```

---

# Ejemplo

## AFND

```text
(q0,a)->{q1,q2}
(q1,b)->{q2}
(q2,a)->{q0}
```

---

# Representación gráfica

```text
          a
     +--------+
     |        v
    (q0) ---> q1
      |        |
      |        | b
      |        v
      +-----> q2
            a |
              |
              +----> q0
```

---

# Cómo funciona delta

La función:

```c
Tdata delta(Automata* A, State q, Symbol a);
```

recorre la lista de transiciones buscando:

```text
from == q
symbol == a
```

---

# Ventajas

* Muy fácil de implementar
* Fácil de debuggear


# Propuesta 2 — Delta Indexado por Estado

# Idea General

Cada estado almacena directamente sus transiciones.

El autómata se modela como un grafo.

---

# Estructuras

## Transición

```c
typedef struct transition{
    Symbol symbol;

    Tdata to;

    struct transition* next;
} Transition;
```

---

## Estado

```c
typedef struct stateNode{
    State name;

    Transition* transitions;

    int isFinal;

    struct stateNode* next;
} StateNode;
```

---

## Autómata

```c
typedef struct{
    StateNode* states;

    State q0;

    int deterministic;
} Automata;
```

---

# Representación conceptual

```text
q0
 ├──a──>{q1,q2}
 └──b──>{q3}
```

---

# Representación gráfica

```text
                 a
            +----------+
            |          |
            v          v
          [q1]       [q2]
            ^
            |
            |
           (q0)
            |
            |
            +------b------> [q3]
```

---

# Cómo funciona

Para procesar una cadena:

1. Buscar el estado actual
2. Acceder directamente a su lista de transiciones
3. Buscar símbolo compatible
4. Obtener conjunto destino

# Ventajas
* Más eficiente
* Muy natural
* Excelente para AFND


# Propuesta 3 — Delta como Matriz Dispersa

# Idea General

Los estados y símbolos se convierten en índices enteros.

[
\delta(q_i,a_j)
]

se representa como una matriz.

---

# Numeración

```text
q0 -> 0
q1 -> 1
q2 -> 2
```

---

# Estructuras

## Entrada de transición

```c
typedef struct{
    int from;

    int symbol;

    Tdata to;
} TransitionEntry;
```

---

## Autómata

```c
typedef struct{
    Tdata Q;

    Tdata Sigma;

    TransitionEntry* delta;

    int deltaSize;

    int q0;

    Tdata F;
} Automata;
```

---

# Representación matemática

```text
          a        b
      +--------+--------+
q0    |  q1    |  q0    |
q1    |  q2    |  q1    |
q2    |   -    |  q0    |
```

---

# Representación gráfica

```text
          +-------------------+
          |     MATRIZ δ      |
          +-------------------+

             a         b
          -----------------
q0  ---> |  {q1}   | {q0} |
q1  ---> |  {q2}   | {q1} |
q2  ---> |   {}    | {q0} |
```

---

# Cómo funciona

Acceso:

```text
Delta[estado][simbolo]
```

---

# Ventajas

* Acceso O(1)
* Muy eficiente


# Propuesta 4 — Delta Funcional

# Idea General

Representar literalmente:

[
\delta(q,a)={q1,q2}
]

---

# Estructuras

## Entrada funcional

```c
typedef struct{
    State from;

    Symbol symbol;

    Tdata destinations;
} DeltaEntry;
```

---

## Autómata

```c
typedef struct{
    Tdata Q;

    Tdata Sigma;

    DeltaEntry* delta;

    int deltaCount;

    State q0;

    Tdata F;
} Automata;
```

---

# Ejemplo

```text
δ(q0,a) = {q1,q2}
δ(q1,b) = {q2}
δ(q2,a) = {q0}
```

---

# Representación gráfica

```text
+--------------------------------+
|             DELTA              |
+--------------------------------+
| (q0,a) -> {q1,q2}              |
| (q1,b) -> {q2}                 |
| (q2,a) -> {q0}                 |
+--------------------------------+
```

---

# Cómo funciona

Cada entrada representa una aplicación concreta de:

[
\delta(q,a)
]

La búsqueda consiste en:

```text
buscar (estado, simbolo)
```

---

# Ventajas

* Muy elegante matemáticamente
* Excelente para AFND
* Ideal para determinización
* Fácil de razonar formalmente


---

# Propuesta 5 — Estados Compuestos para Determinización

# Idea General

Durante la determinización:

cada estado del AFD es un subconjunto de estados del AFND.

---

# Ejemplo

```text
{q0,q1}
{q2,q3}
{q1,q2,q4}
```

---

# Estructuras

## Estado compuesto

```c
typedef struct{
    Tdata subset;
} CompositeState;
```

---

## Transición determinizada

```c
typedef struct{
    CompositeState from;

    Symbol symbol;

    CompositeState to;
} DFA_Transition;
```

---

## AFD resultante

```c
typedef struct{
    Tdata states;

    DFA_Transition* delta;

    int deltaCount;

    CompositeState q0;

    Tdata F;
} DFA;
```

---

# Representación gráfica

```text
        a
+----------------+
|    {q0,q1}     |
+----------------+
          |
          |
          v
+----------------+
|    {q2,q3}     |
+----------------+
          |
          | b
          v
+----------------+
|   {q1,q2,q4}   |
+----------------+
```

---

# Cómo funciona

La construcción por subconjuntos genera:

```text
nuevo_estado = unión de destinos posibles
```

---

# Ejemplo Formal

Si:

```text
δ(q0,a) = {q1,q2}
δ(q1,a) = {q3}
```

Entonces:

```text
δ({q0,q1},a) = {q1,q2,q3}
```

---

# Ventajas

* Ideal para determinización
* Muy alineado con teoría formal
* Facilita conversión automática de AFD