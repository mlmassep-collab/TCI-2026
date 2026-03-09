# Trabajo Práctico Nº 2 – Máquinas Secuenciales

## Actividad 1: Autómatas Finitos vs Máquinas Secuenciales
Identifique las diferencias entre las Máquinas de Mealy y Moore. ¿Qué tipo de máquina puede relacionarse de manera directa con autómatas finitos? 

### Mini-desafío 1:
Considere el siguiente lenguaje: L = {w ∈ {0, 1, 2}* | λ = resto(val(w, 10), 5)}

* Diseñe una máquina de Moore y Mealy para L

* Implemente las máquinas en Python

* Generen los diagramas de transición

* Pruebe distintas cadenas para ambas máquinas

* Comparar las salidas con Mealy vs Moore

from graphviz import Digraph
from IPython.display import display

Código sugerido:

```python
class MS:

    def __init__(self, Q, sigma, delta, q0, salida, tipo="mealy"):
        self.Q = Q
        self.sigma = sigma
        self.delta = delta
        self.q0 = q0
        self.salida = salida
        self.tipo = tipo.lower()

    def procesar(self, w):
        estado = self.q0
        salida_total = []
        recorrido = []

        if self.tipo == "moore":
            salida_total.append(self.salida[estado])

        for a in w:

            estado2 = self.delta[(estado,a)]
            recorrido.append((estado,a,estado2))

            if self.tipo == "mealy":
                salida_total.append(self.salida[(estado,a)])

            estado = estado2

            if self.tipo == "moore":
                salida_total.append(self.salida[estado])

        return "".join(salida_total), recorrido


    def dibujar(self, w=None):

        salida = None
        recorrido = []

        if w:
            salida, recorrido = self.procesar(w)

        dot = Digraph()
        dot.attr(rankdir="LR")

        dot.node("inicio", shape="point")
        dot.edge("inicio", self.q0)

        for q in self.Q:

            if self.tipo == "moore":
                etiqueta = f"{q}/{self.salida[q]}"
            else:
                etiqueta = q

            dot.node(q, etiqueta)

        for (q,a), q2 in self.delta.items():

            if self.tipo == "mealy":
                etiqueta = f"{a}/{self.salida[(q,a)]}"
            else:
                etiqueta = a

            color = "black"
            penwidth = "1"

            for (r,sim,r2) in recorrido:
                if r == q and sim == a and r2 == q2:
                    color = "red"
                    penwidth = "3"

            dot.edge(q, q2, label=etiqueta, color=color, penwidth=penwidth)

        display(dot)

        if w:
            print("cadena:", w)
            print("salida:", salida)
```

## Actividad 2: Diseño de máquinas secuenciales
Para cada uno de los siguientes lenguajes defina una Máquina de Moore y una Máquina de Mealy. ¿Qué alfabeto de salida es conveniente usar?

> a - L = {w ∈ {a, m, r}\*| w = uTv, T = mar, u, v ∈ Σ\*}
>
> b - L = {w ∈ {e, o, p, s}\*| w = uT, T = peso, u ∈ Σ\*}
> 
> c - L = {w ∈ {o, s}\*| w = Tv, T = oso, u ∈ Σ\*}

### Mini-desafío 2: 
Compruebe sus diseño usando la calse MS de la Actividad 1
