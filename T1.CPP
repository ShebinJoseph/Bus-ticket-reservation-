#include <iostream.h>
#include <conio.h>
#include <process.h>
#include <fstream.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

login(int mode=0)
{
    char username[50]="\0", *pasword=NULL;
    cout<<"\n\nPlease Login With Username And Password"<<endl;
    cout<<"-->Enter Username:"<<endl;
    cin>>username;
    cout<<"-->Enter Your Password:"<<endl;
    pasword=getpass("--Type Password here and press Enter Key-->");
    if(mode==1)
    {
      if(!strcmpi(username,"admin")==0)
      {
       cout<<"----------You do not have administrative privelages----------"<<endl;
       getch();
       return 0;
      }
    }
    fstream fil("login22.txt",ios::in);
    char usr[50]="\0",pas[50]="\0";
    int found=0;
    fil.seekg(0);
 while(!fil.eof())
  {
fil>>usr>>pas;
if(strcmp(usr,username)==0&&strcmp(pas,pasword)==0)
{
found=1;
return 1;
}
}
if(found==0)
 {
  cout<<"----Username Or Password Does Not Match.....TRY AGAIN---- "<<endl;
  getch();
 }
return 0;
}


class reser
{
public:
int pnr;
int busno;
char bname[100];
char bp[100];
char dest[100];
char pname[10][100];
int age[20];
int nosr;
int i;
int d,m,y;
void displaypas();
void getresdet();
void displayresdet();
int returnpnrno()
{
  return pnr;
}
};

class bus
{
     public : char busname[50];
	       char busno[50];
	       char time[50];
	       char board[50];
	       char bustype[50];
	       char dest[50];
	       char buscat[50];
	       int seats;
	       char bp[50];
	       char pnr[50];
	       char d[50];
	       char m[50];
	       char y[50];

     public :
	      void getdata();
	      void displaydata();
	      char* returnbusno()
	      {
	       return busno;
	      }

	      int returnnoseats()
	      {
	       return seats;
	      }

	      void updateseat(int no)
	      {
		int temp;
		temp =seats;
		seats =seats-no;
		if(seats<0)
		seats=temp;
	      }}bob;


	      void bus :: getdata()
	      {
	      cout<<"-->Enter The Bus-Name:\t "<<endl;
	      gets(busname);
	      cout<<"-->Enter The Bus-Number:\t "<<endl;
	      gets(busno);
	      cout<<"-->Enter The Arrival Time:\t "<<endl;
	      gets(time);
	      cout<<"-->Enter The Boarding Point:\t"<<endl;
	      gets(board);
	      cout<<"-->Enter The Destination:\t"<<endl;
	      gets(dest);
	      cout<<"-->Enter The Bustype [AC/Non-AC]:\t"<<endl;
	      gets(bustype);
	      cout<<"-->Enter The Bus Category:\t"<<endl;
	      gets(buscat);
	      cout<<"-->Enter total No: Of Seats In The Bus:\t"<<endl;
	      cin>>seats;
	      }


	      void bus :: displaydata()
	      {
	      cout<<"<>Bus-Name-->      "<<busname<<endl;
	      cout<<"<>Bus-Number-->    "<<busno<<endl;
	      cout<<"<>Time-->          "<<time<<endl;
	      cout<<"<>Bording Point--> "<<board<<endl;
	      cout<<"<>Destination-->   "<<dest<<endl;
	      cout<<"<>Bus-Type-->      "<<bustype<<endl;
	      cout<<"<>Bus Category-->  "<<buscat<<endl;
	      getch();
	      }

     void createdatabase()
     {
       clrscr();
       bus bc;
       int n=0;
       fstream fil;
       cout<<"Enter How Many Bus Details You Want To Create ?"<<endl<<endl;
       cin>>n;
	fil.open("busres.dat",ios::out|ios::ate|ios::binary);
       for(int i=0;i<n;i++)
       {
	  cout<<"--|> Enter Bus Details <|--"<<endl;
	  bc.getdata();
	  fil.write((char*)&bc,sizeof(bc));
       }
       fil.close();
     }

     char* findseat(char no[50])
     {
       int found=0;
       fstream filread("busres.dat",ios::in|ios::binary);
       filread.seekg(0);
       while(!filread.eof())
       {
	 filread.read((char*)&bob,sizeof(bob));
	 if(strcmpi(bob.returnbusno(),no)==0)
	 {	found=1;
		if(bob.returnnoseats()>0)
		{
		cout<<"Seats Available : Press any key to continue\n"<<endl;
		cout<<"Bus Number :    \t"<<bob.returnbusno()<<endl;
		cout<<"Seats Available:\t"<<bob.returnnoseats();
		getch();
		return bob.returnbusno();
		}
		else
		{
		cout<<"-----> Seats full <-----"<<endl;
		getch();
		}
	 }
       }
       if(found==0)
       {
	 cout<<"Bus Number Not Found...............Press Any Key To Continue...."<<endl;
	 getch();
       }
       filread.close();
       return " ";
     }

     void bookseat(char no[])
     {
       int noseats=0,found=0;
       cout<<"Enter How Many No: Of Seats You Want To Book --> "<<endl;
       cin>>noseats;
       fstream fil;
       fil.open("busres.dat",ios::out|ios::ate|ios::in);
       fil.seekg(0);
       while(!fil.eof())
       {
	 fil.read((char*)&bob,sizeof(bob));
	 int pos = fil.tellp();
	 if(strcmpi(bob.returnbusno(),no)==0)
	 {
		found=1;
		if(bob.returnnoseats()>0)
		{
		    bob.updateseat(noseats);
		    fil.seekg(pos-sizeof(bob));
		    fil.write((char*)&bob,sizeof(bob));
		    break;
		}
		else
		{
		cout<<"----Seats full----"<<endl;
		getch();
		}
	 }
       }
       if(found==0)
       cout<<"---------Bus Number Not Found---------"<<endl;
       getch();
}

