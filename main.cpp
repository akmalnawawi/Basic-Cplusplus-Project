#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>
#include <math.h>
#include <cstdlib>
#include <cctype>
#define SIZE 10
using namespace std;
//global scope declaration

//train name and price
float price=0;
float priceT1 = 1.0, priceT2 = 2.0, priceT3 = 1.50;
int num [3]= {1,2,3};
char trainName1[20]={"KTM"};
char trainName2[20]={"LRT"};
char trainName3[20]={"Monorel"};

//bus name and price
float priceB1 = 80, priceB2 = 120, priceB3 = 60;
char busName1[20]={"Sani Express"};
char busName2[20]={"Mayang Suri"};
char busName3[20]={"Ekspedisi"};

//plane name and price
float priceF1 = 70000, priceF2 = 90000;
char planeName1[20]={"Domestic"};
char planeName2[20]={"Economy"};

//global declaration for 
int g_count=0;
double overall=0.00;
extern const string u1 = "USER" , u2 = "ADMIN"; //keep this constant and cant be used by other
extern const string time = "evening";
//struct declaration
struct userDB {
	string name;
	string user_id;
	string phoneNum;
	double balance;
}user[SIZE];


void UserSignup(), UserLogin(), UserUI(int ), User(), Admin(), adminlogin(),
	 adminsignup(), adminsite(), option(), trainPrice(char ), flightPrice(char ), 
	 busPrice(char ), busOption(), trainOption(), flightOption(), editBusPrice(), 
	 editTrainPrice(), editFlightPrice(), Userbalance(int ), receiptinfile(int , double , int),
	 ViewPublicTrans();
double calculation(double ,double ,char );
	 
