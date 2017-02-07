//Implemented version of MOUSE.H : 1.1
#include<iomanip.h>
#include<fstream.h>
#include<mouse.h>


Application app("Pineapple Co-operative Bank");
Menu *m1,*m2,*m3,*m4,*m5;
listItem *m11,*m12,*m13,*m21,*m22,*m23,*m31,*m32,*m41,*m42,*m51,*m52;
Label *openedfile;
char msg[30];
void open();
void showf1();
void addnewrec();
void listrec();
void listrec1();
void showinfo();
void confirmexit();
void showaddrec();
void showeditrec();
void updaterec();

fstream files;
char *fname[20];

struct acc
{
	char flag;
	int accno;
	char name[20];
	int acctype;
	float balance;
}bankacc;

class FileControl
{
	public:
	Form *fileopen;
	Label *l11;
	textBox *tb11;
	cmdButton *b11;
	FileControl()
	{
		//Form for opening a file
		fileopen=new Form(50,60,350,160,Window,"Open a File");
		l11=new Label(10,10,12,"File Name");
		tb11=new textBox(120,10,20);
		b11=new cmdButton(120,40,"Open");
		fileopen->add(l11);
		fileopen->add(tb11);
		fileopen->add(b11);
		b11->setAction(&open);
	}

	void openfile()
	{
		files.open("BANK.DAT",ios::binary|ios::in|ios::out);
	}

	int read()
	{
		if(files.read((char*)&bankacc,sizeof(bankacc)))
			return 1;
		else
			return 0;
	}

	int write()
	{
		if(files.write((char*)&bankacc,sizeof(bankacc)))
			return 1;
		else
			return 0;
	}

	void seekgp(long int l)
	{
		closefile();
		openfile();
		files.seekg(l,ios::beg);
	}

	void seekgstart()
	{
		closefile();
		openfile();

		files.seekg(0L,ios::beg);
	}

	void seekgend()
	{
		closefile();
		openfile();

		files.seekg(0L,ios::end);
	}


	void seekpp(long int l)
	{
		closefile();
		openfile();

		files.seekp(l,ios::beg);
	}

	void seekpstart()
	{
		closefile();
		openfile();

		files.seekp(0L,ios::beg);
	}

	void seekpend()
	{
		closefile();
		openfile();

		files.seekp(0L,ios::end);
	}

	void closefile()
	{
		files.close();
	}
};

class records
{
	public:
	Form *addrec;
	Form *showrec,*showrec1;

	Label *lb1,*lb2,*lb3;
	textBox *tb21,*tb22;
	Radio *r1,*r2,*r3;
	radioGroup *rg1;
	cmdButton *b1,*b21,*b31;
	listBox *lbx1;
	listBox *lbx2;

	Form *detailrec;
	Label *lb31,*lb32,*lb33,*lb34,*lb35,*lb36;

	Form *editrec;
	Label *lb41,*lb42,*lb43;
	textBox *tb41,*tb42;
	Radio *r41,*r42,*r43;
	radioGroup *rg41;
	cmdButton *b41;

	records()
	{
	lb1=new Label(10,10,40,"Name of A/C Holder");

	tb21=new textBox(200,10,20);
	tb21->makeActive();

	lb2=new Label(10,40,30,"Account Type");
	rg1=new radioGroup();
	r1=new Radio(200,40,"Savings");
	r2=new Radio(300,40,"Current");
	r3=new Radio(400,40,"Recurring");
	rg1->add(r1);
	rg1->add(r2);
	rg1->add(r3);

	b1=new cmdButton(200,100,"Add Record");
	b1->setAction(&addnewrec);

	lb3=new Label(10,70,30,"Initial Amount");
	tb22=new textBox(200,70,20);

	addrec=new Form(5,60,530,230,Window,"Add a Record");
	addrec->add(lb1);
	addrec->add(lb2);
	addrec->add(lb3);
	addrec->add(tb21);
	addrec->add(tb22);
	addrec->add(rg1);
	addrec->add(b1);

	showrec=new Form(20,70,220,450,Frame,"Show Records");
	lbx1=new listBox(10,10);
	lbx1->setAction(&showinfo);
	showrec->add(lbx1);

	detailrec=new Form(50,100,500,300,Window,"Details of Record");
	lb31=new Label(20,15,30,"Account Holder's Name");
	lb32=new Label(20,45,20,"Account Type");
	lb33=new Label(20,75,20,"Current Balance");
	lb34=new Label(220,15,30,"");
	lb35=new Label(220,45,15,"");
	lb36=new Label(220,75,20,"");
	b31=new cmdButton(380,120,"Back");
	b31->setAction(&listrec);
	detailrec->add(lb31);
	detailrec->add(lb32);
	detailrec->add(lb33);
	detailrec->add(lb34);
	detailrec->add(lb35);
	detailrec->add(lb36);
	detailrec->add(b31);

	showrec1=new Form(20,70,220,450,Frame,"Show Records");
	lbx2=new listBox(10,10);
	lbx2->setAction(&showeditrec);
	showrec1->add(lbx2);

	/////////////////////////////////////////////////

	editrec=new Form(5,60,530,230,Window,"Edit a Record");
	lb41=new Label(10,10,40,"Name of A/C Holder");
	tb41=new textBox(200,10,20);

	lb42=new Label(10,40,30,"Account Type");
	rg41=new radioGroup();
	r41=new Radio(200,40,"Savings");
	r42=new Radio(300,40,"Current");
	r43=new Radio(400,40,"Recurring");
	rg41->add(r41);
	rg41->add(r42);
	rg41->add(r43);

	b41=new cmdButton(200,100,"Update Record");
	b41->setAction(&updaterec);

	lb43=new Label(10,70,30,"Initial Amount");
	tb42=new textBox(200,70,20);

	editrec->add(lb41);
	editrec->add(lb42);
	editrec->add(lb43);
	editrec->add(tb41);
	editrec->add(tb42);
	editrec->add(rg41);
	editrec->add(b41);
	}

};

