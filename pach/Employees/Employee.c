#include "Employee.h"

bool isValidDate(int dd, int mm, int yy){
    if(mm<1 || mm>12) return false;
    else if( (mm % 2 == 0 && mm != 8 && mm != 2) && (dd<1 || dd>30) ) return false;
    else if( (mm % 2 != 0 || mm == 8) && (dd<1 || dd>31) ) return false;
    else if( (isLeapYear(yy) && mm == 2) && (dd<1 || dd>29) ) return false;
    else if( (mm == 2 && !(isLeapYear(yy))) && (dd<1 || dd>28) ) return false;
    else return true;
}

bool isLeapYear(int year){
    return (year>0 && year%4 == 0)?true:false;
}

bool isValidSex(char ch){
    if(ch == 'M' || ch == 'F') return true;
    else return false;
}

FILE* openFile(char* fileName, char* mode){
    FILE *fr;
    if(fileName==NULL || strlen(fileName)<5)
        return NULL;
    fr = fopen(fileName, mode);
    return fr;
}

void closeFile(FILE *fr){
    if(fr!=NULL) fclose(fr);
}

int getDataFromFile(FILE *fr, struct person employees[]){
    if(fr==NULL) return NULL;
    int countEmp = 0;
    while((fscanf(fr,"%d%d%d%f %c %s%s", &employees[countEmp].day, &employees[countEmp].month, &employees[countEmp].year,
    &employees[countEmp].salary, &employees[countEmp].sex, &employees[countEmp].firstname,
    &employees[countEmp].lastname)) != EOF){
        if(isValidDate(employees[countEmp].day, employees[countEmp].month, employees[countEmp].year) &&
           isValidSex(employees[countEmp].sex))
            countEmp++;
        if(countEmp>=SIZE) return 0;
    }
    return countEmp;
}

void sortDataByBirthday(struct person employees[], int count){
    int i,j;
    struct person temp;
    for(i=1; i<count; i++){
        for(j=0; j<count-i; j++){
            if(employees[j].year>employees[j+1].year ||
                (employees[j].year==employees[j+1].year && employees[j].month>employees[j+1].month)||
                (employees[j].year==employees[j+1].year && employees[j].month==employees[j+1].month && employees[j].day>employees[j+1].day)){
                temp = employees[j];
                employees[j] = employees[j+1];
                employees[j+1] = temp;
            }
        }
    }
}

void sortDataByLastName(struct person employees[], int count){
    int i,j;
    struct person temp;
    for(i=1; i<count; i++){
        for(j=0; j<count-i; j++){
            if(strcmp(employees[j].lastname, employees[j+1].lastname)>0){
                temp = employees[j];
                employees[j] = employees[j+1];
                employees[j+1] = temp;
            }
        }
    }
}

void printData(struct person employees[], int count){
    int i;
    printf("Day\tMonth\tYear\tSalary\tSex\tFirst name\tLast Name\n\n");
    for(i=0; i<count; i++)
        printf("%d\t%d\t%d\t%.2f\t%c\t%s\t\t%s\n", employees[i].day,employees[i].month,employees[i].year,
               employees[i].salary,employees[i].sex,employees[i].firstname,employees[i].lastname);
}

float getAverageSalary(struct person employees[], int count, char sex){
    int sum = 0, numOfSalaries = 0, i;

    for(i=0; i<count; i++){
        if(employees[i].sex == sex){
            sum += employees[i].salary;
            numOfSalaries++;
        }
        else if(!isValidSex(sex)) return 0;
    }
    return (float)sum / numOfSalaries;
}

void createEmailFile(struct person employees[], int count, FILE* fileName){
    int i,j;
    char match = '1';
    char matchedEmails[80][80];
    char temp[80];
    int length;
    for(i=0; i<count; i++){
        employees[i].email[0] = tolower(employees[i].firstname[0]);
        employees[i].email[1] = '.';
        employees[i].email[2] = '\0';
        employees[i].lastname[0] = tolower(employees[i].lastname[0]);
        strcat(employees[i].email, tolower(employees[i].lastname));
    }
    for(i=0; i<count-1; i++){
        length = strlen(employees[i].email);
        for(j=i+1; j<count; j++){
            if(strcmp(employees[i].email, employees[j].email) == 0){
                employees[j].email[length] = match++;
                employees[j].email[length+1] = '\0';
            }
        }
        match = '1';
    }

    for(i=0; i<count; i++){
        strcat(employees[i].email, "@gmail.com");
        fprintf(fileName, "%s\n", employees[i].email);
    }
}
