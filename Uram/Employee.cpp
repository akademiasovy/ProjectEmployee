#include <string.h>
#include "Employee.h"

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

int getDataFromFile(FILE *fr, struct person employees[],int countEmp){

   if(fr==NULL)
      return NULL;
    countEmp=0;
   while( fscanf(fr, "%d%d%d%f %c %s%s", &employees[countEmp].day,
    &employees[countEmp].month, &employees[countEmp].year , 
	&employees[countEmp].salary , &employees[countEmp].sex, 
	&employees[countEmp].firstname, &employees[countEmp].lastname)!=EOF)   {
		if(isValidDate(employees[countEmp].day,employees[countEmp].month,employees[countEmp].year)&&isValidSex(employees[countEmp].sex))
	   countEmp++;
       if(countEmp>=SIZE)
         return 0;
   }

   
   return countEmp;  
}
void printData(struct person *p, int count){
	int c;
	for ( c= 0 ; c<count; c++){
		printf("%d %d %d %c %.2f %s %s", p[c].day, p[c].month, p[c].year, p[c].sex, p[c].salary, p[c].firstname, p[c].lastname);
	}
	
}
void sortDataByBirthday(struct person *p, int count){
	
	int c,d;
	struct person temp;
	 for (c = 0 ; c < ( count - 1 ); c++)
  {
    for (d = 0 ; d < count - c - 1; d++)
    {
      if (p[d].day > p[d+1].day)
      {
        temp      = p[d];
        p[d]  = p[d+1];
        p[d+1] = temp;
        }}}
        
   for (c = 0 ; c < ( count - 1 ); c++)
  {
    for (d = 0 ; d < count - c - 1; d++)
    {
      if (p[d].month > p[d+1].month)
      {
        temp      = p[d];
        p[d]  = p[d+1];
        p[d+1] = temp;
        }}}
         for (c = 0 ; c < ( count - 1 ); c++)
  {
    for (d = 0 ; d < count - c - 1; d++)
    {
      if (p[d].year > p[d+1].year)
      {
        temp      = p[d];
        p[d]  = p[d+1];
        p[d+1] = temp;
        }}}
}

void sortDataByLastName(struct person *p, int count){
		int c,d;
		struct person temp;
	 for (c = 0 ; c < ( count - 1 ); c++)
  {
    for (d = 0 ; d < count - c - 1; d++)
    {
      if (strcmp(p[d].lastname ,p[d+1].lastname)>0)
      {
        temp      = p[d];
        p[d]  = p[d+1];
        p[d+1] = temp;
        }}}
}

float getAverageSalary(struct person *p, int count, char sex){
		int c,d;
		struct person temp;
		struct person null{};
		for (c=0; c<=count; c++){
			if((p[d].sex)==sex)p[d]=null;
		}
			
	 for (c = 0 ; c < ( count - 1 ); c++)
  {
    for (d = 0 ; d < count - c - 1; d++)
    {
     if (p[d].salary > p[d+1].salary)
      {
        temp      = p[d];
        p[d]  = p[d+1];
        p[d+1] = temp;
        }}}
        
}





