//This function will modify question, all options, correct option and mark.
void modifyquestions()
{
 char id[10],ch,tempq[200],temp[50];
 int tmark;
 FILE *fp,*fp1;
 cleardevice();
 setbkcolor(GREEN);
 setcolor(RED);
 rectangle(5,5,632,470);
 rectangle(8,8,629,467);
 setcolor(YELLOW);
 settextstyle(8,0,2);
 outtextxy(40,1,"_____________________________________");
 settextstyle(8,0,5);
 outtextxy(40,20,"|MODIFY QUESTION PAGE|");
 settextstyle(8,0,2);
 outtextxy(40,52,"_____________________________________");
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
  outtextxy(40,1,"_____________________________________");
  settextstyle(8,0,5);
  outtextxy(40,20,"|MODIFY QUESTION PAGE|");
  settextstyle(8,0,2);
  outtextxy(40,52,"_____________________________________");
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
  settextstyle(8,0,1);
  outtextxy(350,115,"PRESS 1 TO EDIT QUESTION");
  outtextxy(350,185,"PRESS 2 TO EDIT OPTION A");
  outtextxy(350,218,"PRESS 3 TO EDIT OPTION B");
  outtextxy(350,250,"PRESS 4 TO EDIT OPTION C");
  outtextxy(350,280,"PRESS 5 TO EDIT OPTION D");
  outtextxy(280,330,"PRESS 6 TO EDIT CORRECT OPTION");
  outtextxy(280,360,"PRESS 7 TO EDIT MARK");
  settextstyle(8,0,3);
  outtextxy(150,410,"PRESS ANOTHER TO GO BACK");
  ch=getch();
  if((ch=='1')||(ch=='2')||(ch=='3')||(ch=='4')||(ch=='5')||(ch=='6')||(ch=='7'))
  {
  fclose(fp);
  cleardevice();
  setbkcolor(GREEN);
  setcolor(RED);
  rectangle(5,5,632,470);
  rectangle(8,8,629,467);
  setcolor(YELLOW);
  settextstyle(8,0,2);
  outtextxy(40,1,"_____________________________________");
  settextstyle(8,0,5);
  outtextxy(40,20,"|MODIFY QUESTION PAGE|");
  settextstyle(8,0,2);
  outtextxy(40,52,"_____________________________________");
  settextstyle(8,0,3);
  outtextxy(40,100,"QUESTION ID : ");
  gotoxy(30,8);
  printf("%s",&id);
  }
  switch(ch)
  {
  case '1':
	    outtextxy(78,195,"QUESTION : ");
	    gotoxy(30,14);
	    fflush(stdin);
	    scanf("%[^\n]s",tempq);
	     settextstyle(8,0,3);
	     outtextxy(200,300,"PRESS |S| FOR SAVE");
	     outtextxy(150,340,"PRESS ANY KEY TO GO BACK");
	     outtextxy(292,275,"_");
	     outtextxy(292,303,"_");
	     ch=getch();
	     if((ch!='S')&&(ch!='s'))
		  adminpage1();
	     else
	    {
	      fp1=fopen("temp.txt","wb");
	      fp=fopen("question.txt","rb");
	      fread(&question,sizeof(question),1,fp);
	      while(!feof(fp))
	      {
		if((strcmp(id,question.id))==0)
		      strcpy(question.question_text,tempq);
		fwrite(&question,sizeof(question), 1, fp1);
		fread(&question,sizeof(question),1,fp);
	      }
	      fclose(fp);
	      fclose(fp1);
	      remove("question.txt");
	      rename("temp.txt","question.txt");
	      settextstyle(8,0,3);
	      outtextxy(250,420,"UPDATED");
	      delay(1000);
	    }
	    break;
  case '2':
	   outtextxy(79,195,"OPTION A : ");
	   gotoxy(30,14);
	   fflush(stdin);
	   scanf("%[^\n]s",temp);
	     settextstyle(8,0,3);
	     outtextxy(200,300,"PRESS |S| FOR SAVE");
	     outtextxy(150,340,"PRESS ANY KEY TO GO BACK");
	     outtextxy(292,275,"_");
	     outtextxy(292,303,"_");
	     ch=getch();
	     if((ch!='S')&&(ch!='s'))
		  adminpage1();
	     else
	    {
	      fp1=fopen("temp.txt","wb");
	      fp=fopen("question.txt","rb");
	      fread(&question,sizeof(question),1,fp);
	      while(!feof(fp))
	      {
		if((strcmp(id,question.id))==0)
		      strcpy(question.optionA,temp);
		fwrite(&question,sizeof(question), 1, fp1);
		fread(&question,sizeof(question),1,fp);
	      }
	      fclose(fp);
	      fclose(fp1);
	      remove("question.txt");
	      rename("temp.txt","question.txt");
	      settextstyle(8,0,3);
	      outtextxy(250,420,"UPDATED");
	      delay(1000);
	    }
	   break;
  case '3':
	   outtextxy(79,195,"OPTION B : ");
	   gotoxy(30,14);
	   fflush(stdin);
	   scanf("%[^\n]s",temp);
	     settextstyle(8,0,3);
	     outtextxy(200,300,"PRESS |S| FOR SAVE");
	     outtextxy(150,340,"PRESS ANY KEY TO GO BACK");
	     outtextxy(292,275,"_");
	     outtextxy(292,303,"_");
	     ch=getch();
	     if((ch!='S')&&(ch!='s'))
		  adminpage1();
	     else
	    {
	      fp1=fopen("temp.txt","wb");
	      fp=fopen("question.txt","rb");
	      fread(&question,sizeof(question),1,fp);
	      while(!feof(fp))
	      {
		if((strcmp(id,question.id))==0)
		      strcpy(question.optionB,temp);
		fwrite(&question,sizeof(question), 1, fp1);
		fread(&question,sizeof(question),1,fp);
	      }
	      fclose(fp);
	      fclose(fp1);
	      remove("question.txt");
	      rename("temp.txt","question.txt");
	      settextstyle(8,0,3);
	      outtextxy(250,420,"UPDATED");
	      delay(1000);
	    }
	   break;
  case '4':
	    outtextxy(79,195,"OPTION C : ");
	    gotoxy(30,14);
	    fflush(stdin);
	    scanf("%[^\n]s",temp);
	     settextstyle(8,0,3);
	     outtextxy(200,300,"PRESS |S| FOR SAVE");
	     outtextxy(150,340,"PRESS ANY KEY TO GO BACK");
	     outtextxy(292,275,"_");
	     outtextxy(292,303,"_");
	     ch=getch();
	     if((ch!='S')&&(ch!='s'))
		  adminpage1();
	     else
	    {
	      fp1=fopen("temp.txt","wb");
	      fp=fopen("question.txt","rb");
	      fread(&question,sizeof(question),1,fp);
	      while(!feof(fp))
	      {
		if((strcmp(id,question.id))==0)
		      strcpy(question.optionC,temp);
		fwrite(&question,sizeof(question), 1, fp1);
		fread(&question,sizeof(question),1,fp);
	      }
	      fclose(fp);
	      fclose(fp1);
	      remove("question.txt");
	      rename("temp.txt","question.txt");
	      settextstyle(8,0,3);
	      outtextxy(250,420,"UPDATED");
	      delay(1000);
	    }
	    break;
  case '5':
	    outtextxy(79,195,"OPTION D : ");
	    gotoxy(30,14);
	    fflush(stdin);
	    scanf("%[^\n]s",temp);
	     settextstyle(8,0,3);
	     outtextxy(200,300,"PRESS |S| FOR SAVE");
	     outtextxy(150,340,"PRESS ANY KEY TO GO BACK");
	     outtextxy(292,275,"_");
	     outtextxy(292,303,"_");
	     ch=getch();
	     if((ch!='S')&&(ch!='s'))
		  adminpage1();
	     else
	    {
	      fp1=fopen("temp.txt","wb");
	      fp=fopen("question.txt","rb");
	      fread(&question,sizeof(question),1,fp);
	      while(!feof(fp))
	      {
		if((strcmp(id,question.id))==0)
		      strcpy(question.optionD,temp);
		fwrite(&question,sizeof(question), 1, fp1);
		fread(&question,sizeof(question),1,fp);
	      }
	      fclose(fp);
	      fclose(fp1);
	      remove("question.txt");
	      rename("temp.txt","question.txt");
	      settextstyle(8,0,3);
	      outtextxy(250,420,"UPDATED");
	      delay(1000);
	    }
	    break;
  case '6':
	   outtextxy(20,195,"CORRECT OPTION : ");
	   gotoxy(34,14);
	   fflush(stdin);
	   scanf("%[^\n]s",temp);
	     settextstyle(8,0,3);
	     outtextxy(200,300,"PRESS |S| FOR SAVE");
	     outtextxy(150,340,"PRESS ANY KEY TO GO BACK");
	     outtextxy(292,275,"_");
	     outtextxy(292,303,"_");
	     ch=getch();
	     if((ch!='S')&&(ch!='s'))
		  adminpage1();
	     else
	    {
	      fp1=fopen("temp.txt","wb");
	      fp=fopen("question.txt","rb");
	      fread(&question,sizeof(question),1,fp);
	      while(!feof(fp))
	      {
		if((strcmp(id,question.id))==0)
		      strcpy(question.correct_option,temp);
		fwrite(&question,sizeof(question), 1, fp1);
		fread(&question,sizeof(question),1,fp);
	      }
	      fclose(fp);
	      fclose(fp1);
	      remove("question.txt");
	      rename("temp.txt","question.txt");
	      settextstyle(8,0,3);
	      outtextxy(250,420,"UPDATED");
	      delay(1000);
	    }
	   break;
  case '7':
	    outtextxy(125,195,"MARK : ");
	    gotoxy(30,14);
	    fflush(stdin);
	    scanf("%d",&tmark);
	    settextstyle(8,0,3);
	    outtextxy(200,300,"PRESS |S| FOR SAVE");
	    outtextxy(150,340,"PRESS ANY KEY TO GO BACK");
	    outtextxy(292,275,"_");
	    outtextxy(292,303,"_");
	    ch=getch();
	    if((ch!='S')&&(ch!='s'))
		  adminpage1();
	    else
	    {
	      fp1=fopen("temp.txt","wb");
	      fp=fopen("question.txt","rb");
	      fread(&question,sizeof(question),1,fp);
	      while(!feof(fp))
	      {
		if((strcmp(id,question.id))==0)
		      question.mark=tmark;
		fwrite(&question,sizeof(question), 1, fp1);
		fread(&question,sizeof(question),1,fp);
	      }
	      fclose(fp);
	      fclose(fp1);
	      remove("question.txt");
	      rename("temp.txt","question.txt");
	      settextstyle(8,0,3);
	      outtextxy(250,420,"UPDATED");
	      delay(1000);
	    }
	    break;
  default:
	    adminpage1();
  }
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
 outtextxy(40,1,"_____________________________________");
 settextstyle(8,0,5);
 outtextxy(40,20,"|MODIFY QUESTION PAGE|");
 settextstyle(8,0,2);
 outtextxy(40,52,"_____________________________________");
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
