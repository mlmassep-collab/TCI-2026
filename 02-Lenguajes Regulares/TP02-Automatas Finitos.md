# Actividad 1 - Explorando Autómatas Finitos Deterministas
Tiempo estimado: 30 minutos

Considere los siguientes AFD:
<p align="center">
  <img src="img/TP_AF_AFD_01.png" width="400">
  <img src="img/TP_AF_AFD_02.png" width="300">
</p>


Para cada uno identifique:

> a - Conjunto de estados
> 
> b - Alfabeto
> 
> c - Estado inicial
> 
> d - Conjunto de estados de aceptación
> 
> e - Función de transición ${\delta}$ y tabla de transición

## Mini-desafío 1:

* Use el simulador https://automata-simulation.vercel.app/ para probar el funcionamiento de los autómatas de la Actividad 1.

* Conjeture sobre las cadenas aceptadas por cada autómata

## Formalización:

* Para cada *AFD* escriba una aplicación de ${\delta^*}$ 

* Escriba el lenguaje aceptado por cada *AFD*

# Actividad 2 - Construcción de Autómatas Finitos Deterministas

Tiempo estimado: 60 minutos

Describa los *AFD* que aceptan los siguientes lenguajes sobre el alfabeto ${\sigma=\{0,1\}}$

> a - El conjunto de todas las cadenas que terminan en 00.
>
> b - El conjunto de todas las cadenas que contienen al menos un 1.
>
> c - El conjunto de todas las cadenas con tres ceros consecutivos en cualquier posición.
>
> d - El conjunto de cadenas que contengan la subcadena 011.
>
> f - El conjunto de cadenas que contengan una cantidad par de 0’s e impar de 1’s.

## Mini-desafío 2:
Implemente un simulador simple de *AFD* en Python y úselo para probar sus diseños verificando la aceptación/rechazo de cadenas.

Ejemplo de estructura sugerida:

´´python
states = {"q0","q1","q2"}
alphabet = {"0","1"}

delta = {
("q0","0"):"q1",
("q0","1"):"q0",
("q1","0"):"q2",
("q1","1"):"q0",
("q2","0"):"q2",
("q2","1"):"q1"
}

initial = "q0"
accepting = {"q2"}

def run(w):
    state = initial
    for c in w:
        state = delta[(state,c)]
    return state in accepting
´´´
ppp
