//This studentpage function asks student to login or register. 
void studentpage()
{
 char ch;
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
 settextstyle(8,0,3);
 outtextxy(242,175,"__");
 outtextxy(242,213,"__");
 outtextxy(242,225,"__");
 outtextxy(242,263,"__");
 outtextxy(242,275,"__");
 outtextxy(242,313,"__");
 settextstyle(8,0,4);
 outtextxy(120,200,"PRESS |1| FOR LOGIN");
 outtextxy(120,250,"PRESS |2| FOR REGISTER");
 outtextxy(120,300,"PRESS |3| FOR BACK");
 ch=getch();
 switch(ch)
 {
 case '1':
	studentloginpage();
	break;
 case '2':
	studentregisterpage();
	break;
 case '3':
	login();
	break;
 default:
	outtextxy(170,400,"INCORRECT INPUT");
	delay(1000);
	studentpage();
 }
}
