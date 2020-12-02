#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 
#include "include/user.h"

Teacher* tLogin(){
/**
* Teacher login, need to find from the file, because the memory does not load this table in advance
*/
int id;
char *name = ".teacher.txt", *pwd = NULL;

printf ("please enter the teacher id\n");
id = inputNum();
// Input error
if (id < 0){
return NULL;
}

printf ("please enter the password\n");
pwd = (char *)malloc(100 * sizeof(char));
if (pwd == NULL){
printf ("memory allocation failed\n");
return NULL;
}
inputPwd(pwd);
// Forced exit
if (pwd == NULL){
free(pwd);
return NULL;
}

FILE *in = NULL;

// If the file does not exist, create the file.
if ((access(name, F_OK)) == -1) {
in = fopen(name, "w");
} else {
Teacher* teacher = (Teacher *)malloc(sizeof(Teacher));
if (teacher == NULL){
printf ("memory allocation failed\n");
return NULL;
}
in = fopen(name, "r");
char chr, *str = NULL;
int i = 0, j;

while ((chr = fgetc(in)) != EOF) {
// Get the next word
str = (char *)malloc(100 * sizeof(char));
if (str == NULL){
printf ("memory allocation failed\n");
return NULL;
}
for (j = 0; chr != 10 && chr != 32 && chr != EOF; j++) {
*(str+j) = chr;
chr = fgetc(in);
}
*(str+j) = '\0';

// If it is id
if (i == 0){
teacher->id = atoi(str);
free(str);
i ++;
}
// If it is
else if (i == 1) {
teacher->name = (char *)malloc(100 * sizeof(char));
strcpy(teacher->name, str);
free(str);
i ++;
}
// If it is pwd
else {
teacher->pwd = (char *)malloc(100 * sizeof(char));
strcpy(teacher->pwd, str);
free(str);
i = 0;
// Verify username and password
if (id==teacher->id && strcmp(teacher->pwd, pwd) == 0){
printf ("teacher login successful!\n");
fclose(in);
free(pwd);
pwd = NULL;
str = NULL;
name = NULL;
in = NULL;
return teacher;
}
}
}
}
fclose(in);
pwd = NULL;
name = NULL;
in = NULL;
}

Student *sLogin() {
int id;
char* pwd = NULL;

printf ("please enter the school number\n");
id = inputNum();
// Input error
if (id < 0){
return NULL;
}

printf ("please enter the password\n");
pwd = (char *)malloc(100 * sizeof(char));
if (pwd == NULL){
printf ("memory allocation failed\n");
return NULL;
}
inputPwd(pwd);
// Forced exit
if (pwd == NULL){
free(pwd);
pwd = NULL;
return NULL;
}

for (int i=0; i < STUDENTS_LEN; i++){
if ((*(STUDENTS+i))->id == id){
if (strcmp((*(STUDENTS+i))->pwd, pwd) == 0){
free(pwd);
pwd = NULL;
return *(STUDENTS+i);
}
free(pwd);
pwd = NULL;
return NULL;
}
}
pwd = NULL;
return NULL;
}

void rankAdmin(){
int Selection = -1;
showRankMenu();

while (1){
Selection = inputNum();

switch (Selection){
case -1:
case 0:
printf ("exit sort management\n");
return ;
// Class sorting
case 1:
if (printClassGrade() == -1){
printf ("sorting failed\n");
}
break;
// Grade sorting
case 2:
if (printGrade() == -1){
printf ("sorting failed\n");
}
break;
// Clear screen
case 3:
system("cls");
break;
// Display menu
case 4:
showRankMenu();
break;
default:
break;
}
}
}

void teacherAdmin(Teacher * teacher){
/**
* Teacher management
* teacher: registered teachers
*/
printf ("\n welcome%S to access the student management system\n", teacher->name);
printf("=====================\n");

int Selection = -1;
showTeacherMenu();

while (1){
Selection = inputNum();

switch (Selection){
// Forced exit and exit
case -1:
case 0:
printf ("exit teacher login\n");
return ;
case 1:
showSubject();
break;
// Add students
case 2:
if (addStudent() == -1){
printf("add student failed!")\n");
}else{
printf ("add student success!\n");
}
break;
// Add grades
case 3:
if (addGrade() == -1){
printf ("add score failed!\n");
}else{
printf("add score success!")\n");
}
break;
// Add Account
case 4:
if (addSubject() == -1){
printf ("add discipline failed!\n");
}else{
printf ("add discipline success!\n");
}
break;
// Modify students
case 5:
if (modifyName() == -1){
printf ("modified information failed!\n");
}else{
printf ("modified information successfully!\n");
}
break;
// Modified grades
case 6:
if (modifyGrade() == -1){
printf ("modify the score failed!\n");
}else{
printf("modify the score successfully!")\n");
}
break;
// Modify the account
case 7:
if (modifySubject() == -1){
printf ("modifying the course failed!\n");
}else{
printf ("modify the course successfully!\n");
}
break;
// Query results
case 8:
if (selectGradeByTeacher() == -1){
printf ("query failed!\n");
}
break;
// Number of Statistics
case 9:
printStudentNum();
break;
// Ranking of grades
case 10:
rankAdmin();
showTeacherMenu();
break;
// Clear screen
case 11:
system("cls");
break;
// Display menu
case 12:
showTeacherMenu();
break;
// Input error or no input
default:
break;
}
}
}

void studentAdmin(Student * student){
/**
* Student management
*/
printf ("\n welcome%S to access the student management system\n", student - >name);
printf("=====================\n");

int Selection = -1;
showStudentMenu();

while (1){
Selection = inputNum();
switch (Selection){
// Forced exit and exit
case -1:
case 0:
printf ("log out of student login\n");
return ;
// Query results
case 1:
selectGrade(student);
break;
// Query ranking
case 2:
rankGrade(student);
break;
// Show Course Number
case 3:
showSubject();
break;
// Clear screen
case 4:
system("cls");
break;
// Display menu
case 5:
showStudentMenu();
break;
default:
break;
}
}

}
