/*
Program to implement and Visualise non-recursive sorting algorithms such as
Bubble Sort, Insertion Sort, Selection Sort, Shell Sort
and *Recursive algorithms such as Quicksort and Merge Sort
with Enhanced Graphical User Interface

AppySort+ (Version 2.0)
This code has been made totally OpenSource by Pineapple Software.
You can share, modify, extend and redistribute it.
Code is with Proper Documentation.
Language Implemented: C
Supported Compilers: Turbo C/C++ (Version 3.0 or Further)
Contact Us for Any Doubt: softonetech@yahoo.com
*/

#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<dos.h>

struct crds
{
	int x;
	int y;
};

struct bound
{
	int x1;
	int y1;
	int x2;
	int y2;
};

struct crds cr[20];
struct bound bnd;
int speed=10;
void showinterface(int a[],int n,int index);
void bubble_sort(int a[],int n);
void insertion_sort(int a[],int n);
void selection_sort(int a[],int n);
void shell_sort(int a[],int n);
void quicksort(int a[],int n);
void quick_sort(int a[],int l,int u);
int partition(int a[],int l,int u);
void mergesort(int a[],int n);
void merge_sort(int a[],int lower,int upper);
void merge(int a[],int lower,int mid,int upper);
int maxwid;

int main(void)
{
	int arr[20],ori_arr[20],n;
	int gd=DETECT,gm,i,j;
	char choice;

	while(1)
	{
		clrscr();
		printf("AppySort+ (Version 2.0)\nPlace this executable file into your regular TC folder.\n");
		printf("MENU:\n");
		printf("1. Input Numbers\n");
		printf("2. Bubble Sort\n");
		printf("3. Insertion Sort\n");
		printf("4. Selection Sort\n");
		printf("5. Shell Sort\n");
		printf("6. Quicksort\n");
		printf("7. Merge Sort\n");
		printf("8. Show Numbers\n");
		printf("9. Set Animation Speed\n");
		printf("0. Quit\n");
		printf("Your choice: ");
		choice=getche();
		printf("\n");

		switch(choice)
		{
			case '1':
				printf("Enter number of elements: ");
				scanf("%d",&n);
				printf("Enter elements one by one:\n");
				for(i=0;i<n;i++)
					scanf("%d",&ori_arr[i]);

				for(i=0;i<n;i++)
					arr[i]=ori_arr[i];
				break;
			case '2':
				for(i=0;i<n;i++)
					arr[i]=ori_arr[i];
				printf("Initializing Graphics Mode...");
				delay(1000);
				initgraph(&gd,&gm,"");
				showinterface(arr,n,1);
				bubble_sort(arr,n);
				break;

			case '3':
				for(i=0;i<n;i++)
					arr[i]=ori_arr[i];
				printf("Initializing Graphics Mode...");
				delay(1000);
				initgraph(&gd,&gm,"");
				showinterface(arr,n,2);
				insertion_sort(arr,n);
				break;

			case '4':
				for(i=0;i<n;i++)
					arr[i]=ori_arr[i];
				printf("Initializing Graphics Mode...");
				delay(1000);
				initgraph(&gd,&gm,"");
				showinterface(arr,n,3);
				selection_sort(arr,n);
				break;

			case '5':
				for(i=0;i<n;i++)
					arr[i]=ori_arr[i];
				printf("Initializing Graphics Mode...");
				delay(1000);
				initgraph(&gd,&gm,"");
				showinterface(arr,n,4);
				shell_sort(arr,n);
				break;

			case '6':
				for(i=0;i<n;i++)
					arr[i]=ori_arr[i];
				printf("Initializing Graphics Mode...");
				delay(1000);
				initgraph(&gd,&gm,"");
				showinterface(arr,n,5);
				quicksort(arr,n);
				break;

			case '7':
				for(i=0;i<n;i++)
					arr[i]=ori_arr[i];
				printf("Initializing Graphics Mode...");
				delay(1000);
				initgraph(&gd,&gm,"");
				showinterface(arr,n,5);
				mergesort(arr,n);
				break;


			case '8':
				for(i=0;i<n;i++)
					printf("%d\n",arr[i]);
				break;

			case '9':
				printf("Specify Animation Speed in Milliseconds (Default 10): ");
				scanf("%d",&speed);
				break;

			case '0':
				clrscr();
				printf("Contact Us for Suggestions and Support:\nPineapple Software, SoftOne Tech\nE-mail: softonetech@yahoo.com");
				getch();
				exit(0);

			default:
				printf("Invalid choice!");

		}
		getch();
		closegraph();
	}
	return 0;
}

void showinterface(int a[],int n,int index)
{
	int i,xc,yc;
	char num[5];
	setfillstyle(SOLID_FILL,LIGHTGRAY);
	bar(0,20,640,480);
	setfillstyle(SOLID_FILL,BLUE);
	bar(0,0,640,20);
	setcolor(BLACK);
	for(i=0;i<n;i++)
		sprintf(num,"%d",a[i]);

	sprintf(num,"%d",a[i]);
	maxwid=textwidth(num);
	for(i=1;i<n;i++)
	{
	       sprintf(num,"%d",a[i]);
	       if(textwidth(num)>maxwid)
			maxwid=textwidth(num);
	}

	xc=50;
	yc=240;
	if(index==5||index==6)
	{
		xc=150;
		yc=70;
	}
	for(i=0;i<n;i++)
	{
		cr[i].x=xc;
		cr[i].y=yc;
		xc+=maxwid+20;
	}

	for(i=0;i<n;i++)
	{
		sprintf(num,"%d",a[i]);
		outtextxy(cr[i].x,cr[i].y,num);
	}
	outtextxy(530,460,"Pineapple");
}

