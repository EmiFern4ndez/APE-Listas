#LISTA DE EVENTOS HISTÓRICOS

## Resumen

Se solicita un programa que permita gestionar una lista de eventos históricos. El objetivo es ayudar a un historiador de la comarca a registrar, buscar, eliminar y filtrar eventos históricos de manera eficiente. Los eventos se ordenan cronológicamente (orden ascendente) y se proporciona una funcionalidad adicional para recuperar eventos ocurridos hasta un año específico utilizando recursión.

### Funcionalidades Principales

- Inserción de eventos: Permite agregar un nuevo evento en la lista, garantizando que la lista mantenga el orden cronológico (de menor a mayor año).

- Eliminación de eventos: Permite eliminar un evento específico de la lista basado en el año del evento.

- Búsqueda de eventos: Permite buscar eventos basados en un año específico. Si hay múltiples eventos en el mismo año, se muestran todos.

- Filtrado recursivo por año: Dada una lista de eventos ordenados cronológicamente, permite filtrar todos los eventos ocurridos hasta un año determinado utilizando recursión.



###Funciones Implementadas

`leerEvento(Evento *e)` : Permite la entrada de datos para un nuevo evento.

`crearNodo(Evento e)` : Crea un nodo para la lista enlazada con la información del evento.

`insertarOrdenado(Nodo *l, Evento e)` : Inserta un nuevo evento en la lista de manera que se mantenga el orden cronológico.

`crearLista(Nodo *l)` : Permite la creación interactiva de una lista de eventos hasta que se ingrese un año de corte (por ejemplo, "1" para terminar).

`eliminar(Nodo *l, int anio, int *ok)` : Elimina un evento de la lista basándose en el año especificado.

`buscarTodos(Nodo l, int anio)` : Busca y muestra todos los eventos de un año específico.

`retornarLista(Nodo l1, Nodo *l2, int anio)` : Filtra recursivamente todos los eventos ocurridos hasta el año dado y los almacena en una nueva lista.


###Estructuras utilizadas

```c
/* Registro */
typedef struct evento{
    int anio;
    char titulo[MAX_TITULO];
    char descripcion[MAX_DESCRIPCION];
}Evento;

/* Lista enlazada */
typedef struct nodo{
    Evento dato;
    struct nodo *sig;
}*Nodo;
```
###Integrantes:
- Fernandez Emiliano
- Morales Lautaro
- Henriquez Gerardo Alberto
