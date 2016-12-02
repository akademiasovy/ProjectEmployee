#include "Employee.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
    struct person employees[SIZE];
    int countEmp;

    FILE *fr;
    FILE *fw;
    fr = openFile("Employees.dat", "r");
    fw = openFile("Emails.dat", "w");
    if(fr!=NULL){
        countEmp = getDataFromFile(fr, &employees[0]);
        //sortDataByLastName(&employees[0], countEmp);
        //printData(&employees[0], countEmp);
        //printf("\n\nAvg: %.2f", getAverageSalary(&employees[0], countEmp, 'Z'));
        createEmailFile(&employees[0], countEmp, fw);
    }

    closeFile(fr);
	return 0;
}
