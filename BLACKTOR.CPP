//PROGRAM - TRAIN RESERVATION//
#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<dos.h>
#include<stdio.h>
#include<fstream.h>
#include<process.h>
#include<stdlib.h>
#define password 1000
//MACRO DEFINITION IN LAST STATMENT DEFINING PASSWORD
int *e;int* a=0;int *f,*g,*v=0;//SOME USED GLOBAL VARIABLES AND POINTERS//
class train//CLASS TRAIN DECLARED////variable counter//
  {

   int trainno,nofafseat,nofasseat,noffsseat,nofacseat,nofssseat;
   char trainname[60],startingpoint[60],destination[60];
    public:
      train()
     {
      trainno=0;
      nofafseat=0;
      nofasseat=0;
      noffsseat=0;
      nofacseat=0;
      nofssseat=0;
      strcpy(trainname,"/0");
      strcpy(startingpoint,"/0");
      strcpy(destination,"/0");
     }
   void input();            //To input the details
   void display();          //To display the details
   void tradisplay();
   int returntr();
   int returnaf();
   int returnas();
   int returnfs();
   int returnac();
   int returnss();
  }tr;              //class object declared

int train::returntr() //accessor function
  {
   return trainno;
  }

int train::returnaf()   //accessor function
  {
   return nofafseat;
  }

int train::returnas()   //accessor function
  {
   return nofasseat;
  }

int train::returnfs()   //accessor function
  {
   return noffsseat;
  }

int train::returnac()   //accessor function
  {
   return nofacseat;
  }

int train::returnss()   //accessor function
  {
   return nofssseat;
  }

void train::input()//INPUTING TRAIN DETAILS while declaring new train//
  {
   clrscr();
   gotoxy(10,10);
   cout<<"ENTER THE TRAIN NUMBER ";
   gotoxy(57,10);
   cin>>trainno;
   gotoxy(10,12);
   cout<<"ENTER THE NUMBER OF A/C FIRST CLASS SEATS";
   gotoxy(57,12);
   cin>>nofafseat;
   gotoxy(10,14);
   cout<<"ENTER THE NUMBER OF A/C SECOND CLASS SEATS";
   gotoxy(57,14);
   cin>>nofasseat;
   gotoxy(10,16);
   cout<<"ENTER THE NUMBER OF FIRST CLASS SLEEPER SEATS";
   gotoxy(57,16);
   cin>>noffsseat;
   gotoxy(10,18);
   cout<<"ENTER THE NUMBER OF A/C CHAIR CAR SEATS";
   gotoxy(57,18);
   cin>>nofacseat;
   gotoxy(10,20);
   cout<<"ENTER THE NUMBER OF SECOND CLASS SLEEPER SEATS";
   gotoxy(57,20);
   cin>>nofssseat;
   gotoxy(10,22);
   cout<<"ENTER THE TRAIN NAME";
   gotoxy(57,22);
   gets(trainname);
   gotoxy(10,24);
   cout<<"ENTER THE STARTING POINT ";
   gotoxy(57,24);
   gets(startingpoint);
   gotoxy(10,26);
   cout<<"ENTER THE DESTINATION ";
   gotoxy(57,26);
   gets(destination);
  }

void train::display ()//DISPLAYING TRAIN DETAILS//
  {
   clrscr();
   gotoxy(10,10);
   cout<<"TRAIN NUMBER ";
   gotoxy(47,10);
   cout<<trainno;
   gotoxy(10,12);
   cout<<"TRAIN NAME ";
   gotoxy(47,12);
   puts(trainname);
   gotoxy(10,14);
   cout<<"NO OF A/C FIRST CLASS SEATS ";
   gotoxy(47,14);
   cout<<nofafseat;
   gotoxy(10,16);
   cout<<"NO OF A/C SECOND CLASS SEATS ";
   gotoxy(47,16);
   cout<<nofasseat;
   gotoxy(10,18);
   cout<<"NO OF FIRST CLASS SLEEPER SEATS ";
   gotoxy(47,18);
   cout<<noffsseat;
   gotoxy(10,20);
   cout<<"NO OF A/C CHAIR CLASS SEATS ";
   gotoxy(47,20);
   cout<<nofacseat;
   gotoxy(10,22);
   cout<<"NO OF SECOND CLASS SLEEPER SEATS ";
   gotoxy(47,22);
   cout<<nofssseat;
   gotoxy(10,24);
   cout<<"STARTING POINT ";
   gotoxy(47,24);
   puts(startingpoint);
   gotoxy(10,26);
   cout<<"DESTINATION ";
   gotoxy(47,26);
   puts(destination);
   gotoxy(10,28);
   cout<<"PRESS ANY KEY TO CONTINUE ";
   getch();
  }