void bubble_sort(int a[],int n)
{
	int i,j,l,m,p,o,noex=0,flag=0,nn;
	char msg[10],msg1[10],pass[10];
	char desc[5][100]={"Bubble sort is one of the simplest method of sorting.",
			"The i'th element is compared with its successive element and",
			"if it is greater, then both elements are exchanged.",
			"In this way, the element is `bubbled' at its position in the sorted list.",
			"Press any key to start..."};

	setcolor(WHITE);
	outtextxy(10,5,"AppySort+ : Bubble Sort Visual Demonstration");
	setcolor(BLACK);
	setfillstyle(SOLID_FILL,LIGHTGRAY);
	j=110;
	for(i=0;i<5;i++,j+=15)
		outtextxy(50,j,desc[i]);
	getch();
	j-=15;
	nn=n-1;
	bar(50-3,j-3,50+textwidth(desc[4]),j+textheight(desc[4]));
	for(i=0;i<n;i++)
	{
		bar(20,80,20+textwidth(pass),80+textheight(pass));
		sprintf(pass,"Pass=%d",i+1);
		outtextxy(20,80,pass);
		for(j=0;j<nn;j++)
		{
			line(cr[j].x+5,cr[j].y+15,cr[j].x+5,cr[j].y+15+10);
			line(cr[j+1].x+5,cr[j+1].y+15,cr[j+1].x+5,cr[j+1].y+15+10);
			line(cr[j].x+5,cr[j].y+15+10,cr[j+1].x+5,cr[j+1].y+15+10);
			if(a[j]>a[j+1])
			{
				sprintf(msg,"%d>%d",a[j],a[j+1]);
				outtextxy(cr[j].x-5,cr[j+1].y+15+15,msg);
				for(l=1;l<=16;l++)
				{
					if(l%2==0)
						setcolor(RED);
					else
						setcolor(BLUE);
					outtextxy(cr[j].x-5,cr[j+1].y+15+5+30,"Exchange");
					delay(150);

				}
				setfillstyle(SOLID_FILL,LIGHTGRAY);
				bar(cr[j].x-5,cr[j+1].y+15,cr[j+1].x-5+textwidth("No Exchange"),cr[j+1].y+15+5+30+textheight("No Exchange"));

				setcolor(BLACK);
				m=cr[j].x;
				p=cr[j+1].x;
				o=cr[j+1].y;
				sprintf(msg,"%d",a[j]);
				sprintf(msg1,"%d",a[j+1]);
				for(l=cr[j].y;l>=cr[j].y-30;l--)
				{
					bar(m-3,l-3,m+textwidth(msg),l+textheight(msg));
					bar(p-3,o-3,p+textwidth(msg1),o+textheight(msg1));
					outtextxy(m,l,msg);
					outtextxy(p,o,msg1);
					o++;
					delay(speed);
				}
				for(m=cr[j].x;m<=cr[j+1].x;m++)
				{
					bar(m-3,l-3,m+textwidth(msg),l+textheight(msg));
					bar(p-3,o-3,p+textwidth(msg1),o+textheight(msg1));
					outtextxy(m,l,msg);
					outtextxy(p,o,msg1);
					p--;
					delay(speed);
				}

				for(l;l<=cr[j+1].y;l++)
				{
					bar(m-3,l-3,m+textwidth(msg),l+textheight(msg));
					bar(p-3,o-3,p+textwidth(msg1),o+textheight(msg1));
					outtextxy(m,l,msg);
					outtextxy(p,o,msg1);
					o--;
					delay(speed);
				}

				a[j]=a[j]^a[j+1];
				a[j+1]=a[j]^a[j+1];
				a[j]=a[j]^a[j+1];
			}
			else
			{
				if(a[j]<a[j+1])
					sprintf(msg,"%d<%d",a[j],a[j+1]);
				if(a[j]==a[j+1])
					sprintf(msg,"%d=%d",a[j],a[j+1]);

				outtextxy(cr[j].x-5,cr[j+1].y+15+15,msg);
				outtextxy(cr[j].x-5,cr[j+1].y+15+5+30,"No Exchange");
				delay(2000);
				setfillstyle(SOLID_FILL,LIGHTGRAY);
				bar(cr[j].x-5,cr[j+1].y+15,cr[j+1].x-5+textwidth("No Exchange"),cr[j+1].y+15+5+30+textheight("No Exchange"));
				noex++;
			}
			if(noex==n-1)
				break;
		}
		nn--;
	}
}

