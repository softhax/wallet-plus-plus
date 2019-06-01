////////////////////////////////////////////////////////////////////
//                   Made By : Anurag Singh Bhadauria             //
//							   12-A                               //
//							   11                                 //
////////////////////////////////////////////////////////////////////


//***************************************************************//
//                   HEADER FILE USED IN PROJECT				 //
//***************************************************************//

#include <iostream>
#include <fstream>
#include <conio.h>
#include <stdio.h>
#include<stdlib.h>
#include <process.h>
#include <string.h>
using namespace std;
//***************************************************************//
//          CLASSES and CLASS FUNCTIONS USED IN PROJECT			 //
//***************************************************************//


class user{
		char password[10];
		char name[20];
		char address[20];
		int wbal;
		int bbal;
		long int anum;
		long int mnum;

	public:

		user(){wbal=100;bbal=100;}

		void create_user()		//function to get data from new user
		{
			system("cls");
		 	cout<<"\nEnter the following details :\n";
			cout<<"\nEnter Full Name :";
			gets(name);
			cout<<"\n\nEnter Address : ";
			gets(address);
			cout<<"\n\nEnter Mobile Number : ";
			cin>>mnum;
			cout<<"\n\nEnter Bank Account Number : ";
			cin>>anum;
			cout<<"\n\nEnter Bank Balance : ";
			cin>>bbal;
			cout<<"\n\nEnter Wallet Balance : ";
			cin>>wbal;
			cout<<"\nEnter Password for the wallet :";
			gets(password);
			cout<<"\n\n";

		}

		void show_user()		//function to get data from new user
		{
			cout<<"\nName :";
			cout<<name;
			cout<<"\n\nAddress : ";
			cout<<address;
			cout<<"\n\nMobile Number : ";
			cout<<mnum;
			cout<<"\n\nBank Account Number : ";
			cout<<anum;
			cout<<"\n\nBank Balance : ";
			cout<<bbal;
			cout<<"\n\nWallet Balance : ";
			cout<<wbal<<endl;
		}

		long int retmnum()
		{
			return mnum;
		}

		long int retanum()
		{
			return anum;
		}


		int retbbal()
		{
			return bbal;
		}

		char* retpass()
		{
			return password;
		}

		int retwbal()
		{
			return wbal;
		}

		void b2w(int x)
		{
			bbal-=x;
			wbal+=x;
		}

		void add(int x)
		{

			wbal+=x;
		}

		void w2b(int x)
		{
			wbal=wbal-x;
			bbal=bbal+x;
		}

		void subtract(int x)
		{
			wbal-=x;
		}


}su;

//***************************************************************//
//    		                 declarations 				         //
//***************************************************************//

void write_new_user(user u1);
void modify(long int mnum);
void display_sp(long int mnum);
void display_all();
void delete_sp(long int mnum);
void sendmoney(long int mnum);
void transfer_money(long int mnum);
void delete_all();
void paybill(long int mnum);


//***************************************************************//
//    				          user menu 						 //
//***************************************************************//

void user_menu(long int MNUM)
{
	char ch;

	do
	{
		system("cls");
		cout<<"\n\n\n\tMAIN MENU";
		cout<<"\n\n\t01. Send Money";
		cout<<"\n\n\t02. Pay Bills";
	  	cout<<"\n\n\t03. Transfer Money";
	  	cout<<"\n\n\t04. Modify Account Details";
	  	cout<<"\n\n\t05. Delete Account";
	  	cout<<"\n\n\t06. Show Details";
	  	cout<<"\n\n\t07. LOGOUT";
	  	cout<<"\n\n\tPlease Select Your Option (1-7) ";
	  	ch=getch();

	  		switch(ch)
				  	{
						case '1': {system("cls");			//Send Money
								  sendmoney(MNUM);
								  user_menu(MNUM);
								  break;}

					    case '2': {			// Pay Bills
					    					system("cls");
							  			  	int z;
											cout<<"1. Electricity Bill \n";
											cout<<"2. Telephone Bill \n";
											cin>>z;
											if(z==1 || z==2)
											{
												 paybill(MNUM);
												 user_menu(MNUM);
											}

											else{cout<<"Invalid Entry.";}

							  			  break;
					  			  }


					  	case '3': {
					  				system("cls"); 					// Wallet To Bank
					  			  	transfer_money(MNUM);
					  			  	user_menu(MNUM);
					  			 	break;

					  			  }


					  	case '4': {system("cls"); modify(MNUM);break; }// Modify User

					  	case '5': {system("cls"); delete_sp(MNUM);exit(0);} // Delete User

					  	case '6': {
								  	system("cls");
								  	cout<<"\n\n\nCurrent Account Details : "<<endl;
									display_sp(MNUM);
									user_menu(MNUM);
								  	break;
								  } // Delete User

					  	case '7':{
					  				system("cls");
					  				cout<<"You've Been Logged Out\n"<<endl;
					  				getch();
					  				system("cls");
					  				cout<<"Re-Run the program to login again !";
					  				exit(0);
					  			}
					  	default :cout<<"\a";

					}
	}while(ch!='7');


}