int main(){
	int option;
	cout << "CONNECTED - ALL IN ONE SYSTEM\n"
		 << "------------------------------\n"
		 << "Hello, good " << time << "\n" <<endl;
	cout << "(1) User Site \n"
		 << "(2) Admin Site\n" << endl;
	cout << "Code: ";
	cin >> option;
	while (option < 1||option > 2){
		cout << "Invalid option:";
		cin >> option;
	}//while loop incase the user enter wrong option
	if(option==1)
		User();//seperate the func to User(); for user
	if(option==2)
		Admin();//seperate the func to Admin(); for admin
	return 0;
}
void Admin(){
	int code;
	cout<<"\n\nCONNECTED"<<endl;
	cout<<"Admin"<<endl;
	cout<< "------------------------------\n";
	cout<<" (1) Log in\n"<<" (2) Sign up\n"<<"\nEnter code: ";
	cin>>code;
	
	
	switch(code)//to determine which code admin choose
	{
		case 1:
		{
			system("cls");
			adminlogin(); //seperate the func to adminlogin(); if they already had the id
			break;
		}
		case 2:
		{
			system("cls");
			adminsignup();//seperate the func to adminsignup(); if they haven't sign up yet
			break;
		}
		default: //this works as repeater incase admin enter the wrong code input
		{
			cout<<"\nYou have entered the wrong code!"<<endl;
			cout<<"Please re-enter the code"<<endl<<endl;
			system("pause");
			system("cls");
			main();
		}	
	}
}
void adminlogin() //func works as admin log in site
{
	int count, n=0;
	string username, password, un, pw;
	cout<<"\n\nCONNECTED"<<endl;
	cout<<"Admin Log-In "<<endl;
	cout<< "------------------------------\n";
	cout<<"Username: ";
	cin>>username;
	cout<<"\nPassword: ";
	cin>>password;
	
	ifstream login("admin.txt");//stream used for read the data from admin.txt file
		
	while(login>>un>>pw)//if password  was true,the admin will brings to adminsite();
	{
		if (un == username && pw == password)
		{
			count=1;
			system("cls");
		}
		login.close();
		
		if(count==1)
		{
			adminsite();//seperate func to bring admin to adminsite
		}
		else
		{
			cout<<"Invalid username password"<<endl;
			cout<<"Return to exit"<<endl<<endl;
			system("pause");
			Admin();
		}
	}
}
void adminsignup()//func for admin that haven't sign up yet
{
	string name,username, password;
	int staffNum;
	cout<<"\n\nCONNECTED"<<endl;
	cout<<"Admin Sign-Up"<<endl;
	cout<< "------------------------------\n";
	cout<<"Please enter all the details below: \n";
	cout<<"\nName: ";
	cin.ignore();//to ignore whitespace for next prompt
	getline(cin, name);
	cout<<"Staff number: ";
	cin>>staffNum;
	cout<<"Create username: ";
	cin>>username;
	cout<<"password: ";
	cin>>password;
	
	ofstream signup("admin.txt",ios::app); //operations performed at the end of the file
	signup<<username<<' '<<password<<endl; //file was created and the information was wrote on the file
	system("cls");
	
	cout<<endl<<endl;
	cout<<"CONNECTED"<<endl;
	cout<<"Admin Sign-Up"<<endl;
	cout<< "------------------------------\n";
	cout<<" \tSucessfully registered as admin"<<endl;
	
	system("pause");
	system("cls");
	adminsite();//back to adminsite after successfully registered,so the admin could log in into the system
}
void adminsite()//func determine what admin will looks after they login
{
	int optionTrans,k;
	double *totalsales;//pointer declaration
	double price;
	
	cout<<endl<<endl;
	cout<<"CONNECTED"<<endl;
	cout<<"Admin Site "<<endl<<endl;
	cout<< "------------------------------\n";
	cout<<"WELCOME!\n"<<endl;
	
	
	cout << "1.Public Transport\n" <<"2.User database\n"<<"3.Total sales\n"<<"4.Exit"<<endl;
	cout << "\nEnter Your choice : ";
	cin >> optionTrans;

	
	switch (optionTrans)//works as algorithm that will determine what admin will see based on their input into the system
	{
		case 1:
		{
	        option ();//seperate the func to brings admin to option();
			break;	
		}
		case 2: //print out all user that already sign up on the system,currently we only set total user can signup is 10 as maximum
		{
			cout << "\nCONNECTED - " << u1 << "DATABASE\n"
			 	 << "--------------------------------\n" << endl;
			for(int i=0;i<SIZE;i++){
				cout << "Name: " << user[i].name << endl;
				cout << "Phone No: " << user[i].phoneNum << endl;
				cout << "User id: " << user[i].user_id << endl;
				cout << "--------------------------" << endl;
			}
		}
		case 3: //print out total sales based on the public transport has been taken by user
		{
			cout << "\nTotal Sales: RM" << (totalsales = &overall) << endl;
		}
		case 4: //admin exit or log out from the program
		{
			main(); //admin is logout
			break;
		}
		default: 
		{
			cout<<"\nYou have entered the wrong code!"<<endl;
			cout<<"Please re-enter the code"<<endl<<endl;
			system("pause");
			system("cls");
			adminsite(); //recursive func occurs when admin enter wrong prompt
		}
	}
	
}
void trainPrice() //To view public transport - train
{
		system("cls");
	  	cout.setf(ios::fixed);
	  	cout.setf(ios::left);
	  	cout.precision(2);
	  	cout<<" \t\t\t\t _______________________________________________\n";
		cout<<" \t\t\t\t|                                               |\n"; 	  	
	  	cout<<" \t\t\t\t|    CODE         TRAIN            TOTAL        |\n";
	    cout<<" \t\t\t\t|    [T"<<num[0]<<"]\t  "<<setw(10)<<trainName1<<"\t   RM"<<priceT1<<"\t|\n";
	    cout<<" \t\t\t\t|    [T"<<num[1]<<"]\t  "<<setw(10)<<trainName2<<"\t   RM"<<priceT2<<"\t|\n";
	    cout<<" \t\t\t\t|    [T"<<num[2]<<"]\t  "<<setw(10)<<trainName3<<"\t   RM"<<priceT3<<"\t|\n";
		cout<<" \t\t\t\t|_______________________________________________|"<<endl;	
	
}
void busPrice() //To view public transport - bus
{
		system("cls");
		cout.setf(ios::fixed);
	  	cout.setf(ios::left);
	  	cout.precision(2);
	  	cout<<" \t\t\t\t _______________________________________________\n";
		cout<<" \t\t\t\t|                                               |\n"; 	  	
	  	cout<<" \t\t\t\t|    CODE          BUS             TOTAL        |\n";
	    cout<<" \t\t\t\t|    [B"<<num[0]<<"]\t  "<<setw(10)<<busName1<<"\t   RM"<<priceB1<<"\t|\n";
	    cout<<" \t\t\t\t|    [B"<<num[1]<<"]\t  "<<setw(10)<<busName2<<"\t   RM"<<priceB2<<"\t|\n";
	    cout<<" \t\t\t\t|    [B"<<num[2]<<"]\t  "<<setw(10)<<busName3<<"\t   RM"<<priceB3<<"\t|\n";
		cout<<" \t\t\t\t|_______________________________________________|"<<endl;

}

