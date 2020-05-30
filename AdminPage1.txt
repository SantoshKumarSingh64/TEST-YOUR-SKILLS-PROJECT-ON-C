//This function provides option(ADD QUESTION,SEARCH QUESTION,MODIFY QUESTION,DELETE QUESTION and LOGOUT) to admin
void adminpage1()
{
 char ch;
 cleardevice();
 setbkcolor(GREEN);
 setcolor(RED);
 rectangle(5,5,632,470);
 rectangle(8,8,629,467);
 setcolor(YELLOW);
 settextstyle(8,0,4);
 outtextxy(140,20,"________________");
 settextstyle(8,0,6);
 outtextxy(140,60,"|ADMIN PAGE|");
 settextstyle(8,0,4);
 outtextxy(140,100,"________________");
 settextstyle(8,0,3);
 outtextxy(221,147,"__");
 outtextxy(221,185,"__");
 outtextxy(181,198,"__");
 outtextxy(181,235,"__");
 outtextxy(181,248,"__");
 outtextxy(181,285,"__");
 outtextxy(181,298,"__");
 outtextxy(181,335,"__");
 outtextxy(261,348,"__");
 outtextxy(261,385,"__");
 settextstyle(8,0,4);
 outtextxy(100,172,"PRESS |1| TO ADD QUESTION");
 outtextxy(60,222,"PRESS |2| TO SEARCH QUESTION");
 outtextxy(60,272,"PRESS |3| TO MODIFY QUESTION");
 outtextxy(60,322,"PRESS |4| TO DELETE QUESTION");
 outtextxy(140,372,"PRESS |5| TO LOGOUT");
 ch=getch();
 switch(ch)
 {
  case '1':
	   addquestions();
	   break;
  case '2':
	   searchquestions();
	   break;
  case '3':
	  modifyquestions();
	   break;
  case '4':
	   deletequestions();
	   break;
  case '5':
	   login();
	   break;
  default:
	outtextxy(170,415,"INCORRECT INPUT");
	delay(1000);
	adminpage1();
 }
}
