## Gramáticas Libres de Contexto
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