void flightPrice() //To view public transport - flight
{
		system("cls");
		cout.setf(ios::fixed);
	  	cout.setf(ios::left);
	  	cout.precision(2);
	  	cout<<" \t\t\t\t _______________________________________________\n";
		cout<<" \t\t\t\t|                                               |\n"; 	  	
	  	cout<<" \t\t\t\t|    CODE         FLIGHT         PRICE          |\n";
	    cout<<" \t\t\t\t|    [F"<<num[0]<<"]\t  "<<setw(10)<<planeName1<<"\tRM"<<priceF1<<"\t|\n";
	    cout<<" \t\t\t\t|    [F"<<num[1]<<"]\t  "<<setw(10)<<planeName2<<"\tRM"<<priceF2<<"\t|\n";
		cout<<" \t\t\t\t|_______________________________________________|"<<endl;
	
}

void option() //Func works as option for the admin to choose for the next site
{
	system("cls");
	char PubTrans;
	    	cout<<" \t\t\t\t   _____________________________________________\n";
	    	cout<<" \t\t\t\t  |                                             |\n"; 	  	
	    	cout<<" \t\t\t\t  |           CODE            Transport         |\n";
	        cout<<" \t\t\t\t  |           [T]              TRAIN            |\n";
	     	cout<<" \t\t\t\t  |           [B]              BUS              |\n";       
	        cout<<" \t\t\t\t  |           [F]              FLIGHT           |\n";
     		cout<<" \t\t\t\t  |_____________________________________________|"<<endl;   
            cout << "\nEnter public transport :";
        	cin >> PubTrans;
			
			
	        if(toupper(PubTrans)=='T')
              {
               trainOption(); //brings admin to trainOption() func
              }
	        else if(toupper(PubTrans)=='F')
	        {
	        	flightOption(); //brings admin to flightOption() func
	        }
            else if(toupper(PubTrans)=='B')
			{
           		busOption();   //brings admin to busOption() func
           	}
            else 
			{
				cout<<"\nYou have entered the wrong code!"<<endl;
				cout<<"Please re-enter the code"<<endl<<endl;
			 	cout<<setw(50)<<setfill('*')<<endl;
			 	system("pause");
			 	system("cls");
				option(); //func will recursive if admin put wrong input
			}
			
}

void busOption() //func works as editor for the price 
{
	system ("cls");
    busPrice(); //calls func busPrice()
	int choose;
	cout<<endl<<endl;
	cout<<"CONNECTED"<<endl;
	cout<<"Public Transport "<<endl<<endl;
	cout<< "------------------------------\n";
	cout<<"1.Edit Price\n" << "2.Logout\n"<<"3.To main page\n"<<endl;
	
	cout<<"Choose your option : "<<endl;
	cin>>choose;
	
	switch (choose)
	{
		case 1:
			{
			    editBusPrice(); //brings to func where admin can edit price
				break;
			}
		case 2:
			{
				system ("cls"); //logout from the admin
				main();
				break;
			}
		case 3:
			{
				adminsite(); //back to main page of admin
				system ("pause");
				break;
			}
	
		default:
			{
				cout<<"\nYou have entered the wrong code!"<<endl;
				cout<<"Please re-enter the code"<<endl<<endl;
				system("pause");
				system("cls");
				busOption(); //repeat if enter wrong prompt
			}
	}
	
}

