/*Programming Lab
Practical No. 9
Date 29 September 2011
Program to implement non-recursive sorting algorithms such as Bubble Sort,
Insertion Sort, Selection Sort, Shell Sort
SE(B)			Roll No. 03 */


#include<graphics.h>
#include<stdio.h>
#include<conio.h>

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
void showinterface(int a[],int n);
void bubble_sort(int a[],int n);
void insertion_sort(int a[],int n);
void selection_sort(int a[],int n);
void shell_sort(int a[],int n);

void main()
{
	int arr[20],n,choice;
	int gd=DETECT,gm,i,j;

	while(1)
	{
		clrscr();
		printf("AppySort+\n");
		printf("MENU:\n");
		printf("1. Input Numbers\n");
		printf("2. Bubble Sort\n");
		printf("3. Insertion Sort\n");
		printf("4. Selection Sort\n");
		printf("5. Shell Sort\n");
		printf("0. Quit\n");
		printf("Your choice: ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				printf("Enter number of elements: ");
				scanf("%d",&n);
				printf("Enter elements one by one:\n");
				for(i=0;i<n;i++)
					scanf("%d",&arr[i]);
				break;
			case 2:
				printf("Initializing Graphics Mode...");
				delay(1000);
				initgraph(&gd,&gm,"C:\\TC\\BGI");
				showinterface(arr,n);
				bubble_sort(arr,n);
				break;

			case 3:
				printf("Initializing Graphics Mode...");
				delay(1000);
				initgraph(&gd,&gm,"C:\\TC\\BGI");
				showinterface(arr,n);
				insertion_sort(arr,n);
				break;

			case 4:
				printf("Initializing Graphics Mode...");
				delay(1000);
				initgraph(&gd,&gm,"C:\\TC\\BGI");
				showinterface(arr,n);
				selection_sort(arr,n);
				break;

			case 5:
				printf("Initializing Graphics Mode...");
				delay(1000);
				initgraph(&gd,&gm,"C:\\TC\\BGI");
				showinterface(arr,n);
				shell_sort(arr,n);
				break;

			case 0:
				exit(0);

		}
		getch();
		closegraph();
	}
}

void showinterface(int a[],int n)
{
	int i,xc,yc,maxwid;
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

	xc=10;
	yc=240;
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
	outtextxy(550,460,"AppyBlaze");
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
					delay(10);
				}
				for(m=cr[j].x;m<=cr[j+1].x;m++)
				{
					bar(m-3,l-3,m+textwidth(msg),l+textheight(msg));
					bar(p-3,o-3,p+textwidth(msg1),o+textheight(msg1));
					outtextxy(m,l,msg);
					outtextxy(p,o,msg1);
					p--;
					delay(10);
				}

				for(l;l<=cr[j+1].y;l++)
				{
					bar(m-3,l-3,m+textwidth(msg),l+textheight(msg));
					bar(p-3,o-3,p+textwidth(msg1),o+textheight(msg1));
					outtextxy(m,l,msg);
					outtextxy(p,o,msg1);
					o--;
					delay(10);
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
		for(y=cr[i].y-textheight(msg)-3;y>=cr[i].y-60;y--)
		{
			bar(x-3,y-3,x+textwidth(msg),y+textheight(msg));
			outtextxy(x,y,msg);
			delay(10);
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
				delay(10);
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
			delay(10);
		}

		for(y=cr[i].y-60;y<=cr[j+1].y;y++)
		{
			bar(x-3,y-3,x+textwidth(msg),y+textheight(msg));
			outtextxy(x,y,msg);
			delay(10);
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
				delay(10);
			}

			for(m=cr[i].x;m<=cr[min].x;m++)
			{
				bar(m-3,l-3,m+textwidth(msg),l+textheight(msg));
				bar(p-3,o-3,p+textwidth(msg1),o+textheight(msg1));
				outtextxy(m,l,msg);
				outtextxy(p,o,msg1);
				p--;
				delay(10);
			}

			for(l;l<=cr[min].y;l++)
			{
				bar(m-3,l-3,m+textwidth(msg),l+textheight(msg));
				bar(p-3,o-3,p+textwidth(msg1),o+textheight(msg1));
				outtextxy(m,l,msg);
				outtextxy(p,o,msg1);
				o--;
				delay(10);
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
				delay(10);
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
						delay(10);
					}
					for(l;l<=cr[j].x;l++)
					{
						bar(l-3,m-3,l+textwidth(msg),m+textheight(msg));
						outtextxy(l,m,msg);
						delay(10);
					}
					for(m;m>=cr[j].y;m--)
					{
						bar(l-3,m-3,l+textwidth(msg),m+textheight(msg));
						outtextxy(l,m,msg);
						delay(10);
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
				delay(10);
			}
			for(m;m<=cr[j].y;m++)
			{
				bar(l-3,m-3,l+textwidth(msg),m+textheight(msg));
				outtextxy(l,m,msg);
				delay(10);
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

/* OUTPUT CANNOT BE GENERATED BECAUSE THIS PROGRAM USES GRAPHICS MODE AND NOT REGULAR TEXT MODE */