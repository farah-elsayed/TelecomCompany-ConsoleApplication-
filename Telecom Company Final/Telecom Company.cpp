#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>

const long long card1 = 7894652135745264               //The serial numbers of the cards for recharging the balance
, card2 = 1452365896546565
, card3 = 2583691477899631
, card4 = 4563217418529634;
# define MAX_LINES 3            //Number of maximum line that the user allowed to have

using namespace std;
struct userPhoneData
{
	long long phoneNo;
	string package;
	double balance;
};
struct date
{
	int day, month, year;

};

struct user
{
	int ID;
	char  password[8];
	string name, email, address;
	userPhoneData phone[MAX_LINES];
	date start;

}u;



void Register();
void Operations();
void Date_Of_Subscription();               //This function is for the renewal date
void Transfer_Balance(long long num, double &balance);     //Transfer balance to another number
void Recharge(long long num, double &money);
void RenewSubscriotion();
void PackageType(int pack, double &balance);



int main()
{

	system("color F0");                    //For the console color
	cout << "                  Welcome to ASA telecom                    \n" << endl;

	Register();
	Operations();

	system("pause");
	return 0;
}

void Operations()
{
	long long  CallNo, MessageNo;     //The numbers that the user want to call or send a message to
	long long  serialNo;             //The serial number of one of the cards above to recharge the balance 
	int choice;
	char ans = 'y';
	while (ans == 'y' || ans == 'Y')           //As long as the answer is yes (y) the program will continue
	{
		cout << "Choose the peration: \n 1-Recharge  \t      2-Call   \n 3-Message \t 4- Renewal Date \t 5-Transfer balance    \n";
		cin >> choice;

		if (choice == 1)
		{
			cout << "Enter the card serial number: ";
			cin >> serialNo;
			Recharge(serialNo, u.phone[MAX_LINES].balance);
		}

		else if (choice == 2)
		{
			cout << "Enter the Number You Want to Call: ";
			cin >> CallNo;
			u.phone[MAX_LINES].balance -= 0.25;
			cout << "Your balance has been reduced by 0.25 L.E and your current balance is " << u.phone[MAX_LINES].balance - 0.25 << "L.E" << endl;

		}
		else if (choice == 3)
		{
			cout << "Enter the Number You Want to Call: ";
			cin >> MessageNo;
			u.phone[MAX_LINES].balance -= 0.25;
			cout << "Your balance has been reduced by 0.25 L.E and your current balance is " << u.phone[MAX_LINES].balance - 0.25 << "L.E" << endl;

		}
		else if (choice == 4)
		{
			Date_Of_Subscription();
		}
		else if (choice == 5)
		{
			long long TransferNo;
			Transfer_Balance(TransferNo, u.phone[MAX_LINES].balance);

		}

		cout << "Do you want anything else(y/n)? \n";
		cin >> ans;

	}
}
void Recharge(long long num, double &money)
{

	while (true)
	{

		if (num == card1)
		{
			money += 10;
			cout << "Your new balance is: " << money << endl;
			break;
		}
		else if (num == card2)
		{
			money += 20;
			cout << "Your new balance is: " << money << endl;
			break;
		}
		else if (num == card3)
		{
			money += 30;
			cout << "Your new balance is: " << money << endl;
			break;
		}
		else if (num == card4)
		{
			money += 50;
			cout << "Your new balance is: " << money << endl;
			break;
		}
		else
		{
			cout << "Invaid number \n Enter a valid number\n";
			cin >> num;

		}


	}

}
void PackageType(int pack, double &balance)
{


	if (pack == 1)
	{
		balance -= 40;
		cout << "Your balance now is: " << balance << endl;
	}
	else if (pack == 2)
	{
		balance -= 35;
		cout << "Your balance now is: " << balance << endl;
	}
	else if (pack == 3)
	{
		balance -= 70;
		cout << "Your balance now is: " << balance << endl;
	}
	else if (pack == 4)
	{
		balance -= 20;
		cout << "Your balance now is: " << balance << endl;
	}
	else
	{
		cout << "Not a vaild number \n";

	}


}

void RenewSubscriotion()
{
	int  num_pack;        //The number of the package that the user will enter
	char answer;   // Used to decide if the user want to renwew the subscription or not
	cout << "Do you want to renew your Subscription (y/n)?\n";
	cin >> answer;
	int i;
	while (true)
	{

		if (answer == 'y' || answer == 'Y')
		{
			for (i = 0; i < MAX_LINES; i++)
			{

				cout << "Enter your phone number: ";
				cin >> u.phone[MAX_LINES].phoneNo;
				cout << "What is your package? \n";
				cout << "1- 1500 flex for 40 L.E  \t  2- 1000 flex for 35 L.E  \t 3- 2500 flex for 70 L.E \t   4- 500 flex for 20 L.E \n";
				cin >> num_pack;
				PackageType(num_pack, u.phone[MAX_LINES].balance);
				cout << "Do you want to add another phone number (y/n)?\n";
				cin >> answer;
				if (answer == 'y' || answer == 'Y')
					continue;
				else if (answer == 'n' || answer == 'N')
					break;
			}
			if (i > 2)
				cout << "You have maximum 3 line , You can't have more " << endl;
			break;
		}
		else if (answer == 'n' || answer == 'N')
		{
			cout << "Enter your phone number: ";
			cin >> u.phone[MAX_LINES].phoneNo;
			cout << "Do you want to add another phone number (y/n)?\n";
			cin >> answer;
			if (answer == 'y' || answer == 'Y')
				continue;
			else if (answer == 'n' || answer == 'N')
				break;

		}

	}



}

void Register()
{
	char answer;
	cout << "Enter Your ID number: ";
	cin >> u.ID;
	cin.ignore();
	cout << "Enter Your Name: ";
	getline(cin, u.name);
	cout << "Enter your E-mail: ";
	getline(cin, u.email);
	while (true) {
		cout << "Enter Your Password (Minimum 8 Characters): ";
		cin >> u.password;
		if (u.password[7] == '\0')
		{
			cout << "Please Try Entering the password again\n it must contain 8 characters\n";
			continue;
		}
		else
			break;
	}
	cin.ignore();
	cout << "Enter Your Address: ";
	getline(cin, u.address);
	cout << "Enter Your Balance: ";
	cin >> u.phone[MAX_LINES].balance;
	RenewSubscriotion();

}
void  Transfer_Balance(long long num, double &balance)
{
	double money;
	cout << "Enter the number you want to transfer money to: ";
	cin >> num;                                                 //The number that the money will be transfered to
	cout << "Enter the amount of money: ";
	cin >> money;                                               //The amount of money that will be transfered
	balance -= money;
	cout << money << "L.E" << " will be taken from your balance and your \n current balance is " << balance << "L.E" << endl;


}
void Date_Of_Subscription()
{
	cout << "When was the last time you renewed the subscription?\n";
	cout << "Day: ";  cin >> u.start.day;
	cout << "Month: "; cin >> u.start.month;
	cout << "Year: ";  cin >> u.start.year;

	u.start.month++;
	u.start.month %= 12;

	if ((u.start.month %= 12) == 1)
	{
		u.start.year++;
		cout << "Your Renewal date: " << u.start.day << "/" << u.start.month << "/" << u.start.year << endl;

	}
	else if ((u.start.month %= 12) == 0 && u.start.day == 30)
	{
		u.start.month += 12;
		cout << "Your Renewal date: " << u.start.day << "/" << u.start.month << "/" << u.start.year << endl;

	}
	else
		cout << "Your Renewal date: " << u.start.day << "/" << u.start.month << "/" << u.start.year << endl;

}

