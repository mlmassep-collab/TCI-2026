# Trabajo Práctico Nº 2.2 – Máquinas Secuenciales

## Actividad 1: Autómatas Finitos vs Máquinas Secuenciales
Tiempo: 15 minutos
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
Tiempo: 30 minutos
Para cada uno de los siguientes lenguajes defina una Máquina de Moore y una Máquina de Mealy. ¿Qué alfabeto de salida es conveniente usar?

> a - L = {w ∈ {a, m, r}\*| w = uTv, T = mar, u, v ∈ Σ\*}
>
> b - L = {w ∈ {e, o, p, s}\*| w = uT, T = peso, u ∈ Σ\*}
> 
> c - L = {w ∈ {o, s}\*| w = Tv, T = oso, u ∈ Σ\*}

### Mini-desafío 2: 
Compruebe sus diseño usando la calse MS de la Actividad 1

## Actividad 3: Minimización de Máquinas Secuenciales
Sí. Los lemas de minización describen  un algoritmo clásico de refinamiento de particiones por longitud de cadena (equivalencia ≡i). 
La idea es:
* Construir la partición inicial: estados distinguibles por salida.
* Refinar usando el Lema 2.
* Detenerse cuando Πi=Πi+1 usando el Lema 3.

> a - Enuncie los lemas de minimización. Recuerde que debe considerar las demostraciones de estos lemas para el examen final.
>
> b - Diseñe una *MMe* y *MMo* para los siguientes lenguajes:
> 
>> 1 - L = { w ∈ Σ\* | w = vu, v ∈ {sol, solo, oso, soso, soma, so, moso} ∧ u ∈ Σ\* }
>>
>> 2 - L = { w ∈ Σ\* | w=uv, v ∈ {rol,loro,oro,rolo,lomo,lo,moro}, u ∈ Σ\*}
>>
>>3 - L = { w ∈ Σ\* | w=uvt, v ∈ {aba,bab,cab,bca,caba,abac,bac}, u,t ∈ Σ\*}
>
> c - Minimice las máquinas.

### Mini-desafío 3: 
* Agregue a la clase MS la posibilidad de minimizar una MS.
* Pruebe sus diseños usando la calse MS y compruebe la corrección de la minimización aplicada.

```python
    def minimizar(self):

        # partición inicial Π0
        if self.tipo == "moore":

            grupos = {}
            for q in self.Q:
                s = self.salida[q]
                grupos.setdefault(s,set()).add(q)

            P = list(grupos.values())

        else:  # Mealy

            grupos = {}
            for q in self.Q:
                salidas = tuple(self.salida[(q,a)] for a in sorted(self.sigma))
                grupos.setdefault(salidas,set()).add(q)

            P = list(grupos.values())


        cambio = True

        while cambio:

            cambio = False
            nuevaP = []

            for grupo in P:

                firmas = {}

                for q in grupo:

                    firma = []

                    for a in sorted(self.sigma):

                        q2 = self.delta[(q,a)]

                        for i,g in enumerate(P):
                            if q2 in g:
                                firma.append(i)

                    firma = tuple(firma)

                    firmas.setdefault(firma,set()).add(q)

                nuevaP.extend(firmas.values())

                if len(firmas) > 1:
                    cambio = True

            P = nuevaP


        # construir máquina mínima

        representantes = {q: next(iter(g)) for g in P for q in g}

        Qm = {next(iter(g)) for g in P}

        delta_m = {}

        for g in P:

            r = next(iter(g))

            for a in self.sigma:

                q2 = self.delta[(r,a)]
                delta_m[(r,a)] = representantes[q2]


        if self.tipo == "moore":

            salida_m = {next(iter(g)): self.salida[next(iter(g))] for g in P}

        else:

            salida_m = {}

            for g in P:

                r = next(iter(g))

                for a in self.sigma:
                    salida_m[(r,a)] = self.salida[(r,a)]


        q0m = representantes[self.q0]

        return MS(Qm, self.sigma, delta_m, q0m, salida_m, self.tipo), P
```
