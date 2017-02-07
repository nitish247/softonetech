/*
Pineapple HitBall
"OpenSource" VGA Game from Pineapple Software
Properly Documented C++ Source Code

Contact Us:
E-mail: softonetech@yahoo.com
Facebook Page: www.facebook.com/softonetech

Join With Us (Share your Ideas and Innovations):
Phone: +91-9028967081
*/

#include<graphics.h>
#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>

//Defining Boundaries of Active Window
#define MINX 10
#define MINY 10
#define MAXX 500
#define MAXY 450
#define SPEED 4

struct brick	//Structure for Bricks
{
		int x,y;
		int width,height;
		int color;
		int hit;	//Specifies the hits for cracking a brick (Default=1)
		int number;	//Number of Brick
		int power;	//Non-zero value specifies the Hidden Power that brick contains, Zero for normal brick
		brick *link;	//Pointer to next brick
};

struct powers	//Structure for Powers
{
		int x,y;
		int width,height;
		int color;
		int powindex;	//Specifies Index of Index Power
		/*
		powindex
		1=Increases the size of stick
		2=Loses a life
		3=Reverse Power (by Pressing Enter key)
		4=1-Up
		*/
		char *buff;	//Buffer for restoring screen image while sliding down (used to restore the background)
		powers *next;
};

brick *set=NULL;	//Pointer to the first brick
void updatescore(int score);
void updatechances(int chance);
void drawbricks(int xc,int yc,int row,int col,int width,int height,int color);
void statusmsg(char *msg);

