# Gramática
Definición: Una **gramática** es una cuádrupla: $G = (N, T, S, P)$

donde:

* **$N$**: es un conjunto finito de **variables** (también llamados símbolos no terminales).
* **$T$**: es un conjunto finito de **símbolos terminales**, tal que $N \cap T = \emptyset$.
* **$P$**: es un conjunto finito de **producciones**. Cada regla tiene la forma $\alpha \rightarrow \beta$, donde $\alpha \in (N \cup T)^+$ y $\beta \in (N \cup T)^*$.
* **$S \in N$**: es el **símbolo inicial**.

Tipos de gramáticas (según la Jerarquía de Chomsky):

1. **Tipo 0** – Gramáticas sin restricciones (generan los lenguajes recursivamente enumerables).
2. **Tipo 1** – Gramáticas sensibles al contexto.
3. **Tipo 2** – Gramáticas libres de contexto (GLC).
4. **Tipo 3** – Gramáticas regulares.

En la materia nos enfoca principalmente en las **gramáticas tipo 2 (libres de contexto) y tipo 3 (regulares)**, y su relación con los autómatas de pila (AP) y los autómatas finitos (AF) respectivamente.

## Gramática Regular
Una **gramática regular** es una gramática $G = (N, T, P, S)$ en la que todas las **producciones** en $P$ son de una de las siguiente forma:

Gramática **regular por la derecha** (más común):

* $A \rightarrow aB$
* $A \rightarrow a$
* $A \rightarrow \varepsilon$

Gramática **regular por la izquierda** (menos común):

* $A \rightarrow Ba$
* $A \rightarrow a$
* $A \rightarrow \varepsilon$

donde:

* $A, B \in N$ (símbolos no terminales),
* $a \in T$ (símbolo terminal),
* $\varepsilon$ es la cadena vacía.

EJEMPLO:

```math
G = (\{S, A\}, \{a, b\}, \{S \rightarrow aA,\ A \rightarrow bA,\ A \rightarrow \varepsilon\}, S)
```
Para más claridad las producciones de $G$ se escriben de la siguiente manera:

${S \rightarrow aA}$

${A \rightarrow bA}$

${A \rightarrow \varepsilon}$

El lenguaje generado, ${L(G)}$, por esta gramática es el siguiente:

```math
L = \{ a, ab, abb, abbb, \ldots \} = \{ a b^n \mid n \geq 0 \}
```

Es decir:  ${L(G)=L}$.

### RESUMEN

* Solo genera **lenguajes regulares**.
* Tiene el **mismo poder expresivo** que los **autómatas finitos deterministas y no deterministas** (AFD y ANFD).
* Es el tipo de gramática **más restringido** dentro de la jerarquía de Chomsky.

### Ejemplo:

Queremos construir una **gramática regular (GR)** para el lenguaje:

```math
L = \{ w \in \{x,y\}^* \mid w = xy(xy)^* \}
```
Análisis del lenguaje:

El lenguaje contiene todas las cadenas que empiezan con *xy* y continúan con cero o más repeticiones de *xy*.
Esto es:

```math
L = { xy, xyxy, xyxyxy, \ldots }
```

Es decir, al menos **una** repetición de *xy*.

Definamos una **gramática regular por derecha** $G = (N, T, P, S)$, donde:

$N$ = {S, A}  (símbolos no terminales)

$T$ = {x, y}  (símbolos terminales)

$S$ es el símbolo inicial

$P$ contiene las siguientes producciones:

```math
\begin{aligned}
S &\rightarrow xA \\
A &\rightarrow yS \\
A &\rightarrow y
\end{aligned}
```

Explicación:

$S \rightarrow xA$: empieza con ${x}$ la cadena a generar

$A \rightarrow yS$: RECURSIÓN: agrega un caracter ${y}$ a la cadena y vuelve a empezar (con la variable ${S}$). Esto genera la cadena ${xy}$.

$A \rightarrow y$: termina la última repetición de la cadena ${xy}$ al no tener la concatenación de la variabe ${S}$.

OTRA SOLCUIÓN:

$N$ = {S} (símbolos no terminales)

$T$ = {x, y} (símbolos terminales)

$S$ es el símbolo inicial

$P$ contiene las siguientes producciones:

```math
\begin{aligned}
S &\rightarrow xyS | xy
\end{aligned}
```

NOTAR QUE ESTA GRAMÁTICA **NO ES ESTRICTAMENTE REGULAR**.

Vamos a considerar en el ámbito de la asignatura a esta forma de definir a las gramáticas como regulares puesto que con un simple proceso de factorización podemos obtener una GR formal.

# Derivación

En teoría de lenguajes formales, una **derivación** es el **proceso de aplicar reglas de producción** de una gramática para **generar una cadena** a partir del **símbolo inicial**.

Definición: Dada una gramática ${G = (N, T, P, S)}$, una **derivación** es una **secuencia de aplicaciones de producciones** que transforman el símbolo inicial ${S}$ en una cadena $w \in T^*$ (solo símbolos terminales).

