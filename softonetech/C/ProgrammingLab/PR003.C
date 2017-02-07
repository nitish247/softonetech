/*Programming Lab
Practical No. 3
Date 1 August 2011
Program to perform Matrix operations such as addition, substraction,
multiplication, inverse, skew-symmetric, transpose, determinant
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>

void readmatrix(int m[5][5],int,int,int,int);
void dispmatrix(int m[5][5],int,int,int,int);
int addmatrix(int ma[5][5],int m1[5][5],int m2[5][5]);
int submatrix(int ma[5][5],int m1[5][5],int m2[5][5]);
int mulmatrix(int ma[5][5],int m1[5][5],int m2[5][5],int*,int*);
int transpose(int ma[5][5],int m1[5][5],int,int);
int inv(int ma[5][5],int m1[5][5],int,int);
int issymmetric(int ma[5][5],int,int);
int isskewsymmetric(int ma[5][5],int,int);
int det(int ma[5][5],int,int);
void minor(int d[5][5],int ma[5][5],int,int);
int row1,col1,row2,col2;

void main()
{
	int mat1[5][5],mat2[5][5],mat0[5][5],matx[5][5],flag=0,flag_1,choice,cm,rm,dt;
	clrscr();

	while(1)
	{

		clrscr();

		if(flag==1)
		{
			dispmatrix(mat1,row1,col1,50,2);
			dispmatrix(mat2,row2,col2,50,2+row1+2);
		}

		gotoxy(1,1);
		printf("MENU:\n");
		printf("1. Input Matrices");
		printf("\n2. Perform Addition");
		printf("\n3. Perform Substraction");
		printf("\n4. Perform Multiplication");
		printf("\n5. Transpose");
		printf("\n6. Inverse");
		printf("\n7. Is Symmetric?");
		printf("\n8. Is Skew-symmetric?");
		printf("\n9. Find Determinant");
		printf("\n0. Exit");
		printf("\nYour choice: ");
		scanf("%d",&choice);


		switch(choice)
		{
			case 1:		//Inputs the matrices 1 & 2
				gotoxy(1,13);
				printf("\nPlease specify rows and columns: ");
				scanf("%d%d",&row1,&col1);
				readmatrix(mat1,row1,col1,50,2);

				gotoxy(1,14);
				printf("\nPlease specify rows and columns: ");
				scanf("%d%d",&row2,&col2);
				readmatrix(mat2,row2,col2,50,2+row1+2);

				flag=1;
				break;

			case 2:		//Adds matrices
				flag_1=addmatrix(mat0,mat1,mat2);
				printf("\nAddition of matrices: ");
				if(flag_1)
					dispmatrix(mat0,row1,col1,5,16);
				break;

			case 3:		//Substracts matrices
				flag_1=submatrix(mat0,mat1,mat2);
				printf("\nSubstraction of matrices: ");
				if(flag_1)
					dispmatrix(mat0,row1,col1,5,16);
				break;

			case 4:		//Multiplies matrices
				flag_1=mulmatrix(mat0,mat1,mat2,&cm,&rm);
				printf("\nMultiplication of matrices: ");
				if(flag_1)
					dispmatrix(mat0,rm,cm,5,16);
				break;

			case 5:		//Finds transpose of matrix
				flag_1=transpose(mat0,mat1,row1,col1);
				if(flag_1)
				{
					printf("\nTranspose of matrix: ");
					dispmatrix(mat0,col1,row1,5,16);
				}
				break;

			case 6:		//Finds inverse of matrix
				flag_1=inv(mat0,mat1,row1,col1);
				if(flag_1)
				{
					printf("\nInverse of matrix: ");
					dispmatrix(mat0,row1,col1,5,16);
				}
				break;

			case 7:		//Checks whether matrix is symmetric or not
				if(issymmetric(mat1,row1,col1))
					printf("\nMatrix is symmetric.");
				else
					printf("\nMatrix is not symmetric.");
				break;

			case 8:		//Checks whether matrix is skew-symmetric or not
				if(isskewsymmetric(mat1,row1,col1))

					printf("\nMatrix is skew-symmetric.");
				else
					printf("\nMatrix is not skew-symmetric.");
				break;

			case 9:		//Finds determinant of matrix
				dt=det(mat1,row1,col1);
				printf("\nDeterminant of Matrix = %d",dt);
				break;

			case 0:		//Exits from program
				exit(0);
				break;

			default:	//Default choice (invalid)
				printf("Invalid choice!");
				break;

		}
		getch();
	}
}

//Following function is well designed to provide user a fine interface for matrix access
void readmatrix(int m[5][5],int r,int c,int xc,int yc)
{
	int i,j,x,y,p;

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
	for(i=0;i<r;i++)
	{
		x=p;
		for(j=0;j<c;j++)
		{
			gotoxy(x,y);
			scanf("%d",&m[i][j]);
			x+=4;
		}
		y++;
	}
}

void dispmatrix(int m[5][5],int r,int c,int xc,int yc)
{
	int i,j,x,y,p;

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
	for(i=0;i<r;i++)
	{
		x=p;
		for(j=0;j<c;j++)
		{
			gotoxy(x,y);
			printf("%d",m[i][j]);
			x+=4;
		}
		y++;
	}
}

int addmatrix(int ma[5][5],int m1[5][5],int m2[5][5])
{
	int i,j;
	if((row1!=row2)||(col1!=col2))
	{
		printf("Row or column number mismatch.");
		return 0;
	}
	else
	{

		for(i=0;i<row1;i++)
		{
			for(j=0;j<col1;j++)
			{
				ma[i][j]=m1[i][j]+m2[i][j];
			}
		}
		return 1;
	}
}

int submatrix(int ma[5][5],int m1[5][5],int m2[5][5])
{
	int i,j;
	if((row1!=row2)||(col1!=col2))
	{
		printf("Row or column number mismatch.");
		return 0;
	}
	else
	{

		for(i=0;i<row1;i++)
		{
			for(j=0;j<col1;j++)
			{
				ma[i][j]=m1[i][j]-m2[i][j];
			}
		}
		return 1;
	}
}

int mulmatrix(int mat0[5][5],int mat1[5][5],int mat2[5][5],int *colm,int *rowm)
{
	int i,j,k,s;
	if(row1!=col2)
	{
		printf("Row or column number mismatch.");
		return 0;
	}
	else
	{
		for(i=0;i<row1;i++)
		{
			for(j=0;j<col1;j++)
			{
				s=0;
				for(k=0;k<row2;k++)
					s+=mat1[i][k]*mat2[k][j];
				mat0[i][j]=s;
			}
		}
		*rowm=row1;
		*colm=col1;
		return 1;
	}
}

int transpose(int ma[5][5],int m1[5][5],int r,int c)
{
	int i,j,temp;

	if(r==c)
	{
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				ma[i][j]=m1[j][i];
			}
			if(i==j)
				break;
		}
		return 1;
	}
	else
	{
		return 0;
	}
}

int issymmetric(int ma[5][5],int r,int c)
{
	int mt[5][5],i,j,flag_1;

	flag_1=transpose(mt,ma,r,c);
	if(flag_1)
	{
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				if(ma[i][j]!=mt[i][j])
					return 0;
			}
		}
		return 1;
	}
	else
		return 0;
}

int isskewsymmetric(int ma[5][5],int r,int c)
{
	int mt[5][5],i,j,flag_1;

	flag_1=transpose(mt,ma,r,c);
	if(flag_1)
	{
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				if(j!=i)
				{
					if(ma[i][j]!=(-mt[i][j]))
					return 0;
				}
			}
		}
		return 1;
	}
	else
		return 0;
}

int det(int ma[5][5],int r,int c)
{
	int d,i,j;
	int d1[5][5],d2[5][5],d3[5][5];
	if(r!=c)
		return 0;
	else
	{
		if(r==2)
		{
			d=(ma[0][0]*ma[1][1])-(ma[0][1]*ma[1][0]);
			return d;
		}
		else
		if(r==3)
		{
			minor(d1,ma,0,0);
			minor(d2,ma,0,1);
			minor(d3,ma,0,2);
			d=(ma[0][0]*det(d1,2,2))-(ma[0][1]*det(d2,2,2))+(ma[0][2]*det(d3,2,2));
			return d;
		}
		return 0;
	}
}

int inv(int ma[5][5],int m1[5][5],int r,int c)
{
	//Implementation of adjoint method to compute inverse of matrix
	int dt,d[5][5],cof[5][5],cofdash[5][5],mb[5][5],i,j,in;
	dt=det(m1,3,3);
	if(dt==0)
	{
		printf("Matrix non-invertible.");
		return 0;
	}
	else
	{
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				minor(d,m1,i,j);
				cof[i][j]=pow(-1,i+j)*det(d,2,2);
			}
		}
		transpose(cofdash,cof,3,3);
		dt=det(cofdash,3,3);
		in=(1/dt);
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				ma[i][j]=in*cofdash[i][j];
			}
		}
		return 1;
	}
}

void minor(int d[5][5],int ma[5][5],int r,int c)
{
	int i=0,j=0,k=0,l=0;
	while(i<3)
	{
		if(i==r)
		{
			i++;
			continue;
		}
		j=0;
		l=0;
		while(j<3)
		{
			if(j==c)
			{
				j++;
				continue;
			}
			d[k][l]=ma[i][j];
			l++;
			j++;
		}
		i++;
		k++;
	}
}

/*****************************OUTPUT******************************
MENU:                                  Ú             ¿
1. Input Matrices                      ³ 3   -3  4   ³
2. Perform Addition                    ³ 2   -3  4   ³
3. Perform Substraction                ³ 0   -1  1   ³
4. Perform Multiplication              À             Ù
5. Transpose                           Ú             ¿
6. Inverse                             ³ 1   2   3   ³
7. Is Symmetric?                       ³ 4   5   6   ³
8. Is Skew-symmetric?                  ³ 7   8   9   ³
9. Find Determinant                    À             Ù
0. Exit
Your choice: 1
Please specify rows and columns: 3 3
Please specify rows and columns: 3 3

Your choice: 2

Addition of matrices:
    Ú             ¿
    ³ 4   -1  7   ³
    ³ 6   2   10  ³
    ³ 7   7   10  ³
    À             Ù

Your choice: 3

Substraction of matrices:
    Ú             ¿
    ³ 2   -5  1   ³
    ³ -2  -8  -2  ³
    ³ -7  -9  -8  ³
    À             Ù

Your choice: 4
                                                                                
Multiplication of matrices:                                                     
    Ú             ¿                                                             
    ³ 19  23  27  ³                                                             
    ³ 18  21  24  ³                                                             
    ³ 3   3   3   ³                                                             
    À             Ù

Your choice: 5

Transpose of matrix:                                                            
    Ú             ¿
    ³ 3   2   0   ³                                                             
    ³ -3  -3  -1  ³                                                             
    ³ 4   4   1   ³
    À             Ù

Your choice: 6

Inverse of matrix:
    Ú             ¿
    ³ 1   -1  0   ³
    ³ -2  3   -4  ³
    ³ -2  3   -3  ³
    À             Ù


Your choice: 9

Determinant of Matrix = 1


Your choice: 1

Please specify rows and columns: 3 3

Ú             ¿
³ 1   5   8   ³
³ 5   1   3   ³
³ 8   3   1   ³
À             Ù

Your choice: 7

Matrix is symmetric.


Your choice: 1
Please specify rows and columns: 3 3

Ú             ¿
³ 1   5   8   ³
³ -5  1   3   ³
³ -8  -3  1   ³
À             Ù

Your choice: 7

Matrix is skew-symmetric.

*/