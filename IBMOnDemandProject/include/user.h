#ifndef __USER_H__
#define __USER_H__
#include "./menu.h"

Teacher *tLogin();                  
Student *sLogin();                  
void teacherAdmin(Teacher *teacher); 
void studentAdmin(Student * student);

#endif