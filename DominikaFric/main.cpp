#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "employee.h"
#define SIZE 30

struct person employees[SIZE];
int main() {
    FILE *fr;
    int countEmp;
    int i;
    
    struct person  *ptr;
    ptr = &employees[0];// do it this way!
    
    fr=openFile("database.dat","r");
    
    if(fr!=NULL){
       countEmp=getDataFromFile(fr, &employees[0]);
       printf("\nCountEmp: %d\n", countEmp);
       
      sortEmployeesByBirthday(ptr,countEmp);
      printf("Sorted by Birthday\m");
      printData(ptr,countEmp); 
	  printf("\n");
	  
	  sortEmployeesByLastName(ptr,countEmp);
	  printf("SortedByLastName: \n");
	  printData(ptr,countEmp);
	  
	 
	}
	return 0;
}


