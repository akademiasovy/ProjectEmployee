#include <stdio.h>
#include <string.h>
#include "Employee.h"
#define SIZE 30
 
struct person employees[SIZE];
int main() {
    FILE *fr;
    int countEmp;
    fr=openFile("database.dat","r");
    
    if(fr!=NULL){
       countEmp=getDataFromFile(fr, &employees[0]);
       printf("\nCountEmp: %d ", countEmp);
       printf("%s", employees[3].lastname);
	}
	return 0;
}


