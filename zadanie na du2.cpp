 #include <stdio.h>
 #define SIZE 30
   
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