void trainOption() //func works as editor for the price
{
	system ("cls");
    trainPrice(); //call func trainPrice();
	int choose;
	cout<<endl<<endl;
	cout<<"CONNECTED"<<endl;
	cout<<"Public Transport "<<endl<<endl;
	cout<< "------------------------------\n";
	cout<<"1.Edit Price\n" << "2.Logout\n"<<"3.To main page\n"<<endl;
	
	cout<<"Choose your option : "<<endl;
	cin>>choose;
	
	switch (choose)
	{
		case 1:
			{
			    editTrainPrice(); //brings to func where admin can edit price
				break;
			}
		case 2:
			{
				system ("cls");
				main(); //logout from the admin
				break;
			}
		case 3:
			{
				adminsite();
				system ("pause");//back to main page of admin
				break;
			}
		default:
			{
				cout<<"\nYou have entered the wrong code!"<<endl;
				cout<<"Please re-enter the code"<<endl<<endl;
				system("pause");
				system("cls");
				trainOption(); //repeat if enter wrong prompt
			}
	}
	
}

void flightOption() //func works as editor for the price
{
	system ("cls");
    flightPrice(); //call func
	int choose;
	cout<<endl<<endl;
	cout<<"CONNECTED"<<endl;
	cout<<"Public Transport "<<endl<<endl;
	cout<< "------------------------------\n";
	cout<<"1.Edit Price\n" << "2.Back to main page\n"<<"3.To main\n"<<endl;
	
	cout<<"Choose your option : "<<endl;
	cin>>choose;
	
	switch (choose)
	{
		case 1:
			{
			    editFlightPrice(); //brings to func where admin can edit price
				break;
			}
		case 2:
			{
				system ("cls");
				main (); //logout
				break;
			}
		case 3:
			{
				adminsite(); //back to main page of admin
				system ("pause");
				break;
			}
		default:
			{
				cout<<"\nYou have entered the wrong code!"<<endl;
				cout<<"Please re-enter the code"<<endl<<endl;
				system("pause");
				system("cls");
				flightOption(); //repeat if enter wrong prompt
			}
	
	}
	
	
}

void editBusPrice() //func works for editing the price
{	
	int i;
	
	cout<<"\n Select a bus you want to edit(1/2/3) : Num ";
	cin>>i;
	
	if (i==1) //for first bus
	{
	 float newprice; 
	
	cout<<"Enter new price for bus 1 :";
	cin>>newprice;
	
	priceB1 = newprice; //old price replaced by new price
	
	 busPrice();
		
	}
	else if (i==2) //for second bus
	{
	
	float newprice;
	
	cout<<"Enter new price for bus 2 :";
	cin>>newprice;
	
	priceB2 = newprice; //old price replaced by new price
	
	 busPrice();
	}
	else if (i==3) //for third bus
	{
		
	float newprice;
	
	cout<<"Enter new price for bus 3 :";
	cin>>newprice;
	
	priceB3 = newprice; //old price replaced by new price
	
	 busPrice();
	}
		
	else
	{
		cout<<"\n Please enter the exist transport.";
		
		editBusPrice(); //repeat if wrong input
	}
	option() ;
		
}

void editTrainPrice() //func works for editing the price
{	
	int i;
	
	cout<<"\n Select a train you want to edit(1/2/3) : Num ";
	cin>>i;
	
	if (i==1) //for first train
	{
	 float newprice;
	
	cout<<"Enter new price for train 1 :";
	cin>>newprice;
	
	priceT1 = newprice; //old price replaced by new price
		
	}
	else if (i==2) //for second train
	{
	
	float newprice;
	
	cout<<"Enter new price for train 2 :";
	cin>>newprice;

	priceT2 = newprice; //old price replaced by new price

	}
	else if (i==3) //for third train
	{
		
	float newprice;
	
	cout<<"Enter new price for train 3 :";
	cin>>newprice;

	
	priceT3 = newprice; //old price replaced by new price
	
	}
		
	else
	{
		cout<<"\n Please enter the exist transport.";
		editTrainPrice(); //repeat if wrong input
	}
	option() ;
		
}

