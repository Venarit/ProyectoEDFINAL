#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>


struct generos
{
  int id_gen;
  char gen[50];
}est;

struct artistas
{
  int id_art;
  char art[50];
}est_art;

struct canciones
{
  int id_cancion;
  char can[60];
  int duracion;
  int reproducciones;
  int puntuacion;
  int r_gen;
  int r_art;
}est_can;

struct elem_lista
{
  struct canciones cancion;
  struct artistas artista;
  struct generos genero;
  struct elem_lista *sig;
};

struct nodoCola{
  struct canciones cancion;
  struct artistas artista;
  struct nodoCola *sgt;
}NodoCola;

struct colaReproduccion{
  struct nodoCola *inicio;
  struct nodoCola *final;
}Cola;

int insertarCola(struct colaReproduccion *c, struct elem_lista *lista)
{
  struct nodoCola * newElem = (struct nodoCola*) calloc(1,sizeof(struct nodoCola));
  if(!newElem)
    return 0;
  struct elem_lista *temp = lista;
  
  while(temp)
  {
    newElem = (struct nodoCola*) calloc(1,sizeof(struct nodoCola));
    newElem -> cancion = temp -> cancion;
    newElem -> artista = temp -> artista;

    if(c->inicio == NULL && c->final == NULL)
    {
      c->inicio = newElem;
      c->final = newElem;
    }
    else
    {
      c -> final -> sgt = newElem;
      c -> final = newElem;
    }

    temp = temp -> sig;
  }
  return 1;
}

int insertarCancionCola(struct colaReproduccion *c,struct elem_lista *lista,int id_cancion)
{
  struct nodoCola * newElem;
  struct elem_lista *temp;
  temp = lista;
  while(temp)
  {
    if(temp -> cancion.id_cancion == id_cancion)
    {
      newElem = (struct nodoCola*) calloc(1,sizeof(struct nodoCola));
      newElem -> cancion = temp -> cancion;
      newElem -> artista = temp -> artista;
  
      if(c->inicio == NULL && c->final == NULL)
      {
        c->inicio = newElem;
        c->final = newElem;
      }
      else
      {
        c -> final -> sgt = newElem;
        c -> final = newElem;
      }
    }
    temp = temp -> sig;
  }
  return 1;
}

int vaciarCola(struct colaReproduccion *cola){
    struct nodoCola *ultimo, *temp;
    if(cola == NULL)
    {
        return 0;
    } else 
      {
        ultimo = cola -> inicio;
        while (ultimo->sgt != NULL)
        {   
            temp = ultimo;
            ultimo = ultimo->sgt;
            free(temp);
        }
        cola -> inicio = NULL;
        cola -> final = NULL;
        free(ultimo);
      }
    return 1;
}


int vaciarLista(struct elem_lista **lista);

//Funcion auxiliar para la impresion de los pares de elementos de Cancion, Artista que se encuentren en una lista
void impresion(struct elem_lista *inicio)
{
  struct elem_lista *temp;
  temp = inicio;
  while (temp)
  {
    printf("$%d\n", temp->cancion.id_cancion);
    printf("< %s >\n",temp -> cancion.can);
    printf("- %s -\n",temp -> artista.art);
    printf("\n");
    temp = temp -> sig;   
  }
}

void impresionde1(struct elem_lista *inicio)
{
  struct elem_lista *temp;
  temp = inicio;
  while (temp)
  {
    printf("$%d\n", temp->cancion.id_cancion);
    printf("< %s >\n",temp -> cancion.can);
    printf("- %s -\n",temp -> artista.art);
    printf("\n");
  }
}


//Funcion auxiliar para la creacion e insercion de elementos en una lista, util para la creacion de Colas, ya que //añade el elemento al final de la lista, recorriendola en dado caso hasta llegar al final 
int insertarLista (struct elem_lista **lista,struct canciones cancion)
{
  struct elem_lista *temp, *ultimo;
    if((*lista) == NULL){
        temp = (struct elem_lista *)calloc(1,sizeof(struct elem_lista));
        temp->cancion = cancion;
        *lista =  temp;
        return 1;  
    } else {
        ultimo = (*lista);
        while (ultimo->sig != NULL)
        {
            ultimo = ultimo->sig;
        }
        temp = (struct elem_lista *)calloc(1,sizeof(struct elem_lista));
        temp->cancion = cancion;
        ultimo->sig = temp;
        return 1;
    }
}

//funcion auxiliar que relaciona las canciones que se encuentran en una lista con la de sus artistas relacionados
//Normalmente se manda a llamar despues de la creacion inicial de una lista de canciones
int insertarArtistas (struct elem_lista *inicio)
{
    if(!inicio)
    {
      return 0;
    }
    inicio -> cancion.r_art;
  
    FILE *ptr;
    ptr=fopen("Registroart.txt","ab+");
    if (ptr == NULL)
    {
      return 0;
    }
  
    while(!feof(ptr))
  {
    fread(&est_art,sizeof(est_art),1,ptr);
    
    if(inicio->cancion.r_art == est_art.id_art)
    {
      inicio -> artista = est_art;
    }
  }
    if(inicio -> sig != NULL)
    {
      insertarArtistas(inicio -> sig);
    }
  return 1;
}

