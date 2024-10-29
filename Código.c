/*
Este proyecto tiene como finalidad calcular el aumento de los salarios de los empleados del
Banco Panameno de Produccion segun sus salarios y anios de servicio

Integrantes:
David Roa
Miguel Man
Lianeth Gonzalez
Xavier Cisneros
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
void imprimirDatos();
void validarServicio(int i, int vector[]);
float obtenerAumento();
float calcularSalNet();
void encontrarMayor();
void encontrarMenor();
int mostrarMenu();

int main ()
{
	setlocale(LC_ALL, "");
	int opcion, numEMP, i, a[20];
	float salario[20];
	char nombre[20][35], cedula[20][15], nombreMayor[35], nombreMenor[35];
	

	
	do{
		system("cls");
		opcion = mostrarMenu();
		system("cls");
		switch(opcion)
		{
		
			case 1: 
				imprimirDatos();
				getchar();
				break;
			
			case 2:
				do{	
					system("cls");
					printf("Ingrese la cantidad de registros que desea procesar: ");
					scanf(" %d", &numEMP);
					if (numEMP < 1) 					
            			printf("Error, debes ingresar un dato valido, entero positivo.");
            		getchar();
				
    			} while (numEMP < 1);
				
				for(i=0; i<numEMP; i++)
				{
					printf("\nIngrese los datos del empleado %d: ",(i+1));
					printf("\nNombre: ");
					gets(nombre[i]);

					printf("Cédula: ");
					gets(cedula[i]);
				
					validarServicio(i, a);
					getchar();
					
					printf("Salario actual: ");
					scanf(" %f", &salario[i]);
					getchar();				
				
				}
				for(i=0; i<numEMP; i++) //prueba de almacenaje
				{
					printf("\nnombre: ");
					puts(nombre[i]);
					printf("cedula: ");	
					puts(cedula[i]);
					printf("Años de servicio: %d", a[i]);
					printf("\nSalario actual: %.2f", salario[i]);
				}
				getchar();
				
				break;
			
			case 3: 
				getchar();
				break;
			
			default:
				printf("Error: Opción inválida\nIngrese un valor de 1 a 3\n");
				getchar();
				break;
		}
	if(opcion != 3)
		printf("\n\nPresiona Enter para volver al menú...");
	getchar();
	}while(opcion != 3);
}

int mostrarMenu()
{
	int opcion;
	printf("\t\tUniversidad Tecnológica de Panamá\n");
	printf("\t Facultad de Ingeniería de Sistemas Computacionales\n");
	printf("\t       Herramientas de Programación Aplicada I\n");
	printf("\t\t\t    Proyecto N.1\n\n");
	printf("\t\t\t\tMenú\n\n");
	printf("\t\t1. Presentación\n");
	printf("\t\t2. Banco Panameño de Producción\n");
	printf("\t\t3. Salir\n\n");
	printf("\t\tIntroduce tu opción: ");
	scanf("%d", &opcion);
	
	return opcion;
}
void imprimirDatos()
{
	printf("\t\tUniversidad Tecnológica de Panamá\n");
	printf("\t Facultad de Ingeniería de Sistemas Computacionales\n");
	printf("\t       Herramientas de Programación Aplicada I\n");
	printf("\t\t\t    Proyecto N.1\n\n");
	printf("\n\t\t\tFUNCIONES y ARREGLOS\n\n");
	printf("Integrantes: ");
	printf("Miguel Man\t       8-1032-360\n");
	printf("\t     David Roa\t       20-14-8042\n");
	printf("\t     Xavier Cisneros   8-1032-384\n");
	printf("\t     Lianeth Gonzalez  8-1032-f323\n\n");
	printf("\t     Profesora: Janitza Barraza\n\n");
	printf("\t     Fecha: 26 de octubre de 2024");
}

void validarServicio(int i, int vector[])
{
	do
	{
		printf("Años de servicio: ");
		scanf(" %d", &vector[i]);
		if(vector[i]<1)
			printf("\t\tError, debes ingresar un entero positivo.\n");
			
	}while(vector[i]<1);		
}

float obtenerAumento()
{
	
}

float calcularSalNet()
{
}


void encontrarMayor()
{
}
void encontrarMenor()
{
}
