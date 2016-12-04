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
   while( fscanf(fr, "%d%d%d%f %c %s%s", &employees[countEmp].day,
    &employees[countEmp].month, &employees[countEmp].year , 
	&employees[countEmp].salary , &employees[countEmp].sex, 
	&employees[countEmp].firstname, &employees[countEmp].lastname)!=EOF)   {
	   countEmp++;
       if(countEmp>=SIZE)
         return 0;
   }

   
   return countEmp; 
   
}
void createEmailFile(struct person *p, int count, FILE *fileName){
	char mail[30];
	char first[100];
	int i, j;
	int lengt;
	char x=49;
	char names[30][30];
	
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
	
		
		for(i=0; i<count; i++) {
		mail[0]='\0';
		p[i].firstname[0]=tolower(p[i].firstname[0]);
		
	
		fprintf(fileName,"%s", mail);
		fprintf(fileName,"%s\n", "@akademiasovysovy.sk");  
}

		strcpy(names[i], mail);
		printf("%s", mail);
		printf("%s\n", "@akademiasovysovy.sk");
			

	for(i=0; i<count; i++){
		printf("%s\n", names[i]);
}



float getAverageSalary(struct person *p, int count, char sex){
	float average=0;
	int chosenOnes=0;
	sex=toupper(sex);
	if(sex != 'F' && sex != 'M')
		return NULL;
	for(int i=0; i<count; i++){
		if(toupper(p[i].sex) == sex){
			average+=p[i].salary;
			chosenOnes++;
}	
}
	return average/chosenOnes;
}
