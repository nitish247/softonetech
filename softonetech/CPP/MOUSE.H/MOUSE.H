/*
Pineapple Software
MOUSE.H - Application Programming Interface
Collection of Standard Methods and Classes to Create a GUI Application
through C++
OpenSource Project by Pineapple Software

Last Updated: 3 April 2012

GUI Components:
1. Command Buttons
2. Text Boxes
3. Labels
4. Radio Buttons
5. Check Boxes
6. List Boxes
7. Combo Boxes
8. Menus
9. Forms
10. Message Boxes
*/

#include<iostream.h>
#include<graphics.h>
#include<string.h>
#include<dos.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<stdarg.h>

enum componentName { Button, TextBox, label, radio, CheckBox, ListBox, ComboBox, ComboItem, menu, compoGrp, MessageBox, Nothing };
enum typeMsgBox { OK, OKCancel};
enum formTheme { Plain, Frame, Window };
int menuCount=0;
void _stopapp();

class Mouse
{
	private:
	REGS in,out;


	struct mouseStatus
	{
		int x,y,but;
	};

	public:
	void initMouse()
	{
		in.x.ax=0;
		int86(0x33,&in,&out);
	}

	void showMousePtr()
	{
		in.x.ax=1;
		int86(0x33,&in,&out);
	}

	void hideMousePtr()
	{
		in.x.ax=2;
		int86(0x33,&in,&out);
	}

	mouseStatus* getMousePos()
	{
		mouseStatus *temp;
		temp=new mouseStatus;

		in.x.ax=3;
		int86(0x33,&in,&out);

		temp->but=out.x.bx;
		temp->x=out.x.cx;
		temp->y=out.x.dx;
		return temp;
	}
};

char *_buff[15000];
int _isize;
int _xi,_yi;

class imageControl
{
	protected:
	void saveImage(int xc1,int yc1,int xc2,int yc2)
	{
		_xi=xc1;
		_yi=yc1;
		_isize=imagesize(xc1,yc1,xc2,yc2);
		if(_isize<20000)
			getimage(xc1,yc1,xc2,yc2,_buff);
		_isize;
	}

	void restoreImage()
	{
		if(_isize<20000)
			putimage(_xi,_yi,_buff,COPY_PUT);
	}
};

void donothing()
{

}

class Label:private Mouse
{
	private:
	int x1,y1;
	int x2,y2;
	int bkColor;
	int txtColor;
	int borderColor;
	int size;
	int active;
	char *text;
	char *defaultText;
	void(*actionfun)();
	friend Application;
	friend Form;
	friend msgBox;

	public:
	Label()
	{

	}

	Label(int xc,int yc,int sz,char* txt)
	{
		size=sz;
		bkColor=LIGHTGRAY;
		txtColor=BLACK;
		borderColor=LIGHTGRAY;
		text=new char[sz+1];
		defaultText=new char[sz+1];
		strncpy(defaultText,txt,size);
		strncpy(text,txt,size);
		x1=xc;
		y1=yc;
		x2=x1+size*7+5;
		y2=y1+textheight("A")+8;
		actionfun=&donothing;
		active=1;
	}

	Label(int xc,int yc,int sz,char *txt,int txtclr,int brdrclr,int bkclr)
	{
		size=sz;
		bkColor=bkclr;
		txtColor=txtclr;
		borderColor=brdrclr;
		text=new char[sz+1];
		defaultText=new char[sz+1];
		strncpy(defaultText,txt,size);
		strncpy(text,txt,size);
		x1=xc;
		y1=yc;
		x2=x1+size*7+5;
		y2=y1+textheight("A")+8;
		actionfun=&donothing;
		active=1;
	}

	void setAction(void(*actionpara)())
	{
		actionfun=actionpara;
	}

	void setText(char *txt)
	{
		strncpy(text,txt,size);
		this->display();
	}

	char* getText(char *txt)
	{
		strcpy(txt,text);
	}

	int isEmpty()
	{
		if(text=='\0')
			return 1;
		else
			return 0;
	}

	int getLength()
	{
		return (strlen(text));
	}

	void makeActive()
	{
		hideMousePtr();
		erase();
		txtColor=WHITE;
		active=1;
		display();
		showMousePtr();
	}

	void makeInactive()
	{
		hideMousePtr();
		erase();
		txtColor=LIGHTGRAY;
		active=0;
		display();
		showMousePtr();
	}


	protected:
	void display()
	{
		setfillstyle(SOLID_FILL,bkColor);
		bar(x1,y1,x2,y2);
		setcolor(borderColor);
		rectangle(x1,y1,x2,y2);
		setcolor(txtColor);
		outtextxy(x1+3,y1+3,text);
	}

	void erase()
	{
		setfillstyle(SOLID_FILL,LIGHTGRAY);
		bar(x1,y1,x2,y2);
	}

	void reset()
	{
		active=1;
		strcpy(text,defaultText);
	}
};

class cmdButton:public Mouse
{
	private:
	int x1,y1;
	int x2,y2;
	int active;
	int bkColor;
	int txtColor;

	char caption[30];
	friend Application;
	friend Form;
	friend msgBox;
	void(*actionfun)();

	public:
	cmdButton()
	{

	}

	cmdButton(int xc,int yc,char *cap)
	{
		x1=xc;
		y1=yc;
		active=1;
		bkColor=DARKGRAY;
		txtColor=BLACK;
		strcpy(caption,cap);
		x1=xc;
		y1=yc;
		x2=x1+textwidth(cap)+5;
		y2=y1+textheight(cap)+6;
		actionfun=&donothing;
		active=1;
	}

	cmdButton(int xc,int yc,char *cap,int activeStatus,int bkcol=DARKGRAY,int txtcol=BLACK)
	{
		x1=xc;
		y1=yc;
		active=activeStatus;
		bkColor=bkcol;
		txtColor=txtcol;
		strcpy(caption,cap);
		x1=xc;
		y1=yc;
		x2=x1+textwidth(cap)+5;
		y2=y1+textheight(cap)+6;
		actionfun=&donothing;
		active=1;
	}

	void makeActive()
	{
		hideMousePtr();
		erase();
		txtColor=BLACK;
		active=1;
		display();
		showMousePtr();
	}

	void makeInactive()
	{
		hideMousePtr();
		erase();
		txtColor=LIGHTGRAY;
		active=0;
		display();
		showMousePtr();
	}

	void setAction(void(*actionpara)())
	{
		actionfun=actionpara;
	}

	protected:
	void display()
	{
		setfillstyle(SOLID_FILL,bkColor);
		setcolor(BLACK);
		bar(x1+2,y1+2,x2+2,y2+2);
		rectangle(x1+2,y1+2,x2+2,y2+2);
		bar(x1,y1,x2,y2);
		rectangle(x1,y1,x2,y2);
		setcolor(txtColor);
		outtextxy(x1+3,y1+3,caption);
	}

	void erase()
	{
		setfillstyle(SOLID_FILL,LIGHTGRAY);
		bar(x1,y1,x2+2,y2+2);
	}

	void reset()
	{
		active=1;
	}

	void pulldown()
	{
		hideMousePtr();
		setfillstyle(SOLID_FILL,bkColor);
		setcolor(BLACK);
		bar(x1+2,y1+2,x2+2,y2+2);
		rectangle(x1+2,y1+2,x2+2,y2+2);
		setcolor(txtColor);
		outtextxy(x1+5,y1+5,caption);
		showMousePtr();
	}

	void pullup()
	{
		setfillstyle(SOLID_FILL,DARKGRAY);
		setcolor(BLACK);
		bar(x1+2,y1+2,x2+2,y2+2);
		rectangle(x1+2,y1+2,x2+2,y2+2);
		bar(x1,y1,x2,y2);
		rectangle(x1,y1,x2,y2);
		setcolor(txtColor);
		outtextxy(x1+3,y1+3,caption);
	}

	void redraw()
	{
		hideMousePtr();
		setfillstyle(SOLID_FILL,bkColor);
		setcolor(BLACK);
		bar(x1+2,y1+2,x2+2,y2+2);
		rectangle(x1+2,y1+2,x2+2,y2+2);
		bar(x1,y1,x2,y2);
		rectangle(x1,y1,x2,y2);
		setcolor(txtColor);
		outtextxy(x1+3,y1+3,caption);
		showMousePtr();
	}
};

class Radio:private Mouse
{
	private:
	int x1,y1;
	int x2,y2;
	int status;
	int txtColor;
	char caption[30];
	void(*actionfun)();
	Radio *next;
	int active;
	friend Application;
	friend Form;
	friend radioGroup;

	public:
	Radio()
	{

	}

	Radio(int xc,int yc,char *cap)
	{
		x1=xc;
		y1=yc;
		status=0;
		txtColor=BLACK;
		strcpy(caption,cap);
		x1=xc;
		y1=yc;
		x2=x1+textwidth(cap)+5+10;
		y2=y1+textheight(cap)+6;
		next=NULL;
		actionfun=&donothing;
		active=1;
	}

	void setAction(void(*actionpara)())
	{
		actionfun=actionpara;
	}

	void unset()
	{
		status=0;
		display();
	}

	void set()
	{
		status=1;
		display();
	}

	int getStatus()
	{
		return status;
	}

	void makeActive()
	{
		hideMousePtr();
		erase();
		txtColor=BLACK;
		active=1;
		display();
		showMousePtr();
	}

	void makeInactive()
	{
		hideMousePtr();
		erase();
		txtColor=DARKGRAY;
		active=0;
		display();
		showMousePtr();
	}


	protected:
	void display()
	{
		setfillstyle(SOLID_FILL,LIGHTGRAY);
		setcolor(BLACK);
		bar(x1,y1,x2,y2);
		setcolor(txtColor);
		circle(x1+5,y1+5,5);
		circle(x1+5,y1+5,3);
		if(status==1)
			setfillstyle(SOLID_FILL,GREEN);
		else
			setfillstyle(SOLID_FILL,LIGHTGRAY);
		floodfill(x1+5,y1+5,txtColor);
		outtextxy(x1+15,y1+3,caption);
	}

