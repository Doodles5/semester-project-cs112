#include <iostream>      
#include <windows.h>          //for new interface
#include <conio.h>           //for maths functions
#include <stdlib.h>          //to make input output easy 
#include <string.h>           
#include <time.h>            //for printing current time and date
#include <fstream>           //file handling
#include <cstdio>            


// scanf(%d, &int)  is being used to store the value in specified memory location.  
/// can be replaced with cin if complex



using namespace std;

//global initializing integers

int x; 

int ca(int a);                                      //function for checking accounts

class gikipay{
	
   void check_balance();
   void withdrawl();
   void deposit();
   void transfer();
   void mainexit();                       // initializing member functions to the gikipay class
   void view();                              
   void add();
   void del();
   void edit();
   void search_name();
   void search_acn();                   
  
   
   

//continuous code starts from here.


//data encaptulation
	 
protected: 
          // data hiding
      char id[20],password[15];          //used for logging in the main system 
      
      
   private:
    int choice;                            // choice for admin or user
    
    
   public: // data abstraction
   
       gikipay(){                                      //constructor.
	     
		 cout << "\t\t\t    //////////////////////////////////" << endl;
         cout << "\t\t\t   //------------------------------//" << endl;
         cout << "\t\t\t  ///|        GIKI PAY          |///" << endl;
         cout << "\t\t\t ///----------------------------///" << endl;
         cout << "\t\t\t//////////////////////////////////" << endl;
         cout << "\t\t\t-----------------------------------" << endl;
         cout << "\t\t\t| AAPKAY DIL MAIN HAMARA ACCOUNT |" << endl;
         cout << "\t\t\t-----------------------------------" << endl;                                     
       
	   
	     cout << "CHOOSE ACCOUNT TYPE: ";
         cout << endl;
         
         cout << "[1] . ADMINISTRATOR ";
         cout << "\t\t\t" ;
         cout << "[2] . USER ";
         cout << endl;
         cout << "Enter Your Choice .... ";
         cin >> choice;
         
         if (choice != 1 && choice != 2) {
         	system("cls");// to a new screen  
            gikipay();
         }
         system("cls");
         authentication();
	   }
	   
	 	
	   
	   void authentication() {

      cout << "Welcome to GIKI Pay Banking System - where your finances are in safe hands! "<<endl;

      login();
      cout<<endl<<endl<<endl;
      if (verify() == 1) {
         if (choice== 1)
            main();                  //for admin
         else
            transaction();             // for user
      } 
	  else if (verify() == 0) {
         system("cls");
         cout << "Incorrect Username / Password !!!!";
         cout << endl;
         authentication();
      }
   }
	 
	 
	 
	 void login(){                                    // Takes the user-name and password .

      cout << "Enter The Username : ";
      cin >> id;                                          //initialized globally in gikipay function.

      cout << "Enter The Password : ";
      cin >> password;                                 //initialized globally in gikipay function.
   }

   

	 // verifies the user-name and password .
	 int verify(){ 
      char a;
      if (choice == 1) {                       //if choice is admin 
         
		 if ((strcmp(id, "admin") == 0 && strcmp(password, "admin") == 0)) {

            cout << "You Have Successfully Logged In : " << '"' << id << '"' << endl;
            time_t t;
            time( & t);

            cout << "Logged In Time : " << ctime( & t);

            cout << "Press any key to continue .... ";
            getch();          
            return 1;
         } else
            return 0;
      } else if (choice == 2) {
         if (strcmp(id, "user") == 0 && strcmp(password, "user") == 0) {

            cout << "You Have Successfully Logged In : " << '"' << id << '"' << endl;
            time_t t;
            time( & t);

            cout << "Logged In Time : " << ctime( & t);

            cout << "Press any key to continue .... ";
            getch();
            return 1;
         } else
            return 0;
      }
      return 0;
   }





