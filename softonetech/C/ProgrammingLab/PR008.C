/* Programming Lab
Practical No. 8
Date 22 September 2011
Program to represent sparse matrix using array and perform addition,
simple transpose and fast transpose
SE(B)			Roll No. 03 */


#include<stdio.h>
#include<conio.h>
#define MAX 20

void readmatrix(int mat[MAX][3],int xc,int yc);
void dispmatrix(int mat[MAX][3],int xc,int yc);
void addsparse(int add[MAX][3],int sp1[MAX][3],int sp2[MAX][3]);
void transpose(int trans[MAX][3],int spr[MAX][3]);
void fast_transpose(int trans[MAX][3],int spr[MAX][3]);

void main()
{
	int spr1[MAX][3],spr2[MAX][3],spr0[MAX][3],n,flag=0,choice,i;

	while(1)
	{
		clrscr();
		if(flag)	//Displays matrices everytime at the right side of screen
		{
			dispmatrix(spr1,55,2);
			dispmatrix(spr2,55,2+spr1[0][0]+3);
		}
		gotoxy(1,1);
		printf("MENU:\n");
		printf("1. Input Matrices\n");
		printf("2. Perform Addition\n");
		printf("3. Simple Transpose\n");
		printf("4. Fast Transpose\n");
		printf("0. Exit\n");
		printf("Your choice: ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:	//Inputs sparse matrices
				printf("\nSpecify diamensions of matrix 1: ");
				scanf("%d%d",&spr1[0][0],&spr1[0][1]);
				readmatrix(spr1,55,2);
				gotoxy(1,10);
				printf("\nSpecify diamensions of matrix 1: ");
				scanf("%d%d",&spr2[0][0],&spr2[0][1]);
				readmatrix(spr2,55,2+spr1[0][0]+3);
				flag=1;
				break;

			case 2:	//Adds elements two sparse matrices
				printf("\nAddition of Matrices: ");
				addsparse(spr0,spr1,spr2);
				dispmatrix(spr0,2,12);
				break;

			case 3:	//Computes and displays simple transpose of first sparse matrix
				printf("\nSimple Transpose: ");
				transpose(spr0,spr1);
				dispmatrix(spr0,2,12);
				break;

			case 4: //Computes and displays fast transpose of first sparse matrix
				printf("\nFast Transpose: ");
				fast_transpose(spr0,spr1);
				dispmatrix(spr0,2,12);
				break;

			case 0:	//Quit
				exit(0);

			default:
				printf("Invalid choice!");
				break;

		}
		getch();
	}
}

void readmatrix(int mat[MAX][3],int xc,int yc)
{
	int i,j,x,y,p,m,element,index;
	int r=mat[0][0],c=mat[0][1];

	gotoxy(xc,yc-1);
	putch(218);
	for(i=yc;i<=r+(yc-2)+1;i++)
	{
		gotoxy(xc,i);
		putch(179);
	}

	gotoxy(xc,i);
	putch(192);

	x=xc+(4*c);
	x+=2;
	gotoxy(x,yc-1);
	putch(191);
	for(i=yc;i<=r+(yc-2)+1;i++)
	{
		gotoxy(x,i);
		putch(179);
	}
	gotoxy(x,i);
	putch(217);

	p=xc+2;
	y=yc;
	index=1;
	for(i=0;i<r;i++)
	{
		x=p;
		for(j=0;j<c;j++)
		{
			gotoxy(x,y);
			scanf("%d",&element);
			if(element!=0)		//Main code;
			{
				mat[index][0]=i;
				mat[index][1]=j;
				mat[index][2]=element;
				index++;
			}
			x+=4;
		}
		y++;
	}
	mat[0][2]=--index;
}

void dispmatrix(int mat[MAX][3],int xc,int yc)
{
	int i,j,x,y,p,index;
	int r=mat[0][0],c=mat[0][1];

	gotoxy(xc,yc-1);
	putch(218);// Ú
	for(i=yc;i<=r+(yc-2)+1;i++)
	{
		gotoxy(xc,i);
		putch(179); //³
	}

	gotoxy(xc,i);
	putch(192); //À

	x=xc+(4*c);
	x+=2;
	gotoxy(x,yc-1);
	putch(191); //¿
	for(i=yc;i<=r+(yc-2)+1;i++)
	{
		gotoxy(x,i);
		putch(179); //³
	}
	gotoxy(x,i);
	putch(217); //Ù

	p=xc+2;
	y=yc;

	index=1;
	for(i=0;i<r;i++)
	{
		x=p;
		for(j=0;j<c;j++)
		{
			gotoxy(x,y);
			if(i==mat[index][0]&&j==mat[index][1])
			{
				printf("%d",mat[index][2]);
				index++;
			}
			else
				printf("0");
			x+=4;
		}
		y++;
	}
}

