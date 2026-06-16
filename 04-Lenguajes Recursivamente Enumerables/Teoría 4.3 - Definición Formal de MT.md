# Máquina de Turing

La notación formal que vamos a emplear para una Máquina de Turing (MT) es similar a la utilizada para los autómatas finitos y los autómatas a pila.

Una MT se describe mediante la siguiente séptupla:

$$
M = (Q, \Sigma, \Gamma, \delta, q_0, B, F)
$$

donde sus componentes tienen el siguiente significado:

- $Q$: conjunto finito de estados de la unidad de control.

- $\Sigma$: conjunto finito de símbolos de entrada.

- $\Gamma$: conjunto completo de símbolos de la cinta. El alfabeto de entrada $\Sigma$ es siempre un subconjunto de $Gamma$.

- $\delta$: función de transición. Sus argumentos son un estado $q$ y un símbolo de cinta $a$.

Si está definida, el valor de la función es $\delta(q, X) = (p, Y, D)$

donde:

  1. $p$ es el siguiente estado de $Q$.
  2. $Y$ es el símbolo de $\Gamma$ que se escribe en la celda actual de la cinta, reemplazando al símbolo que se encontraba allí.
  3. $D$ indica la dirección de movimiento del cabezal:
     - $L$ ($Left$): una posición hacia la izquierda.
     - $R$ ($Right$): una posición hacia la derecha.

- $q_0$: estado inicial. Es un elemento de $Q$ en el que comienza la ejecución de la máquina.

- $B$: símbolo blanco (espacio en blanco). Pertenece a $\Gamma$ pero no a $\Sigma$. Inicialmente aparece en todas las celdas de la cinta excepto en aquellas que contienen la entrada.

- $F$: conjunto de estados finales o de aceptación. Es un subconjunto de $Q$.
