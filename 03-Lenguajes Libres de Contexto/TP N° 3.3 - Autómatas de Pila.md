# Trabajo Práctico N° 3.3 - Autómatas de Pila

## Actividad 1 – Conceptos Fundamentales

1. Defina:

   - Autómata de Pila Determinista (APD) con estados finales.
   - Autómata de Pila Determinista por pila vacía.
   - Descripción instantánea (configuración).
   - Movimiento o paso computacional.

2. Explique el funcionamiento general de un APD.

3. Formalice:

   - Lenguaje aceptado por estados finales.
   - Lenguaje aceptado por pila vacía.

# Actividad 2 – Diseño de APD

Considere los siguientes lenguajes:

**Lenguaje 1:** El conjunto de todas las cadenas de paréntesis balanceados.

**Lenguaje 2:** El conjunto de todas las cadenas de paréntesis redondos y cuadrados balanceados.

**Lenguaje 3:** El conjunto de todas las cadenas sobre el alfabeto `{a,b}` con exactamente el doble de símbolos `a` que de símbolos `b`.

**Lenguaje 4:** $L=$ { $a^n b^{2n}\mid n\ge 1$ }

**Lenguaje 5:** $L=$ { $0^n1^m0^n\mid n,m\ge 1$ }

**Lenguaje 6:** $L=$ { $1^n0^m1^{n+m}\mid n,m\ge 1$ }

Para cada uno de ellos:

1. Realice un análisis de las cadenas que pertenecen a $L$ para encontrar patrones que orienten el diseño del AP
2. Indique si acepta por estado final o por pila vacía.
3. Diseñe un APD que lo acepte.
4. Muestre una secuencia de configuraciones para una cadena aceptada.
5. Muestre una secuencia de configuraciones para una cadena rechazada.

### Mini Desafío de Programación 1

Implemente un simulador sencillo de APD capaz de mostrar las configuraciones generadas durante la ejecución.

# Actividad 3 – Diseño de APND

## Parte A – Conceptos

1. Defina Autómata de Pila No Determinista (APND).
2. Explique el funcionamiento del no determinismo.
3. Formalice el lenguaje aceptado por un APND.

### Desafío Teórico

Construya una tabla comparativa entre:

| Modelo | Memoria | Determinismo | Lenguajes reconocidos |
|----------|----------|----------|----------|
| AFD | | | |
| AFND | | | |
| APD | | | |
| APND | | | |

## Parte B – Construcción de APND

Considere los siguientes lenguajes:

**Lenguaje 1:** $L=$ { $0^n1^m\mid n,m\ge 0,\; n\neq m$ }

**Lenguaje 2:** $L=$ { $a^n b^m\mid n\ge m\ge 0$ }

**Lenguaje 3:** $L=$ { $a^n b^m\mid n\neq m-1$ }

**Lenguaje 4:** $L=$ { $a^n b^m\mid n\neq 2m$ }

**Lenguaje 5:** $L=$ { $a^{2n}b^{3n}\mid n\ge 0$ }

**Lenguaje 6:** $L=$ { $a^n b^m\mid n\le m+3$ }

**Lenguaje 7:** $L=$ { $a^n b^m\mid 0\le n\le m\le 2n$ }

**Lenguaje 8:** $L=$ { $a^n b^m\mid 2n\le m\le 3n$ }

**Lenguaje 9:** $L=$ { $a^i b^j c^k\mid i=j-k$ }

**Lenguaje 10:** $L=$ { $w\in\{a,b\}^*\mid n_a(w)\le n_b(w)$ }

Para cada uno de ellos:

1. Realice un análisis de las cadenas que pertenecen a $L$ para encontrar patrones que orienten el diseño del AP
2. Indique si acepta por estado final o por pila vacía.
3. Diseñe un APD que lo acepte.
4. Justifique el uso del no determinismo.
5. Muestre una ejecución para una cadena aceptada.
6. Muestre una ejecución para una cadena rechazada.

### Mini Desafío de Programación 2

Extienda el simulador anterior para permitir múltiples configuraciones simultáneas.

