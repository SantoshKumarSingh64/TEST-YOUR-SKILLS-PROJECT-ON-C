//This function asks student to choose option for test
void studentpage1()
{
 char ch;
 cleardevice();
 setbkcolor(GREEN);
 setcolor(RED);
 rectangle(5,5,632,470);
 rectangle(8,8,629,467);
 setcolor(YELLOW);
 settextstyle(8,0,4);
 outtextxy(142,44,"_______________");
 settextstyle(8,0,5);
 outtextxy(140,75,"|STUDENT PAGE|");
 settextstyle(8,0,4);
 outtextxy(142,90,"_______________");
 settextstyle(8,0,3);
 outtextxy(270,175,"__");
 outtextxy(270,213,"__");
 settextstyle(8,0,4);
 outtextxy(150,200,"PRESS |1| FOR TEST");
 outtextxy(75,250,"PRESS ANY KEY FOR LOGOUT");
 ch=getch();
 if(ch!='1')
 studentpage();
 else
 testpage();
}
