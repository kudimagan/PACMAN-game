#include<iostream.h>
#include<fstream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<process.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int middx,middy,g,gal=-1;
char sq[100][100],t5[100],hipro[100];
union REGS in,out;
class highscores
{char name[100];
 public:
 int score;
 int rank;
 char* showname()
 {return name;}
 void getn()
 {gets(name);}
 int &rerank()
 {return rank;
 }
 void nametra(char a[])
 {strcpy(name,a);}
}a,b[5];

struct pacman
{int  i,j;
 char ch;int st,end;
 int g[9][13];
 int d,de,t1,t2,life;
 int score;
}pc[5];

class pro
{
char name[100];
public:
char password[100];pacman pc[5];
char* retname()
{
return name;
}

};

void music ( int type )
{float octave[24] = {130.813,138.591,146.832,155.563,164.814,174.614,184.997,195.998,207.652,220.000,233.082,246.942, 261.626,277.183,293.665,311.127,329.628, 349.228,369.994,391.995,415.305,440,466.164,493.883};
int n, i;
switch ( type )
{case 1 :
for ( i = 0 ; i < 7 ; i+=2)
{
sound ( octave[i] * 8 ) ;
delay ( 30 ) ;
}
nosound() ;
break ;
case 2 :
n = random ( 23 ) ;
sound ( octave[n] * 2 ) ;
delay ( 100 ) ;
nosound() ;
break ;
case 3 :
while ( !kbhit() )
{n = random ( 7 ) ;
sound ( octave[n] * 4 ) ;
delay ( 100 ) ;
}
nosound() ;
if ( getch() == 0 )
getch() ;
break ;
case 4 :
for ( i = 0 ; i <=13 ; i+=4)
{sound ( octave[i] * 4 ) ;
delay ( 100 ) ;
}
nosound() ;
break ;
case 5 :
sound ( octave[1]  ) ;
delay (150 ) ;
nosound() ;break;



}
}
void callmouse()
{in.x.ax=1;
int86(0x33,&in,&out);
in.x.ax=8;
in.x.cx=8;
int86(0x33,&in,&out);
in.x.ax=8;
in.x.cx=0;
in.x.dx=480;
int86(0x33,&in,&out);
}
void mouseposi(int &xpos,int &ypos,int &click)
{
in.x.ax=3;
int86(0x33,&in,&out);
click=out.x.bx;
xpos=out.x.cx;
ypos=out.x.dx;
}
int mousehide()
{
in.x.ax=2;
int86(0x33,&in,&out);
return 1;
}
void snkstudios();
void maze(int &life);
void food();
void ghost1(char &ch,int &flog,int b[9],int c[13],int &k,int &l,int galf[9][13],int &st1,int &end1,int &,int &,int &,int &,int &,int &);
void ghost2(char &ch,int b[9],int c[13],int &k,int &l,int galf[9][13],int &st1,int &end1,int &,int &,int &,int &,int &,int &);
void ghosts(char &ch,int b[9],int c[13],int &k,int &l,int galf[9][13],int &st1,int &end1,int &,int &,int &,int &,int &,int &);

