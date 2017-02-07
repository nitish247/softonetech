/*Programming Lab
Practical No. 4
Title: Program to perform various set operations such as union, intersection,
difference, symmetric difference etc.
*/

#include<stdio.h>
#include<conio.h>
#define MAX 10
#define MAX2 20

void readset(int [MAX],int,int,int);
void printset(int [MAX],int,int,int);
int digitsof(int);
void set_union(int [MAX2],int [MAX],int [MAX],int,int,int*);
void set_intersection(int [MAX2],int [MAX],int [MAX],int,int,int*);
void set_diff(int [MAX2],int [MAX],int [MAX],int,int,int*);
void set_symdiff(int [MAX2],int [MAX],int [MAX],int,int,int*);

void main()
{
	int set1[MAX],set2[MAX],set0[MAX2],flag=0;
	int choice;
	int size1=0,size2=0,size0;
	while(1)
	{
		clrscr();
		if(flag)
		{
			printset(set1,size1,35,2);
			printset(set2,size2,35,3);
		}
		gotoxy(1,1);
		printf("MENU:");
		printf("\n1. Input Sets");
		printf("\n2. Perform Union");
		printf("\n3. Perform Intersection");
		printf("\n4. Difference (A-B)");
		printf("\n5. Difference (B-A)");
		printf("\n6. Symmetric Difference");
		printf("\n0. Exit");
		printf("\nYour choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:	//Inputs contents of sets
				gotoxy(1,10);
				printf("\nEnter size of Set A: ");
				scanf("%d",&size1);
				readset(set1,size1,35,2);
				gotoxy(1,11);
				printf("\nEnter size of Set B: ");
				scanf("%d",&size2);
				readset(set2,size2,35,3);
				flag=1;
				break;

			case 2: //Peforms union of sets
				set_union(set0,set1,set2,size1,size2,&size0);
				gotoxy(1,10);
				printf("Union of Sets:");
				printset(set0,size0,3,11);
				break;

			case 3: //Performs intersection of sets
				set_intersection(set0,set1,set2,size1,size2,&size0);
				gotoxy(1,10);
				printf("Intersection of Sets:");
				printset(set0,size0,3,11);
				break;

			case 4: //Finds difference of sets (A-B)
				set_diff(set0,set1,set2,size1,size2,&size0);
				gotoxy(1,10);
				printf("Difference of Sets (A-B):");
				printset(set0,size0,3,11);
				break;

			case 5: //Finds difference of sets (B-A)
				set_diff(set0,set2,set1,size2,size1,&size0);
				gotoxy(1,10);
				printf("Difference of Sets (B-A):");
				printset(set0,size0,3,11);
				break;

			case 6: //Finds symmetric difference of sets (A-B) union (B-A)
				set_symdiff(set0,set1,set2,size1,size2,&size0);
				gotoxy(1,10);
				printf("Symmetric Difference of Sets (A-B) union (B-A):");
				printset(set0,size0,3,11);
				break;

			case 0: //Exits from program
				exit(0);
				break;

			default: //Default case
				printf("Invalid choice!");
		}
		getch();
	}
}

void readset(int s[MAX],int size,int x,int y)
{
	int i,j;
	gotoxy(x-2,y);
	printf("{ ");

	for(i=0;i<size;i++)
	{
		gotoxy(x,y);
		scanf("%d",&s[i]);
		gotoxy(x+digitsof(s[i]),y);
		printf(", ");
		x+=digitsof(s[i])+2;
	}
	printf("\b\b }");
}

void printset(int s[MAX],int size,int x,int y)
{
	int i,j;
	gotoxy(x-2,y);
	textcolor(WHITE);
	cprintf("{ ");

	for(i=0;i<size;i++)
	{
		textcolor(i+1);
		gotoxy(x,y);
		cprintf("%d",s[i]);
		gotoxy(x+digitsof(s[i]),y);
		cprintf(", ");
		x+=digitsof(s[i])+2;
	}
	textcolor(WHITE);
	cprintf("\b\b }");
}

int digitsof(int n)
{
	int c=0;
	if(n==0)
		return 1;

	while(n!=0)
	{
		n=n/10;
		c++;
	}
	return c;
}

void set_union(int su[MAX2],int s1[MAX],int s2[MAX],int size1,int size2,int *szu)
{
	int i,j,k,flag;
	for(i=0;i<size1;i++)
	{
		su[i]=s1[i];
	}
	k=i;
	flag=0;
	for(j=0;j<size2;j++)
	{
		flag=0;
		for(i=0;i<size1;i++)
		{
			if(s2[j]==s1[i])
			{
				flag=1;
				break;
			}
		}
		if(!flag)
		{
			su[k]=s2[j];
			k++;
		}
	}
	*szu=k;
}

void set_intersection(int su[MAX2],int s1[MAX],int s2[MAX],int size1,int size2,int *szu)
{
	int i,j,k=0,flag;
	flag=0;
	for(i=0;i<size1;i++)
	{
		flag=1;
		for(j=0;j<size2;j++)
		{
			if(s1[i]==s2[j])
			{
				flag=0;
				break;
			}
		}
		if(!flag)
		{
			su[k]=s1[i];
			k++;
		}
	}
	*szu=k;
}

void set_diff(int su[MAX2],int s1[MAX],int s2[MAX],int size1,int size2,int *szu)
{
	int i,j,k=0,flag;
	flag=0;
	for(i=0;i<size1;i++)
	{
		flag=0;
		for(j=0;j<size2;j++)
		{
			if(s1[i]==s2[j])
			{
				flag=1;
				break;
			}
		}
		if(!flag)
		{
			su[k]=s1[i];
			k++;
		}
	}
	*szu=k;
}

void set_symdiff(int su[MAX2],int s1[MAX],int s2[MAX],int size1,int size2,int *szu)
{
	 int s3[MAX],s4[MAX],sz3,sz4,sz;
	 set_diff(s3,s1,s2,size1,size2,&sz3);
	 set_diff(s4,s2,s1,size2,size1,&sz4);
	 set_union(su,s3,s4,sz3,sz4,&sz);
	 *szu=sz;
}

/******************************OUTPUT*********************************
MENU:
1. Input Sets                   { 1, 2, 3, 4, 5 }
2. Perform Union                { 1, 12, 15, 3, 20, 25, 5, 24 }
3. Perform Intersection
4. Difference (A-B)
5. Difference (B-A)
6. Symmetric Difference
0. Exit
Your choice: 1

Enter size of Set A: 5
Enter size of Set B: 8


MENU:
1. Input Sets                   { 1, 2, 3, 4, 5 }
2. Perform Union                { 1, 12, 15, 3, 20, 25, 5, 24 }
3. Perform Intersection
4. Difference (A-B)
5. Difference (B-A)
6. Symmetric Difference
0. Exit
Your choice: 2
Union of Sets:
{ 1, 2, 3, 4, 5, 12, 15, 20, 25, 24 }


Your choice: 3
Intersection of Sets:
{ 1, 3, 5 }


Your choice: 4
Difference of Sets (A-B):
{ 2, 4 }


Your choice: 5
Difference of Sets (B-A):
{ 12, 15, 20, 25, 24 }


Your choice: 6
Symmetric Difference of Sets (A-B) union (B-A):
{ 2, 4, 12, 15, 20, 25, 24 }
*/