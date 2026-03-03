# Trabajo Práctico Nº 1 – Lenguajes Formales

## Propósitos del trabajo práctico

Este trabajo práctico tiene como objetivo introducir y consolidar los conceptos básicos de lenguajes formales, alfabetos, cadenas y relaciones de equivalencia, articulándolos con **actividades de programación** que permitan:

* Pasar del razonamiento matemático abstracto a representaciones computacionales.
* Reconocer a las cadenas como estructuras manipulables algorítmicamente.
* Comprender el rol de los lenguajes formales como base de la informática (lenguajes de programación, compiladores, protocolos, etc.).

## Objetivos de aprendizaje

Al finalizar el trabajo práctico, se espera que el/la estudiante sea capaz de:

* Identificar y justificar relaciones de equivalencia y sus particiones.
* Reconocer alfabetos, cadenas y lenguajes en distintos contextos.
* Implementar operaciones básicas sobre cadenas mediante programas simples.
* Modelar conceptos teóricos de lenguajes formales utilizando un lenguaje de programación.
* Interpretar el vínculo entre operaciones sobre cadenas y operaciones aritméticas.

## Organización y tiempos sugeridos

**Duración total estimada:** 4 a 5 horas

* Introducción y consignas generales: 15 min
* Actividad 1 (Relaciones y particiones): 45 min
* Actividad 2 (Alfabetos y lenguajes): 45 min
* Actividad 3 (Cadenas y operaciones): 60 min
* Actividad 4 (Lenguajes y operaciones entre lenguajes): 45 min
* Cierre y reflexión integradora: 30 min

## Actividad 1 – Relaciones de equivalencia y particiones (conceptual + código)

### Mini‑desafío de laboratorio 1: Clasificador de números

**Modalidad:** Presencial guiada (laboratorio)

**Tiempo estimado:** 60 minutos

**Contexto**
En informática es frecuente clasificar datos según reglas: tipos, categorías, estados. En este desafío se modelará una relación de equivalencia como un clasificador automático.

**Desafío**
Se trabajará con la relación definida sobre los números naturales:

* El 0 sólo se relaciona consigo mismo.
* El 1 sólo se relaciona consigo mismo.
* Dos números se relacionan si ambos son primos.
* Dos números se relacionan si ambos son compuestos.

**Consignas**

1. Analice colectivamente si esta relación induce una partición de los naturales.
2. Identifique las clases de equivalencia resultantes.
3. Diseñe un algoritmo que, dado un número natural, determine a qué clase pertenece.
4. Implemente el algoritmo en un lenguaje de programación a elección.
5. Pruebe el programa con un conjunto de números dado por la cátedra.

**Productos esperados**

* Código funcional del clasificador.
* Breve justificación de por qué la relación es (o no) de equivalencia.

**Cierre guiado (10 min)**
Discusión sobre cómo una definición matemática se traduce en reglas algorítmicas.

## Actividad 2 – Relaciones en (\mathbb{N} \times \mathbb{N})

1. Dado el conjunto (\mathbb{N} \times \mathbb{N}), se define la relación:

[(a,b) R (m,n) \iff a + n = m + b]

a) Demuestre que la relación es de equivalencia.
b) Describa la partición inducida por la relación.

2. **Extensión con programación:**

   * Escriba una función que determine si dos pares ((a,b)) y ((m,n)) están relacionados.
   * Genere automáticamente varias clases de equivalencia para pares con valores acotados.

## Actividad 3 – Alfabetos, cadenas y lenguajes

1. Analice cuáles de los siguientes conjuntos pueden constituir un **alfabeto**:

   a) {FOR, WHILE, IF, DO, BEGIN, END, REPEAT, CASE}
   b) {a, b, ..., z, a, b, ..., z}
   c) {#, %, (, ), =, +, -}
   d) {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}

2. Determine cuáles de los siguientes conjuntos pueden considerarse **lenguajes**:

   a) (N = {0, 1, 2, ...})
   b) (X = {\lambda, |, ||, |||, ...})

   En los casos afirmativos, indique el alfabeto y las reglas de formación.

3. **Extensión con programación:**

   * Modele alfabeto, cadena y lenguaje mediante estructuras de datos.
   * Verifique mediante un programa si una cadena pertenece a un lenguaje dado.

## Actividad 4 – Operaciones sobre cadenas y lenguajes

### Mini‑desafío de laboratorio 2: Motor simple de lenguajes

**Modalidad:** Presencial guiada + trabajo autónomo

**Tiempo estimado:** 75 minutos (45 presencial + 30 autónomo)

**Contexto**
Los lenguajes formales están en la base de los lenguajes de programación, los analizadores léxicos y los compiladores. En este desafío se construirá un pequeño motor que opere sobre lenguajes finitos.

**Desafío**

Se consideran los lenguajes:

* L1 = {a, ab}
* L2 = {b, bd}

**Consignas presenciales**

1. Represente ambos lenguajes mediante estructuras de datos.
2. Implemente funciones para:

   * concatenación de lenguajes
   * unión
   * intersección
3. Ejecute el programa y muestre los resultados obtenidos.

**Consignas de trabajo autónomo**

4. Experimente con otros lenguajes finitos definidos por usted.
5. Analice si se cumple que |L1 · L2| ≤ |L1| + |L2| en los casos probados.

**Productos esperados**

* Código del motor de operaciones sobre lenguajes.
* Registros de ejecución.
* Respuesta razonada a la desigualdad planteada.

**Cierre reflexivo**
¿Qué ventajas tiene representar lenguajes como estructuras manipulables por programas?

## Actividad 5 – Cadenas, longitud y números naturales

1. Considere la operación concatenación (· : \Sigma^* \times \Sigma^* \to \Sigma^*).

2. Exprese una función que relacione:

   * cadenas y concatenación
   * números naturales y suma

3. **Extensión con programación:**

   * Implemente una función que, dada una cadena, devuelva su longitud.
   * Analice cómo la longitud se comporta frente a la concatenación.

## Cierre

Redacte una breve reflexión (máx. 10 líneas) sobre:

* Qué conceptos resultaron más abstractos.
* Cómo ayudó la programación a comprenderlos.
* En qué otros contextos informáticos cree que aparecen los lenguajes formales.
