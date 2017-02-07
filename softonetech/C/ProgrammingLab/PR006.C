/* Programming Lab
Practical No. 6
Date 8 September 2011
Program to implement all the searching methods such as Sequential search,
Binary search, Fibonacci search
SE(B)			Roll No. 03 */

#include<stdio.h>
#include<conio.h>

int linsearch(int a[],int n,int key);
int binsearch(int a[],int n,int key);
int fibsearch(int a[],int key,int mid,int p,int q,int k);
void bubblesort(int a[],int n,int y[]);
int fib(int n);
void animate(int a[],int n,int y[]);

void main()
{
	int choice,i;
	int a[10];
	int key,n=0,result,flag=0;
	int y[20],yc=11;
	int mid,p,q,k;
	bubblesort(a,n,y);
	while(1)
	{
		clrscr();
		if(flag) //Display numbers everytime at the right side of screen
		{
			for(i=1;i<n+1;i++)
			{
				gotoxy(70,i);
				printf("%d",a[i-1]);
			}
		}
		gotoxy(1,1);
		printf("MENU:\n");
		printf("1. Input Elements\n");
		printf("2. Linear Search\n");
		printf("3. Binary Search\n");
		printf("4. Fibonacci Search\n");
		printf("0. Exit\n");
		printf("Your choice: ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:	//Input Elements
				printf("Enter number of elements: ");
				scanf("%d",&n);
				printf("\nEnter elements one by one:\n");
				for(i=0;i<n;i++)
				{
					scanf("%d",&a[i]);
					y[i]=yc++;
				}
				bubblesort(a,n,y);
				animate(a,n,y);
				flag=1;
				break;

			case 2: //Linear Search
				printf("Enter element to search: ");
				scanf("%d",&key);
				result=linsearch(a,n,key);
				if(result!=-1)
					printf("Element found at location %d",result);
				else
					printf("Element not found!");
				break;

			case 3: //Binary Search
				printf("Enter element to search: ");
				scanf("%d",&key);
				result=binsearch(a,n,key);
				if(result!=-1)
					printf("Element found at location %d",result);
				else
					printf("Element not found!");
				break;

			case 4: //Fibonacci Search
				printf("Enter element to search: ");
				scanf("%d",&key);
				for(k=1;fib(k)<=n;k++);
				mid=n-fib(k-2)+1;
				p=fib(k-2);
				q=fib(k-3);
				result=fibsearch(a,key,mid,p,q,k);
				if(result!=-1)
					printf("Element found at location %d",result);
				else
					printf("Element not found!");
				break;

			case 0:
				exit(0);

			default:
				printf("Invalid choice!");
		}
		getch();
	}
}

int linsearch(int a[],int n,int key)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(a[i]==key)
			return(i+1);
	}
	return(-1);
}

int binsearch(int a[],int n,int key)
{
	int i,j,pivot;
	i=0;
	j=n-1;
	pivot=(i+j)/2;
	printf("pivot=%d, i=%d, j=%d\n",pivot,i,j);
	while(i<=j)
	{
		if(key<a[pivot])
		{
			j=pivot-1;
			pivot=(i+j)/2;
		}

		if(key>a[pivot])
		{
			i=pivot+1;
			pivot=(i+j)/2;
		}

		if(a[pivot]==key)
		{
			return(pivot+1);
		}
		printf("pivot=%d, i=%d, j=%d\n",pivot,i,j);
	}
	return(-1);
}

int fibsearch(int a[],int key,int mid,int p,int q,int k)
{
	int temp;

	if(a[mid]==key)
		return mid;

	printf("mid=%d p=%d q=%d\n",mid,p,q);
	while(1)
	{
		if(key<a[mid-1])
		{
			if(q==0)
				break;
			mid=mid-q;
			temp=p-q;
			p=q;
			q=temp;
		}
		else
		if(key>a[mid-1])
		{
			if(p==1)
				break;
			mid=mid+q;
			p=p-q;
			q=q-p;
		}

		printf("mid=%d p=%d q=%d\n",mid,p,q);

		if(key==a[mid-1])
			return(mid);
	}
	return(-1);
}

void bubblesort(int a[],int n,int y[])
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(a[j]>a[j+1])
			{	//XOR method for exchanging values of two variables
				a[j]=a[j]^a[j+1];
				a[j+1]=a[j]^a[j+1];
				a[j]=a[j]^a[j+1];

				y[j]=y[j]^y[j+1];
				y[j+1]=y[j]^y[j+1];
				y[j]=y[j]^y[j+1];
			}
		}
	}
}

int fib(int n)
{
	if(n==0)
		return 0;
	if(n==1)
		return 1;
	return(fib(n-1)+fib(n-2));
}

void animate(int a[],int n,int y[])//The function will animate the list while sorting
{
	int xc,yc,i;

	for(i=0;i<n;i++)
	{
		xc=2;
		while(xc<=70)
		{
			gotoxy(xc++,y[i]);
			printf("\b%c%d",0,a[i]);
			delay(15);
		}

		yc=y[i];
		while(yc>=i+1)
		{
			gotoxy(70,yc);
			printf("%d",a[i]);
			gotoxy(75,yc);
			delay(15);
			if(yc!=i+1)
				printf("\b\b\b\b\b\b%c%c%c%c%c%c",0,0,0,0,0,0);
			yc--;
		}
	}
	gotoxy(1,12);
}

/******************* OUTPUT *****************
MENU:
1. Input Elements
2. Linear Search
3. Binary Search
4. Fibonacci Search
0. Exit
Your choice: 1
Enter number of elements: 10

Enter elements one by one:
11
21
25
2
6
5
18
20
17
3

MENU:                                                                2
1. Input Elements                                                    3
2. Linear Search                                                     5
3. Binary Search                                                     6
4. Fibonacci Search                                                  11
0. Exit                                                              17
Your choice: 2                                                       18
Enter element to search: 17                                          20
Element found at location 6                                          21

Your choice: 3
Enter element to search: 6
pivot=4, i=0, j=9
pivot=2, i=2, j=3
Element found at location 4

Your choice: 4
Enter element to search: 25
mid=6 p=5 q=3
mid=9 p=2 q=1
mid=10 p=1 q=0
Element found at location 10
*********************************************/