void addsparse(int add[MAX][3],int sp1[MAX][3],int sp2[MAX][3])
{
	int i,j,k,r,c;
	add[0][0]=sp1[0][0];
	add[0][1]=sp1[0][1];
	i=j=k=1;

	while(i<=sp1[0][2]&&j<=sp2[0][2])
	{
		if(sp1[i][0]<sp2[j][0])
		{
			add[k][0]=sp1[i][0];
			add[k][1]=sp1[i][1];
			add[k][2]=sp1[i][2];
			i++;
			k++;
			continue;
		}

		if(sp2[j][0]<sp1[i][0])
		{
			add[k][0]=sp2[j][0];
			add[k][1]=sp2[j][1];
			add[k][2]=sp2[j][2];
			j++;
			k++;
			continue;
		}

		if(sp1[i][1]<sp2[j][1])
		{
			add[k][0]=sp1[i][0];
			add[k][1]=sp1[i][1];
			add[k][2]=sp1[i][2];
			i++;
			k++;
			continue;
		}

		if(sp2[j][1]<sp1[i][1])
		{
			add[k][0]=sp2[j][0];
			add[k][1]=sp2[j][1];
			add[k][2]=sp2[j][2];
			j++;
			k++;
			continue;
		}

		add[k][0]=sp1[i][0];
		add[k][1]=sp1[i][1];
		add[k][2]=sp1[i][2]+sp2[j][2];
		k++;
		i++;
		j++;
	}

	while(i<=sp1[i][2])
	{
		add[k][0]=sp1[i][0];
		add[k][1]=sp1[i][1];
		add[k][2]=sp1[i][2];
		i++;
		k++;
	}

	while(j<=sp2[j][2])
	{
		add[k][0]=sp2[j][0];
		add[k][1]=sp2[j][1];
		add[k][2]=sp2[j][2];
		j++;
		k++;
	}

	add[0][2]=k--;
}

void transpose(int trans[MAX][3],int spr[MAX][3])
{
	int i,j,k;
	trans[0][0]=spr[0][0];
	trans[0][1]=spr[0][0];
	trans[0][2]=spr[0][1];
	k=1;
	for(i=0;i<spr[0][1];i++)
		for(j=1;j<=spr[0][2];j++)
			if(i==spr[j][1])
			{
				trans[k][0]=i;
				trans[k][1]=spr[j][0];
				trans[k][2]=spr[j][2];
				k++;
			}
}

//*** Newer method
void fast_transpose(int trans[MAX][3],int spr[MAX][3])
{
	int i,m,n,t,col_num,location;
	int total[MAX],index[MAX];
	m=spr[0][0];
	n=spr[0][1];
	t=spr[0][2];

	trans[0][0]=m;
	trans[0][1]=n;
	trans[0][2]=t;

	for(i=0;i<n;i++)
		total[i]=0;

	for(i=1;i<=t;i++)
	{
		col_num=spr[i][1];
		total[col_num]++;
	}

	index[0]=1;
	for(i=1;i<n;i++)
		index[i]=index[i-1]+total[i-1];

	for(i=1;i<=t;i++)
	{
		col_num=spr[i][1];
		location=index[col_num];
		index[col_num]++;
		trans[location][0]=spr[i][1];
		trans[location][1]=spr[i][0];
		trans[location][2]=spr[i][2];
	}
}

/************************* OUTPUT *************************
MENU:                               Ú             ¿
1. Input Matrices                   ³ 0   5   0   ³
2. Perform Addition                 ³ 4   0   0   ³
3. Simple Transpose                 ³ 0   0   3   ³
4. Fast Transpose                   À             Ù
0. Exit
Your choice: 1                      Ú             ¿
				    ³ 1   0   0   ³
				    ³ 5   0   9   ³
				    ³ 7   0   0   ³
				    À             Ù


Specify diamensions of matrix 1: 3 3
Specify diamensions of matrix 2: 3 3


Your choice: 2

Addition of Matrices:

 Ú             ¿
 ³ 1   5   0   ³
 ³ 9   0   9   ³
 ³ 7   0   3   ³
 À             Ù


Your choice: 3

Simple Transpose:
 Ú             ¿
 ³ 0   4   0   ³
 ³ 5   0   0   ³
 ³ 0   0   3   ³
 À             Ù


Your choice: 4

Fast Transpose:

 Ú             ¿
 ³ 0   4   0   ³
 ³ 5   0   0   ³
 ³ 0   0   3   ³
 À             Ù
**********************************************************/