#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h> / / getch function
#include "include/func.h"

void getNum(char *num) {
/**
* Input:
* char * NUM input string pointer
*/
int i = 0;
char ch = 0;
while (i <= 100 && ch != '\r' && ch != '\n') {

ch = getch();

// Echo if not fallback or delete
if (ch != '\b' && ch != 127) {
*(num + i) = ch;
i ++;
putchar(ch);
}
else {

// Otherwise fallback
if (i > 0) {
i--;
*(num + i) = 0;
putchar('\b');
putchar(' ');
putchar('\b');
}
}
}

if (ch != '\r' || ch != '\n'){
i--;
*(num + i) = '\0';
} else {
*(num + i) = '\0';
}

putchar('\n');
}

void getPwd(char *pwd) {
/**
* Input:
* pwd: password
*/
int i = 0;
char ch = 0;
while (i <= 100 && ch != '\r' && ch != '\n') {

ch = getch();

// Echo if not fallback or delete*
if (ch != '\b' && ch != 127) {
*(pwd + i) = ch;
i ++;
putchar('*');
}
else {

// Otherwise fallback
if (i > 0) {
i--;
*(pwd + i) = 0;
putchar('\b');
putchar(' ');
putchar('\b');
}
}
}

if (ch != '\r' || ch != '\n'){
i--;
*(pwd + i) = '\0';
} else {
*(pwd + i) = '\0';
}

putchar('\n');
}

void initStudents() {
FILE *in = NULL;
char chr='_', *str = NULL;
int j, i = 0;
in = fopen(".student.txt", "r");

while (chr != EOF) {
*(STUDENTS + STUDENTS_LEN) = (Student *)malloc(sizeof(Student));
if (*(STUDENTS + STUDENTS_LEN) == NULL){
printf ("memory allocation failed!\n");
return ;
}
while((chr = fgetc(in)) != EOF){
// Get the next word str
str = (char *)malloc(100 * sizeof(char));
if (str == NULL){
printf ("memory allocation failed!\n");
return ;
}
for (j = 0; chr != 10 && chr != 32 && chr != EOF; j++) {
*(str+ j) = chr;
chr = fgetc(in);
}
*(str+ j) = '\0';

// If it is a school number
if (i == 0){
(*(STUDENTS + STUDENTS_LEN))->id = atoi(str);
free(str);
i ++;
}
// If it is a class
else if (i == 1){
(*(STUDENTS + STUDENTS_LEN))->zlass = atoi(str);
free(str);
i ++;
}
// If it is a name
else if (i == 2){
(*(STUDENTS + STUDENTS_LEN))->name = (char *) malloc(100*sizeof(char));
strcpy((*(STUDENTS + STUDENTS_LEN))->name, str);
free(str);
i ++;
}
// If it is a password
else{
(*(STUDENTS + STUDENTS_LEN))->pwd = (char *) malloc(100*sizeof(char));
strcpy((*(STUDENTS + STUDENTS_LEN))->pwd, str);
free(str);
STUDENTS_LEN ++;
i = 0;
break;
}
}
}
fclose(in);
str = NULL;
in = NULL;
}

void initSubjects() {
FILE *in = NULL;
char chr='_', *str = NULL;
int j, i = 0;
in = fopen(".subject.txt", "r");

while (chr != EOF) {
*(SUBJECTS + SUBJECTS_LEN) = (Subject *)malloc(sizeof(Subject));
if (*(SUBJECTS + SUBJECTS_LEN) == NULL){
printf ("memory allocation failed!\n");
return ;
}
while((chr = fgetc(in)) != EOF){
// Get the next word str
str = (char *)malloc(100 * sizeof(char));
if (str == NULL){
printf ("memory allocation failed!\n");
return ;
}
for (j = 0; chr != 10 && chr != 32 && chr != EOF; j++) {
*(str + j) = chr;
chr = fgetc(in);
}
*(str + j) = '\0';

// If it is id
if (i == 0){
(*(SUBJECTS + SUBJECTS_LEN))->id = atoi(str);
free(str);
i ++;
}
// If it's a name
else{
(*(SUBJECTS + SUBJECTS_LEN))->name = (char *)malloc(100 * sizeof(char));
strcpy((*(SUBJECTS + SUBJECTS_LEN))->name, str);
free(str);
SUBJECTS_LEN ++;
i = 0;
break;
}
}
}
fclose(in);
in = NULL;
str = NULL;
}

