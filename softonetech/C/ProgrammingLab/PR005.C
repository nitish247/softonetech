/*Programming Lab
Practical No. 5
Date 25 August 2011
Program to perform operations on students database such as Display,
Insert, Modify, Delete, Search and Sort
This program is having specially enhanced interface with arrow keys
SE(B)			Roll No. 03 */

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>

typedef struct date1
{
	int dd;
	int mm;
	int yy;
}date1;

struct dbase
{
	int roll;
	char name[20];
	date1 dob;
	int per;
	char city[10];
};

int rec_count=0;
struct dbase record[25];
void insert_rec();
void display_rec(int access,int rec_id);
void delete_rec(int rec_id);
void modify_rec();
void sort_rec();
int search_rec(int key);
void clearscreen();
int getkey(int,int*);

char far *scr=(char far*)0xB8000000;//This is the pointer to the first bit of CGA video memory

int tabs[6]={-8,-9,-20,-11,-15,-12};

void main()
{
	int choice,sr,id;

	while(1)
	{
		clearscreen();
		printf("Database+\nMENU:\n");
		printf("1. Display\n");
		printf("2. Insert\n");
		printf("3. Delete\n");
		printf("4. Modify\n");
		printf("5. Search\n");
		printf("6. Sort\n");
		printf("0. Exit\n");
		printf("Your choice: ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				display_rec(1,1);
				break;

			case 2:
				insert_rec();
				break;

			case 3:
				delete_rec(1);
				break;

			case 4:
				modify_rec();
				break;

			case 5:
				clearscreen();
				printf("Enter the roll number to search: ");
				scanf("%d",&sr);
				id=search_rec(sr);
				if(id==-1)
					printf("Record not found!");
				else
					display_rec(1,id);
				break;

			case 6:
				sort_rec();
				display_rec(1,1);
				break;

			case 0:
				exit(0);

			default:
				printf("Invalid key!");
		}
		getch();
	}
}

void insert_rec()
{
	int i,j,xc,yc,k,l;

	display_rec(0,0);
	j=rec_count;
	for(i=1;i<=80;i++)
	{
		gotoxy(i,j+2);
		printf("%c",0);
	}

	xc=1;
	gotoxy(xc,j+2);
	printf("%d",j+1);
	xc-=tabs[0];
	gotoxy(xc,j+2);
	printf("³");
	xc-=tabs[1]-1;
	gotoxy(xc,j+2);
	printf("³");
	xc-=tabs[2]-1;
	gotoxy(xc,j+2);
	printf("³");
	printf("  /  /");
	xc-=tabs[3]-1;
	gotoxy(xc,j+2);
	printf("³");
	xc-=tabs[4]-1;
	gotoxy(xc,j+2);
	printf("³");
	k=0;
	l=0;
	l+=tabs[k]-1;
	for(i=1;i<=80;i++)
	{
		gotoxy(i,j+3);
		if(i==-l)
		{
			printf("Á");
			k++;
			l+=tabs[k]-1;
		}
		else
			printf("Ä");
	}

	xc=-tabs[0]+2;
	gotoxy(xc,j+2);
	scanf("%d",&record[j].roll);

	xc+=-tabs[1]+1;
	gotoxy(xc,j+2);
	scanf("%s",record[j].name);

	xc+=-tabs[2]+1;
	gotoxy(xc,j+2);
	scanf("%d",&record[j].dob.dd);
	gotoxy(xc+3,j+2);
	scanf("%d",&record[j].dob.mm);
	gotoxy(xc+6,j+2);
	scanf("%d",&record[j].dob.yy);

	xc+=-tabs[3]+1;
	gotoxy(xc,j+2);
	scanf("%d",&record[j].per);

	xc+=-tabs[4]+1;
	gotoxy(xc,j+2);
	scanf("%s",record[j].city);

	rec_count++;
}

