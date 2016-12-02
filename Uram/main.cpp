#include <stdio.h>
#include <string.h>
#include "Employee.h"
#define SIZE 30
 

int main() {
    FILE *fr;
    int countEmp;
    struct person employees[SIZE];
    fr=openFile("database.dat","r");

    if(fr!=NULL){
       countEmp=getDataFromFile(fr, &employees[0], countEmp);
       printf("\nCountEmp: %d", countEmp);
      
	}
	return 0;
}


