#include <stdio.h>
  #include <string.h>
 //#include "employee.h"
 #include "employee.h"
  #define SIZE 30
  
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
