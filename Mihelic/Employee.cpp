#include <string.h>
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


int getDataFromFile(FILE *fr, struct person employees[]){

   if(fr==NULL)
      return NULL;
   int countEmp=0;
   

   	    	
   while( fscanf(fr,"%d%d%d%f %c %s%s", &employees[countEmp].day,
	    &employees[countEmp].month, &employees[countEmp].year , 
    	&employees[countEmp].salary , &employees[countEmp].sex, 
	   	&employees[countEmp].firstname, &employees[countEmp].lastname)!=EOF){
		
		
		if(isValidSex(employees[countEmp].sex)==1 && isValidDate(employees[countEmp].day,employees[countEmp].month,employees[countEmp].year )){
		
		    countEmp++;	
		}
		
       if(countEmp>=SIZE)
       return 0;
   }
   	    	
		
   	    
   
   return countEmp;  
}

void sortDataByBirthday(struct person *employees, int count){
	
	int i=0;
	int j=0;
	
	for(i;i<count-1;i++){
		for(j;j<count-i-1;j++){
		   
		    if (employees[j].year > employees[j+1].year) 
      		{
			        struct person swap = employees[j];
			        employees[j]   = employees[j+1];
			        employees[j+1] = swap;	
		   	
			}
			else
			if(employees[j].year == employees[j+1].year)
			{
			   if(employees[j].month > employees[j+1].month){
			    
			        struct person swap = employees[j];
			        employees[j]   = employees[j+1];
			        employees[j+1] = swap;
			  }
			  else
			  if(employees[j].month == employees[j+1].month){
			  	
			  	 if(employees[j].day > employees[j+1].day){
				   			  	    
			  	        struct person swap = employees[j];
				        employees[j]   = employees[j+1];
				        employees[j+1] = swap;
			      }
			      
			  }
				
			}	
	}
			
}
}

void sortDataByLastName(struct person *p, int count){
		
	  	int i=0;
		int j=0;
		struct person swap;
	
		for(i;i<count;i++){
			for(j;j<=count-2;j++){
	   			if(strcmp(p[j].lastname , p[j+1].lastname) >0)
      			{
			        swap = p[j];
			        p[j]   = p[j+1];
			        p[j+1] = swap;
								   	
				}
			}
	    }
	
}

void printData(struct person *employees, int count){
	 
	  int countEmp=0;
	  for(countEmp;countEmp<count;countEmp++){
	  	
	  	 printf("\n%d %d %d %0.2f %c %s %s\n",employees[countEmp].day,
		    employees[countEmp].month, employees[countEmp].year , 
	    	employees[countEmp].salary , employees[countEmp].sex, 
		   	employees[countEmp].firstname, employees[countEmp].lastname);
	  	  	
	  }
	
}