	void erase()
	{
		setfillstyle(SOLID_FILL,LIGHTGRAY);
		bar(x1,y1,x2,y2);
	}

	void reset()
	{
		active=1;
	}
};

class radioGroup
{
	private:
	Radio *radioSet,*activeRadio;
	friend Application;
	friend Form;

	public:
	radioGroup()
	{
		radioSet=new Radio;
		radioSet->next=NULL;
		activeRadio=NULL;
	}

	void add(Radio *rad);
	void display();
	void set();
	void setActive(Radio *rad);

	protected:
	void reset()
	{
		setActive(radioSet->next);
	}
};

void radioGroup::add(Radio *rad)
{
	Radio *i,*temp;

	for(i=radioSet;i->next!=NULL;i=i->next);
	temp=rad;

	if(radioSet->next==NULL)
		activeRadio=rad;

	if(rad->status==1)
		activeRadio=rad;
	i->next=temp;
}

void radioGroup::display()
{
	Radio *i;
	for(i=radioSet->next;i!=NULL;i=i->next)
		i->display();
}

void radioGroup::setActive(Radio *rad)
{
	activeRadio=rad;
	set();
}

void radioGroup::set()
{
	Radio *i;
	for(i=radioSet->next;i!=NULL;i=i->next)
	{
		if(i!=activeRadio)
			i->unset();
		else
			i->set();
	}
}

class checkBox:private Mouse
{
	private:
	int x1,y1;
	int x2,y2;
	int status;
	int defaultStatus;
	int txtColor;
	char caption[30];
	void(*actionfun)();
	int active;
	friend Application;
	friend Form;

	public:
	checkBox()
	{

	}

	checkBox(int xc,int yc,char *cap)
	{
		x1=xc;
		y1=yc;
		status=0;
		txtColor=BLACK;
		strcpy(caption,cap);
		x1=xc;
		y1=yc;
		x2=x1+textwidth(cap)+5+10;
		y2=y1+textheight(cap)+6;
		actionfun=&donothing;
		active=1;
	}

	checkBox(int xc,int yc,char *cap,int sta)
	{
		x1=xc;
		y1=yc;
		status=sta;
		defaultStatus=sta;
		txtColor=BLACK;
		strcpy(caption,cap);
		x1=xc;
		y1=yc;
		x2=x1+textwidth(cap)+5+30;
		y2=y1+textheight(cap)+6;
		actionfun=&donothing;
		active=1;
	}

	void setAction(void(*actionpara)())
	{
		actionfun=actionpara;
	}

	void toggle()
	{
		if(status==0)
			status=1;
		else
			status=0;
		display();
	}

	int getStatus()
	{
		return status;
	}

	void makeActive()
	{
		hideMousePtr();
		erase();
		txtColor=BLACK;
		active=1;
		display();
		showMousePtr();
	}

	void makeInactive()
	{
		hideMousePtr();
		erase();
		txtColor=DARKGRAY;
		active=0;
		display();
		showMousePtr();
	}


	protected:
	void display()
	{
		setfillstyle(SOLID_FILL,LIGHTGRAY);
		setcolor(BLACK);
		bar(x1,y1,x2,y2);
		setcolor(txtColor);
		rectangle(x1+2,y1+2,x1+10,y1+10);
		if(status==1)
		{
			setcolor(txtColor);
			line(x1+2,y1+2,x1+10,y1+10);
			line(x1+10,y1+2,x1+2,y1+10);
		}
		else
		{
			setcolor(LIGHTGRAY);
			line(x1+2,y1+2,x1+10,y1+10);
			line(x1+10,y1+2,x1+2,y1+10);
		}
		setcolor(txtColor);
		outtextxy(x1+15,y1+3,caption);
	}

	void erase()
	{
		setfillstyle(SOLID_FILL,LIGHTGRAY);
		bar(x1,y1,x2,y2);
	}

	void reset()
	{
		active=1;
		status=defaultStatus;
	}
};

class listItem:private Mouse
{
	private:
	int x1,y1;
	int x2,y2;
	int status;
	char caption[30];
	int txtColor;
	int bkColor;
	int brdrColor;
	int activeColor;
	int active;
	int allocated;
	listItem *next;
	void(*actionfun)();

	friend Application;
	friend Form;
	friend listBox;
	friend comboBox;
	friend Menu;

	public:
	int index;
	listItem()
	{
		status=0;
		txtColor=BLACK;
		brdrColor=WHITE;
		next=NULL;
		activeColor=BLUE;
		actionfun=&donothing;
		active=1;
		allocated=0;
	}

	listItem(char *cap)
	{
		status=0;
		txtColor=BLACK;
		brdrColor=WHITE;
		strcpy(caption,cap);
		next=NULL;
		activeColor=BLUE;
		actionfun=&donothing;
		active=1;
		allocated=1;
	}

	void setAction(void(*actionpara)())
	{
		actionfun=actionpara;
	}

	void unset()
	{
		status=0;
		display();
	}

	void set()
	{
		status=1;
		display();
	}

	int getStatus()
	{
		return status;
	}

	void makeActive()	//only for Menus
	{
		bkColor=LIGHTGRAY;
		active=1;
	}

	void makeInactive()	//only for Menus
	{
		bkColor=DARKGRAY;
		active=0;
	}


	protected:
	void display()
	{
		if(status==0)
			setfillstyle(SOLID_FILL,bkColor);
		else
			setfillstyle(SOLID_FILL,activeColor);

		bar(x1,y1,x2,y2);
		setcolor(brdrColor);
		rectangle(x1,y1,x2,y2);

		if(status==0)
			setcolor(BLACK);
		else
			setcolor(WHITE);
		outtextxy(x1+3,y1+3,caption);
	}

	void erase()
	{
		setfillstyle(SOLID_FILL,LIGHTGRAY);
		bar(x1,y1,x2,y2);
	}
};

listItem g_liset[100];
int g_liset_cnt=0;

class listBox:private Mouse
{
	private:
	int x1,y1;
	int x2,y2;
	int maxwid;
	int count;
	int listIndex;
	int active;
	int displayed;
	listItem *listItemSet;
	void(*actionfun)();
	friend Application;
	friend Form;

	public:
	listItem *activeListItem;
	listBox(int xc,int yc)
	{
		x1=xc;
		y1=yc;
		x2=xc;
		y2=yc;
		count=0;
		listItemSet=new listItem;
		listItemSet->next=NULL;
		activeListItem=NULL;
		actionfun=&donothing;
		displayed=0;
	}

	void setAction(void(*actionpara)())
	{
		actionfun=actionpara;
	}

	listItem* getActive()
	{
		return activeListItem;
	}

	void setActive(listItem *lst)
	{
		activeListItem=lst;
		set();
	}

	void makeActive()
	{
		hideMousePtr();
		activeListItem->erase();
		activeListItem->activeColor=BLUE;
		activeListItem->activeColor=BLUE;
		activeListItem->display();
		active=1;
		showMousePtr();
	}

	void makeInactive()
	{
		hideMousePtr();
		activeListItem->erase();
		activeListItem->activeColor=DARKGRAY;
		activeListItem->display();
		active=0;
		showMousePtr();
	}

	void add(char *item);
	void clear();

	protected:
	void display();
	void erase();
	void set();

	void reset()
	{
		active=1;
		setActive(listItemSet->next);
	}
};

void listBox::add(char *item)
{
	int cntr;
	listItem *i,*temp;
	for(i=listItemSet;i->next!=NULL;i=i->next);
	for(cntr=0;cntr<100;cntr++)
		if(g_liset[cntr].allocated==0)
		{
			temp=&g_liset[cntr];
			g_liset[cntr].allocated=1;
			break;
		}
	strcpy(temp->caption,item);
	temp->index=count;
	temp->x1=x1;
	temp->y1=y1+(count*14);
	temp->x2=temp->x1+20*8;
	temp->y2=temp->y1+textheight("A")+8;
	temp->bkColor=WHITE;
	if(listItemSet->next==NULL)
	{
		activeListItem=temp;
		temp->status=1;
	}
	x2=temp->x2;
	y2=temp->y2;
	i->next=temp;
	count++;

	if(displayed)
	{
		erase();
		display();
	}
}

void listBox::clear()
{
	int cntr=0;
	listItem *i;
	for(i=listItemSet->next;i!=NULL;i=i->next)
	{
		for(cntr=0;cntr<100;cntr++)
		{
			if(i==&g_liset[cntr])
			{
				delete i;
				g_liset[cntr].allocated=0;
				g_liset[cntr].next=NULL;
			}
		}
	}
	x2=x1;
	y2=y1;
	count=0;
	listItemSet->next=NULL;
}


void listBox::display()
{
	listItem *i;
	setcolor(BLACK);
	rectangle(x1-1,y1-1,x2+1,y2+1);
	for(i=listItemSet->next;i!=NULL;i=i->next)
	{
		i->display();
		setcolor(BLACK);
	}
	displayed=1;
}

void listBox::erase()
{
	setfillstyle(SOLID_FILL,LIGHTGRAY);
	bar(x1-1,y1-1,x2+1,y2+1);
}

void listBox::set()
{
	listItem *i;
	for(i=listItemSet->next;i!=NULL;i=i->next)
	{
		if(i!=activeListItem)
			i->unset();
		else
			i->set();
	}
}

class comboBox:private Mouse
{
	private:
	int x1,y1;
	int x2,y2;

	int xe1,ye1;
	int xe2,ye2;

	int count;
	int txtColor;
	int bkColor;
	int listIndex;
	int active;
	listItem *comboItemSet,*activeComboItem;
	void(*actionfun)();
	friend Application;
	friend Form;

	public:
	comboBox(int xc,int yc)
	{
		x1=xc;
		y1=yc;
		x2=x1+20*8;
		y2=y1+textheight("A")+8;
		count=0;
		comboItemSet=new listItem;
		txtColor=WHITE;
		comboItemSet->next=NULL;
		bkColor=BLUE;
		activeComboItem=NULL;
		actionfun=&donothing;
		active=1;
	}

	void setAction(void(*actionpara)())
	{
		actionfun=actionpara;
	}

