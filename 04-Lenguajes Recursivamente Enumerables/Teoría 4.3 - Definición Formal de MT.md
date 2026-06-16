# Máquina de Turing

La notación formal que vamos a emplear para una Máquina de Turing ($MT$) es similar a la utilizada para los autómatas finitos y los autómatas a pila.

Una $MT$ se describe mediante la siguiente séptupla:

$$
M = (Q, \Sigma, \Gamma, \delta, q_0, B, F)
$$

donde sus componentes tienen el siguiente significado:

- $Q$: conjunto finito de estados de la unidad de control.

- $\Sigma$: conjunto finito de símbolos de entrada.

- $\Gamma$: conjunto completo de símbolos de la cinta. El alfabeto de entrada $\Sigma$ es siempre un subconjunto de $\Gamma$.

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

## Configuración de una Máquina de Turing

En una configuración, se muestran las casillas de la cinta comprendidas entre el símbolo más a la izquierda y el símbolo más a la derecha que no sean espacios en blanco. Cuando se dé la condición especial de que la cabeza está señalando a uno de los espacios en blanco que hay antes o después de la cadena de entrada, también tendremos que incluir en la configuración un número finito de espacios en blanco.

Además de representar la cinta, tenemos que representar la unidad de control y la posición de la cabeza de la cinta. Para ello, incluimos el estado en la cinta y lo situamos inmediatamente a la izquierda de la casilla señalada. Para que la cadena que representa el estado de la cinta no sea ambigua, tenemos que asegurarnos de que no utilizamos como estado cualquier símbolo que sea también un símbolo de cinta. Sin embargo, es fácil cambiar los nombres de los estados, de modo que no tengan nada en común con los símbolos de cinta, ya que el funcionamiento de la MT no depende de cómo se llamen los estados. Por tanto, utilizaremos la cadena:

$$X_1 X_2 · · · X_{i−1} \mathbf{q} X_i X_{i+1} · · · X_n$$

para representar una configuración en la que:

1. q es el estado en el que se encuentra la máquina de Turing.
2. El cabezal está señalando al i-ésimo símbolo empezando por la izquierda.
3. $X_1 X_2 · · · X_n$ es la parte de la cinta comprendida entre los símbolos distintos del espacio en blanco más a la izquierda y más a la derecha.
