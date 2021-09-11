void main()
{
 start();
 login();
 getch();
}
//This function provide first page of the program
void paint()
{
 cleardevice();
 setbkcolor(GREEN);
 setcolor(RED);
 rectangle(5,5,632,470);
 rectangle(8,8,629,467);
 setcolor(YELLOW);
 settextstyle(10,0,4);
 outtextxy(70,160,"TEST YOUR SKILLS");
 rectangle(120,250,500,270);
 settextstyle(6,0,3);
 outtextxy(260,280,"LOADING...");
}
//It will initialize graphics to the program
void start()
{
  int gd=DETECT,gm,i,X;
  initgraph(&gd,&gm,"C:\\Turboc3\\BGI");
   X=196;
   for(i=0;i<5;i++)
  {
   paint();
   setfillstyle(SOLID_FILL,BLUE);
   setcolor(YELLOW);
   rectangle(120,250,X,270);
   floodfill(125,260,YELLOW);
   delay(1000);
   X=X+76;
  }
}
//login function ask user to login as admin or student
void login()
{
 int choice;
 cleardevice();
 setbkcolor(GREEN);
 setcolor(RED);
 rectangle(5,5,632,470);
 rectangle(8,8,629,467);
 setcolor(YELLOW);
 settextstyle(8,0,4);
 outtextxy(129,20,"__________________");
 settextstyle(8,0,6);
 outtextxy(130,60,"| LOGIN PAGE |");
 settextstyle(8,0,4);
 outtextxy(129,100,"__________________");
 settextstyle(8,0,4);
 outtextxy(145,180,"PRESS |1| FOR ADMIN");
 outtextxy(130,230,"PRESS |2| FOR STUDENT");
 outtextxy(150,280,"PRESS |3| FOR EXIT");
 settextstyle(8,0,3);
 outtextxy(266,156,"__");
 outtextxy(266,193,"__");
 outtextxy(251,206,"__");
 outtextxy(251,243,"__");
 outtextxy(271,256,"__");
 outtextxy(271,293,"__");
 choice=getch();
 switch(choice)
 {
  case '1':
	 adminpage();
	 break;
  case '2':
	 studentpage();
	 break;
  case '3':
	exit(0);
  default:
	settextstyle(8,0,4);
	outtextxy(170,360,"INCORRECT INPUT");
	delay(1000);
	login();
	break;
 }
}
