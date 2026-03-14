# Trabajo Práctico Nº 1.2 – Nociones de Lenguajes Formales

## Actividad 1 – Relaciones de equivalencia y particiones (conceptual + código)

### Mini‑desafío 1: Clasificador de números
En informática es frecuente clasificar datos según reglas: tipos, categorías, estados. En este desafío se modelará una relación de equivalencia como un clasificador automático.

**Desafío**
Se trabajará con la relación definida sobre los números naturales:

* El 0 sólo se relaciona consigo mismo.
* El 1 sólo se relaciona consigo mismo.
* Dos números se relacionan si ambos son primos.
* Dos números se relacionan si ambos son compuestos.

**Consignas**

> 1. Analice colectivamente si esta relación induce una partición de los naturales.
> 2. Identifique las clases de equivalencia resultantes.
> 3. Diseñe un algoritmo que, dado un número natural, determine a qué clase pertenece.
> 4. Implemente el algoritmo en un lenguaje de programación a elección.
> 5. Pruebe el programa con un conjunto de números generados al azar.
> 6. Justifique por qué la relación es (o no) de equivalencia.

## Actividad 2 – Relaciones en $(\mathbb{N} \times \mathbb{N})$

1. Dado el conjunto $(\mathbb{N} \times \mathbb{N})$, se define la relación:

${(a,b) R (m,n) \iff a + n = m + b}$

a) Demuestre que la relación es de equivalencia.

b) Describa la partición inducida por la relación.

### Mini‑desafío 2:

   * Escriba una función que determine si dos pares (a,b) y (m,n) están relacionados.
   * Genere automáticamente varias clases de equivalencia para pares con valores acotados.

## Actividad 3 – Alfabetos, cadenas y lenguajes

1. Analice cuáles de los siguientes conjuntos pueden constituir un **alfabeto**:

   a) {FOR, WHILE, IF, DO, BEGIN, END, REPEAT, CASE}
   
   b) {a, b, ..., z, a, b, ..., z}
   
   c) {#, %, (, ), =, +, -}
   
   d) {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}

3. Determine cuáles de los siguientes conjuntos pueden considerarse **lenguajes**:

   a) (N = {0, 1, 2, ...})
   
   b) (X = {\lambda, |, ||, |||, ...})

   En los casos afirmativos, indique el alfabeto y las reglas de formación.

### Mini‑desafío 3:

   * Modele alfabeto, cadena y lenguaje mediante estructuras de datos.
     
   * Verifique mediante un programa si una cadena pertenece a un lenguaje dado.

## Actividad 4 – Operaciones sobre cadenas y lenguajes

### Mini‑desafío 4: Mini‑desafío de programación 2: Motor simple de lenguajes
Los lenguajes formales están en la base de los lenguajes de programación, los analizadores léxicos y los compiladores. En este desafío se construirá un pequeño motor que opere sobre lenguajes finitos.

Se consideran los lenguajes:

* L1 = {a, ab}
* L2 = {b, bd}
* L2 = {a, b, c}

> 1. Represente ambos lenguajes mediante estructuras de datos.
> 2. Implemente funciones para:
   * concatenación de lenguajes
   * unión
   * intersección
   * potencia   
> 3. Ejecute el programa y muestre los resultados obtenidos.
> 4. Experimente con otros lenguajes finitos definidos por usted.

## Actividad 5 – Cadenas, longitud y números naturales

1. Considere la operación concatenación ${· : \Sigma^* \times \Sigma^* \to \Sigma^*}$

2. Exprese una función que relacione:
   * cadenas y concatenación
   * números naturales y suma

### Mini‑desafío 4:
   * Implemente una función que, dada una cadena, devuelva su longitud.
   * Analice cómo la longitud se comporta frente a la concatenación.
