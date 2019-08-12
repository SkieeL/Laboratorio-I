#ifndef __EMPLOYEE
#define __EMPLOYEE
struct {
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

} typedef eEmployee;
#endif

int comparaSalarioEmployee(void* pEmployeeA, void* pEmployeeB);
void printEmployee(eEmployee* pEmployee);
eEmployee* newEmployee(eEmployee* pEmployee, int id, char name[], char lastName[], float salary, int sector);


