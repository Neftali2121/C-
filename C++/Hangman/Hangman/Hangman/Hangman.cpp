// Hangman.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//pseudocode for hangman Iteration 1
/*
The code should include:
1) A start screen
Clear console screen
declare a character StarKey

Display: 'Hangman'
Display: 'by two neurons'
Display: an ASCII image of a lost game state
Display: 'Press any key and enter start'
Get StartKey

Clear console screen

2) a set of variables used in the game
Declare integer Tries and set to 6
Declare character Guess
Declare a bool CorrectGuess and set to false
Declare a list of characters PreviousGuesses and set lenght to 7 (really 8)

(more to go here)
Loop the lenght of PreviousGuesses
    set value to "-"
(more to go here)

Declare a string (we need a string header)
Declare a list of strings WordList and set the lenght to 99(100 words in total)

3) A way to get a random word
set random seed (need appropiate header)
Get a list of words RandomWords (we will expand this later)

loop for 100 iterations
    get from RandomWords and initialize it as a random number (0-99)
Declare RandomNumber and utilize it as a random number (0-99)
Set Word as equal item at RandomNumber from WordList

Declare MyesteryWord and set this to the lenght of Word and the value of each character to '*'

4) The guess and result
While the player still has tries (while tries is greater than or equal 0)
    reset CorrectGuess to false 

    Display information to [layer (i.e., image of the gallows/man, MysteryWord, and tries left)
    if the fisrt value of PreviousGuesses is null
        Display nothing related to PreviousGuesses
    else if the first value is valid
        Dispplay 'You have (incorrectly) guessed the following letters: 'PreviousGuesses

    Dsiplay 'Guess a letter and press enter: '
    get Guess
    for the lenght of MysteryWord
        Check does the Word (actual) have Guess in it
            if it does set Mysteryword at that point to display Guess
            if it does set CorrectGuess to true
    if the puzzle is solved (MysteryWord is equal to Word)
        Display 'Congratulations! You've got the word!'
        end this While-loop (break)
    else if CorrectGuess is false
        decrement Tries
        Display 'Sorry \' 'Guess '\' is not part of the word
    else if CorrectGuess is true 
        Display 'Congratulations \' Guess '\' is part of the word'

    switch (Tries) 
        Display the ASCII drawing based on the number of Tries remaining
        if CorrectGuess is false 
            set the next value in PreviousGuesses to Guess
*/

#include <iostream>

int main()
{
   // The code should include :
    //1) A start screen
    //Clear console screen
    //declare a character StarKey

    //Display : 'Hangman'
    //Display : 'by two neurons'
    //Display : an ASCII image of a lost game state
    //Display : 'Press any key and enter start'
    //Get StartKey

    //Clear console screen

    //1) START SCREEN

    //Clear Screen
    std::system("CLS"); //you should really NOT use this! We will replace it later on.

    //display start screen
    char StartKey{};
    std::cout << " Hangman " << std::endl;
    std::cout << "By Two Neurons Tutorial" << std::endl;
    std::cout << "_____________   " << std::endl;
    std::cout << "|        }      " << std::endl;
    std::cout << "|        O      " << std::endl;
    std::cout << "|        |      " << std::endl;
    std::cout << "|      / | \\    " << std::endl;
    std::cout << "|     /  |  \\   " << std::endl;
    std::cout << "|      /   \\    " << std::endl;
    std::cout << "|     /     \\  " << std::endl;
    std::cout << "|               " << std::endl;
    std::cout << "|_____________  " << std::endl;
    std::cout << "\nPress Any Key (and Enter) to Start\n";
    std::cin >> StartKey;

    std::system("CLS"); //you should really NOT use this! We will replace it later on.

    return 0;
}