class tickets//CLASS TICKET//
  {
   int resno,toaf,nofaf,toas,nofas,tofs,noffs,toac,nofac,toss,nofss,age,tno;
   char status[40],name[40];
   public:
   tickets();
   void reservation();              //For ticket reservation
   void cancellation();             //For ticket cancellation
   int ret();
   void display();                  //To display reservation details
   void tdisplay();                 //TO DISPLAY ETICKET
  }tick;

tickets::tickets()
  {
   tno=0;
   resno=0;
   toaf=0;
   nofaf=0;
   toas=0;
   nofas=0;
   tofs=0;
   noffs=0;
   toac=0;
   nofac=0;
   toss=0;
   nofss=0;
   age=0;
   strcpy(status,"/0");
   strcpy(name,"/0");
  }

int tickets::ret()   //accessor function
  {
   return resno;
  }

void tickets::display()//DISPLAYING STATUS..
//FIRST VERIFYING THE NUMBER FROM DATABASE//
  {
   int f=0;
   clrscr();
   fstream fn("Ticket1.txt",ios::in);
   fn.seekg(0);
   if(!fn)
     {
      cout<<"ERROR IN THE FILE ";
     }
   X:
   gotoxy(10,10);
   cout<<"ENTER THE RESERVATION NO ";
   gotoxy(10,12);
   int n;
   cin>>n;
   while(!fn.eof())
     {
      fn.read((char*)&tick,sizeof(tick));
      gotoxy(10,10);
      if(n==resno)
	{
	 clrscr();
	 f=1;
	 gotoxy(10,10);
	 cout<<"NAME ";
	 gotoxy(30,10) ;
	 cout<<name;
	 gotoxy(10,12);
	 cout<<"AGE ";
	 gotoxy(30,12);
	 cout<<age;
	 gotoxy(10,14);
	 cout<<"PRESENT STATUS ";
	 gotoxy(30,14);
	 cout<<status;
	 gotoxy(10,16);
	 cout<<"RESERVATION NUMBER ";
	 gotoxy(30,16);
	 cout<<resno;
	 gotoxy(10,18);
	 cout<<"PRESS ANY KEY TO CONTINUE ";
	 getch();
	}
     }
   if(f==0)
     {
      clrscr();
      gotoxy(10,10);
      cout<<"UNRECOGINIZED RESERVATION NO !!! WANNA RETRY ?(Y/N) ";
      char a;
      gotoxy(10,12);
      cin>>a;
      if(a=='y'||a=='Y')
	{
	 clrscr();
	 goto X;
	}
      else
	{
	 gotoxy(10,12);
	 cout<<"PRESS ANY KEY TO CONTINUE";
	 getch();
	}
     }
   fn.close();
  }


