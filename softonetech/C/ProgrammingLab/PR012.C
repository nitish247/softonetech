/*Programming Lab
Practical No. 12
Date 13 October 2011
Create to singly linked lists, sort one after creation and one while creation.
Using pointer manipulation, merge these two lists into one list without
crating a new node or swapping of the data
SE(B)			Roll No. 03
Nitish R. Muley*/


#include<stdio.h>
#include<conio.h>

struct node* create_normal();
struct node* create_sorted();
void print(struct node *temp);
void sort(struct node *head);
struct node* merge(struct node *l1,struct node *l2);

struct node
{
	int data;
	struct node *next;
};

void main()
{
	int choice;
	struct node *head1,*head2,*head3;
	clrscr();
	printf("\nCreating Normal Linked List...");
	head1=create_normal();
	printf("\nCreating Sorted Linked List...");
	head2=create_sorted();
	printf("\nFirst Linked List (Before Sorting):");
	print(head1);
	getch();
	sort(head1);
	printf("\nFirst Linked List (After Sorting):");
	print(head1);
	getch();
	printf("\nSecond Linked List:");
	print(head2);
	getch();
	head3=merge(head1,head2);
	printf("\nFinal Linked List (Merged):");
	print(head3);
	getch();
}

struct node* create_normal()
{
	int i,n,data;
	struct node *head,*temp;
	printf("\nEnter the number of elements: ");
	scanf("%d",&n);
	temp=NULL;
	for(i=1;i<=n;i++)
	{
		printf("Enter the element %d: ",i);
		scanf("%d",&data);
		if(temp==NULL)
		{
			head=temp=(struct node*)malloc(sizeof(struct node));
			temp->next=NULL;
		}
		else
		{
			temp->next=(struct node*)malloc(sizeof(struct node));
			temp=temp->next;
			temp->next=NULL;
		}
		temp->data=data;
	}
	return head;
}

struct node* create_sorted()
{
	struct node *head=NULL,*p,*q;
	int n,i,data;
	printf("\nEnter the number of elements: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		p=(struct node*)malloc(sizeof(struct node));
		printf("Enter the element %d: ",i);
		scanf("%d",&data);
		p->data=data;
		p->next=NULL;

		if(head==NULL||data<head->data)
		{
			p->next=head;
			head=p;
		}
		else
		{
			q=head;
			while(q->next!=NULL && data>q->next->data)
				q=q->next;
			p->next=q->next;
			q->next=p;
		}
	}
	return (head);
}

void print(struct node *temp)
{
	while(temp!=NULL)
	{
		printf("\n%d",temp->data);
		temp=temp->next;
	}
}

void sort(struct node *head)
{
	int i,j,n;
	struct node *p;

	for(n=0,p=head;p!=NULL;p=p->next)
		n++;
	for(i=1;i<n;i++)
	{
		p=head;
		for(j=0;j<n-i;j++)
		{
			if(p->data>p->next->data)
			{
				p->data=p->data^p->next->data;
				p->next->data=p->data^p->next->data;
				p->data=p->data^p->next->data;
			}
			p=p->next;
		}
	}
}

struct node* merge(struct node *l1,struct node *l2)
{
	struct node *l,*p;
	l=NULL;

	while(l1!=NULL && l2!=NULL)
	{
		if(l1->data<l2->data)
		{
			if(l==NULL)
			{
				l=p=l1;
				l1=l1->next;
			}
			else
			{
				p->next=l1;
				l1=l1->next;
				p=p->next;
			}
		}
		else
		{
			if(l==NULL)
			{
				l=p=l2;
				l2=l2->next;
			}
			else
			{
				p->next=l2;
				l2=l2->next;
				p=p->next;
			}
		}
	}

	if(l1!=NULL)
	{
		if(l==NULL)
			l=l1;
		else
			p->next=l1;
	}

	if(l2!=NULL)
	{
		if(l==NULL)
			l=l2;
		else
			p->next=l2;
	}
	return(l);
}