//This functions asks student login credentials.
void studentloginpage()
{
 char ch,username[30],password[30],mch;
 int ind=0;
 FILE *fp;
 int count;
 cleardevice();
 setbkcolor(GREEN);
 setcolor(RED);
 rectangle(5,5,632,470);
 rectangle(8,8,629,467);
 setcolor(YELLOW);
 settextstyle(8,0,3);
 outtextxy(70,35,"_____________________________");
 settextstyle(8,0,5);
 outtextxy(65,60,"|STUDENT LOGIN PAGE|");
 settextstyle(8,0,3);
 outtextxy(70,88,"_____________________________");
 settextstyle(8,0,4);
 outtextxy(100,202,"USERNAME : ");
 gotoxy(43,15);
 scanf("%s",&username);
 gotoxy(43,15);
 printf("%s",username);
 outtextxy(106,252,"PASSWORD : ");
 gotoxy(43,18);
 fflush(stdin);
 mch=getch();
 while(mch!=13)
 {
	  password[ind++]=mch;
	  printf("*");
	  mch=getch();
 }
 password[ind]=0;
 gotoxy(43,18);
 settextstyle(8,0,3);
 outtextxy(242,275,"__");
 outtextxy(242,313,"__");
 outtextxy(242,325,"__");
 outtextxy(242,363,"__");
 settextstyle(8,0,4);
 outtextxy(120,300,"PRESS |1| FOR LOGIN");
 outtextxy(120,350,"PRESS |2| FOR BACK");
 ch=getch();
 switch(ch)
 {
  case '1':
     fp=fopen("studentdata.txt","rb");
 if(fp==NULL)
 {
 printf("Can't open file");
 exit(0);
 }
 count=0;
 fread(&student,sizeof(student),1,fp);
 while(!feof(fp))
 {
  if((strcmp(student.username,username))==0 &&((strcmp(student.password,password))==0 ))
  {
   count=1;
   break;
  }
 fread(&student,sizeof(student),1,fp);
 }
 fclose(fp);
 if(count==0)
 {
 settextstyle(8,0,3);
 outtextxy(20,400,"EITHER USERNAME OR PASSWORD IS INCORRECT");
 delay(1000);
 studentloginpage();
 }
 studentpage1();
 break;
  case '2':
	studentpage();
	break;
 default:
	outtextxy(170,400,"INCORRECT INPUT");
	delay(1000);
	studentloginpage();
	break;
 }
}
