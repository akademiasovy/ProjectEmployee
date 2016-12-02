#include <string.h>
 #include "Employee.h"
 #include "struct.h"
  #define SIZE 30
 int code1, code2, code3, code4;
int field[8][8];
int i,j;
int position;
int position row,position col;
printf("Welcome, author: Tomáš Dvorožòák");
printf("\n\Enther code 1:");
scanf("%d",&code 1);
printf("Enther code 3:);
scanf("%d",&code 3);
printf("Enther code 4:");
scanf("%d",&code 4);
printArray(filed);
viodPrintArray(int array[8][8]){
int i,j;
for(i=0;i<8;i++){
for(j=0;j<8;j++){
printf("%2d",array[i][j]);
code1=checkcode(code1);
code2=checkcode (code2);
checkcodeUsingPtr(&code3);
checkcodeUsingPtr(&code4);
positionRow=position\8;
positionCOL=position%8;
printf("\nError.Wrong position")
if(field)[positionRow][positionCol]==-1)=0{
printf("\nError.Wrong position - island")
return 2;
if (field[positionRow][positionCol -1]==0);
field[positionRow][positionCol]-1=0;
if(positionRow>0 && filed [positionCol +1]=0);
int count=1;
{

for(i=0;i<8;i++){
for(j=0;j<8;j++){
field[i][j-1]=count+1;
if(j<7 && field[i-1][j]==0);
filed[positionRow][positionCOl]-2;
if(array[i][j]==0);
printf("");
else if(array[i][j]==-1);
printf("0");
else if(array[i][j]==-2);
printf("@");
printf("%2d",)
//printf("\n%d %d %d %d", code1,code2,code3,code4);
for(i=7;i<=0;i--){
int bit=code1 & 1;//bit=code1%2;
field[1][j]=bit *(-1);t=code2&1
bit=code2 & 1; //bit=code=code2%2;
field[3][j]= bit * (-1);
bit=code3 & 1;//bit=code=code3%2;
field[4][j]=bit * (-1);
bit=code4 & 1;//bit=code=code4%2;
}
bool change=true;
while(change==false);
change=false;
while(count<5);
code1=code1
code1=code>>1;
code2=code>>2;
code3=code>>3;
code4=code>>4;
}
printArray(field);
printf("Point position of the ship<0;63>:");
scanf("%d",&position);
if(position<0 || position>63){
printf("\nError.Wrong input:position=%d,position");
return 1;
}
}
int checkcode(int,num){
if(num>0 &&num<=pow(2,16)-1)// interval <0,65535>
return num;
else
return 0;
}
void checkcodeUsingPtr(int * num){
if(*pnum<0 || *pnum){
*pnum=0;
}
}
 
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
           struct person{
 // global variables
 struct person{
   int day;
   int month;
   int year;
 @@ -11,16 +12,15 @@
   char lastname[30];
  };
  
 // global variables
 struct person employees[SIZE];
 
  
  
  bool isValidDate(int dd, int mm, int yy);
  bool isLeapYear(int year);
  bool isValidSex(char z);
  FILE* openFile(char* fileName, char* mode);
  void closeFile(FILE *fr);
 bool getDataFromFile(FILE *fr);
 int getDataFromFile(FILE *fr, struct person employees[]);
  void sortDataByBirthday(struct person *p, int count);
  void sortDataByLastName(struct person *p, int count);
  void printData(struct person *p, int count);
View
BIN  Employee.o
}
}
 /*
   struct person{
   int day;
   int month;
 @@ -94,14 +94,15 @@ bool getDataFromFile(FILE *fr){
  
     
     return true;  
 }
 
 }*/
 struct person employees[SIZE];
  int main() {
      FILE *fr;
     int countEmp;
      fr=openFile("database.dat","r");
      
      if(fr!=NULL){
        getDataFromFile(fr);
        countEmp=getDataFromFile(fr, &employees[0]);
         printf("\nCountEmp: %d", countEmp);
         printf("%s", employees[3].lastname);
  	}
}
