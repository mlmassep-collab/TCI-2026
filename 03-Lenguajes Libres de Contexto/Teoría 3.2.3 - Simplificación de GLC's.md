# Simplificación de Gramáticas Libres de Contexto

## Símbolos útiles e inútiles

Dada una GLC $G = (V, T, S, P)$:

Un **símbolo $X$** (en general una variable no terminal) es **útil** si existe una derivación:

  $$
  S \Rightarrow^* \alpha X \beta \Rightarrow^* w
  $$

  con:  $\alpha, \beta$: formas sentenciales y $w \in T^*$: una cadena terminal.

En cualquier otro caso, el símbolo $X$ es considerado **inútil**.

**Criterios para determinar si $X$ es útil:**

1. **Generatividad (Lema 3):**
   Desde $X$, se puede derivar alguna cadena terminal:

$$
X \Rightarrow^* w \quad \text{con } w \in T^*
$$

2. **Accesibilidad (Lema 4):**
   $X$ aparece en alguna forma sentencial derivada desde el símbolo inicial $S$:

$$
S \Rightarrow^* \alpha X \beta
$$

Para que un símbolo $X$ sea **útil**, **debe cumplir ambos criterios**: ser **accesible** desde el símbolo inicial y **generar** una cadena terminal.

## Lema 3: Quitar variables no generadoras

Sea ${G = (N, T, S, P)}$ una GLC, con ${L(G) \neq \emptyset}$, es posible obtener efectivamente una *GLC* ${G_{1} = (N_{1}, T, S, P_{1})}$ a partir de ${G}$ done:

${\forall A \in N_{1}, \exists w \in T^* \text{ tal que } A \Rightarrow^* w}$

**Algoritmo:**

```text
lema3(G):
1. Sea G = (N, T, S, P)
2. viejoN = {}
3. nuevoN = { A en N | existe [A,{w}], w ∈ T* }
4. mientras (viejoN ≠ nuevoN):
    4.1 viejoN = nuevoN
    4.2 nuevoN = viejoN union { A en N | existe [A,{w}], w en (T ∪ viejoN)* }
5. nuevoP = {}
6. Para cada A en nuevoN:
    6.1 Sea [A,{alpha_1, alpha_2,...,alpha_n}] en P
    6.2 nuevo_rhs = {}
    6.3 Para cada alpha_i:
        Si alpha_i pertenece a (T union nuevoN)* entonces:
          nuevo_rhs=nuevo_rhs union {alpha_i}
    6.4 nuevoP = nuevoP union [A, nuevo_rhs]
7. Contestar:
   G_1 = (nuevoN, T, S, nuevoP)
```

## Lema 4: Quitar variables no alcanzables

Sea ${G = (N, T, S, P)}$ una GLC, con ${L(G) \neq \emptyset}$, es posible obtener efectivamente una *GLC* ${G_{1} = (N_{1}, T_{1}, S, P_{1})}$ a partir de ${G}$ donde

${\forall A \in N_{1}, \exists \alpha, \beta \in (T_{1} \cup N_{1}) ^* \text{ tal que } S \Rightarrow^* \alpha A \beta}$

**Algoritmo:**

```text
lema4(G):
1. Sea G = (N, T, S, P)
2. nuevoN = { S }
3. viejoN = {}
4. mientras (viejoN ≠ nuevoN ∨ viejoT ≠ nuevoT):
    4.1 D = nuevoN − viejoN
    4.2 viejoN = nuevoN
    4.3 viejoT = nuevoT
    4.4 Para todo A en D tal que [A,{alpha_1, alpha_2,...,alpha_n}] está en P
          Para todo X, a en alpha_i con X en N y a en T:
              nuevoN = nuevoN union { X }
              nuevoT = nuevoT union { a }
5. nuevoP = {}
6. Para cada A ∈ nuevoN:
    6.1 Sea [A,{alpha_1, alpha_2,...,alpha_n}] en P
    6.2 nuevo_rhs = {}
    6.3 Para cada alpha_i:
        Si alpha_i pertence a (nuevoT union nuevoN)* entonces:
          nuevo_rhs=nuevo_rhs union {alpha_i}
    6.4 nuevoP = nuevoP union [A, nuevo_rhs]
7. Contestar:
   G_1 = (nuevoN, nuevoT, S, nuevoP)
```
## Quitar Producciones Epsilon

Pondremos ahora nuestra atención a la eliminación de producciones de la forma ${A \rightarrow \varepsilon}$, a las que llamaremos **producciones $\varepsilon$**. Seguramente si ${\varepsilon}$ está en $L(G)$, no podemos eliminar todas las producciones ${\varepsilon}$ de ${G}$, pero si no está en ${L(G)}$, se hace evidente que podemos eliminarlas.

El método consiste en determinar para cada variable ${A}$ si ${A \stackrel{*}{\Rightarrow} \varepsilon}$. Si esto sucede, decimos que **A es anulable**. Podemos sustituir cada producción ${B \rightarrow X_{1}\, X_{2} \dots X_{n}}$ por todas las producciones formadas mediante la eliminación de algún subconjunto de aquellas ${X_{i}}$ que son anulables, pero no incluimos ${B \rightarrow \varepsilon}$, aún si **todas** las ${X_i}$ son anulables.

