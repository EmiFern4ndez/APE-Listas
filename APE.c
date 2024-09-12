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
    if (e->anio != 1){
        printf("INGRESE EL TITULO:\n");
        scanf(" %s", e->titulo);
        printf("INGRESE UNA BREVE DESCRIPCION:\n");
        scanf(" %s", e->descripcion);
    }  
}

Nodo crearNodo(Evento e){
    Nodo nue = (Nodo)malloc(sizeof(struct nodo));
    nue->dato = e;
    nue->sig = NULL;
    return nue;
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
    printf("----------------------------------------- \n");
    printf("| Se creo con exito la lista de eventos | \n");
    printf("----------------------------------------- \n \n");
}

void mostrarLista(Nodo lista){
    while (lista != NULL){
        printf("------------\n");
        printf(" Anio: %d\n", lista->dato.anio);
        printf(" Titulo: %s\n", lista->dato.titulo);
        printf(" Descripcion: %s\n", lista->dato.descripcion);
        printf("------------\n");
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

void menu(Nodo *lista, Nodo *listaAnio){
    int opcion;
    int anio;
    int ok = 0;
    do{
        printf("  --- MENU ---  \n1.BUSCAR EVENTO\n2.ELIMINAR EVENTO\n3.FILTRAR POR ANIO\n4.SALIR\n \n");
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:
            /* FUNCION PARA BUSCAR UN EVENTO DENTRO DE LA LISTA */
            printf("\nIngrese el anio del evento que quieres buscar:\n");
            scanf("%d", &anio);
            buscar(*lista, &ok, anio);
            if (ok){
                printf("\nEl evento se encuentra en la lista\n \n");
            }else
                printf("\nNo se encontro el evento dentro de la lista\n \n");
            break;

        case 2:
            /* FUNCION PARA ELIMINAR UN EVENTO DE LA LISTA */
            printf("\nIngrese el anio del evento que quieres eliminar:\n");
            scanf("%d", &anio);
            eliminar(lista, anio, &ok);
            if (ok){
            printf("\nSe elimino el evento con el anio %d\n \n", anio);
            }else
                printf("\nNo se pudo eliminar el evento con el anio %d\n \n", anio);
            break;

        case 3:
            /* FUNCION RECURSIVA PARA RETORNAR LA LISTA DE EVENTOS A PARTIR DE UN ANIO */
            printf("\nIngrese el anio por el que quieres filtrar:\n");
            scanf("%d", &anio);
            retornarLista(*lista, listaAnio, anio);
            /* FUNCION PARA IMPRIMIR LISTAS */
            mostrarLista(*listaAnio);
            break;
        
        default:
            printf("\nOpcion no disponible\n");
            break;
        }
    } while (opcion != 4);
}

int main(){
    Nodo lista = NULL;
    Nodo listaAnio = NULL;

    /* CREA LA LISTA DE EVENTOS */
    crearLista(&lista);

    /* MENU DE OPCIONES */
    menu(&lista, &listaAnio);
    return 0;
}