void ghost(int &i,int &j,char &ch,char &x,int b[9],int c[13],int& ,int&,int &);
void frontpage();
void music();
void menu();
void main()
{int gdriver= DETECT, gmode, errorcode;int flag1,flag2,flag3,flag4;
flag1=flag2=flag3=flag4=0;

char msg[80],ch,ch1,ch2;int pp,qq,v,w;
initgraph(&gdriver, &gmode, "C:\\TURBOC3\\BGI");

errorcode=graphresult();
if(errorcode!=grOk)
{
printf("graphics error: %s\n", grapherrormsg(errorcode));
printf("press any key");
getch();
exit(1);
}
int flag5;
int x,y,click,midx=getmaxx()/2,midy=getmaxy()/2,y1=getmaxy()/3,x1=60, j,i,p,q;
middx=getmaxx();middy=getmaxy();
int b[9]={middy/6.386,middy/3.832,middy/2.6611111111,middy/2.17727,270,middy/1.6237288136,middy/1.4088235294,middy/1.2773333333,middy/1.1542168675};
int c[13]={middx/9.05333,middx/5.432,middx/4.24375,middx/3.01777777,middx/2.6115384615,middx/2.26333,middx/2,middx-middx/2.26333,middx-middx/2.6115384615,middx-middx/3.01777777,middx-middx/4.24375,middx-middx/5.432,middx-middx/9.05333};
int d[13]={middx/9.05333,middx/5.432,middx/4.24375,middx/3.01777777,middx/2.6115384615,middx/2.26333,middx/2,middx-middx/2.26333,middx-middx/2.6115384615,middx-middx/3.01777777,middx-middx/4.24375,middx-middx/5.432,middx-middx/9.05333};
music(4);
snkstudios();
cleardevice();
frontpage();
do
{cleardevice();setcolor(9);
flag1=0;
flag2=0;
flag3=0;
flag4=0;
flag5=0;
x1=0;

callmouse();

menu();
in.x.ax=0;


while(1)
{music(2);
click=0;
in.h.ah=0;x=0;y=0;click=0;
mouseposi(x,y,click);

mouseposi(x,y,click);
if((x>midx-100)&&(x<midx+100)&&(y>midy-100)&&(y<midy-60)&&click==1)
{ flag1++;break;}
else if(x>midx-100&&x<midx+100&&y>midy-40&&y<midy&&click==1)
{flag2++;break;}
else if(x>midx-100&&x<midx+100&&y>midy+20&&y<midy+60&&click==1)

{ flag3++;break;}
else if(x>midx-100&&x<midx+100&&y>midy+80&&y<midy+120&&click==1)

{ flag4++;break;}
else if((x>midx-100&&x<midx+100&&y>midy+140&&y<midy+180&&click==1)||kbhit())

{ flag5++;break;}

}
cleardevice();

cleardevice();

char ch5;
if(flag4)
{x1=0;
settextstyle(0, HORIZ_DIR,0 );
setcolor(1);
outtextxy(0,120," Use w,a,s,d to move PAC-MAN");
outtextxy(0,140," Chomp on all PAC-PELLETS to score points ");
setcolor(14);
setfillstyle(1,14);
for (int i=0;i<7;i++)
pieslice(45*i+30,175,0,360,5);
setcolor(1);
outtextxy(0,200," A life will be lost if Pac-Man is eaten by an enemy Pac-Man");
outtextxy(0,220," The game is over when Pac-Man loses all his lives");

settextjustify(LEFT_TEXT,BOTTOM_TEXT);

   for (i=8; i<9; i++)
   {

      settextstyle(TRIPLEX_FONT, HORIZ_DIR, i);

      sprintf(msg,"    PAC-MAN",i);


      outtextxy(x1, 70, msg);


      x1 += textwidth(msg);}

getch();
}
else if(flag1)
{cleardevice();cleardevice();
int life=3;int t1=6,t2=4;
settextstyle(0,HORIZ_DIR,0);
outtextxy(0.32,20,"Greetings Gamer!!!!");
getch();
outtextxy(0.32,40,"Welcome to the amazing world of PAC-MAN created by SNK Studios");
getch();
outtextxy(0.32,60,"Let us see if you are good enough to beat me");
getch();
outtextxy(0.32,80,"Who am I?? I am just a voice.......No.... you are not nuts");
getch();
outtextxy(0.32,100,"Let the adventures begin!!!");
getch();
cleardevice();
settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);

maze(life);
setcolor(0);
setfillstyle(1,14);
food();
int st=45,end=315,k,l;int st1=135,end1=45;int st2=225,end2=135;
setfillstyle(1,14);j=4;i=6;
pieslice(c[i],b[j],st,end,10);
setfillstyle(1,4);
pieslice(getmaxx()/2,getmaxy()/2-7.5,0,360,10);
setfillstyle(1,0);
pieslice(getmaxx()/2,getmaxy()/2-7.5,st1,end1,10);
setfillstyle(1,2);
pieslice(c[6],b[8],0,360,10);
setfillstyle(1,0);
pieslice(c[6],b[8],st2,end2,10);
ch=' ';
ch1='w';int flog=0;k=6;l=3;int galf[9][13]={0};
a.score=0; char ss[25];char xx='d';p=5;q=4;int d=35,de=325,golf=0;pp=6;qq=8;ch2='a';
int x3=6,y3=6,st3=225,end3=135;char c3='a';
setfillstyle(1,6);
pieslice(c[x3],b[y3],0,360,10);
setfillstyle(1,0);
pieslice(c[x3],b[y3],st3,end3,10);ch5=ch;
for( ;life;life--)
{int efil=1;
 do
 {if(kbhit())
  ch=getch();
  t1=i;t2=j;
  if(de<=250)
  {


 if(p==i&&q==j)
  break;
  else
  if(p==i+1&&q==j&&(ch=='a'&&xx=='d'))
  break;
  else
  if(p==i-1&&q==j&&ch=='d'&&xx=='a')
  break;
  else
  if(q==j-1&&p==k&&xx=='s'&&ch=='w')
  break;
  else
  if(q==j+1&&p==k&&ch=='s'&&xx=='s')
  break;
  }
  if(ch=='4')
  a.score=3880;
   if(ch=='p')
   {label:
   cleardevice();

   setcolor(1);int x,y,click;

   settextjustify(LEFT_TEXT,BOTTOM_TEXT);
int q,midx=getmaxx()/2,midy=getmaxy()/2;
   for (q=8; q<9; q++)
   {

      settextstyle(TRIPLEX_FONT, HORIZ_DIR, q);




      outtextxy(50, 70, "PAC-MAN");



}
settextstyle(0, HORIZ_DIR,2 );
outtextxy(midx-120,midy-70, "Resume(Press R)");
outtextxy(midx-120,midy-10, "Save Game(Press S)");
outtextxy(midx-120,midy+50, "Quit(Press Q)");

for (q=EMPTY_FILL; q<1; q++)
{

   setfillstyle(q,7 );

   rectangle(midx-170, midy-100, midx+170,
      midy-60);
}
for (q=EMPTY_FILL; q<1; q++)
{

   setfillstyle(q,7 );

   rectangle(midx-170, midy-40, midx+170,
      midy);
}
for (q=EMPTY_FILL; q<1; q++)
{

   setfillstyle(q,7 );

   rectangle(midx-170, midy+20, midx+170,
      midy+60);
}char c;

while(1)
{if(kbhit())
{ch=getch();
break;}
}

if(ch=='r')
{cleardevice();setcolor(0);
 int b[9]={middy/6.386,middy/3.832,middy/2.6611111111,middy/2.17727,270,middy/1.6237288136,middy/1.4088235294,middy/1.2773333333,middy/1.1542168675};
int c[13]={middx/9.05333,middx/5.432,middx/4.24375,middx/3.01777777,middx/2.6115384615,middx/2.26333,middx/2,middx-middx/2.26333,middx-middx/2.6115384615,middx-middx/3.01777777,middx-middx/4.24375,middx-middx/5.432,middx-middx/9.05333};
int d[13]={middx/9.05333,middx/5.432,middx/4.24375,middx/3.01777777,middx/2.6115384615,middx/2.26333,middx/2,middx-middx/2.26333,middx-middx/2.6115384615,middx-middx/3.01777777,middx-middx/4.24375,middx-middx/5.432,middx-middx/9.05333};



setcolor(1);
maze(life);
 setcolor(0);
setfillstyle(1,14);

for(int i1=0;i1<9;i1++)
for(int j1=0;j1<13;j1++)
{setfillstyle(1,14);
if(i1==4||(j1==6&&(i1==0||i1==1))||(i1==3&&(j1==0||j1==1||j1==5||j1==6||j1==12||j1==11||j1==7))||((i1==5||i1==7)&&(j1==5||j1==6||j1==7))||(j1==4&&i1==6))
 ;
 else
if(!galf[i1][j1])

fillellipse(d[j1],b[i1],5,5);
}
if(st==45&&end==315)
{setfillstyle(1,14);
 pieslice(d[i],b[j],st,end,10);
 }
 else
 {setfillstyle(1,14);
 pieslice(d[i],b[j],0,360,10);
 setfillstyle(1,0);
 pieslice(d[i],b[j],st,end,10);
 setfillstyle(1,14);
}
}
else
if(ch=='S'||ch=='s')
{ pro h;
h.pc[0].i=i;h.pc[0].j=j;h.pc[0].d=d;h.pc[0].de=de;h.pc[0].ch=ch5;h.pc[0].st=st;h.pc[0].end=end;
 for(int dp=0;dp<9;dp++)
 for(int mycd=0;mycd<13;mycd++)
h.pc[0].g[dp][mycd]=galf[dp][mycd];h.pc[0].life=life;
 h.pc[0].t1=t1;
 h.pc[0].t2=t2;
 h.pc[1].i=k;h.pc[1].j=l;h.pc[1].ch=ch1;h.pc[1].st=st1;h.pc[1].end=end1;
 h.pc[2].i=pp;h.pc[2].j=qq;h.pc[2].st=st2;h.pc[2].end=end2;h.pc[2].ch=ch2;
 h.pc[3].i=x3;h.pc[3].j=y3;h.pc[3].st=st3;h.pc[3].end=end3;h.pc[3].ch=c3;
 h.pc[4].i=p;h.pc[4].j=q;h.pc[4].ch=xx;h.pc[0].score=a.score;
 ofstream fin("Masterfile",ios::app);
 char n[100];
 cleardevice();
 closegraph();
 clrscr();
 cout<<"\n\n\t\t Enter name     : ";
 gets(n);
 gal=0;strcpy(hipro,n);
 ifstream fi(n);
 if(!fi)
 {
 cout<<" \n\n\t\t Enter password : ";
 gets(h.password);
 ofstream f(n);
 strcpy(h.retname(),n);
 f.write((char*)&h,sizeof(h));
 fin.write(n,strlen(n));
 fin.put('\n');

 }
else
{
pro h1;
ofstream f(n);
fi.read((char*)&h1,sizeof(h1));
strcpy(h.password,h1.password);
f.write((char*)&h,sizeof(h));

}

initgraph(&gdriver, &gmode, "C:\\TURBOC3\\BGI");
cleardevice();
setcolor(-1);
settextstyle(TRIPLEX_FONT,HORIZ_DIR,8);
outtextxy(0.32,getmaxy()/2," GAME SAVED!!!!!");

 sleep(2);
 cleardevice();
 goto label;
}
else
if(ch=='q'||ch=='Q')
life=-1;

ch='z';
} if(life==-1)
  break;

  if(ch=='w')
  {if((j==0&&(i==0||i==1||i==2||i==3||i==4||i==5||i==6||i==7||i==8||i==9||i==10||i==11||i==12))||(j==1&&(i==2||i==3||i==4||i==8||i==9||i==10))||(j==2&&(i==6))||(j==3&&(i==3||i==4||i==8||i==9))||(j==5&&(i==1||i==0||i==12||i==11))||(j==4&&(i==5||i==6||i==7))||(j==6&&(i==1||i==2||i==5||i==6||i==7||i==10||i==11))||(j==8&&(i==1||i==2||i==6||i==10||i==11))||(j==7&&(i==5||i==7))
  )
  ;else
  {setfillstyle(1,0);
   pieslice(c[i],b[j],0,360,10);

   galf[j][i]++;

   if(galf[j][i]==1)
   if(j==4||(i==6&&(j==0||j==1))||(j==3&&(i==0||i==1||i==5||i==6||i==12||i==11||i==7))||((j==5||j==7)&&(i==5||i==6||i==7)))
   ;
   else
   {a.score+=10;}
   if((l==j-1&&ch1=='s'&&k==i)||(qq==j-1&&ch2=='s'&&pp==i)||(y3==j-1&&c3=='s'&&x3==i))break;
   j--;st=135;end=45;setfillstyle(1,14);pieslice(c[i],b[j],0,360,10);
   setfillstyle(1,0);pieslice(c[i],b[j],st,end,10);delay(de);
   }}
   else
  if(ch=='a')
 {if((j==0&&(i==0||i==7))||(j==1&&(i==0||i==1||i==7||i==12))||(j==2&&i==0)||(j==3&&(i==2||i==3||i==6||i==10||i==8))||(j==4&&i==2)||(j==5&&(i==0||i==8))||(j==6&&(i==3||i==0||i==10))||(j==7&&(i==8||i==0||i==1||i==12))||(j==8&&i==0))
  ;
  else
  {setfillstyle(1,0);
   pieslice(c[i],b[j],0,360,10);

   galf[j][i]++;

   if(galf[j][i]==1)
   if(j==4||(i==6&&(j==0||j==1))||(j==3&&(i==0||i==1||i==5||i==6||i==12||i==11||i==7))||((j==5||j==7)&&(i==5||i==6||i==7)))
   ;
   else
   {a.score+=10;}
   if((k==i-1&&ch1=='d'&&j==l)||(pp==i-1&&ch2=='d'&&j==qq)||(x3==i-1&&c3=='d'&&j==y3))break;
   i--;st=225;end=135;setfillstyle(1,14);pieslice(c[i],b[j],0,360,10);
   setfillstyle(1,0);pieslice(c[i],b[j],st,end,10);delay(de);
   }}
   else
   if(ch=='s')
 {if((j==0&&(i==2||i==3||i==4||i==8||i==9||i==10))||(j==2&&(i==0||i==1||i==3||i==4||i==5||i==7||i==8||i==9||i==11||i==12))||(j==3&&i==6)||((j==4||j==6)&&(i==5||i==6||i==7))||((j==5||j==7)&&(i==1||i==2||i==10||i==11))||j==8)
  ;
  else
  {setfillstyle(1,0);
   pieslice(c[i],b[j],0,360,10);galf[j][i]++;

   if(galf[j][i]==1)
   if(j==4||(i==6&&(j==0||j==1))||(j==3&&(i==0||i==1||i==5||i==6||i==12||i==11||i==7))||((j==5||j==7)&&(i==5||i==6||i==7)))
   ;
   else
   {a.score+=10;}
   if((ch1=='w'&&l==j+1&&k==i)||(ch2=='w'&&qq==j+1&&pp==i)||(c3=='w'&&y3==j+1&&x3==i))break;
   j++;st=225;end=315;setfillstyle(1,14);pieslice(c[i],b[j],0,360,10);
setfillstyle(1,0);pieslice(c[i],b[j],st,end,10);delay(de);
   }}
   else
   if(ch=='d')
 {if((j==0&&(i==5||i==12))||(j==1&&(i==0||i==5||i==11||i==12))||((j==2||j==8)&&i==12)||(j==3&&(i==2||i==4||i==9||i==10))||(j==4&&i==10)||(j==5&&(i==4||i==12))||(j==6&&(i==2||i==9||i==12))||(j==7&&(i==0||i==4||i==11||i==12)))
  ;
  else
  {
  setfillstyle(1,0);
   pieslice(c[i],b[j],0,360,10);galf[j][i]++;




   if(galf[j][i]==1)
   if(j==4||(i==6&&(j==0||j==1))||(j==3&&(i==0||i==1||i==5||i==6||i==12||i==11||i==7))||((j==5||j==7)&&(i==5||i==6||i==7)))
   ;
   else
   {a.score+=10;}
   if((ch1=='a'&&k==i+1&&l==j)||(ch2=='a'&&pp==i+1&&qq==j)||(c3=='a'&&x3==i+1&&y3==j))break;
   i++;st=45;end=315;setfillstyle(1,14);
   pieslice(c[i],b[j],st,end,10);delay(de);
   }}
   else if(ch=='0')
   break;


if((k==i&&j==l)&&(j==qq&&i==pp)||(j==y3&&i==x3))
  break;
if(de<=250)
{
if((p==i&&q==j))
  break;
}
if(ch!='p')
{ghost1(ch1,flog,b,c,k,l,galf,st1,end1,d,de,t1,t2,i,j);
 ghost2(ch2,b,c,pp,qq,galf,st2,end2,d,de,t1,t2,i,j);
 ghosts(c3,b,c,x3,y3,galf,st3,end3,d,de,t1,t2,i,j);
}
if(de<=250)
ghost(i,j,ch,xx,b,c,p,q,d);

if((l==j&&i==k)||(pp==i&&qq==j)||(x3==i&&y3==j))
break;
outtextxy(135,20,ss);
ultoa(a.score,ss,10);
setcolor(1);
settextstyle(1,HORIZ_DIR,2);
outtextxy(135,20,ss);
setcolor(0);ch5=ch;
if(((a.score%890==0&&a.score/890.0==1)||(a.score%1880==0&&a.score/1880.0==1)||(a.score%2970==0)&&a.score/2970.0==1)&&a.score!=0)
{setcolor(-1);
settextstyle(TRIPLEX_FONT,HORIZ_DIR,8);
 outtextxy(0.32,getmaxy()/2," LEVEL CLEAR!!!!!");
 music(4);

 getch();
 cleardevice();
 settextstyle(0, HORIZ_DIR,0 );
 switch(a.score/890)
 {
  case 1:setcolor(9);
	 outtextxy(0.32,20," LEVEL 2");
	 outtextxy(0.32,40," That was, by my standards a PIECE OF CAKE");
	 getch();
	 outtextxy(0.32,60," BUT....You have angered the enemy PAC-MEN");
	 getch();
	 outtextxy(0.32,80," And now....You will feel their WRATH!!");
	 getch();a.score+=100;de-=50;d-=4;
	 break;
  case 2:setcolor(9);
	 outtextxy(0.32,20," LEVEL 3");
	 outtextxy(0.32,40," My ghost program looks REALLY DUMB....doesn't it??");
	 getch();
	 outtextxy(0.32,60," Don't worry, one of my ghosts has managed to place a..(wait for it)");
	 getch();
	 outtextxy(0.32,80," a tracking device on you, and will always be one step behind you");
	 getch();
	 outtextxy(0.32,100," WOO-HOOHOOHOO-HAHAHAHAHAHA....(coughing)");
	 getch();a.score+=200;de-=25;d-=3;
	 break;
  case 3:setcolor(9);
	 outtextxy(0.32,20," LEVEL 4");
	 outtextxy(0.32,40," You are good, much better than the others I hunted");
	 getch();
	 outtextxy(0.32,60," Too bad, I am going to have to finish you too!");
	 outtextxy(0.32,80," @!#@$@!$#%@#%@%!@~@#$@#%@#%......(ANGRY)");
	 getch();a.score+=300;de-=75;d-=12;break;
  case 4:break;

}
cleardevice();
for(int i1=0;i1<9;i1++)
for(int j1=0;j1<13;j1++)
galf[i1][j1]=0;
maze(life);
setcolor(0);ch2='a';
setfillstyle(1,14);
for(i1=0;i1<9;i1++)
for(j1=0;j1<13;j1++)
{setfillstyle(1,14);
if(i1==4||(j1==6&&(i1==0||i1==1))||(i1==3&&(j1==0||j1==1||j1==5||j1==6||j1==12||j1==11||j1==7))||((i1==5||i1==7)&&(j1==5||j1==6||j1==7)))
 ;
 else if(!galf[i1][j1])
 fillellipse(c[j1],b[i1],5,5);
}
st=45;end=315;st1=135;end1=45;
setfillstyle(1,14);j=4;i=6;p=5;q=4;
pieslice(c[i],b[j],st,end,10);
setfillstyle(1,4);
pieslice(getmaxx()/2,getmaxy()/2-7.5,0,360,10);
setfillstyle(1,0);
pieslice(getmaxx()/2,getmaxy()/2-7.5,st1,end1,10);
ch=' ';
ch1='w';flog=0;k=6;l=3;
food();xx='d';pp=6;qq=8;st2=225;end2=135;
x3=6;y3=6;st3=225;end3=135;c3='a';
setfillstyle(1,6);
pieslice(c[x3],b[y3],0,360,10);
setfillstyle(1,0);
pieslice(c[x3],b[y3],st3,end3,10);
}
if(a.score/3890.0==1)
break;

}while(1);
if(a.score/3890.0==1)
break;
if(life==-1)
break;
setcolor(-1);
settextstyle(TRIPLEX_FONT,HORIZ_DIR,8);
outtextxy(0.32,getmaxy()/2," LIFE LOST!!!!!");
getch();
cleardevice();
setcolor(1);ch2='a';
settextstyle(0, HORIZ_DIR,2 );
maze(life-1);
setcolor(0);
setfillstyle(1,14);
for(int i1=0;i1<9;i1++)
for(int j1=0;j1<13;j1++)
{setfillstyle(1,14);
if(i1==4||(j1==6&&(i1==0||i1==1))||(i1==3&&(j1==0||j1==1||j1==5||j1==6||j1==12||j1==11||j1==7))||((i1==5||i1==7)&&(j1==5||j1==6||j1==7)))
 ;
 else if(!galf[i1][j1])
 fillellipse(c[j1],b[i1],5,5);
}
st=45;end=315;st1=135;end1=45;
setfillstyle(1,14);j=4;i=6;p=5;q=4;
pieslice(c[i],b[j],st,end,10);
setfillstyle(1,4);xx='d';
pieslice(getmaxx()/2,getmaxy()/2-7.5,0,360,10);
setfillstyle(1,0);
pieslice(getmaxx()/2,getmaxy()/2-7.5,st1,end1,10);
ch=' ';
ch1='w';flog=0;k=6;l=3;pp=6;qq=8;st2=225;end2=135;
x3=6;y3=6;st3=225;end3=135;c3='a';
setfillstyle(1,6);
pieslice(c[x3],b[y3],0,360,10);
setfillstyle(1,0);
pieslice(c[x3],b[y3],st3,end3,10);
}
setcolor(-1);
settextstyle(TRIPLEX_FONT,HORIZ_DIR,8);
if(a.score/3890.0==1)
outtextxy(0.32,getmaxy()/2," YOU WIN!!!!!!");
else
outtextxy(0.32,getmaxy()/2," Game Over!!!!!!");
sleep(3);
cleardevice();
if(life==-1)
;
else
{
int pos;highscores t;int j5;
closegraph();textcolor(BLUE);
cout<<"HIGH-SCORES\n";
if(gal==-1)
{cout<<"Enter your name\t\t";
a.getn();}
else
a.nametra(hipro);
initgraph(&gdriver, &gmode, "C:\\TURBOC3\\BGI");
cleardevice(); ifstream fin("HIGH-SCORES.dat");
highscores b[6];
for(int the=0;the<5;the++)
{
fin.read((char*)&b[the],104);
ultoa(b[the].score,sq[the],10);
}
b[5]=a;

ultoa(a.score,sq[5],10);


for(pos=0;pos<5;pos++)
for(j5=0;j5<5-pos;j5++)
if(b[j5].score<b[j5+1].score)
{t=b[j5];
 b[j5]=b[j5+1];
 b[j5+1]=t;
 strcpy(t5,sq[j5]);
 strcpy(sq[j5],sq[j5+1]);
 strcpy(sq[j5+1],t5);

}
for(j5=1;j5<=5;j5++)
b[j5-1].rerank()=j5;
setcolor(9);
settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
outtextxy(0.32,47.5,"HIGH-SCORES");
for(pos=0;pos<5;pos++)
{
outtextxy(0.32,120+70*pos,b[pos].showname());
outtextxy(225,120+70*pos,sq[pos]);
}
fin.close();
ofstream fout("HIGH-SCORES.dat");

for(int thea=0;thea<5;thea++)
{fout.write((char*)&b[thea],104);

}
fout.close();

getch();
}

}
else if(flag3)
{setcolor(9);
settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
outtextxy(0.32,47.5,"HIGH-SCORES");
highscores b[5];
ifstream fin("HIGH-SCORES.dat");
for(int the=0;the<5;the++)
{fin.read((char*)&b[the],104);
 ultoa(b[the].score,sq[the],10);
}

for(int pos=0;pos<5;pos++)
{
outtextxy(0.32,120+70*pos,b[pos].showname());
outtextxy(225,120+70*pos,sq[pos]);
}
getch();
}
else
if(flag2)
{
char n[100];
cleardevice();

clrscr();

int galf[9][13];
 char ss[25];
  int bd[9]={middy/6.386,middy/3.832,middy/2.6611111111,middy/2.17727,270,middy/1.6237288136,middy/1.4088235294,middy/1.2773333333,middy/1.1542168675};
int c[13]={middx/9.05333,middx/5.432,middx/4.24375,middx/3.01777777,middx/2.6115384615,middx/2.26333,middx/2,middx-middx/2.26333,middx-middx/2.6115384615,middx-middx/3.01777777,middx-middx/4.24375,middx-middx/5.432,middx-middx/9.05333};
int dd[13]={middx/9.05333,middx/5.432,middx/4.24375,middx/3.01777777,middx/2.6115384615,middx/2.26333,middx/2,middx-middx/2.26333,middx-middx/2.6115384615,middx-middx/3.01777777,middx-middx/4.24375,middx-middx/5.432,middx-middx/9.05333};
int i,j,k,l,pp,qq,p,q,st,end,st1,end1,st2,end2,st3,end3,flog,golf,x3,y3,t1,t2,d,de,life;
cleardevice();
closegraph();
char ch,ch1,ch2,c3,xx;
cout<<"\n\t\tEnter Your NAME      : ";
gets(n);
ifstream f(n);
 if(f)
{
 pro h;char password[100];
 f.read((char*)&h,sizeof(h));
 cout<<"\n\n\t\tEnter Your PASSWORD  : ";
gets(password);
 if(strcmp(password,h.password)==0)
 {
 strcpy(hipro,n);gal=0;
 i=h.pc[0].i;j=h.pc[0].j;st=h.pc[0].st;end=h.pc[0].end; ch=h.pc[0].ch; d=h.pc[0].d;de=h.pc[0].de;t1=h.pc[0].t1;t2=h.pc[0].t2;
 ch5=ch;life=h.pc[0].life+1;
 for(int ku=0;ku<9;ku++)
 for(int lu=0;lu<13;lu++)
 galf[ku][lu]=h.pc[0].g[ku][lu];
 k=h.pc[1].i;l=h.pc[1].j;st1=h.pc[1].st;end1=h.pc[1].end; ch1=h.pc[1].ch;
 pp=h.pc[2].i;qq=h.pc[2].j;st2=h.pc[2].st;end2=h.pc[2].end; ch2=h.pc[2].ch;
 x3=h.pc[3].i;y3=h.pc[3].j;st3=h.pc[3].st;end3=h.pc[3].end; c3=h.pc[3].ch;
 p=h.pc[4].i;q=h.pc[4].j; xx=h.pc[4].ch; life=h.pc[0].life;a.score=h.pc[0].score; flog=1;golf=0;
 }
 initgraph(&gdriver, &gmode, "C:\\TURBOC3\\BGI");
 cleardevice();

 setcolor(1);
 maze(life);
 setcolor(0);
 if(st==45&&end==315)
{setfillstyle(1,14);
 pieslice(dd[i],bd[j],st,end,10);
 }
 else
 {setfillstyle(1,14);
 pieslice(dd[i],bd[j],0,360,10);
 setfillstyle(1,0);
 pieslice(dd[i],bd[j],st,end,10);
 setfillstyle(1,14);
}


 for(int i1=0;i1<9;i1++)
for(int j1=0;j1<13;j1++)
{setfillstyle(1,14);
if(i1==4||(j1==6&&(i1==0||i1==1))||(i1==3&&(j1==0||j1==1||j1==5||j1==6||j1==12||j1==11||j1==7))||((i1==5||i1==7)&&(j1==5||j1==6||j1==7))||(j1==4&&i1==6))
 ;
 else
if(!galf[i1][j1]&&!(i1==j&&j1==i))

fillellipse(dd[j1],bd[i1],5,5);

}
 for( ;life;life--)
{int efil=1;
 do
 {
  if(kbhit())
  ch=getch();
  t1=i;t2=j;
  if(de<=250)
  {


 if(p==i&&q==j)
  break;
  else
  if(p==i+1&&q==j&&(ch=='a'&&xx=='d'))
  break;
  else
  if(p==i-1&&q==j&&ch=='d'&&xx=='a')
  break;
  else
  if(q==j-1&&p==k&&xx=='s'&&ch=='w')
  break;
  else
  if(q==j+1&&p==k&&ch=='s'&&xx=='s')
  break;
  }
  if(ch=='4')
  a.score=3880;
   if(ch=='p')
   {NUT:
   cleardevice();

   setcolor(1);int x,y,click;

   settextjustify(LEFT_TEXT,BOTTOM_TEXT);
int q,midx=getmaxx()/2,midy=getmaxy()/2;
   for (q=8; q<9; q++)
   {

      settextstyle(TRIPLEX_FONT, HORIZ_DIR, q);




      outtextxy(50, 70, "PAC-MAN");



}
settextstyle(0, HORIZ_DIR,2 );
outtextxy(midx-120,midy-70, "Resume(Press R)");
outtextxy(midx-120,midy-10, "Save Game(Press S)");
outtextxy(midx-120,midy+50, "Quit(Press Q)");

for (q=EMPTY_FILL; q<1; q++)
{

   setfillstyle(q,7 );

   rectangle(midx-170, midy-100, midx+170,
      midy-60);
}
for (q=EMPTY_FILL; q<1; q++)
{

   setfillstyle(q,7 );

   rectangle(midx-170, midy-40, midx+170,
      midy);
}
for (q=EMPTY_FILL; q<1; q++)
{

   setfillstyle(q,7 );

   rectangle(midx-170, midy+20, midx+170,
      midy+60);
}char c;

while(1)
{if(kbhit())
{ch=getch();
break;}
}

if(ch=='r')
{cleardevice();setcolor(0);
 int b[9]={middy/6.386,middy/3.832,middy/2.6611111111,middy/2.17727,270,middy/1.6237288136,middy/1.4088235294,middy/1.2773333333,middy/1.1542168675};
int c[13]={middx/9.05333,middx/5.432,middx/4.24375,middx/3.01777777,middx/2.6115384615,middx/2.26333,middx/2,middx-middx/2.26333,middx-middx/2.6115384615,middx-middx/3.01777777,middx-middx/4.24375,middx-middx/5.432,middx-middx/9.05333};
int d[13]={middx/9.05333,middx/5.432,middx/4.24375,middx/3.01777777,middx/2.6115384615,middx/2.26333,middx/2,middx-middx/2.26333,middx-middx/2.6115384615,middx-middx/3.01777777,middx-middx/4.24375,middx-middx/5.432,middx-middx/9.05333};



setcolor(1);
maze(life);
 setcolor(0);
setfillstyle(1,14);

for(int i1=0;i1<9;i1++)
for(int j1=0;j1<13;j1++)
{setfillstyle(1,14);
if(i1==4||(j1==6&&(i1==0||i1==1))||(i1==3&&(j1==0||j1==1||j1==5||j1==6||j1==12||j1==11||j1==7))||((i1==5||i1==7)&&(j1==5||j1==6||j1==7))||(j1==4&&i1==6))
 ;
 else
if(!galf[i1][j1])

fillellipse(d[j1],b[i1],5,5);
}
if(st==45&&end==315)
{setfillstyle(1,14);
 pieslice(d[i],b[j],st,end,10);
 }
 else
 {setfillstyle(1,14);
 pieslice(d[i],b[j],0,360,10);
 setfillstyle(1,0);
 pieslice(d[i],b[j],st,end,10);
 setfillstyle(1,14);
}
}
else
if(ch=='S'||ch=='s')
{pro h;
h.pc[0].i=i;h.pc[0].j=j;h.pc[0].d=d;h.pc[0].de=de;h.pc[0].ch=ch5;h.pc[0].st=st;h.pc[0].end=end;
 for(int dp=0;dp<9;dp++)
 for(int mycd=0;mycd<13;mycd++)
h.pc[0].g[dp][mycd]=galf[dp][mycd];h.pc[0].life=life;
h.pc[0].t1=t1;
h.pc[0].t2=t2;
h.pc[1].i=k;h.pc[1].j=l;h.pc[1].ch=ch1;h.pc[1].st=st1;h.pc[1].end=end1;
h.pc[2].i=pp;h.pc[2].j=qq;h.pc[2].st=st2;h.pc[2].end=end2;h.pc[2].ch=ch2;
h.pc[3].i=x3;h.pc[3].j=y3;h.pc[3].st=st3;h.pc[3].end=end3;h.pc[3].ch=c3;
 h.pc[4].i=p;h.pc[4].j=q;h.pc[4].ch=xx;h.pc[0].score=a.score;
 ofstream fin ("masterfile",ios::app);
 char n[100];int flug=0;
 cleardevice();
 closegraph();
 clrscr();

 cout<<" Enter your name   : ";
 gets(n);
 strcpy(h.retname(),n);
 ifstream f1(n);
 if(!f1)
 {ofstream f(n);
 cout<<"\n Enter password : ";
     char c;
    int pos = 0;
    do {
	c = getch();

	if( isprint(c) )
	{
	    h.password[ pos++ ] = c;
	    cout<<'*';
	}
	else if( c == 8 && pos )
	{
	    h.password[ pos-- ] = '\0';
	   cout<<"\b \b";
	}
    } while( c != 13 );


 f.write((char*)&h,sizeof(h));
 fin.write(n,strlen(n));
 fin.put('\n');}
 else
 { pro h1;
  f1.read((char*)&h1,sizeof(h1));
  strcpy(h.password,h1.password);
  ofstream f(n);
 f.write((char*)&h,sizeof(h));
 }
 initgraph(&gdriver, &gmode, "C:\\TURBOC3\\BGI");
 cleardevice();
 setcolor(-1);
settextstyle(TRIPLEX_FONT,HORIZ_DIR,8);
outtextxy(0.32,getmaxy()/2," GAME SAVED!!!!!");
 sleep(2);
 goto NUT;
}
else if(ch=='q'||ch=='Q')
life=-1;

ch='z';
}
  if(life==-1)
  break;
  if(ch=='w')
  {if((j==0&&(i==0||i==1||i==2||i==3||i==4||i==5||i==6||i==7||i==8||i==9||i==10||i==11||i==12))||(j==1&&(i==2||i==3||i==4||i==8||i==9||i==10))||(j==2&&(i==6))||(j==3&&(i==3||i==4||i==8||i==9))||(j==5&&(i==1||i==0||i==12||i==11))||(j==4&&(i==5||i==6||i==7))||(j==6&&(i==1||i==2||i==5||i==6||i==7||i==10||i==11))||(j==8&&(i==1||i==2||i==6||i==10||i==11))||(j==7&&(i==5||i==7))
  )
  ;else
  {setfillstyle(1,0);
   pieslice(c[i],b[j],0,360,10);

   galf[j][i]++;

   if(galf[j][i]==1)
   if(j==4||(i==6&&(j==0||j==1))||(j==3&&(i==0||i==1||i==5||i==6||i==12||i==11||i==7))||((j==5||j==7)&&(i==5||i==6||i==7)))
   ;
   else
   {a.score+=10;}
   if((l==j-1&&ch1=='s'&&k==i)||(qq==j-1&&ch2=='s'&&pp==i)||(y3==j-1&&c3=='s'&&x3==i))break;
   j--;st=135;end=45;setfillstyle(1,14);pieslice(c[i],b[j],0,360,10);
   setfillstyle(1,0);pieslice(c[i],b[j],st,end,10);delay(de);
   }}
   else
  if(ch=='a')
 {if((j==0&&(i==0||i==7))||(j==1&&(i==0||i==1||i==7||i==12))||(j==2&&i==0)||(j==3&&(i==2||i==3||i==6||i==10||i==8))||(j==4&&i==2)||(j==5&&(i==0||i==8))||(j==6&&(i==3||i==0||i==10))||(j==7&&(i==8||i==0||i==1||i==12))||(j==8&&i==0))
  ;
  else
  {setfillstyle(1,0);
   pieslice(c[i],b[j],0,360,10);

   galf[j][i]++;

   if(galf[j][i]==1)
   if(j==4||(i==6&&(j==0||j==1))||(j==3&&(i==0||i==1||i==5||i==6||i==12||i==11||i==7))||((j==5||j==7)&&(i==5||i==6||i==7)))
   ;
   else
   {a.score+=10;}
   if((k==i-1&&ch1=='d'&&j==l)||(pp==i-1&&ch2=='d'&&j==qq)||(x3==i-1&&c3=='d'&&j==y3))break;
   i--;st=225;end=135;setfillstyle(1,14);pieslice(c[i],b[j],0,360,10);
   setfillstyle(1,0);pieslice(c[i],b[j],st,end,10);delay(de);
   }}
   else
   if(ch=='s')
 {if((j==0&&(i==2||i==3||i==4||i==8||i==9||i==10))||(j==2&&(i==0||i==1||i==3||i==4||i==5||i==7||i==8||i==9||i==11||i==12))||(j==3&&i==6)||((j==4||j==6)&&(i==5||i==6||i==7))||((j==5||j==7)&&(i==1||i==2||i==10||i==11))||j==8)
  ;
  else
  {setfillstyle(1,0);
   pieslice(c[i],b[j],0,360,10);galf[j][i]++;

   if(galf[j][i]==1)
   if(j==4||(i==6&&(j==0||j==1))||(j==3&&(i==0||i==1||i==5||i==6||i==12||i==11||i==7))||((j==5||j==7)&&(i==5||i==6||i==7)))
   ;
   else
   {a.score+=10;}
   if((ch1=='w'&&l==j+1&&k==i)||(ch2=='w'&&qq==j+1&&pp==i)||(c3=='w'&&y3==j+1&&x3==i))break;
   j++;st=225;end=315;setfillstyle(1,14);pieslice(c[i],b[j],0,360,10);
setfillstyle(1,0);pieslice(c[i],b[j],st,end,10);delay(de);
   }}
   else
   if(ch=='d')
 {if((j==0&&(i==5||i==12))||(j==1&&(i==0||i==5||i==11||i==12))||((j==2||j==8)&&i==12)||(j==3&&(i==2||i==4||i==9||i==10))||(j==4&&i==10)||(j==5&&(i==4||i==12))||(j==6&&(i==2||i==9||i==12))||(j==7&&(i==0||i==4||i==11||i==12)))
  ;
  else
  {
  setfillstyle(1,0);
   pieslice(c[i],b[j],0,360,10);galf[j][i]++;




   if(galf[j][i]==1)
   if(j==4||(i==6&&(j==0||j==1))||(j==3&&(i==0||i==1||i==5||i==6||i==12||i==11||i==7))||((j==5||j==7)&&(i==5||i==6||i==7)))
   ;
   else
   {a.score+=10;}
   if((ch1=='a'&&k==i+1&&l==j)||(ch2=='a'&&pp==i+1&&qq==j)||(c3=='a'&&x3==i+1&&y3==j))break;
   i++;st=45;end=315;setfillstyle(1,14);
   pieslice(c[i],b[j],st,end,10);delay(de);
   }}
   else if(ch=='0')
   break;


if((k==i&&j==l)&&(j==qq&&i==pp)||(j==y3&&i==x3))
  break;
if(de<=250)
{
if((p==i&&q==j))
  break;
}
if(ch!='p')
{ghost1(ch1,flog,b,c,k,l,galf,st1,end1,d,de,t1,t2,i,j);
 ghost2(ch2,b,c,pp,qq,galf,st2,end2,d,de,t1,t2,i,j);
 ghosts(c3,b,c,x3,y3,galf,st3,end3,d,de,t1,t2,i,j);
}
if(de<=250)
ghost(i,j,ch,xx,b,c,p,q,d);

if((l==j&&i==k)||(pp==i&&qq==j)||(x3==i&&y3==j))
break;
outtextxy(135,20,ss);
ultoa(a.score,ss,10);
setcolor(1);
settextstyle(1,HORIZ_DIR,2);
outtextxy(135,20,ss);
setcolor(0);ch5=ch;
if(((a.score%890==0&&a.score/890.0==1)||(a.score%1880==0&&a.score/1880.0==1)||(a.score%2970==0)&&a.score/2970.0==1)&&a.score!=0)
{setcolor(-1);
settextstyle(TRIPLEX_FONT,HORIZ_DIR,8);
 outtextxy(0.32,getmaxy()/2," LEVEL CLEAR!!!!!");
 music(4);

 getch();
 cleardevice();
 settextstyle(0, HORIZ_DIR,0 );
 switch(a.score/890)
 {
  case 1:setcolor(9);
	 outtextxy(0.32,20," LEVEL 2");
	 outtextxy(0.32,40," That was, by my standards a PIECE OF CAKE");
	 getch();
	 outtextxy(0.32,60," BUT....You have angered the enemy PAC-MEN");
	 getch();
	 outtextxy(0.32,80," And now....You will feel their WRATH!!");
	 getch();a.score+=100;de-=50;d-=4;
	 break;
  case 2:setcolor(9);
	 outtextxy(0.32,20," LEVEL 3");
	 outtextxy(0.32,40," My ghost program looks REALLY DUMB....doesn't it??");
	 getch();
	 outtextxy(0.32,60," Don't worry, one of my ghosts has managed to place a..(wait for it)");
	 getch();
	 outtextxy(0.32,80," a tracking device on you, and will always be one step behind you");
	 getch();
	 outtextxy(0.32,100," WOO-HOOHOOHOO-HAHAHAHAHAHA....(coughing)");
	 getch();a.score+=200;de-=25;d-=3;
	 break;
  case 3:setcolor(9);
	 outtextxy(0.32,20," LEVEL 4");
	 outtextxy(0.32,40," You are good, much better than the others I hunted");
	 getch();
	 outtextxy(0.32,60," Too bad, I am going to have to finish you too!");
	 outtextxy(0.32,80," @!#@$@!$#%@#%@%!@~@#$@#%@#%......(ANGRY)");
	 getch();a.score+=300;de-=75;d-=12;break;
  case 4:break;

}
cleardevice();
for(int i1=0;i1<9;i1++)
for(int j1=0;j1<13;j1++)
galf[i1][j1]=0;
maze(life);
setcolor(0);ch2='a';
setfillstyle(1,14);
for(i1=0;i1<9;i1++)
for(j1=0;j1<13;j1++)
{setfillstyle(1,14);
if(i1==4||(j1==6&&(i1==0||i1==1))||(i1==3&&(j1==0||j1==1||j1==5||j1==6||j1==12||j1==11||j1==7))||((i1==5||i1==7)&&(j1==5||j1==6||j1==7)))
 ;
 else if(!galf[i1][j1])
 fillellipse(c[j1],b[i1],5,5);
}
st=45;end=315;st1=135;end1=45;
setfillstyle(1,14);j=4;i=6;p=5;q=4;
pieslice(c[i],b[j],st,end,10);
setfillstyle(1,4);
pieslice(getmaxx()/2,getmaxy()/2-7.5,0,360,10);
setfillstyle(1,0);
pieslice(getmaxx()/2,getmaxy()/2-7.5,st1,end1,10);
ch=' ';
ch1='w';flog=0;k=6;l=3;
food();xx='d';pp=6;qq=8;st2=225;end2=135;
x3=6;y3=6;st3=225;end3=135;c3='a';
setfillstyle(1,6);
pieslice(c[x3],b[y3],0,360,10);
setfillstyle(1,0);
pieslice(c[x3],b[y3],st3,end3,10);
}
if(a.score/3890.0==1)
break;

}while(1);
if(a.score/3890.0==1)
break;
if(life==-1)
break;
setcolor(-1);
settextstyle(TRIPLEX_FONT,HORIZ_DIR,8);
outtextxy(0.32,getmaxy()/2," LIFE LOST!!!!!");
getch();
cleardevice();
setcolor(1);ch2='a';
settextstyle(0, HORIZ_DIR,2 );
maze(life-1);
setcolor(0);
setfillstyle(1,14);
for(int i1=0;i1<9;i1++)
for(int j1=0;j1<13;j1++)
{setfillstyle(1,14);
if(i1==4||(j1==6&&(i1==0||i1==1))||(i1==3&&(j1==0||j1==1||j1==5||j1==6||j1==12||j1==11||j1==7))||((i1==5||i1==7)&&(j1==5||j1==6||j1==7)))
 ;
 else if(!galf[i1][j1])
 fillellipse(c[j1],b[i1],5,5);
}
st=45;end=315;st1=135;end1=45;
setfillstyle(1,14);j=4;i=6;p=5;q=4;
pieslice(c[i],b[j],st,end,10);
setfillstyle(1,4);xx='d';
pieslice(getmaxx()/2,getmaxy()/2-7.5,0,360,10);
setfillstyle(1,0);
pieslice(getmaxx()/2,getmaxy()/2-7.5,st1,end1,10);
ch=' ';
ch1='w';flog=0;k=6;l=3;pp=6;qq=8;st2=225;end2=135;
x3=6;y3=6;st3=225;end3=135;c3='a';
setfillstyle(1,6);
pieslice(c[x3],b[y3],0,360,10);
setfillstyle(1,0);
pieslice(c[x3],b[y3],st3,end3,10);
}
setcolor(-1);
settextstyle(TRIPLEX_FONT,HORIZ_DIR,8);
if(a.score/3890.0==1)
outtextxy(0.32,getmaxy()/2," YOU WIN!!!!!!");
else
outtextxy(0.32,getmaxy()/2," Game Over!!!!!!");
sleep(3);
cleardevice();

if(life==-1);
else
{
int pos;highscores t;int j5;
closegraph();textcolor(BLUE);
cout<<"HIGH-SCORES\n";
cout<<"Enter your name\t\t";
a.getn();
initgraph(&gdriver, &gmode, "C:\\TURBOC3\\BGI");
cleardevice(); ifstream fin("HIGH-SCORES.dat");
highscores b[6];
for(int the=0;the<5;the++)
{fin.read((char*)&b[the],104);
 ultoa(b[the].score,sq[the],10);
}
b[5]=a;

ultoa(a.score,sq[5],10);


for(pos=0;pos<5;pos++)
for(j5=0;j5<5-pos;j5++)
if(b[j5].score<b[j5+1].score)
{t=b[j5];
 b[j5]=b[j5+1];
 b[j5+1]=t;
 strcpy(t5,sq[j5]);
 strcpy(sq[j5],sq[j5+1]);
 strcpy(sq[j5+1],t5);

}
for(j5=1;j5<=5;j5++)
b[j5-1].rerank()=j5;
setcolor(9);
settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
outtextxy(0.32,47.5,"HIGH-SCORES");
for(pos=0;pos<5;pos++)
{
outtextxy(0.32,120+70*pos,b[pos].showname());
outtextxy(225,120+70*pos,sq[pos]);
}
fin.close();
ofstream fout("HIGH-SCORES.dat");

for(int theaa=0;theaa<5;theaa++)
{fout.write((char*)&b[theaa],104);}

getch();
fout.close();
}
}
else
cout<<"SAVE-DATA DOESN'T EXIST!!!";

}
click=0;



}while(flag3||flag2||flag1);


}
void maze(int &life)
{setcolor(1);
line(0,0,0,getmaxy()-10);
line(0,0,getmaxx()-10,0);
line(getmaxx()-10,0,getmaxx()-10,getmaxy()-10);
line(0,getmaxy()-10,getmaxx()-10,getmaxy()-10);//border
settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
outtextxy(20,20,"SCORE:");
outtextxy(420,20,"LIVES:");
line(50,50,50,getmaxy()/2-40);//maze border starts
line(50,getmaxy()/2+30,50,getmaxy()-40);
line(getmaxx()-50,50,getmaxx()-50,getmaxy()/2-40);
line(getmaxx()-50,getmaxy()/2+30,getmaxx()-50,getmaxy()-40);
line(50,50,getmaxx()-50,50);
line(50,getmaxy()-40,getmaxx()-50,getmaxy()-40);
line(50,getmaxy()/2-40,120,getmaxy()/2-40);
line(50,getmaxy()/2+30,120,getmaxy()/2+30);
line(120,getmaxy()/2-40,120,getmaxy()/2+30);
line(getmaxx()-50,getmaxy()/2-40,getmaxx()-120,getmaxy()/2-40);
line(getmaxx()-50,getmaxy()/2+30,getmaxx()-120,getmaxy()/2+30);
line(getmaxx()-120,getmaxy()/2-40,getmaxx()-120,getmaxy()/2+30);//maze border ends
line(100,100,100,getmaxy()/2-80);
line(getmaxx()-100,100,getmaxx()-100,getmaxy()/2-80);
line(150,100,250,100);
line(getmaxx()-150,100,getmaxx()-250,100);
line(getmaxx()/2,50,getmaxx()/2,getmaxy()/2-100);//middle line
line(180,getmaxy()/2-45,290,getmaxy()/2-45);
line(getmaxx()-180,getmaxy()/2-45,getmaxx()-290,getmaxy()/2-45);
line(180,getmaxy()/2-45,180,getmaxy()/2-10);
line(getmaxx()-180,getmaxy()/2-45,getmaxx()-180,getmaxy()/2-10);
line(280,getmaxy()/2-20,280,getmaxy()/2+10);
line(getmaxx()-280,getmaxy()/2-20,getmaxx()-280,getmaxy()/2+10);
line(280,getmaxy()/2+10,getmaxx()-280,getmaxy()/2+10);
line(270,getmaxy()/2+50,getmaxx()-270,getmaxy()/2+50);
line(getmaxx()/2,getmaxy()/2+50,getmaxx()/2,getmaxy()/1.5);
line(120,getmaxy()/2+80,180,getmaxy()/2+80);
line(getmaxx()-120,getmaxy()/2+80,getmaxx()-180,getmaxy()/2+80);
line(180,getmaxy()/2+80,180,getmaxy()/2+120);
line(getmaxx()-180,getmaxy()/2+80,getmaxx()-180,getmaxy()/2+120);
line(270,getmaxy()/2+120,getmaxx()-270,getmaxy()/2+120);
line(getmaxx()/2,getmaxy()/2+120,getmaxx()/2,getmaxy()/1.25);
line(90,getmaxy()/2+120,90,getmaxy()/1.22);
line(getmaxx()-90,getmaxy()/2+120,getmaxx()-90,getmaxy()/1.22);
line(90,getmaxy()/1.22,175,getmaxy()/1.22);
line(getmaxx()-90,getmaxy()/1.22,getmaxx()-175,getmaxy()/1.22);
setcolor(14);
setfillstyle(1,14);
for(int i=1;i<=life;i++)
pieslice(500+11*i,10,0,360,4.3);
setcolor(1);
}
void food()
{int b[9]={middy/6.386,middy/3.832,middy/2.6611111111,middy/2.17727,270,middy/1.6237288136,middy/1.4088235294,middy/1.2773333333,middy/1.1542168675};
 int d[13]={middx/9.05333,middx/5.432,middx/4.24375,middx/3.01777777,middx/2.6115384615,middx/2.26333,middx/2,middx-middx/2.26333,middx-middx/2.6115384615,middx-middx/3.01777777,middx-middx/4.24375,middx-middx/5.432,middx-middx/9.05333};
for(int i1=0;i1<9;i1++)
for(int j1=0;j1<13;j1++)
{setfillstyle(1,14);
if(i1==4||(j1==6&&(i1==0||i1==1))||(i1==3&&(j1==0||j1==1||j1==5||j1==6||j1==12||j1==11||j1==7))||((i1==5||i1==7)&&(j1==5||j1==6||j1==7))||(j1==4&&i1==6))
 ;
 else


fillellipse(d[j1],b[i1],5,5);
}
 }

