#include <stdio.h>
#include <string.h>
#include "Employee.h"
#define SIZE 30
 
int main() {
	
	struct person employees[SIZE];
    FILE *fr;
    int countEmp;
    struct person *p;
    
    
    
    fr=openFile("database.dat","r");
    
    
    if(fr!=NULL){
       countEmp=getDataFromFile(fr, &employees[0]);
       printf("\nCountEmp: %d\n", countEmp);
	}
	
	sortDataByBirthday(employees, countEmp);
	printData(employees, countEmp);
		
	
	return 0;
}


