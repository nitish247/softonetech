/*Programming Lab
Practical No. 11
Date 10 October 2011
Program to perform various operations on linked lists such as create, insert,
display, delete and search.
SE(B)			Roll No. 03 */

#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<dos.h>

struct positions
{
	int x1,y1;
	int x2,y2;
	int active;
};

struct pos
{
	int x,y,but;
};

struct node
{
	int data;
	struct positions nodepos;
	struct node *next;
};


void showinterface();
void showmouse();
void hidemouse();
void makeinactive(int id);
void makeactive(int id);
void refreshblackwindow(struct node **head);
void create(struct node **head,int data);
void append(struct node **head,int data);
void insertafter(struct node **head,int num1,int num);
void insertatstart(struct node **head,int num);
void deletenode(struct node **head,int num);
void searchnode(struct node **head,int num);
struct pos* getmousepos();
int getresponse(struct pos *mouse);
char msg[10];
char *names[7]={"Create","Append","Insert After","Insert At Start","Delete","Search","X"};
struct node *mem[20];
struct positions button[10];
struct pos *mouse;
int dnactive=0;
int btnrelease=0;

void main()
{
	int gd=DETECT,gm,res,num,num1;
	struct node *head;
	head=NULL;

	showinterface();
	showmouse();
	setfillstyle(SOLID_FILL,LIGHTGRAY);
	while(1)
	{
		mouse=getmousepos();
		if((mouse->but&1)==1)
		{
			res=getresponse(mouse);
			setcolor(RED);
			if(res!=-1&&dnactive!=1&&button[res].active!=0)
			{
				pulldown(res);
			}
		}
		if(dnactive!=0&&mouse->but!=1)
			pullup(res);
		free(mouse);

		if(btnrelease==1)
			switch(res)
			{
				case 0:
					hidemouse();
					gotoxy(4,6);
					printf("Enter the value to insert: ");
					scanf("%d",&num);
					create(&head,num);
					showmouse();
					refreshblackwindow(&head);
					break;

				case 1:
					hidemouse();
					gotoxy(4,6);
					printf("Enter the value to insert: ");
					scanf("%d",&num);
					append(&head,num);
					showmouse();
					refreshblackwindow(&head);
					break;

				case 2:
					hidemouse();
					gotoxy(4,6);
					printf("Enter the value of node: ");
					scanf("%d",&num1);
					gotoxy(4,7);
					printf("Enter the value to insert: ");
					scanf("%d",&num);
					insertafter(&head,num1,num);
					showmouse();
					refreshblackwindow(&head);
					break;

				case 3:
					hidemouse();
					gotoxy(4,6);
					printf("Enter the value to insert: ");
					scanf("%d",&num);
					insertatstart(&head,num);
					showmouse();
					refreshblackwindow(&head);
					break;

				case 4:
					hidemouse();
					gotoxy(4,6);
					printf("Enter the value of node to delete: ");
					scanf("%d",&num);
					deletenode(&head,num);
					showmouse();
					refreshblackwindow(&head);
					break;

				case 5:
					hidemouse();
					gotoxy(4,6);
					printf("Enter the value of node to search: ");
					scanf("%d",&num);
					searchnode(&head,num);
					showmouse();
					refreshblackwindow(&head);

					break;

				case 6:
					closegraph();
					exit(0);
			}
		btnrelease=0;
	}
}