	listItem* getActive()
	{
		return activeComboItem;
	}

	void setActive(listItem *cmb)
	{
		activeComboItem=cmb;
		set();
	}

	void add(char *txt);

	void makeActive()
	{
		hideMousePtr();
		erase();
		bkColor=BLUE;
		active=1;
		display();
		showMousePtr();
	}

	void makeInactive()
	{
		hideMousePtr();
		erase();
		bkColor=DARKGRAY;
		active=0;
		display();
		showMousePtr();
	}

	protected:
	void display()
	{
		setfillstyle(SOLID_FILL,bkColor);
		setcolor(WHITE);
		bar(x1,y1,x2,y2);
		rectangle(x1,y1,x2,y2);
		setcolor(txtColor);
		outtextxy(x1+3,y1+3,activeComboItem->caption);
		setfillstyle(SOLID_FILL,LIGHTGRAY);
		bar(x2-15,y1+1,x2-1,y2-1);
		setcolor(BLACK);
		rectangle(x2-15,y1+1,x2-1,y2-1);
		line(x2-15+2,y1+4,x2-3,y1+4);
		line(x2-15+2,y1+4,x2-8,y2-4);
		line(x2-3,y1+4,x2-8,y2-4);
		setfillstyle(SOLID_FILL,BLACK);
		floodfill(x2-8,y2-5,BLACK);
	}

	void erase()
	{
		setfillstyle(SOLID_FILL,LIGHTGRAY);
		bar(x1,y1,x2,y2);
	}

	void reset()
	{
		active=1;
		setActive(comboItemSet->next);
	}

	void expand();
	void set();
};

void comboBox::add(char *item)
{
	listItem *i,*temp;
	for(i=comboItemSet;i->next!=NULL;i=i->next);
	temp=&g_liset[g_liset_cnt++];
	strcpy(temp->caption,item);
	temp->index=count;
	temp->x1=x1;
	temp->y1=y2+(count*14)+2;
	temp->bkColor=WHITE;

	if(comboItemSet->next==NULL)
	{
		xe1=temp->x1;
		ye1=temp->y1;
		activeComboItem=temp;
		temp->status=1;
	}

	temp->x2=temp->x1+20*8;
	temp->y2=temp->y1+textheight("A")+8;

	xe2=temp->x2;
	ye2=temp->y2;

	i->next=temp;
	count++;
}

void comboBox::expand()
{
	listItem *i;
	setcolor(BLACK);
	rectangle(x1-1,y1-1,x2+1,y2+1);
	for(i=comboItemSet->next;i!=NULL;i=i->next)
	{
		i->display();
		setcolor(BLACK);
	}
}

void comboBox::set()
{
	listItem *i;
	for(i=comboItemSet->next;i!=NULL;i=i->next)
	{
		if(i!=activeComboItem)
			i->unset();
		else
			i->set();
	}
	display();
}

class Menu
{
	private:
	int x1,y1;
	int x2,y2;

	int xe1,ye1;
	int xe2,ye2;

	int count;
	char caption[20];

	listItem *menuSeries,*activeMenuItem;

	friend Application;
	friend Form;

	public:
	Menu(char *cap)
	{
		count=0;
		menuSeries=new listItem;
		menuSeries->next=NULL;
		strcpy(caption,cap);
		activeMenuItem=NULL;
	}

	static void drawMenuBar()
	{
		setfillstyle(SOLID_FILL,DARKGRAY);
		bar(0,22,640,42);
		setcolor(BLACK);
		rectangle(0,22,640,42);
	}

	void setActive(listItem *mi)
	{
		activeMenuItem=mi;
	}

	void add(listItem *mi);
	void expand();
	void display(int expandedFlag);
	void set();
	void unset();
};

void Menu::add(listItem *mi)
{
	listItem *i,*temp;
	for(i=menuSeries;i->next!=NULL;i=i->next);
	temp=mi;
	temp->status=0;
	temp->txtColor=BLACK;
	temp->bkColor=LIGHTGRAY;

	xe2=temp->x2;
	ye2=temp->y2;

	i->next=temp;
	count++;
}

void Menu::expand()
{
	listItem *i;
	setcolor(BLACK);
	rectangle(xe1-1,ye1-1,xe2+1,ye2+1);
	for(i=menuSeries->next;i!=NULL;i=i->next)
	{
		i->display();
		setcolor(BLACK);
	}
	display(1);
}

void Menu::display(int expandedFlag)
{
	if(expandedFlag==0)
		setfillstyle(SOLID_FILL,LIGHTGRAY);
	else
		setfillstyle(SOLID_FILL,BLUE);
	bar(x1,y1,x2,y2);
	if(expandedFlag==0)
		setcolor(BLACK);
	else
		setcolor(WHITE);
	rectangle(x1,y1,x2,y2);
	outtextxy(x1+3,y1+3,caption);
}

void Menu::set()
{
	listItem *i;
	for(i=menuSeries->next;i!=NULL;i=i->next)
	{
		if(i!=activeMenuItem)
			i->unset();
		else
			i->set();
	}
	display(1);
}

void Menu::unset()
{
	listItem *i;
	for(i=menuSeries->next;i!=NULL;i=i->next)
	{
			i->unset();
	}
	activeMenuItem=NULL;
	display(0);
}

class textBox:private Mouse
{
	private:
	int x1,y1;
	int x2,y2;
	int active;
	int bkColor;
	int txtColor;
	int size;
	char *text;
	char *defaultText;
	void(*actionfun)();
	friend Application;
	friend Form;

	public:
	textBox()
	{

	}

	textBox(int xc,int yc,int sz)
	{
		size=sz;
		active=1;
		bkColor=WHITE;
		txtColor=BLACK;
		text=new char[sz+1];
		defaultText=new char[sz+1];
		strcpy(defaultText,"");
		strcpy(text,"");
		x1=xc;
		y1=yc;
		x2=x1+sz*8+5;
		y2=y1+textheight("A")+8;
		actionfun=&donothing;
	}

	textBox(int xc,int yc,int sz,char *txt)
	{
		size=sz;
		active=1;
		bkColor=WHITE;
		txtColor=BLACK;
		text=new char[sz+1];
		defaultText=new char[sz+1];
		strncpy(defaultText,txt,size);
		strncpy(text,txt,size);
		x1=xc;
		y1=yc;
		x2=x1+sz*8+5;
		y2=y1+textheight("A")+8;
		actionfun=&donothing;
	}

	void setAction(void(*actionpara)())
	{
		actionfun=actionpara;
	}

	void getText(char *txt)
	{
		strcpy(txt,text);
	}

	void setText(char *txt)
	{
		strncpy(text,txt,size);
		this->display();
	}

	int isEmpty()
	{
		if(text=='\0')
			return 1;
		else
			return 0;
	}

	int getLength()
	{
		return (strlen(text));
	}

	void makeActive()
	{
		hideMousePtr();
		erase();
		txtColor=BLACK;
		active=1;
		display();
		showMousePtr();
	}

	void makeInactive()
	{
		hideMousePtr();
		erase();
		txtColor=DARKGRAY;
		active=0;
		display();
		showMousePtr();
	}


	protected:
	void display()
	{
		setfillstyle(SOLID_FILL,bkColor);
		setcolor(BLACK);
		bar(x1,y1,x2,y2);
		rectangle(x1,y1,x2,y2);
		setcolor(txtColor);
		outtextxy(x1+3,y1+3,text);
	}

	void erase()
	{
		setfillstyle(SOLID_FILL,LIGHTGRAY);
		bar(x1,y1,x2,y2);
	}

	void reset()
	{
		active=1;
		strcpy(text,defaultText);
	}

	void inputText();
	void cursor(int on,int x,int y);
};

void textBox::cursor(int on,int x,int y)
{
	char uBarStr[2]={'_',0};
	if(on)
		setcolor(txtColor);
	else
		setcolor(bkColor);
	outtextxy(x,y,uBarStr);
	setcolor(txtColor);
}

void textBox::inputText()
{
	char *str,ch,st[2];
	int x,y,i;
	fflush(stdin);

	if(isEmpty())
		goto EMPTY;
	else
		goto NONEMPTY;

	EMPTY:
	str=text;
	i+1;
	x=x1+3;
	y=y1+3;
	goto LOOP;

	NONEMPTY:
	str=text+getLength();
	i=getLength()+1;
	x=x1+8*getLength()+3;
	y=y1+3;

	LOOP:
	while(1)
	{
		cursor(1,x,y);
		ch=getch();

		if(ch=='\r')
		{
			cursor(0,x,y);
			*str='\0';
			break;
		}

		if(ch==8&&i!=1)
		{
			cursor(0,x,y);
			x-=8;
			setfillstyle(SOLID_FILL,bkColor);
			bar(x,y,x+7,y+textwidth("A"));
			str--;
			i--;
			continue;
		}

		if(ch==8&&i==1)
			continue;

		if(i==size)
			continue;

		st[0]=ch;
		st[1]='\0';
		cursor(0,x,y);
		setcolor(txtColor);
		outtextxy(x,y,st);
		x+=8;
		*str++=ch;
		i++;
	}
}

cmdButton *btnExit;

class Capsules
{
	protected:
	struct btnCapsule
	{
		cmdButton *buttonObject;
		btnCapsule *next;
	};

	struct txtBoxCapsule
	{
		textBox *textBoxObject;
		txtBoxCapsule *next;
	};

	struct lblCapsule
	{
		Label *LabelObject;
		lblCapsule *next;
	};

	struct radioGrpCapsule
	{
		radioGroup *radioGroupObject;
		radioGrpCapsule *next;
	};

	struct chkBoxCapsule
	{
		checkBox *checkBoxObject;
		chkBoxCapsule *next;
	};

	struct lstBoxCapsule
	{
		listBox *listBoxObject;
		lstBoxCapsule *next;
	};

	struct cmbBoxCapsule
	{
		comboBox *comboBoxObject;
		cmbBoxCapsule *next;
	};

	struct menuCapsule
	{
		Menu *menuObject;
		menuCapsule *next;
	};

