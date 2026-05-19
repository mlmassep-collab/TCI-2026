# Trabajo Práctico Nº 3.1 – Gramáticas Libres de Contexto

## Actividad 1 - Exploración Experimental de Gramáticas Libres de Contexto

| G₁ | G₂ | G₃ | G₄ |
|---|---|---|---|
| S → aSb \| A<br>A → bAa \| ab \| ε | S → SS \| aSb \| ε | E → E + T \| T<br>T → T * F \| F<br>F → (E) \| a | S → aA \| bS \| ab<br>A → Sb \| aS \| bb |

Para cada una:

a) $\quad$  Genere manualmente al menos 10 cadenas distintas pertenecientes al lenguaje.

b) $\quad$  Clasifique los patrones observados:

> Símbolo terminal inicial.
> 
> Estructuras repetitivas.
>
> Balanceo entre símbolos.
>
> Concatenaciones.
>
> Restricciones aparentes sobre las cadenas generadas.

c) $\quad$ Proponga una descripción informal del lenguaje generado.

d) $\quad$ Realice el mini-desafío de programación para verificar experimentalmente su hipótesis.


### Mini-desafío 1:

a) $\quad$ Represente las gramáticas utilizando diccionarios:

```python
G1 = {
    "S": ["aSb", "A"],
    "A": ["bAa", "ab", ""]
}
```

b) $\quad$ Implemente una función:

```python
generate(grammar, symbol, depth)
```

que realice las siguientes tareas (las minúsculas son símbolos terminale sy la smayúsculas variables sintácticas):

- Reciba una gramática,
- Genere cadenas derivables hasta cierta profundidad,
- Muestre únicamente cadenas terminales.

c) $\quad$ Finalmente:

- Genere nuevas cadenas para cada gramática,
- Compare los resultados con las cadenas construidas manualmente,
- Verifique experimentalmente las hipótesis propuestas en los puntos anteriores.

### Formalización:

A partir de las observaciones realizadas y de los resultados obtenidos experimentalmente, formalice el lenguaje generado por la gramática.

## Actividad 2 — Diseño de Gramáticas Libres de Contexto

Para cada uno de los siguientes lenguajes:

a) $\quad$ Analice la estructura del lenguaje: 

> ¿Cuál es el caso base?
> 
> ¿Cómo crece el lenguaje?
> 
> ¿Qué parte se repite?
>
> ¿Qué mantiene el balance o la restricción del lenguaje?

b) $\quad$ Construya una Gramática Libre de Contexto que genere el lenguaje. Use las estrategia de diseño propuestas por Brena.

c) $\quad$ Con cada GLC realice para dos cadenas distintas una derivación por izquierda y una derivación por derecha,
  
d) $\quad$ Dibuje los árboles de derivación correspondientes.

e) $\quad$  Genere manualmente al menos 5 cadenas adicionales para verificar experimentalmente que la gramática produce únicamente cadenas válidas.

f) $\quad$  Indique si la gramática diseñada podría ser ambigua. Justifique brevemente.

### Lenguajes
#### A — Lenguajes con simetría y recursión envolvente

$\text{A.1} \quad L =$ { $w \in$ { $a,b$ } $^* \mid w = w^R$ }

$\text{A.2} \quad L =$ { $w \in \{(,)\}^* \mid w \text{ posee paréntesis balanceados}$ }

$\text{A.3} \quad L =$ { $a^n b^m a^n \mid n \geq 1 \land m = 2k$ }

#### B — Lenguajes con restricciones numéricas

$\text{B.1} \quad L =$ { $w \in$ { $a,b$ } $^* \mid n_a(w) = 2n_b(w)$ }

$\text{B.2} \quad L =$ { $a^n b^m \mid n = 2m + 1$ }

$\text{B.3} \quad L =$ { $a^n b^m \mid n \leq m + 3$ }

$\text{B.4} \quad L =$ { $a^n b^m \mid 2n \leq m \leq 3n$ }

#### C — Lenguajes por descomposición o combinación de casos

$\text{C.1} \quad L =$ { $a^n b^m \mid n \neq 2m$ }

$\text{C.2} \quad L =$ { $w \in \{a,b\}^* \mid n_a(w) \neq n_b(w)$ }