void showinterface()
{
	int i,x,y;
	int gd=DETECT,gm;
	char msg[10];
	initgraph(&gd,&gm,"C:\\TC\\BGI");
	setcolor(BLACK);
	setfillstyle(SOLID_FILL,BLUE);
	bar(0,0,640,20);
	rectangle(0,0,640,20);
	setfillstyle(SOLID_FILL,LIGHTGRAY);
	bar(0,20,640,480);
	rectangle(0,0,640,20);
	setcolor(WHITE);
	outtextxy(6,5,"Linked List Visual Demonstration");
	setcolor(BLACK);
	setfillstyle(SOLID_FILL,DARKGRAY);

	x=10;
	y=30;
	for(i=0;i<6;i++)
	{
		button[i].x1=x;
		button[i].y1=y;
		button[i].x2=x+textwidth(names[i])+5;
		button[i].y2=y+textheight(names[i])+6;
		button[i].active=1;
		bar(button[i].x1+2,button[i].y1+2,button[i].x2+2,button[i].y2+2);
		rectangle(button[i].x1+2,button[i].y1+2,button[i].x2+2,button[i].y2+2);
		bar(button[i].x1,button[i].y1,button[i].x2,button[i].y2);		bar(button[i].x1,button[i].y1,button[i].x2,button[i].y2);
		rectangle(button[i].x1,button[i].y1,button[i].x2,button[i].y2);
		outtextxy(button[i].x1+3,button[i].y1+3,names[i]);
		x+=(button[i].x2-button[i].x1)+8;
	}
	setfillstyle(SOLID_FILL,RED);
	setcolor(WHITE);
	button[i].x1=620;
	button[i].y1=3;
	button[i].x2=button[i].x1+textwidth(names[i])+5;
	button[i].y2=button[i].y1+textheight(names[i])+6;
	button[i].active=1;
	bar(button[i].x1,button[i].y1,button[i].x2,button[i].y2);		bar(button[i].x1,button[i].y1,button[i].x2,button[i].y2);
	rectangle(button[i].x1,button[i].y1,button[i].x2,button[i].y2);
	outtextxy(button[i].x1+3,button[i].y1+3,names[i]);

	setfillstyle(SOLID_FILL,BLACK);
	bar(10,70,510,440);

	makeinactive(1);
	makeinactive(2);
	makeinactive(3);
	makeinactive(4);
	makeinactive(5);

	setcolor(BLACK);
	outtextxy(550,460,"AppyBlaze");
}

void showmouse()
{
	union REGS in,out;
	in.x.ax=0;
	int86(0x33,&in,&out);
	in.x.ax=1;
	int86(0x33,&in,&out);
}

void hidemouse()
{
	union REGS in,out;
	in.x.ax=2;
	int86(0x33,&in,&out);
}

struct pos* getmousepos()
{
	struct pos *temp;
	union REGS in,out;
	temp=(struct pos*)malloc(sizeof(struct pos));
	in.x.ax=3;
	int86(0x33,&in,&out);
	temp->but=out.x.bx;
	temp->x=out.x.cx;
	temp->y=out.x.dx;
	return temp;
}

int getresponse(struct pos *mouse)
{
	int i;

	for(i=0;i<7;i++)
	{
		if((mouse->x>=button[i].x1)&&(mouse->y>=button[i].y1)&&(mouse->x<=button[i].x2)&&(mouse->y<=button[i].y2))
		{
			return i;
		}
	}
	return -1;
}

pulldown(int i)
{
	setfillstyle(SOLID_FILL,DARKGRAY);
	setcolor(BLACK);
	bar(button[i].x1+2,button[i].y1+2,button[i].x2+2,button[i].y2+2);
	rectangle(button[i].x1+2,button[i].y1+2,button[i].x2+2,button[i].y2+2);
	outtextxy(button[i].x1+5,button[i].y1+5,names[i]);
	dnactive=1;
}

pullup(int i)
{
	setfillstyle(SOLID_FILL,DARKGRAY);
	setcolor(BLACK);
	bar(button[i].x1+2,button[i].y1+2,button[i].x2+2,button[i].y2+2);
	rectangle(button[i].x1+2,button[i].y1+2,button[i].x2+2,button[i].y2+2);
	bar(button[i].x1,button[i].y1,button[i].x2,button[i].y2);
	rectangle(button[i].x1,button[i].y1,button[i].x2,button[i].y2);
	outtextxy(button[i].x1+3,button[i].y1+3,names[i]);
	dnactive=0;
	btnrelease=1;
}

