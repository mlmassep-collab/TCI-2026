#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ====== STRING SIMPLE : Esto deberìa estar en String.h*/
typedef char* str;

str load2(const char* s){
    str r = (str)malloc(strlen(s)+1);
    strcpy(r, s);
    return r;
}

void print_string(str s){
    printf("%s", s);
}

/* TIPOS  */
#define STR 1
#define SET 2
#define LIST 3

typedef struct dataType{
    int nodeType;

    union{
        str string;

        struct{
            struct dataType* data;
            struct dataType* next;
        };
    };

} *Tdata;

/* CREACION */

Tdata create_str_ast(){
    Tdata n = (Tdata)malloc(sizeof(struct dataType));
    n->nodeType = STR;
    n->string = NULL;
    return n;
}

Tdata create_set(){
    Tdata n = (Tdata)malloc(sizeof(struct dataType));
    n->nodeType = SET;
    n->data = NULL;
    n->next = NULL;
    return n;
}

Tdata create_list(){
    Tdata n = (Tdata)malloc(sizeof(struct dataType));
    n->nodeType = LIST;
    n->data = NULL;
    n->next = NULL;
    return n;
}

/* DEEP COPY */

Tdata clone(Tdata n){
    if(n == NULL) return NULL;

    Tdata nuevo = NULL;

    if(n->nodeType == STR){
        nuevo = create_str_ast();
        nuevo->string = load2(n->string);
    }

    else if(n->nodeType == SET || n->nodeType == LIST){
        nuevo = (n->nodeType == SET) ? create_set() : create_list();

        Tdata aux = n;
        Tdata head = NULL;
        Tdata tail = NULL;

        while(aux != NULL){
            Tdata nodo_lista = create_set();  // nodo contenedor

            nodo_lista->data = clone(aux->data);
            nodo_lista->next = NULL;

            if(head == NULL){
                head = nodo_lista;
                tail = nodo_lista;
            } else {
                tail->next = nodo_lista;
                tail = nodo_lista;
            }

            aux = aux->next;
        }

        return head;
    }

    return nuevo;
}

/* =APPEND */

void append_set(Tdata *A, Tdata e){
    Tdata nuevo = create_set();

    nuevo->data = clone(e);
    nuevo->next = NULL;

    if(*A == NULL){
        *A = nuevo;
    } else {
        Tdata aux = *A;
        while(aux->next != NULL){
            aux = aux->next;
        }
        aux->next = nuevo;
    }
}


/* print */

void printSet(Tdata A){
    if(A == NULL){
        printf("{}");
        return;
    }

    printf("{ ");

    Tdata aux = A;

    while(aux != NULL){

        if(aux->data != NULL){

            if(aux->data->nodeType == STR){
                print_string(aux->data->string);
            }

            else if(aux->data->nodeType == SET){
                printSet(aux->data);  
            }

            else if(aux->data->nodeType == LIST){
                printf("[LIST]");
            }

            if(aux->next != NULL)
                printf(", ");
        }

        aux = aux->next;
    }

    printf(" }");
}

/* ====== MAIN ====== */

int main(){
    Tdata A = NULL;
    Tdata B = NULL;

    Tdata l = NULL;

    /* A = {"hola", "mundo"} */
    Tdata s1 = create_str_ast();
    s1->string = load2("hola");

    Tdata s2 = create_str_ast();
    s2->string = load2("mundo");

    append_set(&A, s1);
    append_set(&A, s2);


    append_list(&l, s1);    

    /* B = {"palabra", {A}} */
    Tdata s3 = create_str_ast();
    s3->string = load2("palabra");

    append_set(&B, s3);
    append_set(&B, A);   // 

    printf("A = ");
    printSet(A);

    printf("\nB = ");
    printSet(B);

    printf("\n");

    return 0;
}
