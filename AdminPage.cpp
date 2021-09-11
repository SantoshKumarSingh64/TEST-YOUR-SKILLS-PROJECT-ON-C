//This function ask login credentials to admin  
void adminpage()
{
 char username[30],password[30],ch,mch;
 int ind=0;
 cleardevice();
 setbkcolor(GREEN);
 setcolor(RED);
 rectangle(5,5,632,470);
 rectangle(8,8,629,467);
 setcolor(YELLOW);
 settextstyle(8,0,4);
 outtextxy(38,20,"________________________");
 settextstyle(8,0,6);
 outtextxy(35,60,"|ADMIN LOGIN PAGE|");
 settextstyle(8,0,4);
 outtextxy(38,100,"________________________");
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
  if((strcmp(username,"admin"))==0 &&((strcmp(password,"admin#123"))==0 ))
   adminpage1();
  else
  {
  settextstyle(8,0,3);
  outtextxy(20,400,"EITHER USERNAME OR PASSWORD IS INCORRECT");
  delay(2000);
  adminpage();
  }
  case '2':
  login();
  default:
	outtextxy(170,400,"INCORRECT INPUT");
	delay(1000);
	adminpage();
 }
}