	union component
	{
		btnCapsule *btn;
		txtBoxCapsule *txtBox;
		lblCapsule *lbl;
		radioGrpCapsule *radioGrp;
		chkBoxCapsule *chkBox;
		lstBoxCapsule *lstBox;
		cmbBoxCapsule *cmbBox;
		menuCapsule *mnu;
		listItem *mi;
		int msgBoxVal;
	};
};
Form *activeForms[2];
//---------------------------------------------------------------------
class Form:private Mouse,private imageControl,private Capsules
{
	private:
	char frmTitle[30];
	int backgroundColor;
	formTheme theme;
	int x1,y1;
	int x2,y2;
	int xa,ya;
	int formVisible;
	int activeFormsIndex;
	int isMsgBox;
	friend Application;
	friend msgBox;

	cmdButton *formCloseButton;

	cmbBoxCapsule *expandedCombo;
	menuCapsule *expandedMenu;
	int comboExpandedFlag,comboItemSelected;
	btnCapsule *buttonSet;
	txtBoxCapsule *textBoxSet;
	lblCapsule *LabelSet;
	radioGrpCapsule *radioGroupSet;
	chkBoxCapsule *checkBoxSet;
	lstBoxCapsule *listBoxSet;
	cmbBoxCapsule *comboBoxSet;

	public:
	Form(int xc1,int yc1,int xc2,int yc2);
	Form(int xc1,int yc1,int xc2,int yc2,formTheme ft,char *title);
	Form(int xc1,int yc1,int xc2,int yc2,formTheme ft,char *title,int isMsgBoxFlag);

	component getFormComponent(mouseStatus *mouse,componentName *componentFlag,int *cex,int *cis,cmbBoxCapsule **ce,int *formClosedFlag)
	{
	component temp;
	*componentFlag=Nothing;

	if(isMsgBox)
		goto GOMSGBOX;

	if(comboExpandedFlag)
	{
		listItem *q;
		for(q=expandedCombo->comboBoxObject->comboItemSet->next;q!=NULL;q=q->next)
		{
			if((mouse->x>=q->x1)&&(mouse->y>=q->y1)&&(mouse->x<=q->x2)&&(mouse->y<=q->y2))
			{
				expandedCombo->comboBoxObject->setActive(q);
				*componentFlag=ComboBox;
				comboItemSelected=1;
				temp.cmbBox=expandedCombo;
				goto GETCOMPOEND1;
			}
		}
	}

	GOMSGBOX:
	btnCapsule *i;
	for(i=buttonSet;i!=NULL;i=i->next)
	{
		if((mouse->x>=i->buttonObject->x1)&&(mouse->y>=i->buttonObject->y1)&&(mouse->x<=i->buttonObject->x2)&&(mouse->y<=i->buttonObject->y2))
		{
			if(isMsgBox)
			{
				*componentFlag=MessageBox;
				if(i==buttonSet)
					temp.msgBoxVal=0;

				if(i==buttonSet->next)
				temp.msgBoxVal=1;

				if(i==buttonSet->next->next)
					temp.msgBoxVal=0;
			}
			else
			{
				*componentFlag=Button;
				temp.btn=i;
			}
			if(i==buttonSet)
				*formClosedFlag=1;
			else
				*formClosedFlag=0;

			goto GETCOMPOEND;
		}
	}

	if(isMsgBox)
		goto GETCOMPOEND;

	lblCapsule *h;
	for(h=LabelSet->next;h!=NULL;h=h->next)
	{
		if((mouse->x>=h->LabelObject->x1)&&(mouse->y>=h->LabelObject->y1)&&(mouse->x<=h->LabelObject->x2)&&(mouse->y<=h->LabelObject->y2))
		{
			*componentFlag=label;
			temp.lbl=h;
			goto GETCOMPOEND;
		}
	}

	txtBoxCapsule *j;
	for(j=textBoxSet->next;j!=NULL;j=j->next)
	{
		if((mouse->x>=j->textBoxObject->x1)&&(mouse->y>=j->textBoxObject->y1)&&(mouse->x<=j->textBoxObject->x2)&&(mouse->y<=j->textBoxObject->y2))
		{
			*componentFlag=TextBox;
			temp.txtBox=j;
			goto GETCOMPOEND;
		}
	}

	radioGrpCapsule *k;
	Radio *l;
	for(k=radioGroupSet->next;k!=NULL;k=k->next)
	{
		for(l=k->radioGroupObject->radioSet->next;l!=NULL;l=l->next)
		{
			if((mouse->x>=l->x1)&&(mouse->y>=l->y1)&&(mouse->x<=l->x2)&&(mouse->y<=l->y2))
			{
				k->radioGroupObject->setActive(l);
				*componentFlag=radio;
				temp.radioGrp=k;
				goto GETCOMPOEND;
			}
		}
	}

	chkBoxCapsule *m;
	for(m=checkBoxSet->next;m!=NULL;m=m->next)
	{
		if((mouse->x>=m->checkBoxObject->x1)&&(mouse->y>=m->checkBoxObject->y1)&&(mouse->x<=m->checkBoxObject->x2)&&(mouse->y<=m->checkBoxObject->y2))
		{
			*componentFlag=CheckBox;
			temp.chkBox=m;
			goto GETCOMPOEND;
		}
	}

	lstBoxCapsule *n;
	listItem *o;
	for(n=listBoxSet->next;n!=NULL;n=n->next)
	{
		for(o=n->listBoxObject->listItemSet->next;o!=NULL;o=o->next)
		{
			if((mouse->x>=o->x1)&&(mouse->y>=o->y1)&&(mouse->x<=o->x2)&&(mouse->y<=o->y2))
			{
				n->listBoxObject->setActive(o);
				*componentFlag=ListBox;
				temp.lstBox=n;
				goto GETCOMPOEND;
			}
		}
	}

	cmbBoxCapsule *p;
	for(p=comboBoxSet->next;p!=NULL;p=p->next)
	{
		if((mouse->x>=p->comboBoxObject->x1)&&(mouse->y>=p->comboBoxObject->y1)&&(mouse->x<=p->comboBoxObject->x2)&&(mouse->y<=p->comboBoxObject->y2))
		{
			*componentFlag=ComboBox;
			temp.cmbBox=p;

			if(comboExpandedFlag==1)
				goto GETCOMPOEND;
			else
				comboExpandedFlag=1;
			comboItemSelected=0;
			expandedCombo=p;
			goto GETCOMPOEND1;
		}
	}

	GETCOMPOEND:
	if(comboExpandedFlag==1)
	{
		hideMousePtr();
		restoreImage();
		showMousePtr();
		comboExpandedFlag=0;
	}

	GETCOMPOEND1:
	*cex=comboExpandedFlag;
	*cis=comboItemSelected;
	*ce=expandedCombo;
	return temp;
}

	void show();
	void close();
	void suspend();
	void add(cmdButton *btn);
	void add(textBox *txtBox);
	void add(Label *lbl);
	void add(radioGroup *radioSet);
	void add(checkBox *chk);
	void add(listBox *lst);
	void add(comboBox *cmb);
//	union component getComponent(mouseStatus *mouse,componentName *componentFlag);
};

Form::Form(int xc1,int yc1,int xc2,int yc2)
{
	strcpy(frmTitle,"");
	backgroundColor=LIGHTGRAY;
	comboExpandedFlag=0;
	expandedCombo=NULL;
	comboItemSelected=0;
	theme=Plain;
	x1=xc1;
	y1=yc1;
	x2=xc2;
	y2=yc2;
	formVisible=0;
	isMsgBox=0;

	xa=x1+1;
	ya=y1+1;

	buttonSet=new btnCapsule;
	buttonSet->buttonObject=NULL;
	formCloseButton=NULL;
	buttonSet->next=NULL;

	textBoxSet=new txtBoxCapsule;
	textBoxSet->textBoxObject=NULL;
	textBoxSet->next=NULL;

	LabelSet=new lblCapsule;
	LabelSet->LabelObject=NULL;
	LabelSet->next=NULL;

	radioGroupSet=new radioGrpCapsule;
	radioGroupSet->radioGroupObject=NULL;
	radioGroupSet->next=NULL;

	checkBoxSet=new chkBoxCapsule;
	checkBoxSet->checkBoxObject=NULL;
	checkBoxSet->next=NULL;

	listBoxSet=new lstBoxCapsule;
	listBoxSet->listBoxObject=NULL;
	listBoxSet->next=NULL;

	comboBoxSet=new cmbBoxCapsule;
	comboBoxSet->comboBoxObject=NULL;
	comboBoxSet->next=NULL;
}

Form::Form(int xc1,int yc1,int xc2,int yc2,formTheme ft,char *title)
{
	cmdButton stopButton;
	strcpy(frmTitle,title);
	backgroundColor=LIGHTGRAY;
	comboExpandedFlag=0;
	expandedCombo=NULL;
	comboItemSelected=0;
	theme=ft;
	x1=xc1;
	y1=yc1;
	x2=xc2;
	y2=yc2;
	formVisible=0;
	isMsgBox=0;

	if(theme==Window)
	{
		xa=x1+1;
		ya=y1+21;

		buttonSet=new btnCapsule;
		buttonSet->buttonObject=new cmdButton(x2-20,y1+2,"X",1,RED,WHITE);
		formCloseButton=buttonSet->buttonObject;
		buttonSet->next=NULL;
	}

	if(theme==Frame)
	{
		xa=x1+1;
		ya=y1+1;
		buttonSet=new btnCapsule;
		buttonSet->buttonObject=NULL;
		formCloseButton=NULL;
		buttonSet->next=NULL;
	}

	buttonSet=new btnCapsule;
	buttonSet->buttonObject=new cmdButton(x2-20,y1+2,"X",1,RED,WHITE);
	formCloseButton=buttonSet->buttonObject;
	buttonSet->next=NULL;
	textBoxSet=new txtBoxCapsule;
	textBoxSet->textBoxObject=NULL;
	textBoxSet->next=NULL;

	LabelSet=new lblCapsule;
	LabelSet->LabelObject=NULL;
	LabelSet->next=NULL;

	radioGroupSet=new radioGrpCapsule;
	radioGroupSet->radioGroupObject=NULL;
	radioGroupSet->next=NULL;

	checkBoxSet=new chkBoxCapsule;
	checkBoxSet->checkBoxObject=NULL;
	checkBoxSet->next=NULL;

	listBoxSet=new lstBoxCapsule;
	listBoxSet->listBoxObject=NULL;
	listBoxSet->next=NULL;

	comboBoxSet=new cmbBoxCapsule;
	comboBoxSet->comboBoxObject=NULL;
	comboBoxSet->next=NULL;
}