void tickets::reservation()//RESERVATION COUNTER//
  {
   clrscr();
   gotoxy(10,10);
   cout<<"RESERVATION ";
   gotoxy(10,12);
   cout<<"ENTER THE TRAIN NO: ";
   int tno,f=0;
   cin>>tno;
   fstream file;
  fstream fin("Train1.txt",ios::out|ios::in);
   fin.seekg(0);
   if(!fin)
     {
      clrscr();
      gotoxy(10,10);
      cout<<"ERROR IN THE FILE ";
     fin.close();
     }
   else
     {
      clrscr();
      while(!fin.eof())
	{
	 fin.read((char*)&tr,sizeof(tr));
	 int z;
	 z=tr.returntr();
	 if(tno==z)
	   {*e=tno;
	    f=1;
	    nofaf=tr.returnaf();
	    nofas=tr.returnas();
	    noffs=tr.returnfs();
	    nofac=tr.returnac();
	    nofss=tr.returnss();
	    fin.close();
	    }
	}
      if(f==1)
	{
	// file.open("Ticket1.txt",ios::app);
	 S:
	 clrscr();
	 /*gotoxy(10,10);
	 cout<<"NAME:";
	 gets(name);
	 gotoxy(10,12);
	 cout<<"AGE:";
	 cin>>age;*/
	 clrscr();
	 gotoxy(10,10);
	 cout<<"SELECT THE CLASS WHICH YOU WISH TO TRAVEL";
	 gotoxy(10,12);
	 cout<<"1.A/C FIRST CLASS " ;
	 gotoxy(10,14);
	 cout<<"2.A/C SECOND CLASS " ;
	 gotoxy(10,16);
	 cout<<"3.FIRST CLASS SLEEPER " ;
	 gotoxy(10,18);
	 cout<<"4.A/C CHAIR CAR " ;
	 gotoxy(10,20);
	 cout<<"5.SECOND CLASS SLEEPER ";
	 gotoxy(10,22);
	 int c;
	 cin>>c;
	 switch(c)
	   {
	    case 1:   toaf++;
			      //USING RAND TO GENERATE RANDOM NUMBERS//
	    //SPECIFIC NUMBERS FOR EACH CLASS//
		   randomize();
		   resno=random(100);
		      if((nofaf-toaf)>=0)
		     {  fstream file("ac1.txt",ios::in|ios::out);
		      clrscr();
	 gotoxy(10,10);
	 cout<<"NAME:";
	 gets(name);
	 gotoxy(10,12);
	 cout<<"AGE:";
	 cin>>age;
		      strcpy(status,"confirmed");
		      gotoxy(10,24) ;
		      cout<<"STATUS";
		      gotoxy(30,24);
		      puts(status);
		      gotoxy(10,26);
		      cout<<"RESERVATION NO";
		      gotoxy(30,26);
		      cout<<resno;
		      getch();
		      file.write((char*)&tick,sizeof(tick));
		      break;
		     }
		   else
		     {
		      fstream file("ac1.txt",ios::in|ios::out);
		      clrscr();
	 gotoxy(10,10);
	 cout<<"NAME:";
	 gets(name);
	 gotoxy(10,12);
	 cout<<"AGE:";
	 cin>>age;
		      strcpy(status,"pending");
		      gotoxy(10,24);
		      cout<<"STATUS";
		      gotoxy(30,24);
		      puts(status);
		      gotoxy(10,26);
		      cout<<"RESERVATION NO";
		      gotoxy(30,26);
		      cout<<resno;
		      getch();
		      file.write((char*)&tick,sizeof(tick));
		      break;
		     }
	    case 2:toas++;
		    randomize();
		   resno=random(100)+100;
		     if((nofas-toas)>=0)
		     {
		      fstream file("ac2.txt",ios::in|ios::out);
			      clrscr();
	 gotoxy(10,10);
	 cout<<"NAME:";
	 gets(name);
	 gotoxy(10,12);
	 cout<<"AGE:";
	 cin>>age;

		      strcpy(status,"confirmed");
		      gotoxy(10,24) ;
		      cout<<"STATUS";
		      gotoxy(30,24);
		      puts(status);
		      gotoxy(10,26);
		      cout<<"RESERVATION NO";
		      gotoxy(30,26);
		      cout<<resno;
		      getch();
		      file.write((char*)&tick,sizeof(tick));
		      break;
		     }
		   else
		     {fstream file("ac2.txt",ios::in|ios::out);
			      clrscr();
	 gotoxy(10,10);
	 cout<<"NAME:";
	 gets(name);
	 gotoxy(10,12);
	 cout<<"AGE:";
	 cin>>age;

		      strcpy(status,"pending");
		      gotoxy(10,24);
		      cout<<"STATUS";
		      gotoxy(30,24);
		      puts(status);
		      gotoxy(10,26);
		      cout<<"RESERVATION NO";
		      gotoxy(30,26);
		      cout<<resno;
		      getch();
		      file.write((char*)&tick,sizeof(tick));
		      break;
		     }
	    case 3:tofs++;
		     randomize();
		   resno=random(100)+200;
		   if((noffs-tofs)>=0)
		     { fstream file("sl1.txt",ios::in|ios::out);
			      clrscr();
	 gotoxy(10,10);
	 cout<<"NAME:";
	 gets(name);
	 gotoxy(10,12);
	 cout<<"AGE:";
	 cin>>age;

		      strcpy(status,"confirmed");
		      gotoxy(10,24) ;
		      cout<<"STATUS";
		      gotoxy(30,24);
		      puts(status);
		      gotoxy(10,26);
		      cout<<"RESERVATION NO";
		      gotoxy(30,26);
		      cout<<resno;
		      getch();
		      file.write((char*)&tick,sizeof(tick));
		      break;
		     }
		   else
		     {fstream file("sl1.txt",ios::in|ios::out);
			      clrscr();
	 gotoxy(10,10);
	 cout<<"NAME:";
	 gets(name);
	 gotoxy(10,12);
	 cout<<"AGE:";
	 cin>>age;

		      strcpy(status,"pending");
		      gotoxy(10,24);
		      cout<<"STATUS";
		      gotoxy(30,24);
		      puts(status);
		      gotoxy(10,26);
		      cout<<"RESERVATION NO";
		      gotoxy(30,26);
		      cout<<resno;
		      getch();
		      file.write((char*)&tick,sizeof(tick));
		      break;
		     }
	    case 4:toac++;
		       randomize();
		   resno=random(100)+300;
		   if((nofac-toac)>=0)
		     { fstream file("acc.txt",ios::in|ios::out);
			      clrscr();
	 gotoxy(10,10);
	 cout<<"NAME:";
	 gets(name);
	 gotoxy(10,12);
	 cout<<"AGE:";
	 cin>>age;

		      strcpy(status,"confirmed");
		      gotoxy(10,24) ;
		      cout<<"STATUS";
		      gotoxy(30,24);
		      puts(status);
		      gotoxy(10,26);
		      cout<<"RESERVATION NO";
		      gotoxy(30,26);
		      cout<<resno;
		      getch();
		      file.write((char*)&tick,sizeof(tick));
		      break;
		     }
		   else
		     {fstream file("acc.txt",ios::in|ios::out);
			      clrscr();
	 gotoxy(10,10);
	 cout<<"NAME:";
	 gets(name);
	 gotoxy(10,12);
	 cout<<"AGE:";
	 cin>>age;

		      strcpy(status,"pending");
		      gotoxy(10,24);
		      cout<<"STATUS";
		      gotoxy(30,24);
		      puts(status);
		      gotoxy(10,26);
		      cout<<"RESERVATION NO";
		      gotoxy(30,26);
		      cout<<resno;
		      getch();
		      file.write((char*)&tick,sizeof(tick));
		      break;
		     }
	    case 5:toss++;
		       randomize();
		   resno=random(100)+400;
		     if((nofss-toss)>=0)
		     { fstream file("sl2.txt",ios::in|ios::out);
			      clrscr();
	 gotoxy(10,10);
	 cout<<"NAME:";
	 gets(name);
	 gotoxy(10,12);
	 cout<<"AGE:";
	 cin>>age;

		      strcpy(status,"confirmed");
		      gotoxy(10,24) ;
		      cout<<"STATUS";
		      gotoxy(30,24);
		      puts(status);
		      gotoxy(10,26);
		      cout<<"RESERVATION NO";
		      gotoxy(30,26);
		      cout<<resno;
		      getch();
		      file.write((char*)&tick,sizeof(tick));
		      break;
		     }
		   else
		     {fstream file("sl2.txt",ios::in|ios::out);
			      clrscr();
	 gotoxy(10,10);
	 cout<<"NAME:";
	 gets(name);
	 gotoxy(10,12);
	 cout<<"AGE:";
	 cin>>age;

		      strcpy(status,"pending");
		      gotoxy(10,24);
		      cout<<"STATUS";
		      gotoxy(30,24);
		      puts(status);
		      gotoxy(10,26);
		      cout<<"RESERVATION NO";
		      gotoxy(30,26);
		      cout<<resno;
		      getch();
		      file.write((char*)&tick,sizeof(tick));
		      break;
		     }
	   }
	 file.close();
	 gotoxy(10,28);
	 cout<<"DO YOU WISH TO CONTINUE BOOKING TICKETS (Y/N) ? ";
	 gotoxy(10,30);
	 char n;
	 cin>>n;
	 if(n=='y'||n=='Y')
	   {
	    goto S;
	   }
	}
      }
   if(f==0)
     {clrscr();
      gotoxy(10,10);
      delay(1000);
      cout<<"ERROR IN THE TRAIN NUMBER ENTERED !!!";
      getch();
     }

  }
  void tickets::tdisplay()//MINI E TICKET DISPLAY//
  {
   int f=0;
   clrscr();
   fstream fn;
  /* if(!fn)
     {
      cout<<"ERROR IN THE FILE ";
     }*/
   X:int g;
   gotoxy(10,10);
   cout<<"ENTER THE RESERVATION NO ";
   gotoxy(10,12);
   int n;
   cin>>n;
   if(n<100)
  {    fn.open("ac1.txt",ios::in);
     fn.seekg(0,ios::beg);
    while(!fn.eof())
     {
      fn.read((char*)&tick,sizeof(tick));
    //  gotoxy(10,10);
      if(n==resno)
	{
	 clrscr();
	 f=1;
	 gotoxy(10,5);
	 cout<<"INDIAN RAILWAYS MINI E TICKET"<<"\tTO SAVE THE ENVIRONMENT";
	 gotoxy(10,10);
	 cout<<"NAME ";
	 gotoxy(30,10) ;
	 cout<<name;
	 gotoxy(10,12);
	 cout<<"AGE ";
	 gotoxy(30,12);
	 cout<<age;
	 gotoxy(10,14);
	 cout<<"PRESENT STATUS ";
	 gotoxy(30,14);
	 cout<<status;
	 gotoxy(10,16);
	 cout<<"RESERVATION NUMBER ";
	 gotoxy(30,16);
	 cout<<resno;
	 gotoxy(10,18);
	 cout<<"TRAIN NUMBER\t\t"<<*e;
	/* cout<<"CLASS-FARE";
     if(*a==0)//DISCOUNT FOR PRIVELAGE MEMBERS//
	{ if((resno<=200)&&(resno>=100))
	 {cout<<"1AC\n"<<"RS 3000/-";}
	 if((resno<=400)&&(resno>=300))
	 {cout<<"2AC\n"<<"RS 1000/-";}
	 if((resno<=600)&&(resno>=500))
	 {cout<<"FC\n"<<"RS 900/-";}
	 if((resno<=800)&&(resno>=700))
	 {cout<<"CC\n"<<"RS 800/-";}
	 if((resno<=1000)&&(resno>=900))
	 {cout<<"SC\n"<<"RS 600/-";}}
     else{ if((resno<=200)&&(resno>=100))
	 {cout<<"1AC\n"<<"RS 2000/-";}
	 if((resno<=400)&&(resno>=300))
	 {cout<<"2AC\n"<<"RS 900/-";}
	 if((resno<=600)&&(resno>=500))
	 {cout<<"FC\n"<<"RS 700/-";}
	 if((resno<=800)&&(resno>=700))
	 {cout<<"CC\n"<<"RS 600/-";}
	 if((resno<=1000)&&(resno>=900))
	 {cout<<"SC\n"<<"RS 500/-";}} */
	 cout<<"\n\n\n\t\tPRESS ANY KEY TO CONTINUE";
	 getch();
	fn.close();
	}
     } }
   else if((n>=100)&&(n<200))
    {  fn.open("ac2.txt",ios::in);
       fn.seekg(0);
    while(!fn.eof())
     {
      fn.read((char*)&tick,sizeof(tick));
      gotoxy(10,10);
      if(n==resno)
	{
	 clrscr();
	 f=1;
	 gotoxy(10,5);
	 cout<<"INDIAN RAILWAYS MINI E TICKET"<<"\tTO SAVE THE ENVIRONMENT";
	 gotoxy(10,10);
	 cout<<"NAME ";
	 gotoxy(30,10) ;
	 cout<<name;
	 gotoxy(10,12);
	 cout<<"AGE ";
	 gotoxy(30,12);
	 cout<<age;
	 gotoxy(10,14);
	 cout<<"PRESENT STATUS ";
	 gotoxy(30,14);
	 cout<<status;
	 gotoxy(10,16);
	 cout<<"RESERVATION NUMBER ";
	 gotoxy(30,16);
	 cout<<resno;
	 gotoxy(10,18);
	 cout<<"TRAIN NUMBER\t\t"<<*e;
	  cout<<"\n\n\t\tPRESS ANY KEY TO CONTINUE";
	 getch();
	 fn.close();}}}
   else if((n>=200)&&(n<300))
   {  fn.open("sl1.txt",ios::in);
    while(!fn.eof())
     {
      fn.read((char*)&tick,sizeof(tick));
      gotoxy(10,10);
      if(n==resno)
	{
	 clrscr();
	 f=1;
	 gotoxy(10,5);
	 cout<<"INDIAN RAILWAYS MINI E TICKET"<<"\tTO SAVE THE ENVIRONMENT";
	 gotoxy(10,10);
	 cout<<"NAME ";
	 gotoxy(30,10) ;
	 cout<<name;
	 gotoxy(10,12);
	 cout<<"AGE ";
	 gotoxy(30,12);
	 cout<<age;
	 gotoxy(10,14);
	 cout<<"PRESENT STATUS ";
	 gotoxy(30,14);
	 cout<<status;
	 gotoxy(10,16);
	 cout<<"RESERVATION NUMBER ";
	 gotoxy(30,16);
	 cout<<resno;
	 gotoxy(10,18);
	 cout<<"TRAIN NUMBER\t\t"<<*e;
	 cout<<"\n\n\t\tPRESS ANY KEY TO CONTINUE";
	 getch();
	 fn.close();}}}
  else if((n>=300)&&(n<400))
   { fn.open("acc.txt",ios::in);
    while(!fn.eof())
     {
      fn.read((char*)&tick,sizeof(tick));
      gotoxy(10,10);
      if(n==resno)
	{
	 clrscr();
	 f=1;
	 gotoxy(10,5);
	 cout<<"INDIAN RAILWAYS MINI E TICKET"<<"\tTO SAVE THE ENVIRONMENT";
	 gotoxy(10,10);
	 cout<<"NAME ";
	 gotoxy(30,10) ;
	 cout<<name;
	 gotoxy(10,12);
	 cout<<"AGE ";
	 gotoxy(30,12);
	 cout<<age;
	 gotoxy(10,14);
	 cout<<"PRESENT STATUS ";
	 gotoxy(30,14);
	 cout<<status;
	 gotoxy(10,16);
	 cout<<"RESERVATION NUMBER ";
	 gotoxy(30,16);
	 cout<<resno;
	 gotoxy(10,18);
	 cout<<"TRAIN NUMBER"<<*e;
	 cout<<"\n\n\t\tPRESS ANY KEY TO CONTINUE";
	 getch();
	 fn.close();}}}
    else if((n>=400)&&(n<500))
    { fn.open("sl2.txt",ios::in);
    while(!fn.eof())
     {
      fn.read((char*)&tick,sizeof(tick));
      gotoxy(10,10);
      if(n==resno)
	{
	 clrscr();
	 f=1;
	 gotoxy(10,5);
	 cout<<"INDIAN RAILWAYS MINI E TICKET"<<"\tTO SAVE THE ENVIRONMENT";
	 gotoxy(10,10);
	 cout<<"NAME ";
	 gotoxy(30,10) ;
	 cout<<name;
	 gotoxy(10,12);
	 cout<<"AGE ";
	 gotoxy(30,12);
	 cout<<age;
	 gotoxy(10,14);
	 cout<<"PRESENT STATUS ";
	 gotoxy(30,14);
	 cout<<status;
	 gotoxy(10,16);
	 cout<<"RESERVATION NUMBER ";
	 gotoxy(30,16);
	 cout<<resno;
	 gotoxy(10,18);
	 cout<<"TRAIN NUMBER"<<*e;
	 cout<<"\n\n\t\tPRESS ANY KEY TO CONTINUE";
	 getch();
	 fn.close();}}}
   if(f==0)
     {
      clrscr();
      gotoxy(10,10);
      cout<<"UNRECOGINIZED RESERVATION NO !!! WANNA RETRY ?(Y/N) ";
      char a;
      gotoxy(10,12);
      cin>>a;
      if(a=='y'||a=='Y')
	{
	 clrscr();
	 goto X;
	}
      else
	{
	 gotoxy(10,12);
	 cout<<"PRESS ANY KEY TO CONTINUE";
	 getch();
	}
     }
//   fn.close();
  }

