# Trabajo Práctico Nº 3.2 – Simplificación de Gramáticas Libres de Contexto

## Actividad 1 - Eliminación de símbolos inútiles

Para cada una de las siguientes gramáticas:

1. Determinar los símbolos generadores.
2. Determinar los símbolos alcanzables.
3. Identificar los símbolos inútiles.
4. Obtener la gramática simplificada con la aplicación del Lema 3 y Lema 4 en ese orden.

| GLC 1                                                                      | GLC 2                                                             | GLC 3                                                                           | GLC 4                                                                               |
| -------------------------------------------------------------------------- | ----------------------------------------------------------------- | ------------------------------------------------------------------------------- | ----------------------------------------------------------------------------------- |
| $S \to AB \mid aA$<br>$A \to aA \mid a$<br>$B \to bB$<br>$C \to cC \mid c$ | $S \to aA \mid B$<br>$A \to aA \mid a$<br>$B \to bB$<br>$C \to c$ | $S \to AB \mid b$<br>$A \to aA \mid a$<br>$B \to CD$<br>$C \to c$<br>$D \to dD$ | $S \to AB \mid C$<br>$A \to a$<br>$B \to b$<br>$C \to D$<br>$D \to d$<br>$E \to eE$ |

### Mini-desafío de programación 1: 

**Objetivo**

Implementar los algoritmos de los lemas 3 y 4 de eliminación de símbolos inútiles

**Ejemplo de entrada**
```python
#S->aA | bBba
#A->aaA|a
#B->abB|abCa|ab
#C->aCb
G=[
    {'S','A','B','C'},
    {'a','b'},
    'S',
    [['S','aA'],['S','bBba'],['A','aaA'],['A','a'],['B','abB'],['B','abCa'],['B','ab'],['C','aCb']]
]
```

**Función auxiliar**
Función que determine si todos los símbolos de una cadena pertenecen a un conjunto dado.
```python
#considerar incluir en T el símbolo que se use para epsilon, por ejemplo e
def is_str(s, T):
    for c in s:
        if c not in T:
            return False
    return True
``` 
**Esqueleto del algoritmo**
```python
def lema3(G):
    N, T, S, P = G
    viejoN = set()
    nuevoN = set()

    # Primera pasada: A -> w con w ∈ T*
    for p in P:
        #completar

    # Iteración hasta punto fijo
    while (nuevoN != viejoN):
        ##compeltar

    #Construcción del nuevo conjunto de producciones
    nuevoP=[]
    for p in P:
        #compeltar

    # Devuelves la gramática modificada
    G = (nuevoN, T, S, nuevoP)
    return G
```
**Ejeplo de uso**
```python
G_1=lema3(G)
print(G_1)
```
**Salida esperada**
```python
({'B', 'S', 'A'}, {'a', 'b'}, 'S', [['S', 'aA'], ['S', 'bBba'], ['A', 'aaA'], ['A', 'a'], ['B', 'abB'], ['B', 'ab']])
```

## Actividad 2 — Eliminación de producciones ε

Para cada una de las siguientes gramáticas:

1. Determinar las variables anulables.
2. Eliminar las producciones ε.
3. Obtener una gramática equivalente sin producciones ε.

| GLC 1                                                                 | GLC 2                                                                                  | GLC 3                                                                                  | GLC 4                                                                                              |
| --------------------------------------------------------------------- | -------------------------------------------------------------------------------------- | -------------------------------------------------------------------------------------- | -------------------------------------------------------------------------------------------------- |
| $S \to AB \mid a$<br>$A \to aA \mid \varepsilon$<br>$B \to bB \mid b$ | $S \to ABC$<br>$A \to aA \mid \varepsilon$<br>$B \to bB \mid \varepsilon$<br>$C \to c$ | $S \to ASA \mid aB$<br>$A \to B \mid S \mid \varepsilon$<br>$B \to b \mid \varepsilon$ | $S \to aA \mid B \mid \varepsilon$<br>$A \to aS \mid B$<br>$B \to C$<br>$C \to c \mid \varepsilon$ |

### Mini-desafío de programación 2:

Implementar en un lenguaje de programación un algoritmo que elimine producciones ε de una GLC.

## Actividad 3 — Eliminación de producciones unitarias

Para cada una de las siguientes gramáticas:

1. Identificar las producciones unitarias.
2. Eliminar las producciones unitarias.
3. Obtener una gramática equivalente sin producciones unitarias.

| GLC 1                                                          | GLC 2                                                                        | GLC 3                                                                 | GLC 4                                                                                           |
| -------------------------------------------------------------- | ---------------------------------------------------------------------------- | --------------------------------------------------------------------- | ----------------------------------------------------------------------------------------------- |
| $S \to A \mid b$<br>$A \to B$<br>$B \to C$<br>$C \to c \mid d$ | $S \to A \mid B$<br>$A \to aA \mid a$<br>$B \to C$<br>$C \to D$<br>$D \to d$ | $S \to A \mid b$<br>$A \to B \mid a$<br>$B \to C$<br>$C \to A \mid c$ | $S \to AB \mid C$<br>$A \to aA \mid \varepsilon$<br>$B \to bB \mid b$<br>$C \to D$<br>$D \to d$ |

**IMPORTANTE:**

Al eliminar ε-producciones, se debe preservar el lenguaje generado por la gramática.
En particular, si el símbolo inicial $S$ es anulable, es decir, si $S \Rightarrow^* \varepsilon$, entonces la producción $S \to \varepsilon$ debe conservarse (o incorporarse explícitamente en la gramática simplificada), ya que el lenguaje original contiene a la cadena vacía.

En cambio, para los demás no terminales, las ε-producciones deben eliminarse durante el proceso de simplificación.

En este trabajo práctico se adoptará la convención habitual de permitir una única ε-producción únicamente para el símbolo inicial, siempre que $\varepsilon \in L(G)$.

### Mini-desafío de programación 3:

Implementar en un lenguaje de programación un algoritmo que elimine producciones unitarias de una GLC.

## Ejercicio 4 — Simplificación completa de GLC

Para cada una de las siguientes gramáticas:

1. Eliminar producciones ε.
2. Eliminar producciones unitarias.
3. Eliminar símbolos inútiles (generadores - inalcanzables)
4. Obtener la gramática completamente simplificada.
5. Comparar la cantidad de variables y producciones antes y después de la simplificación.

| GLC 1                                                                                                         | GLC 2                                                                                                            | GLC 3                                                                                                                            | GLC 4                                                                                                                                     |
| ------------------------------------------------------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------------- | -------------------------------------------------------------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------- |
| $S \to AB \mid C$<br>$A \to aA \mid \varepsilon$<br>$B \to bB \mid b$<br>$C \to D$<br>$D \to d$<br>$E \to eE$ | $S \to aA \mid B \mid \varepsilon$<br>$A \to aS \mid B$<br>$B \to C$<br>$C \to c \mid \varepsilon$<br>$D \to dD$ | $S \to AB \mid BC \mid a$<br>$A \to BA \mid \varepsilon$<br>$B \to CC \mid b \mid A$<br>$C \to cC \mid \varepsilon$<br>$D \to d$ | $S \to AB \mid aA \mid C$<br>$A \to aA \mid \varepsilon$<br>$B \to bB \mid B \mid b$<br>$C \to D$<br>$D \to E$<br>$E \to e$<br>$F \to fF$ |

### Mini-desafío de programación 4:

Implementar en un lenguaje de programación un algoritmo completo de simplificación de GLC.

