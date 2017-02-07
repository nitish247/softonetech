/*Programming Lab
Practical No. 7
Date 15 September 2011 (Engineers' Day)
Program to perform various operations on polynomials and addition,
subtraction, multiplication and evaluation.
SE(B)			Roll No. 03 */

#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>

struct poly
{
	int coef;
	int expo;
};

char* getexpn(int x,int y);
void convert(char* str,struct poly p[],int *count);
void disp_poly(struct poly p[],int count,int x,int y);
void add_poly(struct poly padd[30],struct poly p1[],struct poly p2[],int cnt1,int cnt2,int *cnt3);
void sub_poly(struct poly padd[30],struct poly p1[],struct poly p2[],int cnt1,int cnt2,int *cnt3);
void mul_poly(struct poly p3[30],struct poly p1[],struct poly p2[],int cnt1,int cnt2,int *cnt3);
long int evaluate_poly(struct poly p[],int cnt,int x);
void sort_poly(struct poly p[],int cnt);

void main()
{
	int gd=DETECT,gm;
	int choice,i,cnt1,cnt2,cnt3,x,flag=0;
	long int ev;
	struct poly p1[30],p2[30],p3[30];
	char *expn;
	expn=(char*)malloc(100*(sizeof(char)));
	initgraph(&gd,&gm,"C:\\TC\\BGI");   //Initializes the graphics mode

	while(1)
	{
		cleardevice();
		if(flag)
		{
			settextstyle(2,HORIZ_DIR,6);
			outtextxy(10,25,"Polynomial 1:");
			disp_poly(p1,cnt1,10,60);
			line(0,95,640,95);
			settextstyle(2,HORIZ_DIR,6);
			outtextxy(10,100,"Polynomial 2:");
			disp_poly(p2,cnt2,10,135);
			line(0,170,640,170);
		}
		gotoxy(1,22);
		printf("MENU:\n");
		printf("1. Input Polynomials\n");
		printf("2. Add Polynomials\n");
		printf("3. Subtract Polynomials\n");
		printf("4. Multiply Polynomials\n");
		printf("5. Evaluate\n");
		printf("0. Exit\n");
		printf("Your choice: ");
		setcolor(WHITE);
		line(0,330,225,330);
		line(225,330,225,480);
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				settextstyle(2,HORIZ_DIR,5);
				outtextxy(10,20,"Directly input first Polynomial followed by enter key:");
				expn=getexpn(10,55);
				convert(expn,p1,&cnt1);
				sort_poly(p1,cnt1);

				settextstyle(2,HORIZ_DIR,5);
				outtextxy(10,100,"Directly input Second Polynomial followed by enter key:");
				expn=getexpn(10,135);
				convert(expn,p2,&cnt2);
				sort_poly(p2,cnt2);

				flag=1;
				break;

			case 2:
				settextstyle(2,HORIZ_DIR,6);
				outtextxy(10,190,"Polynomial Addition:");
				add_poly(p3,p1,p2,cnt1,cnt2,&cnt3);
				disp_poly(p3,cnt3,10,250);
				break;

			case 3:
				settextstyle(2,HORIZ_DIR,6);
				outtextxy(10,190,"Polynomial Subtraction:");
				sub_poly(p3,p1,p2,cnt1,cnt2,&cnt3);
				disp_poly(p3,cnt3,10,250);
				break;

			case 4:
				settextstyle(2,HORIZ_DIR,6);
				outtextxy(10,190,"Polynomial Multiplication:");
				mul_poly(p3,p1,p2,cnt1,cnt2,&cnt3);
				disp_poly(p3,cnt3,10,235);
				break;

			case 5:
				gotoxy(2,13);
				printf("Enter value for x: ");
				scanf("%d",&x);
				ev=evaluate_poly(p1,cnt1,x);
				gotoxy(2,14);
				printf("Value of Polynomial 1 for x=%d is %d",x,ev);
				ev=evaluate_poly(p2,cnt2,x);
				gotoxy(2,15);
				printf("Value of Polynomial 1 for x=%d is %d",x,ev);
				break;

			case 0:
				closegraph();
				exit(0);
		}
	getch();
	}
}

char* getexpn(int x,int y) //Graphical user interface for inputting polynomial
{
	char c,s[2],*expn,token;
	const char *base=expn;
	int flag,font=8,sz1=2,sz2=1;
	token=1;
	settextstyle(font,HORIZ_DIR,sz1);
	while(1)
	{
		flag=0;
		c=getch();
		s[0]=c;
		s[1]='\0';
		if(c=='='||c==13)
			break;
		if(token==1)
		{
			if((c>='0'&&c<='9')||c=='+'||c=='-')
			{
				outtextxy(x,y,s);
				flag=1;
			}
			else
			if(c=='x')
			{
				outtextxy(x,y,s);
				token=2;
				flag=1;
			}

		}
		if(token==2)
		{
			if(c>='0'&&c<='9')
			{
				settextstyle(font,HORIZ_DIR,sz2);
				outtextxy(x+3,y-textheight(s)+4,s);
				flag=1;
			}
			else
			if(c=='+'||c=='-')
			{
				settextstyle(font,HORIZ_DIR,sz1);
				outtextxy(x,y,s);
				token=1;
				flag=1;
			}
		}
		if(flag)
		{
			x+=textwidth(s);
			if(expn==base&&c!='-')
				*expn++='+';
			*expn++=c;
		}
	}
	*expn='\0';
	return base;
}

