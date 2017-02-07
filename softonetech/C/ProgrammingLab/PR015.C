/*Programming Lab
Practical No. 15
Date 17 October 2011
PROGRAM STATEMENT : To implement the mini project of student database using
		    linked list for creation,insertion,deletion,modification,
		    sorting and searching.

SE(B)			Roll No. 03 */

 /* inclusion of header files */

#include<stdio.h>
#include<conio.h>
#include<alloc.h>
#include<stdlib.h>

		/* Declaration of Structure node */

typedef struct node
  {
	long int id;
	char name[20],initials[10],add[40],no[12];
	int date;
	int month;
	int year;
	struct node* link;
  }NODE;

		/* Function to create the student database */

NODE *create(NODE *head)
  {
	NODE *curr,*prev;
	char ans;

	do
	  {
		curr=(NODE*) malloc(sizeof(NODE));
		printf("\nEnter the Roll no. : ");
		scanf("%ld",&curr->id);
		printf("\nEnter the NAME: ");
		scanf("%s",curr->name);
		printf("\nEnter the NAME INITIALS: ");
		scanf("%s",curr->initials);
		printf("\nEnter the ADDRESS: ");
		scanf("%s",curr->add);
		printf("\nEnter the NUMBER: ");
		scanf("%s",curr->no);
		printf("\nEnter the DATE OF BIRTH: ");
		scanf("%d%d%d",&curr->date,&curr->month,&curr->year);

		curr->link=NULL;

		if(head==NULL)
		  {
			head=curr;
			prev=curr;
		  }
		else
		  {
			prev->link=curr;
			prev=curr;
		  }
		printf("Do you want to add more nodes???: ");
		ans=getche();
	  }while(tolower(ans)=='y');

	return (head);
  }


		/* Function to display the student database */

void display(NODE *head)
  {
	NODE *temp;
	temp=head;

	if(temp==NULL)
		printf("\nEmpty list");
	else
	  {
		printf("\nID\tNAME\tINITIALS\tADDRESS\t\tNUMBER\t\tDOB\n");

		while(temp!=NULL)
		  {
			printf("\n%ld\t%s\t%s\t\t%s\t\t%s\t\t%d-%d-%d",temp->id,
				temp->name,temp->initials,temp->add,
				temp->no,temp->date,temp->month,temp->year);
			temp=temp->link;
		  }
	  }
  }

		/* Function to perform search operation */

void search(NODE *head)
  {
	char ini;
	int flag=0,count=1;
	NODE *temp;
	temp=head;

	printf("Enter the initials of the record to be searched: ");
	scanf("%s",ini);

	if(head==NULL)
		printf("\nEmpty list");
	else
	  {
		while(temp!=NULL)
		  {
			if(strcmp(temp->initials,ini)==0)
			  {
				printf("%ld\t%s\t%s\t%s\t%s\t%d %d %d",temp->id,temp->name,
					temp->initials,temp->add,temp->no,
					temp->date,temp->month,temp->year);
				printf("\nFound at position %d",count);
				flag=1;
			  }
			temp=temp->link;
			count++;
		  }
	  }
	if(flag==0)
		printf("\nNot found");
  }

	/* Function to perform sorting operations */

NODE* sort(NODE *head)
  {
	NODE *j,*curr,*prev,*temp,*jlink;
	int l=0,i=0;
	curr=head;

	while(curr!=NULL)
	  {
		curr=curr->link;
		l++;
	  }
	for(i=0;i<l;i++)
	  {
		for(j=head;j->link!=NULL;prev=j,j=j->link)
		  {
			if(j->id>j->link->id)
			  {
				jlink=j->link;
				temp=j->link->link;
				prev->link=jlink;
				jlink->link=j;
				j->link=temp;

				if(j==head)
				  {
					head=jlink;
				  }
				j=jlink;
			  }
		  }
	  }
	return(head);
  }

		/* Function to insert new data */

NODE* insert(NODE *head)
  {
	NODE *curr,*temp;
	char ini;
	int flag=0;
	curr=(NODE*)malloc(sizeof(NODE));

	printf("\nEnter the IRoll No. : ");
	scanf("%d",&curr->id);
	printf("\nEnter the NAME: ");
	scanf("%s",curr->name);
	printf("\nEnter the NAME INITIALS: ");
	scanf("%s",curr->initials);
	printf("\nEnter the ADDRESS: ");
	scanf("%s",curr->add);
	printf("\nEnter the NUMBER: ");
	scanf("%s",curr->no);
	printf("\nEnter the DATE OF BIRTH: ");
	scanf("%d%d%d",&curr->date,&curr->month,&curr->year);
	curr->link=NULL;

	printf("\nAfter which name initial do you want to insert it? :");
	scanf("%s",ini);
	temp=head;

	while(temp!=NULL)
	  {
		if(strcmp(temp->initials,ini)==0)
		  {
			flag=1;
			break;
		  }
		else
			temp=temp->link;
	  }
	if(flag==1)
	  {
		curr->link=temp->link;
		temp->link=curr;
	  }
	else
	  {
		printf("\nNot found");
	  }
	return(head);
  }

		/* Function to delete a record */

NODE *del(NODE *head)
  {
	char ini[10];
	int flag=0;
	NODE *temp,*prev;

	printf("\nEnter the record initials to be deleted: ");
	scanf("%s",ini);
	temp=head;

	if(strcmp(head->initials,ini)==0)
	  {
		head=head->link;
		free(head);
	  }
	else
	  {
		while(temp!=NULL)
		  {
			if(strcmp(temp->initials,ini)==0)
			  {
				flag=1;
				break;
			  }
			prev=temp;
			temp=temp->link;
		  }
		if(flag==1)
		  {
			prev->link=temp->link;
			free(temp);
		  }
		else
			printf("\nNot found");
	  }
	return(head);
  }

		/*Function to modify a record */

