/*Programming Lab
Practical No. 2(B)
Date 24 July 2011
Program to perform various string operations such as length,
copy, contencate, reverse etc. without using library functions
*/

//Header files
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include<math.h>

//Declaration of functions
void read_string(char[],char[]);
int xstrlen(char[]);
void xstrrev(char[]);
int xstrlen(char[]);
void xstrcat(char[],char[]);
void xstrcpy(char[],char[]);
int are_equal(char[],char[]);
int xstrchr(char[],char);
int xstrstr(char[],char[]);
void exchange(char[],char[]);
void xstrncpy(char[],char[],int);
void xstrupr(char[]);
void xstrlwr(char[]);
int xatoi(char[]);
void xitoa(int,char[]);

void main()		//Main function
{
	char str1[20],str2[20],str0[20];
	int l1,l2,n;
	char key,ch;
	int flag=0;

	while(1)
	{
	clrscr();
	if(flag==1)	   //Prints the inputted strings everytime at right side of screen
	{
		gotoxy(60,2);
		printf("String 1: %s",str1);
		gotoxy(60,3);
		printf("String 2: %s",str2);
	}
	gotoxy(1,1);
	printf("Menu: \n");	       //Prints the menu
	printf("1. Input the strings\n");
	printf("2. Length of the strings\n");
	printf("3. Reverse the string\n");
	printf("4. Contencate the strings\n");
	printf("5. Copy the string\n");
	printf("6. Check whether the string is palindrome\n");
	printf("7. Find substring\n");
	printf("8. Find occurence of a particular character\n");
	printf("9. Compare two strings\n");
	printf("10. Exchange the contents of two strings\n");
	printf("11. Extract some part of the string\n");
	printf("12. Convert the string into UPPERCASE\n");
	printf("13. Convert the string into lowercase\n");
	printf("14. Convert the string into integer\n");
	printf("15. Convert the integer into string\n");
	printf("0. Exit\n");

	printf("\nYour choice: ");
	scanf("%d",&key);
	switch(key)
	{
		case 1:		//Reads the strings
			read_string(str1,str2);
			flag=1;
			break;

		case 2:		//Calculates the length of strings
			l1=xstrlen(str1);
			l2=xstrlen(str2);
			printf("\nLength of String 1: %d",l1);
			printf("\nLength of String 2: %d",l2);
			break;


		case 3:		//String reversal
			xstrrev(str1);
			printf("\nReversed String: %s",str1);
			break;

		case 4:		//Contencates String 2 into String 1
			xstrcat(str1,str2);
			printf("\nStrings After Contencation:\nString 1: %s",str1);
			printf("\nString 2: %s",str2);
			break;

		case 5:		//Copies String 2 into String 1
			xstrcpy(str1,str2);
			printf("\nStrings After Copy:\nString 1: %s",str1);
			printf("\nString 2: %s",str2);
			break;

		case 6:         //Checks whether strings are palindrome or not
			xstrcpy(str0,str1);
			xstrrev(str0);
			if(are_equal(str1,str0))
				printf("\nThe string is palindrome!");
			else
				printf("\nThe string is not palindrome.");
			break;

		case 7:        //Finds substring
			printf("\nEnter the substring to find: ");
			scanf("%s",str0);
			if(xstrstr(str0,str1))
				printf("Substring %s is present!",str0);
			else
				printf("Substring %s not found.",str0);
			break;

		case 8:	      //Checks whether the given character is present in string or not
			printf("\nEnter any character: ");
			ch=getche();
			if(xstrchr(str1,ch))
				printf("\nCharacter %c is present!",ch);
			else
				printf("\nCharacter %c is not present",ch);
			break;

		case 9:		//Checks whether the strings are equal
			if(are_equal(str1,str2))
				printf("\nStrings are equal.");
			else
				printf("\nStrings are not equal.");
			break;

		case 10:	//Exchanges the contents of two strings
			printf("\nStrings before exchange:");
			printf("\nString 1: %s\nString 2: %s",str1,str2);
			exchange(str1,str2);
			printf("\nStrings after exchange:");
			printf("\nString 1: %s\nString 2: %s",str1,str2);
			exchange(str1,str2);
			break;

		case 11:	//Extracts the given number of characters from the string
			printf("\nEnter the number of characters to extract: ");
			scanf("%d",&n);
			xstrncpy(str0,str1,n);
			printf("\nExtracted string: %s",str0);
			break;

		case 12:	//Converts the string into UPPERCASE
			xstrupr(str1);
			printf("\nString 1 in UPPERCASE: %s",str1);
			break;

		case 13:	//Converts the string into lowercase
			xstrlwr(str1);
			printf("\nString 1 in lowercase: %s",str1);
			break;

		case 14:	//Converts string into integer
			n=xatoi(str1);
			printf("\nExtracted integer from string 1: %d",n);
			break;

		case 15:	//Converts the given integer into string
			printf("Enter any integer: ");
			scanf("%d",&n);
			xitoa(n,str1);
			printf("\nString 1: %s",str1);
			break;

		case 0:		//Exits from program
			exit(0);

		default:	//Invalid choice
			printf("\nInvalid key!");

	}
	getch();
	}
}

void read_string(char s1[],char s2[])
{
	printf("\nInput String 1: ");
	scanf("%s",s1);

	printf("Input String 2: ");
	scanf("%s",s2);
}