void disp_poly(struct poly p[],int count,int x,int y)
{
	int i,font=8,sz1=2,sz2=1,yc=y;
	char s[10],s0[10];
	for(i=0;i<count;i++)
	{
		y=yc;
		if(p[i].coef==0)
			continue;

		if(p[i].coef>0&&i!=0)
				strcpy(s,"+");
		else
			strcpy(s,"");


		if((p[i].coef==1)&&p[i].expo!=0)
			sprintf(s0,"x",p[i].coef);
		else
		if((p[i].coef!=1)&&p[i].expo!=0)
			sprintf(s0,"%dx",p[i].coef);
		else
		if(p[i].expo==0)
			sprintf(s0,"%d",p[i].coef);


		strcat(s,s0);
		settextstyle(font,HORIZ_DIR,sz1);
		outtextxy(x,y,s);
		x+=textwidth(s);

		if(p[i].expo!=0&&p[i].expo!=1)
		{
			sprintf(s,"%d",p[i].expo);
			settextstyle(font,HORIZ_DIR,sz2);
			outtextxy(x+3,y-textheight(s)+4,s);
			x+=textwidth(s)+3;
		}
	}
}

void sort_poly(struct poly p[],int cnt)
{
	int i,j;
	struct poly temp;
	for(i=0;i<cnt;i++)
		for(j=0;j<cnt-1;j++)
		{
			if(p[j].expo<p[j+1].expo)
			{
				temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;
			}
		}

	for(i=0;i<=cnt-1;i++)
	{
		for(j=i+1;j<=cnt-1;j++)
		{
			if(p[i].coef==0)
				continue;
			if(p[i].expo==p[j].expo)
			{
				p[i].coef+=p[j].coef;
				p[j].coef=0;
			}
		}
	}
}

void convert(char* str,struct poly p[],int *count)
{
	int i=0,token=1;
	char *num;
	const char *base=num;
	gotoxy(1,15);

	*num++=*str++;

	while(1)
	{
		if(token==1)
		{
			if((*str>='0'&&*str<='9'))
			{
				*num++=*str++;
			}
			else
			if(*str=='x'||*str=='+'||*str=='-'||*str=='\0')
			{
				*num='\0';
				num=base;
				if((strcmp(num,"+")==0)||(strcmp(num,"-")==0))
				{
					num=base;
					if(*num=='+')
						p[i].coef=1;
					else
						p[i].coef=-1;
				}
				else
					p[i].coef=atoi(num);
				token=2;
				if(*str=='+'||*str=='-'||*str=='\0')
				{
					p[i].expo=0;
					token=1;
					*num++=*str;
					if(*str=='\0')
					{
						*count=i+1;
						break;
					}
					i++;
				}
				str++;
			}
		}
		else
		if(token==2)
		{
			if(*str>='0'&&*str<='9')
			{
				*num++=*str++;
			}
			else
			if(*str=='+'||*str=='-'||*str=='\0')
			{
				*num='\0';
				num=base;
				if(*num=='\0')
					p[i].expo=1;

				else
				p[i].expo=atoi(num);
				if(*str=='\0')
				{
					*count=i+1;
					break;
				}
				token=1;
				*num++=*str++;
				i++;
			}
		}
	}
}

void add_poly(struct poly padd[],struct poly p1[],struct poly p2[],int cnt1,int cnt2,int *cnt3)
{
	int i,j,k=0,flag=0;

	for(i=0;i<cnt1;i++)
	{
		padd[k].coef=p1[k].coef;
		padd[k].expo=p1[k].expo;
		k++;
	}

	for(j=0;j<cnt2;j++)
	{
		flag=0;
		for(i=0;i<cnt1;i++)
		{
			if(p2[j].expo==padd[i].expo)
			{
				flag=1;
				break;
			}
		}

		if(flag==0)
		{
			padd[k].coef=p2[j].coef;
			padd[k].expo=p2[j].expo;
			k++;
		}
		else
		{
			padd[i].coef=padd[i].coef+p2[j].coef;
			padd[i].expo=padd[i].expo;
		}
	}
	*cnt3=k;
	sort_poly(padd,*cnt3);
}

void sub_poly(struct poly padd[],struct poly p1[],struct poly p2[],int cnt1,int cnt2,int *cnt3)
{
	int i,j,k=0,flag=0;

	for(i=0;i<cnt1;i++)
	{
		padd[k].coef=p1[k].coef;
		padd[k].expo=p1[k].expo;
		k++;
	}

	for(j=0;j<cnt2;j++)
	{
		flag=0;
		for(i=0;i<cnt1;i++)
		{
			if(p2[j].expo==padd[i].expo)
			{
				flag=1;
				break;
			}
		}

		if(flag==0)
		{
			padd[k].coef=-p2[j].coef;
			padd[k].expo=p2[j].expo;
			k++;
		}
		else
		{
			padd[i].coef=padd[i].coef-p2[j].coef;
			padd[i].expo=padd[i].expo;
		}
	}
	*cnt3=k;
	sort_poly(padd,*cnt3);
}


void mul_poly(struct poly p3[],struct poly p1[],struct poly p2[],int cnt1,int cnt2,int *cnt3)
{
	int i,j,k=0;
	for(i=0;i<cnt1;i++)
	{
		for(j=0;j<cnt2;j++)
		{
			p3[k].coef=p1[i].coef*p2[j].coef;
			p3[k].expo=p1[i].expo+p2[j].expo;
			k++;
		}
	}
	*cnt3=k;
	sort_poly(p3,*cnt3);
}

long int evaluate_poly(struct poly p[],int cnt,int x)
{
	int i;
	long int ans=0;
	for(i=0;i<cnt;i++)
		ans+=p[i].coef*(pow(x,p[i].expo));
	return ans;
}

/* OUTPUT CANNOT BE GENERATED BECAUSE THIS PROGRAM USES GRAPHICS MODE AND NOT REGULAR TEXT MODE */