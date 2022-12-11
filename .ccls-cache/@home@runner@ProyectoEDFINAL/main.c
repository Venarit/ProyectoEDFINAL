#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


struct generos{
	int id_gen;
	char gen[50];
}est;

struct artistas{
	int id_art;
	char art[50];
}est_art;

struct canciones{
	int id_cancion;
	char can[60];
	int duracion;
	int reproducciones;
	int puntuacion;
	int r_gen;
	int r_art;
}est_can;

struct elem_lista{
  struct canciones cancion;
  struct artistas artista;
  struct generos genero;
  struct elem_lista *sig;
};

struct colaReproduccion
{
  struct canciones cancion;
  struct artistas artista;
  struct colaReproduccion *sig;
  struct colaReproduccion *ant;
};


void impresion(struct elem_lista *inicio)
{
  struct elem_lista *temp;
  temp = inicio;
  while (temp){
    printf("< %s >\n",temp -> cancion.can);
    printf("- %s -\n",temp -> artista.art);
    printf("\n");
    temp = temp -> sig;
    
  }
}
int insertarLista (struct elem_lista *lista,struct canciones cancion){
  struct elem_lista *temp;
  if (lista -> sig == NULL)
  {
    temp = (struct elem_lista *)calloc(1,sizeof(struct elem_lista));
    lista -> sig = temp;
    temp ->  cancion = cancion;
    return 1;  
  } else {
    insertarLista(lista -> sig, cancion);
  }
}
//cola
int insertarArtistas (struct elem_lista *inicio){
  if(!inicio){
    return;
  }
  inicio -> cancion.r_art;
    
  FILE *ptr;
  ptr=fopen("Registroart.txt","ab+");
  if (ptr == NULL){
    return;
  }

  while(!feof(ptr)){
    
      fread(&est_art,sizeof(est_art),1,ptr);
    
      if(inicio->cancion.r_art == est_art.id_art){
        inicio -> artista = est_art;
      }
  }
  if(inicio -> sig != NULL){
    insertarArtistas(inicio -> sig);
  }
}
//lista ligada o cola?^^^^

  int agregarACola(struct colaReproduccion *cola,struct elem_lista *lista, bool reproducir)
  {
    if (reproducir)
    {
      //Aqui se tiene que limpiar la cola
      
      
    }
    //Agregar a la estructura cola todo lo que hay en lista
    struct colaReproduccion *temp;
  if (cola -> sig == NULL)
  {
    temp = (struct colaReproduccion *)calloc(1,sizeof(struct colaReproduccion));
    cola -> sig = temp;
    temp ->  cancion = lista -> cancion;
    temp -> artista = lista -> artista;
    temp -> ant = cola;
    if (lista->sig != NULL)
    {
      agregarACola(cola -> sig, lista->sig, reproducir);
    }
    return 1; 
  } else {
    agregarACola(cola -> sig, lista, reproducir);
  }
    
  }
  void estadoDeCola (struct colaReproduccion *inicioCola)
  {
      struct colaReproduccion *temp;
      temp = inicioCola;
      while (temp){
      printf("< %s >\n",temp -> cancion.can);
      printf("- %s -\n",temp -> artista.art);
      printf("\n");
      temp = temp -> sig;
    }
    int x;
    scanf("%i",&x);
  }

int main (){
    struct elem_lista *lista;
    struct canciones *cancion;
    struct elem_lista *listaTemporal;
    struct colaReproduccion *cola;
  
    listaTemporal  = (struct elem_lista *) calloc(1, sizeof(*listaTemporal));
  
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
  while(opcionSwitch != 4){
        system("clear");
        printf("Bienvenido a SpotiUV\n");
        printf("---------------------\n");
        printf("1.  Explorar Generos\n");
        printf("2.  Explorar Canciones\n");
        printf("3.  Reproductor\n");
        printf("4.  Salir\n\n");
        printf("5. temporal");
        printf("Selecciona una opcion: ");
        scanf("%i",&opcionSwitch);
        switch (opcionSwitch){
        case 1: 
          {
            system("clear");
  				  //printf("\nVER DATOS\n");
    				ptr=fopen("Registrogen.txt","ab+");
    				if (ptr == NULL){
    			        printf("Error al abrir el archivo\n");
    			        main();
    			        break;
  			    }
  				
  				printf("\n ID	|     GENERO\n");
  				printf("----------------------\n");
  				while(fread(&est,sizeof(est),1,ptr)){
  					
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
  				
  				switch(opmengen){
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
                 
                

                 //MOSTRAR CANCIONES SIN ARTISTA(todavia)
                 ptr2=fopen("Registrocan.txt","ab+");
                 if(ptr2 == NULL){
                   printf("Error al abrir el archivo\n");
                   main();
                   break;
                 }

                 while(!feof(ptr2))
                   {
                     fread(&est_can,sizeof(est_can),1,ptr2);
                     if(opgen == est_can.r_gen)
                     {
                       //printf("\n<%s>",est_can.can);
                       
                       insertarLista(listaTemporal,est_can);
                       insertarArtistas(listaTemporal);

                       
                     }
                   }
                 
                  
                 
                 
                 break;
               }
              }
              if(opgen!=est.id_gen){
                 printf("Genero no encontrado.\n");
              }
              //
              
              char opc;
              while (opc != 'p'){
              system("clear");  
              printf("\n----------%s----------\n\n", est.gen);
              impresion(listaTemporal->sig);
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
                case 'q': agregarACola( cola, listaTemporal->sig, false );
                          estadoDeCola(cola->sig);
                  break;
                case 'r':
                  printf("\nReproduciendo todas las canciones de lista...");
                  break;
                case 's':
                  printf("\nSeleccione una canción: ");
                  break;
                default:
                  printf("\nOpción no valida");
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
          }  

          
          
            
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////              
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

        case 3: printf("Reproductor\n");
                printf("Actualmente sonando:\n");
                printf("<Nombre de la cancion>\n");
                printf("<Nombre del artista>\n");
                printf("<   ||   >\n");
                printf("Opciones:\n");
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
                   break;

        case 4: printf("Saliendo...");
            break;
          //case 5 sirve para probar, no borrar porfavor
          case 5: printf("imprimiendo cola repro...");
            estadoDeCola(cola->sig);
            break;
        default: printf("Opcion Invalida");
            break;
        }
    }
return 0; 
}