void editFlightPrice() //func works for editing the price
{	
	int i;
	
	cout<<"\n Select a plane you want to edit(1/2) : Num ";
	cin>>i;
	
	if (i==1) //first flight
	{
	 float newprice;
	
	cout<<"Enter new price for plane 1 :";
	cin>>newprice;
	
	priceF1 = newprice; //old price replaced by new price
		
	}
	else if (i==2) //second fight
	{
	
	float newprice;
	
	cout<<"Enter new price for plane 2 :";
	cin>>newprice;

	priceF2 = newprice; //old price replaced by new price
	
	}		
	else
	{
		cout<<"\n Please enter the exist transport.";
		editFlightPrice(); //repeat if func if wrong input
	}
	option() ; //back after done
		
}

void User(){
	int option1,b;
	cout << "CONNECTED - " << u1 << "\n"
		 << "------------------------------\n"
		 << "Hello, good " << time << "\n" <<endl;
	cout << "(1) User Log in \n"
		 << "(2) User Sign up\n" << endl;
	cout << "Code: ";
	cin >> option1;
	while (option1 < 1||option1 >2){//repeat untill true input being inserted
		cout << "Invalid :";
		cin >> option1;
	}
	if(option1==1)
		UserLogin(); //bring to user login site
	else
		UserSignup(); //bring to user signup site
	b = g_count;
	system("cls");
	//User after log in page
	UserUI(b); //bring to user site
}
void UserLogin(){
	string userid;
	int option2;
	bool valid=false;
	cout << "\n\nCONNECTED - " << u1 << " LOG IN\n"
		 << "-----------------------" << endl;
	cout << "Enter id: ";
	cin >> userid;
	for(int a=0;a<SIZE;a++){
		if(userid==user[a].user_id){
			valid = true;
			break;
		}
		g_count++; //to identify which user he/she are		
	}
		
	if(valid==false){
		cout << "\n\nInvalid id detected!\n"
			 << "-----------------------\n"
			 << "(1) Try again\n"
			 << "(2) Sign up for free"<< endl;
		cout << "Code: ";
		cin >> option2;
			while (option2 < 1||option2 > 2){
			cout << "Invalid :";
			cin >> option2;
			}
			if(option2==1)
				UserLogin();
			else
				UserSignup();
	}
	cout << "SUCCESS" << endl; 
	
}
void UserSignup(){
	int arr=0;
	cin.ignore();
	cout << "CONNECTED - " << u1 << " SIGN UP\n"
		 << "-------------------\n"
		 << "Please fill all details below\n" << endl;
	cout << "Enter full name: ";
	getline(cin, user[arr].name);
	cout << "Enter phone number: ";
	getline(cin, user[arr].phoneNum);
	cout << "Enter prefered id: ";
	getline(cin, user[arr].user_id);
	while((user[arr].user_id).size() <= 6){
		cout << "Must six characters long";
		getline(cin, user[arr].user_id);
	}
	++arr;	 
		 
	cout << "NICE" << endl;
	UserLogin();
}
void UserUI(int b){
	int option; 
	cout << "CONNECTED - Welcome " << user[b].name << " !\n" 
		 << "--------------------\n" 
		 << "(1) Balance\n(2) View Public Transport"<< endl;
	cout << "Option : ";
	cin >> option;
	while (option < 1||option > 2){
		cout << "Invalid option detected: ";
		cin >> option;
	}
	switch(option){
		case 1:
			Userbalance(b);
		break;
		case 2:
			ViewPublicTrans();
		break;
	}
}
void Userbalance(int c){
	int option, pMethod;
	double range;
	cout << "CONNECTED - " << u1 << "BALANCE\n" 
		 << "-----------------------------\n" 
		 << "(1) Check balance\n(2) Topup Balance\n (3) Back to Main"<< endl;
	while (option < 1||option > 3){
		cout << "Invalid option detected: ";
		cin >> option;
	}
	if(option==1){
		cout << "CONNECTED - CHECK" << u1 << "BALANCE\n" 
		 	 << "--------------------------------\n"
		 	 << "Current balance: RM" << user[c].balance << endl;
		cout << "\n" <<endl;
		system("pause");
		return Userbalance(c);
	}else if(option==2){
		cout << "CONNECTED - TOPUP" << u1 << "BALANCE\n" 
		 	 << "------------------------------\n"
		 	 << "Insert all details below\n" << endl;
		cout << "How much want to Topup: ";
		cin >> range;
		while(range<0){
			cout << "Invalid input: ";
			cin >> range;
		}
		cout << "Choose Payment Method\n (1) Cash\n(2) QRpay" << endl;
		cin >> pMethod;
		while (pMethod < 1||pMethod > 2){
		cout << "Invalid Payment Detected: ";
		cin >> pMethod;
		}
		cout << "Sucessfully topup !\n" << endl;
		receiptinfile(pMethod, range, c);
	}else{
		return UserUI(c);
	}
}
void receiptinfile(int method , double topup, int d){
	int j=0;
	string p;
	if(method==1)
		p = "Cash";
	if(method==2)
		p = "QRpay";
		
	ofstream receipt;
	if(j==0)
		receipt.open("receipt.txt");
	else
		receipt.open("receipt.txt", ios::app);
		
	receipt << "Name: " << user[d].name << endl;
	receipt << "Payment Method: " << p << endl;
	receipt << "Total topup: RM" << topup;
	
	receipt.close();
}
void ViewPublicTrans(){ //func to view public trans and calculate them
	double i,k,total=0.00;
	char view;
	cout << "CONNECTED - PUBLIC TRANSPORTS\n" 
		 << "------------------------------\n";
	cout<<" \t\t\t\t   _____________________________________________\n";
	cout<<" \t\t\t\t  |                                             |\n"; 	  	
	cout<<" \t\t\t\t  |           CODE            Transport         |\n";
	cout<<" \t\t\t\t  |           [T]              TRAIN            |\n";
	cout<<" \t\t\t\t  |           [B]              BUS              |\n";       
	cout<<" \t\t\t\t  |           [F]              FLIGHT           |\n";
    cout<<" \t\t\t\t  |_____________________________________________|"<<endl;   
    cout << "\nEnter public transport :";
	cin >> view;
	 if(toupper(view)=='T')
    {
        trainOption();
        cout << "Enter all details below\n Train code:";
        cin >> i;
        cout << "Total station: ";
        cin >> k;
        total = calculation(i,k,view);
        cout << "Total: RM" << total;
        cout << "Credit balance: RM" << ((user[g_count].balance) -= total)  << endl;
        main();
    }
	else if(toupper(view)=='F')
	{
	    flightOption();
	    cout << "Enter all details below\n Train code:";
        cin >> i;
        cout << "Type of flight: ";
        cin >> k;
        total = calculation(i,k,view);
        cout << "Total: RM" << total;
        cout << "Credit balance: RM" << ((user[g_count].balance) -= total)  << endl;
        cout << "Thank you for choose CONNECTED as your public transports partner\n\n\n";
        main();
	}
    else if(toupper(view)=='B')
	{
        busOption();
		cout << "Enter all details below\n Bus code:";
        cin >> i;
        cout << "Total passenger(s): ";
        cin >> k;
        total = calculation(i,k,view);
        cout << "Total: RM" << total;
        cout << "Credit balance: RM" << ((user[g_count].balance) -= total) << endl;
		cout << "Thank you for choose CONNECTED as your public transports partner\n\n\n";
        main();   
    }
    else
	{
		cout<<"\nYou have entered the wrong code!"<<endl;
		cout<<"Please re-enter the code"<<endl<<endl;
		cout<<setw(50)<<setfill('*')<<endl;
		system("pause");
		system("cls");
		ViewPublicTrans();
	}	 
}
double calculation(double i,double j,char detect){ //func to calculate based on type and return total payment
	double total=0.00,calculate=0.00;
	if(detect=='T'){
		//calculate for the train
		if(i==1){
			(calculate=(priceT1*j));
			total=calculate;
		}else if(i==2){
			(calculate=(priceT2*j));
			total=calculate;
		}else{
			(calculate=(priceT3*j));
			total=calculate;
		}
	}else if(detect=='B'){
		//calculate for the bus
		if(i==1){
			(calculate=(priceB1*j));
			total=calculate;
		}else if(i==2){
			(calculate=(priceB2*j));
			total=calculate;
		}else{
			(calculate=(priceB3*j));
			total=calculate;
		}
	}else{
		//calculate for the flight
		if(i==1){
			(calculate=(priceF1*j));
			total=calculate;
		}else{
			(calculate=(priceF2*j));
			total=calculate;
		}
	}
	total += overall;
	return total;
}
