//Programming Lab
//Practical No. 1
//Program to perform various array operations even, odd, max, min

#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#define MAX 10
#define YES 1
#define NO 0

int size;
void findmax(int*);
void findmin(int*);
void findeven(int[]);
void findodd(int[]);
void specify(int*);
void show(int*);
void searchelm(int*);
int flag=NO;

void main()
{
	int arr[10],max,min,yc,i;
	char key;

	HERE:			//Prints the numbers everytime at the right side of screen
	clrscr();
	yc=1;
	if(flag==YES)
	{
		textcolor(WHITE);
		for(i=0;i<=size-1;i++)
		{
			gotoxy(75,yc);
			cprintf("%d",arr[i]);
			yc++;
		}

	}

	gotoxy(1,1);
	textcolor(GREEN);
	cprintf("MENU\n");		//Display Menu
	textcolor(BROWN);
	cprintf("\r1. Specify elements\n");
	cprintf("\r2. Search an element\n");
	cprintf("\r3. Find maximal element\n");
	cprintf("\r4. Find minimal element\n");
	cprintf("\r5. View a set of even elements\n");
	cprintf("\r6. View a set of odd elements\n");
	textcolor(RED);
	cprintf("\r0. Quit\n\r");
	textcolor(WHITE);
	cprintf("Your Choice: ");
	key=getche();
	switch(key)
	{
		case '1':	//Specifies the parameters of array
			specify(arr);
			break;

		case '2':	//Searches the particular element in array
			searchelm(arr);
			break;

		case '3':	//Finds maximal element in array
			findmax(arr);
			break;

		case '4':	//Finds minimal element in array
			findmin(arr);	
			break;

		case '5':	//Finds and prints even elements in array
			findeven(arr);
			break;

		case '6':	//Finds and prints odd elements in array
			findodd(arr);
			break;

		case '0':	//Exit the program
			exit(0);
			break;

		default:	//Exception
			cprintf("\t\t\t\rInvalid key!");
	}
	goto HERE;
}

void specify(int *s)
{
	int i;
	textcolor(CYAN);
	cprintf("\n\rSpecify the number of elements: ");
	scanf("%d",&size);
	if(size>MAX)
	{
		cprintf("\n\rSize of array exceeded!");
		getch();
		return;
	}

	cprintf("\n\rEnter the elements one by one:\n\r");
	for(i=1;i<=size;i++)
	{
		scanf("%d",s);
		s++;
	}
	flag=YES;
}

void searchelm(int *s)
{
	int e,count=1;
	textcolor(CYAN);
	cprintf("\n\rSpecify the element to be searched: ");
	scanf("%d",&e);
	while(count<=size)
	{
		if(*s==e)
			break;
		s++;
		count++;
	}
	if(count>size)
		cprintf("Element %d not found at all.",e);
	else
		cprintf("Element %d found at location %d.",e,count);
	getch();
}

void findmax(int s[])
{
	int max,count=0;
	max=s[0];
	for(count=1;count<=size-1;count++)
	{
		if(s[count]>max)
			max=s[count];
	}
	cprintf("\n\rMaximal element in an array is %d.",max);
	getch();
}

void findmin(int s[])
{
	int min,count;
	min=s[0];
	for(count=1;count<=size-1;count++)
	{
		if(s[count]<min)
			min=s[count];
	}
	cprintf("\n\rMinimal element in an array is %d.",min);
	getch();
}

void findeven(int s[])
{
	int even[10];
	int i,j=0;
	for(i=0;i<=size-1;i++)
	{
		if(s[i]%2==0)
			even[j++]=s[i];
	}
	textcolor(CYAN);
	printf("\n\rEven elements in the array are: \n\r",j);
	for(i=0;i<=j-1;i++)
		cprintf("%d\r\n",even[i]);
	getch();
}

void findodd(int s[])
{
	int odd[10];
	int i,j=0;
	for(i=0;i<=size-1;i++)
	{
		if(s[i]%2!=0)
			odd[j++]=s[i];
	}
	textcolor(CYAN);
	printf("\n\rOdd elements in the array are:\n\r");
	for(i=0;i<=j-1;i++)
		cprintf("%d\r\n",odd[i]);
	getch();
}

/*OUTPUT:
MENU
1. Specify elements                                                             
2. Search an element                                                            
3. Find maximal element                                                         
4. Find minimal element                                                         
5. View a set of even elements                                                  
6. View a set of odd elements                                                   
0. Quit
Your Choice: 1                                                                  
Specify the number of elements: 5                                               
                                                                                
Enter the elements one by one:
3
2
5
7
1

MENU                                                  3
1. Specify elements                                   2
2. Search an element                                  5
3. Find maximal element                               7
4. Find minimal element                               1
5. View a set of even elements
6. View a set of odd elements
0. Quit
Your Choice: 2
Specify the element to be searched: 5
Element 5 found at location 3.


                                                    
Your Choice: 3                                                                  
Maximal element in an array is 7.

Your Choice: 4
Minimal element in an array is 1.

Your Choice: 5
Even elements in the array are:
2

Your Choice: 6
Odd elements in the array are:
3
5
7
1
*/