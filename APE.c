#include <stdio.h>
#include <stdlib.h>

#define MAX_TITULO 30
#define MAX_DESCRIPCION 255

typedef struct evento{
    int anio;
    char titulo[MAX_TITULO];
    char descripcion[MAX_DESCRIPCION];
}Evento;

typedef struct nodo{
    Evento dato;
    struct nodo *sig;
}*Nodo;

void leerEvento(Evento *e){
    printf("INGRESE EL ANIO:\n");
    scanf("%d", &e->anio);
    printf("INGRESE EL TITULO:\n");
    scanf("%s", &e->titulo);
    printf("INGRESE UNA BREVE DESCRIPCION:\n");
    scanf("%s", &e->descripcion);
}

Nodo crearNodo(Evento e){
    Nodo nue = (Nodo)malloc(sizeof(struct nodo));
    nue->dato = e;
    nue->sig = NULL;
}

void insertarOrdenado(Nodo *l, Evento e){
    Nodo nue = crearNodo(e);
    Nodo act = (*l);
    Nodo ant = NULL;
    while ((act != NULL) && (e.anio > act->dato.anio)){
        ant = act;
        act = act->sig;
    }
    if (act == ant){
        (*l) = nue;
    }else  
        ant->sig = nue;
    nue->sig = act;
}

void crearLista(Nodo *l){
    Evento e;
    leerEvento(&e);
    while (e.anio != 1){
        insertarOrdenado(l, e);
        leerEvento(&e);
    }
    printf("| ------------------------------------- |\n");
    printf("| Se creo con exito la lista de eventos |\n");
    printf("| ------------------------------------- |\n");
}

void mostrarLista(Nodo lista){
    while (lista != NULL){
        printf("Anio: %d\n", lista->dato.anio);
        printf("Titulo: %s\n", lista->dato.titulo);
        printf("Descripcion: %s\n", lista->dato.descripcion);
        lista = lista->sig;
    }
}

void buscar(Nodo l, int *ok, int anio){
    Nodo act = l;
    while ((act != NULL) && (act->dato.anio != anio)){
        act = act->sig;
    }
    if ((act != NULL) && (act->dato.anio == anio))
        (*ok) = 1;
}

void eliminar(Nodo *l, int anio, int *ok){
    (*ok) = 0;
    Nodo act = (*l);
    Nodo ant = NULL;
    while ((act != NULL) && (act->dato.anio != anio)){
        ant = act;
        act = act->sig;
    }
    if ((act != NULL) && (act->dato.anio == anio)){
        Nodo A_eliminar = act;
        if (ant == NULL) {
            (*l) = act->sig;
        } else {
            ant->sig = act->sig;
        }
        free(A_eliminar);
        (*ok) = 1;
    }
}

void retornarLista(Nodo l1, Nodo *l2, int anio){
    if ((l1 != NULL) && (l1->dato.anio <= anio)){
            insertarOrdenado(l2, l1->dato);
            retornarLista(l1->sig, l2, anio);
    }
}


int main(){
    Nodo lista = NULL;
    int ok = 0;
    int anio;

    /* CREA LA LISTA DE EVENTOS */
    crearLista(&lista);
    printf("Ingrese el anio del evento que quieres buscar:\n");

    /* FUNCION PARA BUSCAR UN EVENTO DENTRO DE LA LISTA */
    scanf("%d", &anio);
    buscar(lista, &ok, anio);
    if (ok){
        printf("El evento se encuentra en la lista\n");
    }else
        printf("No se encontro el evento dentro de la lista\n");

    /* FUNCION PARA ELIMINAR UN EVENTO DE LA LISTA */
    printf("Ingrese el anio del evento que quieres eliminar:\n");
    scanf("%d", &anio);
    eliminar(&lista, anio, &ok);
    if (ok){
        printf("Se elimino el evento con el anio %d\n", anio);
    }else
        printf("No se pudo eliminar el evento con el anio %d\n", anio);
    
    /* FUNCION RECURSIVA PARA RETORNAR LA LISTA DE EVENTOS A PARTIR DE UN ANIO */
    Nodo listaAnio = NULL;
    printf("Lista filtrada hasta el año %d:\n", anio);
    scanf("%d", &anio);
    retornarLista(lista, &listaAnio, anio);

    /* FUNCION PARA IMPRIMIR LISTAS */
    mostrarLista(listaAnio);

    return 0;
}
