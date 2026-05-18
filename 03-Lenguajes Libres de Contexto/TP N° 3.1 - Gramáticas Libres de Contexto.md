# Trabajo Práctico Nº 3.1 – Gramáticas Libres de Contexto

## Actividad 1 - Exploración Experimental de Gramáticas Libres de Contexto

| G₁ | G₂ | G₃ | G₄ |
|---|---|---|---|
| S → aSb \| A<br>A → bAa \| ab \| ε | S → SS \| aSb \| ε | E → E + T \| T<br>T → T * F \| F<br>F → (E) \| a | S → aA \| bS \| ab<br>A → Sb \| aS \| bb |

Para cada una:

a - Genere manualmente al menos 10 cadenas distintas pertenecientes al lenguaje.

b - Clasifique los patrones observados:

> Símbolo terminal inicial.
> 
> Estructuras repetitivas.
>
> Balanceo entre símbolos.
>
> Concatenaciones.
>
> Restricciones aparentes sobre las cadenas generadas.

c - Proponga una descripción informal del lenguaje generado.

d - Realice el mini-desafío de programación para verificar experimentalmente su hipótesis.


### Mini-desafío 1:

Represente las gramáticas utilizando diccionarios:

```python
G1 = {
    "S": ["aSb", "A"],
    "A": ["bAa", "ab", ""]
}
```

Implemente una función:

```python
generate(grammar, symbol, depth)
```

que:

- reciba una gramática,
- genere cadenas derivables hasta cierta profundidad,
- muestre únicamente cadenas terminales.

Sugerencia:

- considerar mayúsculas como no terminales,
- considerar minúsculas y símbolos como terminales.

Finalmente:

- genere nuevas cadenas para cada gramática,
- compare los resultados con las cadenas construidas manualmente,
- verifique experimentalmente las hipótesis propuestas en los puntos anteriores.

### Formalización:

A partir de las observaciones realizadas y de los resultados obtenidos experimentalmente, formalice el lenguaje generado por la gramática.
