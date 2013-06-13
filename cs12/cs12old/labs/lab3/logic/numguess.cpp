// This program plays a guessing game where you try to guess the number 
// the computer has picked.

#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
  int number_to_guess = std::rand() % 101;
  int guess = 0;

  std::cout << "Guess a number between 1 and 100." << std::endl
	    << "? ";
  
  do 
  {
    std::cin >> guess;
    if ( guess > number_to_guess ) 
      std::cout << "Try lower." << std::endl << "? ";
    else if ( guess < number_to_guess )
      std::cout << "Try Higher." << std::endl << "? ";
    else 
    {
      std::cout << "You guessed right!!!" << std::endl;
    }
  } while ( number_to_guess != guess );

  return 0;
}
