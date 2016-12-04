#include <string.h>
#include<ctype.h>
#include "Employee.h"
#include "struct.h"


/** @author: Jakub Icso
	@input: year
	@output: checks if year is leap
**/

bool isLeapYear(int year){
   return year> 0 && year %4 == 0 ? true:false;
}

/** @author: Jakub Icso
	@input: day, month, year
	@output: checks if date is correct
**/
	
bool isValidDate(int dd, int mm, int yy){
  if(yy < 0)
       return false;
  if(mm < 1 || mm > 12)
       return false;
  if(mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12)	  {
      if(dd > 0 && dd < 32)
          return true;
      else
	      return false;    
  }      
  if(mm == 4 || mm == 6 || mm == 9 || mm == 11){
  if(dd > 0 && dd < 31)
          return true;
      else
	      return false;
  }
  if(mm == 2){
    if(dd > 0 && dd < 29)
        return true;
    else{
        if(isLeapYear(yy) && dd == 29)
            return true;
        else
		    return false;    
	}    
  }

  return false;
}

/** @author: Jakub Icso
	@input: sex
	@output: checks if employees are men or women
**/
	
bool isValidSex(char z){
    toupper(z);
	if(z == 'M' || z == 'F')
       return true;
    else
	   return false;   
}

/** @author: Jakub Icso
	@output: open file
**/

FILE* openFile(char* fileName, char* mode){
   if(fileName == NULL || strlen(fileName) < 5)
       return NULL;
   FILE *fr;
   fr=fopen(fileName, mode);
   if(fr == NULL){
      printf("#nError!. I can't open file: %s", fileName);
      return NULL;
   } 
   else
      return fr;   
}

void closeFile(FILE *fr){
   if(fr!=NULL)
      fclose(fr);
}

/** @author: Jakub Icso
	@input: data
	@output: reads data from file
**/

int getDataFromFile(FILE *fr, struct person employees[]){

   if(fr == NULL)
      return NULL;
   int countEmp = 0;
   while( fscanf(fr, "%d%d%d%f %c %s%s", &employees[countEmp].day,
    									 &employees[countEmp].month, 
										 &employees[countEmp].year, 
										 &employees[countEmp].salary, 
										 &employees[countEmp].sex, 
										 &employees[countEmp].firstname, 
										 &employees[countEmp].lastname)!=EOF) {
		
		if((isValidDate(employees[countEmp].day, employees[countEmp].month, employees[countEmp].year) == true) && (isValidSex(employees[countEmp].sex) == true)) {
			countEmp++;
		}
       if(countEmp>=SIZE)
         return 0;
   }
   return countEmp;  
}

/** @author: Jakub Icso
	@input: date 
	@output: sorts employees by their birth date
**/

void sortDataByBirthday(struct person *p, int count){
	
	//year
	int j, k;
	struct temp;
	for(j=0; j<count; j++)
	{
		for(k=0; k<count-1; k++)
		{
			if(p[k].year > p[k+1].year)
			{
				struct person temp = p[k];
               p[k] = p[k+1];
               p[k+1] = temp;	
			}
			
			
	//month

	else if(p[k].year == p[k].year)
		{
			if(p[k].month > p[k+1].month)
			{
				struct person temp = p[k];
               p[k] = p[k+1];
               p[k+1] = temp;	
			}
		

	
	//day
	else if(p[k].month == p[k].month)
		{
			if(p[k].day > p[k+1].day)
			{
				struct person temp = p[k];
               p[k] = p[k+1];
               p[k+1] = temp;	
			}
		}
	}
}
}
}

/** @author: Jakub Icso
	@input: last name
	@output: sort employees by their last name
**/

void sortDataByLastName(struct person *p, int count){
	
	int j, k;
	struct temp;
	for(j = 0; j < count; j++)
	{
		for(k = 0; k < count-1; k++)
		{
			if(strcmp(p[k].lastname, p[k+1].lastname)>0)
			{
				struct person temp = p[k];
               p[k]=p[k+1];
               p[k+1]=temp;	
			}
		}
	}
}

/** @author: Jakub Icso
	@output: prints data
**/
	
void printData(struct person *p, int count){
	
	int i;
	for(i = 0; i<count; i++)
	printf("%d%d%d%f %c %s%s", p[i].month, p[i].year , p[i].salary , p[i].sex, 
	p[i].firstname, p[i].lastname);
}

/** @author: Jakub Icso
	@input: salary
	@output: compute average salary of employees
**/

float getAverageSalary(struct person *p, int count, char sex){
	
	int i;
	
	int countPersM = 0;
	float averageSalM = 0;
	float tempSalM = 0;
	
	int countPersF = 0;
	float averageSalF = 0;
	float tempSalF = 0;
	
	//males
	if(sex == 'M'){
for(i=0; i < count; i++){
	tempSalM += p[i].salary; 
	countPersM++;
					}
				}
		averageSalM = tempSalM/countPersM;
				
	//females
	if(sex == 'F'){
		for(i=0;i<count;i++){
			tempSalF += p[i].salary;
			countPersF++;
		}
	}
	averageSalF = tempSalF/countPersF;	
	
	return averageSalF averageSalM;
}

/** @author: Jakub Icso
	@output: creates employees email adress
**/

void createEmailFile(struct person *p, int count, FILE *fileName){
	
	
	
	
}




