# Introducción

En esta asignatura, el objetivo no es solo estudiar las máquinas secuenciales como modelos matemáticos, sino también **aprender a modelarlos y manipularlos computacionalmente**. Para lograrlo, es fundamental construir primero una base sólida de estructuras de datos y operaciones abstractas.

Este trabajo práctico se enfoca en desarrollar un **AST (Abstract Syntax Tree)** genérico capaz de representar **cadenas, listas y conjuntos**, junto con sus operaciones. Aunque a primera vista pueda parecer un paso indirecto, en realidad es **una etapa clave** para abordar correctamente problemas más complejos en Teoría de la Computación.

# ¿Por qué es necesario aprender esto?

Los autómatas finitos, las gramáticas y muchos otros modelos formales se definen sobre estructuras como:

- Conjuntos (de estados, símbolos, transiciones)
- Secuencias (palabras, cadenas)
- Relaciones (transiciones)

Para poder implementarlos en una computadora, necesitamos:

- Representar estas estructuras de forma flexible
- Manipularlas de manera segura y consistente
- Separar la **representación** de la **lógica del modelo**

Este trabajo apunta justamente a eso: construir una base que permita luego implementar autómatas de manera clara, reutilizable y correcta.

---

# Beneficios de este enfoque

## 1. Separación de niveles

Se distingue claramente entre:

- **Nivel estructural (AST):** cómo se representan los datos
- **Nivel semántico (AF):** qué significan esos datos

Esto evita errores comunes y mejora la claridad del diseño.

---

## 2. Reutilización

Las operaciones implementadas (unión, intersección, producto cartesiano, etc.):

- No sirven solo para autómatas
- Son reutilizables en múltiples problemas

---

## 🔹 3. Base para algoritmos complejos

Muchos algoritmos de Teoría de la Computación requieren:

- Operaciones sobre conjuntos
- Construcción de nuevos estados (por ejemplo, en determinización)
- Transformaciones estructurales

Este trabajo prepara directamente para:

- AFND → AFD (construcción por subconjuntos)
- Simulación de autómatas
- Manipulación de lenguajes

---

## 4. Comprensión profunda

En lugar de usar estructuras predefinidas, los estudiantes:

- Implementan sus propias abstracciones
- Entienden cómo funcionan internamente
- Detectan y corrigen problemas reales (memoria, duplicados, aliasing)

---

## 5. Conexión con otras áreas

Este tipo de estructuras es ampliamente utilizado en:

- Compiladores (árboles sintácticos)
- Lenguajes funcionales (listas tipo Lisp)
- Sistemas simbólicos

---

# ¿Por qué en C?

Elegir C no es casual, tiene objetivos pedagógicos claros.

---

## 1. Control total sobre la memoria

En C, nos veremos forzados a :

- Manejar punteros explícitamente
- Reservar y liberar memoria
- Evitar errores como aliasing o fugas

Esto permite entender realmente cómo funcionan las estructuras dinámicas.

---

## 2. Comprensión real de estructuras de datos

Al no existir estructuras de alto nivel predefinidas:

- Las listas, conjuntos y árboles deben implementarse desde cero
- Se comprende su costo y comportamiento

---

## 3. Desarrollo de pensamiento abstracto

Aunque C es un lenguaje de bajo nivel, este trabajo exige:

- Diseñar un TAD
- Definir operaciones bien encapsuladas
- Separar implementación de uso

---

## 4. Preparación para sistemas complejos

El manejo de estructuras dinámicas en C es base para:

- Sistemas operativos
- Compiladores
- Software de alto rendimiento

---

## 5. Evitar “magia” de lenguajes de alto nivel

Lenguajes como Python o Java:

- Ocultan detalles importantes
- Permiten resolver problemas sin entender completamente las estructuras

En C, cada decisión es explícita, lo que fortalece el aprendizaje.

---


Este trabajo no trata solo de implementar estructuras, sino de:

- Construir una base sólida para modelar sistemas formales
- Entender cómo representar matemáticas en código
- **Desarrollar habilidades fundamentales en programación**

---


## AST para estructuras simbólicas (STR, LIST, SET)



Implementar en lenguaje C un **Tipo Abstracto de Datos (TAD)** basado en un **Árbol de Sintaxis Abstracta (AST)** capaz de representar y manipular:

- Cadenas (`STR`)
- Listas (`LIST`)
- Conjuntos (`SET`)

Este TAD será utilizado en trabajos prácticos posteriores para modelar autómatas finitos.

---

# Estructura base (obligatoria)

Se deberá trabajar exclusivamente con la siguiente estructura:

```c
#include "String.h"

#define STR 1
#define SET 2
#define LIST 3

struct dataType{
    int nodeType;   /* STR, SET, LIST */
    union{
        str string;
        struct{
            struct dataType* data;
            struct dataType* next;
        };
    };
};

typedef struct dataType* Tdata;
```

#### Consideraciones importantes ###
- Toda la manipulación debe realizarse utilizando Tdata
- Las estructuras deben ser dinámicas (uso de memoria heap)
- Se debe implementar copia profunda (deep copy) en todas las operaciones necesarias
- **No se deben implementar aún autómatas finitos**

### 1 . Implementar funciones de creación
``` c
create_str_ast()
create_list()
create_set()
```
### 2 . Operaciones sobre STR
Utilizando String.h.
- Comparación de strings
- Concatenación

### 3 Operaciones sobre LIST
``` c
append(Tdata* list, Tdata elem)
length(Tdata list)
copy_list(Tdata list) (copia profunda)
concat(Tdata l1, Tdata l2)
search(Tdata list, Tdata elem)
```

### 4 Operaciones sobre SET
``` c
insert_set(Tdata* set, Tdata elem) (sin duplicados)
belongs(Tdata set, Tdata elem)
remove_set(Tdata* set, Tdata elem)

#Operaciones algebraicas
union_set(Tdata A, Tdata B)
intersection_set(Tdata A, Tdata B)
difference_set(Tdata A, Tdata B)
subset(Tdata A, Tdata B)
equals_set(Tdata A, Tdata B)
```


### Casos de prueba

El programa debe incluir pruebas que verifiquen:

- Unión de conjuntos
- Intersección
- Producto cartesiano
- Conversión STR → LIST → STR
- Conjuntos vacíos
- Elementos duplicados
- Listas anidadas
- Copias vs referencias

## Entregables
- Código fuente completo en C
- Max. 3 integrantes por grupo 
- Para identificar los grupos: https://docs.google.com/spreadsheets/d/1bsH8A5VAkkm92EbAfjdgDioG7Z8UwCn2YFvAU-5cHjY/edit?usp=sharing
- **Fecha de Entraga Jueves 30 de Abril** 
