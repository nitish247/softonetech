//Binary Tree

#include<mouse.h>
#include<iostream.h>

class node
{
	public:
		int data;
		int xc,yc,rad;
		node *left,*right;

		node()
		{
			left=right=NULL;
		}

};

class graphical_ui
{
	public:
		int drawnode(int *x,int *y,int ishead,int side,int toggle)
		{
			int data;
			int xb=*x,yb=*y;
			char msg[10];
			setcolor(BLACK);

			if(ishead==1)
			{
				circle(*x,*y,10);
				data=getintgraphics(*x-3,*y-3);
			}
			else
			{
				if(side==-1)
				{
					if(toggle==0)
					{
						line(*x,*y,*x-30,*y+20);
						*x=*x-30-8;
						*y=*y+20+8;
					}
					else
					{
						line(*x,*y,*x-10,*y+20);
						*x=*x-10-8;
						*y=*y+20+8;
					}
					circle(*x,*y,10);
					data=getintgraphics(*x-3,*y-3);
				}

				if(side==+1)
				{
					if(toggle==0)
					{
						line(*x,*y,*x+30,*y+20);
						*x=*x+30+8;
						*y=*y+20+8;
					}
					else
					{
						line(*x,*y,*x+10,*y+20);
						*x=*x+10+8;
						*y=*y+20+8;
					}
					circle(*x,*y,10);
					data=getintgraphics(*x-3,*y-3);
				}

				if(data==-1)
				{
					setcolor(LIGHTGRAY);
					setfillstyle(SOLID_FILL,LIGHTGRAY);
					bar(*x-10,*y-10,*x+20,*y+20);
					if(side==-1)
						line(*x+8,*y-8,xb,yb);
					else
						line(*x-8,*y-8,xb,yb);
				}
			}
			return data;
		}

	int getintgraphics(int x,int y)
	{
		char c,msg[2];
		do
		{
			c=getch();
		}while((c<='0'||c>='9')&&c!='/');
		sprintf(msg,"%c",c);
		outtextxy(x,y,msg);
		if(c!='/')
			return (c-48);
		else
			return -1;
	}
};

class btree:public graphical_ui
{
	node *root;
	public:
		tree()
		{
			root=NULL;
		}

		void create()
		{
			insertnode(&root,320,100,1,0,0);
		}

		void insertnode(node **n,int x,int y,int ishead,int side,int toggle)
		{
			int data;
			node *p;
			data=drawnode(&x,&y,ishead,side,toggle);
			if(data==-1)
			{
				*n=NULL;
				return;
			}
			p=new node;
			if(ishead==0)
				toggle=1;
			p->data=data;
			p->xc=x;
			p->yc=y;
			p->rad=10;
			*n=p;

			insertnode(&((*n)->left),x-8,y+8,0,-1,toggle);
			insertnode(&((*n)->right),x+8,y+8,0,+1,toggle);
		}

		void inorder()
		{
			inordertraversal(root);
		}

		void inordertraversal(node *p)
		{
			if(p!=NULL)
			{
				inordertraversal(p->left);
				printf("%d\n",p->data);
				inordertraversal(p->right);
			}

		}
};

void main()
{
	int choice;
	int gd=DETECT,gm;
	btree t1;
	initgraph(&gd,&gm,"C:\\TC\\BGI");
	setfillstyle(SOLID_FILL,LIGHTGRAY);
	bar(0,0,640,480);
	t1.create();
	t1.inorder();
}