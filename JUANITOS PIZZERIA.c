#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#define MAX 100
#define LONGITUD 10

typedef struct cliente{
	char user[LONGITUD];
	char password[LONGITUD];
}cliente;


void MenuPrincipal(){
    printf("\n ==== BIENVENID@ A Juanito's Pizzeria ====\n");
    printf("\n ========== MENU PRINCIPAL ==========\n");
    printf("1. Iniciar Sesion\n");
    printf("2. Crear Cuenta\n");
    printf("3. Buscar Usuario\n");
    printf("4. Eliminar Usuario\n");
    printf("5. Lista de Usuarios\n");
    printf("0. Salir\n");
    printf("Que quiere mijito? ");
	return;
}

void MenuPizzas(){
	printf("\n=== MENU DE PIZZAS ===\n");
	printf("1. Pepperoni\n");
	printf("2. Hawaiana\n");
	printf("3. Vegetariana\n");
	printf("4. Tres Quesos\n");
	printf("5. Napolitana\n");
	printf("6. Cerrar Sesion\n");
	printf("Que quieres comer hoy mijito? ");
	return;
}

void sizePizza(){
	printf("\nPROMOCIONES\n");
	printf("\n15%% de Descuento por la compra de:\n\n4 Pizzas Personales o Medianas\n-----------------------------------\n25%% de Descuento por la compra de:\n\n3 Pizzas Grandes o Extragrandes\n-----------------------------------\n");
	printf("\nQue tan grande la quieres mijito?\n");
	printf("\n   Tama%co		Precio\n",164);
	printf("1. Personal		$4000\n");
	printf("2. Mediana    		$12000\n");
	printf("3. Grande		$21000\n");
	printf("4. Extragrande		$30000\n");
	printf("\nSeleccionar: ");
}

