//Snake Game by Pineapple Software

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>
#include<dos.h>

#define MINX 20
#define MINY 20
#define MAXX 420
#define MAXY 420

struct snake	//Doubly Linked List for Each Piece of Snake
{
	snake *prev;
	int x,y;
	int color;
	int n;
	snake *next;
};

void updatescore(int);
void statusmsg(char*);

snake *head,*tail;
int width=10,height=10,bgcolor=BLACK;
int xdir=1,ydir=0;
int cnt=1,foodcnt=0;
int speed=60;

void initsnake();
void drawsnake();
void erasesnake();
void insertsnakenode();

void main()
{
	int gd=DETECT,gm;
	int key,rx,ry,rc,score=0,lost=0,specialfood=0,splfooditr=0,splfoodlost=0;
	char msg[10];
	REGS in,out;
	snake *i;
	initgraph(&gd,&gm,"");

	setcolor(WHITE);
	rectangle(MINX-1,MINY-1,MAXX+1,MAXY+1);
	outtextxy(435,30,"Snake (VGA)");
	outtextxy(20,460,"Pineapple Software");
	updatescore(score);

	initsnake();
	drawsnake();

	rectangle(MINX-1,MINY-1,MAXX+1,MAXY+1);
	randomize();

	rx=random(MAXX-MINX-10)+1+20;
	ry=random(MAXX-MINX-10)+1+20;
	rx+=10-(rx%10);
	ry+=10-(ry%10);
	rc=random(16);
	if(rc==BLACK)rc=WHITE;
	setfillstyle(SOLID_FILL,rc);
	bar(rx,ry,rx+9,ry+9);
	foodcnt++;

	statusmsg("Press Enter");
	while(getch()!='\r');
	statusmsg("");

	while(1)
	{
		if(kbhit())
		{
			in.h.ah=0;
			int86(22,&in,&out);
			key=out.h.ah;

			if(key==1)
				exit(0);

			if(key==80&&ydir==0)
			{
				ydir=1;
				xdir=0;
			}

			if(key==72&&ydir==0)
			{
				ydir=-1;
				xdir=0;
			}

			if(key==75&&xdir==0)
			{
				xdir=-1;
				ydir=0;
			}

			if(key==77&&xdir==0)
			{
				xdir=1;
				ydir=0;
			}
//			printf("%d\n",key);
		}

		erasesnake();

		if(specialfood==1)
		{
			setfillstyle(SOLID_FILL,rc++);
			bar(rx,ry,rx+9,ry+9);
			sprintf(msg,"%d",50-splfooditr);
			statusmsg(msg);
			splfooditr++;

			if(splfooditr==50)
			{
				setfillstyle(SOLID_FILL,BLACK);
				bar(rx,ry,rx+9,ry+9);
				splfoodlost=1;
				statusmsg("");
			}
		}

		if(((head->x==rx)&&(head->y==ry))||splfoodlost==1)
		{
			if(specialfood==1&&splfoodlost==0)
				score+=20*splfooditr;

			if(specialfood==0)
				score+=20;

			splfoodlost=0;
			statusmsg("");
			if(foodcnt%5==0)
			{
				specialfood=1;
				rx=random(MAXX-MINX-10)+1+20;
				ry=random(MAXX-MINX-10)+1+20;
				rx+=10-(rx%10);
				ry+=10-(ry%10);
				rc=1;
				setfillstyle(SOLID_FILL,rc);
				bar(rx,ry,rx+9,ry+9);
				foodcnt++;
				splfooditr=0;
			}
			else
			{
				specialfood=0;
				rx=random(MAXX-MINX-10)+1+20;
				ry=random(MAXX-MINX-10)+1+20;
				rx+=10-(rx%10);
				ry+=10-(ry%10);
				rc=random(16);
				if(rc==BLACK)rc=WHITE;
				setfillstyle(SOLID_FILL,rc);
				bar(rx,ry,rx+10,ry+10);
				foodcnt++;
			}
			updatescore(score);
			insertsnakenode();
		}

		for(i=head->next;i!=NULL;i=i->next)
		{
			if((head->x==i->x)&&(head->y==i->y))
			{
				lost=1;
				break;
			}
		}

		if(lost==1)
			break;

		for(i=tail;i!=head;i=i->prev)
		{
			i->x=i->prev->x;
			i->y=i->prev->y;
		}

		if((head->x>=MAXX-10)&&xdir==1)
			head->x=MINX-10;
		else
		if((head->y>=MAXY-10)&&ydir==1)
			head->y=MINY-10;
		else
		if((head->x<=MINX)&&xdir==-1)
			head->x=MAXX;
		else
		if((head->y<=MINY)&&ydir==-1)
			head->y=MAXY;

		head->x+=10*xdir;
		head->y+=10*ydir;

		drawsnake();
		delay(speed);
	}

	if(lost==1)
	{
		statusmsg("You Lost! Press Enter");
		while(getch()!='\r');
	}

	closegraph();
}

void initsnake()
{
	snake *p,*i;
	head=tail=NULL;

	do
	{
		if(head==NULL)
		{
			p=new snake;
			p->prev=NULL;
			p->x=(MINX+MAXX)/2;
			p->y=(MINY+MAXY)/2;
			p->color=GREEN;
			p->next=NULL;
			p->n=1;
			head=tail=p;
		}
		else
		{
			p=new snake;
			p->prev=tail;
			p->x=tail->x-width;
			p->y=tail->y;
			p->color=GREEN;
			p->next=NULL;
			p->n=tail->n+1;
			tail->next=p;
			p->next=NULL;
			tail=p;
		}
		cnt++;
	}while(cnt!=10);
}

void insertsnakenode()
{
	snake *p;
	p=new snake;
	p->prev=tail;
	p->x=tail->x-width;
	p->y=200;
	p->color=GREEN;
	p->next=NULL;
	p->n=tail->n+1;
	tail->next=p;
	p->next=NULL;
	tail=p;
	cnt++;
}

void drawsnake()
{
	snake *i;

	for(i=head;i!=NULL;i=i->next)
	{
		setfillstyle(SOLID_FILL,i->color);
		bar(i->x,i->y,i->x+width,i->y+height);
		if(i==head)
		{
			if(xdir==1)
			{
				putpixel(i->x+8,i->y+3,BLACK);
				putpixel(i->x+8,i->y+8,BLACK);
			}

			if(xdir==-1)
			{
				putpixel(i->x+3,i->y+3,BLACK);
				putpixel(i->x+3,i->y+8,BLACK);
			}

			if(ydir==-1)
			{
				putpixel(i->x+3,i->y+3,BLACK);
				putpixel(i->x+8,i->y+3,BLACK);
			}

			if(ydir==1)
			{
				putpixel(i->x+3,i->y+8,BLACK);
				putpixel(i->x+8,i->y+8,BLACK);
			}
		}
	}
}

void erasesnake()
{
	setfillstyle(SOLID_FILL,BLACK);
	bar(tail->x,tail->y,tail->x+width,tail->y+height);
}

void updatescore(int score)
{
	char scoremsg[20];
	sprintf(scoremsg,"Score: %d",score);
	setfillstyle(SOLID_FILL,BLACK);
	bar(430,200,470+textwidth(scoremsg),200+textheight(scoremsg));
	setcolor(WHITE);
	outtextxy(435,200,scoremsg);
}

//Updates status message
void statusmsg(char *msg)
{
	setfillstyle(SOLID_FILL,BLACK);
	bar(430,400,640,410);
	setcolor(WHITE);
	outtextxy(435,400,msg);
}

/*
(C) 2012, Pineapple Software @ SoftOne Tech
*/