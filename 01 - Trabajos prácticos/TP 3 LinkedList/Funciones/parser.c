#include "parser.h"

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee) {

    char id[6], name[NOMBRE], hours[10], salary[20];
    int idAux;
    int hoursAux;
    int salaryAux;
    int count = 0;

    while( !feof(pFile) ) {
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, name, hours, salary);
        //printf("STRINGS\tID: %s \tNOMBRE: %10s\tHORAS: %s\tSALARIO: %s\n", id, name, hours, salary);

        idAux = atoi(id);
        hoursAux = atoi(hours);
        salaryAux = atoi(salary);
        //printf("AUX\tID: %d \tNOMBRE: %10s\tHORAS: %d\tSALARIO: %d\n\n", idAux, name, hoursAux, salaryAux);

        Employee* aNewEmployee = employee_newParametros(&idAux, name, &hoursAux, &salaryAux);

        ll_add(pArrayListEmployee, aNewEmployee);
        count++;
    }

    return count;
}

int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee) {
    int count = 0;

    while(1) {

        Employee* aNewEmployee = employee_new();
        fread(aNewEmployee,
              sizeof(Employee),
              1,
              pFile);
        if ( feof(pFile) ) {
            break;
        }
        ll_add(pArrayListEmployee, aNewEmployee);
        count++;
    }

    return count;
}
