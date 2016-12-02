/**
* @author: Stanislav Roba
* @date: 2.12.2016
* @description: 1. Program displays correctly sorted data of employees, 
*				2. displays average salary of men and women, 
*				3. generates file 'output.dat' with unique e-mail addresses of each employee.
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
	printf("Sorted employees by DoB:\n\n");
	printData(employees, countEmp);
	
	sortDataBySurName(employees, countEmp);
	printf("\nSorted employees by surname:\n\n");
	printData(employees, countEmp);
	
	printf("\nAverage salary of men: %.2f", getAverageSalary(employees, countEmp, 'M'));
	printf("\nAverage salary of women: %.2f", getAverageSalary(employees, countEmp, 'F'));
	
	createEmailFile(employees, countEmp, fw);
	closeFile(fr);
	closeFile(fw);
	return 0;
}