### Teorema 

Si ${L = L(G)}$ para alguna GLC ${G = (V, T, P, S)}$, entonces **${L - \{ \varepsilon \}}$** es el lenguaje de una GLC ${G'}$ que no tiene símbolos inútiles ni producciones ${\varepsilon}$.

Algoritmo:
Podemos determinar los símbolos anulables de ${G}$ a través del siguiente algoritmo iterativo. Representamos las producciones como una lista de dos elementos, en el que la primer componene es la variable sintáctica del LHS y la segunda componente es un conjunto compuesto por los RHS de la variable. 

```text
quitar_pe(G):
1. Sea G = (N,T,S,P)
2. VA = {} // variables anulables

//Encontrar variables anulables directas
3. Para todo A en N tal que [A,{eps}] es una producción:
     VA = VA union {A}

/7Encontrar variables anulables indirectas
4. cambio=true
5. Mientras cambio==true
     cambio=false
     Para todo A en N:
        Si [A,{alpha}] pertenece a P y todos los símbolos de alpha están VA entonces:
           VA = VA union {B}
           cambio = true

//El conjunto de producciones de P se construyen de la siguiente manera.
5. nuevo_p={}
6. Para toda [A, {X_1, X_2,..., X_n}] en P: 
     nuevo_p = nuevo_p union [A, {alpha_1, alpha_2,...,alpha_n}] donde 
        1. Si X_i no pertenece a VA entonces alpha_i = X_i;  //dejar la prodcción como está
        2. Sino alpha_i = X_i o alpha_i = eps;               //anular de a una variable a la vez 
        3. No todas las alpha_i son eps                      //no anular todas las variables al mismo tiempo
```
7. Eliminar todas las producciones epsilon de nuevo_p

//Resultado final
8. responder G1 = (N,T,S,nuevo_p)

Explicación paso a paso:

**1. Determinación de símbolos anulables:**

* Se identifican variables que derivan a ${\varepsilon}$ directamente.
* Luego, iterativamente se detectan otras variables que pueden derivar a ${\varepsilon}$ si todos los símbolos en su lado derecho ya se han identificado como anulables.

**2. Construcción de nuevas producciones (sin ${\varepsilon}$):**

* Para cada producción ${A \rightarrow X_{1} X_{2} \dots X_{n}}$, se generan nuevas producciones eliminando posibles combinaciones de los símbolos anulables, sin eliminar todos a la vez (para evitar introducir nuevamente ${\varepsilon}$).
* Esto genera múltiples producciones que cubren todas las combinaciones posibles sin la producción vacía.

## Ejemplo 1

${S \rightarrow AB | a}$

${A \rightarrow aA | \varepsilon}$

${B \rightarrow \varepsilon | b}$

Paso 1: Identificar símbolos anulables

* ${A \rightarrow \varepsilon \Rightarrow  A}$ es anulable
* ${B \rightarrow \varepsilon \Rightarrow  B}$  es anulable

Luego, Anulables = ${\{A, B\}}$

Paso 2: Generar nuevas producciones eliminando combinaciones de anulables**

Aplicamos el procedimiento descrito en el texto para construir ${P'}$, es decir, todas las combinaciones posibles al eliminar A y B, **sin que todos los símbolos desaparezcan a la vez** (para evitar agregar una producción ε no deseada).

Producción: ${S \rightarrow AB}$

${A}$ y ${B}$ son anulables. Entonces las combinaciones válidas son:

* ${S \rightarrow AB}$ (original)
* ${S \rightarrow A}$  (eliminamos B)
* ${S \rightarrow B}$  (eliminamos A)

No agregamos ${S \rightarrow \varepsilon}$ (porque el objetivo es eliminar ${\varepsilon}$ -producciones).

Producción: ${A \rightarrow a}$

Se mantiene sin cambios.

Producción: ${A \rightarrow aA}$

${A}$ es anulable. Entonces:

* ${A \rightarrow aA}$  (original)
* ${A \rightarrow a}$   (eliminamos A de la derecha)

Producción: ${B \rightarrow b}$

Se mantiene sin cambios.

**Nueva gramática sin producciones ε:**

${S \rightarrow AB | A | B | a}$

${A \rightarrow aA | a}$

${B \rightarrow b}$

## Ejemplo 2

${S \rightarrow aA | bB | C}$

${A \rightarrow aA | \varepsilon}$

${B \rightarrow bBCa | A}$

${C \rightarrow B}$

Paso 1: Identificar variables anulables

* ${A \rightarrow \varepsilon \Rightarrow A}$  es anulable
* ${B \rightarrow A}$, y como ${A}$ es anulable ${\Rightarrow B}$ es anulable (porque ${B}$ deriva en ${A}$, que deriva en ${\varepsilon}$)
* ${C \rightarrow B}$, y ${B}$ es anulable ${\Rightarrow C}$ es anulable

Entonces Anulables = ${ \{ A, B, C \}}$

Paso 2: Generar nuevas producciones eliminando combinaciones de anulables

Producción: ${S \rightarrow aA}$

A es anulable. Entonces las combinaciones válidas son:

* ${S \rightarrow aA}$ (Original)
* ${S \rightarrow a}$ (Anulo A)

Producción: ${S \rightarrow C}$

C es anulable. Entonces las combinaciones válidas son:

* ${S \rightarrow C}$ (Original)
* **NO se agrega** ${S \rightarrow \varepsilon}$

Producción: ${A \rightarrow aA}$

A es anulable. Entonces las combinaciones válidas son:

* ${A \rightarrow aA}$ (Original)
* ${A \rightarrow a}$ (Anulo A)

Producción: ${A \rightarrow \varepsilon}$

Esta se elimina en la nueva gramática.

Producción: ${B \rightarrow bBCa}$

B y C son anulables. Entonces las combinaciones válidas son:

* ${B \rightarrow bBCa}$ (Original)
* ${B \rightarrow bCa}$ (Anulo B)
* ${B \rightarrow bBa}$ (Anulo C)
* ${B \rightarrow ba}$ (Anulo ambas)

Producción: ${B \rightarrow A}$

A es anulable. Entonces las combinaciones válidas son:

* ${B \rightarrow A}$
* **NO se agrega** ${B \rightarrow \varepsilon}$

Producción: ${C \rightarrow B}$

B es anulable. Entonces las combinaciones válidas son:

* ${C \rightarrow B}$
* **NO se agrega** ${C \rightarrow \varepsilon}$

**Nueva gramática sin producciones ε:**

${S \rightarrow aA | bB | C}$

${A \rightarrow aA | a}$

${B \rightarrow bBCa | bCa | bBa | ba | A}$

${C \rightarrow B}$

# Quitar producciones unitarias

Una producción unitaria es de la forma: ${A \rightarrow  B}$ con ${A,B \in N}$

Como puede se desprende de la definición, **A y B son variables** (no terminales). Estas producciones no agregan información útil y pueden ser eliminadas para simplificar la gramática.

### Teorema
Cada LLC sin ${\varepsilon}$ está definido por una gramática que no tiene símbolos inútiles, producciones ${\varepsilon}$, o producciones unitarias.

```text
quitar_unit(G):
1. Sea G = (N,T,S,P)
2. no_unitarias = {}
3. unitarias = {}

//Separar producciones unitarias y no unitarias
4. Para cada producción p en P:
     4.1 A = lhs(p)
     4.2 nuevo_rhs = {}
     4.3 nuevo_rhs_uni = {}
     4.4 Para cada alpha en rhs(p):
            si alpha es una producción unitaria:
                 nuevo_rhs_uni = nuevo_rhs_uni union {alpha}
            sino:
                 nuevo_rhs = nuevo_rhs union {alpha}
     4.5 no_unitarias(A) = no_unitarias(A) union nuevo_rhs
     4.6 unitarias(A) = unitarias(A) union nuevo_rhs_uni

//Calcular clausura transitiva unitaria
5. cambio = true
6. Mientras cambio == true:
     6.1 cambio = false
     6.2 Para cada A en unitarias:
            nuevas = {}
            Para cada B en unitarias(A):
                 nuevas = nuevas union unitarias(B)
            nuevas = nuevas - unitarias(A)
            Si nuevas != {}:
                 unitarias(A) =
                     unitarias(A) union nuevas
                 cambio = true

//Construir nueva gramática
7. nuevo_p = {}
8. Para cada no terminal A en N:
     8.1 nuevo_p(A) =
             nuevo_p(A) union no_unitarias(A)
     8.2 Para cada B en unitarias(A):
             nuevo_p(A) =
                 nuevo_p(A) union no_unitarias(B)

//Resultado final
9. responder G1 = (N,T,S,nuevo_p)
```
## Ejemplo 1

${S \rightarrow aA | bB}$

${A \rightarrow aA | B | D}$

${B \rightarrow bBCa | C}$

${C \rightarrow abC | ab}$

${D \rightarrow bDa | ba}$

**Paso 1 — Separar producciones unitarias y no unitarias**

no_unitarias =
{
$[S,$ { $aA,bB$ } $]$,
$[A,$ { $aA$ } $]$,
$[B,$ { $bBCa$ } $]$,
$[C,$ { $abC,ab$ } $]$,
$[D,$ { $bDa,ba$ } $]$
}

unitarias =
{
$[A,$ { $B,D$ } $]$,
$[B,$ { $C$ } $]$
}

**Paso 2 — Calcular clausura transitiva unitaria**

unitarias =
{
$[A,$ { $B,D,C$ } $]$,
$[B,$ { $C$ } $]$
}

**Paso 3 — Construir las nuevas producciones**

${S \rightarrow aA \mid bB}$

${A \rightarrow aA \mid bBCa \mid abC \mid ab \mid bDa \mid ba}$

${B \rightarrow bBCa \mid abC \mid ab}$

${C \rightarrow abC \mid ab}$

${D \rightarrow bDa \mid ba}$