//***************************************************************//
//    				   login page function 						 //
//***************************************************************//


void login_page()
{
	system("cls");
	char PASS[20]; long int MNUM;
	cout<<"\t\tLOGIN MENU\n\n";
	cout<<"Enter Mobile Number :"<<endl;
	cin>>MNUM;
	cout<<"Enter Passowrd :"<<endl;
	gets(PASS);
	int flag=0;


			ifstream inFile;
		    inFile.open("db.dat",ios::in|ios::binary);
		    if(!inFile)
		    {
		    	cout<<"Unable To Open Database File......Press any key to return to MAIN Menu \n";
		    	getch();
		    	return;
		    }
			while(inFile.read((char *) &su, sizeof(user)))
			{
				if((su.retmnum()==MNUM) && (strcmp(PASS,su.retpass())==0))
						{flag=1;}
			}
			inFile.close();



	if(flag==1)
	{
		cout<<"LOGIN SUCCESSFUL.....Press Enter To Continue"<<endl;
				getch();
			user_menu(MNUM);
	}

	if(flag==0){cout<<"LOGIN FAILED.";getch();}
}

//***************************************************************//
//    		          register page function                     //
//***************************************************************//

void register_page()
{	user u1,u2;
	u1.create_user();
	fstream File;
    File.open("db.dat",ios::in|ios::out|ios::binary);
    	if(!File)
		    {
		    	cout<<"Unable To Open Database File......Press any key to return to MAIN Menu \n";
		    	getch();
		    	return;
		    }

		while(File.read((char *) &u2, sizeof(u2)))
		{
			if(u1.retmnum()==u2.retmnum())
			{
				cout<<"User With Same Mobile Number Already Exists......Do You Want To Try Again (y/n)\? \n"<<endl;
				char x;
				cin>>x;
						if(x=='y' || x=='Y')
						{
							register_page();
						}

						else if (x=='n' || x=='N')
						{
							return;
						}
			}
		}


	File.close();
	write_new_user(u1);
	return;

}

//***************************************************************//
//    	function to write in file                                //
//***************************************************************//

void write_new_user(user u1)
{

	ofstream outFile;
	outFile.open("db.dat",ios::binary|ios::app);
	outFile.write((char *) &u1, sizeof(user));
	outFile.close();
	cout<<"Wallet ++ Account created successfully."<<endl;
	getch();
}

void display_all()
{

	ifstream inFile;
	inFile.open("db.dat",ios::in|ios::binary);
	cout<<"\n\nUSER LIST\n\n";
	while(inFile.read((char *) &su, sizeof(user)))
	{
		cout<<"\n"<<endl;
		su.show_user();
	}
	inFile.close();

	cout<<"\n\nPress Any Key To Return To ADMINISTRATOR Menu....\n";
	getch();
	return;

}

void display_sp(long int mnum)		//displays specific user
{

	ifstream inFile;
	inFile.open("db.dat",ios::in|ios::binary);

	while(inFile.read((char *) &su, sizeof(user)))
	{		if(su.retmnum()==mnum)
			{
				cout<<"\n"<<endl;
				cout<<"User With Mobile Number "<<mnum<<" is :\n\n";
				su.show_user();
				getch();
			}
	}
	inFile.close();
	return;
}

