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

${S \rightarrow aA \mid \varepsilon}$