void display_rec(int access,int rec_id)
{
	int i,j,xc,yc,k,l,r,key;
	char dob[15];
	char spec[6][20]={"Sr. No.",
			  "Roll No.",
			  "Name",
			  "DOB",
			  "Percentage",
			  "City"};
	char blank[10]="";
	clearscreen();

	for(i=1;i<159;i+=2)
	{
		*(scr+i)=112;
	}

	for(i=0;i<6;i++)
		printf("%*s³",tabs[i],spec[i]);

	for(j=0;j<rec_count;j++)
	{
		gotoxy(1,j+2);
		printf("%*d³",tabs[0],j+1);
		printf("%*d³",tabs[1],record[j].roll);
		printf("%*s³",tabs[2],record[j].name);
		sprintf(dob,"%d/%d/%d",record[j].dob.dd,record[j].dob.mm,record[j].dob.yy);
		printf("%*s³",tabs[3],dob);
		printf("%*d³",tabs[4],record[j].per);
		printf("%*s",tabs[5],record[j].city);
	}

	k=0;
	l=0;
	l+=tabs[k]-1;
	for(i=1;i<=80;i++)
	{
		gotoxy(i,j+2);
		if(i==-l)
		{
			printf("Á");
			k++;
			l+=tabs[k]-1;
		}
		else
			printf("Ä");
	}
	printf("\nKeys Allowed:");
	printf("\n:Up, :Down, ESC: Back to previous menu");

	if(access)
	{
		r=rec_id*160;
		for(i=1+r;i<159+r;i+=2)
		{
			*(scr+i)=63;
		}

		while(1)
		{
			key=getkey(63,&r);
			if(key==1)
				break;
		}
	}
}

void delete_rec(int rec_id)
{
	int i,j,r,key,rec;
	display_rec(0,1);

	r=rec_id*160;

	for(i=1+r;i<159+r;i+=2)
	{
		*(scr+i)=79;
	}
	printf("\nDELETE: Deletes current record");
	while(1)
	{
		key=getkey(79,&r);
		rec=r/160;
		if(key==1)
			break;
		else
		if(key==83)
		{
			for(i=rec-1;i<rec_count;i++)
			{
				record[i]=record[i+1];
			}
			if(rec==rec_count)
				rec--;
			rec_count--;
			delete_rec(rec);
		}
	}
}

void modify_rec()
{
	int i,r=160,rec,key,t=0,x=1,vbar=1,xc,xtemp,ytemp;
	display_rec(0,1);

	for(i=r+1;i<159+r;i+=2)
	{
		*(scr+i)=31;
	}

	printf("\nENTER: Modifies contents of current record");
	while(1)
	{
		vbar=1;
		t=0;
		x=1;
		vbar+=-tabs[t];
		key=getkey(31,&r);
		rec=r/160;
		if(key==1)
			break;
		else
		if(key==28)
		{
			for(i=r;i<158+r;i+=2)
			{
				if(x++==vbar)
				{
					*(scr+i)='³';
					if(t==2)
					{
						xtemp=x;
						ytemp=rec+1;
					}
					t++;
					vbar+=-tabs[t]+1;
				}
				else
					*(scr+i)=0;
				*(scr+i+1)=31;
			}
			gotoxy(xtemp,ytemp);
			printf("  /  /");

			xc=1;
			gotoxy(xc,rec+1);
			printf("%d",rec);

			xc+=-tabs[0]+1;
			gotoxy(xc,rec+1);
			scanf("%d",&record[rec-1].roll);

			xc+=-tabs[1]+1;
			gotoxy(xc,rec+1);
			scanf("%s",record[rec-1].name);

			xc+=-tabs[2]+1;
			gotoxy(xc,rec+1);
			scanf("%d",&record[rec-1].dob.dd);
			gotoxy(xc+3,rec+1);
			scanf("%d",&record[rec-1].dob.mm);
			gotoxy(xc+6,rec+1);
			scanf("%d",&record[rec-1].dob.yy);

			xc+=-tabs[3]+1;
			gotoxy(xc,rec+1);
			scanf("%d",&record[rec-1].per);

			xc+=-tabs[4]+1;
			gotoxy(xc,rec+1);
			scanf("%s",record[rec-1].city);
			gotoxy(1,rec_count+3);
		}
	}
}

int getkey(int color,int *l)
{
	int i,key;
	union REGS in,out;

	while(!kbhit());
	in.h.ah=0;
	int86(22,&in,&out);
	key=out.h.ah;

	for(i=1+*l;i<159+*l;i+=2)
	{
		*(scr+i)=color;
	}

	if((key==72)&&(*l!=160))
	{
		for(i=1+*l;i<159+*l;i+=2)
		{
			*(scr+i)=15;
		}
		*l-=160;
	}
	else
	if((key==80)&&((*l/160)!=rec_count))
	{
		for(i=1+*l;i<159+*l;i+=2)
		{
			*(scr+i)=15;
		}
		*l+=160;
	}
	else
		return key;

	for(i=1+*l;i<159+*l;i+=2)
	{
		*(scr+i)=color;
	}
}

void sort_rec()
{
	int i,j;
	struct dbase temp;
	for(i=0;i<rec_count;i++)
	{
		for(j=0;j<rec_count-1;j++)
		{
			if(record[j].roll>record[j+1].roll)
			{
				temp=record[j];
				record[j]=record[j+1];
				record[j+1]=temp;
			}
		}
	}
	clearscreen();
	printf("Press any key to view the list of sorted records...");
	getch();
}

