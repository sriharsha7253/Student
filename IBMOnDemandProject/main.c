#include <stdio.h>
#include <stdlib.h>
#include "include/user.h"

int main(){
STUDENTS_LEN=0; SUBJECTS_LEN=0; GRADES_LEN=0;
STUDENTS = (Student **)malloc(100*sizeof(Student *));
SUBJECTS = (Subject **)malloc(100*sizeof(Subject *));
GRADES = (Grade **)malloc(100*sizeof(Grade *));
init();
printf ("\n welcome to students grading system\n");
printf("=====================\n");

int Selection = -1;
Teacher* teacher = NULL;
Student* student = NULL;
showMenu();

while (1){
Selection = inputNum();

switch (Selection){
// Forced exit and exit
case -1:
case 0:
saveInfoExit();
return 0;
// Student login
case 1:
student = sLogin();
if (student == NULL){
printf ("wrong username or password!\n");
}else{
studentAdmin(student);
}
showMenu();
break;
// Teacher login
case 2:
teacher = tLogin();
if (teacher == NULL){
printf ("wrong username or password!\n");
} else {
// Teacher management
teacherAdmin(teacher);
}
showMenu();
break;
// Clear screen
case 3:
system("cls");
break;
// Display menu
case 4:
showMenu();
break;
// Input error or no input
default:
break;
}
}
}
