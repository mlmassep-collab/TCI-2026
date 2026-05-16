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
