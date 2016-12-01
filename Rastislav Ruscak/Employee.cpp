#include <string.h>
#include <ctype.h>
#include "Employee.h"
#include "struct.h"

/**
* @input: year
* @output: Function return bool value. 
*          - if Return true year is leap.
*          - if Return false year isn't leap.
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
* @input: day, month, year
* @output: Function return bool value.
*          - if Return true Date is valid.
*          - if Return false Date isn't valid.
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
* @input: gender
* @output: Function return bool value.
*          - if Return true gender is valid.
*          - if Return false gender isn't valid.
*/
bool isValidSex(char z){
    z=toupper(z);
	if(z=='M' || z=='F')
		return true;
	else
		return false;
}

/**
* @input: File name, access mode
* @output: Function return pointer on opened File.
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
* @input: pointer on opened File
* @output: Function close File.
*/
void closeFile(FILE *fr){
   if(fr!=NULL)
      fclose(fr);
}

/**
* @input: pointer on opened File, array of structure
* @output: Function pulls out data from File into array of given structure.
*/
int getDataFromFile(FILE *fr, struct person employees[]){

   if(fr==NULL)
      return NULL;
   int countEmp=0;
   while( fscanf(fr, "%d%d%d%f %c %s%s", &employees[countEmp].day,
    &employees[countEmp].month, &employees[countEmp].year , 
	&employees[countEmp].salary , &employees[countEmp].sex, 
	&employees[countEmp].firstname, &employees[countEmp].lastname)!=EOF) {
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
* @input: array of structure, number of items in array
* @output: Function sort data by Birthdate.
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
* @input: array of structure, number of items in array
* @output: Function sort data by Lastname.
*/
void sortDataByLastName(struct person *p, int count) {
	struct person help;
	int i, j, k;
	for(j=1; j<count; j++){
		for(k=0; k<=count-2; k++){
			if(strcmp(p[k].lastname, p[k+1].lastname) > 0) {
				help=p[k];
				p[k]=p[k+1];
				p[k+1]=help;
			}
		}
	}
}

/**
* @input: array of structure, number of items in array
* @output: Function print data into console.
*/
void printData(struct person *p, int count) {
	int j;
	for(j=0; j<count; j++){
		printf("%d %d %d %f %c %s %s\n", p[j].day,
    p[j].month, p[j].year , 
	p[j].salary , p[j].sex, 
	p[j].firstname, p[j].lastname);	
	}
}

/**
* @input: array of structure, number of items in array, gender
* @output: Function return average salary.
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
* @input: array of structure, number of items in array, pointer on opened File
* @output: Function generate unique e-mail addresses and write them into file.
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
		p[i].firstname[0]=tolower(p[i].firstname[0]);
		
		strncat(mail, p[i].firstname, 1);
		strcat(mail, ".");
		p[i].lastname[0]=tolower(p[i].lastname[0]);
		strcat(mail, p[i].lastname);
		
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
/*		printf("%s", mail);
		printf("%s\n", "@akademiasovysovy.sk");*/
			
		fprintf(fileName,"%s", mail);
		fprintf(fileName,"%s\n", "@akademiasovysovy.sk");  
	}
/*	for(i=0; i<count; i++){
		printf("%s\n", names[i]);
	}*/
}
