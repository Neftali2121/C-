// This file is for the number guesser game from two neurons tutorial.
//


// Iteration 1: make a game that checks if a guess number is correct or not.
/*
Declare GuessedNumber
declare FavoriteNumber

FavoriteNumber = random number (1-10)

display "Guess a number: "
Get GuessedNumber

While GuessedNumber is not equal to the FavoriteNumber
    Display "You guessed: " GuessedNumber " and that is not my favorite number."
    Display "Guess again: "
    Get GuessedNumber 

Display "You're right; " GuessedNumber "is indeed my favorite number."

*/

//Iteration 2 of the Number Guesser Pseudocode 
/*
Iteration 2: Make a game that checks if a guessed number is correct or not-
add in a check if the value guessed is in range of 1 to 10.

Seed Random Number Generator

declare GuessedNumber
declare FavoriteNumber

FavoriteNumber= random number (1-10)

Display "Guess a number: " MAYBE, update?!?
Get GuessedNumber

while GuessedNumber is not equal to FavoriteNumber
    If guessed number is greater than 10
        display that the GuessedNumber was greater than 10
        display "Guess again: "
        Get GuessedNumber 
    else if the guess number is equal to or less than 0
        display that the guess number was less than 1
        display "Guess again:"
    else 
        Display "You guessed:" "GuessedNumber " and that is not my favorite number."
        Display "Guess again: "
        Get GuessedNumber

Display "You're right; "GuessNumber "is indeed my favorite number."

*/

//Iteration 3 of the Number Guesser Pseudocode
/*
Iteration 3: Make a game that checks if a guessed number is correct or not-
add in a check if the value guessed is in range of 100 AND
gives hints to the player if they are near or far from the favoriteNumber; near is equal or less than 5.

Seed Random Number Generator

declare GuessedNumber
declare FavoriteNumber

FavoriteNumber= random number (1-100)

Display "Guess a number: " (make sure tot tell the player it is 1 to 100)
Get GuessedNumber

while GuessedNumber is not equal to FavoriteNumber

    declare DifferenceBetweenValues
    DifferenceBetweenValues to be to absolute of the FavoriteNumber - GuessedNumber

    If guessed number is greater than 100
        display that the GuessedNumber was greater than 100
        display "Guess again: "
        Get GuessedNumber
    else if the guess number is equal to or less than 0
        display that the guess number was less than 1
        display "Guess again:"
    else if DifferenceBetweenValues is equal to or less than 5 
        display that the GuessNumber was close but not quite right
        display "GuessAgain: "
        Get GuessedNumber
    else if DifferenceBetweenValues is greater than 5 
        display that the guess was not close
        display "Guess Again: "
        Get GuessedNumber
    else
        Display "You guessed:" "GuessedNumber " and that is not my favorite number."
        Display "Guess again: "
        Get GuessedNumber

Display "You're right; "GuessNumber "is indeed my favorite number."
*/


#include <iostream> // this is a header
#include <cstdlib> // this header gets the rand and srand functions
#include <ctime> // this gets the time function 
 
int main()
{
    srand(time(NULL)); // sets our random seed based on our pc time
    float GuessedNumber; // declared but not initialized an int variable called 'GuessedNumber'
    int FavoriteNumber; // declare and initialized an int variable called 'FavoriteNumber' (we will make this ramdon later)
    const int MaxValue{ 100 };
    
    
    FavoriteNumber = rand() % MaxValue + 1;
    std::cout << "Hey! Let's play a game. Guess what my favorite number is! It is between 1 and " << MaxValue << ". Go on, Guess: " << std::endl;
    std::cin >> GuessedNumber; // initialized the variable (as it will give GuessNumber) a variable.

    while (GuessedNumber != FavoriteNumber)
    {
        int DifferenceBetweenValues{ 0 };
        DifferenceBetweenValues = std::abs(FavoriteNumber - GuessedNumber); //setd DifferenceBewteenValues to the absolute of FavoriteNumber - GuessedNumber

        int CheckValue = fmod(GuessedNumber * 10, 10);

        if (!GuessedNumber)
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "You think this is funny? That is a character and characters are non valid numbers." << std::endl;
            std::cout << "Please guess a valid integer like the mature adult you are:" << std::endl;
            std::cin >> GuessedNumber; 
        }
        else if (CheckValue != 0)
        {
            std::cin.clear();
            std::cin.ignore(10000, 10);
            std::cout << "You have entered a floating number. This is not a valid integer. Can't believe you know floats but not integers" << std::endl;
            std::cout << "Please enter a valid integer, human." << std::endl;
            std::cin >> GuessedNumber;
        }

        if (GuessedNumber > MaxValue)
        {
            std::cout << "I said between 1 and " << MaxValue << ", why would you guess that? " << GuessedNumber << " is greater than " << MaxValue << "!!" << std::endl;
            std::cout << "Guess again: " << std::endl;
            std::cin >> GuessedNumber;
        }
        else if (GuessedNumber <= 0)
        {
            std::cout << "OMG, I said between 1 and " << MaxValue << ", why would you guess that. " << GuessedNumber << " is less than 1!!" << std::endl;
            std::cout << "Guess again, jeez: " << std::endl;
            std::cin >> GuessedNumber;
        }
        else if (DifferenceBetweenValues <= 5)
        {
            std::cout << "oh! You were very close, but not quite right. Try again!" << std::endl;
            std::cout << "Guess again: " << std::endl;
            std::cin >> GuessedNumber;
        }
        else if (DifferenceBetweenValues > 5)
        {
            std::cout << "You are not near close. What a disappointment. Try again" << std::endl;
            std::cout << "Guess again: " << std::endl;
            std::cin >> GuessedNumber;
        }
        else
        {
            std::cout << "You guessed: " << GuessedNumber << " and that is not my favorite number" << std::endl;
            std::cout << "Guess again: " << std::endl;
            std::cin >> GuessedNumber;
        }
        

    }
    std::cout << "You are right; " << GuessedNumber << " is indeed my favorite number!" << std::endl;
    
    return 0;
}