void insertion_sort(int a[],int n)
{
	int i,j,temp,x,y,ps=1;
	char msg[10],pass[10];
	char desc[4][100]={"Insertion sort is based on the principle of inserting element at its correct",
			   "place in a previously sorted list. i can be varied from 1 to n-1 to sort the entire array.",
			   "This sorting methodis very much efficient and fast as compared to others.",
			   "Press any key to start..."};

	setcolor(WHITE);
	outtextxy(10,5,"AppySort+ : Insertion Sort Visual Demonstration");
	setcolor(BLACK);
	setfillstyle(SOLID_FILL,LIGHTGRAY);
	j=110;
	for(i=0;i<4;i++,j+=15)
		outtextxy(50,j,desc[i]);
	getch();
	j-=15;
	bar(50-3,j-3,50+textwidth(desc[3]),j+textheight(desc[3]));

	sprintf(pass,"Pass = %d",ps);
	for(i=1;i<n;i++)
	{
		bar(20-3,80-3,20+textwidth(pass),80+textheight(pass));
		sprintf(pass,"Pass = %d",ps++);
		outtextxy(20,80,pass);
		temp=a[i];
		x=cr[i].x;
		sprintf(msg,"%d",temp);
		setcolor(RED);
		for(y=cr[i].y;y>=cr[i].y-60;y--)
		{
			bar(x-3,y-3,x+textwidth(msg),y+textheight(msg));
			outtextxy(x,y,msg);
			delay(speed);
		}
		outtextxy(x-50,y-textheight("Element to insert")-5,"Element to insert");
		bnd.x1=x-50-6;
		bnd.y1=y-textheight("Element to insert")-6;
		bnd.x2=bnd.x1+textwidth("Element to insert")+3;
		bnd.y2=bnd.y1+textheight("Element to insert")+3;

		setcolor(BLACK);

		for(j=i-1;j>=0&&a[j]>=temp;j--)
		{
			a[j+1]=a[j];
			y=cr[j].y;
			for(x=cr[j].x;x<=cr[j+1].x;x++)
			{
				sprintf(msg,"%d",a[j]);
				bar(x-3,y-3,x+textwidth(msg),y+textheight(msg));
				outtextxy(x,y,msg);
				delay(speed);
			}
		}

		a[j+1]=temp;	//Actual Insertion
		bar(bnd.x1,bnd.y1,bnd.x2,bnd.y2);
		y=cr[i].y-60;
		sprintf(msg,"%d",temp);
		for(x=cr[i].x;x>=cr[j+1].x;x--)
		{
			bar(x-3,y-3,x+textwidth(msg),y+textheight(msg));
			outtextxy(x,y,msg);
			delay(speed);
		}

		for(y=cr[i].y-60;y<=cr[j+1].y;y++)
		{
			bar(x-3,y-3,x+textwidth(msg),y+textheight(msg));
			outtextxy(x,y,msg);
			delay(speed);
		}
	}
}

void selection_sort(int a[],int n)
{
	int i,j,min,l,m,p,o,c,ps=1;
	char msg[10],msg1[10],pass[10];
	char desc[4][100]={"Selection sort is one of the simple and efficient sorting methods.",
			  "The list is traversed and the element which has value",
			  "less than `i' is searched and these both values are then exchanged.",
			  "Press any key to start..."};

	setcolor(WHITE);
	setfillstyle(SOLID_FILL,LIGHTGRAY);
	outtextxy(10,5,"AppySort+ : Selection Sort Visual Demonstration");
	setcolor(BLACK);

	j=110;
	for(i=0;i<4;i++,j+=15)
		outtextxy(50,j,desc[i]);
	getch();
	j-=15;
	bar(50-3,j-3,50+textwidth(desc[3]),j+textheight(desc[3]));

	sprintf(pass,"Pass = %d",ps);

	for(i=0;i<n-1;i++)
	{
		bar(20-3,80-3,20+textwidth(pass),80+textheight(pass));
		sprintf(pass,"Pass = %d",ps++);
		outtextxy(20,80,pass);
		min=i;
		sprintf(msg,"%d",a[i]);
		setcolor(RED);
		outtextxy(cr[i].x,cr[i].y,msg);
		setcolor(RED);
		outtextxy(cr[i].x,cr[i].y-40,"i");
		setcolor(BLACK);
		line(cr[i].x+5,cr[i].y-15,cr[i].x+5,cr[i].y-15-15);
		bnd.x1=cr[i].x-3;
		bnd.y1=cr[i].y-40-3;
		bnd.x2=cr[i].x+textwidth("i");
		bnd.y2=cr[i].y-15;


		for(j=i+1;j<n;j++)
		{
			sprintf(msg,"%d",a[j]);
			bar(cr[j].x-3,cr[j].y-3,cr[j].x+textwidth(msg),cr[j].y+textheight(msg));
			setcolor(BLUE);
			outtextxy(cr[j].x,cr[j].y,msg);
			if(a[j]<a[min])
				min=j;
			delay(500);
			setcolor(BLACK);
			outtextxy(cr[j].x,cr[j].y,msg);
		}
		if(min!=i)
		{
			line(cr[min].x+5,cr[min].y+15,cr[min].x+5,cr[min].y+15+15);
			sprintf(msg,"%d",a[min]);
			setcolor(BLUE);
			outtextxy(cr[min].x,cr[min].y,msg);
			for(c=1;c<=16;c++)
			{
				if(c%2==0)
					setcolor(BLUE);
				else
					setcolor(RED);
				outtextxy(cr[min].x-20,cr[min].y+30,"Minimal Element");
				outtextxy(bnd.x1+3,bnd.y1+3,"i");
				delay(150);
			}
			bar(cr[min].x-20-3,cr[min].y+15-3,cr[min].x-20+textwidth("Minimal Element"),cr[min].y+30+textheight("Minimal Element"));
			bar(bnd.x1,bnd.y1,bnd.x2,bnd.y2);

			setcolor(BLACK);
			m=cr[i].x;
			l=cr[i].y;
			p=cr[min].x;
			o=cr[min].y;
			sprintf(msg,"%d",a[i]);
			sprintf(msg1,"%d",a[min]);
			for(l=cr[i].y;l>=cr[i].y-50;l--)
			{
				bar(m-3,l-3,m+textwidth(msg),l+textheight(msg));
				bar(p-3,o-3,p+textwidth(msg1),o+textheight(msg1));
				outtextxy(m,l,msg);
				outtextxy(p,o,msg1);
				o++;
				delay(speed);
			}

			for(m=cr[i].x;m<=cr[min].x;m++)
			{
				bar(m-3,l-3,m+textwidth(msg),l+textheight(msg));
				bar(p-3,o-3,p+textwidth(msg1),o+textheight(msg1));
				outtextxy(m,l,msg);
				outtextxy(p,o,msg1);
				p--;
				delay(speed);
			}

			for(l;l<=cr[min].y;l++)
			{
				bar(m-3,l-3,m+textwidth(msg),l+textheight(msg));
				bar(p-3,o-3,p+textwidth(msg1),o+textheight(msg1));
				outtextxy(m,l,msg);
				outtextxy(p,o,msg1);
				o--;
				delay(speed);
			}

			a[i]=a[i]^a[min];
			a[min]=a[i]^a[min];
			a[i]=a[i]^a[min];
		}
		else
		{
			sprintf(msg,"%d",a[i]);
			bar(bnd.x1,bnd.y1,bnd.x2,bnd.y2);
			setcolor(BLACK);
			outtextxy(cr[i].x,cr[i].y,msg);
		}
	}
}

