//This function registers student details.
void studentregisterpage()
{
 char username[30],password[30],address[30],email[30],firstname[30],lastname[40];
 char ch,mobileno[10];
 FILE *fp;
 cleardevice();
 setbkcolor(GREEN);
 setcolor(RED);
 rectangle(5,5,632,470);
 rectangle(8,8,629,467);
 setcolor(YELLOW);
 settextstyle(8,0,4);
 outtextxy(29,1,"_________________________");
 settextstyle(8,0,5);
 outtextxy(25,35,"|STUDENT REGISTER PAGE|");
 settextstyle(8,0,4);
 outtextxy(29,50,"_________________________");
 settextstyle(8,0,3);
 outtextxy(77,112,"USERNAME/EMAIL : ");
 gotoxy(43,9);
 scanf("%s",&username);
 gotoxy(43,9);
 printf("%s",username);
 //It will create a studentdata.txt file in default folder if this file is not exist.
 fp=fopen("studentdata.txt","ab");
 if(fp==NULL)
 {
 printf("Can't open file");
 exit(0);
 }
 fclose(fp);
 //Now we check that this username is already added or not.
 fp=fopen("studentdata.txt","rb");
 if(fp==NULL)
 {
 printf("Can't open file");
 exit(0);
 }
 fread(&student,sizeof(student),1,fp);
 while(!feof(fp))
 {
  if((strcmp(student.username,username))==0)
  {
   outtextxy(60,210,"THIS USERNAME HAS BEEN ALREADY ADDED");
   outtextxy(150,300,"PRESS R FOR REGISTER AGAIN");
   outtextxy(150,340,"PRESS ANY KEY TO GO BACK");
   ch=getch();
   if((ch=='R')||(ch=='r'))
      studentregisterpage();
   else
      studentpage(0);
  }
 fread(&student,sizeof(student),1,fp);
 }
 fclose(fp);
 strcpy(student.username,username);
 outtextxy(153,145,"FIRST NAME : ");
 gotoxy(43,11);
 fflush(stdin);
 scanf("%[^\n]s",&student.firstname);
 gotoxy(43,11);
 printf("%s",student.firstname);
 outtextxy(163,177,"LAST NAME : ");
 gotoxy(43,13);
 scanf("%s",&student.lastname);
 gotoxy(43,13);
 printf("%s",student.lastname);
 outtextxy(100,210,"MOBILE NUMBER : ");
 gotoxy(43,15);
 scanf("%s",&student.mobile);
 gotoxy(43,15);
 printf("%s",student.mobile);
 outtextxy(197,245,"ADDRESS : ");
 gotoxy(43,17);
 fflush(stdin);
 scanf("%[^\n]s",&student.address);
 gotoxy(43,17);
 printf("%s",student.address);
 outtextxy(177,280,"PASSWORD : ");
 gotoxy(43,19);
 scanf("%s",&student.password);
 gotoxy(43,19);
 printf("%s",student.password);
 settextstyle(8,0,3);
 outtextxy(200,340,"PRESS |S| FOR SAVE");
 outtextxy(150,380,"PRESS ANY KEY TO GO BACK");
 settextstyle(8,0,2);
 outtextxy(292,320,"_");
 outtextxy(292,345,"_");
 ch=getch();
 if((ch=='S')||(ch=='s'))
 {
  fp=fopen("studentdata.txt","ab");
  if(fp==NULL)
  {
   printf("Can't open file");
   exit(0);
  }
  fwrite(&student,sizeof(student),1,fp);
  fclose(fp);
  settextstyle(8,0,3);
  outtextxy(250,420,"REGISTERED");
  delay(1000);
  studentpage();
 }
 else
  studentpage();
}
