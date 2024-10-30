/*
Este proyecto tiene como finalidad calcular el aumento de los salarios de los empleados del
Banco Panameno de Produccion segun sus salarios y anios de servicio

Integrantes:
David Roa
Miguel Man
Lianeth Gonzalez
Xavier Cisneros
*/

// librerias a utilizar
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

// Declaracion de funciones a utilizar
void imprimirDatos();
int mostrarMenu();
void validarServicio(int i, int vector[]);
float calcularAumento(float salario_bruto, int anios);
float calcularSalNet(float salario_bruto, int anios);
int encontrarMayor(int arr[], int size);
int encontrarMenor(int arr[], int size);
void printINF(char nombres[][35], char cedulas[][15], int aservicio[], float salario_bruto[], float salario_neto[], float aumentos[], int n);   

// Funcion principal, contiene un switch case para alternar las opciones del menu
int main ()
{
	setlocale(LC_ALL, "");
	// Declaracion de variables
	int opcion, numEMP, i, aservicio[20];
	float salario[20], neto[20], aumentos[20] ;
	char nombre[20][35], cedula[20][15];
	

	// Se utiliza un do while para que el menu siempre este presente
	// Solamente termina si la opcion elegida es 3
	do{
		system("cls");
		opcion = mostrarMenu();
		system("cls");
		switch(opcion)
		{
			// caso 1 imprime los datos del grupo del proyecto
			case 1: 
				imprimirDatos();
				getchar();
				break;
				
			// caso 2 se encarga de la impresion de la lista de empleados
			case 2:
				/* Primero preguntamos cuantos empleados vamos a registrar, usando 
				un do while para que se repita en caso de que el valor ingresado no sea entero positivo*/
				do{	
					system("cls");
					printf("Ingrese la cantidad de registros que desea procesar: ");
					scanf(" %d", &numEMP);
					if (numEMP < 1) 					
            			printf("Error, debes ingresar un dato valido, entero positivo.");
            		getchar();
				
    			} while (numEMP < 1);
				
				/* Despues en el for se piden los datos del empleado, cada iteracion del for siendo
				1 empleado de la cantidad ingresada en numEMP. Estos datos seran almacenados en arreglos
				lo que nos permite tener un orden y poder manipularlos de forma eficiente*/
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
				/* Despues de ingresar todos los datos y salir del for, llamamos a la 
				funcion de salida que imprimira el listado completo*/
				printINF(nombre, cedula, aservicio, salario, neto, aumentos, numEMP);
				getchar();
				break;
			
			// En el caso 3 se sale del switch case y se sale del do while al ser la opcion de salida del programa
			case 3: 
				getchar();
				break;
			
			//Como default tenemos un mensaje de error para ingresar las opciones validas
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

//Funcion que imprime el listado de datos del caso 1
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
/*Funcion que imprime el menu que aparece al iniciar el programa,
a su vez retorna la opcion a elegir*/
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

/*Funcion que valida que el dato ingresado sea un numero entero positivo,
permite que a pesar de poder ingresarse caracteres, solo prosiga si se ingresa
un valor numerico entero y posittivo*/
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

/*Funcion que calculara el aumento correspondiente al salario bruto y años de 
servicio ingresado de acuerdo a lo especificado, si el valor de alguno de estos no se
encuentra en el enunciado, el valor del aumento sera 0*/
float calcularAumento(float salario_bruto, int anios) 
{
	float porcentaje = 0.0;
	if(anios >= 1)
	{
    		if ((salario_bruto >= 100) && (salario_bruto < 300))
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

/*Funcion que calcula el salario neto apartir del salario bruto
y el aumento calculado en la funcion anterior*/
float calcularSalNet(float salario_bruto, int anios)
{
	float salNet;
	salNet= salario_bruto + calcularAumento(salario_bruto, anios);
	return salNet;
}

/* Función para encontrar el indice del valor máximo
este nos permitira imprimir el nombre y el valor del sueldo neto
correspondiente*/
int encontrarMayor(float arr[], int size) 
{
    float max = 0, x;
    for (int i = 0; i < size; i++)
	 {
        if (max < arr[i])
    	{
            max = arr[i];
            x=i;
        }
    }
    return x;
}
/*Función para encontrar el indice del valor minimo, este nos permitira 
imprimir el nombre y el valor del sueldo neto correspondiente*/
int encontrarMenor(float arr[], int size) 
{
    float min = arr[0], x;
    for (int i = 0; i < size; i++)
	 {
        if (arr[i] <= min)
        {
            min = arr[i];
            x=i;
        }
    }
    return x;
}


//Funcion de salida del listado con todos los datos
void printINF(char nombres[][35], char cedulas[][15], int aservicio[], float salario_bruto[], float salario_neto[], float aumentos[], int n)
{
    float totalBruto = 0.0, totalNeto = 0.0, x[20];
	int a, b; 
	char mayor[35], menor[35];
    
    printf("\n\t\t\tBANCO PANAMEÑO DE PRODUCCION\n");
    printf("\t\t\t LISTADO DE AUMENTO SALARIAL\n\n");
    printf("NOMBRE\t\tCEDULA\t\tAÑOS\tSALARIO BRUTO\t AUMENTO\tSALARIO NETO\n");
    for (int i = 0; i < n; i++) 
	{
		totalBruto += salario_bruto[i];
		x[i] = calcularSalNet(salario_bruto[i],aservicio[i]);
        totalNeto += x[i];
        printf("%-10s\t%-10s\t%d\t%.2f\t         %.2f\t       %.2f\n", nombres[i], cedulas[i], aservicio[i], salario_bruto[i], calcularAumento(salario_bruto[i],aservicio[i]), x[i]);
    
    }
    a= encontrarMayor(x,n);
	b= encontrarMenor(x,n);
    printf("\nTOTALES:\t\t\t\t%.2f\t\t\t     %.2f\n", totalBruto, totalNeto);
    printf("EMPLEADO DE MAYOR SUELDO: %s\t%.2f\n", nombres[a],x[a] );
    printf("EMPLEADO DE MENOR SUELDO: %s\t%.2f\n", nombres[b],x[b] );
}