void shell_sort(int a[],int n)
{
	int i,j,step,temp;
	int x,y,ln,l,m,ps=1;
	char msg[10],pass[10];
	char desc[4][100]={"Shell sort makes the repeated use of insertion sort. The given list is",
			   "divided into n/2 subsequent lists. The corresponding elements of these",
			   "sublists are exchanged if i'th element is less than i-step'th element.",
			   "Press any key to start..."};

	setcolor(WHITE);
	setfillstyle(SOLID_FILL,LIGHTGRAY);
	outtextxy(10,5,"AppySort+ : Shell Sort Visual Demonstration");
	setcolor(BLACK);

	j=110;
	for(i=0;i<4;i++,j+=15)
		outtextxy(50,j,desc[i]);
	getch();
	j-=15;
	bar(50-3,j-3,50+textwidth(desc[3]),j+textheight(desc[3]));

	sprintf(pass,"Pass = %d",ps);

	for(step=n/2;step>0;step=step/2)
	{
		bar(20-3,80-3,20+textwidth(pass),80+textheight(pass));
		sprintf(pass,"Pass = %d",ps++);
		setcolor(BLACK);
		outtextxy(20,80,pass);
		for(ln=step;ln<n;ln+=step)
			line(cr[ln].x-10,cr[ln].y-10,cr[ln].x-10,cr[ln].y-10+30);

		for(i=step;i<n;i++)
		{
			temp=a[i];
			x=cr[i].x;
			sprintf(msg,"%d",temp);
			setcolor(RED);
			for(y=cr[i].y;y>=cr[i].y-60;y--)
			{
				bar(x-3,y-3,x+textwidth(msg),y+textheight(msg));
				outtextxy(x,y,msg);
				delay(speed);
			}
			setcolor(BLACK);
			setfillstyle(SOLID_FILL,LIGHTGRAY);
			for(j=i;j>=step;j=j-step)
				if(temp<a[j-step])
				{
					sprintf(msg,"%d",a[j-step]);

					l=cr[j-step].x;
					m=cr[j-step].y;
					for(m;m<=cr[j-step].y+40;m++)
					{
						bar(l-3,m-3,l+textwidth(msg),m+textheight(msg));
						outtextxy(l,m,msg);
						delay(speed);
					}
					for(l;l<=cr[j].x;l++)
					{
						bar(l-3,m-3,l+textwidth(msg),m+textheight(msg));
						outtextxy(l,m,msg);
						delay(speed);
					}
					for(m;m>=cr[j].y;m--)
					{
						bar(l-3,m-3,l+textwidth(msg),m+textheight(msg));
						outtextxy(l,m,msg);
						delay(speed);
					}
					a[j]=a[j-step];
				}
				else
					break;

			l=cr[i].x;
			m=cr[i].y-60;
			sprintf(msg,"%d",temp);
			for(l;l>=cr[j].x;l--)
			{
				bar(l-3,m-3,l+textwidth(msg),m+textheight(msg));
				outtextxy(l,m,msg);
				delay(speed);
			}
			for(m;m<=cr[j].y;m++)
			{
				bar(l-3,m-3,l+textwidth(msg),m+textheight(msg));
				outtextxy(l,m,msg);
				delay(speed);
			}
			a[j]=temp;
		}
		for(ln=step;ln<n;ln+=step)
		{
			setcolor(LIGHTGRAY);
			line(cr[ln].x-10,cr[ln].y-10,cr[ln].x-10,cr[ln].y-10+30);
		}

	}
}