void imprimirCola (struct nodoCola *inicio)
{
  struct nodoCola *temp;
  temp = inicio;
  while (temp)
  {
    printf("< %s >\n",temp -> cancion.can);
    printf("- %s -\n",temp -> artista.art);
    printf("\n");
    temp = temp -> sgt;
  }
  int x;
  scanf("%i",&x);
}

void cancionActual (struct nodoCola *nodo)
{
  struct nodoCola *temp;
  temp = nodo;
  
    printf("< %s >\n",temp -> cancion.can);
    printf("- %s -\n",temp -> artista.art);
    printf("\n");
  int x;
  scanf("%i",&x);
}

void cancionActual2 (struct nodoCola *nodo)
{
	int y;
  struct nodoCola *temp;
  temp = nodo;
  while (temp)
  {
  	system("clear");
    printf("------------Reproductor-------------\n");
    printf("\nActualmente sonando:\n\n");
    printf("< %s >\n",temp -> cancion.can);
    printf("- %s -\n",temp -> artista.art);
    
    printf("\n");
    
    printf("Siguiente");
    scanf("%i",&y);
    temp = temp -> sgt;
  }
  	system("clear");
    printf("------------Reproductor-------------\n");
    printf("\nActualmente sonando:\n\n");
    printf("< NONE >\n");
    printf("- NONE -\n");
    printf("\n");
}



//Funcion auxiliar que deja completamente vacia y elimina todos los elementos de una lista
int vaciarLista(struct elem_lista **lista){
    struct elem_lista *ultimo, *temp;
    if((*lista) == NULL){
        return 0;
    } else {
        ultimo = (*lista);
        while (ultimo->sig != NULL)
        {   
            temp = ultimo;
            ultimo = ultimo->sig;
            free(temp);
        }
        free(ultimo);
        (*lista) = NULL;
    }
    return 1;
}