Form::Form(int xc1,int yc1,int xc2,int yc2,formTheme ft,char *title,int isMsgBoxFlag)
{
	cmdButton stopButton;
	strcpy(frmTitle,title);
	backgroundColor=LIGHTGRAY;
	comboExpandedFlag=0;
	expandedCombo=NULL;
	comboItemSelected=0;
	theme=ft;
	x1=xc1;
	y1=yc1;
	x2=xc2;
	y2=yc2;
	formVisible=0;
	isMsgBox=1;

	xa=x1+1;
	ya=y1+21;

	buttonSet=new btnCapsule;
	buttonSet->buttonObject=new cmdButton(x2-20,y1+2,"X",1,RED,WHITE);
	formCloseButton=buttonSet->buttonObject;
	buttonSet->next=NULL;

	LabelSet=new lblCapsule;
	LabelSet->LabelObject=NULL;
	LabelSet->next=NULL;
	isMsgBoxFlag;
}

void Form::show()
{
	if(formVisible)
		return;
	int i;
	if(isMsgBox)
		activeForms[0]=this;
	else
	{
		if(activeForms[1]!=NULL)
			activeForms[1]->suspend();
		activeForms[1]=this;
	}

	hideMousePtr();
	if(theme==Window)
	{
		setcolor(BLACK);
		rectangle(x1+3,y1+3,x2+3,y2+3);
		setfillstyle(SOLID_FILL,BLUE);
		bar(x1,y1,x2,y1+20);
		line(x1,y1+21,x2,y1+21);
		setcolor(WHITE);
		outtextxy(x1+5,y1+5,frmTitle);
		setfillstyle(SOLID_FILL,backgroundColor);
		bar(x1,y1+22,x2,y2);
		setcolor(BLACK);
		rectangle(x1,y1,x2,y2);
		buttonSet->buttonObject->display();
	}

	if(theme==Frame)
	{
		setcolor(BLACK);
		rectangle(x1,y1,x2,y2);
		setfillstyle(SOLID_FILL,LIGHTGRAY);
		bar(x1+10,y1-4,x1+10+textwidth(frmTitle)+10,y1-4+textheight(frmTitle)+6);
		outtextxy(x1+15,y1-2,frmTitle);
	}

	if(theme==Plain)
	{
		setcolor(BLACK);
		rectangle(x1,y1,x2,y2);
	}

	for(lblCapsule *tmp3=LabelSet->next;tmp3!=NULL;tmp3=tmp3->next)
	{
		tmp3->LabelObject->display();
	}

	btnCapsule *tmp1;
	if(theme==Window)
	tmp1=buttonSet;
	else
		tmp1=buttonSet->next;
	for(tmp1;tmp1!=NULL;tmp1=tmp1->next)
	{
		tmp1->buttonObject->display();
	}

	if(isMsgBox)
	{
		showMousePtr();
		formVisible=1;
		return;
	}

	for(txtBoxCapsule *tmp2=textBoxSet->next;tmp2!=NULL;tmp2=tmp2->next)
	{
		tmp2->textBoxObject->display();
	}

	for(radioGrpCapsule *tmp4=radioGroupSet->next;tmp4!=NULL;tmp4=tmp4->next)
	{
		tmp4->radioGroupObject->display();
	}

	for(chkBoxCapsule *tmp5=checkBoxSet->next;tmp5!=NULL;tmp5=tmp5->next)
	{
		tmp5->checkBoxObject->display();
	}

	for(lstBoxCapsule *tmp6=listBoxSet->next;tmp6!=NULL;tmp6=tmp6->next)
	{
		tmp6->listBoxObject->display();
	}

	for(cmbBoxCapsule *tmp7=comboBoxSet->next;tmp7!=NULL;tmp7=tmp7->next)
	{
		tmp7->comboBoxObject->display();
	}

	showMousePtr();
	formVisible=1;
}

void Form::suspend()
{
	activeForms[1]=NULL;
	hideMousePtr();
	setfillstyle(SOLID_FILL,LIGHTGRAY);
	bar(x1,y1-5,x2+3,y2+3);
	showMousePtr();
	formVisible=0;
}

void Form::close()
{
	if(!isMsgBox)
	{
		for(btnCapsule *tmp1=buttonSet->next;tmp1!=NULL;tmp1=tmp1->next)
		{
			tmp1->buttonObject->reset();
		}

		for(txtBoxCapsule *tmp2=textBoxSet->next;tmp2!=NULL;tmp2=tmp2->next)
		{
			tmp2->textBoxObject->reset();
		}

		for(radioGrpCapsule *tmp4=radioGroupSet->next;tmp4!=NULL;tmp4=tmp4->next)
		{
			tmp4->radioGroupObject->reset();
		}

		for(chkBoxCapsule *tmp5=checkBoxSet->next;tmp5!=NULL;tmp5=tmp5->next)
		{
			tmp5->checkBoxObject->reset();
		}

		for(lstBoxCapsule *tmp6=listBoxSet->next;tmp6!=NULL;tmp6=tmp6->next)
		{
			tmp6->listBoxObject->reset();
		}

		for(cmbBoxCapsule *tmp7=comboBoxSet->next;tmp7!=NULL;tmp7=tmp7->next)
		{
			tmp7->comboBoxObject->reset();
		}

		activeForms[1]=NULL;
		hideMousePtr();
		setfillstyle(SOLID_FILL,LIGHTGRAY);
		bar(x1,y1-5,x2+3,y2+3);
		showMousePtr();
		formVisible=0;
	}
	else
	{
		activeForms[0]=NULL;
		formVisible=0;
	}
}


void Form::add(cmdButton *btn)
{
	btnCapsule *i,*temp;
	for(i=buttonSet;i->next!=NULL;i=i->next);
	temp=new btnCapsule;
	temp->buttonObject=btn;

	temp->buttonObject->x1+=xa;
	temp->buttonObject->y1+=ya;
	temp->buttonObject->x2+=xa;
	temp->buttonObject->y2+=ya;

	temp->next=NULL;
	i->next=temp;
	if(formVisible)
		temp->buttonObject->display();
}

void Form::add(textBox *txtBox)
{
	txtBoxCapsule *i,*temp;
	for(i=textBoxSet;i->next!=NULL;i=i->next);
	temp=new txtBoxCapsule;
	temp->textBoxObject=txtBox;

	temp->textBoxObject->x1+=xa;
	temp->textBoxObject->y1+=ya;
	temp->textBoxObject->x2+=xa;
	temp->textBoxObject->y2+=ya;

	temp->next=NULL;
	i->next=temp;
	if(formVisible)
		temp->textBoxObject->display();
}

void Form::add(radioGroup *radioSet)
{
	radioGrpCapsule *i,*temp;
	for(i=radioGroupSet;i->next!=NULL;i=i->next);
	temp=new radioGrpCapsule;
	temp->radioGroupObject=radioSet;

	Radio *rad;
	for(rad=radioSet->radioSet->next;rad!=NULL;rad=rad->next)
	{
		rad->x1+=xa;
		rad->y1+=ya;
		rad->x2+=xa;
		rad->y2+=ya;
	}

	temp->next=NULL;
	i->next=temp;
	if(formVisible)
		temp->radioGroupObject->display();
}

void Form::add(Label *lbl)
{
	lblCapsule *i,*temp;
	for(i=LabelSet;i->next!=NULL;i=i->next);
	temp=new lblCapsule;
	temp->LabelObject=lbl;

	temp->LabelObject->x1+=xa;
	temp->LabelObject->y1+=ya;
	temp->LabelObject->x2+=xa;
	temp->LabelObject->y2+=ya;

	temp->next=NULL;
	i->next=temp;
	if(formVisible)
		temp->LabelObject->display();
}

void Form::add(checkBox *chk)
{
	chkBoxCapsule *i,*temp;
	for(i=checkBoxSet;i->next!=NULL;i=i->next);
	temp=new chkBoxCapsule;
	temp->checkBoxObject=chk;

	temp->checkBoxObject->x1+=xa;
	temp->checkBoxObject->y1+=ya;
	temp->checkBoxObject->x2+=xa;
	temp->checkBoxObject->y2+=ya;

	temp->next=NULL;
	i->next=temp;
	if(formVisible)
		temp->checkBoxObject->display();
}

void Form::add(listBox *lst)
{
	int countc;
	lstBoxCapsule *i,*temp;
	listItem *lit;
	for(i=listBoxSet;i->next!=NULL;i=i->next);
	temp=new lstBoxCapsule;
	temp->listBoxObject=lst;

	temp->listBoxObject->x1+=xa;
	temp->listBoxObject->y1+=ya;
	temp->listBoxObject->x2+=xa;
	temp->listBoxObject->y2+=ya;

	for(lit=lst->listItemSet;lit!=NULL;lit=lit->next)
	{
		lit->x1+=xa;
		lit->y1+=ya;
		lit->x2+=xa;
		lit->y2+=ya;
	}


	temp->next=NULL;
	i->next=temp;
	if(formVisible)
		temp->listBoxObject->display();
}

void Form::add(comboBox *cmb)
{
	cmbBoxCapsule *i,*temp;
	listItem *lit;
	for(i=comboBoxSet;i->next!=NULL;i=i->next);
	temp=new cmbBoxCapsule;
	temp->comboBoxObject=cmb;

	temp->comboBoxObject->x1+=xa;
	temp->comboBoxObject->y1+=ya;
	temp->comboBoxObject->x2+=xa;
	temp->comboBoxObject->y2+=ya;

	temp->comboBoxObject->xe1+=xa;
	temp->comboBoxObject->ye1+=ya;
	temp->comboBoxObject->xe2+=xa;
	temp->comboBoxObject->ye2+=ya;

	for(lit=cmb->comboItemSet;lit!=NULL;lit=lit->next)
	{
		lit->x1+=xa;
		lit->y1+=ya;
		lit->x2+=xa;
		lit->y2+=ya;
	}

	temp->next=NULL;
	i->next=temp;
	if(formVisible)
		temp->comboBoxObject->display();
}