int xstrlen(char s[])
{
	int cnt=0,i;

	for(i=0;s[i]!='\0';i++)
	{
		cnt++;
	}
	return cnt;
}

void xstrrev(char s[])
{
	char t[20];
	int i,j=0,l;
	l=xstrlen(s);
	for(i=l-1;i>=0;i--)
	{
		t[j++]=s[i];
	}
	t[j]='\0';
	strcpy(s,t);
}

void xstrcpy(char s1[],char s2[])
{
	int i;

	for(i=0;s2[i]!='\0';i++)
	{
		s1[i]=s2[i];
	}
	s1[i]='\0';
}

void xstrcat(char s1[],char s2[])
{
	int i=0,j=0;
	while(s1[i]!='\0')
	{
		i++;
	}

	while(s2[j]!='\0')
	{
		s1[i]=s2[j];
		i++;
		j++;
	}
	s2[i]='\0';
}

int are_equal(char s1[],char s2[])
{
	int i,j;
	for(i=0;s1[i]!='\0';i++)
	{
		if(s1[i]!=s2[i])
		{
			return 0;
		}

	}
	return 1;
}

int xstrchr(char s[],char c)
{
	int i;
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]==c)
			return 1;
	}
	return 0;
}

int xstrstr(char s0[],char s1[])
{
	int l0,l1,i,j,k;
	l0=xstrlen(s0);
	l1=xstrlen(s1);

	j=0;
	for(i=0;i<l1;i++)
	{
		if(s1[i]==s0[j])
		{
			k=i;
			for(j=0;j<l0;j++)
			{
				if(s0[j]==s1[k])
					k++;
				else
					break;

				if(s0[j+1]=='\0')
					return 1;
			}
		}
	}
	return 0;
}

void exchange(char s1[],char s2[])
{
	char s0[20];
	xstrcpy(s0,s1);
	xstrcpy(s1,s2);
	xstrcpy(s2,s0);
}

void xstrncpy(char s0[],char s1[],int n)
{
	int i;
	for(i=0;i<=n-1;i++)
	{
		s0[i]=s1[i];
	}

	s0[i]='\0';
}

void xstrupr(char s[])
{
	int i;
	for(i=0;s[i]!='\0';i++)
	{
		if((s[i]>=97)&&(s[i]<=122))
			s[i]-=32;
	}
}

void xstrlwr(char s[])
{
	int i;
	for(i=0;s[i]!='\0';i++)
	{
		if((s[i]>=65)&&(s[i]<=90))
			s[i]+=32;
	}
}

int xatoi(char s[])
{
	int l,i,p,n=0;
	l=strlen(s);
	p=l-1;
	for(i=0;i<l;i++)
	{
		if((s[i]>=48)&&(s[i]<=57))
		{
			n=n+((s[i]-48)*(pow(10,p)));
			p--;
		}
	}
	return n;
}

void xitoa(int n,char s[])
{
	int i=0,nd;
	char temp[10];

	while(n!=0)
	{
		nd=n%10;
		s[i]=nd+48;
		i++;
		n=n/10;
	}
	s[i]='\0';
	strrev(s);
}

/************************* OUTPUT *******************************
Menu:
1. Input the strings                                       String 1: Rajinikanth
2. Length of the strings                                   String 2: Robot      
3. Reverse the string                                                           
4. Contencate the strings                                                       
5. Copy the string
6. Check whether the string is palindrome
7. Find substring
8. Find occurence of a particular character
9. Compare two strings
10. Exchange the contents of two strings
11. Extract some part of the string
12. Convert the string into UPPERCASE
13. Convert the string into lowercase
14. Convert the string into integer
15. Convert the integer into string
0. Exit

Your choice: 1

Input String 1: Rajinikanth
Input String 2: Robot

Menu:
1. Input the strings                                       String 1: Rajinikanth
2. Length of the strings                                   String 2: Robot      
3. Reverse the string                                                           
4. Contencate the strings                                                       
5. Copy the string                                                              
6. Check whether the string is palindrome                                       
7. Find substring                                                               
8. Find occurence of a particular character                                     
9. Compare two strings                                                          
10. Exchange the contents of two strings                                        
11. Extract some part of the string                                             
12. Convert the string into UPPERCASE
13. Convert the string into lowercase                                           
14. Convert the string into integer                                             
15. Convert the integer into string                                             
0. Exit                                                                         
                                                                                
Your choice: 2
                                                                                
Length of String 1: 11
Length of String 2: 5

Your choice: 3

Reversed String: htnakinijaR

Your choice: 4

Strings After Contencation:
String 1: RajinikanthRobot
String 2: Robot

Your choice: 5

Strings After Copy:
String 1: Robot
String 2: Robot

Your choice: 6

The string is not palindrome.

Your choice: 7

Enter the substring to find: kant
Substring kant is present!

Your choice: 8

Enter any character: j
Character j is present!

Your choice: 9

Strings are not equal.

Your choice: 10

Strings before exchange:
String 1: Rajinikanth
String 2: Robot
Strings after exchange:
String 1: Robot
String 2: Rajinikanth

Your choice: 11

Enter the number of characters to extract: 6

Extracted string: Rajini

Your choice: 12

String 1 in UPPERCASE: RAJINIKANTH

Your choice: 13

String 1 in lowercase: rajinikanth

Your choice: 14
Input String 1: 24567
Input String 2: 12345

Your choice: 14

Extracted integer from string 1: 24567

Your choice: 15
Enter any integer: 450

String 1: 450

*/