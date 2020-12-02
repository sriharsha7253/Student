#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 
#include "include/menu.h"

int inputNum(){
/**
* Return:
* -1: forced exit
* -2: enter the wrong character
* -3: No input
* Integers greater than or equal to 0
*/

// Return results
int num = 0;
// Input string array
char *p = NULL, *numChars = (char *)malloc(100 * sizeof(char));
if (numChars == NULL){
printf ("memory allocation failed!\n");
return -1;
}
// Print input prompt
printf("=>> ");

// Get input characters
getNum(numChars);

// If there is no input
if (strlen(numChars) == 0) {
free(numChars);
numChars = NULL;
return -3;
}

p = numChars;

// Forced exit
if (strcmp(p, "-1") == 0) {
printf(" ----------\n");
printf (|/force exit |\n");
printf(" ----------\n\n");
free(numChars);
numChars = NULL;
p = NULL;
return -1;
}

// Get input character converted to int
while (*p != '\0') {
// Entered an error character
if (*p < '0' || *p > '9') {
printf ("enter the wrong character!Please enter the number\n");
free(numChars);
numChars = NULL;
p = NULL;
return -2;
}

num = num * 10 + (*p - '0');
p++;
}

free(numChars);
numChars = NULL;
p = NULL;
return num;
}

void inputPwd(char* pwdChars){
// Print input prompt
printf("=>> ");

// Get input characters
getPwd(pwdChars);

// Forced exit
if (strcmp(pwdChars, "-1") == 0) {
printf(" ----------\n");
printf (|/force exit |\n");
printf(" ----------\n\n");
free(pwdChars);
pwdChars = NULL;
}
}

void showMenu() {
printf ("\n--menu-------------------------------\n.");
printf("||||||| -1. Force exit | / / / / / / \n");
printf("||||||| 0. Exit | / / / / / / \n");
printf("||||||| 1. Student login | / / / / / / \n");
printf("||||||| 2. Teacher login | / / / / / / \n");
printf("||||||| 3. Clear screen |||||||\n");
printf("||||||| 4. Display menu | / / / / / / \n");
printf.("------------------------------- menu--\n");
printf("\n");
}

void showTeacherMenu() {
printf ("\n--menu-------------------------------\n.");
printf("||||||| -1. Force exit | / / / / / / \n");
printf("||||||| 0. Exit | / / / / / / \n");
printf("||||||| 1. Course number | / / / / / / \n");
printf("||||||| 2. Add student |||||||\n");
printf("||||||| 3. Add grades | / / / / / / \n");
printf("||||||| 4. Add Account | / / / / / / \n");
printf("||||||| 5. Modify student / / / / / / / \n");
printf("||||||| 6. Modify grades | / / / / / / \n");
printf("||||||| 7. Modify account | / / / / / / \n");
printf("||||||| 8. Query results | / / / / / / \n");
printf("||||||| 9. Number of Statistics / / / / / / / \n");
printf("||||||| 10. Grade sorting | / / / / / / \n");
printf("||||||| 11. Clear screen |||||||\n");
printf("||||||| 12. Display menu | / / / / / / \n");
printf.("------------------------------- menu--\n");
printf("\n");
}

void showStudentMenu() {
printf ("\n--menu-------------------------------\n.");
printf("||||||| -1. Force exit | / / / / / / \n");
printf("||||||| 0. Exit | / / / / / / \n");
printf("||||||| 1. Query results | / / / / / / \n");
printf("||||||| 2. Query ranking | / / / / / / \n");
printf("||||||| 3. Course number | / / / / / / \n");
printf("||||||| 4. Clear screen |||||||\n");
printf("||||||| 5. Display menu | / / / / / / \n");
printf.("------------------------------- menu--\n");
printf("\n");
}

void showRankMenu() {
printf ("\n--menu-------------------------------\n.");
printf("||||||| -1. Force exit | / / / / / / \n");
printf("||||||| 0. Exit | / / / / / / \n");
printf("||||||| 1. Class sorting | / / / / / / \n");
printf("||||||| 2. Grade sorting | / / / / / / \n");
printf("||||||| 3. Clear screen |||||||\n");
printf("||||||| 4. Display menu | / / / / / / \n");
printf.("------------------------------- menu--\n");
printf("\n");
}


// #include <stdio.h>

// char * Int2String (int NUM,char *str); / / function declaration
// int main()
// {
// int number1 = 123456;
// int number2 = -123456;
// char string[16] = {0};
// Int2String(number1,string);
// printf ("number:%D converted string:%s\n", number1,string);
// Int2String(number2,string);
// printf ("number:%D converted string:%s\n", number2,string);
// return 0;
// }

// void Int2String(int num,char *str){
// int i = 0; / / indicates padding str
// if(num<0) {
// num = -num;
// str[i++] = '-';
// }
/// / Conversion
// do {
// str[i++] = num%10+48; / / take NUM lowest character 0~9 ASCII code is 48~57;in simple terms, the number 0+48=48, ASCII code corresponding to the character '0'
// num / = 10; / / remove the lowest bit
// } while (num);//num is not 0 to continue the loop

// str[i] = '\0';

/// / Determine where to start the adjustment
// int j = 0;
// if(str[0]=='-'){
// j = 1;//adjust from second place
// ++i;//because there is a negative sign, so the axis of symmetry of the exchange should also be shifted 1 bit back
// }
// / / Symmetric exchange
// for(;j<i/2;j++) {
/// / The value at both ends of the symmetric exchange is actually to save the value of the intermediate variable exchange a+b:a=a+b;b=a-b;a=a-b;
// str[j] = str[j] + str[i-1-j];
// str[i-1-j] = str[j] - str[i-1-j];
// str[j] = str[j] - str[i-1-j];
// }
// }


void saveInfoExit() {
// TODO: save the current data to the database
FILE *file;
char str[100];
char *student = ".student.txt", *grade = ".grade.txt", *subject = ".subject.txt";
if ((file = fopen(student, "w")) == NULL) {
printf ("writing student data failed, cannot be closed correctly!");
fclose(file);
return ;
}
for (int i=0; i < STUDENTS_LEN; i++){
sprintf(str, "%d", (*(STUDENTS+i))->id);
fputs(str, file);
fputs(" ", file);
sprintf(str, "%d", (*(STUDENTS+i))->zlass);
fputs(str, file);
fputs(" ", file);
fputs((*(STUDENTS+i))->name, file);
fputs(" ", file);
fputs((*(STUDENTS+i))->pwd, file);
fputs("\n", file);
}
fclose(file);

if ((file = fopen(subject, "w")) == NULL) {
printf ("write entry data failed, can not be closed correctly!");
fclose(file);
return ;
}
for (int i=0; i < SUBJECTS_LEN; i++){
sprintf(str, "%d", (*(SUBJECTS+i))->id);
fputs(str, file);
fputs(" ", file);
fputs((*(SUBJECTS+i))->name, file);
fputs("\n", file);
}
fclose(file);

if ((file = fopen(grade, "w")) == NULL) {
printf ("write entry data failed, can not be closed correctly!");
fclose(file);
return ;
}
for (int i=0; i < GRADES_LEN; i++){
sprintf(str, "%d", (*(GRADES+i))->subjectId);
fputs(str, file);
fputs(" ", file);
sprintf(str, "%d", (*(GRADES+i))->studentId);
fputs(str, file);
fputs(" ", file);
sprintf(str, "%f", (*(GRADES+i))->grade);
fputs(str, file);
fputs("\n", file);
}
fclose(file);

printf ("\N exit!\n");
printf("=====\n\n");
}

void init() {
char *student = ".student.txt", *grade = ".grade.txt", *subject = ".subject.txt";

if ((access(student, F_OK)) != -1) {
initStudents();
}

if ((access(subject, F_OK)) != -1){
initSubjects();
}

if ((access(grade, F_OK)) != -1){
initGrades();
}
}

int addStudent() {
/**
* Increase in students
*/
int id, zlass;
char *name = NULL, *pwd = NULL;

if (STUDENTS_LEN == 100) {
return -1;
}

printf ("please enter the school number:\n");
id = inputNum();
if (id < 0){
printf ("School Number input error!\n");
return -1;
}
for (int i=0; i<STUDENTS_LEN; i++){
if ((*(STUDENTS + i))->id == id){
printf ("School Number already exists!\n");
return -1;
}
}
if (id > MAXID){
printf("School Number out of range!")\n");
return -1;
}

printf ("please enter class:\n");
zlass = inputNum();
if (zlass < 0){
printf ("class input error!\n");
return -1;
}

name = (char *)malloc(50*sizeof(char));
if (name == NULL){
printf ("memory allocation failed\n");
return -1;
}
printf ("please enter the student's name:\n");
printf("=>> ");
gets(name);
if (strcmp(name, "-1") == 0){
free(name);
name = NULL;
return -1;
}

printf ("please enter the student password:\n");
// Input string array
pwd = (char *)malloc(100 * sizeof(char));
if (pwd == NULL){
printf ("memory allocation failed\n");
return -1;
}
inputPwd(pwd);
if (pwd == NULL){
free(name);
free(pwd);
name = NULL;
pwd = NULL;
return -1;
}

*(STUDENTS + STUDENTS_LEN) = (Student *)malloc(sizeof(Student));
(*(STUDENTS + STUDENTS_LEN))->id = id;
(*(STUDENTS + STUDENTS_LEN))->zlass = zlass;
(*(STUDENTS + STUDENTS_LEN))->name = (char *) malloc(100*sizeof(char));
strcpy((*(STUDENTS + STUDENTS_LEN))->name, name);
(*(STUDENTS + STUDENTS_LEN))->pwd = (char *) malloc(100*sizeof(char));
strcpy((*(STUDENTS + STUDENTS_LEN))->pwd, pwd);
free(name);
free(pwd);
STUDENTS_LEN ++;
name = NULL;
pwd = NULL;
return 0;
}

int addGrade(){
int subjectId, studentId;

if (GRADES_LEN == 100){
return -1;
}

printf ("please enter the school number:\n");
studentId = inputNum();
if (studentId < 0){
printf ("School Number input error!\n");
return -1;
}

printf ("please enter the course number:\n");
subjectId = inputNum();
if (subjectId < 0){
printf("the course number was entered incorrectly!")\n");
return -1;
}

printf ("please enter the score:\n");
char res[50];
printf("=>> ");
gets(res);
if (strcmp(res, "-1") == 0){
return -1;
}
float socre = atof(res);

*(GRADES + GRADES_LEN) = (Grade *)malloc(sizeof(Grade));
(*(GRADES + GRADES_LEN))->subjectId = subjectId;
(*(GRADES + GRADES_LEN))->studentId = studentId;
(*(GRADES + GRADES_LEN))->grade = socre;
GRADES_LEN ++;
return 0;
}

int addSubject(){
int id;
char *name = NULL;

if (SUBJECTS_LEN == 100){
return -1;
}

printf ("please enter the course number:\n");
id = inputNum();
if (id < 0){
printf("the course number was entered incorrectly!")\n");
return -1;
}
for (int i=0; i<SUBJECTS_LEN; i++){
if ((*(SUBJECTS + i))->id == id){
printf ("the course number already exists!\n");
return -1;
}
}
if (id > MAXID){
printf ("number out of range!\n");
return -1;
}

name = (char *)malloc(50*sizeof(char));
if (name == NULL){
printf ("memory allocation failed\n");
return -1;
}
printf ("please enter the subject name:\n");
printf("=>> ");
gets(name);
if (strcmp(name, "-1") == 0){
free(name);
name = NULL;
return -1;
}

Subject subject = {id, name};
*(SUBJECTS + SUBJECTS_LEN) = (Subject *)malloc(sizeof(Subject));
(*(SUBJECTS + SUBJECTS_LEN))->id = id;
(*(SUBJECTS + SUBJECTS_LEN))->name = (char *)malloc(100 * sizeof(char));
strcpy((*(SUBJECTS + SUBJECTS_LEN))->name, name);
SUBJECTS_LEN ++;
return 0;
}

int modifyName(){
int id;
char* name = NULL;
Student *student=NULL;

printf ("please enter the school number:\n");
id = inputNum();
if (id < 0){
printf ("School Number input error!\n");
return -1;
}
for (int i=0; i<STUDENTS_LEN; i++){
if ((*(STUDENTS+i))->id == id){
student = *(STUDENTS+i);
break;
}
}
if (!student){
printf("there is no information for this student!")\n");
return -1;
}

name = (char *)malloc(50*sizeof(char));
if (name == NULL){
printf ("memory allocation failed\n");
return -1;
}
printf ("please enter a new name:\n");
printf("=>> ");
gets(name);
if (strcmp(name, "-1") == 0){
free(name);
name = NULL;
return -1;
}

student->name = name;
name = NULL;
student = NULL;
return 0;
}

int modifyGrade(){
int id1, id2;
Grade * grade=NULL;

printf ("please enter modify student number:\n");
id1 = inputNum();
if (id1 < 0){
printf ("School Number input error!\n");
return -1;
}

printf ("please enter the modified subject number:\n");
id2 = inputNum();
if (id2 < 0){
printf ("number input error!\n");
return -1;
}

for (int i=0; i<GRADES_LEN; i++){
if ((*(GRADES+i))->studentId == id1 && (*(GRADES+i))->subjectId == id2){
grade = *(GRADES+i);
break;
}
}

if (!grade){
printf("there is no information on the student's grades!")\n");
return -1;
}

printf ("please enter the modified score:\n");
char res[50];
printf("=>> ");
gets(res);
if (strcmp(res, "-1") == 0){
return -1;
}
grade->grade = atof(res);
grade = NULL;
return 0;
}

int modifySubject(){
int id;
char* name = NULL;
Subject *subject=NULL;

printf ("please enter the course number:\n");
id = inputNum();
if (id < 0){
printf("the course number was entered incorrectly!")\n");
return -1;
}
for (int i=0; i<SUBJECTS_LEN; i++){
if ((*(SUBJECTS+i))->id == id){
subject = *(SUBJECTS+i);
break;
}
}
if (!subject){
printf("there is no discipline!")\n");
return -1;
}

name = (char *)malloc(50*sizeof(char));
if (name == NULL){
printf ("memory allocation failed\n");
return -1;
}
printf ("please enter the new course name:\n");
printf("=>> ");
gets(name);
if (strcmp(name, "-1") == 0){
free(name);
name = NULL;
return -1;
}
subject->name = name;
name = NULL;
subject = NULL;
return 0;
}

void selectGrade(Student *student) {
printf ("%s has a score of:\n", student->name);
for (int i=0; i < GRADES_LEN; i++){
if ((*(GRADES+i))->studentId == student->id){
printf("%d: %f\n", (*(GRADES+i))->subjectId, (*(GRADES+i))->grade);
}
}
}

void rankGrade(Student *student) {
/**
* Student achievement ranking
*/
float totalScore = 0;
printf ("%s has a score of:\n", student->name);
for (int i=0; i < GRADES_LEN; i++){
if ((*(GRADES+i))->studentId == student->id){
printf ("%d: class ranking: %d\N", (*(GRADES+i))->subjectId, getClassRank (*(GRADES+I), student- > zlass));
printf("%d: grade ranking: %d\N", (*(GRADES+i))->subjectId, getGradeRank(*(GRADES+i)) - > subjectId, getGradeRank (*(GRADES + i)) - > subjectId, getGradeRank (*(GRADES + i)) - > subjectId, getGradeRank ( * )));
totalScore += (*(GRADES+i))->grade;
}
}
printf ("total score ranking:\n");
printf("class rank: %d\N", getTotalClassRank(totalScore, student->zlass), printf ("class rank: % d \ n", getTotalClassRank (totalScore, student - > zlass).));
printf("grade rank: %d\N", getTotalGradeRank(totalScore)), and printf ("grade rank: % d \ N", getTotalGradeRank (totalScore)).));
}