void sendmoney(long int mnum)				// Send Money
{
	system("cls");
	int amt,flag=0;
	cout<<"Enter Amount To Be Sent : \n";
	cin>>amt;
	long int to;
	cout<<"Enter The Mobile Number Of Receiver : " ;
	cin>>to;
	user receiver;
	user sender;
	fstream File;
	File.open("db.dat",ios::binary|ios::out|ios::in);
	while(File.read((char *) &receiver, sizeof(user)) && flag==0)
		{
			if(receiver.retmnum()==to)
			{
				receiver.add(amt);
				int pos=(-1)*sizeof(user);
				File.seekp(pos,ios::cur);
			    File.write((char *) &receiver, sizeof(user));
			    flag=1;
			}
		}
	File.close();

	if(flag)
	{
		fstream File2;
		File2.open("db.dat",ios::in|ios::binary|ios::out);
		File2.seekp(0,ios::beg);File2.seekg(0,ios::beg);
		while(File2.read((char *) &sender, sizeof(user)))
		{
			if(sender.retmnum()==mnum)
			{
				sender.subtract(amt);
				int pos=(-1)*sizeof(user);
				File2.seekp(pos,ios::cur);
			    File2.write((char *) &sender, sizeof(user));
			    cout<<"\nMoney Sent Successfully\n"<<endl;
			    getch();
			}
		}
		File2.close();
	}

	if(!flag)
	{
		cout<<"\n\n Record Of Receiver Not Found !!!\n";
		getch();
	}
	return;
}

void modify(long int mnum)		//Modify User
{
	/*ifstream inFile;int pos;
	inFile.open("db.dat",ios::in|ios::binary);
	while(inFile.read((char *)&su, sizeof(user)))
	{
		if(su.retmnum()==mnum)
		{
			pos=inFile.tellg();
		}
	}
	inFile.close();

	ofstream outFile;
	outFile.open("db.dat",ios::out|ios::binary);
	su.create_user();
	outFile.seekp(pos-sizeof(su),ios::beg);
	outFile.write((char *)&su, sizeof(user));
	cout<<"\nUser Details Modified Successfully."<<endl;
	getch();
	outFile.close();
	return;*/

	fstream File;user X; int flag=1;
	File.open("db.dat",ios::in|ios::out|ios::binary);
	while(File.read((char *)&X, sizeof(user)))
	{
		if(X.retmnum()==mnum)
		{	flag=1;
			X.create_user();
			int pos=(-1)*sizeof(user);
			File.seekp(pos,ios::cur);
			File.write((char *)&X, sizeof(user));
			cout<<"\nUser Details Modified Successfully."<<endl;
			getch();
			File.close();
		}
	}

	if(!flag)
	{
		cout<<"\nRecord NOT FOUND !!!\n";
		getch();
	}

	return;

}

void delete_all()				//Delete All Records
{
		system("cls");
	  	char d;
	  	cout<<"Are you sure you want to delete all records ? (y/n) \n";
	  	cin>>d;
	  	if(d=='y'|| d=='Y')
	  		{
	  			remove("db.dat");
	  			cout<<"All records deleted ! \n";
	  			getch();

	  		}
	return;
}

void delete_sp(long int mnum)		//Delete Specific Record
{
	user U1;int flag=0;
	fstream File1,File2;
	File1.open("db.dat",ios::in|ios::binary);
	File2.open("temp.dat",ios::binary|ios::out);
	while(File1.read((char *) &U1, sizeof(user)))
	{
		if(mnum==U1.retmnum())
			{
				flag=1;
			}

		if(U1.retmnum()!=mnum)
			{
				File2.write((char *) &U1, sizeof(user));
			}
	}
	File1.close();
	File2.close();

	if(flag)
	{
		remove("db.dat");
		rename("temp.dat","db.dat");
		cout<<"User Deleted Successfully. \n";
		getch();
	}
	if(!flag){
			cout<<"\nSpecified User Details Not Found !!!"<<endl;
			getch();
	}

	return;
}

void paybill(long int mnum)			// Bill Payment
{
		system("cls");int pos;
		int found=0,flag=1;
		long int billnum; int amt;
		cout<<"Enter Bill Number :\n";
		cin>>billnum;
		cout<<"Enter Amount To Be Payed : \n";
		cin>>amt;
		ifstream inFile;
		inFile.open("db.dat",ios::in|ios::binary);

			while(inFile.read((char *) &su, sizeof(user)) && found==0)
			{
				if(su.retmnum()==mnum)
				{	found=1;
					pos=inFile.tellg();
					su.subtract(amt);
					cout<<"\n\n"<<su.retwbal()<<endl;
					if(su.retwbal()<0)
						{	flag=0;
							su.add(amt);
							cout<<"Insufficient Wallet Balance.....Unable To Pay Bill.";
							getch();

						}
				}

			}

		inFile.close();
		if(found==1 && flag==1)
		{
			ofstream outFile;
			outFile.open("db.dat",ios::binary|ios::out);
			outFile.seekp((pos-sizeof(su)),ios::beg);
			outFile.write((char *)&su,sizeof(user));
			cout<<"Bill payment done successfully.";
			getch();
			outFile.close();
		}
		return;
}