void initGrades() {
FILE *in = NULL;
char chr='_', *str = NULL;
int j, i = 0;
in = fopen(".grade.txt", "r");

while (chr != EOF) {
*(GRADES + GRADES_LEN) = (Grade *)malloc(sizeof(Grade));
if (*(GRADES + GRADES_LEN) == NULL){
printf ("memory allocation failed!\n");
return ;
}
while((chr = fgetc(in)) != EOF){
// Get the next word str
str = (char *)malloc(100 * sizeof(char));
if (str == NULL){
printf ("memory allocation failed!\n");
return ;
}
for (j = 0; chr != 10 && chr != 32 && chr != EOF; j++) {
*(str + j) = chr;
chr = fgetc(in);
}
*(str + j) = '\0';

// If it is a discipline
if (i == 0){
(*(GRADES + GRADES_LEN))->subjectId = atoi(str);
free(str);
i ++;
}
// If it is a student
else if (i == 1){
(*(GRADES + GRADES_LEN))->studentId = atoi(str);
free(str);
i ++;
}
// If it is a grade
else{
(*(GRADES + GRADES_LEN))->grade = atof(str);
free(str);
GRADES_LEN ++;
i = 0;
break;
}
}
}
fclose(in);
in = NULL;
str = NULL;
}

float getGrades(int id) {
// Get all students ' grades
float totalScore=0;
for (int i=0; i < GRADES_LEN; i++){
if ((*(GRADES + i))->studentId == id){
totalScore += (*(GRADES + i))->grade;
}
}
return totalScore;
}

int getClassRank(Grade *grade, int zlass){
int rank=1, flag;
for (int i=0; i < GRADES_LEN; i++){
// Same class,same subject, different people
flag = 0;
for (int j=0; j<STUDENTS_LEN; j++){
if (STUDENTS[j]->id == grade->studentId){
if (STUDENTS[j]->zlass == zlass){
flag = 1;
}
break;
}
}
if (flag == 1 &&
(*(GRADES + i))->subjectId == grade->subjectId &&
(*(GRADES + i))->studentId != grade->studentId &&
(*(GRADES + i))->grade >= grade->grade){
rank ++;
}
}
return rank;
}

int getGradeRank(Grade *grade) {
int rank=1;
for (int i=0; i < GRADES_LEN; i++){
// The same discipline, different people
if ((*(GRADES + i))->subjectId == grade->subjectId &&
(*(GRADES + i))->studentId != grade->studentId &&
(*(GRADES + i))->grade >= grade->grade){
rank ++;
}
}
return rank;
}

void getClassTotalScore(int classId, float *totalScores){
if (totalScores == NULL){
printf ("memory allocation failed!\n");
return NULL;
}
int flag;
for (int i=0; i < GRADES_LEN; i++){
flag = 0;
for (int j=0; j<STUDENTS_LEN; j++){
if (STUDENTS[j]->id == (*(GRADES + i))->studentId){
if (STUDENTS[j]->zlass == classId){
flag = 1;
}
break;
}
}
if (flag == 1){
(*(totalScores + (*(GRADES + i))->studentId - 1)) += (*(GRADES + i))->grade;
}
}
}

void getTotalScore(float * totalScores){
if (totalScores == NULL){
printf ("memory allocation failed!\n");
return NULL;
}
for (int i=0; i < GRADES_LEN; i++){
(*(totalScores + (*(GRADES + i))->studentId - 1)) += (*(GRADES + i))->grade;
}
}

int getTotalClassRank(float totalScore, int classID){
int rank = 0;
float* scores = (float *)malloc(MAXID*sizeof(float));
getClassTotalScore(classID, scores);
for (int i=0; i < MAXID; i++){
if (*(scores + i) >= totalScore){
rank++;
}
}
// free(scores);
scores = NULL;
return rank;
}

int getTotalGradeRank(float totalScore) {
int rank = 0;
float* scores = (float *)malloc(MAXID*sizeof(float));
getTotalScore(scores);
for (int i=0; i < MAXID; i++){
if (*(scores + i) >= totalScore){
rank++;
}
}
// free(scores);
scores = NULL;
return rank;
}

int __partition(Transcript **transcripts, int l, int r){
int randNum = rand()%(r - l + 1) + l;
Transcript * t = NULL;
t = *(transcripts + l);
*(transcripts + l) = *(transcripts + randNum);
*(transcripts + randNum) = t;

Transcript *v = *(transcripts + l);

int lt = l; // arr[l+1, lt] < v
int gt = r +1; // arr[gt, r] > v
int i = l + 1; // arr[lt+1, i] == v
while( i < gt ){
if( (*(transcripts + i))->totalScore > v->totalScore ){
t = *(transcripts + i);
*(transcripts + i) = *(transcripts + lt+1);
*(transcripts + lt+1) = t;
i ++;
lt ++;
}
else if( (*(transcripts + i))->totalScore < v->totalScore ){
t = *(transcripts + i);
*(transcripts + i) = *(transcripts + gt - 1);
*(transcripts + gt - 1) = t;
gt--;
}