void tickets::cancellation()//CANCELLING TICKET////READING FROM TICKET1//
  {clrscr();
   ifstream fin;
  // fin.open("Ticket1.txt",ios::out);
   ofstream file;
   file.open("Temp1.txt",ios::ate);
   fin.seekg(0);
   gotoxy(10,10);
   cout<<"ENTER THE RESERVATION NO: ";
   int r,f=0;
   cin>>r;
   if(r<100)
   {fin.open("ac1.txt");
   if(!fin)
     {
      cout<<"ERROR IN THE FILE !!!";
     }
   while(!fin.eof())
     {
      fin.read((char*)&tick,sizeof(tick));
      int z;
      z=ret();
      if(z!=r)
	{
	 file.write((char*)&tick,sizeof(tick));
	}
      if(z==r)
	{
	 f=1;
	 toaf--;
	}
     }
   }
 else if((r>=100)&&(r<200))
   {fin.open("ac2.txt");
   if(!fin)
     {
      cout<<"ERROR IN THE FILE !!!";
     }
   while(!fin.eof())
     {
      fin.read((char*)&tick,sizeof(tick));
      int z;
      z=ret();
      if(z!=r)
	{
	 file.write((char*)&tick,sizeof(tick));
	}
      if(z==r)
	{
	 f=1;
	toas--;
	}
     }
   }
  else if((r>=200)&&(r<300))
  {fin.open("sl1.txt");
   if(!fin)
     {
      cout<<"ERROR IN THE FILE !!!";
     }
   while(!fin.eof())
     {
      fin.read((char*)&tick,sizeof(tick));
      int z;
      z=ret();
      if(z!=r)
	{
	 file.write((char*)&tick,sizeof(tick));
	}
      if(z==r)
	{
	 f=1;
	tofs--;
	}
     }
   }
   else if((r>=300)&&(r<400))
   {fin.open("acc.txt");
   if(!fin)
     {
      cout<<"ERROR IN THE FILE !!!";
     }
   while(!fin.eof())
     {
      fin.read((char*)&tick,sizeof(tick));
      int z;
      z=ret();
      if(z!=r)
	{
	 file.write((char*)&tick,sizeof(tick));
	}
      if(z==r)
	{
	 f=1;
	toac--;
	}
     }
   }
   else if((r>=400)&&(r<500))
   {fin.open("sl2.txt");
   if(!fin)
     {
      cout<<"ERROR IN THE FILE !!!";
     }
   while(!fin.eof())
     {
      fin.read((char*)&tick,sizeof(tick));
      int z;
      z=ret();
      if(z!=r)
	{
	 file.write((char*)&tick,sizeof(tick));
	}
      if(z==r)
	{
	 f=1;
	toss--;
	}
     }
   }
   file.close();
   fin.close();
   remove("Ticket1.txt");
   rename("Temp1.txt","Ticket1.txt");
   if(f==0)
     {gotoxy(10,12);
      cout<<"NO SUCH RESERVATION IS MADE !!! PLEASE RETRY....";
      getch();
     }
   else
     {
      gotoxy(10,12);
      cout<<"RESERVATION CANCELLED";
      getch();
     }
  }