Se escribe:

```math
S \Rightarrow \alpha_1 \Rightarrow \alpha_2 \Rightarrow \cdots \Rightarrow w
```

donde cada paso $\alpha_i \Rightarrow \alpha_{i+1}$ es una aplicación de alguna producción del conjunto ${P}$.

Tipos de derivación:

**Derivación por la izquierda**: en cada paso se sustituye el **no terminal más a la izquierda**.

**Derivación por la derecha**: en cada paso se sustituye el **no terminal más a la derecha**.

Ambas derivan la misma cadena, pero el orden de aplicación puede ser diferente. Esto importa, por ejemplo, cuando se construyen árboles de derivación o al analizar ambigüedad.

EJEMPLO:

Dada la gramática: ${S \rightarrow aS \mid b}$

Derivación de la cadena ${aab}$:

${S \Rightarrow aS \Rightarrow aaS \Rightarrow aab}$

Definamos una **gramática regular por derecha** $G = (N, T, S, P)$, donde:
<br><br>

$N$ = { ${R_{0},R_{1}, R_{2}}$ } (símbolos no terminales)

$T$ = {0, 1} (símbolos terminales)

$R_{0}$ es el símbolo inicial

$P$ contiene las siguientes producciones:

```math
\begin{aligned}
R_{0} &\rightarrow 0R_{0} | 1R_{1} | \varepsilon \\
R_{1} &\rightarrow 0R_{2} | 1R_{0} \\
R_{2} &\rightarrow 0R_{1} | 1R_{2}
\end{aligned}
```

Derivación de la cadena 1001: 

${R_{0} \Rightarrow 1R_{1} \Rightarrow 10R_{2} \Rightarrow 100R_{1} \Rightarrow 1001R_{0} \Rightarrow 1001}$

## Lenguaje Generado por una Gramática

Sea $G = (N, T, P, S)$, el **lenguaje generado por $G$**, denotado $L(G)$, es el conjunto de **todas las cadenas de símbolos terminales** que pueden ser **derivadas desde el símbolo inicial** $S$ usando las reglas de producción en ${P}$.

```math
L(G) = \{ w \in \Sigma^* \mid S \Rightarrow^* w \}
```

donde:

* $\Rightarrow^*$ significa **derivación en cero o más pasos**.
* $w$ es una cadena formada **solo por símbolos terminales** del alfabeto $\Sigma$.
  
## Relación entre Gramáticas Regulares y Autómatas

**Teorema: Conversión de GR a AF**

Sea $G = (N, T, P, S)$  una **gramática regular**  ${\Rightarrow \exists A = (Q, \Sigma, \delta, q_0, F)}$ un **Autómata Finito** tal que ${L(G)=L(A)}$.

ALGORITMO:

1. $\Sigma=T$
2. $Q=N$
3. $q_{0}=S$.
4. $\delta(R_{i},a) =$ { $R_{j} \in N | R_{i} \rightarrow a R_{j}, \forall R_{i} \in N, \forall a \in T$ }
5. $F=$ { $Q_{i} \in N | R_{i} \rightarrow \varepsilon$ }


EJEMPLO: $G = (\{S, A\}, \{a, b\}, P, S)$

Con el conjunto P formado con las siguientes producciones:

$$
\begin{aligned}
S &\rightarrow aA \\
A &\rightarrow bS \mid \varepsilon
\end{aligned}
$$

Construcción del AF:

1. $\Sigma = ${ $a, b$ }
2. $N=$ { $S, A$ }
3. $q_{0}=S$
4. Transiciones: $\delta(S, a) = A$ y $\delta(A, b) = S$
5. $F=$ { $A$ }

**Teorema: Conversión de AF a GR**

Sea $A = (Q, \Sigma, \delta, q_0, F)$  una **Autómata Finito** $\Rightarrow \exists \,\, G = (N, T, P, S)$ una **Gramática Regular** tal que $L(A)=L(G)$.

ALGORITMO:

1. $T= \Sigma$
2. $N=Q$
3. $S=q_{0}$
4. $\forall R_{i},R_{j} \in Q, \forall a \in \Sigma | \delta(R_{i},a) = R_{j} \Rightarrow R_{i} \rightarrow aR_{j}$
5. $\forall R_{i} \in Q | R_{i} \in F \Rightarrow R_{i} \rightarrow \varepsilon$

EJEMPLO: Dado el AF definido como sigue

$Q=$ { $q_0, q_1$ }, $\Sigma=$ { $a, b$ }, $F=$ { $q_{1}$ }

Transiciones:

$\delta(q_0, a) = q_1$

$\delta(q_1, b) = q_1$

Gramática equivalente:

$N=$ { $q_0, q_1$ },  $\Sigma=$ { $a, b$ } , $S = q_{0}$

Producciones:

```math
\begin{aligned}
q_{0} &\rightarrow a q_{1} \\
q_{1} &\rightarrow b q_{1} \mid \varepsilon
\end{aligned}
```

Esta GR genera el lenguaje $L=$ { $a b^*$ }