class msgBox:virtual protected imageControl,virtual private Mouse
{
	protected:
	Label *msg1,*msg2,*msg3;
	cmdButton *bOK,*bCancel;
	btnCapsule *bOKCapsule,*bCancelCapsule;
	Form *messageBox;
	int msgBoxShown;

	public:

	msgBox()
	{
		int gd=DETECT,gm;
		initgraph(&gd,&gm,"");
		messageBox=new Form(180,180,450,300,Window,"Message Box",1);

		bOK=new cmdButton(messageBox->xa+230,messageBox->ya+70,"OK",NULL);
		bCancel=new cmdButton(messageBox->xa+160,messageBox->ya+70,"Cancel",NULL);
		bOKCapsule=new btnCapsule;
		bCancelCapsule=new btnCapsule;

		msg1=new Label(10,10,30,"");
		msg2=new Label(10,25,30,"");
		msg3=new Label(10,40,30,"");
		messageBox->add(msg1);
		messageBox->add(msg2);
		messageBox->add(msg3);

		bOKCapsule->buttonObject=bOK;

		msgBoxShown=0;

		bCancelCapsule=new btnCapsule;
		bCancelCapsule->buttonObject=bCancel;
		bCancelCapsule->next=NULL;

		messageBox->buttonSet->next=bOKCapsule;
	}

	void closeMsgBox()
	{
		hideMousePtr();
		messageBox->close();
		restoreImage();
		showMousePtr();
		msgBoxShown=0;
	}
};

class Application:virtual private Mouse,virtual private imageControl,private Capsules,public msgBox
{
	private:
	char appTitle[80];
	int backgroundColor;
	int comboExpandedFlag,comboItemSelected;
	int *cex,*cis;
	int menuExpandedFlag,menuItemSelected;
	int formClosedFlag;
	Form *formClicked;
	Form *msgBox;
	Form *suspendedForm;

	cmbBoxCapsule *expandedCombo;
	menuCapsule *expandedMenu;

	btnCapsule *buttonSet;
	txtBoxCapsule *textBoxSet;
	lblCapsule *LabelSet;
	radioGrpCapsule *radioGroupSet;
	chkBoxCapsule *checkBoxSet;
	lstBoxCapsule *listBoxSet;
	cmbBoxCapsule *comboBoxSet;
	menuCapsule *menuSet;

	public:
	Application(char* title)
	{
		int i;
		cmdButton stopButton;
		backgroundColor=LIGHTGRAY;
		comboExpandedFlag=0;
		expandedCombo=NULL;
		comboItemSelected=0;
		menuExpandedFlag=0;
		expandedMenu=NULL;
		menuItemSelected=0;
		strcpy(appTitle,title);

		for(i=0;i<100;i++)
			g_liset[i].allocated=0;

		activeForms[0]=NULL;
		activeForms[1]=NULL;

		buttonSet=new btnCapsule;
		buttonSet->buttonObject=new cmdButton(620,2,"X",1,RED,WHITE);
		buttonSet->buttonObject->setAction(&_stopapp);
		buttonSet->next=NULL;
		btnExit=buttonSet->buttonObject;

		textBoxSet=new txtBoxCapsule;
		textBoxSet->textBoxObject=NULL;
		textBoxSet->next=NULL;

		LabelSet=new lblCapsule;
		LabelSet->LabelObject=NULL;
		LabelSet->next=NULL;

		radioGroupSet=new radioGrpCapsule;
		radioGroupSet->radioGroupObject=NULL;
		radioGroupSet->next=NULL;

		checkBoxSet=new chkBoxCapsule;
		checkBoxSet->checkBoxObject=NULL;
		checkBoxSet->next=NULL;

		listBoxSet=new lstBoxCapsule;
		listBoxSet->listBoxObject=NULL;
		listBoxSet->next=NULL;

		comboBoxSet=new cmbBoxCapsule;
		comboBoxSet->comboBoxObject=NULL;
		comboBoxSet->next=NULL;

		menuSet=new menuCapsule;
		menuSet->menuObject=NULL;
		menuSet->next=NULL;
	}

	void stop()
	{
		hideMousePtr();
		closegraph();
	}

	void suspend()
	{
		suspendedForm=activeForms[1];
		activeForms[1]->suspend();
		closegraph();
	}

	void resume()
	{
		int gd=DETECT,gm;
		initgraph(&gd,&gm,"");
		start();
	}

	component getComponent(mouseStatus *mouse,componentName *componentFlag)
	{
	component temp;
	*componentFlag=Nothing;
	formClosedFlag=0;
	formClicked=NULL;
	int ti;
	Form *t;
	cmbBoxCapsule *ce;

	if(comboExpandedFlag==1)
	{
		listItem *q;
		for(q=expandedCombo->comboBoxObject->comboItemSet->next;q!=NULL;q=q->next)
		{
			if((mouse->x>=q->x1)&&(mouse->y>=q->y1)&&(mouse->x<=q->x2)&&(mouse->y<=q->y2))
			{
				expandedCombo->comboBoxObject->setActive(q);
				*componentFlag=ComboBox;
				temp.cmbBox=expandedCombo;
				comboItemSelected=1;
				comboExpandedFlag=0;
				if(activeForms[1]!=NULL)
				{
					activeForms[1]->comboItemSelected=1;
					activeForms[1]->comboExpandedFlag=0;
				}
				goto GETCOMPOEND1;
			}
		}
	}

	if(menuExpandedFlag==1)
	{
		listItem *r;
		for(r=expandedMenu->menuObject->menuSeries->next;r!=NULL;r=r->next)
		{
			if((mouse->x>=r->x1)&&(mouse->y>=r->y1)&&(mouse->x<=r->x2)&&(mouse->y<=r->y2))
			{
				expandedMenu->menuObject->setActive(r);
				*componentFlag=menu;
				temp.mnu=expandedMenu;
				menuItemSelected=1;
				menuExpandedFlag=0;
				goto GETCOMPOEND1;
			}
		}
	}

	for(ti=0;ti<=1;ti++)
	{
		t=activeForms[ti];
		if(t==NULL)
			continue;

		if((mouse->x>=t->x1)&&(mouse->y>=t->y1)&&(mouse->x<=t->x2)&&(mouse->y<=t->y2))
		{
			temp=t->getFormComponent(mouse,componentFlag,&comboExpandedFlag,&comboItemSelected,&ce,&formClosedFlag);
			formClicked=t;
			if(*componentFlag==Nothing)
				break;
			if(comboExpandedFlag!=0)
			{
				expandedCombo=ce;
				goto GETCOMPOEND2;
			}

			goto GETCOMPOEND1;
		}

		if(msgBoxShown)
			goto GETCOMPOEND1;
	}

	lblCapsule *h;
	for(h=LabelSet;h!=NULL;h=h->next)
	{
		if((mouse->x>=h->LabelObject->x1)&&(mouse->y>=h->LabelObject->y1)&&(mouse->x<=h->LabelObject->x2)&&(mouse->y<=h->LabelObject->y2))
		{
			*componentFlag=label;
			temp.lbl=h;
			goto GETCOMPOEND;
		}
	}

	btnCapsule *i;
	for(i=buttonSet;i!=NULL;i=i->next)
	{
		if((mouse->x>=i->buttonObject->x1)&&(mouse->y>=i->buttonObject->y1)&&(mouse->x<=i->buttonObject->x2)&&(mouse->y<=i->buttonObject->y2))
		{
			*componentFlag=Button;
			temp.btn=i;
			goto GETCOMPOEND;
		}
	}

	txtBoxCapsule *j;
	for(j=textBoxSet->next;j!=NULL;j=j->next)
	{
		if((mouse->x>=j->textBoxObject->x1)&&(mouse->y>=j->textBoxObject->y1)&&(mouse->x<=j->textBoxObject->x2)&&(mouse->y<=j->textBoxObject->y2))
		{
			*componentFlag=TextBox;
			temp.txtBox=j;
			goto GETCOMPOEND;
		}
	}

	radioGrpCapsule *k;
	Radio *l;
	for(k=radioGroupSet->next;k!=NULL;k=k->next)
	{
		for(l=k->radioGroupObject->radioSet->next;l!=NULL;l=l->next)
		{
			if((mouse->x>=l->x1)&&(mouse->y>=l->y1)&&(mouse->x<=l->x2)&&(mouse->y<=l->y2))
			{
				k->radioGroupObject->setActive(l);
				*componentFlag=radio;
				temp.radioGrp=k;
				goto GETCOMPOEND;
			}
		}
	}

	chkBoxCapsule *m;
	for(m=checkBoxSet->next;m!=NULL;m=m->next)
	{
		if((mouse->x>=m->checkBoxObject->x1)&&(mouse->y>=m->checkBoxObject->y1)&&(mouse->x<=m->checkBoxObject->x2)&&(mouse->y<=m->checkBoxObject->y2))
		{
			*componentFlag=CheckBox;
			temp.chkBox=m;
			goto GETCOMPOEND;
		}
	}

	lstBoxCapsule *n;
	listItem *o;
	for(n=listBoxSet->next;n!=NULL;n=n->next)
	{
		for(o=n->listBoxObject->listItemSet->next;o!=NULL;o=o->next)
		{
			if((mouse->x>=o->x1)&&(mouse->y>=o->y1)&&(mouse->x<=o->x2)&&(mouse->y<=o->y2))
			{
				n->listBoxObject->setActive(o);
				*componentFlag=ListBox;
				temp.lstBox=n;
				goto GETCOMPOEND;
			}
		}
	}

	cmbBoxCapsule *p;
	for(p=comboBoxSet->next;p!=NULL;p=p->next)
	{
		if((mouse->x>=p->comboBoxObject->x1)&&(mouse->y>=p->comboBoxObject->y1)&&(mouse->x<=p->comboBoxObject->x2)&&(mouse->y<=p->comboBoxObject->y2))
		{
			*componentFlag=ComboBox;
			temp.cmbBox=p;
			if(comboExpandedFlag==1)
				goto GETCOMPOEND;
			else
			{
				comboExpandedFlag=1;
				comboItemSelected=0;
				expandedCombo=p;
				goto GETCOMPOEND2;
			}
		}
	}

	menuCapsule *s;
	for(s=menuSet->next;s!=NULL;s=s->next)
	{
		if((mouse->x>=s->menuObject->x1)&&(mouse->y>=s->menuObject->y1)&&(mouse->x<=s->menuObject->x2)&&(mouse->y<=s->menuObject->y2))
		{
			*componentFlag=menu;
			temp.mnu=s;
			if(menuExpandedFlag==1)
				goto GETCOMPOEND2;
			else
			{
				menuExpandedFlag=1;
				menuItemSelected=0;
				expandedMenu=s;
				goto GETCOMPOEND;
			}
		}
	}

	GETCOMPOEND:
	if(comboExpandedFlag==1)
	{
		hideMousePtr();
		restoreImage();
		showMousePtr();
		comboExpandedFlag=0;
	}
	if(*componentFlag!=menu)
		goto GETCOMPOEND2;
	else
		goto GETCOMPOEND1;

	GETCOMPOEND2:
	if(menuExpandedFlag==1)
	{
		hideMousePtr();
		expandedMenu->menuObject->unset();
		restoreImage();
		showMousePtr();
		menuExpandedFlag=0;
	}

	GETCOMPOEND1:
	return temp;
}

