# Práctica: TAD con Listas Enlazadas en C

En los siguientes ejercicios se solicita implementar **Tipos Abstractos de Datos (TAD)** utilizando **listas enlazadas simples** en lenguaje C.  
Cada TAD debe separar claramente:

- **definición del tipo**
- **operaciones del TAD**
- **gestión de memoria dinámica**

Todas las implementaciones deben garantizar que **la memoria reservada sea correctamente liberada**.

---

# Ejercicio 1 — TAD Lista de Enteros

Diseñar e implementar un **TAD ListaEnteros** utilizando una lista enlazada simple.

El TAD debe permitir almacenar números enteros.

Operaciones requeridas:

- crear lista vacía
- insertar un elemento al inicio
- insertar un elemento al final
- eliminar un valor
- buscar un valor
- obtener la longitud de la lista
- imprimir la lista
- liberar completamente la memoria utilizada



---

# Ejercicio 2 — TAD Pila de Enteros

Implementar un **TAD PilaEnteros** utilizando una lista enlazada.

La pila debe seguir el comportamiento **LIFO (Last In First Out)**.

Operaciones requeridas:

- crear pila
- apilar elemento
- desapilar elemento
- obtener el elemento del tope
- verificar si la pila está vacía
- liberar toda la memoria

Interfaz sugerida:
```
Pila* pila_crear();
void pila_push(Pila* pila, int valor);
int pila_pop(Pila* pila);
int pila_top(Pila* pila);
int pila_vacia(Pila* pila);
void pila_destruir(Pila* pila);
```
Cada operación que elimine nodos debe **liberar la memoria correspondiente**.


---


Cada operación que elimine nodos debe **liberar la memoria correspondiente**.

---
---
# Ejercicio 3 — TAD Cola de Enteros

Implementar un **TAD ColaEnteros** utilizando listas enlazadas.

La cola debe respetar el comportamiento **FIFO (First In First Out)**.

Operaciones requeridas:

- crear cola
- encolar elemento
- desencolar elemento
- obtener el primer elemento
- verificar si la cola está vacía
- liberar completamente la cola

Interfaz sugerida:
```
Cola* cola_crear();
void cola_encolar(Cola* cola, int valor);
int cola_desencolar(Cola* cola);
int cola_frente(Cola* cola);
int cola_vacia(Cola* cola);
void cola_destruir(Cola* cola);
```
---

# Ejercicio 4 — TAD Lista de Caracteres

Implementar un **TAD ListaCaracteres** basado en una lista enlazada.

El TAD debe permitir almacenar caracteres individuales.

Operaciones requeridas:

- crear lista
- insertar carácter al final
- eliminar un carácter
- buscar un carácter
- imprimir la lista
- liberar la memoria

Interfaz sugerida:
```
Cola* cola_crear();
void cola_encolar(Cola* cola, int valor);
int cola_desencolar(Cola* cola);
int cola_frente(Cola* cola);
int cola_vacia(Cola* cola);
void cola_destruir(Cola* cola);
```
---
---


# Ejercicio 5 — TAD Cadena como Lista Enlazada

Implementar un **TAD CadenaLista** que represente una cadena de caracteres usando una lista enlazada.

Cada nodo debe almacenar un carácter.

Operaciones requeridas:

- crear cadena vacía
- agregar carácter al final
- construir cadena a partir de un string
- eliminar todas las vocales
- imprimir la cadena
- liberar la memoria utilizada

Interfaz sugerida:
```
Cadena* cadena_crear();
void cadena_agregar(Cadena* cadena, char c);
void cadena_desde_string(Cadena* cadena, char* texto);
void cadena_eliminar_vocales(Cadena* cadena);
void cadena_imprimir(Cadena* cadena);
void cadena_destruir(Cadena* cadena);
```