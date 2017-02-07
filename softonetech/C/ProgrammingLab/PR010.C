/*Programming Lab
Practical No. 10
Date 3 October 2011
Program to implement recursive sorting algorithms such as Quicksort and
Merge Sort
SE(B)			Roll No. 03 */


#include<stdio.h>
#include<conio.h>

void quicksort(int a[],int lower,int upper);
void mergesort(int a[],int lower,int upper);
int partition(int a[],int lower, int upper);
void merge(int a[],int lower,int mid,int upper);

void main()
{
	int arr[20],i,choice,n;
	clrscr();
	while(1)
	{
		clrscr();
		printf("MENU:\n");
		printf("1. Input Numbers\n");
		printf("2. Quick Sort\n");
		printf("3. Merge Sort\n");
		printf("0. Quit\n");
		printf("Your choice: ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				printf("Enter the number of elements: ");
				scanf("%d",&n);
				printf("Enter the elements one by one:\n");
				for(i=0;i<n;i++)
					scanf("%d",&arr[i]);
				break;

			case 2:
				quicksort(arr,0,n-1);
				printf("\nSorted List after Quicksort:\n");
				for(i=0;i<n;i++)
					printf("%d ",arr[i]);
				break;
			case 3:
				mergesort(arr,0,n-1);
				printf("\nSorted List after Merge Sort:\n");
				for(i=0;i<n;i++)
					printf("%d ",arr[i]);
				break;

			case 0:
				exit(0);

			default:
				printf("Invalid choice!");
		}
		if(choice!=1)
		exit(0);
	}
}

void quicksort(int a[],int lower,int upper)
{
	int j;
	if(lower<upper)
	{
		j=partition(a,lower,upper);
		quicksort(a,lower,j-1);
		quicksort(a,j+1,upper);
	}
}

void mergesort(int a[],int lower,int upper)
{
	int mid;
	if(lower<upper)
	{
		mid=(lower+upper)/2;
		mergesort(a,lower,mid);
		mergesort(a,mid+1,upper);
		merge(a,lower,mid,upper);
	}
}

int partition(int a[],int lower,int upper)
{
	int v,i,j;
	v=a[lower];
	i=lower;
	j=upper+1;

	do
	{
		do
		{
			i++;
		}while(a[i]<v&&i<=upper);

		do
		{
			j--;
		}while(a[j]>v);

		if(i<j)
		{
			a[i]=a[i]^a[j];
			a[j]=a[i]^a[j];
			a[i]=a[i]^a[j];
		}
	}while(i<j);

	for(i=0;i<=upper;i++)
		printf("%d ",a[i]);
	printf("\n");

	a[lower]=a[j];
	a[j]=v;
	return j;
}

void merge(int a[],int lower,int mid,int upper)
{
	int c[20];
	int i,j,k;
	i=lower;
	j=mid+1;
	k=0;
	while(i<=mid && j<=upper)
	{
		if(a[i]<a[j])
		{
			c[k]=a[i];
			k++;
			i++;
		}
		else
		{
			c[k]=a[j];
			k++;
			j++;
		}
	}

	while(i<=mid)
	{
		c[k]=a[i];
		i++;
		k++;
	}

	while(j<=upper)
	{
		c[k]=a[j];
		k++;
		j++;
	}

	for(j=0;j<k;j++)
		printf("%d ",c[j]);
	printf("\n");
	for(i=lower,j=0;i<=upper;i++,j++)
		a[i]=c[j];
}

/********************** OUTPUT **********************
MENU:
1. Input Numbers
2. Quick Sort
3. Merge Sort
0. Quit
Your choice: 1
Enter the number of elements: 10
Enter the elements one by one:
9
0
2
8
9
6
7
0
8
1


MENU:
1. Input Numbers
2. Quick Sort
3. Merge Sort
0. Quit
Your choice: 2
9 0 2 8 1 6 7 0 8 9
8 0 2 0 1 6 7 8
7 0 2 0 1 6
6 0 2 0 1
1 0 0 2
0 0

Sorted List after Quicksort:
0 0 1 2 6 7 8 8 9 9


MENU:
1. Input Numbers
2. Quick Sort
3. Merge Sort
0. Quit
Your choice: 3
0 9
0 2 9
8 9
0 2 8 9 9
6 7
0 6 7
1 8
0 1 6 7 8
0 0 1 2 6 7 8 8 9 9

Sorted List after Merge Sort:
0 0 1 2 6 7 8 8 9 9
************************************************************/