# Símbolos útiles e inútiles

Dada una GLC $G = (V, T, S, P)$:

Un **símbolo $X$** (en general una variable no terminal) es **útil** si existe una derivación:

  $$
  S \Rightarrow^* \alpha X \beta \Rightarrow^* w
  $$

  con:  $\alpha, \beta$: formas sentenciales y $w \in T^*$: una cadena terminal.

En cualquier otro caso, el símbolo $X$ es considerado **inútil**.

**Criterios para determinar si $X$ es útil:**

1. **Generatividad (Lema 3):**
   Desde $X$, se puede derivar alguna cadena terminal:

$$
X \Rightarrow^* w \quad \text{con } w \in T^*
$$

2. **Accesibilidad (Lema 4):**
   $X$ aparece en alguna forma sentencial derivada desde el símbolo inicial $S$:

$$
S \Rightarrow^* \alpha X \beta
$$

Para que un símbolo $X$ sea **útil**, **debe cumplir ambos criterios**: ser **accesible** desde el símbolo inicial y **generar** una cadena terminal.

## Lema 3: Quitar variables no generadoras

Sea ${G = (N, T, S, P)}$ una GLC, con ${L(G) \neq \emptyset}$, es posible obtener efectivamente una *GLC* ${G_{1} = (N_{1}, T, S, P_{1})}$ a partir de ${G}$ done:

$${\forall A \in N_{1}, \exists w \in T^* \text{ tal que } A \Rightarrow^* w}$$

**Algoritmo:**

```text
lema3(G):
1. Sea G = (N, T, S, P)
2. viejoN = ∅
3. nuevoN = { A ∈ N | ∃ A → w, w ∈ T* }
4. mientras (viejoN ≠ nuevoN):
    4.1 viejoN = nuevoN
    4.2 nuevoN = viejoN ∪ { A ∈ N | ∃ A → w, w ∈ (T ∪ viejoN)* }
5. nuevoP = ∅
6. Para cada A ∈ nuevoN:
    6.1 Sea p = A → α₁ | α₂ | ... | αₙ
    6.2 Para cada αᵢ en p:
        Si αᵢ ∈ (T ∪ nuevoN)* entonces:
            nuevoP = nuevoP ∪ { A → αᵢ }
7. Contestar:
   G₁ = (nuevoN, T, S, nuevoP)
```