void transfer_money(long int mnum) 			// 1. Wallet To Bank
{							   				// 2. Bank To Wallet

	user X;
	fstream File; int flag=0;
	File.open("db.dat",ios::in|ios::out|ios::binary);
	File.seekp(0,ios::beg);File.seekg(0,ios::beg);
	while(File.read((char *)&X, sizeof(user)))
	{
		if(X.retmnum()==mnum)
		{	flag=1;
			int z,amt;
			cout<<"1. Wallet To Bank \n";
			cout<<"2. Bank To Wallet \n";
			cin>>z;
			cout<<"Enter Amount : \n" ;
			cin>>amt;


				if(z==1)	// Wallet To Bank
				{
					X.w2b(amt);
					cout<<"Money Transferred To Wallet Successfully. "<<endl;
					getch();
			    }

				if(z==2)	// Bank To Wallet
				{
					X.b2w(amt);
					cout<<"Money Transferred To Bank Successfully. "<<endl;
					getch();
			    }

			int pos=(-1)*sizeof(user);
			File.seekp(pos,ios::cur);
			File.write((char *)&X, sizeof(user));
			File.close();
		}
	}

	if(!flag)
		{
			cout<<"\nRecord NOT FOUND !!!\n";
			getch();
		}

	return;
}

//***************************************************************//
//    			  administrator page function 					 //
//***************************************************************//

void admin_page()
{
	char ch;

	do
	{
			system("cls");
			cout<<"\n\n\n\tADMINISTRATOR MENU";
			cout<<"\n\n\t01. Display All Users ";
			cout<<"\n\n\t02. Display Specific User";
		  	cout<<"\n\n\t03. Create New User";
		  	cout<<"\n\n\t04. Modify Specific User";
		  	cout<<"\n\n\t05. Delete Specific User";
		  	cout<<"\n\n\t06. Delte All Records";
		  	cout<<"\n\n\t07. Exit";
		  	cout<<"\n\n\tPlease Select Your Option (1-7) ";
		  	ch=getch();
		  	switch(ch)
		  	{
				case '1': {
							system("cls");
							display_all();
							break;
						  }

			  	case '2': {
			  				system("cls");
					  		long int num;
							cout<<"Enter The Mobile No of User To Be Displayed : "<<endl;
							cin>>num;
			  				display_sp(num);
			  				break;
			  			  }

			  	case '3': {system("cls");register_page();break;}
			  	case '4': {
			  				system("cls");
					  		long int num;
							cout<<"Enter The Mobile No of User To Be Modified : "<<endl;
							cin>>num;
			  				modify(num);
			  				break;
			  			}
			  	case '5': {
			  				system("cls");
					  		long int num;
							cout<<"Enter The Mobile No of User To Be Deleted : "<<endl;
							cin>>num;
			  				delete_sp(num);
			  				admin_page();
			  				break;
			  			}
			  	case '6': {	 system("cls");
			  				char d;
			  				cout<<"Are you sure you want to delete all records ? (y/n) \n";
			  				cin>>d;
			  				if(d=='y'|| d=='Y')
			  					{remove("db.dat");cout<<"All records deleted ! \n";}
			  				break;
			  			  }
			  	case '7': return;
			  	default :cout<<"\a"<<endl;
			}
    }while(ch!='7');
}



//***************************************************************//
//    				THE MAIN FUNCTION OF PROGRAM				 //
//***************************************************************//


int main()
{
	char ch;

			do
			{
				system("cls");
				cout<<"\n\n\n\tMAIN MENU";
				cout<<"\n\n\t01. LOGIN TO WALLET";
				cout<<"\n\n\t02. CREATE WALLET";
			  	cout<<"\n\n\t03. ADMINISTRATOR MENU";
			  	cout<<"\n\n\t04. EXIT";
			  	cout<<"\n\n\tPlease Select Your Option (1-4) ";
			  	ch=getch();
			  	switch(ch)
			  	{
					case '1':login_page(); break;
				  	case '2':register_page(); break;
				  	case '3':admin_page(); break;
				  	case '4':exit(0);
				  	default :cout<<"\a";
				}

		    } while(ch!='4');

		    return 0;
}


//***************************************************************//
//    			END OF PROJECT									 //
//***************************************************************//
