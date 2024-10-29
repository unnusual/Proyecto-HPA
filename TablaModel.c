#include <stdio.h>
#include <locale.h>
#define NUM_EMPLEADOS 5

void ingresarDatos(char nombres[][50], char cedulas[][20], int aservicio[], float salario_bruto[]);
int validarAniosServicio(int anios);
float calcularAumento(float salario_bruto, int anios);
void calcularMayorMenor(float salario_neto[], int *indiceMayor, int *indiceMenor);
void imprimirInforme(char nombres[][50], char cedulas[][20], int aservicio[], float salario_bruto[], float salario_neto[], float aumentos[]);

int main() {
    setlocale(LC_CTYPE, "spanish");

    char nombres[NUM_EMPLEADOS][50];
    char cedulas[NUM_EMPLEADOS][20];
    int aservicio[NUM_EMPLEADOS];
    float salario_bruto[NUM_EMPLEADOS];
    float salario_neto[NUM_EMPLEADOS];
    float aumentos[NUM_EMPLEADOS];  

    ingresarDatos(nombres, cedulas, aservicio, salario_bruto);

    for (int i = 0; i < NUM_EMPLEADOS; i++) {
        if (validarAniosServicio(aservicio[i])) {
            aumentos[i] = calcularAumento(salario_bruto[i], aservicio[i]);
            salario_neto[i] = salario_bruto[i] + aumentos[i];
        } else {
            aumentos[i] = 0;  
            salario_neto[i] = salario_bruto[i]; 
        }
    }

    imprimirInforme(nombres, cedulas, aservicio, salario_bruto, salario_neto, aumentos);

}

void ingresarDatos(char nombres[][50], char cedulas[][20], int aservicio[], float salario_bruto[]) {
    for (int i = 0; i < NUM_EMPLEADOS; i++) {
        printf("\nEmpleado %d\n", i + 1);
        printf("Nombre: ");
        scanf(" %[^\n]", nombres[i]);
        printf("Cedula: ");
        scanf(" %[^\n]", cedulas[i]);

        do {
            printf("Años de servicio: ");
            scanf("%d", &aservicio[i]);
            if (aservicio[i] <= 0) {
                printf("Por favor, ingrese un valor positivo para los años de servicio.\n");
            }
        } while (aservicio[i] <= 0);

        printf("Salario bruto: ");
        scanf("%f", &salario_bruto[i]);
    }
}

int validarAniosServicio(int anios) {
    return anios > 0; 
}

float calcularAumento(float salario_bruto, int anios) {
    float porcentaje = 0.0;

    if (salario_bruto >= 100 && salario_bruto < 300) {
        porcentaje = (anios > 3) ? 0.03 : 0.02;
    } else if (salario_bruto >= 300 && salario_bruto < 500) {
        porcentaje = (anios > 3) ? 0.06 : 0.04;
    } else if (salario_bruto >= 500 && salario_bruto < 800) {
        porcentaje = (anios > 3) ? 0.08 : 0.07;
    } else if (salario_bruto >= 800 && salario_bruto < 1000) {
        porcentaje = (anios > 3) ? 0.10 : 0.09;
    } else if (salario_bruto >= 1000 && salario_bruto < 2000) {
        porcentaje = (anios > 5) ? 0.13 : 0.0;
    } else if (salario_bruto >= 2000 && anios > 10) {
        porcentaje = 0.15;
    }

    return salario_bruto * porcentaje;
}

void calcularMayorMenor(float salario_neto[], int *indiceMayor, int *indiceMenor) {
    *indiceMayor = *indiceMenor = 0;
    for (int i = 1; i < NUM_EMPLEADOS; i++) {
        if (salario_neto[i] > salario_neto[*indiceMayor]) {
            *indiceMayor = i;
        }
        if (salario_neto[i] < salario_neto[*indiceMenor]) {
            *indiceMenor = i;
        }
    }
}

void imprimirInforme(char nombres[][50], char cedulas[][20], int aservicio[], float salario_bruto[], float salario_neto[], float aumentos[]) {
    float totalBruto = 0.0, totalNeto = 0.0;
    int indiceMayor, indiceMenor;

    for (int i = 0; i < NUM_EMPLEADOS; i++) {
        totalBruto += salario_bruto[i];
        totalNeto += salario_neto[i];
    }

    calcularMayorMenor(salario_neto, &indiceMayor, &indiceMenor);

    printf("\n\t\tBANCO PANAMEÑO DE PRODUCCION\n");
    printf("\t\tLISTADO DE AUMENTO SALARIAL\n\n");
    printf("NOMBRE\t\tCEDULA\t\tAÑOS\tSALARIO BRUTO\tAUMENTO\tSALARIO NETO\n");
    for (int i = 0; i < NUM_EMPLEADOS; i++) {
        printf("%-10s\t%-10s\t%d\t%.2f\t\t%.2f\t%.2f\n", nombres[i], cedulas[i], aservicio[i], salario_bruto[i], aumentos[i], salario_neto[i]);
    }

    printf("\nTOTALES:\t\t\t\t%.2f\t%.2f\n", totalBruto, totalNeto);
    printf("EMPLEADO DE MAYOR SUELDO: %s\t%.2f\n", nombres[indiceMayor], salario_neto[indiceMayor]);
    printf("EMPLEADO DE MENOR SUELDO: %s\t%.2f\n", nombres[indiceMenor], salario_neto[indiceMenor]);
}
