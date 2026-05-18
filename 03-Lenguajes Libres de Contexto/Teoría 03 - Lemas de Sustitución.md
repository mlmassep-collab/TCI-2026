## Lema 1: Sustituye producciones derivables en un paso desde una variable sintáctica

Sea ${G = (N, T, S, P)}$ una GLC. Sean:

* ${A \rightarrow \alpha_{1} B \alpha_{2}}$ una producción,
* ${B \rightarrow \beta_1 \mid \beta_{2} \mid \ldots \mid \beta_{n}}$ el conjunto de todas las producciones de ${B}$ en ${P}$.

Entonces, **es posible obtener efectivamente** una nueva gramática ${G_{1} = (N, T, S, P_{1})}$ a partir de ${G}$, reemplazando en $P$ la producción ${A \rightarrow \alpha_{1} B \alpha_{2}}$ por las producciones:

$${
A \rightarrow \alpha_{1} \beta_{1} \alpha_{2} \mid \alpha_1 \beta_{2} \alpha_{2} \mid \ldots \mid \alpha_{1} \beta_n \alpha_{2}
}$$

De esta manera, se cumple que:

$${
L(G) = L(G_{1})
}$$

**Interpretación**

Este lema afirma que si una producción de una variable ${A}$ contiene una variable intermedia ${B}$, se puede reemplazar directamente ${B}$ por todas sus producciones, obteniendo una nueva gramática que genera el mismo lenguaje. Esta técnica es útil para eliminar producciones intermedias y simplificar gramáticas.

## Lema 2: Quitar recursión por izquierda

Sea ${G = (N, T, S, P)}$ una GLC. Sean:

* ${A \rightarrow A\alpha_{1} \mid A\alpha_{2} \mid \ldots \mid A\alpha_{n}}$:
  El conjunto de todas las producciones de ${A}$ **con** recursión por la izquierda.

* ${A \rightarrow \beta_{1} \mid \beta_{2} \mid \ldots \mid \beta_{m}}$:
  El conjunto de producciones de ${A}$ **sin** recursión por izquierda.

Se puede construir efectivamente una nueva gramática

$${
G_1 = (N_{1}, T, S, P_{1})
}$$

donde:

* ${N_{1} = N \cup \{B\}}$ (con ${B \notin N}$ una nueva variable auxiliar)

Reemplazando las producciones de ${A}$ de la siguiente forma:

1.Para cada producción **sin** recursión por izquierda:

${A \rightarrow \beta_i}$

${A \rightarrow \beta_{i} B \quad \text{para } 1 \leq i \leq m}$

2.Para cada producción **con** recursión por izquierda:

${B \rightarrow \alpha_{i}}$

${B \rightarrow \alpha_{i} B \quad \text{para } 1 \leq i \leq n}$

Se cumple que:

$${
L(G) = L(G_1)
}$$

**Interpretación**

Este lema permite **transformar una gramática con recursión por izquierda** (que no es adecuada para algunos algoritmos como el de análisis LL en el desarrollo de compiladores) en una **gramática equivalente sin recursión por izquierda**, esta nueva gramática al ser equivalente a la original, genera el mismo lenguaje que la primera.
