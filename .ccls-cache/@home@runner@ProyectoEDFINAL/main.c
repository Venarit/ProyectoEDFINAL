#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct generos{
	int id_gen;
	char gen[50];
}est;

int main (){
    FILE *ptr;
    int opcionSwitch,opcionGeneros;
    char opcionGeneros2,opcionReproductor,opcionCanciones;
  system("clear");
    printf("Bienvenido a SpotiUV\n");
    printf("---------------------\n");
    printf("1.  Explorar Generos\n");
    printf("2.  Explorar Canciones\n");
    printf("3.  Reproductor\n");
    printf("4.  Salir\n\n");
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
                 printf("\n----------%s----------\n", est.gen);
                 break;
               }
              }
              if(opgen!=est.id_gen){
                 printf("Genero no encontrado.\n");
              }
              
  						break;
            }
  						
  					case 2:
  						main();
  						break;
  					default:
  						printf("\nOPCION NO VALIDA");
  						main();
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
                case 'p': main();
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
        default: printf("Opcion Invalida");
            break;
        }
    
return 0;
}