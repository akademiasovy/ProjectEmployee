 #include <stdio.h>
 #define SIZE 30
 
// global variables
struct person{
 int day;
 int month;
 int year;
 char sex;
 float salary;
 char givenname[20];
 char surname[30];
};

bool isValidDate(int dd, int mm, int yy);
bool isLeapYear(int year);
bool isValidSex(char z);
FILE* openFile(char* fileName, char* mode);
void closeFile(FILE *fr);
int getDataFromFile(FILE *fr, struct person employees[]);
void sortDataByBirthday(struct person *p, int count);
void sortDataBySurName(struct person *p, int count);
void printData(struct person *p, int count);
float getAverageSalary(struct person *p, int count, char sex);
void createEmailFile(struct person *p, int count, FILE *fileName);

