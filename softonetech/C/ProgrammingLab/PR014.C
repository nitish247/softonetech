/*Programming Lab
Practical No. 14
Date 17 August 2011
Program to implement queue represented using circular linked list
and perform operations like insert, delete, print, front and rear element
SE(B)			Roll No. 03 */

#include<stdio.h>
#include<conio.h>

typedef struct node
{
	int data;
	struct node *next;
}node;
void init(node **R);
void enqueue(node **R,int x);
int dequeue(node **R);
int empty(node *rear);
void print(node *rear);
int front_element(node *rear);
int rear_element(node *rear);
void main()
{
 int x,option;
 int n = 0,i;
 node *rear;
 init(&rear);
 clrscr();
 do
   {
      printf("\n1. Insert\n2. Delete\n3. Print");
      printf("\n4. Front element\n5. Rear Element\n0. Quit");
      printf("\n Your Option:     ");
      scanf("%d",&option);
      switch(option)
	  {
	    case 1: printf("\nEnter queue data : ");
		    scanf("\n %d",&x);
		    enqueue(&rear,x);
		    break;
	    case 2 : if(! empty(rear))
			{
			  x=dequeue(&rear);
			  printf("\n Element deleted = %d",x);
			}
		     else
			  printf("\n Underflow..... Cannot deleted");
		     break;
	    case 3 : print(rear);
		     break;
	    case 4 :if(!empty(rear))
		       printf("\nFront Element = %d",front_element(rear));
		    else
		       printf("\nQueue is empty");
		    break;
	    case 5 :if(!empty(rear))
		       printf("\nRear Element = %d",rear_element(rear));
		    else
		       printf("\nQueue is empty");
		    break;
	 }
  }while(option!= 0);

 }

 void init(node **R)
    {
      *R = NULL;
    }

 void enqueue(node **R,int x)
    {
     node *p;
     p = (node *)malloc(sizeof(node));
     p->data = x;
     if(empty(*R))
	{
	  p->next = p;
	  *R = p;
	}
     else
       {
	  p->next = (*R)->next;
	  (*R)->next = p;
	  (*R) = p;
       }
    }

int dequeue(node **R)
  {
    int x;
    node *p;
    p=(*R)->next;
    x=p->data;
    if(p->next == p)
	 {
	     *R = NULL;
	     free(p);
	     return(x);
	 }
   (*R)->next = p->next;
   free(p);
   return(x);
 }

void print(node *rear)
  {
   node *p;
   if(!empty(rear))
      {
	  p = rear->next;
      }
   else
     {
       printf("\nQueue is empty");
       return;
     }

   printf("\n");
   do
     {
	printf("%d  ",p->data);
	p = p->next;
     }while(p != rear->next);
  }

int empty(node *P)
  {
	if(P->next== NULL)
		return(1);
	return(0);
  }

int front_element(node *rear)
  {
     return(rear->next->data);
  }

int rear_element(node *rear)
  {
     return(rear->data);
  }
/************************* OUTPUT **************************
1. Insert
2. Delete
3. Print
4. Front element
5. Rear Element
6. Quit
Your Option:     1

Enter queue data : 12

Your Option:     1

Enter queue data : 1

Your Option: 2

Element deleted = 12

Your Option:  3

1

Your Option:  4

Front Element = 1

Your Option:  5

Rear Element = 1

Your Option:  6
*/