#include <string.h>
#include <ctype.h>
#include "Employee.h"
#include "struct.h"

/**
* @Input: year
* @Output: Function returns bool value. 
*          - If function returns true, year is leap.
*          - If function returns false, year is not leap.
*/
bool isLeapYear(int year){
    if (year % 4!=0)
		return false;
	else if (year % 100 != 0)
		return true;
	else if (year % 400 != 0)
		return false;
	else 
		return false;
}

/**
* @Input: Day, Month, Year
* @Output: Function returns bool value.
*          - If function returns true, date is valid.
*          - If function returns false, date is not valid.
*/
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

/**
* @Input: Sex
* @Output: Function returns bool value.
*          - If function returns true, sex is valid.
*          - If function returns false, sex is not valid.
*/
bool isValidSex(char z){
    z=toupper(z);
	if(z=='M' || z=='F')
		return true;
	else
		return false;
}

/**
* @Input: File with names, access mode.
* @Output: Function returns pointer to opened file.
*/
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

/**
* @Input: Pointer to opened file
* @Output: Function closes file.
*/
void closeFile(FILE *fr){
   if(fr!=NULL)
      fclose(fr);
}

/**
* @Input: Pointer to opened file, structure array.
* @Output: Function withdraws data from file and puts them into given structure array.
*/
int getDataFromFile(FILE *fr, struct person employees[]){

   if(fr==NULL)
      return NULL;
   int countEmp=0;
   while( fscanf(fr, "%d%d%d%f %c %s%s", &employees[countEmp].day,
    &employees[countEmp].month, &employees[countEmp].year , 
	&employees[countEmp].salary , &employees[countEmp].sex, 
	&employees[countEmp].givenname, &employees[countEmp].surname)!=EOF) {
		if( (isValidDate(employees[countEmp].day, employees[countEmp].month, employees[countEmp].year) == true)
		&& (isValidSex(employees[countEmp].sex) == true) ) {
			countEmp++;
		}
       if(countEmp>=SIZE)
         return 0;
   }
   return countEmp;  
}

/**
* @Input: Structure array, number of items in array.
* @Output: Function sorts data by DoB.
*/
void sortDataByBirthday(struct person *p, int count) {
	struct person help;
	int i, j, k;
	for(j=1; j<count; j++){
		for(k=0; k<=count-2; k++){
			if(p[k].year < p[k+1].year) {
				help=p[k];
				p[k]=p[k+1];
				p[k+1]=help;
			}
			else if(p[k].year == p[k+1].year) {
				if(p[k].month < p[k+1].month) {
					help=p[k];
					p[k]=p[k+1];
					p[k+1]=help;
				}
				else if(p[k].month == p[k+1].month) {
					if(p[k].day < p[k+1].day) {
						help=p[k];
						p[k]=p[k+1];
						p[k+1]=help;
					}
				}
			}
		}
	}
}

/**
* @Input: Structure array, number of items in array.
* @Output: Function sorts data by surname.
*/
void sortDataBySurName(struct person *p, int count) {
	struct person help;
	int i, j, k;
	for(j=1; j<count; j++){
		for(k=0; k<=count-2; k++){
			if(strcmp(p[k].surname, p[k+1].surname) > 0) {
				help=p[k];
				p[k]=p[k+1];
				p[k+1]=help;
			}
		}
	}
}

/**
* @Input: Structure array, number of items in array.
* @Output: Function displays data into console.
*/
void printData(struct person *p, int count) {
	int j;
	for(j=0; j<count; j++){
		printf("%d %d %d %f %c %s %s\n", p[j].day,
    p[j].month, p[j].year , 
	p[j].salary , p[j].sex, 
	p[j].givenname, p[j].surname);	
	}
}

/**
* @Input: Structure array, number of items in array, sex.
* @Output: Function returns average salary.
*/
float getAverageSalary(struct person *p, int count, char sex){
	float average=0;
	int chosenOnes=0;
	sex=toupper(sex);
	if(sex != 'F' && sex != 'M')
		return NULL;
	for(int i=0; i<count; i++) {
		if(toupper(p[i].sex) == sex){
			average+=p[i].salary;
			chosenOnes++;
		}	
	}
	return average/chosenOnes;
}

/**
* @Input: Structure array, number of items in array, pointer to opened file.
* @Output: Function generates unique e-mail addresses and writes them into file 'output.dat'.
*/
void createEmailFile(struct person *p, int count, FILE *fileName) {
	char mail[30];
	char first[100];
	int i, j;
	int lengt;
	char x=49;
	char names[30][30];
	
	for(i=0; i<count; i++) {
		mail[0]='\0';
		p[i].givenname[0]=tolower(p[i].givenname[0]);
		
		strncat(mail, p[i].givenname, 1);
		strcat(mail, ".");
		p[i].surname[0]=tolower(p[i].surname[0]);
		strcat(mail, p[i].surname);
		
		strcpy(names[i], mail);
		x=49;
		lengt=strlen(mail);
		mail[lengt+1]='\0';
		for(j=0; j<i; j++){
			while(strcmp(names[j], mail)==0){
				mail[lengt]=x;
				mail[strlen(mail)]='\0';
				x++;
			}
		}
		strcpy(names[i], mail);
			
		fprintf(fileName,"%s", mail);
		fprintf(fileName,"%s\n", "@akademiasovysovy.sk");  
	}

}
