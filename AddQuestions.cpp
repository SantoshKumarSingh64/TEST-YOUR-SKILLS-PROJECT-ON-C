//This function add question to file 
void addquestions()
{
 char ch,id[10];
 FILE *fp;
 cleardevice();
 setbkcolor(GREEN);
 setcolor(RED);
 rectangle(5,5,632,470);
 rectangle(8,8,629,467);
 setcolor(YELLOW);
 settextstyle(8,0,2);
 outtextxy(84,1,"_______________________________");
 settextstyle(8,0,5);
 outtextxy(80,20,"|ADD QUESTION PAGE|");
 settextstyle(8,0,2);
 outtextxy(84,52,"_______________________________");
 settextstyle(8,0,3);
 outtextxy(40,100,"QUESTION ID : ");
 gotoxy(30,8);
 scanf("%s",&id);
 gotoxy(30,8);
 printf("%s",id);
//It checks that file is exist or not.If not,It will create file.
 fp=fopen("question.txt","ab");
 if(fp==NULL)
 {
 printf("Can't open file");
 exit(0);
 }
 fclose(fp);
//It checks that this question id is already added or not.
 fp=fopen("question.txt","rb");
 if(fp==NULL)
 {
 printf("Can't open file");
 exit(0);
 }
 fread(&question,sizeof(question),1,fp);
 while(!feof(fp))
 {
  if((strcmp(question.id,id))==0)
  {
   outtextxy(30,210,"THIS QUESTION ID HAS BEEN ALREADY ADDED");
   outtextxy(90,260,"PRESS R FOR ADD QUESTION AGAIN");
   outtextxy(120,300,"PRESS ANY KEY TO GO BACK");
   ch=getch();
   if((ch=='R')||(ch=='r'))
      addquestions();
   else
      adminpage1();
  }
 fread(&question,sizeof(question),1,fp);
 }
 fclose(fp);
 strcpy(question.id,id);
 outtextxy(78,130,"QUESTION : ");
 gotoxy(30,10);
 fflush(stdin);
 scanf("%[^\n]s",question.question_text);
 gotoxy(30,10);
 printf("%s",question.question_text);
 outtextxy(79,195,"OPTION A : ");
 gotoxy(30,14);
 fflush(stdin);
 scanf("%[^\n]s",question.optionA);
 gotoxy(30,14);
 printf("%s",question.optionA);
 outtextxy(79,230,"OPTION B : ");
 gotoxy(30,16);
 fflush(stdin);
 scanf("%[^\n]s",question.optionB);
 gotoxy(30,16);
 printf("%s",question.optionB);
 outtextxy(79,260,"OPTION C : ");
 gotoxy(30,18);
 fflush(stdin);
 scanf("%[^\n]s",question.optionC);
 gotoxy(30,18);
 printf("%s",question.optionC);
 outtextxy(79,290,"OPTION D : ");
 gotoxy(30,20);
 fflush(stdin);
 scanf("%[^\n]s",question.optionD);
 gotoxy(30,20);
 printf("%s",question.optionD);
 outtextxy(20,325,"CORRECT OPTION : ");
 outtextxy(300,325,"(A/B/C/D)");
 gotoxy(34,22);
 fflush(stdin);
 scanf("%s",&question.correct_option);
 gotoxy(34,22);
 printf("%s",question.correct_option);
 outtextxy(125,353,"MARK : ");
 gotoxy(30,24);
 fflush(stdin);
 scanf("%d",&question.mark);
 gotoxy(30,24);
 printf("%d",question.mark);
 settextstyle(8,0,3);
 outtextxy(200,390,"PRESS |S| FOR SAVE");
 outtextxy(150,430,"PRESS ANY KEY TO GO BACK");
 settextstyle(8,0,2);
 outtextxy(292,370,"_");
 outtextxy(292,395,"_");
 ch=getch();
 if((ch=='S')||(ch=='s'))
 {
 settextstyle(8,0,5);
 outtextxy(400,230,"|ADDED|");
 settextstyle(8,0,3);
 outtextxy(402,207,"_________");
 outtextxy(402,257,"_________");
  fp=fopen("question.txt","ab");
 if(fp==NULL)
 {
  printf("Can't open file");
  exit(0);
 }
//writing question to file
 fwrite(&question,sizeof(question),1,fp);
 fclose(fp);
 settextstyle(8,0,5);
 outtextxy(400,230,"|ADDED|");
 settextstyle(8,0,3);
 outtextxy(402,207,"_________");
 outtextxy(402,257,"_________");
 delay(1000);
 adminpage1();
 }
 else
   adminpage1();
}