int search_rec(int key)
{
	int i;
	for(i=0;i<=rec_count;i++)
	{
		if(record[i].roll==key)
			return(i+1);
	}
	return -1;
}

void clearscreen()
{
	int i;
	clrscr();
	for(i=1;i<4000;i+=2)
		*(scr+i)=15;
}

/****************************** OUTPUT ***************************
Database+
MENU:
1. Display
2. Insert
3. Delete
4. Modify
5. Search
6. Sort
0. Exit

Your choice: 1

Sr. No. ³Roll No. ³Name                ³DOB        ³Percentage     ³City
1       ³22       ³Anand               ³12/1/1992  ³70             ³Nashik
2       ³46       ³Manoj               ³22/5/1992  ³65             ³A'bad
3       ³14       ³Sanket              ³29/7/1992  ³60             ³Sangamner
4       ³4        ³Pratik              ³8/11/1992  ³60             ³Nasik
ÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄ

Keys Allowed:
:Up, :Down, ESC: Back to previous menu


Your choice: 2
<RECORD WILL BE ADDED TO THE END OF LIST>
Sr. No. ³Roll No. ³Name                ³DOB        ³Percentage     ³City
1       ³22       ³Anand               ³12/1/1992  ³70             ³Nashik
2       ³46       ³Manoj               ³22/5/1992  ³65             ³A'bad
3       ³14       ³Sanket              ³29/7/1992  ³60             ³Sangamner
4       ³4        ³Pratik              ³8/11/1992  ³60             ³Nasik
*5      ³3        ³Nitish              ³24/7/1992  ³50             ³Aurangabad
ÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄ
Keys Allowed:
:Up, :Down, ESC: Back to previous menu


Your choice: 3
<SELECT THE RECORD TO DELETE AND PRESS "DELETE" KEY>
Sr. No. ³Roll No. ³Name                ³DOB        ³Percentage     ³City
1       ³22       ³Anand               ³12/1/1992  ³70             ³Nashik
2       ³46       ³Manoj               ³22/5/1992  ³65             ³A'bad
*3      ³14       ³Sanket              ³29/7/1992  ³60             ³Sangamner
4       ³4        ³Pratik              ³8/11/1992  ³60             ³Nasik
5       ³3        ³Nitish              ³24/7/1992  ³50             ³Aurangabad
ÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄ

Keys Allowed:
:Up, :Down, ESC: Back to previous menu
DELETE: Deletes current record

Your choice: 4
<SELECT THE RECORD TO MODIFY AND PRESS "ENTER" KEY>
Sr. No. ³Roll No. ³Name                ³DOB        ³Percentage     ³City
1       ³22       ³Anand               ³12/1/1992  ³70             ³Nashik
2       ³46       ³Manoj               ³22/5/1992  ³65             ³A'bad
*3      ³11       ³Madhuvan            ³28/8 /1992 ³60             ³Nasik
4       ³4        ³Pratik              ³8/11/1992  ³60             ³Nasik
5       ³3        ³Nitish              ³24/7/1992  ³50             ³Aurangabad
ÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄ

Keys Allowed:
:Up, :Down, ESC: Back to previous menu
ENTER: Modifies contents of current record


Your choice: 5
Enter the roll number to search: 46
<POINTER WILL AUTOMETICALLY POINT TO THE DESIRED RECORD>

Sr. No. ³Roll No. ³Name                ³DOB        ³Percentage     ³City
1       ³22       ³Anand               ³12/1/1992  ³70             ³Nashik
2       ³46       ³Manoj               ³22/5/1992  ³65             ³A'bad
3       ³14       ³Sanket              ³29/7/1992  ³60             ³Sangamner
4       ³4        ³Pratik              ³8/11/1992  ³60             ³Nasik
5       ³3        ³Nitish              ³24/7/1992  ³50             ³Aurangabad
ÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄ

Keys Allowed:
:Up, :Down, ESC: Back to previous menu


Your choice: 5
Press any key to view the list of sorted records...

Sr. No. ³Roll No. ³Name                ³DOB        ³Percentage     ³City
1       ³3        ³Nitish              ³24/7/1992  ³50             ³Aurangabad
2       ³4        ³Pratik              ³8/11/1992  ³60             ³Nasik
3       ³14       ³Sanket              ³29/7/1992  ³60             ³Sangamner
4       ³22       ³Anand               ³12/1/1992  ³70             ³Nashik
5       ³46       ³Manoj               ³22/5/1992  ³65             ³A'bad
ÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄ

Keys Allowed:
:Up, :Down, ESC: Back to previous menu
*****************************************************************/