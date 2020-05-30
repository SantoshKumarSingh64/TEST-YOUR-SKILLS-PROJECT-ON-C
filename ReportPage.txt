//This function simply shows scorecard of student test.
void reportpage(int total_mark,int ans_mark)
{
  char n[5];
  float n1;
 cleardevice();
 setbkcolor(GREEN);
 setcolor(RED);
 rectangle(5,5,632,470);
 rectangle(8,8,629,467);
 setcolor(YELLOW);
 settextstyle(8,0,4);
 outtextxy(182,1,"___________");
 settextstyle(8,0,5);
 outtextxy(180,32,"|SCORECARD|");
 settextstyle(8,0,4);
 outtextxy(182,47,"___________");
 settextstyle(8,0,3);
 outtextxy(30,150,"TOTAL ATTEMPTED QUESTION  : ");
 itoa(10,n,10);
 outtextxy(440,150,n);
 outtextxy(253,200,"TOTAl MARK : ");
 itoa(total_mark,n,10);
 outtextxy(440,200,n);
 outtextxy(255,250,"YOUR MARK : ");
 itoa(ans_mark,n,10);
 outtextxy(440,250,n);
 outtextxy(245,300,"PERCENTAGE : ");
 n1=(float)(ans_mark*100)/total_mark;
 gcvt(n1,4,n);
 strcat(n,"%");
 outtextxy(440,300,n);
 settextstyle(8,0,4);
 outtextxy(100,380,"PRESS ANY KEY TO BACK");
 fflush(stdin);
 getch();
 studentpage1();
}