void quicksort(int a[],int n)
{
	int x,y,i,xt,cond;
	char msg[10];
	setcolor(WHITE);
	setfillstyle(SOLID_FILL,LIGHTGRAY);
	outtextxy(10,5,"AppySort+ : Quicksort Visual Demonstration");
	setcolor(BLACK);
	getch();
	quick_sort(a,0,n-1);
	setfillstyle(SOLID_FILL,LIGHTGRAY);

	for(i=0;i<n;i++)
	{
		x=cr[i].x;
		y=cr[i].y;
		while(y<=420)
		{
			sprintf(msg,"%d",a[i]);
			bar(x-3,y-3,x+textwidth(msg)+3,y+textheight(msg)+3);
			y++;
			setcolor(BLACK);
			sprintf(msg,"%d",a[i]);
			outtextxy(x,y,msg);
			delay(5);
		}
		xt=70+maxwid+i*40;

		if(x<=xt)
		{
			while(x<=xt)
			{
				setcolor(LIGHTGRAY);
				sprintf(msg,"%d",a[i]);
				outtextxy(x,y,msg);
				x++;
				setcolor(BLACK);
				sprintf(msg,"%d",a[i]);
				outtextxy(x,y,msg);
				delay(5);
			}
		}
		else
		{
			while(x>=xt)
			{
				setcolor(LIGHTGRAY);
				sprintf(msg,"%d",a[i]);
				outtextxy(x,y,msg);
				x--;
				setcolor(BLACK);
				sprintf(msg,"%d",a[i]);
				outtextxy(x,y,msg);
				delay(5);
			}
		}

		while(y<=440)
		{
			setcolor(LIGHTGRAY);
			sprintf(msg,"%d",a[i]);
			outtextxy(x,y,msg);
			y++;
			setcolor(BLACK);
			sprintf(msg,"%d",a[i]);
			outtextxy(x,y,msg);
			delay(5);
		}
	}
}

void quick_sort(int a[],int l,int u)
{
	int j,ii,jj;
	int x[20],y[20];
	char msg[10];
	setfillstyle(SOLID_FILL,LIGHTGRAY);
	if(l<u)
	{
		j=partition(a,l,u);

		if(j!=l)
		{
		for(ii=l;ii<=j-1;ii++)
		{
			x[ii]=cr[ii].x;
			y[ii]=cr[ii].y;
		}

		while(y[l]<=cr[l].y+20)
		{
			for(ii=l;ii<=j-1;ii++)
			{
				sprintf(msg,"%d",a[ii]);
				bar(x[ii]-3,y[ii]-3,x[ii]+textwidth(msg)+3,y[ii]+textheight(msg)+3);
				y[ii]++;
			}
			for(ii=l;ii<=j-1;ii++)
			{
				sprintf(msg,"%d",a[ii]);
				outtextxy(x[ii],y[ii],msg);
			}
			delay(speed);
		}

		while(x[l]>=cr[l].x-20)
		{
			for(ii=l;ii<=j-1;ii++)
			{
				sprintf(msg,"%d",a[ii]);
				bar(x[ii]-3,y[ii]-3,x[ii]+textwidth(msg)+3,y[ii]+textheight(msg)+3);
				x[ii]--;
			}
			for(ii=l;ii<=j-1;ii++)
			{
				sprintf(msg,"%d",a[ii]);
				outtextxy(x[ii],y[ii],msg);
			}
			delay(speed);
		}

		while(y[l]<=cr[l].y+40)
		{
			for(ii=l;ii<=j-1;ii++)
			{
				sprintf(msg,"%d",a[ii]);
				bar(x[ii]-3,y[ii]-3,x[ii]+textwidth(msg)+3,y[ii]+textheight(msg)+3);
				y[ii]++;
			}
			for(ii=l;ii<=j-1;ii++)
			{
				sprintf(msg,"%d",a[ii]);
				outtextxy(x[ii],y[ii],msg);
			}
			delay(speed);
		}

		for(jj=l;jj<=j-1;jj++)
		{
			cr[jj].x=x[jj];
			cr[jj].y=y[jj];
		}
		}
		//------------------
		if(j!=u)
		{
		for(ii=j+1;ii<=u;ii++)
		{
			x[ii]=cr[ii].x;
			y[ii]=cr[ii].y;
		}
		while(y[j+1]<=cr[j+1].y+20)
		{
			for(ii=j+1;ii<=u;ii++)
			{
				sprintf(msg,"%d",a[ii]);
				bar(x[ii]-3,y[ii]-3,x[ii]+textwidth(msg)+3,y[ii]+textheight(msg)+3);
				y[ii]++;
			}
			for(ii=j+1;ii<=u;ii++)
			{
				sprintf(msg,"%d",a[ii]);
				outtextxy(x[ii],y[ii],msg);
			}
			delay(speed);
		}

		while(x[j+1]<=cr[j+1].x+20)
		{
			for(ii=j+1;ii<=u;ii++)
			{
				sprintf(msg,"%d",a[ii]);
				bar(x[ii]-3,y[ii]-3,x[ii]+textwidth(msg)+3,y[ii]+textheight(msg)+3);
				x[ii]++;
			}
			for(ii=j+1;ii<=u;ii++)
			{
				sprintf(msg,"%d",a[ii]);
				outtextxy(x[ii],y[ii],msg);
			}
			delay(speed);
		}

		while(y[j+1]<=cr[j+1].y+40)
		{
			for(ii=j+1;ii<=u;ii++)
			{
				sprintf(msg,"%d",a[ii]);
				bar(x[ii]-3,y[ii]-3,x[ii]+textwidth(msg)+3,y[ii]+textheight(msg)+3);
				y[ii]++;
			}
			for(ii=j+1;ii<=u;ii++)
			{
				sprintf(msg,"%d",a[ii]);
				outtextxy(x[ii],y[ii],msg);
			}
			delay(speed);
		}

		for(jj=j+1;jj<=u;jj++)
		{
			cr[jj].x=x[jj];
			cr[jj].y=y[jj];
		}
		}

		quick_sort(a,l,j-1);
		quick_sort(a,j+1,u);
	}
}