void reser::getresdet()
{
clrscr();
cout<<"-----Enter The Detail As Follows-----\n";
cout<<"-->Enter The Ticket No:"<<endl;cin>>pnr;
cout<<"-->Enter The Bus-No:"<<endl;cin>>busno;
cout<<"-->Enter The Bus-Name:"<<endl;gets(bname);
cout<<"-->Enter Your Desired Boarding Point:"<<endl;gets(bp);
cout<<"-->Enter Your Desired Destination Point:"<<endl;gets(dest);
cout<<"-->No of seats required:"<<endl;cin>>nosr;
for(i=0;i<nosr;i++)
{
cout<<"-->Passenger Name:"<<endl;gets(pname[i]);
cout<<"-->Passenger Age:"<<endl;cin>>age[i];
}
cout<<"-->Date Of Travel [dd-mm-yyyy]:"<<endl;
cin>>d>>m>>y;
cout<<"..................END OF GETTING DETAILS............\n";
}

void reser::displayresdet()
{
cout<<"-----------------------------------------------------\n";
cout<<"--------------------BUS TICKET-----------------------\n";
cout<<"-----------------------------------------------------\n";
cout<<"Ticket No:               "<<pnr;
cout<<"\nBus no:                  "<<busno;
cout<<"\nBus name:                ";puts(bname);
cout<<"\nBoarding Point:          ";puts(bp);
cout<<"\nDestination Point:       ";puts(dest);
cout<<"\nNo: Of Seats Reserved:   "<<nosr;
for (i=0;i<nosr;i++)
{
cout<<"\nPassenger Name:          ";puts(pname[i]);
cout<<"\nPassenger Age:           "<<age[i];
}
cout<<"\nDate Of Reservation:     "<<d<<"-"<<m<<"-"<<y<<endl;
cout<<"\nTicket Fare:             "<<endl;
cout<<"*****************************************************\n";
cout<<"...............->->-HAPPY JOURNEY-<-<-...............\n";
cout<<"*****************************************************\n";
}

void res()
{
  fstream f;
  reser re;
  re.getresdet();
  f.open("res.dat",ios::out|ios::app|ios::binary);
  f.seekg(0);
  f.write((char*)&re,sizeof(re));
  f.close();
}

void displayreservation()
{
  fstream f;
  reser re;
  long pnrno=0;
  clrscr();
  cout<<"-->Enter Your Ticket-No: "<<endl;
  cin>>pnrno;
  int found=0;
  f.open("res.dat",ios::in|ios::binary);
  f.seekg(0);
  while(f.read((char*)&re, sizeof(re)))
  {
   if(re.returnpnrno()==pnrno)
   {
       found=1;
       re.displayresdet();
       getch();
       break;
   }
  }
  if(found==0)
  cout<<"----------Ticket Number Not Found---------"<<endl;
  f.close();
}