void frontpage()
{int i;
 settextjustify(LEFT_TEXT,BOTTOM_TEXT);
 settextstyle(TRIPLEX_FONT, HORIZ_DIR, 8);
 for(i=1;i<=21;i++)
 {if(i%2)
 setcolor(14);
 else
 setcolor(0);
 outtextxy(50,150 , "PAC-MAN");
 delay(10);
 music(2);
 }

 int b[9]={middy/6.386,middy/3.832,middy/2.6611111111,middy/2.17727,270,middy/1.6237288136,middy/1.4088235294,middy/1.2773333333,middy/1.1542168675};
 int c[13]={middx/9.05333,middx/5.432,middx/4.24375,middx/3.01777777,middx/2.6115384615,middx/2.26333,middx/2,middx-middx/2.26333,middx-middx/2.6115384615,middx-middx/3.01777777,middx-middx/4.24375,middx-middx/5.432,middx-middx/9.05333};
 setcolor(-1);
 settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
 outtextxy(100,b[4],"LOADING........");
 setcolor(14);
 setfillstyle(1,14);
 for(i=0;i<13;i++)
 pieslice(c[i],b[7],0,360,5);
 setcolor(0);
 pieslice(c[0],b[7],45,315,10);
 for(i=0;i<12;i++)
 {setfillstyle(1,0);
   pieslice(c[i],b[7],0,360,10);
   setfillstyle(1,14);
   pieslice(c[i+1],b[7],45,315,10);
   music(2);
   delay(250);

  }











}
void menu()
{settextjustify(LEFT_TEXT,BOTTOM_TEXT);
int i,midx=getmaxx()/2,midy=getmaxy()/2;
   for (i=8; i<9; i++)
   {

      settextstyle(TRIPLEX_FONT, HORIZ_DIR, i);




      outtextxy(50, 70, "PAC-MAN");



}
settextstyle(0, HORIZ_DIR,2 );
outtextxy(midx-80,midy-70, "New Game");
outtextxy(midx-80,midy-10, "Load Game");
outtextxy(midx-80,midy+50, "Hi-Score");
outtextxy(midx-80,midy+110, "Help");
outtextxy(midx-80,midy+170,"Quit");
for (i=EMPTY_FILL; i<1; i++)
{

   setfillstyle(i,7 );

   rectangle(midx-100, midy-100, midx+100,
      midy-60);
}
for (i=EMPTY_FILL; i<1; i++)
{

   setfillstyle(i,7 );

   rectangle(midx-100, midy-40, midx+100,
      midy);
}
for (i=EMPTY_FILL; i<1; i++)
{

   setfillstyle(i,7 );

   rectangle(midx-100, midy+20, midx+100,
      midy+60);
}

for (i=EMPTY_FILL; i<1; i++)
{

   setfillstyle(i,7 );

   rectangle(midx-100, midy+80, midx+100,
      midy+120);
}
for (i=EMPTY_FILL; i<1; i++)
{

   setfillstyle(i,7 );

   rectangle(midx-100, midy+140, midx+100,
      midy+180);
}




}
void ghost1(char &ch1,int &flog,int b[9],int c[13],int &k,int &l,int galf[9][13],int &st1,int &end1,int &d,int &de,int &t1,int &t2,int &i,int &j)
{if(ch1=='w')
{setfillstyle(1,0);
 if(flog)
 {pieslice(c[k],b[l],0,360,10);}
 else
 pieslice(c[k],getmaxy()/2-7.5,0,360,10);
 if(!galf[l][k]&&!(k==6&&l==3))
{setfillstyle(1,14);fillellipse(c[k],b[l],5,5);}
   l--;st1=135;end1=45;setfillstyle(1,4);pieslice(c[k],b[l],0,360,10);
   setfillstyle(1,0);pieslice(c[k],b[l],st1,end1,10);
   if(t1==i&&t2==j)
   delay(de-d-50);
   else
   delay(d);
   flog++;
if(l==2)
ch1='a';
else if(l==0&&k==0)
ch1='d';
else if(l==0&&k==12)
ch1='a';

}

else
if(ch1=='a')
{setfillstyle(1,0);
   pieslice(c[k],b[l],0,360,10);if(!galf[l][k])
{setfillstyle(1,14);fillellipse(c[k],b[l],5,5);}
   k--;st1=225;end1=135;setfillstyle(1,4);pieslice(c[k],b[l],0,360,10);
   setfillstyle(1,0);pieslice(c[k],b[l],st1,end1,10);if(t1==i&&t2==j)
   delay(de-d-50);
   else
   delay(d);

if(k==0)
ch1='w';
else
if(k==7&&l==0)
ch1='s';
}
else
if(ch1=='d')
 { setfillstyle(1,0);
   pieslice(c[k],b[l],0,360,10);if(!galf[l][k])
{  setfillstyle(1,14);fillellipse(c[k],b[l],5,5);}
   k++;st1=45;end1=315;setfillstyle(1,4);
   pieslice(c[k],b[l],st1,end1,10);if(t1==i&&t2==j)
   delay(de-d-50);
   else
   delay(d);
 if(k==5&&l==0)
 ch1='s';
 else if(k==12&&l==2)
 ch1='w';
}
else
if(ch1=='s')
{setfillstyle(1,0);
   pieslice(c[k],b[l],0,360,10);if(!galf[l][k])
{setfillstyle(1,14);fillellipse(c[k],b[l],5,5);}
   l++;st1=225;end1=315;setfillstyle(1,4);pieslice(c[k],b[l],0,360,10);
setfillstyle(1,0);pieslice(c[k],b[l],st1,end1,10);if(t1==i&&t2==j)
   delay(de-d-50);
   else
   delay(d);
if(l==2&&k==7)
ch1='a';
else if(k==5&&l==2)
ch1='d';
}
}
void ghost(int &i,int &j,char &ch,char &x,int b[9], int c[13],int &k,int &l,int &d)
{
 setfillstyle(1,9);
 int p,q,st,end;
 pieslice(c[k],b[l],45,315,10);
 if(ch=='d'&&(j==l) )
 {x='d';
 setfillstyle(1,0);
 pieslice(c[k],b[l],0,360,10);
 k++;st=45;end=315;setfillstyle(1,9);
 pieslice(c[k],b[l],st,end,10);delay(d);}
 else
 if(ch=='a'&&(j==l) )
 {x='a';
 setfillstyle(1,0);
   pieslice(c[k],b[l],0,360,10) ;
 k--;st=225;end=135;setfillstyle(1,9);pieslice(c[k],b[l],0,360,10);
 setfillstyle(1,0);pieslice(c[k],b[l],st,end,10);delay(d);
 }
 else
 if(ch=='w'&&(i==k) )
 {x='w';
 setfillstyle(1,0);
   pieslice(c[k],b[l],0,360,10) ;
 l--;st=135;end=45;setfillstyle(1,9);pieslice(c[k],b[l],0,360,10);
 setfillstyle(1,0);pieslice(c[k],b[l],st,end,10);delay(d);
 }
 else
 if(ch=='s'&&(i==k) )
 {x='s';
 setfillstyle(1,0);
   pieslice(c[k],b[l],0,360,10)  ;
 l++;st=225;end=315;setfillstyle(1,9);pieslice(c[k],b[l],0,360,10);
 setfillstyle(1,0);pieslice(c[k],b[l],st,end,10);delay(d);
 }
 else
 if(ch=='w') //over
{ if(x=='a'&&i+1==k)
 {
 setfillstyle(1,0);
   pieslice(c[k],b[l],0,360,10)  ;
 x='w';
 k--;st=135;end=45;setfillstyle(1,9);pieslice(c[k],b[l],0,360,10);
 setfillstyle(1,0);pieslice(c[k],b[l],st,end,10);delay(d);
 }
 else if(x=='d'&&i==k+1)
 {
 setfillstyle(1,0);
   pieslice(c[k],b[l],0,360,10)   ;
 k++;x='w';
 st=45;end=315;setfillstyle(1,9);pieslice(c[k],b[l],st,end,10);delay(d);
 }
}
else
if(ch=='d')
{
if(x=='w'&&j+1==l)
 {
 setfillstyle(1,0);
   pieslice(c[k],b[l],0,360,10)  ;

 l--;st=135;end=45;setfillstyle(1,9);pieslice(c[k],b[l],0,360,10);
 x='d';
 setfillstyle(1,0);pieslice(c[k],b[l],st,end,10);delay(d);
 }

 else
 if(x=='s'&&j==l+1)//over
 {
 setfillstyle(1,0);
   pieslice(c[k],b[l],0,360,10)   ;
 l++;st=225;end=315;setfillstyle(1,9);pieslice(c[k],b[l],0,360,10);
 setfillstyle(1,0);pieslice(c[k],b[l],st,end,10);delay(d);
 x='d';
 }
}
else
if(ch=='s')
{ if(x=='a'&&i+1==k)
 {
 setfillstyle(1,0);
   pieslice(c[k],b[l],0,360,10)  ;
 x='s';
 k--;st=225;end=135;setfillstyle(1,9);pieslice(c[k],b[l],0,360,10);
 setfillstyle(1,0);pieslice(c[k],b[l],st,end,10);delay(d);
 }
 else
 if(x=='d'&&i==k+1)
 {
 setfillstyle(1,0);
   pieslice(c[k],b[l],0,360,10)   ;
 k++;st=45;end=315;setfillstyle(1,9);pieslice(c[k],b[l],st,end,10);delay(d);
 x='s';
 }
}
else
if(ch=='a')    //over
{ if(x=='w'&&j+1==l)
 {
 setfillstyle(1,0);
   pieslice(c[k],b[l],0,360,10)  ;
 x='a';
 l--;st=135;end=45;setfillstyle(1,9);pieslice(c[k],b[l],0,360,10);
 setfillstyle(1,0);pieslice(c[k],b[l],st,end,10);delay(d);
 }
 else if(x=='s'&&j==l+1)
 {
 setfillstyle(1,0);
   pieslice(c[k],b[l],0,360,10)   ;
 l++;x='a';
 st=225;end=315;setfillstyle(1,9);pieslice(c[k],b[l],0,360,10);
 setfillstyle(1,0);pieslice(c[k],b[l],st,end,10);delay(d);
 }
}
}
void ghost2(char &ch1,int b[9],int c[13],int &k,int &l,int galf[9][13],int &st1,int &end1,int &d,int &de,int &t1,int &t2,int &i,int&j)
{if(ch1=='w')
{setfillstyle(1,0);
 if(1)
   pieslice(c[k],b[l],0,360,10);
 else
 pieslice(c[k],getmaxy()/2,0,360,10); if(!galf[l][k])
{setfillstyle(1,14);fillellipse(c[k],b[l],5,5);}
   l--;st1=135;end1=45;setfillstyle(1,2);pieslice(c[k],b[l],0,360,10);
   setfillstyle(1,0);pieslice(c[k],b[l],st1,end1,10);
   if(t1==i&&t2==j)
   delay(de-d-50);
   else
   delay(d);
if(k==0&&l==6)
ch1='d';
else if(l==6&&k==4)
ch1='d';
else if(l==6&&k==10)
ch1='d';

}

else
if(ch1=='a')
{setfillstyle(1,0);
   pieslice(c[k],b[l],0,360,10);if(!galf[l][k])
{setfillstyle(1,14);fillellipse(c[k],b[l],5,5);}
   k--;st1=225;end1=135;setfillstyle(1,2);pieslice(c[k],b[l],0,360,10);
   setfillstyle(1,0);pieslice(c[k],b[l],st1,end1,10);
    if(t1==i&&t2==j)
   delay(de-d-50);
   else
   delay(d);

if(k==0&&l==8)
ch1='w';

}
else
if(ch1=='d')
 { setfillstyle(1,0);
   pieslice(c[k],b[l],0,360,10);if(!galf[l][k])
{  setfillstyle(1,14);fillellipse(c[k],b[l],5,5);}
   k++;st1=45;end1=315;setfillstyle(1,2);
   pieslice(c[k],b[l],st1,end1,10);
    if(t1==i&&t2==j)
   delay(de-d-50);
   else
   delay(d);
 if(k==2&&l==6)
 ch1='s';
 else if(k==4&&l==7)
 ch1='w';
 else if(k==9&&l==6)
 ch1='s';
 else if(k==10&&l==7)
 ch1='w';
 else if(k==12&&l==6)
 ch1='s';


}
else
if(ch1=='s')
{setfillstyle(1,0);
   pieslice(c[k],b[l],0,360,10);if(!galf[l][k])
{setfillstyle(1,14);fillellipse(c[k],b[l],5,5);}
   l++;st1=225;end1=315;setfillstyle(1,2);pieslice(c[k],b[l],0,360,10);
setfillstyle(1,0);pieslice(c[k],b[l],st1,end1,10);
 if(t1==i&&t2==j)
   delay(de-d-50);
   else
   delay(d);
if(l==7&&k==2)
ch1='d';
else if(k==9&&l==7)
ch1='d';
else if(l==8&&k==12)
ch1='a';
}
}
void ghosts(char &ch1,int b[9],int c[13],int &k,int &l,int galf[9][13],int &st1,int &end1,int &d,int &de,int &t1,int &t2,int &i,int&j)
{if(ch1=='w')
{setfillstyle(1,0);
 if(1)
   pieslice(c[k],b[l],0,360,10);
 else
 pieslice(c[k],getmaxy()/2,0,360,10); if(!galf[l][k])
{setfillstyle(1,14);fillellipse(c[k],b[l],5,5);}
   l--;st1=135;end1=45;setfillstyle(1,6);pieslice(c[k],b[l],0,360,10);
   setfillstyle(1,0);pieslice(c[k],b[l],st1,end1,10);
   if(t1==i&&t2==j)
   delay(d);
   else
   delay(d);
if(l==5&&k==3)
ch1='a';
else
if(l==2&&k==2)
ch1='a';
else
if(l==1&&k==1)
ch1='d';
else if(l==1&&k==7)
ch1='d';
}


else
if(ch1=='a')
{setfillstyle(1,0);
   pieslice(c[k],b[l],0,360,10);if(!galf[l][k])
{setfillstyle(1,14);fillellipse(c[k],b[l],5,5);}
   k--;st1=225;end1=135;setfillstyle(1,6);pieslice(c[k],b[l],0,360,10);
   setfillstyle(1,0);pieslice(c[k],b[l],st1,end1,10);
   if(t1==i&&t2==j)
   delay(d);
   else
   delay(d);

if(k==2&&l==5)
ch1='w';
else if (k==1&&l==2)
ch1='w';
else if(k==10&&l==2)
ch1='s';
else if(k==8&&l==5)
ch1='s';
else if(l==6&&k==3)
ch1='w';
else if(l==6&&k==3)
ch1='w';
}
else
if(ch1=='d')
 { setfillstyle(1,0);
   pieslice(c[k],b[l],0,360,10);if(!galf[l][k])
{  setfillstyle(1,14);fillellipse(c[k],b[l],5,5);}
   k++;st1=45;end1=315;setfillstyle(1,6);
   pieslice(c[k],b[l],st1,end1,10);
   {if(t1==i&&t2==j)
   delay(d);
   else
   delay(d);
   }
 if(k==5&&l==1)
 ch1='s';
 else if(k==11&&l==1)
 ch1='s';
 else
 if(k==7&&l==2)
 ch1='w';
}
else
if(ch1=='s')
{setfillstyle(1,0);
   pieslice(c[k],b[l],0,360,10);if(!galf[l][k])
{setfillstyle(1,14);fillellipse(c[k],b[l],5,5);}
   l++;st1=225;end1=315;setfillstyle(1,6);pieslice(c[k],b[l],0,360,10);
setfillstyle(1,0);pieslice(c[k],b[l],st1,end1,10);
if(t1==i&&t2==j)
   delay(d);
   else
   delay(d);
if(k==5&&l==2)
ch1='d';
else
if(k==11&&l==2)
ch1='a';
else if(k==10&&l==5)
ch1='a';
else if  (k==8&&l==6)
ch1='a';
}
}
void snkstudios()
{randomize();
 int c;
 c=1+random(15);
 setcolor(c);
 settextstyle(TRIPLEX_FONT,HORIZ_DIR,9);
 outtextxy(235,50,"S");
 outtextxy(235,250,"K");
 outtextxy(235,160,"N");
 sound(130.81);
delay(200);
nosound();delay(200);
setcolor(c);
 settextstyle(TRIPLEX_FONT,HORIZ_DIR,9);
 outtextxy(235,50,"S");
 outtextxy(235,250,"K");
 outtextxy(235,160,"N");
sound(130.81);
delay(100);
nosound();delay(100);
c=1+random(15);
setcolor(c);
 settextstyle(TRIPLEX_FONT,HORIZ_DIR,9);
 outtextxy(235,50,"S");
 outtextxy(235,250,"K");
 outtextxy(235,160,"N");

sound(130.81);
delay(100);
nosound();delay(100);
c=1+random(15);
setcolor(c);
 settextstyle(TRIPLEX_FONT,HORIZ_DIR,9);
 outtextxy(235,50,"S");
 outtextxy(235,250,"K");
 outtextxy(235,160,"N");
sound(155.56);
delay(400);
nosound();delay(200);
c=1+random(15);
setcolor(c);
 settextstyle(TRIPLEX_FONT,HORIZ_DIR,9);
 outtextxy(235,50,"S");
 outtextxy(235,250,"K");
 outtextxy(235,160,"N");
sound(130.81);
delay(200);
nosound();delay(150);
c=1+random(15);
setcolor(c);
 settextstyle(TRIPLEX_FONT,HORIZ_DIR,9);
 outtextxy(235,50,"S");
 outtextxy(235,250,"K");
 outtextxy(235,160,"N");
sound(130.81);
delay(100);
nosound();delay(100);
c=1+random(15);
setcolor(c);
 settextstyle(TRIPLEX_FONT,HORIZ_DIR,9);
 outtextxy(235,50,"S");
 outtextxy(235,250,"K");
 outtextxy(235,160,"N");
sound(155.86);
delay(300);
nosound();delay(100);
c=1+random(15);
 setcolor(c);
 settextstyle(TRIPLEX_FONT,HORIZ_DIR,9);
 outtextxy(235,50,"S");
 outtextxy(235,250,"K");
 outtextxy(235,160,"N");

sound(130.81);
delay(100);
nosound();delay(100);
c=1+random(15);
 setcolor(c);
 settextstyle(TRIPLEX_FONT,HORIZ_DIR,9);
 outtextxy(235,50,"S");
 outtextxy(235,250,"K");
 outtextxy(235,160,"N");

sound(130.81);
delay(100);
nosound();delay(100);
c=1+random(15);
 setcolor(c);
 settextstyle(TRIPLEX_FONT,HORIZ_DIR,9);
 outtextxy(235,50,"S");
 outtextxy(235,250,"K");
 outtextxy(235,160,"N");

sound(155.56);
delay(200);
nosound();delay(200);
c=1+random(15);
 setcolor(c);
 settextstyle(TRIPLEX_FONT,HORIZ_DIR,9);
 outtextxy(235,50,"S");
 outtextxy(235,250,"K");
 outtextxy(235,160,"N");

sound(130.81);
delay(200);
nosound();delay(200);
c=1+random(15);
 setcolor(c);
 settextstyle(TRIPLEX_FONT,HORIZ_DIR,9);
 outtextxy(235,50,"S");
 outtextxy(235,250,"K");
 outtextxy(235,160,"N");

sound(130.81);
delay(100);
nosound();delay(100);
c=1+random(15);
 setcolor(c);
 settextstyle(TRIPLEX_FONT,HORIZ_DIR,9);
 outtextxy(235,50,"S");
 outtextxy(235,250,"K");
 outtextxy(235,160,"N");

sound(130.81);
delay(100);
nosound();delay(100);
c=1+random(15);
 setcolor(c);
 settextstyle(TRIPLEX_FONT,HORIZ_DIR,9);
 outtextxy(235,50,"S");
 outtextxy(235,250,"K");
 outtextxy(235,160,"N");

sound(155.56);
delay(400);
nosound();delay(200);
c=1+random(15);
 setcolor(c);
 settextstyle(TRIPLEX_FONT,HORIZ_DIR,9);
 outtextxy(235,50,"S");
 outtextxy(235,250,"K");
 outtextxy(235,160,"N");
 sound(130.81);

delay(200);
nosound();delay(200);
c=1+random(15);
 setcolor(c);
 settextstyle(TRIPLEX_FONT,HORIZ_DIR,9);
 outtextxy(235,50,"S");
 outtextxy(235,250,"K");
 outtextxy(235,160,"N");

sound(116.54);
delay(150);
nosound();delay(100);
c=1+random(15);
 setcolor(c);
 settextstyle(TRIPLEX_FONT,HORIZ_DIR,9);
 outtextxy(235,50,"S");
 outtextxy(235,250,"K");
 outtextxy(235,160,"N");

sound(110);
delay(300);
nosound();delay(100);
c=1+random(15);
 setcolor(c);
 settextstyle(TRIPLEX_FONT,HORIZ_DIR,9);
 outtextxy(235,50,"S");
 outtextxy(235,250,"K");
 outtextxy(235,160,"N");

sound(116.54);
delay(300);
nosound();delay(100);
c=1+random(15);
 setcolor(c);
 settextstyle(TRIPLEX_FONT,HORIZ_DIR,9);
 outtextxy(235,50,"S");
 outtextxy(235,250,"K");
 outtextxy(235,160,"N");

sound(123.47);
delay(200);
nosound();delay(100);

 setcolor(9);
 settextstyle(TRIPLEX_FONT,HORIZ_DIR,9);
 outtextxy(235,50,"S");
 outtextxy(235,250,"K");
 outtextxy(235,160,"N");




 sleep(1);




 }