int main(){
   cliente PIZZERIA[MAX];
	
   char usuario[LONGITUD];
   char clave[LONGITUD];
   char caracter;
	
   int opcion;
   int cont = 0;
   int i,j;
   int intentos = 0;
   int cantidadPizza, precioTotal, descuento;
	
	FILE *f, *salvar;
	
	salvar = fopen( "PIZZERIA.dat", "rb" );
	fread( &cont, sizeof( int ), 1, salvar );
	fread( PIZZERIA, sizeof( PIZZERIA ), 1, salvar );
	fclose( salvar );
	printf( "*** se cargaron %d registros con exito\n", cont );
	
	do{
		MenuPrincipal(); scanf("%d",&opcion);
		switch(opcion){
			
			case 1: 
			system("cls");
			i = 0;
			printf("\n === Iniciar Sesion ===\n");
			printf("\nUsuario: "); scanf("%s",usuario);
			printf("Clave(10 digitos max): ");
			while(caracter = getch()){
				if(caracter == 13){
					clave[i] = '\0'; //ASCII DE LA TECLA ENTER
					break;
				}
				else if(caracter == 8){ // ASCII DE LA TECLA BACKSPACE
					if(i > 0){
						i--;
						printf("\b \b");//SECUENCIA QUE MUEVE EL CURSOR A LA IZQUIERDA	
					}
						
				}else{
					if(i < LONGITUD){
						printf("*");
						clave[i] = caracter;
						i++;
					}
					
				}
				
			}
			
			
			for(i = 0; i < cont; i++){
				
				if(strcmp(usuario,PIZZERIA[i].user) == 0 && strcmp(clave,PIZZERIA[i].password) == 0){
					system("cls");
					printf("\nBIENVENIDO/A %s! \n",usuario);
									
						MenuPizzas(); scanf("%d",&opcion);//cargar menu de pizzas si el usuario y clave son correctos
						switch(opcion){
							
							case 1: 
							system("cls");
							printf("\nPIZZA DE PEPPERONI\n");
							sizePizza(); scanf("%d",&opcion);
							
							switch(opcion){
								
								case 1:
									cantidadPizza = 0; 
									precioTotal = 0;
									descuento = 0;
									printf("Cuantas desea llevar: "); scanf("%d",&cantidadPizza);
									if(cantidadPizza > 3){
										descuento = (cantidadPizza * 4000) * 0.15;
										precioTotal = (cantidadPizza * 4000) - descuento ;
										system("cls");
										f = fopen( "RECIBO.txt", "w");
										fprintf(f,"\n		JUANITO'S PIZZERIA \n---------------------------------------------------\n---------------------------------------------------\n\nEl Total de su compra es: $ %d\nGracias Por su Compra! Vuelva Pronto", precioTotal);
										fclose(f);
										system("notepad RECIBO.txt");  
									}
									else{
										precioTotal = cantidadPizza * 4000;
										printf("Total: %d \n",precioTotal);
										system("cls");
										f = fopen( "RECIBO.txt", "w");
										fprintf(f,"\n		JUANITO'S PIZZERIA \n---------------------------------------------------\n---------------------------------------------------\n\nEl Total de su compra es: $ %d\nGracias Por su Compra! Vuelva Pronto", precioTotal);
										fclose(f);
										system("notepad RECIBO.txt");	
									}
									break;
								
								case 2:
									cantidadPizza = 0; 
									precioTotal = 0;
									descuento = 0;
									printf("Cuantas desea llevar: "); scanf("%d",&cantidadPizza);
									if(cantidadPizza > 3){
										descuento = (cantidadPizza * 12000) * 0.15;
										precioTotal = (cantidadPizza * 12000) - descuento ;
										system("cls");
										f = fopen( "RECIBO.txt", "w");
										fprintf(f,"\n		JUANITO'S PIZZERIA \n---------------------------------------------------\n---------------------------------------------------\n\nEl Total de su compra es: $ %d\nGracias Por su Compra! Vuelva Pronto", precioTotal);
										fclose(f);
										system("notepad RECIBO.txt");  
									}
									else{
										precioTotal = cantidadPizza * 12000;
										printf("Total: %d \n",precioTotal);
										system("cls");
										f = fopen( "RECIBO.txt", "w");
										fprintf(f,"\n		JUANITO'S PIZZERIA \n---------------------------------------------------\n---------------------------------------------------\n\nEl Total de su compra es: $ %d\nGracias Por su Compra! Vuelva Pronto", precioTotal);
										fclose(f);
										system("notepad RECIBO.txt");	
									}
									break;
									
									
								case 3:
									cantidadPizza = 0; 
									precioTotal = 0;
									descuento = 0;
									printf("Cuantas desea llevar: "); scanf("%d",&cantidadPizza);
									if(cantidadPizza >= 3){
										descuento = (cantidadPizza * 21000) * 0.25;
										precioTotal = (cantidadPizza * 21000) - descuento ;
										system("cls");
										f = fopen( "RECIBO.txt", "w");
										fprintf(f,"\n		JUANITO'S PIZZERIA \n---------------------------------------------------\n---------------------------------------------------\n\nEl Total de su compra es: $ %d\nGracias Por su Compra! Vuelva Pronto", precioTotal);
										fclose(f);
										system("notepad RECIBO.txt");  
									}
									else{
										precioTotal = cantidadPizza * 21000;
										printf("Total: %d \n",precioTotal);
										system("cls");
										f = fopen( "RECIBO.txt", "w");
										fprintf(f,"\n		JUANITO'S PIZZERIA \n---------------------------------------------------\n---------------------------------------------------\n\nEl Total de su compra es: $ %d\nGracias Por su Compra! Vuelva Pronto", precioTotal);
										fclose(f);
										system("notepad RECIBO.txt");	
									}
									break;
									
									
								case 4:
									cantidadPizza = 0; 
									precioTotal = 0;
									descuento = 0;
									printf("Cuantas desea llevar: "); scanf("%d",&cantidadPizza);
									if(cantidadPizza >= 3){
										descuento = (cantidadPizza * 30000) * 0.25;
										precioTotal = (cantidadPizza * 30000) - descuento ;
										system("cls");
										f = fopen( "RECIBO.txt", "w");
										fprintf(f,"\n		JUANITO'S PIZZERIA \n---------------------------------------------------\n---------------------------------------------------\n\nEl Total de su compra es: $ %d\nGracias Por su Compra! Vuelva Pronto", precioTotal);
										fclose(f);
										system("notepad RECIBO.txt");  
									}
									else{
										precioTotal = cantidadPizza * 30000;
										printf("Total: %d \n",precioTotal);
										system("cls");
										f = fopen( "RECIBO.txt", "w");
										fprintf(f,"\n		JUANITO'S PIZZERIA \n---------------------------------------------------\n---------------------------------------------------\n\nEl Total de su compra es: $ %d\nGracias Por su Compra! Vuelva Pronto", precioTotal);
										fclose(f);
										system("notepad RECIBO.txt");	
									}
									break;
									
								default: sizePizza(); scanf("%d",&opcion);
										 
							}
							break;
							//PIZZA HAWWAIANA
							case 2:
							system("cls");
							printf("\nPIZZA HAWAIANA\n");
							sizePizza(); scanf("%d",&opcion);
							
							switch(opcion){
								case 1:
									cantidadPizza = 0; 
									precioTotal = 0;
									descuento = 0;
									printf("Cuantas desea llevar: "); scanf("%d",&cantidadPizza);
									if(cantidadPizza > 3){
										descuento = (cantidadPizza * 4000) * 0.15;
										precioTotal = (cantidadPizza * 4000) - descuento ;
										system("cls");
										f = fopen( "RECIBO.txt", "w");
										fprintf(f,"\n		JUANITO'S PIZZERIA \n---------------------------------------------------\n---------------------------------------------------\n\nEl Total de su compra es: $ %d\nGracias Por su Compra! Vuelva Pronto", precioTotal);
										fclose(f);
										system("notepad RECIBO.txt");  
									}
									else{
										precioTotal = cantidadPizza * 4000;
										printf("Total: %d \n",precioTotal);
										system("cls");
										f = fopen( "RECIBO.txt", "w");
										fprintf(f,"\n		JUANITO'S PIZZERIA \n---------------------------------------------------\n---------------------------------------------------\n\nEl Total de su compra es: $ %d\nGracias Por su Compra! Vuelva Pronto", precioTotal);
										fclose(f);
										system("notepad RECIBO.txt");	
									}
									break;
								
								case 2:
									cantidadPizza = 0; 
									precioTotal = 0;
									descuento = 0;
									printf("Cuantas desea llevar: "); scanf("%d",&cantidadPizza);
									if(cantidadPizza > 3){
										descuento = (cantidadPizza * 12000) * 0.15;
										precioTotal = (cantidadPizza * 12000) - descuento ;
										system("cls");
										f = fopen( "RECIBO.txt", "w");
										fprintf(f,"\n		JUANITO'S PIZZERIA \n---------------------------------------------------\n---------------------------------------------------\n\nEl Total de su compra es: $ %d\nGracias Por su Compra! Vuelva Pronto", precioTotal);
										fclose(f);
										system("notepad RECIBO.txt");  
									}
									else{
										precioTotal = cantidadPizza * 12000;
										printf("Total: %d \n",precioTotal);
										system("cls");
										f = fopen( "RECIBO.txt", "w");
										fprintf(f,"\n		JUANITO'S PIZZERIA \n---------------------------------------------------\n---------------------------------------------------\n\nEl Total de su compra es: $ %d\nGracias Por su Compra! Vuelva Pronto", precioTotal);
										fclose(f);
										system("notepad RECIBO.txt");	
									}
									break;
									
								case 3:
									cantidadPizza = 0; 
									precioTotal = 0;
									descuento = 0;
									printf("Cuantas desea llevar: "); scanf("%d",&cantidadPizza);
									if(cantidadPizza >= 3){
										descuento = (cantidadPizza * 21000) * 0.25;
										precioTotal = (cantidadPizza * 21000) - descuento ;
										system("cls");
										f = fopen( "RECIBO.txt", "w");
										fprintf(f,"\n		JUANITO'S PIZZERIA \n---------------------------------------------------\n---------------------------------------------------\n\nEl Total de su compra es: $ %d\nGracias Por su Compra! Vuelva Pronto", precioTotal);
										fclose(f);
										system("notepad RECIBO.txt");  
									}
									else{
										precioTotal = cantidadPizza * 21000;
										printf("Total: %d \n",precioTotal);
										system("cls");
										f = fopen( "RECIBO.txt", "w");
										fprintf(f,"\n		JUANITO'S PIZZERIA \n---------------------------------------------------\n---------------------------------------------------\n\nEl Total de su compra es: $ %d\nGracias Por su Compra! Vuelva Pronto", precioTotal);
										fclose(f);
										system("notepad RECIBO.txt");	
									}
									break;
									
								case 4:
									cantidadPizza = 0; 
									precioTotal = 0;
									descuento = 0;
									printf("Cuantas desea llevar: "); scanf("%d",&cantidadPizza);
									if(cantidadPizza >= 3){
										descuento = (cantidadPizza * 30000) * 0.25;
										precioTotal = (cantidadPizza * 30000) - descuento ;
										system("cls");
										f = fopen( "RECIBO.txt", "w");
										fprintf(f,"\n		JUANITO'S PIZZERIA \n---------------------------------------------------\n---------------------------------------------------\n\nEl Total de su compra es: $ %d\nGracias Por su Compra! Vuelva Pronto", precioTotal);
										fclose(f);
										system("notepad RECIBO.txt");  
									}
									else{
										precioTotal = cantidadPizza * 30000;
										printf("Total: %d \n",precioTotal);
										system("cls");
										f = fopen( "RECIBO.txt", "w");
										fprintf(f,"\n		JUANITO'S PIZZERIA \n---------------------------------------------------\n---------------------------------------------------\n\nEl Total de su compra es: $ %d\nGracias Por su Compra! Vuelva Pronto", precioTotal);
										fclose(f);
										system("notepad RECIBO.txt");	
									}
									break;
									
								default: sizePizza(); scanf("%d",&opcion);
										 
							}
							break;
							
							
							case 3:
							system("cls");
							printf("\nPIZZA VEGETARIANA\n");
							sizePizza(); scanf("%d",&opcion);
							
							switch(opcion){
								case 1:
									cantidadPizza = 0; 
									precioTotal = 0;
									descuento = 0;
									printf("Cuantas desea llevar: "); scanf("%d",&cantidadPizza);
									if(cantidadPizza > 3){
										descuento = (cantidadPizza * 4000) * 0.15;
										precioTotal = (cantidadPizza * 4000) - descuento ;
										system("cls");
										f = fopen( "RECIBO.txt", "w");
										fprintf(f,"\n		JUANITO'S PIZZERIA \n---------------------------------------------------\n---------------------------------------------------\n\nEl Total de su compra es: $ %d\nGracias Por su Compra! Vuelva Pronto", precioTotal);
										fclose(f);
										system("notepad RECIBO.txt");  
									}
									else{
										precioTotal = cantidadPizza * 4000;
										printf("Total: %d \n",precioTotal);
										system("cls");
										f = fopen( "RECIBO.txt", "w");
										fprintf(f,"\n		JUANITO'S PIZZERIA \n---------------------------------------------------\n---------------------------------------------------\n\nEl Total de su compra es: $ %d\nGracias Por su Compra! Vuelva Pronto", precioTotal);
										fclose(f);
										system("notepad RECIBO.txt");	
									}
									break;
								
								case 2:
									cantidadPizza = 0; 
									precioTotal = 0;
									descuento = 0;
									printf("Cuantas desea llevar: "); scanf("%d",&cantidadPizza);
									if(cantidadPizza > 3){
										descuento = (cantidadPizza * 12000) * 0.15;
										precioTotal = (cantidadPizza * 12000) - descuento ;
										system("cls");
										f = fopen( "RECIBO.txt", "w");
										fprintf(f,"\n		JUANITO'S PIZZERIA \n---------------------------------------------------\n---------------------------------------------------\n\nEl Total de su compra es: $ %d\nGracias Por su Compra! Vuelva Pronto", precioTotal);
										fclose(f);
										system("notepad RECIBO.txt");  
									}
									else{
										precioTotal = cantidadPizza * 12000;
										printf("Total: %d \n",precioTotal);
										system("cls");
										f = fopen( "RECIBO.txt", "w");
										fprintf(f,"\n		JUANITO'S PIZZERIA \n---------------------------------------------------\n---------------------------------------------------\n\nEl Total de su compra es: $ %d\nGracias Por su Compra! Vuelva Pronto", precioTotal);
										fclose(f);
										system("notepad RECIBO.txt");	
									}
									break;
									
								case 3:
									cantidadPizza = 0; 
									precioTotal = 0;
									descuento = 0;
									printf("Cuantas desea llevar: "); scanf("%d",&cantidadPizza);
									if(cantidadPizza >= 3){
										descuento = (cantidadPizza * 21000) * 0.25;
										precioTotal = (cantidadPizza * 21000) - descuento ;
										system("cls");
										f = fopen( "RECIBO.txt", "w");
										fprintf(f,"\n		JUANITO'S PIZZERIA \n---------------------------------------------------\n---------------------------------------------------\n\nEl Total de su compra es: $ %d\nGracias Por su Compra! Vuelva Pronto", precioTotal);
										fclose(f);
										system("notepad RECIBO.txt");  
									}
									else{
										precioTotal = cantidadPizza * 21000;
										printf("Total: %d \n",precioTotal);
										system("cls");
										f = fopen( "RECIBO.txt", "w");
										fprintf(f,"\n		JUANITO'S PIZZERIA \n---------------------------------------------------\n---------------------------------------------------\n\nEl Total de su compra es: $ %d\nGracias Por su Compra! Vuelva Pronto", precioTotal);
										fclose(f);
										system("notepad RECIBO.txt");	
									}
									break;
									
								case 4:
									cantidadPizza = 0; 
									precioTotal = 0;
									descuento = 0;
									printf("Cuantas desea llevar: "); scanf("%d",&cantidadPizza);
									if(cantidadPizza >= 3){
										descuento = (cantidadPizza * 30000) * 0.25;
										precioTotal = (cantidadPizza * 30000) - descuento ;
										system("cls");
										f = fopen( "RECIBO.txt", "w");
										fprintf(f,"\n		JUANITO'S PIZZERIA \n---------------------------------------------------\n---------------------------------------------------\n\nEl Total de su compra es: $ %d\nGracias Por su Compra! Vuelva Pronto", precioTotal);
										fclose(f);
										system("notepad RECIBO.txt");  
									}
									else{
										precioTotal = cantidadPizza * 30000;
										printf("Total: %d \n",precioTotal);
										system("cls");
										f = fopen( "RECIBO.txt", "w");
										fprintf(f,"\n		JUANITO'S PIZZERIA \n---------------------------------------------------\n---------------------------------------------------\n\nEl Total de su compra es: $ %d\nGracias Por su Compra! Vuelva Pronto", precioTotal);
										fclose(f);
										system("notepad RECIBO.txt");	
									}
									break;	
								default: sizePizza(); scanf("%d",&opcion);
										 
							}
							break;
							
							
							case 4:
							system("cls");
							printf("\nPIZZA Tres Quesos\n");
							sizePizza(); scanf("%d",&opcion);
							
							switch(opcion){
								case 1:
									cantidadPizza = 0; 
									precioTotal = 0;
									descuento = 0;
									printf("Cuantas desea llevar: "); scanf("%d",&cantidadPizza);
									if(cantidadPizza > 3){
										descuento = (cantidadPizza * 4000) * 0.15;
										precioTotal = (cantidadPizza * 4000) - descuento ;
										system("cls");
										f = fopen( "RECIBO.txt", "w");
										fprintf(f,"\n		JUANITO'S PIZZERIA \n---------------------------------------------------\n---------------------------------------------------\n\nEl Total de su compra es: $ %d\nGracias Por su Compra! Vuelva Pronto", precioTotal);
										fclose(f);
										system("notepad RECIBO.txt");  
									}
									else{
										precioTotal = cantidadPizza * 4000;
										printf("Total: %d \n",precioTotal);
										system("cls");
										f = fopen( "RECIBO.txt", "w");
										fprintf(f,"\n		JUANITO'S PIZZERIA \n---------------------------------------------------\n---------------------------------------------------\n\nEl Total de su compra es: $ %d\nGracias Por su Compra! Vuelva Pronto", precioTotal);
										fclose(f);
										system("notepad RECIBO.txt");	
									}
									break;
								
								case 2:
									cantidadPizza = 0; 
									precioTotal = 0;
									descuento = 0;
									printf("Cuantas desea llevar: "); scanf("%d",&cantidadPizza);
									if(cantidadPizza > 3){
										descuento = (cantidadPizza * 12000) * 0.15;
										precioTotal = (cantidadPizza * 12000) - descuento ;
										system("cls");
										f = fopen( "RECIBO.txt", "w");
										fprintf(f,"\n		JUANITO'S PIZZERIA \n---------------------------------------------------\n---------------------------------------------------\n\nEl Total de su compra es: $ %d\nGracias Por su Compra! Vuelva Pronto", precioTotal);
										fclose(f);
										system("notepad RECIBO.txt");  
									}
									else{
										precioTotal = cantidadPizza * 12000;
										printf("Total: %d \n",precioTotal);
										system("cls");
										f = fopen( "RECIBO.txt", "w");
										fprintf(f,"\n		JUANITO'S PIZZERIA \n---------------------------------------------------\n---------------------------------------------------\n\nEl Total de su compra es: $ %d\nGracias Por su Compra! Vuelva Pronto", precioTotal);
										fclose(f);
										system("notepad RECIBO.txt");	
									}
									break;
									
								case 3:
									cantidadPizza = 0; 
									precioTotal = 0;
									descuento = 0;
									printf("Cuantas desea llevar: "); scanf("%d",&cantidadPizza);
									if(cantidadPizza >= 3){
										descuento = (cantidadPizza * 21000) * 0.25;
										precioTotal = (cantidadPizza * 21000) - descuento ;
										system("cls");
										f = fopen( "RECIBO.txt", "w");
										fprintf(f,"\n		JUANITO'S PIZZERIA \n---------------------------------------------------\n---------------------------------------------------\n\nEl Total de su compra es: $ %d\nGracias Por su Compra! Vuelva Pronto", precioTotal);
										fclose(f);
										system("notepad RECIBO.txt");  
									}
									else{
										precioTotal = cantidadPizza * 21000;
										printf("Total: %d \n",precioTotal);
										system("cls");
										f = fopen( "RECIBO.txt", "w");
										fprintf(f,"\n		JUANITO'S PIZZERIA \n---------------------------------------------------\n---------------------------------------------------\n\nEl Total de su compra es: $ %d\nGracias Por su Compra! Vuelva Pronto", precioTotal);
										fclose(f);
										system("notepad RECIBO.txt");	
									}
									break;
									
								case 4:
									cantidadPizza = 0; 
									precioTotal = 0;
									descuento = 0;
									printf("Cuantas desea llevar: "); scanf("%d",&cantidadPizza);
									if(cantidadPizza >= 3){
										descuento = (cantidadPizza * 30000) * 0.25;
										precioTotal = (cantidadPizza * 30000) - descuento ;
										system("cls");
										f = fopen( "RECIBO.txt", "w");
										fprintf(f,"\n		JUANITO'S PIZZERIA \n---------------------------------------------------\n---------------------------------------------------\n\nEl Total de su compra es: $ %d\nGracias Por su Compra! Vuelva Pronto", precioTotal);
										fclose(f);
										system("notepad RECIBO.txt");  
									}
									else{
										precioTotal = cantidadPizza * 30000;
										printf("Total: %d \n",precioTotal);
										system("cls");
										f = fopen( "RECIBO.txt", "w");
										fprintf(f,"\n		JUANITO'S PIZZERIA \n---------------------------------------------------\n---------------------------------------------------\n\nEl Total de su compra es: $ %d\nGracias Por su Compra! Vuelva Pronto", precioTotal);
										fclose(f);
										system("notepad RECIBO.txt");	
									}
									break;
								default: sizePizza(); scanf("%d",&opcion);
										 
								
							}
							break;
							
							
							case 5:
							system("cls");
							printf("\nPIZZA Napolitana\n");
							sizePizza(); scanf("%d",&opcion);
							
							switch(opcion){
								case 1:
									cantidadPizza = 0; 
									precioTotal = 0;
									descuento = 0;
									printf("Cuantas desea llevar: "); scanf("%d",&cantidadPizza);
									if(cantidadPizza > 3){
										descuento = (cantidadPizza * 4000) * 0.15;
										precioTotal = (cantidadPizza * 4000) - descuento ;
										system("cls");
										f = fopen( "RECIBO.txt", "w");
										fprintf(f,"\n		JUANITO'S PIZZERIA \n---------------------------------------------------\n---------------------------------------------------\n\nEl Total de su compra es: $ %d\nGracias Por su Compra! Vuelva Pronto", precioTotal);
										fclose(f);
										system("notepad RECIBO.txt");  
									}
									else{
										precioTotal = cantidadPizza * 4000;
										printf("Total: %d \n",precioTotal);
										system("cls");
										f = fopen( "RECIBO.txt", "w");
										fprintf(f,"\n		JUANITO'S PIZZERIA \n---------------------------------------------------\n---------------------------------------------------\n\nEl Total de su compra es: $ %d\nGracias Por su Compra! Vuelva Pronto", precioTotal);
										fclose(f);
										system("notepad RECIBO.txt");	
									}
									break;
								
								case 2:
									cantidadPizza = 0; 
									precioTotal = 0;
									descuento = 0;
									printf("Cuantas desea llevar: "); scanf("%d",&cantidadPizza);
									if(cantidadPizza > 3){
										descuento = (cantidadPizza * 12000) * 0.15;
										precioTotal = (cantidadPizza * 12000) - descuento ;
										system("cls");
										f = fopen( "RECIBO.txt", "w");
										fprintf(f,"\n		JUANITO'S PIZZERIA \n---------------------------------------------------\n---------------------------------------------------\n\nEl Total de su compra es: $ %d\nGracias Por su Compra! Vuelva Pronto", precioTotal);
										fclose(f);
										system("notepad RECIBO.txt");  
									}
									else{
										precioTotal = cantidadPizza * 12000;
										printf("Total: %d \n",precioTotal);
										system("cls");
										f = fopen( "RECIBO.txt", "w");
										fprintf(f,"\n		JUANITO'S PIZZERIA \n---------------------------------------------------\n---------------------------------------------------\n\nEl Total de su compra es: $ %d\nGracias Por su Compra! Vuelva Pronto", precioTotal);
										fclose(f);
										system("notepad RECIBO.txt");	
									}
									break;
									
								case 3:
									cantidadPizza = 0; 
									precioTotal = 0;
									descuento = 0;
									printf("Cuantas desea llevar: "); scanf("%d",&cantidadPizza);
									if(cantidadPizza >= 3){
										descuento = (cantidadPizza * 21000) * 0.25;
										precioTotal = (cantidadPizza * 21000) - descuento ;
										system("cls");
										f = fopen( "RECIBO.txt", "w");
										fprintf(f,"\n		JUANITO'S PIZZERIA \n---------------------------------------------------\n---------------------------------------------------\n\nEl Total de su compra es: $ %d\nGracias Por su Compra! Vuelva Pronto", precioTotal);
										fclose(f);
										system("notepad RECIBO.txt");  
									}
									else{
										precioTotal = cantidadPizza * 21000;
										printf("Total: %d \n",precioTotal);
										system("cls");
										f = fopen( "RECIBO.txt", "w");
										fprintf(f,"\n		JUANITO'S PIZZERIA \n---------------------------------------------------\n---------------------------------------------------\n\nEl Total de su compra es: $ %d\nGracias Por su Compra! Vuelva Pronto", precioTotal);
										fclose(f);
										system("notepad RECIBO.txt");	
									}
									break;
									
								case 4:
									cantidadPizza = 0; 
									precioTotal = 0;
									descuento = 0;
									printf("Cuantas desea llevar: "); scanf("%d",&cantidadPizza);
									if(cantidadPizza >= 3){
										descuento = (cantidadPizza * 30000) * 0.25;
										precioTotal = (cantidadPizza * 30000) - descuento ;
										system("cls");
										f = fopen( "RECIBO.txt", "w");
										fprintf(f,"\n		JUANITO'S PIZZERIA \n---------------------------------------------------\n---------------------------------------------------\n\nEl Total de su compra es: $ %d\nGracias Por su Compra! Vuelva Pronto", precioTotal);
										fclose(f);
										system("notepad RECIBO.txt");  
									}
									else{
										precioTotal = cantidadPizza * 30000;
										printf("Total: %d \n",precioTotal);
										system("cls");
										f = fopen( "RECIBO.txt", "w");
										fprintf(f,"\n		JUANITO'S PIZZERIA \n---------------------------------------------------\n---------------------------------------------------\n\nEl Total de su compra es: $ %d\nGracias Por su Compra! Vuelva Pronto", precioTotal);
										fclose(f);
										system("notepad RECIBO.txt");	
									}
									break;
								
							}
							break;
							
							case 6:
								system("cls");
								break;
								
							
									 
						}
						break;
							
				}
				else{
					system("cls");	
					printf("\nUSUARIO Y/O CLAVE INCORRECTA\nSe le ha devuelto al Menu Principal por seguridad.\n");	
				}
				
			}
			Beep(500,600);
			break;
			
			case 2:
			system("cls"); 
			printf("\n=== Crear Cuenta ===\n");
			printf("\nUsuario: "); scanf("%s",PIZZERIA[cont].user);
			printf("Clave: "); scanf("%s", &PIZZERIA[cont++].password);
			break;
			
			
			
			case 3:
			system("cls");
			printf("\n ===Buscar Usuario===\n");
			printf("Usuario a Buscar: "); scanf("%s",usuario);
			for(i = 0; i <cont; i++){
				if(strcmp(usuario,PIZZERIA[i].user) == 0){
					printf("\nHola %s es un gusto verte!\n", usuario);
					break;	
				}		
			}
			if(strcmp(usuario,PIZZERIA[i].user)!= 0){
				printf("\nEl usuario %s no existe! Y no puede pedir nuestras pizzas :( \n",usuario);
			}
			break;
			
			
			case 4:
			system("cls");
			printf("\nEliminar Usuario\n");
			printf("Usuario a Eliminar: "); scanf("%s",usuario);
			printf("Clave: "); 
			
			while(caracter = getch()){
				if(caracter == 13){
					clave[i] = '\0'; //ASCII DE LA TECLA ENTER
					break;
				}
				else if(caracter == 8){ // ASCII DE LA TECLA BACKSPACE
					if(i > 0){
						i--;
						printf("\b \b");//SECUENCIA QUE MUEVE EL CURSOR A LA IZQUIERDA	
					}
						
				}else{
					if(i < LONGITUD){
						printf("*");
						clave[i] = caracter;
						i++;
					}
					
				}
				
			}
			
			for(i = 0; i < cont; i++){
				if(strcmp(usuario,PIZZERIA[i].user)== 0){
					for (j = i; j < cont - 1; j++){
						PIZZERIA[j] = PIZZERIA[j + 1];
						
					}
					cont--;
					printf("\nSe ha eliminado al usuario %s\n",usuario);
					break;
				}
				
				else{
					printf("\nERROR 777! El usuario %s no existe o ya fue eliminado.\n",usuario);
				}
			}//problema. SE ELIMINA EL USUARIO PERO IMPRIME LO QUE ESTA EN ESTE IF. ERROR 777 EL USUARIO NO EXISTE O YA FUE ELIMINADO
			break;
			
			
			case 5:
			system("cls");
			printf("Lista de Usuarios\n\n");
			printf("      Nombre\n");
			for( i = 0; i < cont; i++){
				printf("      %s\n", PIZZERIA[i].user);
			}
			break;	
		}
		
	}while(opcion !=0);
	

	salvar = fopen( "Pizzeria.dat", "wb" );
	fwrite( &cont, sizeof( int ), 1, salvar );
	fwrite( PIZZERIA, sizeof( cliente ), 100, salvar );
	fclose( salvar );
	printf( "\n*** se salvaron %d registros con exito\n", cont );

	
	return 0;
}
