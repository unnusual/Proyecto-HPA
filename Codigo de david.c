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

//declaración de funciones a utilizar, buena práctica
void imprimirDatos();
int mostrarMenu();
void validarServicio(int i, int vector[]);
float calcularAumento(float salario_bruto, int anios);
float calcularSalNet(float salario_bruto, int anios);
int encontrarMaximo(float arr[], int size);
int encontrarMinimo(float arr[], int size);
void printINF(char nombres[][35], char cedulas[][15], int aservicio[], float salario_bruto[], float salario_neto[], float aumentos[], int n);   

int main ()
{
	setlocale(LC_ALL, "");//permite el uso del acento y ñ en el español, adopta el lenguaje de la máquina
	//declaración de variables
	int opcion, numEMP, i, aservicio[20];
	float salario[20], neto[20], aumentos[20] ;
	char nombre[20][35], cedula[20][15];
	

	
	do{
		system("cls");//limpia la pantalla
		opcion = mostrarMenu();//muestra el menú de opciones 
		system("cls");
		switch(opcion)
		{
		
			case 1: 
				imprimirDatos();//muestra en pantalla la información del proyecto, integrantes, facilitadora, fecha de entrega
				getchar();
				break;
			
			case 2:
				do{	
					system("cls");
					printf("Ingrese la cantidad de registros que desea procesar: ");
					scanf(" %d", &numEMP);
					if (numEMP < 1) 					//comprueba que el número sea mayor que cero, entero, y que no sea un caracter
            			printf("Error, debes ingresar un dato valido, entero positivo.");
            		getchar();
				
    			} while (numEMP < 1);//repite el ciclo mientras ingrese un valor no permitido
				
				for(i=0; i<numEMP; i++)
				{
					printf("\nIngrese los datos del empleado %d: ",(i+1));
					printf("\nNombre: ");
					gets(nombre[i]);

					printf("Cédula: ");
					gets(cedula[i]);
				
					validarServicio(i, aservicio);
					getchar();
					
					printf("Salario actual: ");
					scanf(" %f", &salario[i]);
					getchar();					
				}
				printINF(nombre, cedula, aservicio, salario, neto, aumentos, numEMP); //tabla con la información de la producción
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
void imprimirDatos()
{
	printf("\t\tUniversidad Tecnológica de Panamá\n");
	printf("\t Facultad de Ingeniería de Sistemas Computacionales\n");
	printf("\t       Herramientas de Programación Aplicada I\n");
	printf("\t\t\t    Proyecto N.1\n\n");
	printf("\n\t\t\tFUNCIONES y ARREGLOS\n\n");
	printf("\t\tIntegrantes: ");
	printf("Miguel Man\t       8-1032-360\n");
	printf("\t\t\t     David Roa\t       20-14-8042\n");
	printf("\t\t\t     Xavier Cisneros   8-1032-384\n");
	printf("\t\t\t     Lianeth Gonzalez  8-1032-f323\n\n");
	printf("\t\t     Profesora: Janitza Barraza\n\n");
	printf("\t\t     Fecha: 30 de octubre de 2024");
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

void validarServicio(int i, int vector[])
{
    int x;
    do {
        printf("Años de servicio: ");
        x = scanf("%d", &vector[i]);

        if (x != 1 || vector[i] < 1)
		{
            printf("\t\tError, debes ingresar un número entero positivo.\n");
            while(getchar() != '\n');
        }

    } while (x != 1 || vector[i] < 1);
}

float calcularAumento(float salario_bruto, int anios) 
{
	float porcentaje = 0.0;
	if(anios >= 1)
	{
    		if ((salario_bruto >= 100) && (salario_bruto < 300))//condiones para el aumento del salario de cada persona según su salario bruto y años de servicio
        		porcentaje = (anios > 3) ? 0.03 : 0.02;
    		else if ((salario_bruto >= 300) && (salario_bruto < 500))
			porcentaje = (anios > 3) ? 0.06 : 0.04;
    		else if ((salario_bruto >= 500) && (salario_bruto < 800))
			porcentaje = (anios > 3) ? 0.08 : 0.07;
    		else if ((salario_bruto >= 800) && (salario_bruto < 1000)) 
			porcentaje = (anios > 3) ? 0.10 : 0.09;
    		else if ((salario_bruto >= 1000) && (salario_bruto < 2000) && (anios > 5)) 
       			porcentaje = 0.13;
    		else if ((salario_bruto >= 2000) && (anios > 10)) 
       			porcentaje = 0.15;
		return salario_bruto * porcentaje;
	}
	else
		return porcentaje;
}

float calcularSalNet(float salario_bruto, int anios)
{
	float salNet;
	salNet= salario_bruto + calcularAumento(salario_bruto, anios);
	return salNet;
}

int encontrarMaximo(float arr[], int size) {
    int maxIdx = 0;
    for (int i = 1; i < size; i++)
        if (arr[i] > arr[maxIdx])
            maxIdx = i;
    return maxIdx;
}

int encontrarMinimo(float arr[], int size) {
    int minIdx = 0;
    for (int i = 1; i < size; i++)
        if (arr[i] < arr[minIdx])
            minIdx = i;
    return minIdx;
}

void printINF(char nombres[][35], char cedulas[][15], int aservicio[], float salario_bruto[], float salario_neto[], float aumentos[], int n) {
    float totalBruto = 0.0, totalNeto = 0.0, x[30];
    
    printf("\n\t\tBANCO PANAMEÑO DE PRODUCCION\n");
    printf("\t\tLISTADO DE AUMENTO SALARIAL\n\n");
    printf("NOMBRE\t\tCEDULA\t\tAÑOS\tSALARIO BRUTO\tAUMENTO\tSALARIO NETO\n");
    for (int i = 0; i < n; i++) {
        totalBruto += salario_bruto[i];
        x[i] = calcularSalNet(salario_bruto[i], aservicio[i]);
        totalNeto += x[i];
        printf("%-10s\t%-10s\t%d\t%.2f\t\t%.2f\t   %.2f\n", nombres[i], cedulas[i], aservicio[i], salario_bruto[i], calcularAumento(salario_bruto[i], aservicio[i]), x[i]);
    }
    
    int indiceMayor = encontrarMaximo(x, n);
    int indiceMenor = encontrarMinimo(x, n);

    printf("\nTOTALES:\t\t\t\t%.2f\t\t\t%.2f\n", totalBruto, totalNeto);
    printf("EMPLEADO DE MAYOR SUELDO: %s\t%.2f\n", nombres[indiceMayor], x[indiceMayor]);
    printf("EMPLEADO DE MENOR SUELDO: %s\t%.2f\n", nombres[indiceMenor], x[indiceMenor]);
}