	void start();
	void close();
	void showMsgBox(char *msg);
	int showMsgBox(char *msg,char *title,int type);
	void add(cmdButton *btn);
	void add(textBox *txtBox);
	void add(Label *lbl);
	void add(radioGroup *radioSet);
	void add(checkBox *chk);
	void add(listBox *lst);
	void add(comboBox *cmb);
	void add(Menu *mnu);

//	union component getComponent(mouseStatus *mouse,componentName *componentFlag);
	int getResponse();
};

void Application::start()
{
	setfillstyle(SOLID_FILL,BLUE);
	bar(0,0,640,20);
	setcolor(BLACK);
	line(0,21,640,21);
	setcolor(WHITE);
	outtextxy(5,5,appTitle);
	setfillstyle(SOLID_FILL,backgroundColor);
	bar(0,22,640,480);
	buttonSet->buttonObject->display();

	for(lblCapsule *tmp3=LabelSet->next;tmp3!=NULL;tmp3=tmp3->next)
	{
		tmp3->LabelObject->display();
	}

	for(btnCapsule *tmp1=buttonSet->next;tmp1!=NULL;tmp1=tmp1->next)
	{
		tmp1->buttonObject->display();
	}

	for(txtBoxCapsule *tmp2=textBoxSet->next;tmp2!=NULL;tmp2=tmp2->next)
	{
		tmp2->textBoxObject->display();
	}

	for(radioGrpCapsule *tmp4=radioGroupSet->next;tmp4!=NULL;tmp4=tmp4->next)
	{
		tmp4->radioGroupObject->display();
	}

	for(chkBoxCapsule *tmp5=checkBoxSet->next;tmp5!=NULL;tmp5=tmp5->next)
	{
		tmp5->checkBoxObject->display();
	}

	for(lstBoxCapsule *tmp6=listBoxSet->next;tmp6!=NULL;tmp6=tmp6->next)
	{
		tmp6->listBoxObject->display();
	}

	for(cmbBoxCapsule *tmp7=comboBoxSet->next;tmp7!=NULL;tmp7=tmp7->next)
	{
		tmp7->comboBoxObject->display();
	}

	hideMousePtr();
	Menu::drawMenuBar();
	showMousePtr();
	for(menuCapsule *tmp8=menuSet->next;tmp8!=NULL;tmp8=tmp8->next)
	{
		tmp8->menuObject->display(0);
	}

	initMouse();
	showMousePtr();

	if(suspendedForm!=NULL)
	{
		suspendedForm->show();
	}

	AGAIN:
		getResponse();
		goto AGAIN;

}

void Application::close()
{
	for(btnCapsule *tmp1=buttonSet->next;tmp1!=NULL;tmp1=tmp1->next)
	{
		tmp1->buttonObject->reset();
	}

	for(txtBoxCapsule *tmp2=textBoxSet->next;tmp2!=NULL;tmp2=tmp2->next)
	{
		tmp2->textBoxObject->reset();
	}

	for(radioGrpCapsule *tmp4=radioGroupSet->next;tmp4!=NULL;tmp4=tmp4->next)
	{
		tmp4->radioGroupObject->reset();
	}

	for(chkBoxCapsule *tmp5=checkBoxSet->next;tmp5!=NULL;tmp5=tmp5->next)
	{
		tmp5->checkBoxObject->reset();
	}

	for(lstBoxCapsule *tmp6=listBoxSet->next;tmp6!=NULL;tmp6=tmp6->next)
	{
		tmp6->listBoxObject->reset();
	}

	for(cmbBoxCapsule *tmp7=comboBoxSet->next;tmp7!=NULL;tmp7=tmp7->next)
	{
		tmp7->comboBoxObject->reset();
	}

	activeForms[1]->close();
}

int Application::getResponse()
{
	mouseStatus *mouse;
	component componentFound;
	int btnrelease=0,dnactive=0;
	listItem *li;
	componentName componentFlag;

	HERE:
		mouse=new mouseStatus;
		mouse=getMousePos();
		if((mouse->but&1)==1)
		{
			if(dnactive!=1)
				componentFound=getComponent(mouse,&componentFlag);

			if(componentFlag==Nothing)
			{
				goto HERE;
			}

			if(componentFlag==Button && dnactive!=1)
			{
				if(componentFound.btn->buttonObject->active)
					componentFound.btn->buttonObject->pulldown();
				dnactive=1;
			}

			if(componentFlag==MessageBox && dnactive!=1)
			{
				if(componentFound.msgBoxVal==1)
					activeForms[0]->buttonSet->next->buttonObject->pulldown();
				else
				if(componentFound.msgBoxVal==0 && !formClosedFlag)
					activeForms[0]->buttonSet->next->next->buttonObject->pulldown();
				else
				if(componentFound.msgBoxVal==0 && formClosedFlag)
					activeForms[0]->buttonSet->buttonObject->pulldown();
				dnactive=1;
			}

			if(componentFlag==label && dnactive!=1)
			{
				dnactive=1;
			}

			if(componentFlag==TextBox)
			{
				if(componentFound.txtBox->textBoxObject->active)
				{
					hideMousePtr();
					componentFound.txtBox->textBoxObject->inputText();
					showMousePtr();
					componentFound.txtBox->textBoxObject->actionfun();
				}
			}

			if(componentFlag==radio&&dnactive!=1)
			{
				if(componentFound.radioGrp->radioGroupObject->activeRadio->active)
				{
					hideMousePtr();
					componentFound.radioGrp->radioGroupObject->set();
					showMousePtr();
				}
				dnactive=1;
			}

			if(componentFlag==CheckBox&&dnactive!=1)
			{
				if(componentFound.chkBox->checkBoxObject->active)
				{
					hideMousePtr();
					componentFound.chkBox->checkBoxObject->toggle();
					showMousePtr();
				}
					dnactive=1;
			}

			if(componentFlag==ListBox&&dnactive!=1)
			{
				if(componentFound.lstBox->listBoxObject->active)
				{
					hideMousePtr();
					componentFound.lstBox->listBoxObject->set();
					showMousePtr();
				}
				dnactive=1;
			}

			if(componentFlag==ComboBox && (comboItemSelected!=1) && dnactive!=1)
			{
				if(componentFound.cmbBox->comboBoxObject->active)
				{
					hideMousePtr();
					if(comboExpandedFlag==1)
					{
						saveImage(componentFound.cmbBox->comboBoxObject->xe1,componentFound.cmbBox->comboBoxObject->ye1,componentFound.cmbBox->comboBoxObject->xe2,componentFound.cmbBox->comboBoxObject->ye2);
						componentFound.cmbBox->comboBoxObject->expand();
					}
					showMousePtr();
				}
				dnactive=1;
			}

			if(componentFlag==ComboBox && (comboItemSelected==1) && dnactive!=1)
			{
				hideMousePtr();
				componentFound.cmbBox->comboBoxObject->set();
				showMousePtr();
				dnactive=1;
			}

			if(componentFlag==menu&&menuItemSelected!=1&&dnactive!=1)
			{
				hideMousePtr();
				if(menuExpandedFlag==1)
				{
					saveImage(componentFound.mnu->menuObject->xe1-1,componentFound.mnu->menuObject->ye1-1,componentFound.mnu->menuObject->xe2+1,componentFound.mnu->menuObject->ye2+1);
					componentFound.mnu->menuObject->expand();
				}
				showMousePtr();
				dnactive=1;
			}

			if(componentFlag==menu&&menuItemSelected==1&&dnactive!=1)
			{
				if(componentFound.mnu->menuObject->activeMenuItem->active)
				{
					hideMousePtr();
					componentFound.mnu->menuObject->set();
					showMousePtr();
				}
				dnactive=1;
			}

		}

		if(componentFlag==Button && dnactive!=0 && mouse->but!=1)
		{
			if(componentFound.btn->buttonObject->active)
				componentFound.btn->buttonObject->pullup();
			dnactive=0;
			btnrelease=1;
			showMousePtr();
		}

		if(componentFlag==MessageBox && dnactive!=0 && mouse->but!=1)
		{
			if(componentFound.msgBoxVal==1)
				activeForms[0]->buttonSet->next->buttonObject->pullup();
			else
			if(componentFound.msgBoxVal==0 && !formClosedFlag)
				activeForms[0]->buttonSet->next->next->buttonObject->pullup();
			else
			if(componentFound.msgBoxVal==0 && formClosedFlag)
				activeForms[0]->buttonSet->buttonObject->pullup();
			dnactive=0;
			btnrelease=1;
			showMousePtr();
		}

		if(componentFlag==label && dnactive!=0)
		{
			dnactive=0;
			btnrelease=1;
		}

		if(componentFlag==CheckBox && dnactive!=0&&mouse->but!=1)
		{
			dnactive=0;
			btnrelease=1;
		}

		if(componentFlag==radio&&dnactive!=0&&mouse->but!=1)
		{
			dnactive=0;
			btnrelease=1;
		}

		if(componentFlag==ListBox&&dnactive!=0&&mouse->but!=1)
		{
			dnactive=0;
			btnrelease=1;
		}

		if(componentFlag==ComboBox&&dnactive!=0&&mouse->but!=1)
		{
			dnactive=0;
			btnrelease=1;
		}

		if(componentFlag==menu&&dnactive!=0&&mouse->but!=1)
		{
			dnactive=0;
			btnrelease=1;
		}

		delete mouse;

		if(btnrelease==1)
		{
			if(componentFlag==Button)
			{
				if(componentFound.btn->buttonObject->active)
				{
					componentFound.btn->buttonObject->redraw();
					componentFound.btn->buttonObject->actionfun();
				}

				if(formClicked!=NULL)
					if(formClosedFlag==1)
						formClicked->close();
				return -1;
			}

			if(componentFlag==MessageBox)
			{
				if(componentFound.msgBoxVal==1)
				{
					activeForms[0]->buttonSet->next->buttonObject->redraw();
					closeMsgBox();
					return 1;
				}
				else
				if(componentFound.msgBoxVal==0 && !formClosedFlag)
				{
					activeForms[0]->buttonSet->next->next->buttonObject->redraw();
					closeMsgBox();
					return 0;
				}
				else
				if(formClosedFlag==1)
				{
					activeForms[0]->buttonSet->buttonObject->redraw();
					closeMsgBox();
				}
			}

			if(componentFlag==label)
			{
				if(componentFound.lbl->LabelObject->active)
					componentFound.lbl->LabelObject->actionfun();
				return -1;
			}

			if(componentFlag==CheckBox)
			{
				if(componentFound.chkBox->checkBoxObject->active)
					componentFound.chkBox->checkBoxObject->actionfun();
				return -1;
			}

			if(componentFlag==radio)
			{
				if(componentFound.radioGrp->radioGroupObject->activeRadio->active)
					componentFound.radioGrp->radioGroupObject->activeRadio->actionfun();
				return -1;
			}

			if(componentFlag==ListBox)
			{
				if(componentFound.lstBox->listBoxObject->active)
					componentFound.lstBox->listBoxObject->actionfun();
				return -1;
			}

			if(componentFlag==ComboBox && comboItemSelected==1)
			{
				if(componentFound.cmbBox->comboBoxObject->active)
				{
					hideMousePtr();
					restoreImage();
					showMousePtr();
					showMousePtr();
					componentFound.cmbBox->comboBoxObject->actionfun();
				}
				return -1;
			}

			if(componentFlag==menu&&menuItemSelected==1)
			{
				li=componentFound.mnu->menuObject->activeMenuItem;
				componentFound.mnu->menuObject->unset();
				hideMousePtr();
				restoreImage();
				showMousePtr();
				if(li->active)
					li->actionfun();
				return -1;
			}
		}
		btnrelease=0;
	goto HERE;
}