int partition(int a[],int l,int u)
{
	int v,i,j,x1,y1,x2,y2;
	char msg[10];
	v=a[l];
	i=l;
	j=u+1;

	setcolor(BLACK);
	line(cr[l].x+5,cr[l].y+10,cr[l].x+5,cr[i].y+30);
	outtextxy(cr[l].x-15,cr[l].y+35,"Pivot");

	do
	{
		do
		{
			if(i!=l)
			{
			setcolor(LIGHTGRAY);
			line(cr[i].x+5,cr[i].y+10,cr[i].x+5,cr[i].y+30);
			outtextxy(cr[i].x+5,cr[i].y+35,"i");
			}
			i++;
			setcolor(BLACK);
			line(cr[i].x+5,cr[i].y+10,cr[i].x+5,cr[i].y+30);
			setcolor(RED);
			outtextxy(cr[i].x+5,cr[i].y+35,"i");
			delay(500);
		}while(a[i]<v && i<u);

		do
		{
			if(j!=u+1)
			{
				if(j==i||j==l)
				{
					setcolor(LIGHTGRAY);
					line(cr[j].x+5,cr[j].y+45,cr[j].x+5,cr[j].y+65);
					outtextxy(cr[j].x+5,cr[j].y+70,"j");
				}
				else
				{
					setcolor(LIGHTGRAY);
					line(cr[j].x+5,cr[j].y+10,cr[j].x+5,cr[j].y+30);
					outtextxy(cr[j].x+5,cr[j].y+35,"j");
				}
			}
			j--;
			if(j==i||j==l)
			{
				setcolor(BLACK);
				line(cr[j].x+5,cr[j].y+45,cr[j].x+5,cr[j].y+65);
				setcolor(BLUE);
				outtextxy(cr[j].x+5,cr[j].y+70,"j");
			}
			else
			{
				setcolor(BLACK);
				line(cr[j].x+5,cr[j].y+10,cr[j].x+5,cr[j].y+30);
				setcolor(BLUE);
				outtextxy(cr[j].x+5,cr[j].y+35,"j");
			}
			delay(500);
		}while(a[j]>v);

		if(i>j)
		{
			setcolor(RED);
			outtextxy(cr[j].x-3,cr[j].y+80,"(i>j)");
			delay(1500);
			setcolor(LIGHTGRAY);
			outtextxy(cr[j].x-3,cr[j].y+80,"(i>j)");
		}

		setcolor(LIGHTGRAY);
		line(cr[i].x+5,cr[i].y+10,cr[i].x+5,cr[i].y+30);
		outtextxy(cr[i].x+5,cr[i].y+35,"i");
		line(cr[j].x+5,cr[j].y+10,cr[j].x+5,cr[j].y+30);
		outtextxy(cr[j].x+5,cr[j].y+35,"j");

		if(j==i||j==l)
		{
			setcolor(LIGHTGRAY);
			line(cr[j].x+5,cr[j].y+45,cr[j].x+5,cr[j].y+65);
			outtextxy(cr[j].x+5,cr[j].y+70,"j");
		}

		if(i<j)
		{
			x1=cr[i].x;
			y1=cr[i].y;
			x2=cr[j].x;
			y2=cr[j].y;
			while(y1<=cr[i].y+30)
			{
				setfillstyle(SOLID_FILL,LIGHTGRAY);
				sprintf(msg,"%d",a[i]);
				bar(x1-3,y1-3,x1+textwidth(msg)+3,y1+textheight(msg)+3);
				sprintf(msg,"%d",a[i]);
				bar(x2-3,y2-3,x2+textwidth(msg)+3,y2+textheight(msg)+3);
				y1++;
				y2--;
				setcolor(BLACK);
				sprintf(msg,"%d",a[i]);
				outtextxy(x1,y1,msg);
				sprintf(msg,"%d",a[j]);
				outtextxy(x2,y2,msg);
				delay(speed);
			}

			while(x1<=cr[j].x)
			{
				setfillstyle(SOLID_FILL,LIGHTGRAY);
				sprintf(msg,"%d",a[i]);
				bar(x1-3,y1-3,x1+textwidth(msg)+3,y1+textheight(msg)+3);
				sprintf(msg,"%d",a[i]);
				bar(x2-3,y2-3,x2+textwidth(msg)+3,y2+textheight(msg)+3);
				x1++;
				x2--;
				setcolor(BLACK);
				sprintf(msg,"%d",a[i]);
				outtextxy(x1,y1,msg);
				sprintf(msg,"%d",a[j]);
				outtextxy(x2,y2,msg);
				delay(speed);
			}

			while(y1>=cr[j].y)
			{
				setfillstyle(SOLID_FILL,LIGHTGRAY);
				sprintf(msg,"%d",a[i]);
				bar(x1-3,y1-3,x1+textwidth(msg)+3,y1+textheight(msg)+3);
				sprintf(msg,"%d",a[i]);
				bar(x2-3,y2-3,x2+textwidth(msg)+3,y2+textheight(msg)+3);
				y1--;
				y2++;
				setcolor(BLACK);
				sprintf(msg,"%d",a[i]);
				outtextxy(x1,y1,msg);
				sprintf(msg,"%d",a[j]);
				outtextxy(x2,y2,msg);
				delay(speed);
			}

			a[i]=a[i]^a[j];
			a[j]=a[i]^a[j];
			a[i]=a[i]^a[j];
		}
	}while(i<j);

	setcolor(LIGHTGRAY);
	line(cr[l].x+5,cr[l].y+10,cr[l].x+5,cr[i].y+30);
	outtextxy(cr[l].x-15,cr[l].y+35,"Pivot");

	x1=cr[l].x;
	y1=cr[l].y;
	x2=cr[j].x;
	y2=cr[j].y;

	while(y1<=cr[l].y+30)
	{
		setfillstyle(SOLID_FILL,LIGHTGRAY);
		sprintf(msg,"%d",a[l]);
		bar(x1-3,y1-3,x1+textwidth(msg)+3,y1+textheight(msg)+3);
		sprintf(msg,"%d",a[j]);
		bar(x2-3,y2-3,x2+textwidth(msg)+3,y2+textheight(msg)+3);
		y1++;
		y2--;
		setcolor(BLACK);
		sprintf(msg,"%d",a[l]);
		outtextxy(x1,y1,msg);
		sprintf(msg,"%d",a[j]);
		outtextxy(x2,y2,msg);
		delay(speed);
	}

	while(x1<=cr[j].x-2)
	{
		setfillstyle(SOLID_FILL,LIGHTGRAY);
		sprintf(msg,"%d",a[l]);
		bar(x1-3,y1-3,x1+textwidth(msg)+3,y1+textheight(msg)+3);
		sprintf(msg,"%d",a[j]);
		bar(x2-3,y2-3,x2+textwidth(msg)+3,y2+textheight(msg)+3);
		x1++;
		x2--;
		setcolor(BLACK);
		sprintf(msg,"%d",a[l]);
		outtextxy(x1,y1,msg);
		sprintf(msg,"%d",a[j]);
		outtextxy(x2,y2,msg);
		delay(speed);
	}
	while(y1>=cr[j].y)
	{
		setfillstyle(SOLID_FILL,LIGHTGRAY);
		sprintf(msg,"%d",a[l]);
		bar(x1-3,y1-3,x1+textwidth(msg)+3,y1+textheight(msg)+3);
		sprintf(msg,"%d",a[i]);
		bar(x2-3,y2-3,x2+textwidth(msg)+3,y2+textheight(msg)+3);
		y1--;
		y2++;
		setcolor(BLACK);
		sprintf(msg,"%d",a[l]);
		outtextxy(x1,y1,msg);
		sprintf(msg,"%d",a[j]);
		outtextxy(x2,y2,msg);
		delay(speed);
	}
	setfillstyle(SOLID_FILL,LIGHTGRAY);
	sprintf(msg,"%d",a[l]);
	bar(x1-3,y1-3,x1+textwidth(msg)+3,y1+textheight(msg)+3);
	y1--;
	setcolor(BLACK);
	sprintf(msg,"%d",a[l]);
	outtextxy(x1,y1,msg);

	a[l]=a[j];
	a[j]=v;
	return j;
}

