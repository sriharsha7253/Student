#ifndef __MENU_H__
#define __MENU_H__
#include "./func.h"

int inputNum();                     
void inputPwd(char *pwd);          
void showMenu();                    
void saveInfoExit();                
void showTeacherMenu();             
void showStudentMenu();             
void showRankMenu();                
void init();                        
int addStudent();                   
int addGrade();                     
int addSubject();                   
int modifyName();                   
int modifyGrade();                  
int modifySubject();                
void selectGrade(Student *student); 
void rankGrade(Student *student);   
int selectGradeByTeacher();         
void printStudentNum();             
int printClassGrade();              
int printGrade();                   

#endif