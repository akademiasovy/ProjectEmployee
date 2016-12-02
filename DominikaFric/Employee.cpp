#include <string.h>
#include <stdlib.h>
#include "Employee.h"
#include "struct.h"




bool isLeapYear(int year){
   return year>0&&year%4==0?true:false;
}

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

bool isValidSex(char z){
    if(z=='m' || z=='M' || z=='F' || z=='f')
       return true;
    else
	   return false;   
}

bool isValidSalary(float s){
	
	if(s<1||s>1000000){
		return false;
	}
	else{
		return true;
	}
	
}


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

void closeFile(FILE *fr){
   if(fr!=NULL)
      fclose(fr);
}

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

void sortEmployeesBySalary(struct person *p, int count){  //sort people by salary returns crap!
	
	int i,j;
	for(i=1;i<=count;i++){
		for(j=0;j<count-i;j++){
			if(p->salary>(p+1)->salary){
			struct person temp=*p;
				p=p+1;
				*(p+1)=temp;
			}
		}
		p++;
	} 

}

void sortEmployeesByLastname(struct person *p,int count){ //gotta test this
	int i,j;
	for(i=1;i<=count;i++){
		for(j=0;j<count-i;j++){
			if(strcmp(p->lastname,(p+1)->lastname)){
			struct person temp=*p;
				p=p+1;
				*(p+1)=temp;
			}
		}
		p++;
	} 
	
}

float getAverageSalary(struct person *p, int count, char sex){ //gotta test this
	int i;
	int avg=0;
	for(i=0;i<count;i++){
		int sex=p->sex;
			avg+=p->salary;
			p++;
		
	}
	avg=avg/count;
	return avg;
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