void main()//START OF MAIN PROGRAM//
  {//ADMINISTRATION MENU//
   int ch,no,i,r=1000,j;
   clrscr();
   textcolor(6);
   textbackground(5);
   /*cout<<"*******   *******    ******   *******    ******\n";
   cout<<"   *      *     *    *           *       *\n";
   cout<<"   *      *     *    *           *       *\n";
   cout<<"   *      *******    *           *       *\n";
   cout<<"   *      *     *    *           *       *\n";
   cout<<"   *      *      *   *           *       *\n";
   cout<<"*******   *       *  ******      *       ******\n";
   cout<<"===============================================\n";
  // gotoxy(33,22);
  // cout<<"SWAGATAM"; */
  //HOME SCREEN-1
  gotoxy(33,5);
  cout<<"INDIAN RAILWAYS";
  gotoxy(29,6);
  cout<<"Govt. of India enterprise";
  gotoxy(10,10);
  for(int q=0;q<8;q++)
  cout<<"*";
  for(int h=0;h<6;h++)
  {gotoxy(13,11+h);
   cout<<"*";}
   gotoxy(10,17);
   for(int h1=0;h1<8;h1++)
   cout<<"*";
   for(int h2=0;h2<8;h2++)
   {gotoxy(19,10+h2); cout<<"*";}
   gotoxy(20,10);
   for(int h3=0;h3<5;h3++)
   cout<<"*";
   for(int h4=0;h4<4;h4++)
   {gotoxy(24,10+h4);cout<<"*";}
   gotoxy(20,14);
   for(int h5=0;h5<5;h5++)
   cout<<"*";
   gotoxy(20,15);cout<<"*";
   gotoxy(21,16);cout<<"*";
   gotoxy(22,17);cout<<"*";
   gotoxy(23,18);cout<<"*";
   gotoxy(26,10);
   for(int h6=0;h6<7;h6++) cout<<"*";
   for(int h7=0;h7<7;h7++)
   {gotoxy(26,11+h7);cout<<"*";}
   gotoxy(26,17);
   for(int h8=0;h8<7;h8++) cout<<"*";
   gotoxy(34,10);
   for(int h9=0;h9<8;h9++)
   cout<<"*";
   for(int h10=0;h10<7;h10++)
   {gotoxy(38,11+h10); cout<<"*";}
   gotoxy(44,10);
   for(int h11=0;h11<8;h11++)
   cout<<"*";
   for(int h12=0;h12<7;h12++)
   {gotoxy(44,11+h12); cout<<"*";}
   gotoxy(44,17);
   for(int h13=0;h13<8;h13++)
   cout<<"*";
   gotoxy(12,22);
   cout<<"Indian Railways Catering and Tourism Corporation";
   gotoxy(33,48);
   cout<<"copyright,1934";
   gotoxy(37,33);
   cout<<"SWAGATAM";
   delay(1000);
   Z:
   //HOME SCREEN-2
   clrscr();int d;int a;char b[10];
   for(int il=10;il<=66;il++)//CREATE PATTERN//
   {gotoxy(il,7);cout<<"*";}
   for(int op=7;op<=35;op++)
   {gotoxy(10,op);cout<<"*";}
   for(int oi=10;oi<=66;oi++)
   {gotoxy(oi,35);cout<<"*";}
   for(int ow=7;ow<=35;ow++)
   {gotoxy(66,ow);cout<<"*";}
   gotoxy(25,8) ;
   cout<<"RAILWAY TICKET RESERVATION";
   gotoxy(25,9);
   cout<<"==========================";
   gotoxy(20,15) ;
   cout<<"1.TRAIN DETAILS";
   gotoxy(20,17);
   cout<<"2.UPDATE TRAIN DETAILS ";
   gotoxy(20,19);
   cout<<"3.RESERVING A TICKET ";
   gotoxy(20,21);
   cout<<"4.CANCELLING A TICKET";
   gotoxy(20,23);
   cout<<"5.DISPLAY THE PRESENT TICKET STATUS ";
   gotoxy(20,25);
   cout<<"6.RAIL YATRA MEMBERS";
   gotoxy(20,27);
   cout<<"7.DISPLAY e-TICKET";
   gotoxy(20,29);cout<<"8.EXIT";
   textcolor(1);
   textbackground(5);

   gotoxy(20,31);
   cout<<"ENTER YOUR CHOICE: ";
   cin>>ch;
   char n;
   switch(ch)
     {//READ TRAIN DETAILS //
      case 1:ifstream fin("Train1.txt",ios::out|ios::in);
	     fin.seekg(0,ios::beg);
	     clrscr();
	     if(!fin)
	       {
		clrscr();
		gotoxy(10,10);
		cout<<"ERROR IN THE FILE !!!";
	       }
	     else
	       {clrscr();
		while(!fin.eof())
		  {
		   fin.read((char*)&tr,sizeof(tr));
		   tr.display();
		  }
	       }
	     fin.close();
	     goto Z;
      case 2://OPEN TO ONLY USER TRAIN UPDATION//
	     clrscr();
	     gotoxy(20,10);
	     cout<<"ENTER THE PASSWORD " ;
	     cin>>j;
	     gotoxy(20,30);
	     cout<<"CHECKING  PLEASE WAIT.....................";
	     delay(2000);
	     if(j==r)
	       {
		Y:
		ofstream fout("Train1.txt",ios::app);
		tr.input();
		fout.write((char*)&tr,sizeof(tr));
		fout.close();
		gotoxy(10,30);
		cout<<"DO YOU WISH TO CONTINUE UPDATING ?(Y/N)";
		cin>>n;
		int kl;
		textcolor(3);
		if(n=='y'||n=='Y')
		   goto Y;
		goto Z;
	       }
	     else
	       {gotoxy(19,20);
	       cout<<"wrong password!!!"; delay(2000);
	       goto Z;}
      case 3:d:tick.reservation();
	     goto Z;
      case 4:tick.cancellation();
	     goto Z;
      case 5:tick.display();
	     goto Z;

      case 6:clrscr();//rail yatra members//
	       {gotoxy(22,25);cout<<"enter user name\n";
		gets(b);
		gotoxy(22,27);cout<<"enter password numerals only ";
	       cin>>a;
	       if((strcmp(b,"BLACKTOR")==0)&&(a==password))
	       {clrscr();gotoxy(22,25);cout<<"welcome vidya shankar\n";
	       gotoxy(22,27);cout<<"loading your details\n";
	       delay(1200);*v++;goto d;}
	       else {cout<<"wrong entry";}
      case 7:tick.tdisplay(); goto Z;
      case 8:exit(0);
      default:gotoxy(25,33); cout<<"wrong input.......ABORTING!!!!";delay(2000);exit(0);
     }
   getch();
   }  }       ;
