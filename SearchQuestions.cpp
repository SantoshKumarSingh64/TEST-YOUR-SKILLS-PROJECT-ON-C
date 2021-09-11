//This function searches the question of specified Id.
void searchquestions()
{
 char id[10],ch;
 FILE *fp;
 cleardevice();
 setbkcolor(GREEN);
 setcolor(RED);
 rectangle(5,5,632,470);
 rectangle(8,8,629,467);
 setcolor(YELLOW);
 settextstyle(8,0,2);
 outtextxy(43,1,"_____________________________________");
 settextstyle(8,0,5);
 outtextxy(40,20,"|SEARCH QUESTION PAGE|");
 settextstyle(8,0,2);
 outtextxy(43,52,"_____________________________________");
 settextstyle(8,0,3);
 outtextxy(40,100,"QUESTION ID : ");
 gotoxy(30,8);
 scanf("%s",&id);
 gotoxy(30,8);
 printf("%s",id);
 fp=fopen("question.txt","rb");
 if(fp==NULL)
 {
 outtextxy(60,260,"THERE IS NO QUESTION IN QUESTION FILE");
 outtextxy(120,300,"PRESS ANY KEY TO GO BACK");
 getch();
 adminpage1();
 }
 settextstyle(8,0,3);
 outtextxy(200,190,"PRESS |S| FOR SEARCH");
 outtextxy(150,230,"PRESS ANY KEY TO GO BACK");
 outtextxy(292,165,"_");
 outtextxy(292,193,"_");
 ch=getch();
 if((ch!='S')&&(ch!='s'))
 adminpage1();
 else
 {
 fread(&question,sizeof(question),1,fp);
 while(!feof(fp))
 {
  if((strcmp(question.id,id))==0)
  {
  cleardevice();
  setbkcolor(GREEN);
  setcolor(RED);
  rectangle(5,5,632,470);
  rectangle(8,8,629,467);
  setcolor(YELLOW);
  settextstyle(8,0,2);
  outtextxy(43,1,"_____________________________________");
  settextstyle(8,0,5);
  outtextxy(40,20,"|SEARCH QUESTION PAGE|");
  settextstyle(8,0,2);
  outtextxy(43,52,"_____________________________________");
  settextstyle(8,0,3);
  outtextxy(40,100,"QUESTION ID : ");
  gotoxy(30,8);
  printf("%s",&id);
  outtextxy(78,130,"QUESTION : ");
  gotoxy(30,10);
  printf("%s",question.question_text);
  outtextxy(79,195,"OPTION A : ");
  gotoxy(30,14);
  printf("%s",question.optionA);
  outtextxy(79,230,"OPTION B : ");
  gotoxy(30,16);
  printf("%s",question.optionB);
  outtextxy(79,260,"OPTION C : ");
  gotoxy(30,18);
  printf("%s",question.optionC);
  outtextxy(79,290,"OPTION D : ");
  gotoxy(30,20);
  printf("%s",question.optionD);
  outtextxy(20,325,"CORRECT OPTION : ");
  gotoxy(34,22);
  printf("%s",question.correct_option);
  outtextxy(125,353,"MARK : ");
  gotoxy(30,24);
  printf("%d",question.mark);
  outtextxy(150,400,"PRESS ANY KEY TO GO BACK");
  getch();
  fclose(fp);
  adminpage1();
  }
 fread(&question,sizeof(question),1,fp);
 }
 fclose(fp);
  cleardevice();
  setbkcolor(GREEN);
  setcolor(RED);
  rectangle(5,5,632,470);
  rectangle(8,8,629,467);
  setcolor(YELLOW);
  settextstyle(8,0,2);
  outtextxy(43,1,"_____________________________________");
  settextstyle(8,0,5);
  outtextxy(40,20,"|SEARCH QUESTION PAGE|");
  settextstyle(8,0,2);
  outtextxy(43,52,"_____________________________________");
  settextstyle(8,0,3);
  outtextxy(40,100,"QUESTION ID : ");
  gotoxy(30,8);
  printf("%s",&id);
 outtextxy(80,260,"THERE IS NO QUESTION OF THIS ID IN");
 outtextxy(220,300,"QUESTION FILE");
 outtextxy(120,340,"PRESS ANY KEY TO GO BACK");
 getch();
 adminpage1();
 }
}
