/*Programming Lab
Practical No. 2
Date 21 July 2011
Program to perform various string operations such as length,
copy, contencate, reverse etc.
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

void main()	//Initialize the program from main function
{
	char str1[20],str2[20],str0[20],*ptr,ch;
	int choice,l1,l2,num,rad,flag=0;

	HERE:
	clrscr();
	if(flag==1)
	{
		gotoxy(60,2);
		printf("String 1: %s",str1);
		gotoxy(60,3);
		printf("String 2: %s",str2);
		gotoxy(1,1);
	}
	printf("Menu: \n");
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
	printf("11. Convert string into number\n");
	printf("12. Convert an integer number into the string\n");
	printf("13. Extract some part of the string\n");
	printf("14. Convert the string into UPPERCASE\n");
	printf("15. Convert the string into lowercase\n");
	printf("16. Exit\n");
	printf("Your choice: ");
	scanf("%d",&choice);


	switch(choice)
	{
		case 1:		//Input the strings
			printf("Input string 1: ");
			scanf("%s",str1);
			printf("Input string 2: ");
			scanf("%s",str2);
			flag=1;
			goto HERE;
			break;

		case 2:		//Length of strings
			l1=strlen(str1);
			l2=strlen(str2);
			printf("Length of string 1 = %d",l1);
			printf("\nLength of string 2 = %d",l2);
			break;

		case 3:		//Reverses the stirng
			printf("String 1 before reversing: %s\n",str1);
			strrev(str1);
			printf("String 1 after reversing: %s",str1);
			break;

		case 4:		//Contencation of two strings
			strcat(str1,str2);
			printf("String 1 after contencation: %s\nString 2: %s",str1,str2);
			break;

		case 5:		//Copying one string into another
			strcpy(str1,str2);
			printf("String 1 after copy: %s\nString 2:%s",str1,str2);
			break;

		case 6:		//Checks whether the string is palindrome
			strcpy(str0,str1);
			strrev(str0);
			if(strcmp(str1,str0)==0)
				printf("String is palindrome");
			else
				printf("String is not palinderome");
			break;

		case 7:		//Finds the first occurence of substring
			printf("Enter the substring: ");
			scanf("%s",str0);
			ptr=strstr(str1,str0);
			if(ptr==0)
				printf("The substring %s not found at all.",str0,str1);
			else
				printf("The substring %s found at first occurence %u.",str0,ptr);
			break;

		case 8:		//Finds the occurence of given character
			printf("Enter the character: ");
			ch=getch();
			ptr=strchr(str1,ch);
			if(ptr==0)
				printf("The character %c not found at all.",ch,str1);
			else
				printf("The character %c found at location %u",ch,ptr);
			break;

		case 9:		//Checks whether the strings are equal
			if(strcmp(str1,str2)==0)
				printf("Strings are equal.");
			else
				printf("Strings are not equal.");
			break;

		case 10:	//Exchanges the contents of two strings
			printf("Strings before exchange:\nString 1: %s\nString 2: %s\n\n",str1,str2);
			strcpy(str0,str1);
			strcpy(str1,str2);
			strcpy(str2,str0);
			printf("Strings after exchange:\nString 1: %s\nString 2: %s",str1,str2);
			break;

		case 11:	//Converts the string into integer
			num=atoi(str1);
			printf("String 1: %s\n",str1);
			printf("Extracted Integer: %d",num);
			break;

		case 12:	//Converts the integer into string
			printf("Enter any number and desired radix: ");
			scanf("%d %d",&num,&rad);
			itoa(num,str2,rad);
			printf("String 2: %s",str2);
			break;

		case 13:	//Extracts the given length of string
			printf("Enter the length to extract: ");
			scanf("%d",&num);
			strncpy(str0,str1,num);
			printf("Extracted string: %s",str0);
			break;

		case 14:	//Converts the string into UPPERCASE
			strupr(str1);
			printf("String 1 in UPPERCASE: %s",str1);
			break;

		case 15:	//Converts the string into lowercase
			strlwr(str1);
			printf("String 1 in lowercase: %s",str1);
			break;

		case 16:	//Exits from application
			exit(0);

		default:	//Default case (invalid)
			printf("Invalid choice!");
	}
	getch();
	goto HERE;
}

/* OUTPUT:
Menu:
1. Input the strings
2. Length of the strings
3. Reverse the string
4. Contencate the strings
5. Copy the string
6. Check whether the string is palindrome
7. Find substring
8. Find occurence of a particular character
9. Compare two strings
10. Exchange the contents of two strings
11. Convert string into number
12. Convert an integer number into the string
13. Extract some part of the string
14. Convert the string into UPPERCASE
15. Convert the string into lowercase
16. Exit
Your choice: 1
Input string 1: Harry
Input string 2: Potter


Menu:
1. Input the strings                    String 1: Harry      
2. Length of the strings                String 2: Potter     
3. Reverse the string                                                           
4. Contencate the strings                                                       
5. Copy the string                                                              
6. Check whether the string is palindrome                                       
7. Find substring                                                               
8. Find occurence of a particular character                                     
9. Compare two strings                                                          
10. Exchange the contents of two strings                                        
11. Convert string into number
12. Convert an integer number into the string
13. Extract some part of the string
14. Convert the string into UPPERCASE
15. Convert the string into lowercase
16. Exit
Your choice: 2
Length of string 1 = 5
Length of string 2 = 6

Your Choice: 3
String 1 before reversing: Harry
String 1 after reversing: yrraH

Your choice: 4
String 1 after contencation: HarryPotter                                        
String 2: Potter                                                                
                                                                                
Your choice: 5
String 1 after copy: Potter
String 2:Potter

Your choice: 6
String is not palinderome

Your choice: 7
Enter the substring: rry
The substring rry found at first occurence 65496.

Your choice: 9
Strings are not equal.

Your choice: 10
Strings before exchange:
String 1: Harry
String 2: Potter                                                                
                                                                                
Strings after exchange:                                                         
String 1: Potter                                                                
String 2: Harry

Your choice: 11
String 1: 1234
Extracted Integer: 1234

Your choice: 12
Enter any number and desired radix: 95 2
String 2: 1011111

Your choice: 13
Enter the length to extract: 3
Extracted string: Harry

Your choice: 14
String 1 in UPPERCASE: HARRY

Your choice: 15
String 1 in lowercase: harry
*/


