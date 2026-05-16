# Gramáticas Libres de Contexto
Una **Gramática Libre de Contexto (GLC)** es una gramática $G = (N, T, P, S)$ en la que todas las **producciones** en $P$ son de una de las siguiente forma:

$${
A \rightarrow \alpha
}$$

donde:

$A \in N$ (un solo no terminal)

$\alpha \in (N \cup T)^*$ (cualquier cadena de terminales y/o no terminales)

Característica principal:

Cada producción tiene **exactamente un solo no terminal en el lado izquierdo**. Esto lo distingue de gramáticas más generales (como las sensibles al contexto).

EJEMPLO:

$G = (S$, { $a, b$ }, { S $\rightarrow aSb, S \rightarrow \varepsilon$ }, $S)$


Este GLC genera el lenguaje: $L(G) =$ { $a^n b^n \mid n \geq 0$ }

¿Por qué se llaman *libres de contexto*?

Porque las reglas pueden aplicarse **sin importar el contexto** en el que aparezca el no terminal.
Por ejemplo, si tienes $A \rightarrow x$, puedes reemplazar $A$ por $x$ **en cualquier lugar** donde aparezca $A$, sin importar lo que haya antes o después.

IMPORTANTE: 
```text id="gmlc4x"
Lenguajes Regulares ⊂ Lenguajes Libres de Contexto
```
Los RHS de las producciones de las Gramáticas Regulares imponen más restricciones que los de las Gramáticas Libres de Contexto. En las GR, el lado derecho de una producción puede estar formado únicamente por un terminal seguido opcionalmente de una variable sintáctica (o solo por un terminal). En cambio, en las GLC el RHS puede consistir en cualquier combinación de terminales y variables sintácticas, sin restricciones adicionales sobre su forma. 

En general, cuanto mayores son las restricciones impuestas sobre la forma de las producciones, menor es la potencia expresiva de la gramática y, por lo tanto, más reducida es la clase de lenguajes que puede generar.

## Forma Sentencial
Una **forma sentencial** en una gramática formal (ya sea GR o GLC) es **cualquier cadena de símbolos** que puede obtenerse a partir del **símbolo inicial** mediante una secuencia de **derivaciones**, y que puede contener **terminales, no terminales o ambos**.

Definición formal:

Dada una gramática $G = (N, T, P, S)$, una **forma sentencial** es **una cadena** $\alpha \in (N \cup T)^*$ tal que:

$$
S \Rightarrow^* \alpha
$$

donde:

* $S$ es el símbolo inicial,
* $\Rightarrow^*$ representa una derivación en cero o más pasos,
* $\alpha$ puede contener símbolos terminales y/o no terminales.

EJEMPLO: Sea una GLC con las siguientes producciones:

$$
\begin{aligned}
S &\rightarrow aSb \\
S &\rightarrow \varepsilon
\end{aligned}
$$

La derivación de la cadena ${aabb}$:

$$
S \Rightarrow aSb \Rightarrow aaSbb \Rightarrow aabbb
$$

Contiene las siguientes formas sentenciales:

* $S$ es una forma sentencial *inicial*
* $aSb$, $aaSbb$ son formas sentenciales *intermedias*
* $aabbb$ es una forma sentencial *terminal* (cadena en el lenguaje)

## Derivación

### Derivación en un paso:  

Si la producción ${A \rightarrow \beta}$ está en ${P}$ (el conjunto de producciones), y además ${\alpha}$ y ${\gamma}$ son cadenas de ${(N \cup T)^*}$ (es decir, secuencias de símbolos terminales y no terminales), entonces la cadena ${\alpha A \gamma}$ **deriva en un paso** a ${\alpha \beta \gamma}$, lo cual se denota:

$${
\alpha A \gamma \Rightarrow \alpha \beta \gamma
}$$

EJEMPLO:

Supongamos que se tiene la producción:

$$
A \rightarrow ab
$$

Y una cadena:

$$
bbAbb \Rightarrow bbabbb
$$

Esto es una **derivación en un paso** porque se sustituyó ${A}$ por ${ab}$, usando la producción dada.

### Derivación en más de un paso

Supongamos que la secuencia de cadenas $\alpha_1, \alpha_2, \dots, \alpha_m$ son **formas sentenciales** de una gramática $G$, con $m \geq 1$, y además:

$$
\alpha_1 \Rightarrow \alpha_2, \quad \alpha_2 \Rightarrow \alpha_3, \quad \dots, \quad \alpha_{m-1} \Rightarrow \alpha_m
$$

Entonces se dice que:

$$
\alpha_1 \Rightarrow^* \alpha_m
$$

Es decir, **$\alpha_1$ deriva en muchos pasos** en $\alpha_m$.

EJEMPLO: Sea la gramática:

$$
S \rightarrow aS \mid b
$$

Derivación:

$$
S \Rightarrow aS \Rightarrow aaS \Rightarrow aab
$$

Entonces:

$$
S \Rightarrow^* aab
$$

## Árbol de Derivación
Sea $G = (N, T, S, P)$ una gramática libre de contexto. Un **árbol es un árbol de derivación** si cumple con las siguientes características:

1. **Etiquetas de vértices:**
   Todo vértice tiene una etiqueta que pertenece a $N \cup T$,
   es decir, es un **símbolo no terminal o terminal**.

2. **Raíz:**
   La etiqueta de la raíz es el **símbolo inicial** $S$.

3. **Nodos interiores:**
   Si un nodo es interior (es decir, tiene hijos) y su etiqueta es ${A}$, entonces ${A \in N}$
   (solo los **no terminales** pueden expandirse).

4. **Reglas de producción:**
   Si un nodo con etiqueta ${A}$ tiene hijos con etiquetas ${X_{1}, X_{2}, \dots, X_{m}}$, entonces debe existir una producción:

   $${
   A \rightarrow X_{1} X_{2} \dots X_{m} \in P
   }$$

5. **Símbolo ${\varepsilon}$:**
   Si un vértice tiene como etiqueta ${\varepsilon}$, entonces: Es una **hoja** y es el **único hijo** de su padre

## Relación entre derivación y árbol de derivación

**Teorema**: Sea $G = (N, T, S, P)$ una GLC.
$S \Rightarrow^* \alpha$ ⟺ existe un árbol de derivación con raíz $S$ que produce $\alpha$.

**Derivación por izquierda/derecha**:
En cada paso de derivación se toma **la variable más a la izquierda o más a la derecha** de la forma sentencial para ser reemplazada.

## AMBIGUEDAD
Una GLC es ambigua cuando posee para al menos una cadena ${w}$ de ${L}$, al menos dos derivaciones por izquierda distintas o al menos dos derivaciones por derecha distintas.

En otras palabras, una gramática es ambigua si existe alguna cadena del lenguaje generado por la gramática que puede tener más de un árbol de derivación (ya sea por izquierda o por derecha), lo que implica múltiples formas de interpretar esa cadena.
