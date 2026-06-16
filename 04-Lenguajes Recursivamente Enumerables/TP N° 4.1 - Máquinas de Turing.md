# Trabajo Práctico N° 4 - Máquinas de Turing

Para cada una de los siguientes problemas realice:

a- Idea general de la solución

b- Solución

c- Explicación del propósito de cada estado

d- Computación de un cadena

## Actividad 1 – Operaciones simples sobre cadenas

Problema 1.1: Calcular el complemento a $1$ de un número binario, es decir invertir los bits de entrada. Si la entrada es $11001$ la salida debe ser $00110$.

Problema 1.2: Obtener el sucesor de un número en codificación unaria. Considerar en la codificación unaria que el $0$ se representa por la cadena vacía, el $1$ por $1$, el $2$ por $11$, etc. Si la entrada es $1111$ la salida debe ser $11111$.

Problema 1.3: Duplicar la cadena de entrada sobre el alfabeto ${a,b}$. Si la entrada es $abba$ la salida debe ser $abbaabba$.

Problema 1.4: Eliminar todas las ocurrencias de los $0's$ de unsa secuencia de bits. Si la entrada es $001011$, la salida debe ser $111$.

Problema 1.5: Para cadena sobre el alfabeto ${x,y}$, reemplazar cada símbolo $x$ por la secuencia $xy$. Si la entrada es $xxyxy$ la salida debe ser $xyxyyxyy$.

## Actividad 2 — Cálculo y manipulación numérica

Problema 2.1: Calcular el sucesor de un número binario.

Problema 2.2: Calcular el antecesor de un número binario.

Problema 2.3: Calcular $m+n$ donde $m$ y $n$ son números unarios. La entrada tiene el formato $1^n01^m$. No perder la entrada, separar el resultado con el símbolo $0$. Si la entrada es $11101111$, la salida debe ser $1110111101111111$. 

Problema 2.4: Calcular $m*n$ donde $m$ y $n$ son números unarios. La entrada tiene el formato $1^n01^m$. No perder la entrada, separar el resultado con el símbolo $0$. Si la entrada es $110111$, la salida debe ser $1101110111111$. 

Problema 2.5: Para cadenas de la forma $w = 0^m10^n$, calcular la sustracción binaria propia, $m − n$ si $m > n$ o $0$ en el caso contrario. Si la entrdada es $11110111$ la salida debe ser $1111011101$

## Actividad 3 — Reconocimiento de lenguajes

Problema 3.1: Aceptar cadenas del lenguaje $L=${ $0^n1^m0^n \mid n>0$ }

Problema 3.2: Aceptar cadenas del lenguaje $L=$ { $ww^R \mid w\in$ { $0,1$ } $^{*}$ }

Problema 3.3: Aceptar cadenas del lenguaje $L=$ { $w \in$ { $0,1$ } $^{*} \mid cant_0(w)=cant_1(w)$ }

## Actividad 4 — Desafío

Problema 4.1: Ordenar una cadena formada por ${0,1}$ colocando primero todos los $0$ y luego todos los $1$.

Problema 4.2: Determinar si un número binario representa una potencia de 2.

Problema 4.3: Aceptar cadenas del lenguaje $L=$ { $a^n b^m c^{n+m} \mid n,m>0$ }
