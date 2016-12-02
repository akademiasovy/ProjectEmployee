#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define SIZE 30

 struct person{
     int day;
     int month;
     int year;
     char sex;
     float salary;
     char firstname[20];
     char lastname[30];
     char email[90];
};


bool isValidDate(int dd, int mm, int yy);
bool isLeapYear(int year);
bool isValidSex(char z);
FILE* openFile(char* fileName, char* mode);
void closeFile(FILE *fr);
int getDataFromFile(FILE *fr, struct person employees[]);
void sortDataByBirthday(struct person employees[], int count);
void sortDataByLastName(struct person employees[], int count);
void printData(struct person employees[], int count);
float getAverageSalary(struct person employees[], int count, char sex);
void createEmailFile(struct person *p, int count, FILE* fileName);