void makeinactive(int i)
{
	button[i].active=0;
	setfillstyle(SOLID_FILL,DARKGRAY);
	setcolor(LIGHTGRAY);
	bar(button[i].x1+2,button[i].y1+2,button[i].x2+2,button[i].y2+2);
	rectangle(button[i].x1+2,button[i].y1+2,button[i].x2+2,button[i].y2+2);
	bar(button[i].x1,button[i].y1,button[i].x2,button[i].y2);
	rectangle(button[i].x1,button[i].y1,button[i].x2,button[i].y2);
	outtextxy(button[i].x1+3,button[i].y1+3,names[i]);
}

void makeactive(int i)
{
	button[i].active=1;
	setfillstyle(SOLID_FILL,DARKGRAY);
	setcolor(BLACK);
	bar(button[i].x1+2,button[i].y1+2,button[i].x2+2,button[i].y2+2);
	rectangle(button[i].x1+2,button[i].y1+2,button[i].x2+2,button[i].y2+2);
	bar(button[i].x1,button[i].y1,button[i].x2,button[i].y2);
	rectangle(button[i].x1,button[i].y1,button[i].x2,button[i].y2);
	outtextxy(button[i].x1+3,button[i].y1+3,names[i]);
}

void create(struct node **head,int data)
{
	struct node *temp;
	temp=*head;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->next=NULL;
	*head=temp;
	makeinactive(0);
	makeactive(1);
	makeactive(2);
	makeactive(3);
	makeactive(4);
	makeactive(5);
}

void append(struct node **head,int data)
{
	struct node *temp,*exp;
	temp=*head;
	while(temp->next!=NULL)
		temp=temp->next;
	exp=(struct node*)malloc(sizeof(struct node));
	exp->data=data;
	exp->next=NULL;
	temp->next=exp;
}

void insertafter(struct node **head,int num1,int num)
{
	struct node *temp,*exp;
	temp=*head;
	while(temp->data!=num1&&temp!=NULL)
		temp=temp->next;
	if(temp==NULL)
	{
		gotoxy(4,8);
		printf("Node %d not found!",num1);
		getch();
		return;
	}
	exp=(struct node*)malloc(sizeof(struct node));
	exp->data=num;
	exp->next=temp->next;
	temp->next=exp;
}

void insertatstart(struct node **head,int num)
{
	struct node *exp;
	exp=(struct node*)malloc(sizeof(struct node));
	exp->data=num;
	exp->next=*head;
	*head=exp;
}

void deletenode(struct node **head,int num)
{
	struct node *temp,*temp2;
	temp=*head;

	if(temp->data==num)
	{
		*head=(*head)->next;
		free(temp);
		return;
	}
	while(temp->next->data!=num&&temp->next!=NULL)
		temp=temp->next;

	if(temp->next==NULL)
	{
		gotoxy(4,8);
		printf("Node %d not found!",num);
		getch();
		return;
	}
	temp2=temp->next;
	temp->next=temp->next->next;
	free(temp2);
	gotoxy(4,8);
	printf("Node %d deleted!",num);
}

void searchnode(struct node **head,int num)
{
	struct node *temp;
	temp=*head;
	while(temp->data!=num&&temp!=NULL)
		temp=temp->next;
	if(temp!=NULL)
	{
		gotoxy(4,8);
		printf("Node %d found at location %u",num,temp);
		getch();
	}
	else
	{
		gotoxy(4,8);
		printf("Node %d not found at all...",num);
		getch();
	}
}

void refreshblackwindow(struct node **head)
{
	int y;
	struct node *temp;
	setfillstyle(SOLID_FILL,BLACK);
	bar(10,70,510,440);
	gotoxy(50,6);
	printf("Linked List:");
	y=7;
	temp=*head;
	while(temp!=NULL)
	{
		gotoxy(60,y++);
		printf("%d",temp->data);
		temp=temp->next;
	}
}