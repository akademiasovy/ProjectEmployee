#include <stdio.h>
#include <string.h>
#include "Employee.h"
#define SIZE 30


int main() {
    FILE *fr;
    FILE *fw;
    int countEmp;
    struct person employees[SIZE];
    fr=openFile("database.dat","r");
    fw=openFile("EmpEmails.dat", "w");
    if(fr!=NULL){
        countEmp=getDataFromFile(fr, &employees[0], countEmp);
        printf("\nCountEmp: %d", countEmp);
        
    }
    return 0;
}


