#include "carteles.h"

void menu() {
    renglon(); renglon();
    printf("     _____________________________________________________________________\n"
           "    |                                                                     |\n"
           "    |    1. Cargar desde el archivo data.csv (modo texto)                 |\n"
           "    |    2. Cargar desde el archivo data.bin (modo binario)               |\n"
           "    |_____________________________________________________________________|\n"
           "    |                                                                     |\n"
           "    |    3. Alta de empleado                                              |\n"
           "    |    4. Modificar datos de empleado                                   |\n"
           "    |    5. Baja de empleado                                              |\n"
           "    |    6. Listar empleados                                              |\n"
           "    |    7. Ordenar empleados                                             |\n"
           "    |_____________________________________________________________________|\n"
           "    |                                                                     |\n"
           "    |    8. Guardar empleados en el archivo data.csv (modo texto)         |\n"
           "    |    9. Guardar empleados en el archivo data.bin (modo binario)       |\n"
           "    |_____________________________________________________________________|\n"
           "    |                                                                     |\n"
           "    |    10. Salir                                                        |\n"
           "    |_____________________________________________________________________|\n\n\n");
}

void c_empleadoDadoDeBaja(){
    renglon();
    printf("                                                            /\n");
    printf("                         _________________________         /\n");
    printf("                        |                         |       /\n");
    printf("                        |  Empleado dado de baja  |   %c  /\n", 92);
    printf("                        |_________________________|    %c/  ", 92);
}

void c_noSeEncontroEmpleado() {
    renglon(); renglon();
    printf("                       ____________________________\n");
    printf("                      |                            |\n");
    printf("                      |  No se encontr%c empleado   |\n", 162);
    printf("                      |____________________________|\n\n");
}

void c_nombreModificado() {
    renglon();
    printf("                                                           /\n");
    printf("                          _______________________         /\n");
    printf("                         |                       |       /\n");
    printf("                         |   Nombre modificado   |   %c  /\n", 92);
    printf("                         |_______________________|    %c/", 92);
}

void c_horasModificado() {
    renglon();
    printf("                                                              /\n");
    printf("                      ______________________________         /\n");
    printf("                     |                              |       /\n");
    printf("                     |   Carga horaria modificada   |   %c  /\n", 92);
    printf("                     |______________________________|    %c/", 92);
}

void c_salarioModificado() {
    renglon();
    printf("                                                           /\n");
    printf("                         ________________________         /\n");
    printf("                        |                        |       /\n");
    printf("                        |   Salario modificado   |   %c  /\n", 92);
    printf("                        |________________________|    %c/", 92);
}

void c_altaDeEmpleado() {
    renglon(); renglon();
    printf("                           _____________________\n");
    printf("                          |                     |\n");
    printf("                          |  Alta de empleado   |\n");
    printf("                          |_____________________|\n\n\n");
}

void c_empleadoDadoDeAlta(){
    renglon(); renglon();
    printf("                                                            /\n");
    printf("                         _________________________         /\n");
    printf("                        |                         |       /\n");
    printf("                        |  Empleado dado de alta  |   %c  /\n", 92);
    printf("                        |_________________________|    %c/  ", 92);
}

void c_noHayEmpleadosEnElSistema() {
    short f;
    system("cls");
    renglon(); renglon();
    printf("     _____________________________________________________________________\n"
           "    |                                                                     |\n"
           "    |    1. Cargar desde el archivo data.csv (modo texto)                 |\n"
           "    |    2. Cargar desde el archivo data.bin (modo binario)               |\n"
           "    |_____________________________________________________________________|\n"
           "    |                                                                     |\n"
           "    |    3. Alta de empleado                                              |\n"
           "    |    4. Modifica  ");
    for (f=0 ; f<36 ; f++) {
        printf("%c", 178);
    }
    printf("                |\n"
           "    |    5. Baja de e|                                    |               |\n"
           "    |    6. Listar em|   No hay empleados en el sistema   |               |\n"
           "    |    7. Ordenar e|____________________________________|               |\n"
           "    |_____________________________________________________________________|\n"
           "    |                                                                     |\n"
           "    |    8. Guardar empleados en el archivo data.csv (modo texto)         |\n"
           "    |    9. Guardar empleados en el archivo data.bin (modo binario)       |\n"
           "    |_____________________________________________________________________|\n"
           "    |                                                                     |\n"
           "    |    10. Salir                                                        |\n"
           "    |_____________________________________________________________________|\n\n");
}

void c_primeroCargueUnArchivo() {
    short f;
    system("cls");
    renglon(); renglon();
    printf("     _____________________________________________________________________\n"
           "    |                                                                     |\n"
           "    |    1. Cargar desde el archivo data.csv (modo texto)                 |\n"
           "    |    2. Cargar desde el archivo data.bin (modo binario)               |\n"
           "    |_____________________________________________________________________|\n"
           "    |                                                                     |\n"
           "    |    3. Alta de empleado                                              |\n"
           "    |    4. Mod ");
    for (f=0 ; f<49 ; f++) {
        printf("%c", 178);
    }
    printf("         |\n"
           "    |    5. Baj|                                                 |        |\n"
           "    |    6. Lim|   No se puede calcular ID                       |        |\n"
           "    |    7. Ord|   Por favor, cargue la lista desde un archivo   |        |\n"
           "    |__________|_________________________________________________|________|\n"
           "    |                                                                     |\n"
           "    |    8. Guardar empleados en el archivo data.csv (modo texto)         |\n"
           "    |    9. Guardar empleados en el archivo data.bin (modo binario)       |\n"
           "    |_____________________________________________________________________|\n"
           "    |                                                                     |\n"
           "    |    10. Salir                                                        |\n"
           "    |_____________________________________________________________________|\n\n");
}

