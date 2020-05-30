//This function picks ten random questions from file and takes test of student.
void testpage()
{
 int i,j,temp,totalq=0;
 char num[2],qp1[35],qp2[35],qp3[35],tm[2],ch[2],ch1;
 int a[10]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
 time_t t;
 FILE *fp;
 total_mark=0;
 mark=0;
 cleardevice();
 setbkcolor(GREEN);
 setcolor(RED);
 rectangle(5,5,632,470);
 rectangle(8,8,629,467);
 setcolor(YELLOW);
 settextstyle(8,0,4);
 outtextxy(182,1,"___________");
 settextstyle(8,0,5);
 outtextxy(180,30,"|TEST PAGE|");
 settextstyle(8,0,4);
 outtextxy(182,45,"___________");
 settextstyle(8,0,3);
 outtextxy(30,100,"INSTRUCTION :");
 outtextxy(30,130,"1) THIS TEST IS A MULTIPLE CHOICE QUESTION TEST");
 outtextxy(30,160,"2) THIS TEST CONTAINS 10 QUESTIONS");
 outtextxy(30,190,"3) THERE IS NO NEGATIVE MARKING");
 outtextxy(30,220,"4) TIP TO SUBMIT ANSWER ");
 outtextxy(80,250,"a) WRITE YOU OPTION NO. FROM (A|B|C|D)");
 outtextxy(80,280,"b) PRESS ENTER THEN WRITE 'S'");
 outtextxy(100,350,"PRESS ANY KEY TO CONTINUE");
 getch();
 fp=fopen("question.txt","rb");
 fread(&student,sizeof(student),1,fp);
 while(!feof(fp))
 {
   totalq+=1;
   fread(&question,sizeof(question),1,fp);
 }
 fclose(fp);
 srand((unsigned) time(&t));
 for(i=0; i<10; i++)
 {
    pos:
    temp=(rand()%totalq);
    for(j=0; j<i; j++)
    {
     if(a[j]==temp)
	goto pos;
    }
    a[i]=temp;
 }
 qsort(a,10,sizeof(int),cmpfunc);
 i=0;
 totalq=0;
 fp=fopen("question.txt","rb");
 fread(&question,sizeof(question),1,fp);
 while(!feof(fp))
 {
  if(totalq==a[i])
  {
   again:
   cleardevice();
   setbkcolor(GREEN);
   setcolor(RED);
   rectangle(5,5,632,470);
   rectangle(8,8,629,467);
   setcolor(YELLOW);
   settextstyle(8,0,4);
   outtextxy(182,1,"___________");
   settextstyle(8,0,5);
   outtextxy(180,30,"|TEST PAGE|");
   settextstyle(8,0,4);
   outtextxy(182,45,"___________");
   settextstyle(8,0,3);
   outtextxy(20,100,"QUESTION ID :");
   outtextxy(106,130,"MARK :");
   outtextxy(32,160,"QUESTION   :");
   settextstyle(8,0,3);
   itoa(i+1,num,10);
   outtextxy(160,160,num);
   outtextxy(58,242,"OPTION A :");
   outtextxy(58,275,"OPTION B :");
   outtextxy(58,306,"OPTION C :");
   outtextxy(58,338,"OPTION D :");
   outtextxy(30,370,"YOUR ANSWER :");
   outtextxy(280,370,"(A/B/C/D)");
   outtextxy(35,420,"PRESS |S| TO SUBMIT AND FOR NEXT ANSWER");
   outtextxy(127,395,"_");
   outtextxy(127,420,"_");
   gotoxy(27,8);
   printf("%s",question.id);
   gotoxy(27,10);
   printf("%d",question.mark);
   gotoxy(27,12);
   for(j=0;j<strlen(question.question_text);j++)
   {
      if(j==45)
	gotoxy(27,14);
      if(j==90)
	gotoxy(27,16);
      printf("%c",question.question_text[j]);
   }
   gotoxy(27,17);
   printf("%s",question.optionA);
   gotoxy(27,19);
   printf("%s",question.optionB);
   gotoxy(27,21);
   printf("%s",question.optionC);
   gotoxy(27,23);
   printf("%s",question.optionD);
   gotoxy(31,25);
   scanf("%s",&tm);
   ch1=getch();
   if((ch1!='S')&&(ch1!='s'))
    {
       outtextxy(30,390,"__________________________________");
       outtextxy(30,425,"__________________________________");
       outtextxy(27,415,"|");
       outtextxy(608,415,"|");
       outtextxy(27,423,"|");
       outtextxy(608,423,"|");
       delay(2000);
       goto again;
     }
   strcpy(ch,question.correct_option);
   for(j=0;j<strlen(tm);j++)
       tm[j]=tolower(tm[j]);
   for(j=0;j<strlen(ch);j++)
       ch[j]=tolower(ch[j]);
   if(strcmp(tm,ch)==0)
       mark+=question.mark;
   total_mark=total_mark+question.mark;
   i+=1;
   if(i==10)
   {
       fclose(fp);
       cleardevice();
       setbkcolor(GREEN);
       setcolor(RED);
       rectangle(5,5,632,470);
       rectangle(8,8,629,467);
       setcolor(YELLOW);
       settextstyle(8,0,4);
       outtextxy(182,1,"___________");
       settextstyle(8,0,5);
       outtextxy(180,30,"|TEST PAGE|");
       settextstyle(8,0,4);
       outtextxy(182,45,"___________");
       outtextxy(70,242,"NOW IT'S TIME FOR RESULT");
       delay(2000);
       reportpage(total_mark,mark);
     }
  }
  totalq+=1;
  fread(&question,sizeof(question),1,fp);
 }
 fclose(fp);
}
//With the help of this function we do sorting
int cmpfunc(const void *a,const void *b)
{
 return (*(int*)a-*(int*)b);
}