void cancel()
{
bus a;
reser b;

fstream f1,f2,f3;
f1.open("res.dat",ios::in|ios::binary);
f2.open("canc.dat",ios::out|ios::binary);
int found=0,n=0;
clrscr();
cout<<"Enter The Ticket Number You Want To Cancel : "<<endl;
cin>>n;
while(f1.read((char*)&b,sizeof(b)))
{
   if(!(b.returnpnrno()==n))
   {
      f2.write((char*)&b,sizeof(b));
   }
}
f1.close();
f2.close();
remove("res.dat");
rename("canc.dat","res.dat");
if(found!=0)
{
  cout<<"----------Ticket number Not Found----------"<<endl;
  getch();
}
}



void busdisplaydetails()
{
       bus bc;
       char n[50]="\0";
       fstream fil;int found=0;
       clrscr();
       cout<<"-->Enter The Bus-Number For Displaying Details: "<<endl;
       gets(n);
       fil.open("busres.dat",ios::in|ios::binary);
       fil.seekg(0);
       while(fil.read((char*)&bc,sizeof(bc)))
       {
	if(strcmpi(bc.returnbusno(),n)==0)
	{
	 found=1;
	 bc.displaydata();
	 break;
	}
       }
       if(found==0)
       {
	 cout<<"---------Bus Information Not Found---------"<<endl;
	 getch();
       }
       fil.close();
}
      void main()
      {
       int choice1=0;
	   do
	   {
	    clrscr();
	    cout<<"--------------------------------"<<endl;
	    cout<<"------------MAIN MENU-----------"<<endl;
	    cout<<"--------------------------------"<<endl;
	    cout<<"Select Your Desired Mode:"<<endl;
	    cout<<" 1.ADMIN MODE"<<endl;
	    cout<<" 2.USER MODE"<<endl;
	    cout<<" 3.Exit"<<endl;
	    cout<<" Enter Your Choice"<<endl;
	    cin>>choice1;
	       switch (choice1)
		       {
			case 1:
				int accept1=0;
				accept1=login(1);
				if(accept1==1)
				{
				   int choice2=0;
				   do
					{
						clrscr();
						cout<<"-----------------------------"<<endl;
						cout<<"-----ADMINISTRATIVE MENU-----"<<endl;
						cout<<"-----------------------------"<<endl;
						cout<<"1.Create Bus Details"<<endl;
						cout<<"2.Display Passenger Details"<<endl;
						cout<<"3.Display Bus Deatils"<<endl;
						cout<<"4.Exit"<<endl;
						cout<<"Enter Your choice"<<endl;
						cin>>choice2;
						switch (choice2)
						{
						case 1:
							createdatabase();
						break;
						case 2: displayreservation();
						break;
						case 3: busdisplaydetails();
							break;
						case 4:break;
						}
					}
					while (choice2!=4);
				}
				break;

			case 2: int accept2=0;
				accept2=login();
				if(accept2==1)
				{
				   int choice3=0;
				   do
					{
						clrscr();
						cout<<"--------------------------------------"<<endl;
						cout<<"--------------USER MENU---------------"<<endl;
						cout<<"--------------------------------------"<<endl;
						cout<<"1.Reserve Bus Ticket"<<endl;
						cout<<"2.Display Ticket Details"<<endl;
						cout<<"3.Enquire Ticket For A Bus"<<endl;
						cout<<"4.Cancel Your Bus-Ticket"<<endl;
						cout<<"5.Exit"<<endl;
						cout<<"Enter choice"<<endl;
						cin>>choice3;
						switch(choice3)
						{
						case 1: res();
							break;
						case 2:displayreservation();
							cout<<"Press any key to continue"<<endl;
							getch();
							break;
						case 3: char confirm='\0'; char wbusno[50]="\0";
							clrscr();
							cout<<"Enter The Bus Number For Enquiring About Ticket:"<<endl;
							gets(wbusno);
							char bnumb[50]="\0";
							strcpy(bnumb,findseat(wbusno));
							break;

						case 4: cancel();
							cout<<"Press Any Key To Continue.."<<endl;
							getch();
						break;
						case 5:break;
						}
					}
					while (choice3!=5);
				}
				break;

			case 4:exit(0);
		       }
	    }
	    while (choice1!=3);
	    cout<<"Exiting out of the application..Press any key to continue..."<<endl;
	    getch();
}