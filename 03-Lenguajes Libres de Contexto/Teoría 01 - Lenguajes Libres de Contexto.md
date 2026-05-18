Los **lenguajes libres de contexto** (LLC) son una clase fundamental dentro de la teoría de lenguajes formales, rama de la Teoría de lenguajes formales. Estos lenguajes se utilizan para describir estructuras jerárquicas o anidadas, como expresiones aritméticas, paréntesis balanceados o bloques sintácticos en lenguajes de programación, que no pueden ser capturadas por lenguajes regulares.

Una forma de definirlos es mediante **gramáticas libres de contexto**, en las que cada regla de producción reemplaza un único símbolo no terminal por una cadena de símbolos terminales y/o no terminales. Este tipo de reglas permite generar estructuras recursivas, lo que resulta esencial para modelar la sintaxis de muchos lenguajes formales y de programación.

De manera equivalente, los lenguajes libres de contexto también pueden describirse mediante modelos computacionales llamados **autómatas de pila**. Un Autómata con pila es una extensión de los autómatas finitos que incorpora una pila como estructura de memoria adicional. Esta pila permite almacenar información durante el procesamiento de la entrada, lo que resulta clave para reconocer patrones anidados.

La aceptación de una cadena por un autómata de pila puede darse de dos maneras:

* **Por estado final**: la cadena es aceptada si, al terminar de leer la entrada, el autómata se encuentra en un estado de aceptación.
* **Por pila vacía**: la cadena es aceptada si, al finalizar el procesamiento, la pila queda completamente vacía.

Ambas formas de aceptación son equivalentes en cuanto al poder expresivo del modelo.

Finalmente, una propiedad central de esta teoría es que los lenguajes libres de contexto coinciden exactamente con aquellos que pueden ser generados por gramáticas libres de contexto y, al mismo tiempo, reconocidos por autómatas de pila. Esta equivalencia los sitúa dentro de la Jerarquía de Chomsky, entre los lenguajes regulares y los lenguajes más generales como los sensibles al contexto.

