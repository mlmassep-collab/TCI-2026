# Trabajo Práctico N° 2.4 - Gramáticas Regulares

## Actividad 1: 

Dadas las siguientes GLC's

(a)  G = ({S, A, B}, {0,1}, S, P) donde P contiene las siguientes producciones:

```math
S \rightarrow 0A \mid \varepsilon
```

```math
A \rightarrow 10A \mid 10B
```

```math
B \rightarrow 0A \mid \varepsilon
```

(b) ( G = ({S, A, B}, {a,b}, S, P) ) donde P contiene las siguientes producciones:

```math
S \rightarrow aA \mid abB
```

```math
A \rightarrow aB \mid a
```

```math
B \rightarrow bbB \mid b
```

(c)  G = ({S, A, B}, {0,1}, S, P) donde P contiene las siguientes producciones:

```math
S \rightarrow 0S \mid 1A \mid \varepsilon
```

```math
A \rightarrow 0B \mid 1S
```

```math
B \rightarrow 0A \mid 1B
```

Se pide:

a) Derivar al menos 3 cadenas distintas.

b) Describir informalmente el lenguaje generado.

c) Proponer una expresión regular equivalente.

d) Construir el autómata finito correspondiente.

**Minidesafío de programación 1**

Usando una estructura como esta:

```python
#S → bA ∣ CB
#A → a
#B → BC ∣ AB
#C → aB
G=[
    {'S','A','B','C'},
    {'a','b'},
    'S',
    [['S','bA'],['S','CB'],['A','a'],['B','BC'],['B','AB'],['C','aB']]
]
G_1=lema3(G)
print(G_1)
```

a) Implementar en Python una función:


```python
genera_cadenas(gr, n)
```

que genere todas las cadenas de longitud menor o igual a n derivables desde la gramática.

b) Probar las GR's diseñadas en esta actividad.

## Actividad 2:

Especifique una gramática regular que genere los siguientes lenguajes y muestre para cada lenguaje derivaciones de al menos dos cadenas. Escriba la ER del lenguaje.

(a) Cadenas sobre el alfabeto *{x,y}* que comiencen o terminen con la secuencia *xy*.

(b) Cadenas sobre el alfabeto *{0,1}* que contengan cuatro *1’s* consecutivos (puede no tener 1’s sueltos, si los tiene, deben ser 4 consecutivos)

(c) Cadenas sobre el alfabeto *{a,b}* que contengan no más de tres *a’s* (no importa el orden).

(d) Cadenas sobre el alfabeto *{0,1,2,3,4,5,6,7,8,9,.,+,-}* que representen constantes reales con signo.

(e) Cadenas sobre el alfabeto *{0,1,2,3,4,5,6,7,8,9,:}* que representen una hora válida en el formato hh:mm de 24hs. (ejemplo 21:30 formato válido, 44:02 formato inválido)

**Para pensar:**
Cadenas sobre el alfabeto ({I, V, X, L, C, D, M}) que representen números romanos.
(Sugerencia, leer en esta página web las reglas de construcción:
[https://www.smartick.es/blog/matematicas/recursos-didacticos/los-numeros-romanos/](https://www.smartick.es/blog/matematicas/recursos-didacticos/los-numeros-romanos/))

## Actividad 3

Defina una gramática regular que genere el lenguaje definido por las siguientes expresiones regulares y muestre para cada lenguaje derivaciones de al menos dos cadenas.

(a) ${ aa^* \(ab + a\)^* }$

(b) ${ \(aab^* ab\)^* }$

(c) L = { $a^n b^m \mid n + m \text{ es impar}$ }

(d) L = { $w \in \Sigma^* \mid cant_a(w) + 3cant_b(w) \text{ es impar} $}

(e) L = { $w \in \Sigma^* \mid cant_a(w) \land cant_b(w) \text{ ambos son impares} $}