void main()
{
	/*
		*************** Data Dictionary ***************
		x = x-coordinate of Ball
		y = y-coordinate of Ball
		xdir = x-Direction of Ball (Either -1 or +1)
		ydir = y-Direction of Ball (Either -1 or +1)
		barx = x-Coordinate of Stick
		bary = y-Coordinate of Stick
		barsize = Size of Stick
		reversepow = Flag for Reverse Power Activation
		chance = Number of Chances
		lost = Flag for Lost Condition (Either 0 or 1)
		finish = Flag for Level Finish Condition (Either 0 or 1)
		powdnactive = Flag for Power Scrolling Down condition
		imgsize = For storing size of image on screen whenever required
		ch = for reading a character or key

		Pointers:
		*p = Temporary Pointer for Traversing Bricks List
		*pr = Temporrary Pointer for Pointing to the Previous Brick

		*pow = Pointer to First Power among those which are sliding down
		*powp = Temporary Pointer to Create Powers
		*powi = Temporary Pointer for Traversing Powers List
		*powcatched = Temporary Pointer to Access the Catched Power by Stick
		*powprev = Temporary Pointer to previous power while traversing
	*/

	int gd=DETECT,gm;
	int x,y,r=5,xdir=1,ydir=1,barx=220,bary=420,barsize=80,reversepow=0,chance=2;
	int lost=0,finish=0,score=0,powdnactive=0,imgsize;
	int ch;
	REGS in,out;

	brick *p,*pr;
	powers *pow=NULL,*powp,*powi,*powcatched,*powprev;

	initgraph(&gd,&gm,"");      //Initializes VGA Graphics Mode
	setfillstyle(SOLID_FILL,BLACK);	       //Sets the Black background
	bar(0,0,640,480);
	outtextxy(510,30,"HitBall (VGA)");
	outtextxy(10,460,"Pineapple Software");
	updatescore(score);	//Updates Score on Right Side of screen
	drawbricks(150,70,5,6,35,20,MAGENTA);	//Draws the Matrix of Bricks
	//drawbricks(initial_x, initial_y,rows, columns, width_of_each_brick, height_of_each_brick, color_of_normal_bricks)


	setcolor(WHITE);
	setfillstyle(SOLID_FILL,DARKGRAY);  	//Draws Stick
	bar(barx,bary,barx+barsize,bary+10);
	rectangle(barx,bary,barx+barsize,bary+10);

	rectangle(MINX,MINY,MAXX,MAXY);	//Draws the active window

	START:		//Begin
	x=barx+barsize/2;
	y=410-r;
	updatechances(chance);
	setcolor(WHITE);
	setfillstyle(SOLID_FILL,RED);	//Draws Ball
	circle(x,y,r);
	floodfill(x,y,WHITE);
	statusmsg("Hit Enter Key");	//Updates Status Message at the right side of screen
	while(getch()!='\r');		//Waits for "Enter" Key
	statusmsg("Left, Right");



	while(1)	//Start the emulation
	{
		if(kbhit())		//Checks whether any keystrokes is presents
		{
			in.h.ah=0;
			int86(22,&in,&out);
			ch=out.h.ah;

			if(ch==1)	//Quit condition
			{
				closegraph();
				exit(0);
			}
			if(ch==28&&reversepow==1)	//Reverses the motion of ball if Reverse Power is Present
			{
				xdir*=-1;
				ydir*=-1;
			}

			if(ch==75)	//Shifts bar towards right
			{
				setfillstyle(SOLID_FILL,BLACK);
				bar(barx,bary,barx+barsize,bary+10);
				if(barx-10>MINX)
					barx-=10;

				setfillstyle(SOLID_FILL,DARKGRAY);
				bar(barx,bary,barx+barsize,bary+10);
				setcolor(WHITE);
				rectangle(barx,bary,barx+barsize,bary+10);
			 }

			if(ch==77)	//Shifts bar towards left
			{
				setfillstyle(SOLID_FILL,BLACK);
				bar(barx,bary,barx+barsize,bary+10);
				if(barx+barsize+10<MAXX)
					barx+=10;
				setfillstyle(SOLID_FILL,DARKGRAY);
				bar(barx,bary,barx+barsize,bary+10);
				setcolor(WHITE);
				rectangle(barx,bary,barx+barsize,bary+10);
			}
		}

		setfillstyle(SOLID_FILL,BLACK);
		floodfill(x,y,WHITE);          //Clears the Previous Position of Ball
		setcolor(BLACK);
		circle(x,y,r);

		if((x>=MAXX-r-1)||x<=r+MINX+1)	//Boundary Coditions (X) to Rebounce the Ball
			xdir*=-1;

		if(y<=r+MINY+1)		//Boundary Codition (+Y) to Rebounce the Ball
			ydir*=-1;
		else
		if((y>=bary-r-1)||y<=r)         //Boundary Condition (-Y)
			if(x>=barx&&x<=barx+barsize)	//Checks whether Stick is present below the Ball
			{
				ydir*=-1;
			}

			if(y>=MAXY-r-1)		//Checks if Ball Crosses the Stick (Lost Condition)
			{
				lost=1;
				break;
			}

			for(p=set;p!=NULL;p=p->link)		//Checks whether the Ball hits any brick
			{
				if((x+r+1>=p->x&&x-r-1<=p->x+p->width)&&(y+r+1>=p->y&&y-r-1<=p->y+p->height))
				{
					if((x+r+1==p->x)||(x-r-1==p->x+p->width))	//Rebounce the ball in reverse direction
					{
						xdir*=-1;
					}

					if((y+r+1==p->y)||(y-r-1==p->y+p->height))
					{
						ydir*=-1;
					}

					if(p->hit==1)	//For single-hit bricks
					{
						setfillstyle(SOLID_FILL,BLACK);		//Clears the graphical existance of brick (still the brick is present within memory)
						bar(p->x,p->y,p->x+p->width,p->y+p->height);
						if(p!=set)	//If hit brick is head node of bricks linked list, then assign the position of head to its next node
							pr->link=p->link;
						else
							set=p->link;

						if(p->power!=0)	     //Checks if any hidden power is present in brick
						{
							powp=new powers;
							powp->x=p->x;
							powp->y=p->y+p->height;
							powp->width=p->width;	       //Sets the new power node
							powp->height=p->height;
							powp->powindex=p->power;
							powp->buff=NULL;
							if(p->power==1)		       //Assigns various colors to powers
								powp->color=BLUE;
							if(p->power==2)
								powp->color=RED;
							if(p->power==3)
								powp->color=CYAN;
							if(p->power==4)
								powp->color=GREEN;

							powp->next=NULL;

							//Adds the new power to powers linked list
							if(pow==NULL)	//If powers linked list is empty
							{
								pow=powp;
							}
							else
							{
								for(powi=pow;powi->next!=NULL;powi=powi->next);
								powi->next=powp;
							}
							setfillstyle(SOLID_FILL,BLACK);                 //Erases the brick
							bar(p->x,p->y,p->x+p->width,p->y+p->height);
							powdnactive=1;		//Sets the Power Sliding Down flag active
						}
						delete p;	//Physically deletes the hit brick from memory
					}

					else	//Condition for Multihit Bricks
					{
						if(p->hit==2)
						{
							setfillstyle(SOLID_FILL,LIGHTGRAY);
							bar(p->x,p->y,p->x+p->width,p->y+p->height);
							p->color=LIGHTGRAY;
							setcolor(WHITE);
							rectangle(p->x,p->y,p->x+p->width,p->y+p->height);
						}
						p->hit--;
					}
					score+=10;	//Adds 10 to score for each hit
					updatescore(score);	//Updates score onto screen
					break;
				}
				pr=p;	//Backups current node as previous node
			}

			if(y>480)	//Checks whether the ball is lost
			{
				lost=1;
				break;
			}

			if(set==NULL)		//If all bricks are hit, this condition finishes the game
			{
				finish=1;
				break;
			}
			x+=xdir;	//New x-coordinate for ball
			y+=ydir;	//New y-coordinate for ball

			if(powdnactive==1)	//Checks whether Power Sliding Down Flag is active
			{
				for(powi=pow;powi!=NULL;powi=powi->next)
				{
					putimage(powi->x,powi->y,powi->buff,COPY_PUT);	//Restores the previous image onto screen which was overdrawn by Sliding Power
					powi->y+=2;

					if(((powi->y+powi->height+1)>bary)&&(powi->x+powi->width>=barx)&&(powi->x+powi->width<=barx+barsize))
					{	//Checks whether the Stick catches the Power
						powcatched=powi;
						if(powi==pow)
							pow=powi->next;
						else
							powprev->next=powi->next;

						delete powi;	//Deletes the Catched power from memory
						if(pow==NULL)	//If there is no Power Sliding Down
							powdnactive=0;
						if(powcatched->powindex==1)	//Condition for Power Index = 1 (Increase the Stick Length by 20)
						{
							barsize+=20;
							score+=100;
							updatescore(score);
						}

						if(powcatched->powindex==2)	//Condition for Power Index = 2 (Danger, loses one life)
						{
							setcolor(WHITE);
							setfillstyle(SOLID_FILL,BLACK);
							circle(x,y,r);
							floodfill(x,y,WHITE);
							setcolor(BLACK);
							circle(x,y,r);
							setcolor(WHITE);

							lost=1;
							break;
						}

						if(powcatched->powindex==3)	//Condition for Power Index = 3 (Activates Reverse power)
						{
							reversepow=1;
						}

						if(powcatched->powindex==4)	//Condition for Power Index = 4 (1-Up!)
						{
							chance++;
							updatechances(chance);
						}
						continue;
					}
					if(powi->y+powi->height>MAXY-4)		//If power crosses the stick, delete the power from memory
					{
						if(powi==pow)
							pow=powi->next;
						else
							powprev->next=powi->next;
						delete powi;
						if(pow==NULL)
							powdnactive=0;
						continue;
					}

					//Saves the background fragment bitmap to memory, so as to restore it next time
					imgsize=imagesize(powi->x,powi->y,powi->x+powi->width,powi->y+powi->height);

					free(powi->buff);	//frees the previously allocated bitmap
					powi->buff=(char*)malloc(imgsize);
					getimage(powi->x,powi->y,powi->x+powi->width,powi->y+powi->height,powi->buff);

					//Draws Power to screen
					setfillstyle(SOLID_FILL,powi->color);
					bar(powi->x,powi->y,powi->x+powi->width,powi->y+powi->height);
					setcolor(WHITE);
					rectangle(powi->x,powi->y,powi->x+powi->width,powi->y+powi->height);
					powprev=powi;
				}
			}

			if(lost==1)
				break;
			setcolor(WHITE);

			setfillstyle(SOLID_FILL,RED);
			circle(x,y,r);		//Draws Ball to new position
			floodfill(x,y,WHITE);
			delay(SPEED);
		}
	fflush(stdin);
	setcolor(WHITE);

	if(lost==1)
	{
		if(chance!=0)	       //Checks whether the Chance is there
		{
			lost=0;
			chance--;
			goto START;	//Restarts the program
		}
		else
			statusmsg("Game Over");		//Game Over condition if chance=0
	}

	if(finish==1)	//Finish flag
	{
		statusmsg("Level Cleared!");
	}
	getch();
	closegraph();	//Closes the graphics screen
}