//////////////////////////////////////////////////////////////////////////////////
int main ()
{
  struct elem_lista *lista;
  struct canciones *cancion;
  struct elem_lista *listaTemporal = NULL;
  struct colaReproduccion *cola;
  
  int opcionReproductorint;
  //listaTemporal  = (struct elem_lista *) calloc(1, sizeof(*listaTemporal));
  
  FILE *ptr;
  FILE *ptr2;
  FILE *ptr3;
  
  lista  = (struct elem_lista *) calloc(1, sizeof(*lista));
  cancion = (struct canciones *) calloc(1, sizeof(*cancion));
  cola = (struct colaReproduccion *) calloc(1, sizeof(*cola));
  
  //strcpy(cancion->can, "Test");
  //insertarLista(lista, *cancion);
  //impresion(lista);
  int opcionSwitch,opcionGeneros;
  char opcionGeneros2,opcionReproductor,opcionCanciones;
  
  
  //poner do while para menu para quitar mains
  while(opcionSwitch != 4)
  {
    system("clear");
    printf("Bienvenido a SpotiUV\n");
    printf("---------------------\n");
    printf("1.  Explorar Generos\n");
    printf("2.  Explorar Canciones\n");
    printf("3.  Reproductor\n");
    printf("4.  Salir\n");
    printf("5. Cola de reproduccion\n");
    printf("Selecciona una opcion: ");
    scanf("%i",&opcionSwitch);
    switch (opcionSwitch)
    {
      case 1: 
      {
        system("clear");
        //printf("\nVER DATOS\n");
        ptr=fopen("Registrogen.txt","ab+");
        if (ptr == NULL)
        {
          printf("Error al abrir el archivo\n");
          main();
          break;
        }
        
        printf("\n ID	|     GENERO\n");
        printf("----------------------\n");
        while(fread(&est,sizeof(est),1,ptr))
          
        {
          printf(" %d.       | %s\n", est.id_gen, est.gen);
        }
        fclose(ptr);
        int opmengen;
        printf( "\n------------------------------");
        printf( "\n1.Seleccionar un genero.");
        printf( "\n2.Regresar al menu principal.");
        printf( "\n------------------------------");
        printf( "\n\nIntroduzca una opcion (1-2): ");
        scanf( "%d", &opmengen );
        
        switch(opmengen)
        {
            case 1:
          {
            ptr=fopen("Registrogen.txt","rb+");
            if(ptr==NULL)
            return 0;
            int opgen;
            printf("\nSeleccione un genero: ");
            scanf("%d",&opgen);
            
            while(!feof(ptr))
            {
                fread(&est,sizeof(est),1,ptr);
                if( est.id_gen == opgen)
              {
                //MOSTRAR CANCIONES CON ARTISTA
                ptr2=fopen("Registrocan.txt","ab+");
                if(ptr2 == NULL)
                {
                  printf("Error al abrir el archivo\n");
                  main();
                  break;
                }
                  //listaTemporal  = (struct elem_lista *) calloc(1,sizeof(*listaTemporal));
                vaciarLista(&listaTemporal);
                  while(!feof(ptr2))
                {
                  fread(&est_can,sizeof(est_can),1,ptr2);
                  if(opgen == est_can.r_gen)
                  {
                    //printf("\n<%s>",est_can.can);    
                    insertarLista(&listaTemporal,est_can);
                    insertarArtistas(listaTemporal);
                  }
                }    
                break;
              }
            }
            if(opgen!=est.id_gen)
            {
              
              printf("Genero no encontrado.\n");
            }
            ////////////////     
            char opc;
            while (opc != 'p')
            {
              system("clear");  
              printf("\n----------%s----------\n\n", est.gen);
              impresion(listaTemporal);
              printf("\n--------------------------------------");
              printf("\np.  Regresar al menu principal.");
              printf("\nq.  Agregar a la cola de reproducción.");
              printf("\nr.  Reproducir toda esta lista.");
              printf("\ns.  Escoger una canción.");
              printf("\n--------------------------------------");
              printf("\nSeleccione una opción: ");
              scanf( "%s", &opc);
              
              switch(opc)
              {     
                case 'q':  
                  insertarCola( cola, listaTemporal); 
                          //imprimirCola(cola->inicio);
                         // vaciarLista(&listaTemporal);
                break;
                case 'r': 
                  vaciarCola(cola);
                  insertarCola( cola, listaTemporal);
                          //imprimirCola(cola->inicio);
                         // vaciarLista(&listaTemporal);
                break;
                case 's': printf("\nSeleccione una canción: ");
                          scanf("%d",&opcionReproductorint);
                          insertarCancionCola(cola, listaTemporal,opcionReproductorint);
                          //agregarCancionACola(&cola, listaTemporal, false, opcionReproductorint);
                break;
                default:               
                break;
              }
            }
            break;
          }			
          case 2:						
          break;
          default:
          //printf("\nOPCION NO VALIDA");
          
          break;
        }
        break;
      }      //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////              
      case 2: 
      {
        printf("Lista de canciones\n");
        printf("1.<Nombre cancion>\n");
        printf("  <Nombre artista>\n");
        printf("2.<cancion>\n");
        printf("  <Nombre artista>\n");
        printf("Opciones:\n");
        printf("p: Regresar al menu principal\n");
        printf("a: 10 Canciones anteriores\n");
        printf("d: 10 Canciones siguientes \n");
        printf("q: Agregar a la cola una cancion de la lista\n");
        printf("r: Reproducir una cancion\n");
        printf("Selecciona una opcion: ");
        getchar();
        scanf("%c",&opcionCanciones);
        
        switch (opcionCanciones)
        {
          case 'p': 
          break;
          case 'a': printf("10 Canciones anteriores...");
          break;
          case 'd': printf("10 Canciones siguientes...");
          break;
          case 'q': printf("Agregar a la cola una cancion de la lista...");
          break;
          case 'r': printf("Reproducir una cancion...");
          break;
          
          default:
          break;
        }
        break;
      }
      //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      
      case 3: 
        while (opcionReproductor != 'p')
        {
          system("clear");
          printf("------------Reproductor-------------\n");
          printf("\nActualmente sonando:\n");
          cancionActual2(cola->inicio);
          //progresoCancion(cola->sig);
          printf("<   ||   >\n");
          printf("\nOpciones:\n");
          printf("p: Regresar al menu principal\n");
          printf("a: Cancion anterior\n");
          printf("d: Siguiente cancion\n");
          printf("e: Repetir cancion\n");
          printf("r: Activar/desactivar Repeticion\n");
          printf("s: Pausar/Continuar sonando\n");
          printf("Selecciona una opcion: ");
          getchar();
          scanf("%c",&opcionReproductor);
      
          switch (opcionReproductor)
          {
            case 'p': main();
            break;
            case 'a': printf("Cancion anterior...");
            break;
            case 'd': printf("Siguiente cancion...");
            break;
            case 'e': printf("Repetir cancion...");
            break;
            case 'r': printf("Activar/desactivar Repeticion...");
            break;
            case 's': printf("Pausando/Continuando...");
            break;
            default: 
            break;
          }
        }
          
      break;
      case 4: printf("Saliendo...");
          return 0;
      break;
      //case 5 sirve para probar, no borrar porfavor
      case 5: 
        printf("\nCola de reproduccion: \n");
        imprimirCola(cola->inicio);
      break;
      default: 
      break;
    }
  }
  return 0; 
}