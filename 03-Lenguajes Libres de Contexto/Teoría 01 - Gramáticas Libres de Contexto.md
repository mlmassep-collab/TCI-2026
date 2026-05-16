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