void mergesort(int a[],int n)
{
	int x,y,i,xt,cond;
	char msg[10];
	setcolor(WHITE);
	setfillstyle(SOLID_FILL,LIGHTGRAY);
	outtextxy(10,5,"AppySort+ : Merge Sort Visual Demonstration");
	setcolor(BLACK);
	getch();
	merge_sort(a,0,n-1);
}

void merge_sort(int a[],int lower,int upper)
{
	int mid,ii,jj,x[20],y[20];
	char msg[10];

	setfillstyle(SOLID_FILL,LIGHTGRAY);
	bar(20,30,200,40);
	outtextxy(23,33,"Status: Partitioning");

	if(lower<upper)
	{
		mid=(lower+upper)/2;

		for(ii=lower;ii<=mid;ii++)
		{
			x[ii]=cr[ii].x;
			y[ii]=cr[ii].y;
		}

		while(y[lower]<=cr[lower].y+20)
		{
			for(ii=lower;ii<=mid;ii++)
			{
				sprintf(msg,"%d",a[ii]);
				bar(x[ii]-3,y[ii]-3,x[ii]+textwidth(msg)+3,y[ii]+textheight(msg)+3);
				y[ii]++;
			}
			for(ii=lower;ii<=mid;ii++)
			{
				sprintf(msg,"%d",a[ii]);
				outtextxy(x[ii],y[ii],msg);
			}
			delay(speed);
		}

		while(x[lower]>=cr[lower].x-20)
		{
			for(ii=lower;ii<=mid;ii++)
			{
				sprintf(msg,"%d",a[ii]);
				bar(x[ii]-3,y[ii]-3,x[ii]+textwidth(msg)+3,y[ii]+textheight(msg)+3);
				x[ii]--;
			}
			for(ii=lower;ii<=mid;ii++)
			{
				sprintf(msg,"%d",a[ii]);
				outtextxy(x[ii],y[ii],msg);
			}
			delay(speed);
		}

		while(y[lower]<=cr[lower].y+40)
		{
			for(ii=lower;ii<=mid;ii++)
			{
				sprintf(msg,"%d",a[ii]);
				bar(x[ii]-3,y[ii]-3,x[ii]+textwidth(msg)+3,y[ii]+textheight(msg)+3);
				y[ii]++;
			}
			for(ii=lower;ii<=mid;ii++)
			{
				sprintf(msg,"%d",a[ii]);
				outtextxy(x[ii],y[ii],msg);
			}
			delay(speed);
		}

		for(jj=lower;jj<=mid;jj++)
		{
			cr[jj].x=x[jj];
			cr[jj].y=y[jj];
		}
		//------------------

		for(ii=mid+1;ii<=upper;ii++)
		{
			x[ii]=cr[ii].x;
			y[ii]=cr[ii].y;
		}
		while(y[mid+1]<=cr[mid+1].y+20)
		{
			for(ii=mid+1;ii<=upper;ii++)
			{
				sprintf(msg,"%d",a[ii]);
				bar(x[ii]-3,y[ii]-3,x[ii]+textwidth(msg)+3,y[ii]+textheight(msg)+3);
				y[ii]++;
			}
			for(ii=mid+1;ii<=upper;ii++)
			{
				sprintf(msg,"%d",a[ii]);
				outtextxy(x[ii],y[ii],msg);
			}
			delay(speed);
		}

		while(x[mid+1]<=cr[mid+1].x+20)
		{
			for(ii=mid+1;ii<=upper;ii++)
			{
				sprintf(msg,"%d",a[ii]);
				bar(x[ii]-3,y[ii]-3,x[ii]+textwidth(msg)+3,y[ii]+textheight(msg)+3);
				x[ii]++;
			}
			for(ii=mid+1;ii<=upper;ii++)
			{
				sprintf(msg,"%d",a[ii]);
				outtextxy(x[ii],y[ii],msg);
			}
			delay(speed);
		}

		while(y[mid+1]<=cr[mid+1].y+40)
		{
			for(ii=mid+1;ii<=upper;ii++)
			{
				sprintf(msg,"%d",a[ii]);
				bar(x[ii]-3,y[ii]-3,x[ii]+textwidth(msg)+3,y[ii]+textheight(msg)+3);
				y[ii]++;
			}
			for(ii=mid+1;ii<=upper;ii++)
			{
				sprintf(msg,"%d",a[ii]);
				outtextxy(x[ii],y[ii],msg);
			}
			delay(speed);
		}

		for(jj=mid+1;jj<=upper;jj++)
		{
			cr[jj].x=x[jj];
			cr[jj].y=y[jj];
		}

		merge_sort(a,lower,mid);
		merge_sort(a,mid+1,upper);
		merge(a,lower,mid,upper);
	}
}