//Function for drawing bricks to graphics screen
void drawbricks(int xc,int yc,int row,int col,int width,int height,int color)
{
		int i,j,x,y,n=1;
		brick *p,*q;
		y=yc;
		for(i=1;i<=row;i++)
		{
				x=xc;
				for(j=1;j<=col;j++)
				{
						p=new brick;
						p->x=x;
						p->y=y;		//Allocates each brick as the new node of linked list in memory
						p->width=width;
						p->height=height;
						p->color=color;

						//Assigning conditions for Hit indexes
						if(n%4==0)
						{
							p->hit=2;
							p->color=DARKGRAY;
						}
						else
							p->hit=1;

						//Assigning conditions for hidden Powers
						if(n%7==0)
							p->power=1;
						else
						if(n%15==0)
							p->power=2;
						else
						if(n==5)
							p->power=3;
						else
						if(n==11)
							p->power=4;
						else
							p->power=0;

						p->number=n++;
						p->link=NULL;

						setfillstyle(SOLID_FILL,p->color);
						bar(p->x,p->y,p->x+p->width,p->y+p->height);
						setcolor(WHITE);
						rectangle(p->x,p->y,p->x+p->width,p->y+p->height);



						if(set==NULL)
							set=p;
						else
						{
							for(q=set;q->link!=NULL;q=q->link);
							q->link=p;
						}
						x+=width+1;
				}
				y+=height+1;
		}
}