NODE* modify(NODE *head)
  {
	NODE *temp;
	char ini[10],n_name[20],n_add[40],n_no[12];
	int n_date,n_month,n_year;
	long int n_id;
	int count=1,flag=0;

	printf("\nEnter the student initials for modification: ");
	scanf("%s",ini);
	temp=head;

	while(temp!=NULL)
	  {
		if(strcmp(temp->initials,ini)==0)
		  {
			printf("\nFound at position %d ",count);
			printf("\nEnter the Roll no. : : ");
			scanf("%d",&n_id);
			printf("Enter the name.: ");
			scanf("%s",n_name);
			printf("Enter the address: ");
			scanf("%s",n_add);
			printf("Enter the number: ");
			scanf("%s",n_no);
			printf("Enter the date of birth: ");
			scanf("%d %d %d",&n_date,&n_month,&n_year);
			temp->id=n_id;
			strcpy(temp->name,n_name);
			strcpy(temp->add,n_add);
			strcpy(temp->no,n_no);
			temp->date=n_date;
			temp->month=n_month;
			flag=1;
			break;
		  }
		temp=temp->link;
		count++;
	  }
	if(flag==0)
		printf("\nNot found");
	return(head);

  }

			/* MAIN FUNCTION */

void main()
  {
	NODE *head=NULL;
	int ch;
	clrscr();

	while(1)
	  {
		printf("\nMENU");
		printf("\n1.Create and Display\n2.Search\n3.Sort\n4.Insert");
		printf("\n5.Delete\n6.Modify\n7.Exit");
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		  {
			case 1:
				head=create(head);
				display(head);
				break;

			case 2:
				search(head);
				break;

			case 3:
				printf("\nAfter sorting");
				head=sort(head);
				display(head);
				break;

			case 4:
				head=insert(head);
				display(head);
				break;


			case 5:
				head=del(head);
				display(head);
				break;

			case 6:
				head=modify(head);
				display(head);
				break;

			case 7:
				exit(0);

			default:
				printf("\nEnter a valid choice");
		  }
		getch();
	  }
  }

/*  **********OUTPUT**********

MENU
1.Create and Display
2.Search
3.Sort
4.Insert
5.Delete
6.Modify
7.Exit
Enter your choice: 1

Enter the Roll no. : 11

Enter the NAME: Madhuvan

Enter the NAME INITIALS: M

Enter the ADDRESS: Nashik

Enter the NUMBER: 8087733458

Enter the DATE OF BIRTH: 28 08 1992
Do you want to add more nodes???: y

Enter the Roll no. : 1

Enter the NAME: Rupinder

Enter the NAME INITIALS: R

Enter the ADDRESS: Nashik

Enter the NUMBER: 9923386257

Enter the DATE OF BIRTH: 16 07 1992
Do you want to add more nodes???: y
Enter the Roll no. : 14

Enter the NAME: Aniruddha

Enter the NAME INITIALS: A

Enter the ADDRESS: Nashik

Enter the NUMBER: 9423954230

Enter the DATE OF BIRTH: 28 05 1988
Do you want to add more nodes???: n
ID      NAME    INITIALS        ADDRESS         NUMBER          DOB

11      Madhuvan        M       Nashik          8087733458      28-8-1992

1       Rupinder        R       Nashik          9923386257      16-7-1992

14      Aniruddha       A       Nashik          9423954230      28-5-1988

Enter your choice: 2
Enter the initials of the record to be searched: R
1       Rupinder        R       Nashik  9923386257      16 7 1992
Found at position 2

Enter your choice: 3

After sorting
ID      NAME    INITIALS        ADDRESS         NUMBER          DOB

1       Rupinder        R       Nashik          9923386257      16-7-1992

11      Madhuvan        M       Nashik          8087733458      28-8-1992

14      Aniruddha       A       Nashik          9423954230      28-5-1988

Enter your choice: 4

Enter the IRoll No. : 83

Enter the NAME: Mansi

Enter the NAME INITIALS: P

Enter the ADDRESS: Nashik

Enter the NUMBER: 9730139155

Enter the DATE OF BIRTH: 21 01 1992

After which name initial do you want to insert it? :A

ID      NAME    INITIALS        ADDRESS         NUMBER          DOB

1       Rupinder        R       Nashik          9923386257      16-7-1992

11      Madhuvan        M       Nashik          8087733458      28-8-1992

14      Aniruddha       A       Nashik          9423954230      28-5-1988

83      Mansi           P       Nashik          9730139155      21-1-1992

Enter your choice: 5

Enter the record initials to be deleted:  P

ID      NAME    INITIALS        ADDRESS         NUMBER          DOB

1       Rupinder        R       Nashik          9923386257      16-7-1992
11      Madhuvan        M       Nashik          8087733458      28-8-1992
14      Aniruddha       A       Nashik          9423954230      28-5-1988

Enter your choice: 6

Enter the student initials for modification: A

Found at position 3
Enter the Roll no. : : 14
Enter the name.: Andy
Enter the address: Jamner
Enter the number: 9423954230
Enter the date of birth: 28 05 1988

ID      NAME    INITIALS        ADDRESS         NUMBER          DOB

1       Rupinder        R       Nashik          9923386257      16-7-1992
11      Madhuvan        M       Nashik          8087733458      28-8-1992
14      Andy            A       Jamner          9423954230      28-5-1988

Enter your choice: 7

*/