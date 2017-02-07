/*Programming Lab
Practical No. 13
Date 17 August 2011
PROGRAM STATEMENT : To implement stack as an ADT .Use this ADT to perform
		    expression conversion and evaluation(infix to postfix,
		    infix to prefix,prefix to infix,prefix to postfix,
		    postfix to infix and postfix to prefix).

SE(B)			Roll No. 03 */

/* inclusion of header files */

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<stdlib.h>

			 //GLOBAL DECLARATION
char stack[20];
int top=-1;


void push(char x)
  {
	stack[++top]=x;
  }

char pop()
  {
	char x;
	x=stack[top--];
	return(x);
  }

int priority(char x)
  {
	switch(x)
	  {
		case '*':
		case '/':
		case '%':
			  return(2);

		case '+':
		case '-':
			  return(1);
		default:
			  return(0);
	  }
  }


		/* INFIX TO POSTFIX */

void inpost(char infix[20],char postfix[20])
  {
	char ch,ch1;
	int i,j;

	j=0;

	for(i=0;infix[i]!='\0';i++)
	  {
		ch=infix[i];

		if(ch=='(')
			push(ch);

		else if(ch==')')
		  {
			ch1=pop();
			while(ch1!='(')
			  {
				postfix[j++]=ch1;
				ch1=pop();
			  }
		  }
		else if(ch=='+'||ch=='-'||ch=='%'||ch=='/'||ch=='*')
		  {
			while(priority(stack[top])>=priority(ch) && top!=-1)
			  {
				ch1=pop();
				postfix[j++]=ch1;
			  }
			push(ch);
		  }
		else
			postfix[j++]=ch;
	  }
	while(top!=-1)
		postfix[j++]=pop();
	postfix[j]='\0';
  }


		/* INFIX TO PREFIX */

void inpre(char infix[20])
  {
	char ch,ch1,prefix[20];
	int i,j;

	strrev(infix);
	j=strlen(infix);
	prefix[j]='\0';

	j--;

	for(i=0;infix[i]!='\0';i++)
	  {
		ch=infix[i];

		if(ch==')')
			push(ch);

		else if(ch=='(')
		  {
			ch1=pop();
			while(ch1!=')')
			  {
				prefix[j--]=ch1;
				ch1=pop();
			  }
		  }
		else if(ch=='+'||ch=='-'||ch=='%'||ch=='/'||ch=='*')
		  {
			while(priority(stack[top])>priority(ch) && top!=-1)
			  {
				ch1=pop();
				prefix[j--]=ch1;
			  }
			push(ch);
		  }
		else
			prefix[j--]=ch;
	  }
	while(top!=-1)
		prefix[j--]=pop();

	printf("\nResultant prefix string is :");
	for(i=j+1;prefix[i]!='\0';i++)
		printf("%c",prefix[i]);
  }

		/* POSTFIX TO INFIX */

void postin(char postfix[20],char infix[20])
  {
	char stk[20][20],temp[20];
	char  temp1[20],temp2[20],temp3[20];
	int i;

	for(i=0;postfix[i]!='\0';i++)
	  {
		if(isalpha(postfix[i])||isdigit(postfix[i]))
		  {
			temp1[0]=postfix[i];
			temp1[1]='\0';
			strcpy(stk[++top],temp1);
		  }
		else
		  {
			strcpy(temp,stk[top--]);
			strcpy(temp2,temp);
			strcpy(temp,stk[top--]);
			strcpy(temp3,temp);
			strcpy(temp,"(");
			strcat(temp,temp3);
			temp3[0]=postfix[i];
			temp3[1]='\0';
			strcat(temp,temp3);
			strcat(temp,temp2);
			strcat(temp,")");
			strcpy(stk[++top],temp);
		  }
	  }
	strcpy(infix,stk[top]);
  }

		/* PREFIX TO INFIX */

void prein(char prefix[20],char infix[20])
  {
	char stk[20][20],temp[20];
	char  temp1[20],temp2[20],temp3[20];
	int i;

	strrev(prefix);

	for(i=0;prefix[i]!='\0';i++)
	  {
		if(isalpha(prefix[i])||isdigit(prefix[i]))
		  {
			temp1[0]=prefix[i];
			temp1[1]='\0';
			strcpy(stk[++top],temp1);
		  }
		else
		  {
			strcpy(temp,stk[top--]);
			strcpy(temp2,temp);
			strcpy(temp,stk[top--]);
			strcpy(temp3,temp);
			strcpy(temp,"(");
			strcat(temp,temp2);
			temp2[0]=prefix[i];
			temp2[1]='\0';
			strcat(temp,temp2);
			strcat(temp,temp3);
			strcat(temp,")");
			strcpy(stk[++top],temp);
		  }
	  }
	strcpy(infix,stk[top]);
  }

		/* PREFIX TO POSTFIX */

void prepost(char prefix[20],char postfix[20])
  {
	char stk[20][20],temp[20];
	char  temp1[20],temp2[20],temp3[20],t[20];
	int i;

	strrev(prefix);

	for(i=0;prefix[i]!='\0';i++)
	  {
		if(isalpha(prefix[i])||isdigit(prefix[i]))
		  {
			temp1[0]=prefix[i];
			temp1[1]='\0';
			strcpy(stk[++top],temp1);
		  }
		else
		  {
			strcpy(temp,stk[top--]);
			strcpy(temp3,stk[top--]);
			strcat(temp,temp3);
			t[0]=prefix[i];
			t[1]='\0';
			strcat(temp,t);
			strcpy(stk[++top],temp);
		  }
	  }
	strcpy(postfix,stk[top]);
  }

		/* POSTFIX TO PREFIX */

   void postpre(char prefix[20],char postfix[20])
    {
	char stk[20][20];
	char  temp1[20],temp2[20],temp3[20],t[20];
	int i;

	for(i=0;postfix[i]!='\0';i++)
	  {
		if(isalpha(postfix[i])||isdigit(postfix[i]))
		  {
			temp1[0]=postfix[i];
			temp1[1]='\0';
			strcpy(stk[++top],temp1);
		  }
		else
		  {
			strcpy(temp2,stk[top--]);
			strcpy(temp3,stk[top--]);
			t[0]=postfix[i];
			t[1]='\0';

			strcat(t,temp3);
			strcat(t,temp2);
			strcpy(stk[++top],t);
		  }
	  }
	strcpy(prefix,stk[top]);
    }

			/*  POSTFIX EVALUATION */

