#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<graphics.h>
#include<time.h>
#include<ctype.h>
typedef struct student
{
char username[30];
char firstname[20];
char lastname[15];
char mobile[10];
char address[50];
char password[20];
}
st;
st student;
typedef struct question
{
char id[10];
char question_text[200];
char optionA[50];
char optionB[50];
char optionC[50];
char optionD[50];
char correct_option[2];
int mark;
}
qt;
qt question;
int total_mark=0,mark=0;
