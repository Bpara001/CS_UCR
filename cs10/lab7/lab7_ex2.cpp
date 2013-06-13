// Course: CS 10 <fall quarter, 2009>
//
// First Name: Chris
// Last Name: Wong
// Login id: wongc
// email address: cwong030@student.ucr.edu
//
// Lecture Section: 02
// Lab Section: 026
// TA: Muzaffer Akbay
//
// Assignment: lab7_ex2
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//
// ===========================================================

#include <iostream>
#include <iomanip>
using namespace std;



double total(double price, int quantity)
{

    return price * quantity;
}

double change(double price, double payment)
{
    return payment - price;
}

int main()
{
   const double TWINKIES = 0.60;
   const double DRPEPPER = 1.25;
   const double GUM = 0.40;

   cout << "1) Twinkies $0.60\n";
   cout << "2) Dr. Pepper $1.25\n";
   cout << "3) Gum $0.40\n";

   int choice;
   cout << "What would you like to buy?";
   cin >> choice;

   double price;

   if ( choice == 1 )
   {
      price = TWINKIES;
   }
   else if ( choice == 2 )
   {
      price = DRPEPPER;
   }
   else if ( choice == 3 )
   {
      price = GUM;
   }

   int quantity;
   cout << "How many would you like to buy?";
   cin >> quantity;


   double total_price = total( price, quantity );

   cout << fixed << setprecision( 2 );
   cout << "Your total price is $" << total_price << endl;

   double payment;
   cout << "Enter amount giving cashier: ";
   cin >> payment;

   cout << "Your change is $" << change( total_price, payment ) << endl;

   return 0;
}
