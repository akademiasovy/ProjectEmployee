#include <string.h>
#include <stdlib.h>
#include "Employee.h"
#include "struct.h"



//@input: year
//@output: checks if the year is a leap one or not.
bool isLeapYear(int year){
   return year>0&&year%4==0?true:false;
}

//@ input: dd mm yy
//@output: checks if birthdate of employees is valid or not
bool isValidDate(int dd, int mm, int yy){
  if(yy<0)
       return false;
  if(mm<1 || mm>12)
       return false;
  if(mm==1 || mm ==3 || mm==5 || mm==7 || mm==8 || mm==10 || mm==12)	  {
      if(dd>0 && dd<32)
          return true;
      else
	      return false;    
  }      
  if(mm==4 || mm==6 || mm==9 || mm==11){
  if(dd>0 && dd<31)
          return true;
      else
	      return false;
  }
  if(mm==2){
    if(dd>0 && dd<29)
        return true;
    else{
        if(isLeapYear(yy) && dd==29)
            return true;
        else
		    return false;    
	}    
  }

  return false;
}
//@input:sex
//@output: checks if employees are male or female, other options not allowed
bool isValidSex(char z){
    if(z=='m' || z=='M' || z=='F' || z=='f')
       return true;
    else
	   return false;   
}

//@input:salary
//output:valid salary, must be more than 1 less than a million
bool isValidSalary(float s){
	
	if(s<1||s>1000000){
		return false;
	}
	else{
		return true;
	}
	
}

//opens employee file
FILE* openFile(char* fileName, char* mode){
   if(fileName==NULL || strlen(fileName)<5)
       return NULL;
   FILE *fr;
   fr=fopen(fileName,mode);
   if(fr==NULL){
      printf("#nError!. I can't open file: %s",fileName);
      return NULL;
   } 
   else
      return fr;   
}

//closes employee file
void closeFile(FILE *fr){
   if(fr!=NULL)
      fclose(fr);
}

//loads data from file into a structure
int getDataFromFile(FILE *fr, struct person employees[]){ //fill array with RELEVANT info.

   if(fr==NULL)
      return NULL;
   int countEmp=0;
   while( fscanf(fr, "%d%d%d%f %c %s%s", &employees[countEmp].day,
    &employees[countEmp].month, &employees[countEmp].year , 
	&employees[countEmp].salary , &employees[countEmp].sex, 
	&employees[countEmp].firstname, &employees[countEmp].lastname)!=EOF)   {
	if(isValidDate(employees[countEmp].day,employees[countEmp].month,employees[countEmp].year)&&
	   isValidSex(employees[countEmp].sex)&&isValidSalary(employees[countEmp].salary)){
	   	countEmp++;
	   }
	   
       if(countEmp>=SIZE)
         return 0;
   }

   
   return countEmp;  
}

//sorts employees by lastname
void sortEmployeesByLastname(struct person *p,int count){ //gotta test this
	int i,j;
	struct person temp;
	for(i=1;i<=count;i++){
		for(j=0;j<count-i;j++){
			if(strcmp(p[j].lastname,p[j+1].lastname)>0){
			struct person temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;
			}
		}
	} 
	
}

//sorts employees by birthday, input; dd mm yy
void sortEmployeesByBirthday(struct person *p, int count){
	
	struct person temp;
	int i,j;
	
	for(i=1;i<count;i++){
		for(j=0;j<=count-i;j++){
			if(p[j].year<p[j+1].year){
				temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;
			}
			else{
				if(p[j].year==p[j+1].year){
					if(p[j].month < p[j+1].month){
						temp=p[j];
						p[j]=p[j+1];
						p[j+1]=temp;
					}
					else{
						if(p[j].month == p[j+1].month){
							if(p[j].day < p[j+1].day) {
								temp=p[j];
								p[j]=p[j+1];
								p[j+1]=temp;
					}
						}
						
					}
					
				}
				
			}
		}
	}
	
	
	
	
}
//counts average salary of all employees
float getAverageSalary(struct person *p, int count, char sex){ //gotta test this
	int i;
	int avg=0;
	for(i=0;i<count;i++){
		avg+=p[i].salary;
		
	}
	avg=avg/count;
	return avg;
}

//creates e-mail addresses for all employees and prints them into a single file,not working yet
void createEmailFile(struct person *p, int count){
	FILE *fp;
	fopen("emails.txt","w");
	int i;
	char newMail[60];
	int size;
	
	
	for(i=0;i<count;i++){
		newMail[0]='\0';
		strcat(newMail, p[i].firstname);
		strcat(newMail, ".");
		strcat(newMail, p[i].lastname);
		strcat(newMail,"@gmail.com");
		fprintf(fp,"%s",newMail);
		printf("%s",newMail);
	}
	
	fclose(fp);
	
}

//prints out data in the list
void printData(struct person *ptr, int count){
	int i;
	   for(i=0;i<count;i++){
      	printf("%d %d %d %c %f %s %s\n", 
		ptr->day,ptr->month,ptr->year,ptr->sex,ptr->salary,ptr->firstname,ptr->lastname);
		ptr++;
	  }  
}