  void main() {                                            // displays the main user interface screen of program .
     system("cls");

      cout << " WELCOME TO MAIN MENU ";
      cout << endl;

      cout << "[1] . View Customer Accounts";
      cout << endl;

      cout << "[2] . Customer Account Registration";
      cout << endl;

      cout << "[3] . Edit Customer Account";
      cout << endl;

      cout << "[4] . Delete Customer Account";
      cout << endl;

      cout << "[5] . Search Customer Account";
      cout << endl;

      cout << "[6] . Transaction";
      cout << endl;

      cout << "[7] . Log Out !!! ";
      cout << endl;

      cout << "[8] . About US ";
      cout << endl;

      cout << "Please Enter Your Choice [1-8] : ";
      mainchoice();
   }
   
   
   
   
   void mainchoice() {                                        // takes user choice in main  and goes to desired function .
   
      int i;
      cin >> i;
      cout<<endl;
      system("cls");
      
      switch (i) {
      case 1:
         view();
         break;
      case 2:
         add();
         break;
      case 3:
         edit();
         break;
      case 4:
         del();
         break;
      case 5:
         search();
         break;
      case 6:
         transaction();
         break;
      case 7:
         mainexit();
         break;
      case 8:
         about();
         break;
      default:
         main();
      }
   }


	
	
	
	
 void search() {                               //module for searching account ( 2 types by number and name )
 
 system("cls");
      int search_choice;

      cout << " SEARCH MENU: ";
      cout << endl;

      cout << "[1] . Search By Account ";
      cout << endl;

      cout << "[2] . Search By Name ";
      cout << endl;

      cout << "Enter Your Choice [1-2] : ";
      cin>>search_choice;
      system("cls");
      
      if (search_choice== 1) {
         search_acn();
      }
	   else if (search_choice== 2) {
         search_name();
      } else
         main();
   }
  
	
	
	
	
	
	
	
	void transaction(){                        // displays screen for the transaction options and takes the user choice .
	
	system("cls");
	
	  cout << " TRANSACTION MENU ";
      cout << endl;

      cout << "[1] . Balance Inquiry";
      cout << endl;

      cout << "[2] . Cash Deposit";
      cout << endl;

      cout << "[3] . Cash Withdrawal";
      cout << endl;

      cout << "[4] . Fund Transfer";
      cout << endl;
      
      
      if (choice == 1) {
           cout << "[5] . Main Menu";
      } 
	  else {
         cout << "[5] . Exit";
      }
		
		cout<<endl<<endl<<endl;
		
	  cout << "Please Enter Your Choice [1-5] : ";
      int transaction_choice;
      cin>> transaction_choice;
      
      switch (transaction_choice) {
      case 1:
         check_balance();
         break;
      case 2:
         deposit();
         break;
      case 3:
         withdrawl();
         break;
      case 4:
         transfer();
         break;
      case 5:
         if (transaction_choice == 1)
            main();
         else
            mainexit();
         break;
      default:
         transaction();
      }
   }
     
   
   
   
   
   
   
   void about(){
   	
   	  cout << " ABOUT US ";
	  cout<<endl;
	  
      cout << "It is a  Bank Management System Project for our 2nd Semester based on C++ programming language.";
      cout<<endl;
      	
      cout << "Members of Our Team: ";
      cout<<endl;
      	
      	
      	
      cout << "[1] . Saba Hareem Shaikh";
      cout<<endl;
      	
      cout << "[2] . Syed Mojiz Zaidi";
      cout<<endl;
      	
      cout<<"[3] .  Dua Tahir";
      cout<<endl;
      
      cout<<"[4] . Muhammad Abdullah";
      cout<<endl;
      
      
      cout << "Press any key to return back to main menu. ";
      char z = getch();
      
      if (z == 13) {
         main();
      }
   }
	
};               // class gikipay ends here. code of project mile stone 1;  file handling will be done in later classes.







class record {                                                                      //inheritance

   public: 
                                                                       
   char name[25];
   int account;
   char phone[15];
   char address[25];
   char email[35];
   char citizenship_no[20];
   double balance;
   char UserID[10];

};
   
//module for adding accounts.

