10:17


 @author:Maroš Zorièák
 @date: 2.12.2016


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
       	
	sortDataByLastName(employees, countEmp);
	printf("\nSorted employees by their lastname:\n");
	printData(employees, countEmp);
	
       
	printf("\nAverage male salary is: %.2f", getAverageSalary(employees, countEmp, 'M'));
	printf("\nAverage female salary is: %.2f", getAverageSalary(employees, countEmp, 'F'));
	

	
	
	createEmailFile(employees, countEmp, fw);
	closeFile(fr);
	closeFile(fw);
	return 0;
}

