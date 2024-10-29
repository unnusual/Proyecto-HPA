/*
Este proyecto tiene por fin...

Integrantes:
David Roa
Miguel Man
Lianeth Gonzalez
Xavier Cisneros
*/


#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int mostrarMenu(){
	int opcion;
	
	printf("\t\t\t\tMenï¿½\n\n");
	printf("\t\t1. Presentaciï¿½n\n");
	printf("\t\t2. Banco Panameï¿½o de Producciï¿½n\n");
	printf("\t\t3. Salir\n\n");
	printf("\t\tIntroduce tu opciï¿½n: ");
	scanf("%d", &opcion);
	
	return opcion;
}

int main () {
	setlocale(LC_ALL, "");
	int opcion, i=0, j=0, tam2;
	char tam[20];
	int valores[tam2][4];
	char nombre[tam2][20], cedula[tam2][20];
	
	printf("\t\tUniversidad Tecnolï¿½gica de Panamï¿½\n");
	printf("\t Facultad de Ingenierï¿½a de Sistemas Computacionales\n");
	printf("\t       Herramientas de Programaciï¿½n Aplicada I\n");
	printf("\t\t\t    Proyecto N.1\n\n");
	
	do{
		opcion = mostrarMenu();
		
		switch (opcion){
			case 1: {
				printf("\n\nFUNCIONES y ARREGLOS\n\n");
				printf("Integrantes: ");
				printf("Miguel Man\t       8-1032-360\n");
				printf("\t     David Roa\t       20-14-8042\n");
				printf("\t     Xavier Cisneros   8-1032-384\n");
				printf("\t     Lianeth Gonzalez  8-1032-f323\n\n");
				printf("\tProfesora: Janitza Barraza\n\n");
				printf("\t Fecha: 26 de octubre de 2024");
				break;
			}
			case 2:{
				do{
					printf("\t\tIngrese la cantidad de registros que desea procesar: ");
					fgets(tam, sizeof(tam), stdin);
					
					tam2 = atoi(tam);
					
					if (tam2 < 1) {
            			printf("\t\tError, debes ingresar un entero positivo.\n");
           				while (getchar() != '\n'); // Limpiar el buffer
            			continue;  // Repetir el ciclo
        			}

        			// Limpiar el buffer si es necesario
        			while (getchar() != '\n');
    			} while (tam2 < 1);
				
				printf("Ingrese los siguientes datos: ");
					for(i; i<tam2; i++){
						printf("\nNombre: ");
						fgets(nombre[i], 20, stdin);
					
						printf("\nCï¿½dula: ");
						fgets(cedula[i], 20, stdin);
						
						for(j=0; j<4; j++){
							printf("\nAï¿½os ");
							scanf("%f", &valores[i][j]);
						}
				}
				
				
				printf("\n\n\t\t\tBANCO PANAMEï¿½O DE PRODUCCIï¿½N\n");
				printf("\t\t\t LISTADO DE AUMENTO SALARIAL\n\n");
				printf("\t    NOMBRE\t");
				printf("Cï¿½DULA\t");
				printf("  Aï¿½OS\t");
				printf("   SALARIO");
				printf("  AUMENTO");
				printf("  SALARIO");
				printf("\n\t\t\t\t  SERVICIO");
				
				break;
			}
			case 3: {
				break;
			}
			default:{
				printf("Error: Opciï¿½n invï¿½lida\n");
				break;
			}	
		}
		
		if(opcion !=3)
		printf("\nPresiona Enter para volver al menï¿½...");
    	getchar();
    	getchar();
        
	}while(opcion != 3);
}