void gikipay::add(){
	
	
	char choice_add;
	record recs;
	
	//app = append binary / write data to the file.
	
	ofstream xon;       //write data
	
	xon.open("record.bin", ios::app | ios::binary); // data will be written at end of the file
	
	 int i = 0, x;
   // first we evaluate body and check condition
    do {
      system("cls");

      cout << " CUSTOMER ACCOUNT REGISTRATION ";
      cout<<endl;
      
      cout << "[1] . Enter Your Name           : ";
      cin >> recs.name;

      cout << "[2] . Enter Your Account Number : ";
      cin>>recs.account;

      cout << "[3] . Enter Your Phone Number   : ";
      cin >> recs.phone;

      cout << "[4] . Enter Your Address        : ";
      cin >> recs.address;

      cout << "[5] . Enter Your E-mail         : ";
      cin >> recs.email;

      cout << "[6] . Enter Your Citizenship No.: ";
      cin >> recs.citizenship_no;

      cout << "[7] . Enter Amount To Deposit   : $";
      cin>>recs.balance;
                                                        
                                                        
      srand(time(0)); //random number
      
      for (int r = 0; r < 10; r++) {
         recs.UserID[r] = rand() % 10;
      }
      
      //write() = for writing binary data
      // reinterpret_cast - casting one pointer data type to another pointer data type
      //This helps to write contents in a class variable in the file and stores it in the variable rec.
      //char is just a byte , //sizeof gets no. of byte it takes to hold whatevery type rec is

	xon.write(reinterpret_cast < char * > ( & recs), sizeof(recs)); //whatever &rec is treat it as char *
	
	
      cout << "CUSTOMER ACCOUNT REGISTRATION SUCCESSFULL";
      i++;
      cout << endl;
      cout << "Do You Want To Add Another Record ? (Y/N) : ";
      cin>>choice_add;
  }
      
    while (choice_add == 'Y' || choice_add == 'y');
    xon.close();

   cout << "Press any key to return back to main menu. ";
   char z = getch();
   
   if (z == 13) {
      main();
   }
   
    else
      view();
  }
  
  
  
    // module for deleting accout;
  void gikipay::del(){
  	
  	record recs;
  	ifstream con;
  	ofstream xon;
  	
  	int t,p;
  	
  	
  	re:
  		 cout << " DELETE CUSTOMER ACCOUNT ";
  		 cout<<endl;
  		 
  		 cout << "Enter Your Account Number To Delete : ";
         cin>>t;
         
         
         if(ca(t)==1){
         	con.open("record.bin", ios::in | ios::binary);
            xon.open("new.bin", ios::out | ios::binary);                                                 // if{ while  {if}  }
            
            while (con.read(reinterpret_cast < char * > ( & recs), sizeof(recs))) {
                      if (recs.account != t)
                      xon.write(reinterpret_cast < char * > ( & recs), sizeof(recs));
		 }
		 
	  con.close();
      xon.close();
      ifstream xon;
      ofstream con;
      con.open("record.bin", ios::out | ios::binary); // write only
      xon.open("new.bin", ios::in | ios::binary);
      
      
      while (xon.read(reinterpret_cast < char * > ( & recs), sizeof(recs)))
         con.write(reinterpret_cast < char * > ( & recs), sizeof(recs));
      xon.close();
      con.close();	 
  }
  
  else if(ca(t)==0){


     system("cls");
      cout << "Account Doesn't Exist";
      cout<<endl;
      
      
      goto re;
   
  
  }
  
  
   cout << "CUSTOMER ACCOUNT DELETED SUCCESSFULLY";
cout<<endl;
   cout << "Press any key to return back to main menu. ";
   getch();
   main();

}




//module for logging out of the program.
void gikipay::mainexit() { 
   system("cls");

   cout << " THANK YOU ";
cout<<endl;
cout<<endl;
cout<<endl;
   cout << "USER            :: " << id;
   cout<<endl;
   time_t t;
   time( & t);
   cout<<endl;
   cout << "Logged Out Time :: " << ctime( & t);
   cout<<endl;
   fflush(stdin);
   getch();

   exit(0);
}