void c_listaCargada(int amount) {
    short f;
    system("cls");
    renglon(); renglon();
    printf("     _____________________________________________________________________\n"
           "    |                                                                     |\n"
           "    |    1. Cargar desde el archivo data.csv (modo texto)                 |\n"
           "    |    2. Cargar desde el archivo data.bin (modo binario)               |\n"
           "    |_____________________________________________________________________|\n"
           "    |                                                                     |\n"
           "    |    3. Alta de empleado                                              |\n"
           "    |    4. Modificar  ");
    for (f=0 ; f<33 ; f++) {
        printf("%c", 178);
    }
    printf("                  |\n"
           "    |    5. Baja de em|                                 |                 |\n"
           "    |    6. Listar emp|   Archivo cargado               |                 |\n"
           "    |    7. Ordenar em|   Empleados encontrados: %4d   |                 |\n"
           "    |_________________|_________________________________|_________________|\n"
           "    |                                                                     |\n"
           "    |    8. Guardar empleados en el archivo data.csv (modo texto)         |\n"
           "    |    9. Guardar empleados en el archivo data.bin (modo binario)       |\n"
           "    |_____________________________________________________________________|\n"
           "    |                                                                     |\n"
           "    |    10. Salir                                                        |\n"
           "    |_____________________________________________________________________|\n\n", amount);
}

void c_archivoYaCargado() {
    short f;
    system("cls");
    renglon(); renglon();
    printf("     _____________________________________________________________________\n"
           "    |                                                                     |\n"
           "    |    1. Cargar desde el archivo data.csv (modo texto)                 |\n"
           "    |    2. Cargar desde el archivo data.bin (modo binario)               |\n"
           "    |_____________________________________________________________________|\n"
           "    |                                                                     |\n"
           "    |    3. Alta de empleado                                              |\n"
           "    |    4. Modificar dato ");
    for (f=0 ; f<24 ; f++) {
        printf("%c", 178);
    }
    printf("                       |\n"
           "    |    5. Baja de emplea|                        |                      |\n"
           "    |    6. Listar emplead|   Archivo ya cargado   |                      |\n"
           "    |    7. Ordenar emplea|________________________|                      |\n"
           "    |_____________________________________________________________________|\n"
           "    |                                                                     |\n"
           "    |    8. Guardar empleados en el archivo data.csv (modo texto)         |\n"
           "    |    9. Guardar empleados en el archivo data.bin (modo binario)       |\n"
           "    |_____________________________________________________________________|\n"
           "    |                                                                     |\n"
           "    |    10. Salir                                                        |\n"
           "    |_____________________________________________________________________|\n\n");
}

void c_archivoGuardado() {
    short f;
    system("cls");
    renglon(); renglon();
    printf("     _____________________________________________________________________\n"
           "    |                                                                     |\n"
           "    |    1. Cargar desde el archivo data.csv (modo texto)                 |\n"
           "    |    2. Cargar desde el archivo data.bin (modo binario)               |\n"
           "    |_____________________________________________________________________|\n"
           "    |                                                                     |\n"
           "    |    3. Alta de empleado                                              |\n"
           "    |    4. Modificar datos ");
    for (f=0 ; f<22 ; f++) {
        printf("%c", 178);
    }
    printf("                        |\n"
           "    |    5. Baja de emplead|                      |                       |\n"
           "    |    6. Listar empleado|   Archivo guardado   |                       |\n"
           "    |    7. Ordenar emplead|______________________|                       |\n"
           "    |_____________________________________________________________________|\n"
           "    |                                                                     |\n"
           "    |    8. Guardar empleados en el archivo data.csv (modo texto)         |\n"
           "    |    9. Guardar empleados en el archivo data.bin (modo binario)       |\n"
           "    |_____________________________________________________________________|\n"
           "    |                                                                     |\n"
           "    |    10. Salir                                                        |\n"
           "    |_____________________________________________________________________|\n\n");
}

void printEditMenu() {
    renglon();
    printf("                      __________________________________\n"
           "                     |                                  |\n"
           "                     |    1. Nombre                     |\n"
           "                     |    2. Horas                      |\n"
           "                     |    3. Salario                    |\n"
           "                     |__________________________________|\n"
           "                     |                                  |\n"
           "                     |    4. Atr%cs                      |\n"
           "                     |__________________________________|\n\n", 160);
}

void printSortMenu() {
    renglon();
    printf("                      __________________________________\n"
           "                     |                                  |\n"
           "                     |    1. ID                         |\n"
           "                     |    2. Nombre                     |\n"
           "                     |    3. Horas                      |\n"
           "                     |    4. Salario                    |\n"
           "                     |__________________________________|\n"
           "                     |                                  |\n"
           "                     |    5. Atr%cs                      |\n"
           "                     |__________________________________|\n\n", 160);
}

void printOrderMenu() {
    renglon();
    printf("                      __________________________________\n"
           "                     |                                  |\n"
           "                     |    1. Ascendente                 |\n"
           "                     |    2. Descendente                |\n"
           "                     |__________________________________|\n"
           "                     |                                  |\n"
           "                     |    3. Atr%cs                      |\n"
           "                     |__________________________________|\n\n", 160);
}
