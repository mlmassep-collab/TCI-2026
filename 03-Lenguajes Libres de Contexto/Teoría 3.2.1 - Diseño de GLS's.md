# Diseño de Gramáticas Libres de Contexto
**Lectura sugerida**: Ramón Brena, *Autómatas y Lenguajes*, pág. 116

**Objetivo**: Diseñar una GLC $G$ tal que $L(G) = L$

**Propiedades deseadas**:

**Correcta**: Una GLC $G$ es correcta respecto de $L$ si no genera cadenas que no están en $L$:

$L(G) \subseteq L$

**Completa**: Una GLC $G$ es completa respecto de $L$ si genera al menos todas las cadenas que pertenecen a $L$:

$L \subseteq L(G)$

**Errores comunes al diseñar una GLC**:

* Si **sobran cadenas** en $L(G)$: la gramática es **incorrecta**.
* Si **faltan cadenas** en $L(G)$: la gramática es **incompleta**.

**Nota final**: No existe un método completamente sistemático para diseñar GLC, pero sí hay **lineamientos útiles** que ayudan a construirlas de forma más precisa y eficiente.

## 1. Adaptación de GLC

**Objetivo**: Diseñar una gramática que genere el lenguaje

<p align="center">
  $L =$ { $a^n b^m \mid n > m$ }
</p>

Es decir, cadenas con **más a’s que b’s**.

**Punto de partida**: Se parte de una GLC conocida que genera el lenguaje

<p align="center">
  $L =$ { $a^n b^m \mid n = m$ }
</p>

con la siguiente regla:

$$
S \rightarrow aSb \mid ab
$$

Esta gramática genera pares de a’s y b’s balanceados (misma cantidad).

**Siguiente paso**:

Para adaptarla al lenguaje $L =$ { $a^n b^m \mid n > m$ }, necesitamos modificarla para **permitir más a’s que b’s**. Esto implica permitir **a's "extra"** antes del balance $a^n b^n$, o introducir reglas que agreguen ${a's}$ sin un ${b}$ correspondiente.

${S \rightarrow aSb \mid aA}$

${A \rightarrow aA \mid \varepsilon}$

## 2. Unión de GLC's

**Objetivo**: Diseñar una gramática que genere el lenguaje

<p align="center">
  $L =$ { $a^n b^m \mid n \ne m$ }
</p>

**Idea clave**: Unión de lenguajes

Se observa que el lenguaje puede expresarse como la **unión** de dos subconjuntos:

* $L_1 =$ { $a^n b^m \mid n < m$ }
* $L_2 =$ { $a^n b^m \mid n > m$ }

Entonces:

$$
L = L_1 \cup L_2
$$

**Gramáticas para $L_1$ y $L_2$**

* Para $L_1$ (más ${b}$ que ${a}$): $S_1 \rightarrow aS_1b \mid aS_1 \mid a$

* Para $L_2$ (más ${a}$ que ${b}$): $S_2 \rightarrow aS_2b \mid bS_2 \mid b$

**Gramática para ${L}$**

Para obtener una GLC que genere $L =$ { $a^n b^m \mid n \ne m$ }, se puede definir una nueva variable inicial:

${
S \rightarrow S_1 \mid S_2
}$

${
S_{1} \rightarrow aS_{1}b \mid aS_{1} \mid a
}$

${
S_{2} \rightarrow aS_{2}b \mid bS_{2} \mid b
}$

## 3. Mezcla de GLC's

**Objetivo**: Diseñar una gramática que genere el lenguaje

<p align="center">
$L = ${ $a^n b^m \mid n \le m \le 2n$ }
</p>

Este lenguaje representa las cadenas donde el número de ${b's}$ está entre ${n}$ (igual que ${a's}$) y el **doble de** ${n}$. 

Ejemplos: ${aabb}$, ${aabbbb}$, ${aabbb}$.

**Estrategia:** Se mezclan dos gramáticas:

* $L_1 =$ { $a^n b^m \mid n = m$ } $\quad \Rightarrow \quad S \rightarrow aSb \mid \varepsilon$
* $L_2 =$ { $a^n b^m \mid m = 2n$ } $\quad \Rightarrow \quad S \rightarrow aSbb \mid \varepsilon$

**Gramática resultante:**

$$
S \rightarrow aSb \mid aSbb \mid \varepsilon
$$

Esta gramática permite generar cualquier combinación válida donde el número de ${b's}$ esté entre ${n}$ y ${2n}$, como se deseaba.

OTRO EJEMPLO: $L =$ { $a^n b^m \mid 2n \le m \le 5n$ }

Tomamos las GLC de los extremos:

* $L_1 =$ { $a^n b^m \mid m = 2n$ } $\quad \Rightarrow \quad S \rightarrow aSbb \mid \varepsilon$
  
* $L_2 =$ { $a^n b^m \mid m = 5n$ } $\quad \Rightarrow \quad S \rightarrow aSbbbbb \mid \varepsilon$

Se obtiene:

${
S \rightarrow aSbb \mid aSbbbbb \mid \varepsilon
}$

Además hay que considerar las ${b's}$ adicionales para todas las posibilidades entre ${2n}$ y ${5n}$. 

Usando adaptación:

$S \rightarrow aSBbb \mid aSbbbbb \mid \varepsilon$

$B \rightarrow b \mid bb \mid \varepsilon$

## 4. Concatenación de GLC's

**Objetivo**: Diseñar una gramática que genere el lenguaje

$${
L = \{ a^n b^m \mid n \ge m \}
}$$


Para lograr esto, se propone una **concatenación de GLC** a partir de dos lenguajes auxiliares:

* $L_1 = \{ a^n \mid n \in \mathbb{N} \}$, generado por: ${S_{1} \rightarrow aS_{1} \mid \varepsilon}$

* $L_2 = \{ a^n \mid n=m \}$, generado por: ${S_{2} \rightarrow aS_{2}b \mid \varepsilon}$

**Estrategia:** Para generar cadenas donde **hay más** ${a's}$ **que** ${b's}$, es decir, ${n > m}$, se concatenan dos lenguajes:

* Primero, un número arbitrario de ${a's}$ (${L_{1}}$), y
* Luego, una secuencia equilibrada de ${a's}$ y ${b's}$ (${L_{2}}$), de modo que la cantidad total de $a's$ supera la de $b's$.

**Resultado Final:** Así, la gramática completa es:

${
S \rightarrow S_{1}S_{2}
}$

Con:

${
S_{1} \rightarrow aS_{1} \mid \varepsilon}$

${S_{2} \rightarrow aS_{2}b \mid \varepsilon}$
