#include <iostream>
#include <string.h>
using namespace std;

class Bankaccount {
	private:
		string accountnumber;
		double balance;
		
	public:
		Bankaccount (string accountnum)
		{
			accountnumber = accountnum;
			balance= 0.0;
		}

void deposit(double amount)
{
	if(amount > 0)
	{
		balance += amount;
		cout << "Deposit Amount " << amount << " . Current Balance " << balance << endl;
	}
	else
	{
		cout << "Invalid Input " << endl;
	}
}

void withdraw(double amount)
{
	if(amount > 0)
	{
		if(balance >= amount)
		{
			balance -= amount;
			cout << "Withdraw " << amount << " . Current balance: " << balance << endl;
		}
		else 
		{
			cout << "Insufficient Balance" << endl;
		}
	}
		else
		{
			cout << "Invalid Input" << endl;
		}
}

void checkbalance()
{
	cout << "Account number " << accountnumber << endl;
	cout << "Current Balance " << balance << endl;
	
}

};

int main ()
{
	string accountnumber;
	cout <<" Enter account number:" << endl;
	cin >> accountnumber;
	
	Bankaccount account(accountnumber);
	int choice;
	double amount;
	
	do
	{
		cout << "Bank Account System" << endl;
		cout << "Enter your choice:" << endl;
		cout << "1.Deposit Money" << endl;
		cout << "2.With Draw Money" << endl;
		cout << "3.Check Balance" << endl;
		cout << "4.Exit" << endl;
		cin >> choice;
		
		switch(choice)
		{
			case 1:
				cout << "Enter Amount to deposit:" << endl;
				cin >> amount;
				account.deposit(amount);
				break;
			case 2:
				cout << "Enter Amount to Withdraw:" << endl;
				cin >> amount;
				account.withdraw(amount);
				break;
			case 3:
				account.checkbalance();
				break;
			case 4:
				cout << "Thank You For coming to our Bank Account System" << endl;
				break;
			default:
				cout << "Invalid Input" << endl;
		}
	}
		
		while (choice !=4);
		return 0;
	}
