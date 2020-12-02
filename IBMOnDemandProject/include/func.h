#ifndef __FUNC_H__
#define __FUNC_H__
#include "./model.h"

void getNum(char *num);                                 
void getPwd(char *pwd);                                 
void initStudents();                                    
void initSubjects();                                    
void initGrades();                                      
float getGrades(int id);                                
int getClassRank(Grade *grade, int zlass);              
int getGradeRank(Grade *grade);                         
int getTotalClassRank(float totalScore, int classID);   
int getTotalGradeRank(float totalScore);                
void quickSort(Transcript **transcripts);               
void printGradeByTranscripts(Transcript **transcripts); 
void showSubject();                                     

#endif