/**
* @author: Rastislav Rušèák
* @date: 1.12.2016
* @description: Program print sorted correct data of employees, their salary statistics and generate file with e-mails of employees.
* @copyright: All rights reserved.
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
    
    if(fr!=NULL)
       countEmp=getDataFromFile(fr, &employees[0]);
       
	sortDataByBirthday(employees, countEmp);
	printf("Sorted employees by their birthdate:\n");
	printData(employees, countEmp);
	
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