//Function for updating score on screen
void updatescore(int score)
{
	char scoremsg[20];
	sprintf(scoremsg,"Score: %d",score);
	setfillstyle(SOLID_FILL,BLACK);
	bar(540,200,540+textwidth(scoremsg),200+textheight(scoremsg));
	setcolor(WHITE);
	outtextxy(510,200,scoremsg);
}

//Updates 'Chances' on screen
void updatechances(int chance)
{
	int i,x=530,y=250;
	for(i=1;i<=4;i++)
	{
		if(i<=chance)
		{
			setcolor(WHITE);
			setfillstyle(SOLID_FILL,RED);
			circle(x,y,10);
			floodfill(x,y,WHITE);
			x+=30;
		}
		else
		{
			setcolor(WHITE);
			setfillstyle(SOLID_FILL,BLACK);
			circle(x,y,10);
			floodfill(x,y,WHITE);
			setcolor(BLACK);
			circle(x,y,10);
			x+=30;
		}
	}
}

//Updates status message
void statusmsg(char *msg)
{
	setfillstyle(SOLID_FILL,BLACK);
	bar(505,400,640,410);
	setcolor(WHITE);
	outtextxy(510,400,msg);
}

/*
(C) 2012, Pineapple Software @ SoftOne Tech
Modify, Share, Redistribute
*/