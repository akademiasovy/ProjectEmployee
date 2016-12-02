 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>
 #define SIZE 30
 
// global variables
struct person{
 int day;
 int month;
 int year;
 char sex;
 float salary;
 char firstname[20];
 char lastname[30];
};




bool isValidDate(int dd, int mm, int yy);
bool isLeapYear(int year);
bool isValidSex(char z);
bool isValidSalary(float s);
//bool isValidFirstname(char firstName); MAYBE LATER
//bool isValidLastName(char lName);
FILE* openFile(char* fileName, char* mode);
void closeFile(FILE *fr);
int getDataFromFile(FILE *fr, struct person employees[]);
void sortEmployeesBySalary(struct person *p,int count);
void sortDataByBirthday(struct person *p, int count);
void sortDataByLastName(struct person *p, int count);
void printData(struct person *ptr, int count);
float getAverageSalary(struct person *p, int count, char sex);
void createEmailFile(struct person *p, int count, char *fileName);
//add email file
//sort by last name
//avg salary