void Application::showMsgBox(char *msg)
{
	char msgtemp[31],msgi;
	int count;

	for(count=0,msgi=*msg;count<=30 && *msg!='\0';count++,msg++)
		msgtemp[count]=*msg;
	msgtemp[count]='\0';
	strcpy(msg1->text,msgtemp);

	for(count=0,msgi=*msg;count<=30 && *msg!='\0';count++,msg++)
		msgtemp[count]=*msg;
	msgtemp[count]='\0';
	strcpy(msg2->text,msgtemp);

	for(count=0,msgi=*msg;count<=30 && *msg!='\0';count++,msg++)
		msgtemp[count]=*msg;
	msgtemp[count]='\0';
	strcpy(msg3->text,msgtemp);

	bOKCapsule->next=NULL;
	strcpy(messageBox->frmTitle,"Message Box");
	hideMousePtr();
	saveImage(180-3,180-3,450+3,300+3);
	showMousePtr();
	messageBox->show();
	msgBoxShown=1;

	int val=-1;
	while(val==-1)
	       val=this->getResponse();
	msgi;
}

int Application::showMsgBox(char *msg,char *title,int type)
{
	char msgtemp[31],msgi;
	int count;

	for(count=0,msgi=*msg;count<=30 && *msg!='\0';count++,msg++)
		msgtemp[count]=*msg;
	msgtemp[count]='\0';
	strcpy(msg1->text,msgtemp);

	for(count=0,msgi=*msg;count<=30 && *msg!='\0';count++,msg++)
		msgtemp[count]=*msg;
	msgtemp[count]='\0';
	strcpy(msg2->text,msgtemp);

	for(count=0,msgi=*msg;count<=30 && *msg!='\0';count++,msg++)
		msgtemp[count]=*msg;
	msgtemp[count]='\0';
	strcpy(msg3->text,msgtemp);

	if(type==OK)
	{
		bOKCapsule->next=NULL;
		strcpy(messageBox->frmTitle,title);
		hideMousePtr();
		saveImage(180-3,180-3,450+3,300+3);
		showMousePtr();
		messageBox->show();
	}

	if(type==OKCancel)
	{
		bOKCapsule->next=bCancelCapsule;
		strcpy(messageBox->frmTitle,title);
		hideMousePtr();
		saveImage(180-3,180-3,450+3,300+3);
		showMousePtr();
		messageBox->show();
	}
	msgBoxShown=1;

	int val=-1;
	while(val==-1)
		val=this->getResponse();
	msgi;
	return val;
}

void Application::add(cmdButton *btn)
{
	btnCapsule *i,*temp;
	for(i=buttonSet;i->next!=NULL;i=i->next);
	temp=new btnCapsule;
	temp->buttonObject=btn;
	temp->next=NULL;
	i->next=temp;
	temp->buttonObject->display();
}

void Application::add(textBox *txtBox)
{
	txtBoxCapsule *i,*temp;
	for(i=textBoxSet;i->next!=NULL;i=i->next);
	temp=new txtBoxCapsule;
	temp->textBoxObject=txtBox;
	temp->next=NULL;
	i->next=temp;
	temp->textBoxObject->display();
}

void Application::add(radioGroup *radioSet)
{
	radioGrpCapsule *i,*temp;
	for(i=radioGroupSet;i->next!=NULL;i=i->next);
	temp=new radioGrpCapsule;
	temp->radioGroupObject=radioSet;
	temp->next=NULL;
	i->next=temp;
	temp->radioGroupObject->display();
}

void Application::add(Label *lbl)
{
	lblCapsule *i,*temp;
	for(i=LabelSet;i->next!=NULL;i=i->next);
	temp=new lblCapsule;
	temp->LabelObject=lbl;
	temp->next=NULL;
	i->next=temp;
	temp->LabelObject->display();
}

void Application::add(checkBox *chk)
{
	chkBoxCapsule *i,*temp;
	for(i=checkBoxSet;i->next!=NULL;i=i->next);
	temp=new chkBoxCapsule;
	temp->checkBoxObject=chk;
	temp->next=NULL;
	i->next=temp;
	temp->checkBoxObject->display();
}

void Application::add(listBox *lst)
{
	lstBoxCapsule *i,*temp;
	for(i=listBoxSet;i->next!=NULL;i=i->next);
	temp=new lstBoxCapsule;
	temp->listBoxObject=lst;
	temp->next=NULL;
	i->next=temp;
	temp->listBoxObject->display();
}

void Application::add(comboBox *cmb)
{
	cmbBoxCapsule *i,*temp;
	for(i=comboBoxSet;i->next!=NULL;i=i->next);
	temp=new cmbBoxCapsule;
	temp->comboBoxObject=cmb;
	temp->next=NULL;
	i->next=temp;
	temp->comboBoxObject->display();
}

void Application::add(Menu *mnu)
{
	menuCapsule *i,*temp;
	listItem *mi;
	int menux=10,menuy=25,count=0,micount=0;
	for(i=menuSet;i->next!=NULL;i=i->next,count++);
	temp=new menuCapsule;
	temp->menuObject=mnu;

	if(count==0)
	{
		hideMousePtr();
		Menu::drawMenuBar();
		showMousePtr();
		temp->menuObject->x1=menux;
		temp->menuObject->y1=menuy;
		temp->menuObject->x2=temp->menuObject->x1+textwidth(mnu->caption)+3;
		temp->menuObject->y2=temp->menuObject->y1+textheight(mnu->caption)+6;
	}
	else
	{
		temp->menuObject->x1=i->menuObject->x2+10;
		temp->menuObject->y1=i->menuObject->y1;
		temp->menuObject->x2=temp->menuObject->x1+textwidth(mnu->caption)+3;
		temp->menuObject->y2=i->menuObject->y2;
	}

	for(mi=temp->menuObject->menuSeries->next;mi!=NULL;mi=mi->next,micount++)
	{
		mi->x1=temp->menuObject->x1;
		mi->y1=temp->menuObject->y2+(micount*14)+2;

		if(micount==0)
		{
			temp->menuObject->xe1=mi->x1;
			temp->menuObject->ye1=mi->y1;
		}
		mi->x2=mi->x1+16*8;
		mi->y2=mi->y1+textheight("A")+8;
		mi->brdrColor=BLACK;

		temp->menuObject->xe2=mi->x2;
		temp->menuObject->ye2=mi->y2;
	}

	temp->next=NULL;
	i->next=temp;
	temp->menuObject->display(0);
}

void _stopapp()
{
	closegraph();
	exit(0);
}

/*
MOUSE.H Application Programming Interface for GUI Development through C++
(C) Pineapple Software @ SoftOne Tech
softonetech@yahoo.com
+91-9028967081
*/