int posteval(char postfix[20])
  {
	int op1,op2,i;
	for(i=0;postfix[i]!='\0';i++)
	  {
		if(isdigit(postfix[i]))
			push(postfix[i]-'0');
		else
		  {
			op1=pop();
			op2=pop();
			switch(postfix[i])
			  {
				case '+':
					push(op2+op1);
					break;
				case '-':
					push(op2-op1);
					break;
				case '*':
					push(op2*op1);
					break;
				case '/':
					push(op2/op1);
					break;
				case '%':
					push(op2%op1);
					break;
			  }
		  }
	  }
       return(stack[top]);
  }

			/* PREFIX EVALUATION */

int preeval(char prefix[20])
  {
	int op1,op2,i;

	strrev(prefix);
	for(i=0;prefix[i]!='\0';i++)
	  {
		if(isdigit(prefix[i]))
			push(prefix[i]-'0');
		else
		  {
			op1=pop();
			op2=pop();
			switch(prefix[i])
			  {
				case '+':
					push(op1+op2);
					break;
				case '-':
					push(op1-op2);
					break;
				case '*':
					push(op1*op2);
					break;
				case '/':
					push(op1/op2);
					break;
				case '%':
					push(op1%op2);
					break;
			  }
		  }
	  }
       return(stack[top]);
  }
			/* MAIN FUNCTION */

void main()
  {
	char postfix[20],infix[20],prefix[20];
	int ch,res,res2;
	clrscr();

	while(1)
	  {
		printf("\n**************MENU**************\n");
		printf("\n1) Infix to postfix");
		printf("\n2) Infix to prefix");
		printf("\n3) Prefix to infix");
		printf("\n4) Prefix to postfix");
		printf("\n5) Postfix to infix");
		printf("\n6) Postfix to prefix");
		printf("\n7) Postfix evaluation");
		printf("\n8) Prefix evaluation");
		printf("\n9) Exit");

		printf("\nEnter your choice : ");
		scanf("%d",&ch);

		switch(ch)
		  {
		     case 1:
			    printf("\nEnter infix expression : ");
			    scanf("%s",infix);
			    inpost(infix,postfix);
			    printf("\nResultant postfix string is :");
			    printf("\n\t\t%s",postfix);
			    break;

		     case 2:
			    printf("\nEnter infix expression : ");
			    scanf("%s",infix);
			    inpre(infix);
			    break;

		     case 3:
			    printf("\nEnter prefix string : ");
			    scanf("%s",prefix);
			    prein(prefix,infix);
			    printf("\nInfix is : ");
			    printf("%s",infix);
			    break;

		     case 4:
			    printf("\nEnter prefix string : ");
			    scanf("%s",prefix);
			    prepost(prefix,postfix);
			    printf("\nPostfix is : ");
			    printf("%s",postfix);
			    break;

		     case 5:
			    printf("\nEnter postfix string : ");
			    scanf("%s",postfix);
			    postin(postfix,infix);
			    printf("\nInfix is : ");
			    printf("%s",infix);
			    break;

		     case 6:
			    printf("\nEnter postfix string : ");
			    scanf("%s",postfix);
			    postpre(prefix,postfix);
			    printf("\nPrefix is : ");
			    printf("%s",prefix);
			    break;

		     case 7:
			    printf("\nEnter a postfix expression : ");
			    scanf("%s",postfix);
			    res=posteval(postfix);
			    printf("\nThe value of expression is %d",res);
			    break;

		     case 8:
			    printf("\nEnter a prefix expression : ");
			    scanf("%s",prefix);
			    res2=preeval(prefix);
			    printf("\nThe value of expression is %d",res2);
			    break;

		     case 9:
			    exit(0);

		     default:
			      printf("\nEnter a valid choice");
		  }
		getch();
	  }
  }
/*
----------------------OUTPUT---------------

**************MENU**************

1) Infix to postfix
2) Infix to prefix
3) Prefix to infix
4) Prefix to postfix
5) Postfix to infix
6) Postfix to prefix
7) Postfix evaluation
8) Prefix evaluation
9) Exit

Enter your choice : 1

Enter infix expression : (A+B)*D+E/(F+A*D)+C

Resultant postfix string is :
                AB+D*EFAD*+/+C+

Enter your choice : 2

Enter infix expression : (A+B)*(C-D)

Resultant prefix string is :*+AB-CD

Enter your choice : 3

Enter prefix string : -A/B$*CDE

Infix is : (A-(B/((C*D)$E)))

Enter your choice : 4

Enter prefix string : -A/B$*CDE

Postfix is : ABCD*E$/-

Enter your choice : 5

Enter postfix string : AB+D*EFAD*+/+C+

Infix is : ((((A+B)*D)+(E/(F+(A*C+C)

Enter your choice : 6

Enter postfix string : AB+D*EFAD*+/+C+

Prefix is : ++*+ABD/E+F*ADC

Enter your choice : 7

Enter a postfix expression : 653+9*

The value of expression is 72

Enter your choice : 8

Enter a prefix expression : +92

The value of expression is 11

Enter your choice :9

*/
