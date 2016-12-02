10:17

Adrian Matta
Adrian
/**
* @author:Maro� Zori��k
* @date: 2.12.2016

*/
#include <stdio.h>
#include <string.h>
#include "Employee.h"
#define SIZE 30
 
struct person employees[SIZE];
int main() {
    FILE *fr;
    FILE *fw;
    int countEmp;
    fr=openFile("database.dat","r");
    fw=openFile("output.dat","w");
    
    sortDataByBirthday(employees, countEmp);
	printf("Sorted employees by their birthdate:\n");
	printData(employees, countEmp);
    
    if(fr!=NULL)
       countEmp=getDataFromFile(fr, &employees[0]);
       
	printf("\nAverage male salary is: %.2f", getAverageSalary(employees, countEmp, 'M'));
	printf("\nAverage female salary is: %.2f", getAverageSalary(employees, countEmp, 'F'));
	
	sortDataByLastName(employees, countEmp);
	printf("\nSorted employees by their lastname:\n");
	printData(employees, countEmp);
	
	
	
	createEmailFile(employees, countEmp, fw);
	closeFile(fr);
	closeFile(fw);
	return 0;
}

