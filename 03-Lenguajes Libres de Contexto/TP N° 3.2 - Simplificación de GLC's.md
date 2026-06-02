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

Función que determine si todos los símbolos de una cadena pertenecen a un conjunto dado. Sirve por ejemplo para determinar si una cadena de símbolos está compuesta solo por terminales, o solo por variables sintácticas.

```python
#considerar incluir en T el símbolo que se use para epsilon, por ejemplo e
def is_str(s, T):
    for c in s:
        if c not in T:
            return False
    return True
``` 
**Esqueleto del algoritmo Lema 3 (El algoritmo de Lema 4 se implementa análogamente)**
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

**Ejemplo de estructura**

Aquí se propone el uso de un diccionario, a diferencia de la propuesta anterior que usa una lista de pares ordenados

```python
P = {
    'S': {'bA', 'aC','ε'},
    'A': {'ε'},
    'B': {'BC', 'AD', 'a'},
    'C': {'aB'},
    'D': {'aD','ε'}
}
G = [
    {'S','A','B', 'C','D'},
    {'a','b'},
    'S',
    P
]
```

**Generador de todas las combinaciones de alphas con símbolos anulados**

DE: una producción `alpha` y el conjunto de variables no anulables `NVA`.

Idea: cada posición asociada a una variable anulable puede tomar los valores 0 (conservar) o 1 (eliminar), mientras que los símbolos terminales y las variables no anulables permanecen fijos y se representan mediante el valor 2. La función recorre sistemáticamente todas las configuraciones posibles de las posiciones anulables mediante un mecanismo equivalente a un contador binario. Por ejemplo, para tres posiciones anulables se generan sucesivamente las configuraciones 000, 001, 010, 011, 100, 101, 110 y 111, donde 0 indica conservar el símbolo y 1 indica eliminarlo. Cada configuración produce una nueva cadena derivada de `alpha`.

DS: devuelve el conjunto de todas las producciones distintas obtenidas a partir de `alpha` mediante la eliminación de cualquier subconjunto de variables anulables, excluyendo la cadena vacía.

```python
def alpha_anul(alpha,NVA):
  if (alpha=='ε'):
    return set()
  else:
    lista = list(alpha)
    #marcar con 2 los símbolos no anulables
    marcas = [2 if c in NVA else 0 for c in alpha]
    rta=set()
    terminar=False
    while not terminar:
      j=len(lista)-1
      continuar=True
      while j>=0 and continuar:
        if marcas[j]==2: #ignorar los símbolos no anulables
          j = j - 1
        else:
          if marcas[j]==0:
            marcas[j]=1
            continuar=False
          elif marcas [j]==1:
            while j>=0 and marcas[j]>=1:
              if marcas[j]==1: marcas[j]=0
              j = j-1
            if j>=0:
              marcas[j]=1
            else:
              terminar=True
            continuar=False
      #concatenar los símbolos marcados con 2 (no anulables) con los
      #no anulados aquellos que tienen asignada la marca 0. 
      resultado = ''.join(
      lista[i]
      for i in range(len(lista))
      if marcas[i] == 0 or marcas[i]== 2
      )
      if resultado != "": #No todos los símbolos se anulan en simultáneo
        rta.add(resultado)
    return rta
```

**Estructura del programa**
```python
#usar algún carcater para epsilon. Puede ser 'e' o 'ε'. EL SÍMBOLO QUE SE ELIJA NO PUEDE SER CARACTER DE ENTRADA.
def quitar_pe(G):
  N, T, S, P = G

  VA=set()
  #detectar variables anulables directas
  for A in N:
    for alpha in P[A]:
        #completar

  #detectar variables anulables indirectas
  cambio=True
  while cambio:
    cambio=False
    for A in N:
      for alpha in P[A]:
        #completar

  #armar nuevas producciones
  nuevoP={}
  nuevoN=set()
  anulable = VA | {'ε'}
  fijos = T | (N-VA)
  for A in P:
    for alpha in P[A]:
      if any(symbol in anulable for symbol in alpha):
        #aquí hay que anular de a un símbolo de alpha

        #completar
        
      else:
        #aqui ningún símbolo es anulabe, alpha no cambia

  #verificar si el lenguaje contiene 'ε' para agregarlo de nuevo
  if S in VA:
    if S not in nuevoP:
        nuevoP[S] = set()
    nuevoP[S].add('ε')
  G = (nuevoN, T, S, nuevoP)
  return G,VA
```

**Ejemplo de uso**
```python
N,T,S,P = G
for A in P:
  print(A,P[A])
G_1,VA=quitar_pe(G)
N1,T1,S1,P1 = G_1
print("")
print("simplificacion")
print("VA=",VA)
print("N=",N1)
print("T=",T1)
print("S=",S1)
for A in P1:
  print(A,P1[A])
```

**Salida esperada**
```python
S {'bA', 'ε', 'aC'}
A {'ε'}
B {'AD', 'BC', 'a'}
C {'aB'}
D {'aD', 'ε'}

simplificacion
VA= {'D', 'S', 'B', 'A'}
N= {'B', 'S', 'C', 'D'}
T= {'b', 'a'}
S= S
S {'bA', 'b', 'ε', 'aC'}
B {'C', 'BC', 'a', 'A', 'AD', 'D'}
C {'aB', 'a'}
D {'aD', 'a'}
```

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

