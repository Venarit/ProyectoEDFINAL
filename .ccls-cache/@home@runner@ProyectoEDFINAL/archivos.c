#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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




int main(){
	FILE *ptr; //puntero a archivo
	FILE *ptr2;
	FILE *ptr3;
	
	int opcion;
	char nom[20];
	
		system("cls"); 
		printf("\nREGISTRO\n");
        printf( "\n1.	Agregar generos.");
        printf( "\n2.	Ver generos");
        printf( "\n3.	Agregar artistas.");
        printf( "\n4.	Ver artistas");
        printf( "\n5.	Agregar canciones.");
        printf( "\n6.	Ver canciones");
        printf( "\n7.	Salir." );
        printf( "\n\nIntroduzca una opcion (1-7): ");
        
        scanf( "%d", &opcion );
        
        
        switch(opcion){
        	
        	case 1:{
            int n;
        		system("cls"); 
        		printf("\nCANTIDAD DE GENEROS A INTRODUCIR: ");
        		scanf("%d",&n);
        		
        		for(int i=0; i<n; i++){
        			printf("\nINGRESE GENERO %d: ",i+1);
        			scanf("%s",est.gen);
        			printf("INGRESE ID DE GENERO %d: ",i+1);
        			scanf("%d",&est.id_gen);
				
					ptr=fopen("Registrogen.txt","ab+");
					if(ptr==NULL){
						printf("No se puede crear el archivo\n");
						return 0;
					}
					fwrite(&est,sizeof(est),1,ptr);
					fclose(ptr);
				}
					printf("Los datos han sido guardados correctamente.\n\n");
					
					pausa();
					
					main();
					
					break;
          }
        		
					
			case 2: {
				
				system("cls"); 
				//printf("\nVER DATOS\n");
				ptr=fopen("Registrogen.txt","ab+");
				if (ptr == NULL){
			        printf("Error al abrir el archivo\n");
			        main();
			        break;
			    }
				
				printf("\n ID	| GENERO\n");
				printf("----------------------\n");
				while(fread(&est,sizeof(est),1,ptr)){
					
					printf(" %d.	| %s\n", est.id_gen, est.gen);
					
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
					case 1:{
            int opgen;
						printf("\nSeleccione un genero: ");
						scanf("%d",&opgen);
						
						
						
						break;
					case 2:
						main();
						break;
					default:
						printf("\nOPCION NO VALIDA");
						pausa();
						main();
						break;
          }
						
				}
					
				pausa();
				main();
				
				break;
			}
			case 3: {
				int n;
				system("cls"); 
        		printf("\nCANTIDAD DE ARTISTAS A INTRODUCIR: ");
        		scanf("%d",&n);
        		
        		for(int i=0; i<n; i++){
        			printf("\nINGRESE NOMBRE DE ARTISTA %d: ",i+1);
        			scanf("%s",est_art.art);
        			printf("INGRESE ID DE ARTISTA %d: ",i+1);
        			scanf("%d",&est_art.id_art);
				
					ptr2=fopen("Registroart.txt","ab+");
					if(ptr2==NULL){
						printf("No se puede crear el archivo\n");
						return 0;
					}
					fwrite(&est_art,sizeof(est_art),1,ptr2);
					fclose(ptr2);
				}
					printf("Los datos han sido guardados correctamente.\n\n");
					
					pausa();
					
					main();
					
					break;
				}
			case 4:
				system("cls"); 
				//printf("\nVER DATOS\n");
				ptr2=fopen("Registroart.txt","ab+");
				if (ptr2 == NULL){
			        printf("Error al abrir el archivo\n");
			        main();
			        break;
			    }
				
				printf("\n ID	| ARTISTA\n");
				printf("----------------------\n");
				while(fread(&est_art,sizeof(est_art),1,ptr2)){
					
					printf(" %d.	| %s\n", est_art.id_art, est_art.art);
					
				}
				
				
				fclose(ptr2);
				break;
				
			case 5: {
				
				int n;
				system("cls"); 
        		printf("\nCANTIDAD DE CANCIONES A INTRODUCIR: ");
        		scanf("%d",&n);
        		
        		for(int i=0; i<n; i++){
        			printf("\nINGRESE NOMBRE DE CANCION %d: ",i+1);
        			scanf("%s",est_can.can);
        			printf("INGRESE ID DE CANCION %d: ",i+1);
        			scanf("%d",&est_can.id_cancion);
        			printf("INGRESE DURACION DE CANCION %d: ",i+1);
        			scanf("%d",&est_can.duracion);
        			printf("INGRESE LAS REPRODUCCIONES DE CANCION %d: ",i+1);
        			scanf("%d",&est_can.reproducciones);
        			printf("INGRESE LA PUNTUACION DE CANCION %d: ",i+1);
        			scanf("%d",&est_can.puntuacion);
        			
        			///////VER GENEROS
        			ptr=fopen("Registrogen.txt","ab+");
					if (ptr == NULL){
				        printf("Error al abrir el archivo\n");
				        main();
				        break;
				    }
					
					printf("\n ID	| GENERO\n");
					printf("----------------------\n");
					while(fread(&est,sizeof(est),1,ptr)){
						
						printf(" %d.	| %s\n", est.id_gen, est.gen);
						
					}
					
					
					fclose(ptr);
        			
        			////////////VER ARTISTAS
        			printf("\nINGRESE EL ID DEL GENERO DE LA CANCION %d: ",i+1);
        			scanf("%d",&est_can.r_gen);
        			
        			
        			ptr2=fopen("Registroart.txt","ab+");
					if (ptr2 == NULL){
				        printf("Error al abrir el archivo\n");
				        main();
				        break;
				    }
					
					printf("\n ID	| ARTISTA\n");
					printf("----------------------\n");
					while(fread(&est_art,sizeof(est_art),1,ptr2)){
						
						printf(" %d.	| %s\n", est_art.id_art, est_art.art);
						
					}
					
					
					fclose(ptr2);
					
        			printf("\nINGRESE EL ID DEL ARTISTA DE LA CANCION %d: ",i+1);
        			scanf("%d",&est_can.r_art);
        			
        			
        			
        			
				
					ptr3=fopen("Registrocan.txt","ab+");
					if(ptr3==NULL){
						printf("No se puede crear el archivo\n");
						return 0;
					}
					fwrite(&est_can,sizeof(est_can),1,ptr3);
					fclose(ptr3);
				}
					printf("Los datos han sido guardados correctamente.\n\n");
					
					pausa();
					
					main();
				
				break;
			}
			
			case 6:
				system("cls"); 
				//printf("\nVER DATOS\n");
				ptr3=fopen("Registrocan.txt","ab+");
				if (ptr3 == NULL){
			        printf("Error al abrir el archivo\n");
			        main();
			        break;
			    }
												
				printf("\n ID	| CANCION	| DURACION(SEG)	| REPRODUCCIONES	| PUNTUACION	| IDGENERO	| IDARTISTA\n");
				printf("---------------------------------------------------------------------------------------------------------\n");
				while(fread(&est_can,sizeof(est_can),1,ptr3)){
					
					printf(" %d.	| %s	| %d		| %d		| %d/10		| %d		| %d \n", 
					est_can.id_cancion, est_can.can,est_can.duracion,est_can.reproducciones,est_can.puntuacion,est_can.r_gen,est_can.r_art);
					
				}
				
				
				fclose(ptr3);
				main();
				
				break;
				
			default:
				printf("\nOPCION NO VALIDA");
				pausa();
				main();
				break;
				
		}
        
	
	return 0;
}