void merge(int a[],int lower,int mid,int upper)
{
	int c[20];
	int i,j,k,x,y;
	char msg[20];
	struct crds crt[20],crk[20];

	setfillstyle(SOLID_FILL,LIGHTGRAY);
	bar(20,30,200,40);
	outtextxy(23,33,"Status: Merging");

	i=lower;
	j=mid+1;
	k=0;
	while(i<=mid && j<=upper)
	{
		if(a[i]<a[j])
		{
			c[k]=a[i];
			crt[k]=cr[i];
			k++;
			i++;
		}
		else
		{
			c[k]=a[j];
			crt[k]=cr[j];
			k++;
			j++;
		}

	}

	while(i<=mid)
	{
		c[k]=a[i];
		crt[k]=cr[i];
		i++;
		k++;
	}

	while(j<=upper)
	{
		c[k]=a[j];
		crt[k]=cr[j];
		k++;
		j++;
	}

	x=cr[lower].x;
	y=cr[lower].y+40;

	for(i=0;i<20;i++)
	{
		crk[i].x=x;
		crk[i].y=y;
		x+=maxwid+30;
	}

	for(i=lower,j=0;i<=upper;i++,j++)
	{
		a[i]=c[j];
		cr[i].x=crt[j].x;
		cr[i].y=crt[j].y;

		x=cr[i].x;
		y=cr[i].y;

		while(y<=crk[0].y-20)
		{
			setfillstyle(SOLID_FILL,LIGHTGRAY);
			sprintf(msg,"%d",a[i]);
			bar(x-3,y-3,x+textwidth(msg)+3,y+textheight(msg)+3);
			y++;
			setcolor(BLACK);
			sprintf(msg,"%d",a[i]);
			outtextxy(x,y,msg);
			delay(speed);
		}

		if(crk[j].x<=cr[i].x)
		{
		while(x>=crk[j].x)
		{
			setfillstyle(SOLID_FILL,LIGHTGRAY);
			sprintf(msg,"%d",a[i]);
			bar(x-3,y-3,x+textwidth(msg)+3,y+textheight(msg)+3);
			x--;
			setcolor(BLACK);
			sprintf(msg,"%d",a[i]);
			outtextxy(x,y,msg);
			delay(speed);
		}
		}
		else
		{
		while(x<=crk[j].x)
		{
			setfillstyle(SOLID_FILL,LIGHTGRAY);
			sprintf(msg,"%d",a[i]);
			bar(x-3,y-3,x+textwidth(msg)+3,y+textheight(msg)+3);
			x++;
			setcolor(BLACK);
			sprintf(msg,"%d",a[i]);
			outtextxy(x,y,msg);
			delay(speed);
		}
		}

		while(y<=crk[j].y)
		{
			setfillstyle(SOLID_FILL,LIGHTGRAY);
			sprintf(msg,"%d",a[i]);
			bar(x-3,y-3,x+textwidth(msg)+3,y+textheight(msg)+3);
			y++;
			setcolor(BLACK);
			sprintf(msg,"%d",a[i]);
			outtextxy(x,y,msg);
			delay(speed);
		}
		cr[i].x=x;
		cr[i].y=y;
	}
}


/*
Pineapple Software, SoftOne Tech (2012)
*/