int selectGradeByTeacher() {
int id;
printf ("please enter the student number:\n");
id = inputNum();
if (id < 0){
printf ("School Number input error!\n");
return -1;
}
for (int i=0; i < STUDENTS_LEN; i++){
if ((*(STUDENTS+i))->id == id){
selectGrade(*(STUDENTS+i));
return 0;
}
}
}

void printStudentNum() {
printf ("total number of students in all grades: %d\N", STUDENTS_LEN);
int zlass[50] = {0}, i;
for (i = 0; i < STUDENTS_LEN; i++){
zlass[(*(STUDENTS + i))->zlass] += 1;
}
i = 1;
while (zlass[i]){
printf ("%D total number of Classes: %d\N", i, zlass[i]);
i++;
}
} 
int printClassGrade() {
printf ("please enter the class number:\n");
int zlass, tspIndex=0, j;
float totalScore;
zlass = inputNum();
if (zlass < 0){
printf ("input error!\n");
return -1;
}

Transcript **transcripts = (Transcript **) malloc(GRADES_LEN*sizeof(Transcript *));
TRANSCRIPT_LEN = 0;

for (int i=0; i < STUDENTS_LEN; i++){
if ((*(STUDENTS+i))->zlass == zlass){
*(transcripts + tspIndex) = (Transcript *)malloc(sizeof(Transcript *));
(*(transcripts + tspIndex))->name = (char *)malloc(100*sizeof(char));
strcpy((*(transcripts + tspIndex))->name, (*(STUDENTS+i))->name);
// (*(transcripts + tspIndex))->id = (*(STUDENTS+i))->id;
(*(transcripts + tspIndex))->totalScore = getGrades((*(STUDENTS+i))->id);
tspIndex ++;
TRANSCRIPT_LEN ++;
}
}

printf ("%D class transcript is as follows:\n", zlass);
quickSort(transcripts);
printGradeByTranscripts(transcripts);
free(transcripts);
transcripts = NULL;
return 0;
}

int printGrade() {
Transcript **transcripts = (Transcript **) malloc(100*sizeof(Transcript *));
TRANSCRIPT_LEN = STUDENTS_LEN;

for (int i=0; i < STUDENTS_LEN; i++){
*(transcripts + i) = (Transcript *)malloc(sizeof(Transcript *));
(*(transcripts + i))->name = (char *)malloc(100*sizeof(char));
strcpy((*(transcripts + i))->name, (*(STUDENTS+i))->name);
// (*(transcripts + i))->id = (*(STUDENTS+i))->id;
(*(transcripts + i))->totalScore = getGrades((*(STUDENTS+i))->id);
}

printf ("grade grade table is as follows:\n");
quickSort(transcripts);
printGradeByTranscripts(transcripts);
free(transcripts);
transcripts = NULL;
return 0;
}
