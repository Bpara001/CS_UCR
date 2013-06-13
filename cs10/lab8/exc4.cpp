#include <iostream>
using namespace std;



double transaction(double current,int choice, double amount)
{
    if (choice == 1)
    {  current = current + amount;
        return current;}
    if (choice == 2)
    { current = current - amount;
        if (current >= 0)
        {return current;}

    }
}

int main()
{
double balance = 0;
    while(true)
    {
        
        cout << "Please enter your choice (1-3)" <<endl;
        cout <<"Your Current balance: $" << balance << "\n"
        << " 1) Make a deposit \n 2) Make a withdrawl \n 3) Quit" << endl;

        int choice;
        cin >> choice;

        if (choice == 1)
        {   cout <<"Enter Deposit amount:"<<endl;
            double deposit;
            cin >> deposit;
            balance = transaction(balance,1,deposit);
            
        }
        if(choice == 2)
        {
            cout <<"Enter Withdraw amount:" << endl;
            double withdraw;
            cin >> withdraw;
            if ( balance >= withdraw)
            {balance = transaction(balance,2,withdraw);}
            else
            {cout <<"Invalid number, please try again.\n" << endl;}
        }
        if(choice == 3)
        {
            exit(0);
        }



    }
    return 0;
}
