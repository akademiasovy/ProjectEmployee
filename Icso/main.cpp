/** 
	@author: Jakub Icso
	@date: 4.12.2016
**/

#include <stdio.h>
#include <string.h>
#include "Employee.h"
#define SIZE 30
 
struct person employees[SIZE];
int main() {
    FILE *fr;
    int countEmp;
    fr=openFile("database.dat","r");
    fw=openFile("output.dat","w");
    
    if(fr!=NULL){
       countEmp=getDataFromFile(fr, &employees[0]);
       
       sortDataByBirthday(employees,countEmp);
       printf("Sorted employees by date of birth: \n");
       printData(employees, countEmp);
       
       sortBySurename(employees, countEmp);
       printf("Sorterd employees by surename: \n");
       printf(employees, countEmp);
       
       printf("Average salary of men: %.2f\n",employees, countEmp, averageSalM);
       printf("Average salary of women: %2.f\n",employees, countEmp, averageSalF);
       
       createEmailFile(employees, countEmp, fw);
       closeFile(fr);
       closeFile(fw);
	}
	return 0;
}