FileControl fc;
records rec;

int main()
{
	fc.openfile();

	m1=new Menu("File");
	m11=new listItem("Open...");
	m12=new listItem("Save As...");
	m13=new listItem("Exit");
	m2=new Menu("Records");
	m21=new listItem("Add a Record");
	m22=new listItem("Show Records");
	m23=new listItem("Edit a Record");
	m3=new Menu("Transaction");
	m31=new listItem("Deposit");
	m32=new listItem("Withdrawl");
	m4=new Menu("Delete");
	m41=new listItem("Logically");
	m42=new listItem("Physically");
    //	m5=new Menu("Help");
  //	m51=new listItem("General Help");
//	m52=new listItem("About MOUSE.H");

	openedfile=new Label(500,460,30,"BANK.DAT");
	m11->setAction(&showf1);
	m13->setAction(&confirmexit);
	m21->setAction(&showaddrec);
	m22->setAction(&listrec);
	m23->setAction(&listrec1);
	m1->add(m11);
	m1->add(m12);
	m1->add(m13);
	m2->add(m21);
	m2->add(m22);
	m2->add(m23);
	m3->add(m31);
	m3->add(m32);
	m4->add(m41);
	m4->add(m42);
	m5->add(m51);
	m5->add(m52);
	app.add(m1);
	app.add(m2);
	app.add(m3);
	app.add(m4);
//	app.add(m5);
	app.add(openedfile);
	app.start();
	return 0;
}

void confirmexit()
{
	int m;
	m=app.showMsgBox("Are you sure you want to exit?","Confirm Quit",OKCancel);
	if(m)
	{
		app.close();
		exit(0);
	}
}

void showf1()
{
	fc.fileopen->show();
}

void showaddrec()
{
	rec.addrec->show();
}

void open()
{
	char fname[30];
	fc.tb11->getText(msg);
	strcpy(msg,"BANK.DAT");
	if(strcmp(msg,"")==0)
		app.showMsgBox("Please enter filename");
	else
	{
		files.open(msg,ios::binary|ios::in|ios::out);
		if(!files)
		{
			app.showMsgBox("Unable to open file");

		}
		else
		{

			fc.fileopen->close();
		}
	}
}

void addnewrec()
{
	rec.tb21->getText(msg);
	bankacc.flag=' ';
	strcpy(bankacc.name,msg);
	rec.tb22->getText(msg);
	bankacc.balance=atof(msg);
	if(rec.r1->getStatus()==1)
		bankacc.acctype=1;
	else
	if(rec.r2->getStatus()==1)
		bankacc.acctype=2;
	else
	if(rec.r3->getStatus()==1)
		bankacc.acctype=3;

	fc.seekpend();
	if(!files.write((char*)&bankacc,sizeof(bankacc)))
		app.showMsgBox("Record writing failed!");
	else
	{
		app.showMsgBox("The new record has been added!");
		rec.addrec->close();
	}
}

void listrec()
{
	rec.lbx1->clear();
	rec.showrec->show();
	fc.seekgstart();
	while(fc.read())
	{
		rec.lbx1->add(bankacc.name);
	}
}

void listrec1()
{
	rec.lbx2->clear();
	rec.showrec1->show();
	fc.seekgstart();
	while(fc.read())
	{
		rec.lbx2->add(bankacc.name);
	}
}

void showinfo()
{
	long int pos;
	pos=(rec.lbx1->activeListItem->index)*sizeof(bankacc);
	cout<<pos;
	rec.showrec->close();
	rec.detailrec->show();
	fc.seekgp(pos);
	fc.read();
	rec.lb34->setText(bankacc.name);
	if(bankacc.acctype==1)
		rec.lb35->setText("Saving");
	else
	if(bankacc.acctype==2)
		rec.lb35->setText("Current");
	else
	if(bankacc.acctype==3)
		rec.lb35->setText("Recurring");

	sprintf(msg,"%2.2f",bankacc.balance);
	rec.lb36->setText(msg);
}

void showeditrec()
{
	long int pos;
	pos=(rec.lbx2->activeListItem->index)*sizeof(bankacc);
	cout<<pos;
	rec.editrec->show();
	fc.seekgp(pos);
	fc.read();
	rec.tb41->setText(bankacc.name);
	sprintf(msg,"%2.2f",bankacc.balance);
	rec.tb42->setText(msg);

	if(bankacc.acctype==1)
		rec.rg41->setActive(rec.r41);
	else
	if(bankacc.acctype==2)
		rec.rg41->setActive(rec.r42);
	else
	if(bankacc.acctype==3)
		rec.rg41->setActive(rec.r43);
}

void updaterec()
{
	long int pos;
	pos=(rec.lbx2->activeListItem->index)*sizeof(bankacc);
	cout<<pos;
	fc.seekpp(pos);

	rec.tb41->getText(msg);
	strcpy(bankacc.name,msg);
	rec.tb42->getText(msg);
	bankacc.balance=atof(msg);
	if(rec.r41->getStatus()==1)
		bankacc.acctype=1;
	else
	if(rec.r42->getStatus()==1)
		bankacc.acctype=2;
	else
	if(rec.r43->getStatus()==1)
		bankacc.acctype=3;

	fc.seekpp(pos);
	if(!fc.write())
		app.showMsgBox("Record writing failed!");
	else
	{
		app.showMsgBox("The record has been updated");
		rec.editrec->close();
		rec.showrec1->close();
		listrec1();
	}
}