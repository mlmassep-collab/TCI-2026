# AUTÓMATAS DE PILA

## AUTÓMATAS DE PILA DETERMINISTAS (APD)

Un **Autómata Finito con Pila Determinista** (APD) es una 6-upla:

$$
M = (Q, \Sigma, \Gamma, \Delta, q_0, Z_0)
$$

con los siguientes componentes:

1. ${ Q }$ es el conjunto finito no vacío de estados internos.

2. ${ q_0 \in Q }$ es el estado inicial.

3. ${ \Sigma }$ es el alfabeto de entrada, también llamado alfabeto de la cinta.

4. ${ \Gamma }$ es el alfabeto de pila.

5. ${ z_0 \in \Gamma }$ es el marcador de fondo, también llamado símbolo inicial de pila  
   ${ (z_0 \text{ no pertenece al alfabeto de entrada } \Sigma) }$.

6. ${ \Delta }$ es la función de transición del autómata:

$$
\Delta : Q \times (\Sigma \cup \lambda) \times \Gamma \to (Q \times \Gamma^*)
$$

Un APD procesa cadenas sobre una cinta de entrada semi-infinita, y además utiliza una cinta adicional, llamada **pila**, que es utilizada por el autómata como lugar de almacenamiento.  

<img src="https://drive.google.com/uc?export=view&id=1VsY0B98d5d_vc2d3GHksiPg1_O4QdtwD" width="500">

Un APD puede definirse usando un conjunto ${ F \subseteq Q  }$  de estados de acpetación, pasando de ser una 6-upla a una 7-upla:

$$
M = (Q, \Sigma, \Gamma, \Delta, q_0, Z_0, F)
$$

### Movimiento o Paso Computacional
La transición:

$$
\Delta(q, a, s) = (q', \gamma)
$$

representa un **movimiento o paso computacional**:

1. la unidad de control pasa al estado ${ q' }$ y se mueve a la derecha,  
2. se borra el símbolo ${s }$ que está en la parte superior de la pila,  
3. se escribe la cadena ${ \gamma }$ en el tope de la pila(cadena que pertenece a ${ \Gamma^* }$),  
4. se pasa a escanear el nuevo símbolo de entrada en la cinta.

**Nota:**  
Recalcamos que en cada momento, el autómata sólo tiene acceso al símbolo que está en el tope de la pila; además, el contenido de la pila siempre se lee desde arriba (el tope) hacia abajo.  
Por estas dos razones la pila se dibuja verticalmente.

<img src="https://drive.google.com/uc?export=view&id=1JAtSwmTVI_UObVFaUmY4vNucBSZx4mEa" width="500">

### Ejemplo 1

Construir un APD que acepte $L = ${ $a^n b^n \mid n \geq 1$ }

Las cadenas que pertenecen a $L$ son aquellas con igual cantidad de `a` y `b`, con todas las `a` primero y luego todas las `b`.

**Definición formal**

El APD es la 7-upla:

$$
M = (Q, \Sigma, \Gamma, \Delta, q_0, Z_0, F)
$$

**Componentes**:

* $Q =$ { $q_0, q_1, q_f$ }
* $q_0$ es el estado inicial
* $F =$ { $q_f$ } es el conjunto de estados finales
* $\Sigma =$ { $a, b$ }
* $\Gamma =$ { $Z_0, A$ } ( $Z_0$ es el símbolo inicial de la pila, $A$ es un marcador para cada ${a}$ )
* $Z_0 = Z_0$
* $\Delta$ se define como:

| Estado actual | Símbolo entrada | Tope pila actual | Nueva configuración (Estado, Nuevo tope pila) |
| ------------- | --------------- | ----------------- | ---------------------------------------- |
| $q_0$         | ${a}$             | $Z_0$             | $(q_0, AZ_0)$                            |
| $q_0$         | ${a}$             | $A$               | $(q_0, AA)$                              |
| $q_0$         | ${b}$             | $A$               | $(q_1, \lambda)$                         |
| $q_1$         | ${b}$             | $A$               | $(q_1, \lambda)$                         |
| $q_1$         | $\lambda$       | $Z_0$             | $(q_f, Z_0)$                             |

**Ejemplo de procesamiento**

Cadena: ${aaabbb}$

Estado inicial: ${q_{0}}$, pila: ${Z_{0}}$

| Entrada leída | Acción en pila | Estado actual | Pila     |
| ------------- | -------------- | ------------- | -------- |
| -            | -       | -        | Z₀     |
| ${a}$             | push A         | $q_0$         | A Z₀     |
| ${a}$             | push A         | $q_0$         | A A Z₀   |
| ${a}$             | push A         | $q_0$         | A A A Z₀ |
| ${b}$             | pop A          | $q_1$         | A A Z₀   |
| ${b}$             | pop A          | $q_1$         | A Z₀     |
| ${b}$            | pop A          | $q_1$         | Z₀       |
| ${\lambda}$      | move to $q_f$  | $q_f$         | Z₀       |

Conclusión: **Cadena aceptada**

**Resumen**

Este APD utiliza la pila como contador de las ${a}$  leídas.
Por cada ${a}$  se hace un *push*.
Por cada ${b}$  se hace un *pop*.
Cuando la pila regresa a su símbolo base ${Z_{0}}$ y no quedan más símbolos por leer, se acepta la cadena.

### Tipos de Transiciones

1. $\Delta(q, a, s) = (q', s)$. En este caso, el contenido de la pila no se altera. Se consume la entrada ${a}$.

${\hspace{2cm}}$ * Se lee el símbolo ${a}$ en la cinta de entrada.

${\hspace{2cm}}$ * El tope de la pila es ${s}$, pero no se cambia (queda igual).

${\hspace{2cm}}$ * Se avanza la cinta (se consume ${a}$).

${\hspace{2cm}}$ * Se cambia el estado a ${q'}$.

Ejemplo: $\Delta(q_0, a, A)= (q_1, A)$  no cambia la pila (se pone el mismo símbolo que se sacó)

2. $\Delta(q, a, s) = (q', \lambda)$. El símbolo **s** en el tope de la pila se borra y la unidad de control pasa a escanear el nuevo tope de la pila, que es el símbolo colocado inmediatamente debajo de ${s}$. Se consume la entrada ${a}$.
Se lee ${a}$ en la cinta de entrada (se consume).

${\hspace{2cm}}$ * Se lee ${a}$ en la cinta de entrada (se consume).

${\hspace{2cm}}$ * El tope de la pila ${s}$ se borra.

${\hspace{2cm}}$ * Se cambia el estado a ${q'}$.

Ejemplo: $\Delta(q_0, a, A)=(q_1, \lambda)$  se borra el tope de la pila

3. $\Delta(q, \lambda, s) = (q', \gamma)$. **Es una transición $\lambda$ o transición espontánea**: el símbolo sobre la cinta de entrada no se procesa y la unidad de control no se mueve a la derecha, pero el tope ${s}$ de la pila es reemplazado por la cadena $\gamma$.

${\hspace{2cm}}$ * No se consume símbolo de la cinta (se mantiene en el mismo símbolo).

${\hspace{2cm}}$ * Se borra el tope de la pila ${s}$.

${\hspace{2cm}}$ * Se escriben los símbolos ${\gamma}$ en la pila.

${\hspace{2cm}}$ * Se cambia el estado a ${q'}$.

Ejemplo: $\Delta(q_1, \lambda, Z_0)= (q_2, AZ_0)$  transición espontánea que deja $Z_0$ en la pila y agrega al tope $A$

Para garantizar el determinismo, $\Delta(q, a, s)$ y $\Delta(q, \lambda, s)$, con $a \in \Sigma$, no pueden estar simultáneamente definidos (de lo contrario el autómata tendría una opción no-determinista).

Las transiciones espontáneas en un APD permiten que el autómata **cambie el contenido de la pila sin procesar (o consumir) símbolos sobre la cinta de entrada**.

### Configuración o descripción instantánea

Es una terna $(q, au, s\beta)$ que representa lo siguiente:

* el autómata está en el estado $q$,
* $au$ es la parte no procesada de la cadena de entrada,
* la unidad de control está escaneando el símbolo $a$,
* la cadena $s\beta$ es el contenido total de la pila; siendo $s$ el símbolo colocado en la parte superior.

La notación $(q, au, s\beta)$ para configuraciones instantáneas es muy cómoda para representar un paso computacional. Escribimos simplemente:

$$
(q, au, s\beta) \vdash (q', u, \gamma\beta)
$$

Aquí el autómata utilizó la transición $\Delta(q, a, s) = (q', \gamma)$.

La notación:

$$
(q, u, \beta) \vdash^* (p, v, \gamma)
$$

significa que el autómata pasa de la configuración instantánea $(q, u, \beta)$ a la configuración instantánea $(p, v, \gamma)$ en cero, uno o más pasos computacionales.

## Configuración inicial

Para una cadena de entrada $w \in \Sigma^*$, la configuración inicial es $(q_0, w, Z_0)$.

Al comenzar el procesamiento de toda cadena de entrada, el contenido de la pila es $Z_0$, que sirve como marcador de fondo.

## Configuración de aceptación por estado finales 

Se aplica cuando el APD se define usando un conjunto $F$ de estados de aceptación.

Sea ${q_{f} \in F}$, la configuración de aceptación es ${(q_{f},\lambda,\beta)}$, con ${\beta \in \Gamma^{*}}$

Caracterísitcas:
* El autómata termina en un estado final ${q_{f} \in F}$.
* No importa lo que quede en la pila.
* La entrada debe estar completamente consumida

La entrada se ha terminado (no queda nada por leer) y el estado actual es un estado de aceptación.

## Configuración de aceptación por pila vacía

La configuración de aceptación es $(q,\lambda,\lambda)$, con $q \in Q$

Caracterísitcas:
* El autómata termina en cualquier estado ${q \in Q}$.
* La pila **debe quedar vacía**.
* La entrada debe estar completamente consumida.

La entrada se ha terminado (no queda nada por leer) y la pila se encuentra totalmente vacía (incluso el símbolo $Z_0$.

### Ejemplo 2

Construir un APD que acepte $L =$ { $a^n b^n \mid n \geq 2$ }

**Solución:**

$M = (Q, \Sigma, \Gamma, \Delta, q_0, z_0, F)$, donde

$\Sigma = \{a, b\}$
$\Gamma = \{Z_0, A\}$
$q_0 = q_0$
$Q = \{q_0, q_1, q_2, q_3 q_f\}$
$F = \{q_f\}$

y la función de transición está dada por:

$\Delta(q_0, a, Z_0) = (q_1, AZ_0)$

$\Delta(q_1, a, A) = (q_2, AA)$

$\Delta(q_2, a, A) = (q_1, AA)$

$\Delta(q_2, b, A) = (q_3, \lambda)$

$\Delta(q_3, b, A) = (q_3, \lambda)$

$\Delta(q_3, \lambda, Z_0) = (q_f, Z_0)$

Los estados tienen distintos propósitos o indican la ocurrencia de distintos sucesos en la lectura de la cadena de entrada, en este caso:

$q_0$: estado en el que se solo es posible leer una (No pueden haber b’s en la cinta).

$q_1$: estado en el que se verificó la exstencia de una $a$

$q_2$: estado en el que se verificó la exstencia de dos $a's$

$q_3$: estado en el que se emparejan las a’s con las b’s (No pueden aparecer a’s en la cinta).

$q_f$: estado de aceptación (significa que se logró emparejar cada A de la pila con cada b de la cinta).

Podemos ilustrar el procesamiento de varias cadenas de entrada.

Para la cadena de entrada $u = aaabbb$, se obtiene el siguiente procesamiento:

$(q_0, aaabbb, z_0) \vdash (q_1, aabbb, AZ_0) \vdash (q_2, abbb, AA Z_0) \vdash (q_2, bbb, AAA Z_0) \vdash (q_3, bb, AA Z_0) \vdash (q_3, b, A Z_0) \vdash (q_3, \lambda , Z_0) \vdash (q_f, \lambda, Z_0)$

$(q_f, \lambda, Z_0)$ es una configuración de aceptación; por lo tanto la cadena $u = aaabbb$ es aceptada.

Para la cadena de entrada $v = aabbb$, se obtiene el siguiente procesamiento:

$(q_0, aabbb, Z_0) \vdash (q_1, abbb, AZ_0) \vdash (q_2, bbb, AA Z_0) \vdash (q_3, bb b, A Z_0) \vdash (q_3, b, Z_0)$

**\[cómputo abortado]**

El autómata ha ingresado al estado de aceptación $q_f$, pero la cadena de entrada no es aceptada debido a que no se ha procesado completamente; $(q_f, b, Z_0)$ no es una configuración de aceptación, por lo tanto la cadena $v = aabbb$ no es aceptada.

Para la cadena de entrada $v = ab$, se obtiene el siguiente procesamiento:

$(q_0, ab, Z_0) \vdash (q_1, b, AZ_0) \vdash (q_2, \lambda, Z_0)$

**\[cómputo abortado]**

El autómata no ha ingresado al estado de aceptación $q_f$, y la cadena de entrada se ha consumido completamente; $(q_2, \lambda, Z_0)$ no es una configuración de aceptación, por lo tanto la cadena $v = ab$ no es aceptada.

### Lenguaje Aceptado

**Aceptación por estados finales**

$L(M)=$ { $w \in \Sigma^* | (q_0, w, Z_0) \vdash^* (p, \lambda, \beta), \ p \in F$ }

**Aceptación por pil avacía**

$L(M)=$ { $w \in \Sigma^* | (p_0, w, Z_0) \vdash^* (q, \lambda, \lambda) \ \text{para algún estado} \ q$ }

En ambos casos se tiene que una cadena es aceptada si se puede ir desde la configuración inicial hasta una configuración de aceptación, en cero, uno o más pasos.

**Importante:**
Se permite que una transición $\Delta(q, a, s)$ no esté definida, para algunos valores $q \in Q$, $a \in \Sigma$, $s \in \Gamma$. Esto implica que el cómputo de algunas cadenas de entrada puede abortarse sin que éstas se procesen completamente.

### Ejemplo 3
$L =$ { $a^n b^{2n+1} \mid n \geq 0$ }

Ejemplos de cadenas de $L$:

* $n = 0 \Rightarrow b^1 = b$
* $n = 1 \Rightarrow a b^3 = a bbb$
* $n = 2 \Rightarrow aa b^5 = aa bbbbb$
* $n = 3 \Rightarrow aaa b^7 = aaa bbbbbbb$

Este lenguaje tiene una relación fija entre las ${a’s}$ y ${b’s}$, que se puede seguir perfectamente con una pila y de manera determinista.

Ideas para la construcción de aceptación por un APD determinista:

1. **Primera fase:** mientras se leen ${a}$, se apilan dos símbolos (por cada ${a}$ leído, se ponen dos símbolo en la pila).
2. **Transición:** cuando se empieza a leer ${b}$, se pasa a la segunda fase.
3. **Segunda fase:** por cada ${b}$, se hace lo siguiente:

   * Por cada par de ${b}$, se desapila **un** símbolo.
   * Al terminar de desapilar todos los símbolos (cuando la pila esté vacía), **queda 1 ${b}$ extra** que se debe comprobar.
     
4. Si se llega al final de la cadena con la pila vacía y habiendo leído exactamente **2n + 1** ${b}$, la cadena se acepta.

Solución:
$M = (Q, \Sigma, \Gamma, \Delta, q_0, Z_0, F)$, donde

$\Sigma = \{a, b\}$

$\Gamma = \{Z_0, A\}$

$q_0 = q_0$

$Z_0 = Z_0$

$Q = \{q_0, q_1, q_f\}$

$F = \{q_f\}$

y la función de transición está dada por:

$\Delta(q_0, a, Z_0) = (q_0, AAZ_0)$

$\Delta(q_0, a, A) = (q_0, AAA)$

$\Delta(q_0, b, A) = (q_1, \lambda)$

$\Delta(q_1, b, A) = (q_1, \lambda)$

$\Delta(q_1, b, Z_0) = (q_2, Z_0)$

$\Delta(q_2, \lambda, Z_0) = (q_f, Z_0)$

Procesamiento de la cadena ${w=aabbbbb}$

${(q_0, aabbbbb, Z_0) \vdash (q_0, abbbbb, AAZ_0) \vdash (q_0, bbbbb, AAAAZ_0) \vdash (q_1, bbbb, AAAZ_0) \vdash (q_1, bbb, AAZ_0) \vdash (q_1, bb, AZ_0) \vdash (q_1, b, Z_0) \vdash (q_2, \lambda, Z_0) \vdash (q_f, \lambda, Z_0)}$

$(q_f,\lambda,Z_0)$ es una configuración de aceptación; por lo tanto la cadena ${u=aabbbbb}$ es aceptada.

### Ejemplo 4

**Diseñar un APD que acepte el lenguaje**
$L =$ { $wcw^R : w \in \{a, b\}^*$ } **sobre** $\Sigma = \{a, b, c\}$.

**Notar que las cadenas** $w$ **y** $w^R$ **sólo poseen a's y/o b's.**

**Solución.**
La idea es acumular los símbolos en la pila hasta que aparezca la **c**.
 
Luego se comparan los símbolos leídos con los almacenados en la pila, borrando en cada paso el tope de la pila.

La cadena de entrada será aceptada si es procesada completamente y en la pila sólo queda el marcador de fondo $Z_0$.

$M = (Q, q_0, F, \Sigma, \Gamma, Z_0, \Delta)$, donde:

$\Sigma = \{a, b, c\}$

$\Gamma = \{Z_0, A, B\}$

$Q = \{q_0, q_1, q_f\}$

$F = \{q_f\}$

### Función de transición:

**Si la cadena de entrada** $u = wcw^R$ **tiene** $w = \lambda$ → entonces $u = c$

$\Delta(q_0, c, Z_0) = (q_f, Z_0)$

**Si la cadena de entrada** $u = wcw^R$ **tiene** $w \ne \lambda$, acumular $w$:

$\Delta(q_0, a, Z_0) = (q_0, AZ_0)$

$\Delta(q_0, a, A) = (q_0, AA)$

$\Delta(q_0, a, B) = (q_0, AB)$

$\Delta(q_0, b, Z_0) = (q_0, BZ_0)$

$\Delta(q_0, b, A) = (q_0, BA)$

$\Delta(q_0, b, B) = (q_0, BB)$

**Cambiar de estado para emparejar:**

$\Delta(q_0, c, A) = (q_1, A)$

$\Delta(q_0, c, B) = (q_1, B)$

**Emparejar** $w^R$:

$\Delta(q_1, a, A) = (q_1, \lambda)$

$\Delta(q_1, b, B) = (q_1, \lambda)$

$\Delta(q_1, \lambda, Z_0) = (q_f, Z_0)$

### Ejemplo de procesamiento:

$w = abbab \rightarrow u = abbabcbabba$

$(q_0, abbabc babba, Z_0) \vdash^{*} (q_1, babba, B A B B A Z_0)
\vdash (q_1, abba,  A B B A Z_0) \vdash (q_1, bba,  B B A Z_0)
\vdash (q_1, ba,  B A Z_0) \vdash (q_1, a, A Z_0)
\vdash (q_1, \lambda, Z_0) \vdash$

$(q_f, \lambda, Z_0)$

La **configuración de aceptación en APD con estados finales es:**
$(q_f, \lambda, \beta)$





