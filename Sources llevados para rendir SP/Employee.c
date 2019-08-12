#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"

int comparaSalarioEmployee(void* EmployeeA, void* EmployeeB) {

    if(((eEmployee*)EmployeeA)->sector > ((eEmployee*)EmployeeB)->sector)
        return 1;

    if(((eEmployee*)EmployeeA)->sector < ((eEmployee*)EmployeeB)->sector)
        return -1;

    return 0;
}

void printEmployee(eEmployee* Employee) {
    printf("Nombre:%s Salario:%.2f\r\n", Employee->name, Employee->salary);
}

/** @brief Set this employee the values recived as parameters
 *
 * \param Employee employee*
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [NULL pointer] - (0) if Ok
 *
 */
eEmployee* newEmployee(eEmployee* Employee, int id, char name[], char lastName[], float salary, int sector) {
    eEmployee* returnAux = NULL;

    if(Employee != NULL) {
        Employee->id = id;
        strcpy(Employee->name, name);
        strcpy(Employee->lastName, lastName);
        Employee->salary = salary;
        Employee->sector = sector;
        Employee->isEmpty = 0;
        returnAux = Employee;
    }

    return returnAux;
}
